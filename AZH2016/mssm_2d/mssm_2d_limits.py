import ROOT
import json
from array import array
from collections import OrderedDict
import helpers
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

add_bbA = True
add_bbA = False
app = '' if not add_bbA else '_with_bbA'

def setLegStyle( x1,y1,x2,y2 ) :
    leg = ROOT.TLegend(x1,y1,x2,y2)
    leg.SetBorderSize(0)
    leg.SetLineColor(1)
    leg.SetLineStyle(1)
    leg.SetLineWidth(1)
    leg.SetFillColor(0)
    leg.SetFillStyle(1001)
    leg.SetTextFont(42)
    return leg

# Didn't work
#def set_color_gradient( th2 ) :
#    Red = array('d', [1.0, 0.0, 0.0])
#    Green = array('d', [0.0, 1.0, 0.0])
#    Blue = array('d', [1.0, 0.0, 1.0])
#    Length = array('d', [ th2.GetMinimum(), th2.GetMaximum() / 100., th2.GetMaximum() ] )
#    nb = 50
#    print "here",th2.GetMinimum(), th2.GetMaximum()
#    print ROOT.TColor.CreateGradientColorTable( 3, Length, Red, Green, Blue, nb )
#    ROOT.gStyle.SetNumberContours(nb)
    
def check_for_intersections( h2, mass, limit, SF ) :
    mass_bin = h2.GetXaxis().FindBin( mass )
    to_save = []
    previous_tuple = []
    current_tuple = []
    count = 0
    for y_bin in range( 1, h2.GetYaxis().GetNbins()+1 ) :
        y_bin_val = h2.GetYaxis().GetBinCenter( y_bin )
        bin_content = h2.GetBinContent( mass_bin, y_bin )
        sf_val = SF.GetBinContent( mass_bin, y_bin )
        # Initialize first one
        if previous_tuple == [] :
            previous_tuple = [ y_bin, y_bin_val, bin_content ] 
            current_tuple = [ y_bin, y_bin_val, bin_content ] 
        previous_tuple = list( current_tuple )
        current_tuple = [ y_bin, y_bin_val, bin_content ] 
        if bin_content >= (limit / sf_val) and (limit / sf_val) > previous_tuple[2] :
            #print ' - intersection', limit
            #print ' --- current',current_tuple
            #print ' --- previous',previous_tuple
            to_save.append( y_bin_val )
            count += 1
            
        if bin_content <= (limit / sf_val) and (limit / sf_val) < previous_tuple[2]  : 
            #print ' - intersection', limit
            #print ' --- current',current_tuple
            #print ' --- previous',previous_tuple
            to_save.append( y_bin_val )
            count += 1

        #print ' - ', y_bin, bin_content
    #print "Mass: %i,  Limit: %.4f,  Intersection counts: %i" % (mass, limit, count)
    if len( to_save ) == 0 : return [0,]
    return to_save



def new_pad( name = 'p' ) :
    p = ROOT.TPad( name, name, 0, 0, 1, 1)
    p.Draw()
    p.cd()
    p.SetRightMargin( 1.6 * p.GetRightMargin() )
    return p

def slim_hist( h ) :
    h.GetXaxis().SetRangeUser( 220, 400 )
    #h.GetXaxis().SetRangeUser( 250, 300 )
    h.GetYaxis().SetRangeUser( 1.0, 6.0 )
    #h.GetYaxis().SetRangeUser( 2.0, 4.0 )
    h.GetXaxis().SetTitle( 'm_{A} (GeV)' )
    h.GetXaxis().SetTitleSize( h.GetXaxis().GetTitleSize()*1.3 )
    h.GetYaxis().SetTitle( 'tan#beta' )
    h.GetYaxis().SetTitleOffset( .85 )
    h.GetYaxis().SetTitleSize( h.GetYaxis().GetTitleSize()*1.3 )
    h.GetZaxis().SetTitleOffset( .85 )
    h.GetZaxis().SetTitleSize( h.GetZaxis().GetTitleSize()*1.3 )
    
