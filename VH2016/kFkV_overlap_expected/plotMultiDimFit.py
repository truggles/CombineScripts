import CombineHarvester.CombineTools.plotting as plot 
import ROOT
import math
import argparse
from array import array

ROOT.gROOT.SetBatch(ROOT.kTRUE)
parser = argparse.ArgumentParser()
parser.add_argument('files', nargs="+", help='Input files')
parser.add_argument(
    '--output', '-o', default='limit', help="""Name of the output
    plot without file extension""")
parser.add_argument(
    '--sm-exp', default=[], nargs="+", help="""Input files for the SM expectation""")
parser.add_argument(
    '--bg-exp', default=[], nargs="+", help="""Input files for the backgroud only expectation""")
parser.add_argument(
    '--cms-sub', default='Preliminary', help="""Text below the CMS logo""")
parser.add_argument(
    '--mass', default='', help="""Mass label on the plot""")
parser.add_argument(
    '--title-right', default='', help="""Right header text above the frame""")
parser.add_argument(
    '--title-left', default='', help="""Left header text above the frame""")
parser.add_argument(
    '--x-title', default='#kappa_{v}', help="""Title for the x-axis""")
parser.add_argument(
    '--y-title', default='#kappa_{f}', help="""Title for the x-axis""")
parser.add_argument(
    '--debug-output', '-d', help="""If specified, write the contour TH2s and
    TGraphs into this output ROOT file""")
args = parser.parse_args()

#Create canvas and TH2D for each component
plot.ModTDRStyle(width=600, l=0.12)
ROOT.gStyle.SetNdivisions(510, 'XYZ')
plot.SetBirdPalette()
canv = ROOT.TCanvas(args.output, args.output)
pads = plot.OnePad()

if args.debug_output is not None:
    debug = ROOT.TFile(args.debug_output, 'RECREATE')
else:
    debug = None

print args.files
####limit = plot.MakeTChain(args.files[0], 'limit')
####graph = plot.TGraph2DFromTree(
####    limit, "CV", "CF", '2*deltaNLL', 'quantileExpected > -0.5 && deltaNLL > 0 && deltaNLL < 1000')
####best = plot.TGraphFromTree(
####    limit, "CV", "CF", 'deltaNLL == 0')
####plot.RemoveGraphXDuplicates(best)
####hists = plot.TH2FromTGraph2D(graph, method='BinCenterAligned')
###
#####plot.fastFillTH2(hists, graph,interpolateMissing=True)
###limit = plot.MakeTChain(['old/higgsCombineCvCf.MultiDimFit.mH125.root',], 'limit')
###limit = plot.MakeTChain([args.files[0],], 'limit')
###graph = plot.TGraph2DFromTree(
###    limit, "CV", "CF", '2*deltaNLL', 'quantileExpected > -0.5 && deltaNLL > 0 && deltaNLL < 1000')
###best = plot.TGraphFromTree(
###    limit, "CV", "CF", 'deltaNLL == 0')
###plot.RemoveGraphXDuplicates(best)
###hists = []
###hists.append( plot.TH2FromTGraph2D(graph, method='BinCenterAligned') )
###plot.fastFillTH2(hists[0], graph,interpolateMissing=True)
###
####limit2 = plot.MakeTChain(['new/higgsCombineCvCf.MultiDimFit.mH125.root',], 'limit')
###limit2 = plot.MakeTChain([args.files[1],], 'limit')
###graph2 = plot.TGraph2DFromTree(
###    limit2, "CV", "CF", '2*deltaNLL', 'quantileExpected > -0.5 && deltaNLL > 0 && deltaNLL < 1000')
###best2 = plot.TGraphFromTree(
###    limit2, "CV", "CF", 'deltaNLL == 0')
###plot.RemoveGraphXDuplicates(best2)
####hists2 = plot.TH2FromTGraph2D(graph2, method='BinCenterAligned')
###hists.append( plot.TH2FromTGraph2D(graph2, method='BinCenterAligned') )
####plot.fastFillTH2(hists2, graph,interpolateMissing=True)
###if args.bg_exp:
###    limit_bg = plot.MakeTChain(args.bg_exp, 'limit')
###    best_bg = plot.TGraphFromTree(
###        limit_bg, "CV", "CF", 'deltaNLL == 0')
###    plot.RemoveGraphXDuplicates(best_bg)
limit = plot.MakeTChain(args.files, 'limit')
print limit
graph = plot.TGraph2DFromTree(
    limit, "CV", "CF", '2*deltaNLL', 'quantileExpected > -0.5 && deltaNLL > 0 && deltaNLL < 1000')
