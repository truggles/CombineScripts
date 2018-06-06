#!/usr/bin/env python
import ROOT
import re
from array import array
import argparse
from poisson import convert
from poisson import poisson_errors
from poisson import getTH1FfromTGraphAsymmErrors

parser = argparse.ArgumentParser(
    "Create pre/post-fit plots for SM HTT")
parser.add_argument(
    "--fs",
    action="store",
    dest="fs",
    default="emt",
    help="Which channel to run over? (emt, mmt, ett, mtt, whlep, whhad, wh, zh, eeem, eeet, eemt, eett, emmm, emmt, mmtt, mmmt, llem, llet, llmt, lltt)")
parser.add_argument(
    "--fit",
    action="store",
    dest="fit",
    default="postfit",
    help="Prefit or postfit? choose prefit or postfit")
parser.add_argument(
    "--ratio",
    action="store",
    dest="ratio",
    default="default",
    help="default == obs/(bkg+sig), nonDefault = obs/bkg with signal added")
parser.add_argument(
    "--unblind",
    action="store",
    dest="unblind",
    default=False,
    help="Ready to unblind? default is unblind=False, use --unblind=1 to unblind")
args = parser.parse_args()
fs=args.fs
fit=args.fit
ratio=args.ratio
unblind=args.unblind
assert( fit in ["prefit","postfit"] ), "Choice was not a valid fit argument: %s" % fit

if fit == "prefit" :
    prepend = "shapes_prefit/"
    output_dir = "prefit"
if fit == "postfit" :
    prepend = "shapes_fit_s/"
    output_dir = "postfit"
output_dir = "/afs/cern.ch/user/t/truggles/www/post-fit2/"+output_dir

def print_yields( h, name ) :
    err = ROOT.Double(0.)
    #print h.IntegralAndError( 1, h.GetNbinsX() + 1, err )
    h.IntegralAndError( 1, h.GetNbinsX() + 1, err )
    #print h.Integral()
    print "%15s: %.3f \pm %.3f   &" % (name, h.Integral(), err)

def add_lumi():
    lowX=0.58
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.06)
    lumi.SetTextFont (   42 )
    lumi.AddText("35.9 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.05)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend( ratioLegend=False, shape="zh" ):
        #output = ROOT.TLegend(0.70, 0.40, 0.92, 0.84, "", "brNDC")
        if not ratioLegend :
            output = ROOT.TLegend(0.43, 0.55, 0.93, 0.84, "", "brNDC")
            output.SetNColumns(2)
        else :
            if shape == "zh" :
                output = ROOT.TLegend(0.61, 0.71, 0.93, 0.94, "", "brNDC")
                output.SetNColumns(1)
            else : # should be wh
                output = ROOT.TLegend(0.36, 0.75, 0.89, 0.94, "", "brNDC")
                output.SetNColumns(2)
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        #output.SetFillStyle(0)
        output.SetFillStyle(1001)
        output.SetFillColor(ROOT.kWhite)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output

ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,600,600)
c.cd()

file=ROOT.TFile("official_plotted_fitDiagnostics.root","r")
#print file

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

wh_channels=["ch9","ch11","ch10","ch12"]
zh_channels=["ch1","ch5","ch2","ch6","ch3","ch7","ch4","ch8"]
channels=[]
set_max = 10
if fs=="emt":
  channels=["ch9"]
  cat_text = "e#mu#tau_{h}"
  set_max = 17
if fs=="mmt":
  channels=["ch11"]
  cat_text = "#mu#mu#tau_{h}"
  set_max = 25
if fs=="ett":
  channels=["ch10"]
  cat_text = "e#tau_{h}#tau_{h}"
  set_max = 12
if fs=="mtt":
  channels=["ch12"]
  cat_text = "#mu#tau_{h}#tau_{h}"
  set_max = 16
if fs=="eeem":
  channels=["ch1"]
  cat_text = "ee+e#mu"
  set_max = 7
  lt_num = 50
if fs=="eeet":
  channels=["ch2"]
  cat_text = "ee+e#tau_{h}"
  lt_num = 60
if fs=="eemt":
  channels=["ch3"]
  cat_text = "ee+#mu#tau_{h}"
  lt_num = 60
  set_max = 15
if fs=="eett":
  channels=["ch4"]
  cat_text = "ee+#tau_{h}#tau_{h}"
  lt_num = 75