def get_limit_from_json( json_name, target = "exp0" ) :
    with open( json_name ) as jsonFile :
        jsonDict = json.load( jsonFile )

    d1 = {}
    for mass in jsonDict :
        #d1[ float( mass ) ] = float(jsonDict[ mass ][ target ]/1000.) # convert to pb to compare with HIG-14-034
        d1[ float( mass ) ] = float(jsonDict[ mass ][ target ]) # keep as fb b/c that is consistent with other limit plots

    # Sort this dict
    d2 = OrderedDict(sorted(d1.items(), key=lambda t: t[0]))

    masses = array('d', [])
    limits = array('d', [])
    for mass in d2.keys() :
        #print mass, d2[ mass ]
        masses.append( mass )
        limits.append( d2[ mass ] )

    #g = ROOT.TGraph( len(masses), masses, limits )
    #g.SetLineWidth( 4 )
    return d2

# Good 2D palette color
from ROOT import gStyle
#ROOT.gStyle.SetPalette( 57, array('i', [i for i in range( 1, 251)]) ) # 57 == kBird


uncert = '_pdfasDown'
uncert = '_pdfasUp'
uncert = '_scaleDown'
uncert = '_scaleUp'
uncert = ''

save_base = '/afs/cern.ch/user/t/truggles/www/azh_mssm_2d/Mar12v1_sup'+uncert+'/'
#save_base = '/afs/cern.ch/user/t/truggles/www/azh_mssm_2d/Mar12v1_prelim'+uncert+'/'
#save_base = '/afs/cern.ch/user/t/truggles/www/azh_mssm_2d/Mar12v1'+uncert+'/'

model_info = {
    #'mH Mod Plus scenario' : 'mhmodp_mu200_13TeV.root',
    #'mH Mod Minus scenario' : 'mhmodm_13TeV.root',
    'MSSM Low tan#beta scenario' : 'low-tb-high_13TeV.root',
    'hMSSM scenario' : 'hMSSM_13TeV.root',
    #'Light Stop Mod scenario' : 'lightstopmod_13TeV.root',
    #'New mH Max scenario' : 'newmhmax_mu200_13TeV.root',
    #'Light Stau scenario' : 'lightstau1_13TeV.root',
    ###'Low TanBeta scenario' : 'low-tb-high_8TeV.root',
    #'tauphobic scenario' : 'tauphobic_13TeV.root',
}

c = ROOT.TCanvas( 'c', 'c', 800, 600 )
p = new_pad( 'p1' )
p.SetLogz()

