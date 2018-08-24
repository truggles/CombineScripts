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

f = ROOT.TFile('fitDiagnostics.root','r')
f2 = ROOT.TFile('htt_input.root','r')
err = ROOT.Double(0.)

for k, v in mapper.iteritems() :
    print k, v
    d = f.Get('shapes_prefit/'+k)
    h_all = d.Get('allFakes')
    h_all.IntegralAndError(1, 31, err)
    
    d2 = f2.Get('htt_'+v+'_1_13TeV')
    h_stat = d2.Get('allFakes')
    
    
    h_stat.IntegralAndError(1, 31, err)

    syst_total = get_syst_error( h_all, h_stat )
    print "Yield: %.3f +/- %.3f (stat.) +/- %.3f (syst.).........Total Relative Uncert. %.3f" % (h_all.Integral(), err, syst_total, math.sqrt(err**2+syst_total**2)/h_all.Integral())