if fs=="emmm":
  channels=["ch5"]
  cat_text = "#mu#mu+e#mu"
  set_max = 7
  lt_num = 50
if fs=="emmt":
  channels=["ch6"]
  cat_text = "#mu#mu+e#tau_{h}"
  lt_num = 60
if fs=="mmmt":
  channels=["ch7"]
  cat_text = "#mu#mu+#mu#tau_{h}"
  lt_num = 60
if fs=="mmtt":
  channels=["ch8"]
  cat_text = "#mu#mu+#tau_{h}#tau_{h}"
  lt_num = 75
if fs=="llem":
  channels=["ch1","ch5"]
  cat_text = "ll+e#mu"
  lt_num = 50
if fs=="llet":
  channels=["ch2","ch6"]
  cat_text = "ll+e#tau_{h}"
  lt_num = 60
  set_max = 16
if fs=="llmt":
  channels=["ch3","ch7"]
  cat_text = "ll+#mu#tau_{h}"
  lt_num = 60
if fs=="lltt":
  channels=["ch4","ch8"]
  cat_text = "ll+#tau_{h}#tau_{h}"
  lt_num = 75
if fs=="zh":
  channels=zh_channels
  cat_text = "ZH combined"
  lt_num = ""
if fs=="whlep":
  channels=["ch9","ch11"]
  cat_text = "WH semileptonic"
  set_max = 40
if fs=="whhad":
  channels=["ch10","ch12"]
  cat_text = "WH hadronic"
  set_max = 22
if fs=="wh":
  channels=wh_channels
  cat_text = "WH combined"
  set_max = 55

nchan=len(channels)
print fs
#print channels

#print file.Get(prepend+channels[0])
#print file.Get(prepend+channels[0]).Get("data")
data_graph=file.Get(prepend+channels[0]).Get("data")
Data=getTH1FfromTGraphAsymmErrors( data_graph, "data" )
Data.Sumw2(ROOT.kFALSE)
Data.SetBinErrorOption(ROOT.TH1.kPoisson)
#Data=file.Get(prepend+channels[0]).Get("data")
#print Data
ZZ=file.Get(prepend+channels[0]).Get("ZZ")
if file.Get(prepend+channels[0]).Get("ggZZ"):
  ZZ.Add(file.Get(prepend+channels[0]).Get("ggZZ"))
WZ=file.Get(prepend+channels[0]).Get("WZ")
#print file.Get(prepend+channels[0]).Get("WZ")
Rare=file.Get(prepend+channels[0]).Get("ttZ")
if file.Get(prepend+channels[0]).Get("TT"):
 Rare.Add(file.Get(prepend+channels[0]).Get("TT"))
if file.Get(prepend+channels[0]).Get("allFakes"):
  Fake=file.Get(prepend+channels[0]).Get("allFakes")
if file.Get(prepend+channels[0]).Get("RedBkg"):
  Fake=file.Get(prepend+channels[0]).Get("RedBkg")
if file.Get(prepend+channels[0]).Get("jetFakes"):
  Fake=file.Get(prepend+channels[0]).Get("jetFakes")
#print prepend+channels[0]
WH=file.Get(prepend+channels[0]).Get("WH_htt")
ZH=file.Get(prepend+channels[0]).Get("ZH_htt")
VH=file.Get(prepend+channels[0]).Get("WH_htt").Clone()
VH.Add(file.Get(prepend+channels[0]).Get("ZH_htt").Clone())
VHfill=file.Get(prepend+channels[0]).Get("WH_htt").Clone()
VHfill.Add(file.Get(prepend+channels[0]).Get("ZH_htt").Clone())
#Total=file.Get(prepend+channels[0]).Get("total_background")
Total=file.Get(prepend+channels[0]).Get("total_background")
TotalAll=file.Get(prepend+channels[0]).Get("total")
if file.Get(prepend+channels[0]).Get("DY"):
  Rare.Add(file.Get(prepend+channels[0]).Get("DY"))
if file.Get(prepend+channels[0]).Get("ttW"): 
  Rare.Add(file.Get(prepend+channels[0]).Get("ttW"))
if file.Get(prepend+channels[0]).Get("TriBoson"):
  Rare.Add(file.Get(prepend+channels[0]).Get("TriBoson"))
