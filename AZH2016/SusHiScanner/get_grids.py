import ROOT
ROOT.gROOT.SetBatch(True)
from glob import glob
from array import array
from helpers import get_pairs



def get_cos_b_a( tan_b, sinB_A ) :
    f = open("out/%s/%s/sushi_out/2HDMC.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ), "r" )

    for line in f :
        info = line.strip().split()
        if 'cos(beta-alpha)' in info :
            return float(info[1])
    assert(0), "Didn't find cos(beta-alpha) in file %s" % f.name



def get_sm_htt_BR( tan_b, sinB_A ) :
    f = open("out/%s/%s/sushi_out/2HDMC.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ), "r" )

    in_sm_higgs_section = False
    for line in f :
        info = line.strip().split()

        # If we make it back to another 'DECAY' after entering the target, error out
        if in_sm_higgs_section and 'DECAY' in info :
            print " - didn't find SM-Higgs -> TauTau BR for tan(b) %s, sinB_A %s" % ( tan_b, sinB_A )
            return 0.
            #assert(0), "Didn't find SM-Higgs BR in file %s" % f.name

        if 'DECAY' in info and 'lightest' in info and 'CP-even' in info and 'Higgs' in info :
            in_sm_higgs_section = True
        if in_sm_higgs_section and '15' in info and '-15' in info :
            return float(info[0])
    assert(0), "Didn't find SM-Higgs BR in file %s" % f.name



def get_A_Zh_BR( tan_b, sinB_A ) :
    f = open("out/%s/%s/sushi_out/2HDMC.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ), "r" )

    in_A_higgs_section = False
    for line in f :
        info = line.strip().split()

        # If we make it back to another 'DECAY' after entering the target, error out
        if in_A_higgs_section and 'DECAY' in info :
            print " - didn't find A -> Zh BR for tan(b) %s, sinB_A %s" % ( tan_b, sinB_A )
            return 0.
            #assert(0), "Didn't find A to Zh BR in file %s" % f.name

        if 'DECAY' in info and  'CP-odd' in info and 'Higgs' in info :
            in_A_higgs_section = True
        if in_A_higgs_section and info[2] == '23' and info[3] == '25' :
            return float(info[0])
    assert(0), "Didn't find A to Zh BR in file %s" % f.name



def get_ggA( tan_b, sinB_A ) :
    sushi_out = glob("out/%s/%s/sushi_out/type2_Htype_21_*.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ) )
    f = open( sushi_out[0], "r" ) 

    in_ggA_section = False
    for line in f :
        info = line.strip().split()
        if 'Block' in info and 'SUSHIggh' in info :
            in_ggA_section = True
        if in_ggA_section and '1' in info :
            return float(info[1])
    assert(0), "Didn't find cross section ggA in file %s" % f.name



def get_bbA( tan_b, sinB_A ) :
    sushi_out = glob("out/%s/%s/sushi_out/type2_Htype_21_*.out" % ( str(tan_b).replace('.','p'), str(sinB_A).replace('.','p') ) )
    f = open( sushi_out[0], "r" ) 

    in_bbA_section = False
    for line in f :
        info = line.strip().split()
        if 'Block' in info and 'SUSHIbbh' in info :
            in_bbA_section = True
        if in_bbA_section and '1' in info :
            return float(info[1])
    assert(0), "Didn't find cross section bbA in file %s" % f.name
    



pairs = get_pairs()
print len(pairs)

# Output file
file_ = ROOT.TFile( 'type-II_2HDM_Params.root', 'RECREATE' )

# 2D Graphs to contain our results
g_br_sm_htt = ROOT.TGraph2D()
g_br_sm_htt.SetTitle('BR SM Higgs(125) #rightarrow #tau#tau, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);BR SM-Higgs(125) #rightarrow #tau#tau')
g_br_sm_htt.SetName('sm_htt_br')
g_br_AZh = ROOT.TGraph2D()
g_br_AZh.SetTitle('BR A #rightarrow Zh, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);BR A #rightarrow Zh')
g_br_AZh.SetName('AZh_br')
g_ggA = ROOT.TGraph2D()
g_ggA.SetTitle('#sigma ggA, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);#sigma ggA (fb)')
g_ggA.SetName('xsec_ggA')
g_bbA = ROOT.TGraph2D()
g_bbA.SetTitle('#sigma bbA, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);#sigma bbA (fb)')
g_bbA.SetName('xsec_bbA')
g_bbA_over_ggA = ROOT.TGraph2D()
g_bbA_over_ggA.SetTitle('#sigma bbA / #sigma_ggA, m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);bbA/ggA')
g_bbA_over_ggA.SetName('xsec_bbA_over_ggA')
g_total = ROOT.TGraph2D()
g_total.SetTitle('#sigma (ggA+bbA) x BR(A#rightarrow Zh #rightarrow ll#tau#tau) (pb), m_{A}=300 GeV;cos(#beta-#alpha);tan(#beta);#sigma (ggA+bbA) x BR(A#rightarrow Zh #rightarrow ll#tau#tau)')
g_total.SetName('total_xsec_times_BRs')

# Get associated Cos(beta-alpha) from the 2HDM file
cnt = 0
for pair in pairs :

    cos_b_a = get_cos_b_a( pair[0], pair[1] )

    br_htt = get_sm_htt_BR( pair[0], pair[1] )
    g_br_sm_htt.SetPoint( cnt, cos_b_a, pair[0], br_htt )
    br_A = get_A_Zh_BR( pair[0], pair[1] )
    g_br_AZh.SetPoint( cnt, cos_b_a, pair[0], br_A )
    ggA = get_ggA( pair[0], pair[1] ) * 1000. # pb --> fb
    g_ggA.SetPoint( cnt, cos_b_a, pair[0], ggA )
    bbA = get_bbA( pair[0], pair[1] ) * 1000. # pb --> fb
    g_bbA.SetPoint( cnt, cos_b_a, pair[0], bbA )
    g_bbA_over_ggA.SetPoint( cnt, cos_b_a, pair[0], float(bbA/ggA) )
    #print pair, cos_b_a, br, ggA, bbA

    # Set total (ggA+bbA) x BR(A#rightarrow Zh #rightarrow ll#tau#tau)
    br_zll = 0.03363 + 0.03366 + 0.03370 # ee + mumu + tautau, PDG
    total = ( ggA + bbA ) * br_A * br_htt * br_zll
    g_total.SetPoint( cnt, cos_b_a, pair[0], total )

    cnt += 1

g_br_sm_htt.Write()
g_br_AZh.Write()
g_ggA.Write()
g_bbA.Write()
g_bbA_over_ggA.Write()
g_total.Write()

file_.Close()

base = '/afs/cern.ch/user/t/truggles/www/azh_mssm_2d/type2_2HDM/Feb06/'
c = ROOT.TCanvas('c1','c1',600,600)
g_br_sm_htt.Draw("COLZ")
ROOT.gPad.SetRightMargin( .15 )
c.SaveAs( base+'br_sm_htt.png' )
g_br_AZh.Draw("COLZ")
c.SaveAs( base+'br_AZh.png' )
g_ggA.Draw("COLZ")
c.SaveAs( base+'ggA.png' )
g_bbA.Draw("COLZ")
c.SaveAs( base+'bbA.png' )
g_bbA_over_ggA.Draw("COLZ")
c.SaveAs( base+'bbA_over_ggA.png' )
g_total.Draw("COLZ")
ROOT.gPad.SetLogz()
c.SaveAs( base+'total.png' )



