import ROOT
import math

def get_syst_error( h_all, h_stat ) :
    syst_total = 0.
    for b in range( 1, h_all.GetXaxis().GetNbins()+1 ) :
        if h_stat.GetBinContent(b) != 1e-5 :
            to_add = h_all.GetBinError(b)**2 - h_stat.GetBinError(b)**2
            # Not sure why but some of the bin to bin comparisons have larger uncertainties pre-systematics
            if to_add > 0. :
                syst_total += math.sqrt( to_add )
        #print b, syst_total
    return syst_total

mapper = {
    "ch1" : "eeem",
    "ch2" : "eeet",
    "ch3" : "eemt",
    "ch4" : "eett",
    "ch5" : "emmm",
    "ch6" : "emmt",
    "ch7" : "mmmt",
    "ch8" : "mmtt",
}

f1 = ROOT.TFile('htt_input.root','r')
f2 = ROOT.TFile('dcSync_AsvConstr_SF_btag_August14_EXP.root','r')
err1 = ROOT.Double(0.)
err2 = ROOT.Double(0.)
err3 = ROOT.Double(0.)
err4 = ROOT.Double(0.)
#print f1
#print f1.ls()
#print f2
#print f2.ls()

from collections import OrderedDict
rslt_map = OrderedDict()

for k, v in mapper.iteritems() :
    h1 = f1.Get('htt_'+v+'_1_13TeV/allFakes')
    
    h2_wz = f2.Get(v+'_inclusive/WZ')
    h2_ff = f2.Get(v+'_inclusive/data_FR')
    h2_all = f2.Get(v+'_inclusive/allFakes')

    i1 = h1.IntegralAndError(10, 31, err1)
    i2 = h2_wz.IntegralAndError(10, 31, err2)
    i3 = h2_ff.IntegralAndError(10, 31, err3)
    i4 = h2_all.IntegralAndError(10, 31, err4)

    l = [i1, err1, i2, err2, i3, err3, i4, err4]
    #rslt_map[ v ] = list(l)
    print "%s," % v,
    while (len(l) > 0) :
        print "%.2f +/- %.2f," % (l.pop(0), l.pop(0)),
    print ""


#for n in rslt_map.keys() :
#    print n, 
#    for item in rslt_map[n] :
#        print "%.2f" % item,
#    #print rslt_map[n]
#    print "\n"

#for n in rslt_map.keys() :
#    print "FF1: $.2f, %.2f" % (rslt_map[n][0], rslt_map[n][1]),

#print "Yield: %.3f +/- %.3f (stat.) +/- %.3f (syst.).........Total Relative Uncert. %.3f" % (h_all.Integral(), err, syst_total, math.sqrt(err**2+syst_total**2)/h_all.Integral())