if file.Get(prepend+channels[0]).Get("WH_hww125"):
  Rare.Add(file.Get(prepend+channels[0]).Get("WH_hww125"))
if file.Get(prepend+channels[0]).Get("ZH_hww125"):
  Rare.Add(file.Get(prepend+channels[0]).Get("ZH_hww125"))
if file.Get(prepend+channels[0]).Get("ggH_hzz125"):
  Rare.Add(file.Get(prepend+channels[0]).Get("ggH_hzz125"))
if file.Get(prepend+channels[0]).Get("ttH_other125"):
  Rare.Add(file.Get(prepend+channels[0]).Get("ttH_other125"))
if file.Get(prepend+channels[0]).Get("ttHnonBB"):
  Rare.Add(file.Get(prepend+channels[0]).Get("ttHnonBB"))
if channels[0] not in wh_channels and file.Get(prepend+channels[0]).Get("WZ"):
  Rare.Add(file.Get(prepend+channels[0]).Get("WZ"))

for i in range (1,nchan):
   data_graph=file.Get(prepend+channels[i]).Get("data")
   data_hist=getTH1FfromTGraphAsymmErrors( data_graph )
   data_hist.Sumw2(ROOT.kFALSE)
   data_hist.SetBinErrorOption(ROOT.TH1.kPoisson)
   Data.Add(data_hist)
   ZZ.Add(file.Get(prepend+channels[i]).Get("ZZ"))
   if file.Get(prepend+channels[i]).Get("ggZZ"):
     ZZ.Add(file.Get(prepend+channels[i]).Get("ggZZ"))
   if channels[i] in wh_channels :
     WZ.Add(file.Get(prepend+channels[i]).Get("WZ"))
   if file.Get(prepend+channels[i]).Get("DY"): 
     Rare.Add(file.Get(prepend+channels[i]).Get("DY"))
   if file.Get(prepend+channels[i]).Get("TT"): 
     Rare.Add(file.Get(prepend+channels[i]).Get("TT"))
   if file.Get(prepend+channels[i]).Get("allFakes"): 
     Fake.Add(file.Get(prepend+channels[i]).Get("allFakes"))
   if file.Get(prepend+channels[i]).Get("RedBkg"): 
     Fake.Add(file.Get(prepend+channels[i]).Get("RedBkg"))
   if file.Get(prepend+channels[i]).Get("jetFakes"): 
     Fake.Add(file.Get(prepend+channels[i]).Get("jetFakes"))
   WH.Add(file.Get(prepend+channels[i]).Get("WH_htt"))
   ZH.Add(file.Get(prepend+channels[i]).Get("ZH_htt"))
   VH.Add(file.Get(prepend+channels[i]).Get("WH_htt").Clone())
   VH.Add(file.Get(prepend+channels[i]).Get("ZH_htt").Clone())
   VHfill.Add(file.Get(prepend+channels[i]).Get("WH_htt").Clone())
   VHfill.Add(file.Get(prepend+channels[i]).Get("ZH_htt").Clone())
   if file.Get(prepend+channels[i]).Get("ttZ"):
     Rare.Add(file.Get(prepend+channels[i]).Get("ttZ"))
   if file.Get(prepend+channels[i]).Get("ttW"):
     Rare.Add(file.Get(prepend+channels[i]).Get("ttW"))
   if file.Get(prepend+channels[i]).Get("TriBoson"):
     Rare.Add(file.Get(prepend+channels[i]).Get("TriBoson"))
   if file.Get(prepend+channels[i]).Get("WH_hww125"):
     Rare.Add(file.Get(prepend+channels[i]).Get("WH_hww125"))
   if file.Get(prepend+channels[i]).Get("ZH_hww125"):
     Rare.Add(file.Get(prepend+channels[i]).Get("ZH_hww125"))
   if file.Get(prepend+channels[i]).Get("ggH_hzz125"): 
     Rare.Add(file.Get(prepend+channels[i]).Get("ggH_hzz125"))
   if file.Get(prepend+channels[0]).Get("ttH_other125"):
     Rare.Add(file.Get(prepend+channels[0]).Get("ttH_other125"))
   if file.Get(prepend+channels[0]).Get("ttHnonBB"):
     Rare.Add(file.Get(prepend+channels[0]).Get("ttHnonBB"))
   if channels[i] not in wh_channels and file.Get(prepend+channels[i]).Get("WZ"):
     Rare.Add(file.Get(prepend+channels[i]).Get("WZ"))

   Total.Add(file.Get(prepend+channels[i]).Get("total_background"))
   TotalAll.Add(file.Get(prepend+channels[i]).Get("total"))

