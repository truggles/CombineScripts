# Simple script to multithread the SusHiScanner shell interface
# b/c the lxplus one is disabled. This generates a host of files
# containing info for limit setting.



#from multiprocessing import Process
#from multiprocessing import Pool, set_start_method
print("1")
import multiprocessing as mp
print("1")
import subprocess as subprocess
print("1")
from setup import TranslateCosB_To_sinA
print("1")
from helpers import get_pairs

"""
defaults set all heavy Higgs to 300 GeV.
Uses Type-II 2HDM. Let SusHi take care of the rest.
The results are stored in output folders based on their
input TanBeta and Sin(A-B) values.
"""


nCores = 5 # Don't set this too high.  It can crash your machine

"""
Grabbing SusHiScanner setup.py intervals
"""

##nPointsTanBeta = 90
##nPointsTanBeta = 5
##tan_b_min = 1.0
##tan_b_max = 10.0
#tanBetaLowRange = [0.5,2]
#tanBetaLowStep  = 0.05
#tanBetasLow = [ tanBetaLowRange[0]+tanBetaLowStep*i for i in range(int((tanBetaLowRange[1]-tanBetaLowRange[0])/tanBetaLowStep)) ]
#tanBetaRange = [2.,10.]
#tanBetaStep = 0.5
#tanBetas = [ tanBetaRange[0]+tanBetaStep*i for i in range(int((tanBetaRange[1]-tanBetaRange[0])/tanBetaStep+1)) ]
#tanBetas = tanBetasLow + tanBetas
#
#
##SinB_A_min = -1.0
##SinB_A_max = 1.0
##nPoints_SinB_A_min = 20 
#cosB_A_Range = [0,1]
#cosB_A_step = 0.005
#cosB_A_step = 0.05
#cosB_As = [cosB_A_Range[0] + cosB_A_step* i for i in range(int((cosB_A_Range[1] - cosB_A_Range[0])/cosB_A_step + 1))]
#sinB_As = TranslateCosB_To_sinA(cosB_As)





def make_points( tanB, sinB_A ) :

    toRun = []
    toRun.append('python3')
    toRun.append('project.py')
    toRun.append('-o')
    toRun.append('out/tanB%s/sinBminusA%s' % ( str(tanB).replace('.','p'), str(sinB_A).replace('.','p') ) )
    toRun.append('physicalbasis')
    toRun.append('--thdmType=2')
    toRun.append('--higgsType=21')
    toRun.append('--mA=300')
    toRun.append('--mH=300')
    toRun.append('--mC=300')
    toRun.append('--tanBeta=%f' % tanB )
    toRun.append('--sinB_A=%f' % sinB_A )
    print("(%.2f, %.2f)..." % (tanB, sinB_A),)

    #subprocess.call( toRun )

    return (tanB, sinB_A)


pairs = get_pairs()
#points = len(tanBetas) * len(sinB_As)
prints = len(pairs)
print("\n\nUsing nCores = %i to create working points for %i 2HDM points." % ( nCores, points ))
print("\n\nScanning Tan(beta) points: ", tanBetas)
print("\n\nScanning Sin(beta-alpha) points: ", sinB_As)

#pool = mp.Pool(processes=nCores )
#multiprocessingOutputs = []
processes = []


##print("\nStarting point (tanB,sinB_A) = ")
#pairs = []
#for tan_b in tanBetas :
#    for sinB_A in sinB_As :
#        pairs.append( [tan_b, sinB_A] )

out_files = {}
for i in range( nCores ) :
    out_files[str(i)] = open( 'input_%i.sh' % i, 'w')

# Use modulo to write to every file
cnt = 0
for items in pairs :
    file_num = cnt%nCores
    print("Outfile %i get item (%.2f, %.2f)" % (file_num, items[0], items[1]))
    out_files[str( file_num )].write(
        "python project.py -o out/%s/%s -c %i physicalbasis --thdmType=2 --tanBeta=%f --mA=300 --higgsType=21 --mH=300 --mC=300 --sinB_A=%f\n" % ( str(items[0]).replace('.','p'), str(items[1]).replace('.','p'), file_num, items[0], items[1]) )

    # Clean up the Sushi files
    #out_files[str( file_num )].write( 'rm out/*/*/sushi_out/sushi'+str(file_num)+'\n' )
    out_files[str( file_num )].write( 'rm out/%s/%s/sushi_out/sushi%s\n' % ( str(items[0]).replace('.','p'), str(items[1]).replace('.','p'), file_num) )
    cnt += 1
    

for i in range( nCores ) :
    out_files[str(i)].close()

#        multiprocessingOutputs.append( pool.apply_async(make_points, args=(tan_b, sinB_A) ) )
#
#mpResults = [p.get() for p in multiprocessingOutputs]
#
#mpResults.sort()
#for item in mpResults :
#    item
#
#
#