for model_name in model_info.keys() :
    model_file = ROOT.TFile( 'model_files/'+model_info[ model_name ], 'r' )
    mod_name_short = str(model_info[ model_name ]).replace('.root','')

    # Start with the ggA cross section
    xs_gg_A = model_file.Get( 'xs_gg_A'+uncert )
    slim_hist( xs_gg_A )
    xs_gg_A.GetZaxis().SetTitle( '#sigma ggA (fb)' )
    xs_gg_A.Draw('COLZ')
    ROOT.gPad.SetGrid()
    c.SaveAs( save_base+mod_name_short+'_xs_gg_A.png' )

    ## Next bbA cross section
    #xs_bb_A = model_file.Get( 'xs_bb4F_A' )
    #slim_hist( xs_bb_A )
    #xs_bb_A.GetZaxis().SetTitle( '#sigma bbA (fb)' )
    #xs_bb_A.Draw('COLZ')
    #c.SaveAs( save_base+mod_name_short+'_xs_bb4F_A.png' )

    # Next bbA cross section
    xs_bb5F_A = model_file.Get( 'xs_bb5F_A'+uncert )
    slim_hist( xs_bb5F_A )
    xs_bb5F_A.GetZaxis().SetTitle( '#sigma bb5FA (fb)' )
    xs_bb5F_A.Draw('COLZ')
    c.SaveAs( save_base+mod_name_short+'_xs_bb5F_A.png' )

    # Ratio of bbA/ggA cross sections
    ratio_bbA_ggA = xs_bb5F_A.Clone()
    ratio_bbA_ggA.Divide( xs_gg_A )
    ratio_bbA_ggA.SetTitle( 'Ratio #sigma bbA5F / #sigma ggA' )
    ratio_bbA_ggA.GetZaxis().SetTitle( 'Ratio #sigma bbA5F / #sigma ggA' )
    ratio_bbA_ggA.Draw('COLZ')
    c.SaveAs( save_base+mod_name_short+'_bbA_divided_by_ggA.png' )

    # Next get A -> Zh BR
    br_A_Zh = model_file.Get( 'br_A_Zh' )
    slim_hist( br_A_Zh )
    br_A_Zh.GetZaxis().SetTitle( 'BR A#rightarrowZh' )
    br_A_Zh.Draw('COLZ')
    c.SaveAs( save_base+mod_name_short+'_br_A_Zh.png' )

    # Next get A -> Zh BR
    br_h_tautau = model_file.Get( 'br_h_tautau' )
    slim_hist( br_h_tautau )
    br_h_tautau.GetZaxis().SetTitle( 'BR h#rightarrow#tau#tau' )
    br_h_tautau.Draw('COLZ')
    ROOT.gPad.SetLogz(0)
    c.SaveAs( save_base+mod_name_short+'_br_h_tautau.png' )
    ROOT.gPad.SetLogz(1)



    # This is a scaling for the limit and is how we include
    # the bbA contribution if it is requested,
    # otherwise it is scaled to 1.0 for all bins
    scale_factor = xs_gg_A.Clone()
    if add_bbA :
        bbA_eff = 0.76 # measured relative bbA efficiency / ggA eff, by Jaana
        bbA_mod = xs_bb5F_A.Clone()
        bbA_mod.Scale( bbA_eff )
        scale_factor.Add( bbA_mod )
    scale_factor.Divide( xs_gg_A )
    ROOT.gStyle.SetPaintTextFormat("4.2f")
    c2 = ROOT.TCanvas( 'c2', 'c2', 2000, 2000 )
    p2 = new_pad( 'p2' )
    p2.SetLogz()
    p2.Draw()
    p2.cd()
    scale_factor2 = scale_factor.Clone()
    scale_factor2.GetXaxis().SetRangeUser( 280, 300 )
    scale_factor2.GetYaxis().SetRangeUser( 3, 6 )
    scale_factor2.Draw('COLZ TEXT')
    ROOT.gPad.Update()
    c2.SaveAs( save_base+mod_name_short+'_limit_scaling_factor_for_ggA_vs_bbA.png' )
    c.cd()
    p.cd()


    # Now multiply all of them together for
    # xs ggA -> Zh, h -> tautau, Z -> ll
    # keep 1) version as bkg for the plot
    # keep 2) version which includes the ggA 75% efficiency for scaling limits

    # Not sure why renaming the Z axis isn't working once cloned
    # so doing it here
    if add_bbA :
        xs_gg_A.GetZaxis().SetTitle( '#sigma(ggA+bbA) #bf{#it{#Beta}} (A#rightarrow Zh #rightarrow ll#tau#tau) (fb)' )
        xs_times_br_plot = xs_gg_A.Clone()
        xs_times_br_plot.Add( xs_bb5F_A )
        xs_times_br_inc_eff = xs_gg_A.Clone()
        xs_times_br_inc_eff.Add( xs_bb5F_A )
    else : # only do ggA
        xs_gg_A.GetZaxis().SetTitle( '#sigma(ggA) #bf{#it{#Beta}} (A#rightarrow Zh #rightarrow ll#tau#tau) (fb)' )
        xs_times_br_plot = xs_gg_A.Clone()
        xs_times_br_inc_eff = xs_gg_A.Clone()


    br_Z_LL = 0.03363 + 0.03366 + 0.03370 # ee + mumu + tautau, PDG
    xs_times_br_plot.SetTitle( "" )
    xs_times_br_plot.Multiply( br_A_Zh )
    xs_times_br_plot.Multiply( br_h_tautau )
    xs_times_br_plot.Scale( br_Z_LL )
    xs_times_br_plot.Scale( 1000. ) # pb --> fb
    #xs_times_br_plot.GetZaxis().SetRangeUser( 1e-4, 0.1 )
    #xs_times_br_plot.Draw('COLZ TEXT')
    xs_times_br_plot.Draw('COLZ')
    p.Update()
    c.SaveAs( save_base+mod_name_short+'_plotted_bkg.png' )

    # FIXME, delete this
    xs_times_br_inc_eff.SetTitle( "" )
    xs_times_br_inc_eff.Multiply( br_A_Zh )
    xs_times_br_inc_eff.Multiply( br_h_tautau )
    xs_times_br_inc_eff.Scale( br_Z_LL )
    xs_times_br_inc_eff.Scale( 1000. ) # pb --> fb

    exp_lim_dictionaries = OrderedDict()
    exp_lim_dictionaries['exp0'] = get_limit_from_json( 'cmb_limits_1611OBS.json', 'exp0' )
    exp_lim_dictionaries['exp+1'] = get_limit_from_json( 'cmb_limits_1611OBS.json', 'exp+1' )
    exp_lim_dictionaries['exp+2'] = get_limit_from_json( 'cmb_limits_1611OBS.json', 'exp+2' )
    exp_lim_dictionaries['exp-1'] = get_limit_from_json( 'cmb_limits_1611OBS.json', 'exp-1' )
    exp_lim_dictionaries['exp-2'] = get_limit_from_json( 'cmb_limits_1611OBS.json', 'exp-2' )
    obs_limit = get_limit_from_json( 'cmb_limits_1611OBS.json', 'obs' )

    # Check if there are intersections
    masses = array('d', [])
    obs_limits_y_vals = array('d', [])
    exp_limits_y_vals = OrderedDict()
    for mass, limit in obs_limit.iteritems() :
        masses.append( mass )
        # Just take first for now, we will look into multiple crossing later
        y_vals = check_for_intersections( xs_times_br_plot, mass, limit, scale_factor )
        obs_limits_y_vals.append( y_vals[-1] )
    for name, dictionary in exp_lim_dictionaries.iteritems() :
        exp_limits_y_vals[ name ] = array('d', [])
        for mass, limit in dictionary.iteritems() :
            # Just take first for now, we will look into multiple crossing later
            y_vals = check_for_intersections( xs_times_br_plot, mass, limit, scale_factor )
            exp_limits_y_vals[ name ].append( y_vals[-1] )

    leg = setLegStyle( .47, .67, .8, .88 )

    obs_g = ROOT.TGraph( len(masses), masses, obs_limits_y_vals )
    obs_g.SetLineWidth( 4 )
    obs_g.Draw( 'same' )
    leg.SetHeader("95% CL upper limits")
    leg.AddEntry(obs_g, "Observed","lp")

    exp_graphs = OrderedDict()
    for name, lim in exp_limits_y_vals.iteritems() :
        g = ROOT.TGraph( len(masses), masses, lim )
        g.SetTitle( name )
        g.SetName( name )
        g.SetLineWidth( 4 )
        g.SetLineStyle( 7 )

        # Set +/- 1 and +/- 2 bands to different colors
        if '1' in name : g.SetLineColor( ROOT.kBlue )
        elif '2' in name : g.SetLineColor( ROOT.kRed )

        # Only need to add a single instance of the +/- 1 and +/- 2 bands
        if name == 'exp0' : leg.AddEntry(g, "Median expected","lp")
        elif name == 'exp+1' : leg.AddEntry(g, "68% expected","lp")
        elif name == 'exp+2' : leg.AddEntry(g, "95% expected","lp")
        exp_graphs[ name ] = g
        #g.Draw( "same" )

    for name, g in exp_graphs.iteritems() :
        g.Draw( "same" )

    leg.Draw("same")
    c.Update()

    lumi = helpers.add_lumi()
    lumi.Draw("same")
    cms = helpers.add_CMS()
    cms.Draw("same")
    prelim = helpers.add_Preliminary()
    prelim.Draw("same")
    scenario = helpers.add_Scenario()
    scenario.DrawLatexNDC( .14, .8, model_name.replace(' scenario','') )

    xs_times_br_plot.GetZaxis().SetRangeUser( 0.01, 100 )

    #print "Bkg value at mA 300, Tan(b) 4 = %f" % xs_times_br_plot.GetBinContent( xs_times_br_plot.FindBin( 300, 4 ) )

    c.SaveAs( save_base+model_name.replace(' ','_').replace('(#beta)','Beta')+app+'.png' )
    c.SaveAs( save_base+model_name.replace(' ','_').replace('(#beta)','Beta')+app+'.pdf' )