best = plot.TGraphFromTree(
    limit, "CV", "CF", 'deltaNLL == 0')
plot.RemoveGraphXDuplicates(best)
hists = plot.TH2FromTGraph2D(graph, method='BinCenterAligned')
plot.fastFillTH2(hists, graph,interpolateMissing=True)
if args.bg_exp:
    limit_bg = plot.MakeTChain(args.bg_exp, 'limit')
    best_bg = plot.TGraphFromTree(
        limit_bg, "CV", "CF", 'deltaNLL == 0')
    plot.RemoveGraphXDuplicates(best_bg)

# If included just plot SM exp at 1,1
if args.sm_exp:
    limit_sm = plot.MakeTChain(args.sm_exp, 'limit')
    best_sm = ROOT.TGraph( 1, array('d', [1,]), array('d', [1,]))
    plot.RemoveGraphXDuplicates(best_sm)

hists.SetMaximum(6)
hists.SetMinimum(0)
hists.SetContour(255)
# c2=ROOT.TCanvas()
# hists.Draw("COLZ")
# c2.SaveAs("heatmap.png")

#axis = ROOT.TH2D(hists[0].GetName(),hists[0].GetName(),hists[0].GetXaxis().GetNbins(),0,hists[0].GetXaxis().GetXmax(),hists[0].GetYaxis().GetNbins(),0,hists[0].GetYaxis().GetXmax())
axis = ROOT.TH2D(hists.GetName(),hists.GetName(),hists.GetXaxis().GetNbins(),0,2,hists.GetYaxis().GetNbins(),0,2)
axis.Reset()
axis.GetXaxis().SetTitle(args.x_title)
axis.GetXaxis().SetLabelSize(0.025)
axis.GetYaxis().SetLabelSize(0.025)
axis.GetYaxis().SetTitle(args.y_title)

cont_1sigma = plot.contourFromTH2(hists, ROOT.Math.chisquared_quantile_c(1 - 0.68, 2), 10, frameValue=20)
cont_2sigma = plot.contourFromTH2(hists, ROOT.Math.chisquared_quantile_c(1 - 0.95, 2), 10, frameValue=20)
print cont_1sigma
for item in cont_1sigma :
    print item
    #if 'Graph' in item.GetName() or 'Graph' in item.GetTitle() : item.SaveAs('hig-16-043_1sigma.root')
print cont_2sigma
for item in cont_2sigma :
    print item
    #if 'Graph' in item.GetName() or 'Graph' in item.GetTitle() : item.SaveAs('hig-16-043_2sigma.root')

old1 = ROOT.TFile('hig-16-043_1sigma.root','r')
cont_1sigma2 = old1.Get('Graph')
old2 = ROOT.TFile('hig-16-043_2sigma.root','r')
cont_2sigma2 = old2.Get('Graph')

print cont_1sigma2
print cont_2sigma2

if debug is not None:
    debug.WriteTObject(hists, 'hist')
    for i, cont in enumerate(cont_1sigma):
        debug.WriteTObject(cont, 'cont_1sigma_%i' % i)
    for i, cont in enumerate(cont_2sigma):
        debug.WriteTObject(cont, 'cont_2sigma_%i' % i)

if args.sm_exp or args.bg_exp:
    #legend = plot.PositionedLegend(0.47, 0.20, 3, 0.015)
    #legend = plot.PositionedLegend(0.47, 0.26, 4, 0.03)
    legend = plot.PositionedLegend(0.7, 0.2, 4, 0.03)
    legend.SetNColumns(2)
else:
    legend = plot.PositionedLegend(0.3, 0.2, 3, 0.015)

pads[0].cd()
axis.Draw()
for i, p in enumerate(cont_2sigma):
    p.SetLineStyle(1)
    p.SetLineWidth(2)
    p.SetLineColor(ROOT.kBlack)
    p.SetFillColor(ROOT.kBlue-10)
    p.SetFillStyle(1001)
    p.Draw("F SAME")
    p.Draw("L SAME")
    if i > 0 : continue # This odity is from the fits with multiple closed contours
    legend.AddEntry(cont_1sigma[0], "68% CL - Combined, H#rightarrow#tau#tau", "F")