#if fit == "prefit" :
#    WH.Scale(5./6.5 / 2.34)
#    ZH.Scale(5./6.5 / 2.34)
#if fit == "postfit" :
#    WH.Scale(5. / 2.34) # 2.34 is signal str
#    ZH.Scale(5. / 2.34)

WH.GetXaxis().SetTitle("")
WH.GetXaxis().SetTitleSize(0)
WH.GetXaxis().SetNdivisions(505)
WH.GetYaxis().SetLabelFont(42)
WH.GetYaxis().SetLabelOffset(0.01)
WH.GetYaxis().SetLabelSize(0.06)
WH.GetYaxis().SetTitleSize(0.075)
WH.GetYaxis().SetTitleOffset(1.04)
WH.SetTitle("")
if channels[0] in wh_channels :
    WH.GetYaxis().SetTitle("Events / 10 GeV")
else :
    WH.GetYaxis().SetTitle("Events / 20 GeV")
WH.SetMinimum(0)
WH.SetMarkerStyle(20)
WH.SetMarkerSize(1)
WH.GetXaxis().SetLabelSize(0)

VH.GetXaxis().SetTitle("")
VH.GetXaxis().SetTitleSize(0)
VH.GetXaxis().SetNdivisions(505)
VH.GetYaxis().SetLabelFont(42)
VH.GetYaxis().SetLabelOffset(0.01)
VH.GetYaxis().SetLabelSize(0.06)
VH.GetYaxis().SetTitleSize(0.075)
VH.GetYaxis().SetTitleOffset(1.04)
VH.SetTitle("")
if channels[0] in wh_channels :
    VH.GetYaxis().SetTitle("Events / 10 GeV")
else :
    VH.GetYaxis().SetTitle("Events / 20 GeV")
VH.SetMinimum(0)
VH.SetMarkerStyle(20)
VH.SetMarkerSize(1)
VH.GetXaxis().SetLabelSize(0)

Data.Sumw2(ROOT.kFALSE)
Data.SetBinErrorOption(ROOT.TH1.kPoisson)
Data.GetXaxis().SetTitle("")
Data.GetXaxis().SetTitleSize(0)
Data.GetXaxis().SetNdivisions(505)
Data.GetYaxis().SetLabelFont(42)
Data.GetYaxis().SetLabelOffset(0.01)
Data.GetYaxis().SetLabelSize(0.06)
Data.GetYaxis().SetTitleSize(0.075)
Data.GetYaxis().SetTitleOffset(1.04)
Data.SetTitle("")
Data.GetYaxis().SetTitle("Events/bin")

if channels[0] in wh_channels :
 WZ.SetFillColor(ROOT.TColor.GetColor("#efe7ae"))
ZZ.SetFillColor(ROOT.TColor.GetColor("#11e7ae"))
Fake.SetFillColor(ROOT.TColor.GetColor("#a278aa"))
Rare.SetFillColor(ROOT.TColor.GetColor("#3e125f"))
VHfill.SetFillColor(ROOT.kRed)
WH.SetLineWidth(4)
ZH.SetLineWidth(4)
VH.SetLineWidth(4)
#VHfill = VH.Clone()

Data.SetMarkerStyle(20)
Data.SetLineColor(1)
Data.SetMarkerSize(1)
Fake.SetLineColor(1)
if channels[0] in wh_channels :
  WZ.SetLineColor(1)
ZZ.SetLineColor(1)
Rare.SetLineColor(1)
VHfill.SetLineColor(1)
Total.SetLineColor(1)
ZH.SetLineColor(2)
WH.SetLineColor(9)
VH.SetLineColor(ROOT.kRed)

errorBand=TotalAll.Clone()
for b in range( 1, errorBand.GetNbinsX()+1 ) :
    errorBand.SetBinError( b, TotalAll.GetBinError( b ) )
errorBandBkg=Total.Clone()
for b in range( 1, errorBandBkg.GetNbinsX()+1 ) :
    errorBandBkg.SetBinError( b, Total.GetBinError( b ) )

