import ROOT

def get_syst_error( h1, h2 ) :
    syst_total = 0.
    for b in range( 1, h1.GetXaxis().GetNbins()+1 ) :
        if h1.GetBinContent(b) != 1e-5 :
            syst_total += (h2.GetBinError(b) - h1.GetBinError(b))
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
    h = d.Get('allFakes')
    h.IntegralAndError(1, 31, err)
    
    d2 = f2.Get('htt_'+v+'_1_13TeV')
    h2 = d2.Get('allFakes')
    
    
    h2.IntegralAndError(1, 31, err)

    syst_total = get_syst_error( h2, h )
    print "%.3f (stat.) +/- %.3f (syst.) +/- %.3f........%.3f" % (h.Integral(), err, syst_total, (err+syst_total)/h.Integral())