for i, p in enumerate(cont_1sigma):
    p.SetLineStyle(1)
    p.SetLineWidth(2)
    p.SetLineColor(ROOT.kBlack)
    p.SetFillColor(ROOT.kBlue-8)
    p.SetFillStyle(1001)
    p.Draw("F SAME")
    p.Draw("L SAME")
    if i > 0 : continue # This odity is from the fits with multiple closed contours
    legend.AddEntry(cont_2sigma[0], "95% CL - Combined, H#rightarrow#tau#tau", "F")

cont_1sigma2.SetLineWidth(2)
cont_1sigma2.SetLineColor(ROOT.kBlack)
cont_1sigma2.SetLineStyle(2)
cont_1sigma2.Draw("L SAME")
legend.AddEntry(cont_1sigma2, "68% CL - ggH + VBF, H#rightarrow#tau#tau", "L")
cont_2sigma2.SetLineWidth(2)
cont_2sigma2.SetLineColor(ROOT.kBlack)
cont_2sigma2.SetLineStyle(7)
cont_2sigma2.Draw("L SAME")
legend.AddEntry(cont_2sigma2, "95% CL - ggH + VBF, H#rightarrow#tau#tau", "L")


#for i, p in enumerate(cont_2sigma2):
#    p.SetLineStyle(1)
#    p.SetLineWidth(2)
#    p.SetLineColor(ROOT.kBlack)
#    p.SetLineStyle(9)
#    p.SetFillColor(ROOT.kBlue+10)
#    p.SetFillStyle(1001)
#    p.Draw("F SAME")
#    p.Draw("L SAME")
#    legend.AddEntry(cont_1sigma2[0], "68% CL", "L")
#
#for i, p in enumerate(cont_1sigma2):
#    p.SetLineStyle(1)
#    p.SetLineWidth(2)
#    p.SetLineColor(ROOT.kBlack)
#    p.SetLineStyle(9)
#    p.SetFillColor(ROOT.kBlue+8)
#    p.SetFillStyle(1001)
#    p.Draw("F SAME")
#    p.Draw("L SAME")
#    legend.AddEntry(cont_2sigma2[0], "95% CL", "L")

best.SetMarkerStyle(34)
best.SetMarkerSize(3)
best.Draw("P SAME")
legend.AddEntry(best, "Best fit", "P")
#best2.SetMarkerStyle(34)
#best2.SetMarkerSize(2)
#best2.Draw("P SAME")
#legend.AddEntry(best2, "Best fit - HIG-16-043", "P")
if args.sm_exp:
    best_sm.SetMarkerStyle(33)
    best_sm.SetMarkerColor(1)
    best_sm.SetMarkerSize(3.0)
    best_sm.Draw("P SAME")
    legend.AddEntry(best_sm, "Expected for 125 GeV SM Higgs", "P")
if args.bg_exp:
    best_bg.SetMarkerStyle(33)
    best_bg.SetMarkerColor(46)
    best_bg.SetMarkerSize(3)
    best_bg.Draw("P SAME")
    legend.AddEntry(best_bg, "Expected for background only", "P")


if args.mass:
    legend.SetHeader("m_{#phi} = "+args.mass+" GeV")
legend.SetFillStyle( 0 )
legend.Draw("SAME")
if args.sm_exp:
    overlayLegend,overlayGraphs = plot.getOverlayMarkerAndLegend(legend, {legend.GetNRows()-1 : best_sm}, {legend.GetNRows()-1 : {"MarkerColor" : 2}}, markerStyle="P")

plot.DrawCMSLogo(pads[0], 'CMS', args.cms_sub, 11, 0.045, 0.035, 1.2, '', 1.0)
pads[0].cd()
lumi = ROOT.TLatex(.7,1.05,"X fb^{-1} (13 TeV)")
lumi.SetTextSize(0.03)
lumi.DrawTextNDC(.7,.96,"35.9 / fb (13 TeV)" )

plot.DrawTitle(pads[0], args.title_right, 3)
plot.DrawTitle(pads[0], args.title_left, 1)
plot.FixOverlay()
if args.sm_exp:
    best_sm.Draw("P SAME")
    for overlayGraph in overlayGraphs:
        print "test"
        overlayGraph.Draw("P SAME")
    overlayLegend.Draw("SAME")
canv.Print('.pdf')
canv.Print('.png')
canv.Print('.C')
canv.Close()

if debug is not None:
    debug.Close()