stack=ROOT.THStack("stack","stack")
stack.Add(Fake)
stack.Add(Rare)
stack.Add(ZZ)
if channels[0] in wh_channels :
  stack.Add(WZ)
stack.Add(VHfill)

#print "ZZ: %.2f" % ZZ.Integral()
print_yields( ZZ, 'ZZ' )
if channels[0] in wh_channels :
  #print "WZ: %.2f" % WZ.Integral()
  print_yields( WZ, 'WZ' )
print_yields( Rare, 'Rare' )
print_yields( Fake, 'Fake' )
print_yields( WH, 'WH' )
print_yields( ZH, 'ZH' )
print_yields( VH, 'VH' )
print_yields( Data, 'Data' )

print "WH / VH = %.4f" % (( WH.Integral() / VH.Integral() ) * 100.)
print "ZH / VH = %.4f" % (( ZH.Integral() / VH.Integral() ) * 100.)
#print "Rare: %.2f" % Rare.Integral()
#print "Fake: %.2f" % Fake.Integral()
#print "WH: %.2f" % WH.Integral()
#print "ZH: %.2f" % ZH.Integral()
#print "Data: %.2f" % Data.Integral()

errorBand.SetMarkerSize(0)
errorBand.SetFillColor(new_idx)
errorBand.SetFillStyle(3001)
errorBand.SetLineWidth(0)
errorBandBkg.SetMarkerSize(0)
errorBandBkg.SetFillColor(new_idx)
errorBandBkg.SetFillStyle(3001)
errorBandBkg.SetLineWidth(0)

pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
pad1.Draw()
pad1.cd()
pad1.SetFillColor(0)
pad1.SetBorderMode(0)
pad1.SetBorderSize(10)
pad1.SetTickx(1)
pad1.SetTicky(1)
pad1.SetLeftMargin(0.18)
pad1.SetRightMargin(0.05)
pad1.SetTopMargin(0.122)
pad1.SetBottomMargin(0.026)
pad1.SetFrameFillStyle(0)
pad1.SetFrameLineStyle(0)
pad1.SetFrameLineWidth(3)
pad1.SetFrameBorderMode(0)
pad1.SetFrameBorderSize(10)

Data.GetXaxis().SetLabelSize(0)

# Blinding
if not unblind :
    for k in range(1,Data.GetSize()-1):
         s=WH.GetBinContent(k)+ZH.GetBinContent(k)
         b=ZZ.GetBinContent(k)+Fake.GetBinContent(k)
         if channels[0] in wh_channels :
           b=ZZ.GetBinContent(k)+Fake.GetBinContent(k)+WZ.GetBinContent(k)
         if (b<0):
             b=0.000001
         if (0.2*s/(0.00001+0.05*s+b)**0.5 > 0.15):
             Data.SetBinContent(k,-10)
             Data.SetBinError(k,0)
         # blind ZH on mass peak for high LT always
         if channels[0] in zh_channels and (k == 15 or k == 16) :
             Data.SetBinContent(k,-10)
             Data.SetBinError(k,0)
Data.SetMinimum(0)

Poisson=convert(Data)
Poisson.GetXaxis().SetTitle("")
Poisson.GetXaxis().SetTitleSize(0)
Poisson.GetXaxis().SetNdivisions(505)
Poisson.GetYaxis().SetLabelFont(42)
Poisson.GetYaxis().SetLabelOffset(0.01)
Poisson.GetYaxis().SetLabelSize(0.06)
Poisson.GetYaxis().SetTitleSize(0.075)
Poisson.GetYaxis().SetTitleOffset(1.04)
Poisson.SetTitle("")
Poisson.GetYaxis().SetTitle("Events/bin")
Poisson.SetMinimum(0)
Poisson.SetMarkerStyle(20)
Poisson.SetLineColor(1)
Poisson.SetMarkerSize(1)
Poisson.GetXaxis().SetLabelSize(0)

# Poisson errors are large, make max 10 or greater
#WH.SetMaximum( 
VH.SetMaximum( 
    max( Poisson.GetMaximum()*2.0, stack.GetMaximum()*2.0,
    Data.GetMaximum()*2.0,stack.GetMaximum()*2.0, set_max) )

