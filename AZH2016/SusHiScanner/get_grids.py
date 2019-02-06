import ROOT
from glob import glob
from array import array
from helpers import get_pairs



def get_sm_htt_BR( tan_b, sinB_A ) :
    f = open("out/%s/%s/sushi_out/2HDMC.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ), "r" )
    #print f.name

    in_cos_b_a_section = False
    cos_b_a = -9.
    for line in f :
        info = line.strip().split()
        if 'Block' in info and 'MINPAR' in info :
            in_cos_b_a_section = True
        if in_cos_b_a_section and 'cos(beta-alpha)' in info :
            cos_b_a = info[1]
            break

    in_sm_higgs_section = False
    for line in f :
        info = line.strip().split()
        if 'DECAY' in info and 'lightest' in info and 'CP-even' in info and 'Higgs' in info :
            in_sm_higgs_section = True
        #if in_sm_higgs_section : print "In SM Higgs SEction", info
        if in_sm_higgs_section and '15' in info and '-15' in info :
            print info
            return (float(info[0]), float(cos_b_a))
    assert(0), "Didn't find SM-Higgs BR in file %s" % f.name
    



pairs = get_pairs()
print len(pairs)

file_ = ROOT.TFile( 'output.root', 'RECREATE' )
g = ROOT.TGraph2D()
g.SetTitle('BR SM Higgs(125) #rightarrow #tau#tau, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);BR SM-Higgs(125) #rightarrow #tau#tau')

cnt = 0
for pair in pairs :
    info = get_sm_htt_BR( pair[0], pair[1] )
    #print pair, br
    #if cnt > 10 : break

    g.SetPoint( cnt, info[1], pair[0], info[0] )
    cnt += 1

g.Write()
file_.Close()