# Check all bins to see if bin yield is zero (this is happening
# to WH postfit for some reason...) and limit range if so
emptyBins = []
for b in range(1, Total.GetXaxis().GetNbins()+ 1 ) :
    if Total.GetBinContent(b) == 0 and Data.GetBinContent(b) <= 0 :
        print "both equal zero. skip bin",b
        emptyBins.append( b )
print "To skip:",emptyBins

if len( emptyBins ) > 0 :
    #WH.GetXaxis().SetRange(1,emptyBins[0]-1)
    VH.GetXaxis().SetRange(1,emptyBins[0]-1)
    print "Limiting range from bins: %i - %i" % (1, emptyBins[0]-1 )

#Poisson.Draw("AP")
#Data.Draw("e0")
#WH.Draw("hist")
VH.Draw("hist")
stack.Draw("histsame")
errorBand.Draw("e2same")
#WH.Draw("histsame")
#ZH.Draw("histsame")
VH.Draw("histsame")
#Data.Draw("e0same")
Poisson.Draw("P 0")

### TLine
zh_center = VH.GetXaxis().GetNbins() / 2
if channels[0] not in wh_channels :
    line = ROOT.TLine( zh_center, 0, zh_center, VH.GetMaximum() )
    line.SetLineColor( ROOT.kBlack )
    line.SetLineStyle( 2 )
    line.SetLineWidth( 2 )
    line.Draw()

legende=make_legend()
legende.AddEntry(Data,"Observed","elp")
if channels[0] in wh_channels :
  legende.AddEntry(WZ,"WZ#rightarrow 3l#nu","f")
legende.AddEntry(ZZ,"ZZ#rightarrow 4l","f")
legende.AddEntry(Rare,"Rare","f")
legende.AddEntry(Fake,"Reducible","f")
legende.AddEntry(VHfill,"VH, H#rightarrow#tau#tau (#mu=2.5)","f")
#legende.AddEntry(WH,"WH, H#rightarrow#tau#tau (#mu=2.5)","l")
#legende.AddEntry(ZH,"ZH, H#rightarrow#tau#tau (#mu=2.5)","l")
legende.AddEntry(VH,"VH, H#rightarrow#tau#tau (#mu=2.5)","l")
legende.AddEntry(errorBand,"Uncertainty","f")
legende.Draw()
# To make sure it is on top!
Poisson.Draw("P 0")

l1=add_lumi()
l1.Draw("same")
l2=add_CMS()
l2.Draw("same")
l3=add_Preliminary()
l3.Draw("same")

pad1.RedrawAxis()

categ  = ROOT.TPaveText(0.21, 0.45+0.013, 0.38, 0.70+0.155, "NDC")
categ.SetBorderSize(   0 )
categ.SetFillStyle(    0 )
categ.SetTextAlign(   12 )
categ.SetTextSize ( 0.05 )
categ.SetTextColor(    1 )
categ.SetTextFont (   42 )
categ.AddText( cat_text )

categ.Draw()

# For ZH LT Regions
if channels[0] not in wh_channels :

    lt_txt_low = "L_{T}^{Higgs} < %s" % lt_num
    lt_txt_high = "L_{T}^{Higgs} > %s" % lt_num
    if fs=="zh":
        lt_txt_low = "Low L_{T}^{Higgs}"
        lt_txt_high = "High L_{T}^{Higgs}"

    #lt_1  = ROOT.TPaveText(0.415, 0.5, 0.57, 0.60, "NDC")
    lt_1  = ROOT.TPaveText(0.415, 0.45, 0.57, 0.55, "NDC")
    lt_1.SetBorderSize(   0 )
    lt_1.SetFillStyle(    0 )
    lt_1.SetTextAlign(   12 )
    lt_1.SetTextSize ( 0.0475 )
    lt_1.SetTextColor(    1 )
    lt_1.SetTextFont (   42 )
    lt_1.AddText( lt_txt_low )
    lt_1.Draw()

    #lt_2  = ROOT.TPaveText(0.5625, 0.5, 0.71, 0.60, "NDC")
    lt_2  = ROOT.TPaveText(0.5625, 0.45, 0.71, 0.55, "NDC")
    lt_2.SetBorderSize(   0 )
    lt_2.SetFillStyle(    0 )
    lt_2.SetTextAlign(   12 )
    lt_2.SetTextSize ( 0.0475 )
    lt_2.SetTextColor(    1 )
    lt_2.SetTextFont (   42 )
    lt_2.AddText( lt_txt_high )
    lt_2.Draw()

c.cd()
# Ratio plot
pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
pad2.SetTopMargin(0.05);
pad2.SetBottomMargin(0.35);
pad2.SetLeftMargin(0.18);
pad2.SetRightMargin(0.05);
pad2.SetTickx(1)
pad2.SetTicky(1)
pad2.SetFrameLineWidth(3)
pad2.SetGridx()
pad2.SetGridy()
pad2.Draw()
pad2.cd()
h1=Data.Clone()
h1.Sumw2()
h1.Add( -1 * Total )
hp=Poisson.Clone()
hp.SetMarkerStyle(20)
h1.SetMarkerStyle(20)
if ratio == "default" :
    h3=errorBand.Clone()
    h3.Sumw2()
    hwoE=errorBand.Clone()
else :
    h3=errorBandBkg.Clone()
    hwoE=errorBandBkg.Clone()
p_x=hp.GetX()
p_y=hp.GetY()

# If an empty data bin was set to negative for plotting purposes,
# reset it to zero for ratio plot.
x_val = ROOT.Double(0.)
y_val = ROOT.Double(0.)
for iii in range( len(p_x) ) :
  if y_val < 0. :
    hp.SetPoint( iii, x_val, 0. )
    

#print p_x[0],p_x[1],hwoE.GetBinContent(1)
for iii in range (0,hwoE.GetSize()-2):
  hwoE.SetBinError(iii+1,0)
  #print iii,p_x[iii],p_y[iii],p_y[iii]/max(hwoE.GetBinContent(iii+1),1e-5),h3.GetBinContent(iii+1)
  #print iii, hp.GetErrorYhigh(iii), hwoE.GetBinContent(iii+1),  hp.GetErrorYlow(iii), hwoE.GetBinContent(iii+1)
  #print iii, p_y[iii], hwoE.GetBinContent(iii+1)

  # Make sure it goes off the bottom of the ratio plot!!!
  if p_y[iii] < 0. :
    hp.SetPoint(iii,p_x[iii],-0.03)
    hp.SetPointEYlow(iii,-0.03)
  else :
    hp.SetPoint(iii,p_x[iii],p_y[iii]/max(hwoE.GetBinContent(iii+1),1e-5))
    hp.SetPointEYlow(iii,hp.GetErrorYlow(iii)/max(hwoE.GetBinContent(iii+1),1e-5))
  hp.SetPointEYhigh(iii,hp.GetErrorYhigh(iii)/max(hwoE.GetBinContent(iii+1),1e-5))
h1.SetStats(0)
#h1.Divide(hwoE)
#h3.Divide(hwoE)
h1.GetXaxis().SetTitle("m_{vis} (GeV)")
if channels[0] not in wh_channels :
   h1.GetXaxis().SetTitle("m_{#tau#tau} (GeV)")
h1.GetXaxis().SetNdivisions(505)
h1.GetYaxis().SetNdivisions(5)

h3.GetXaxis().SetTitle("m_{vis} (GeV)")
if channels[0] not in wh_channels :
   h3.GetXaxis().SetTitle("m_{#tau#tau} (GeV)")
h3.GetXaxis().SetNdivisions(505)
h3.GetYaxis().SetNdivisions(5)
h3.SetTitle("")
if ratio == "default" :
    h1.GetYaxis().SetTitle("Obs./(Bkg. + Sig.)")
    h3.GetYaxis().SetTitle("Obs./(Bkg. + Sig.)")
else :
    h1.GetYaxis().SetTitle("(Obs. - Bkg.)/Bkg.")
    h3.GetYaxis().SetTitle("(Obs. - Bkg.)/Bkg.")
h3.GetXaxis().SetTitleSize(0.12)
h3.GetYaxis().SetTitleSize(0.12)
h3.GetYaxis().SetTitleOffset(0.56)
h3.GetXaxis().SetTitleOffset(1.25)
h3.GetXaxis().SetLabelSize(0.09)
h3.GetYaxis().SetLabelSize(0.11)
#for b in range( 1, Data.GetXaxis().GetNbins()+1 ) :
#    if channels[0] in wh_channels :
#        text = "%i - %i" % ( ((b+1) * 10), (b+2) * 10)
#    else : # ZH
#        if b < 11 :
#            text = "%i - %i" % ( ((b) * 20), (( (b+1)) * 20) )
#        else :
#            text = "%i - %i" % ( ((b) * 20)-200, (( (b+1)) * 20)-200 )
#    h3.GetXaxis().SetBinLabel( b, text ) 
#h3.GetXaxis().SetBit( ROOT.TAxis.kLabelsVert )
h3.GetXaxis().SetLabelOffset(0.02)
h3.GetXaxis().SetTitleFont(42)
h3.GetYaxis().SetTitleFont(42)
    

mini = 0.0
maxi = 3.0
if ratio != "default" :
    mini = -0.5
    maxi = 2.0
h3.SetMaximum(maxi)
h3.SetMinimum(mini)
h1.SetMaximum(maxi)
h1.SetMinimum(mini)

if ratio != "default" :
    signal = VH.Clone()
    signal.Sumw2()
    signal.Divide(Total)
    signal.SetMaximum(maxi)
    signal.SetMinimum(mini)
    h1.Divide(Total)
    h3.Divide(Total)
    for b in range( 1, h3.GetXaxis().GetNbins()+1 ) :
        h3.SetBinContent( b, 0 )

if len( emptyBins ) > 0 :
    h3.GetXaxis().SetRange(1,emptyBins[0]-1 )
    h1.GetXaxis().SetRange(1,emptyBins[0]-1 )
    if ratio != "default" :
        signal.GetXaxis().SetRange(1,emptyBins[0]-1 )
    print "Limiting range from bins: %i - %i" % (1, emptyBins[0]-1 )


h3.Draw("e2")
print h3.GetXaxis().GetLabelOffset()
h3.GetXaxis().SetLabelOffset( h3.GetXaxis().GetLabelOffset() * 2 )
ROOT.gPad.SetGridx(0)
#h3.GetXaxis().ChangeLabel(-1,-1,-1,-1,-1,-1,"-#pi")
if fs in ["emt", "ett", "mmt", "mtt","whhad","whlep","wh"] :
    if fs in ["ett", "mtt", "whhad", "wh"] : # had
        h3.GetXaxis().SetNdivisions(12, ROOT.kFALSE)
        for j in range( 1, 14 ) :
            h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % (j*10 + 10))
    else : # semilep
        h3.GetXaxis().SetNdivisions(11, ROOT.kFALSE)
        for j in range( 1, 13 ) :
            h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % (j*10 + 10))
else : # is ZH
    h3.GetXaxis().SetNdivisions(20, ROOT.kFALSE)
    for j in range( 1, 22 ) :
        if j < 11 :
            h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % (j*20))
        elif j == 11 :
            h3.GetXaxis().ChangeLabel(j,45,.07,-1,-1,-1,"220/20")
        else :
            h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % ((j-10)*20))

h3.Draw("e2")

# Get signal for ratio plot if not default
if ratio != "default" :
    signal.Draw("histsame")
    #h1.SetMarkerSize(0)
    h1.Draw("E0 E1 same")
else :
    hp.Draw("P 0")

if channels[0] not in wh_channels :
    line2 = ROOT.TLine( zh_center, mini, zh_center, maxi )
    line2.SetLineColor( ROOT.kBlack )
    line2.SetLineStyle( 2 )
    line2.SetLineWidth( 2 )
    line2.Draw()

if ratio != "default" :
    ratioLegend=True
    legend1=make_legend( ratioLegend, fs )
    legend1.AddEntry(h1,"(Obs. - Bkg.) / Bkg.","elp")
    legend1.AddEntry(signal,"VH, H#rightarrow#tau#tau / Bkg.  (#mu=2.5)","l")
    legend1.Draw()

if ratio != "default" :
    #h1.SetMarkerSize(0)
    h1.Draw("E0 E1 same")
else :
    hp.Draw("P 0 same")

c.cd()
pad1.Draw()

ROOT.gPad.RedrawAxis()

c.Modified()
app = "" if ratio == "default" else "_modRatio"
c.SaveAs(output_dir+"/"+fs+"_"+fit+app+".png")
c.SaveAs(output_dir+"/"+fs+"_"+fit+app+".pdf")


