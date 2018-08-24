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
    "--unblind",
    action="store",
    dest="unblind",
    default=False,
    help="Ready to unblind? default is unblind=False, use --unblind=1 to unblind")
args = parser.parse_args()
fs=args.fs
fit=args.fit
unblind=args.unblind
assert( fit in ["prefit","postfit"] ), "Choice was not a valid fit argument: %s" % fit

if fit == "prefit" :
    prepend = "shapes_prefit/"
    output_dir = "prefit"
if fit == "postfit" :
    prepend = "shapes_fit_s/"
    output_dir = "postfit"
output_dir = "/afs/cern.ch/user/t/truggles/www/mssm_plots_aug22v2/"+output_dir

azhScale = 10

def print_yields( h, name ) :
    err = ROOT.Double(0.)
    #print h.IntegralAndError( 1, h.GetNbinsX() + 1, err )
    h.IntegralAndError( 1, h.GetNbinsX() + 1, err )
    #print h.Integral()
    print "%15s: %.3f \pm %.3f   &" % (name, h.Integral(), err)

def add_lumi():
    lowX=0.67
    lowY=0.82
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

def make_legend():
        #output = ROOT.TLegend(0.70, 0.40, 0.92, 0.84, "", "brNDC")
        output = ROOT.TLegend(0.43, 0.55, 0.93, 0.84, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        #output.SetFillStyle(0)
        output.SetFillStyle(1001)
        output.SetFillColor(ROOT.kWhite)
        output.SetBorderSize(0)
        output.SetNColumns(2)
        output.SetTextFont(62)
        return output

ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)

c=ROOT.TCanvas("canvas","",0,0,600,600)
c.cd()

file=ROOT.TFile("fitDiagnostics_withAsimov2.root","r")
print file

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

wh_channels=["ch9","ch11","ch10","ch12"]
zh_channels=["ch1","ch5","ch2","ch6","ch3","ch7","ch4","ch8"]
channels=[]
set_max = 10
if fs=="eeem":
  channels=["ch1",]
  cat_text = "ee+e#mu"
  set_max = 7
  lt_num = 50
if fs=="eeet":
  channels=["ch2",]
  cat_text = "ee+e#tau_{h}"
  lt_num = 60
  set_max = 5
if fs=="eemt":
  channels=["ch3",]
  cat_text = "ee+#mu#tau_{h}"
  lt_num = 60
  set_max = 15
if fs=="eett":
  channels=["ch4",]
  cat_text = "ee+#tau_{h}#tau_{h}"
  lt_num = 75
if fs=="emmm":
  channels=["ch5",]
  cat_text = "#mu#mu+e#mu"
  set_max = 7
  lt_num = 50
if fs=="emmt":
  channels=["ch6",]
  cat_text = "#mu#mu+e#tau_{h}"
  lt_num = 60
if fs=="mmmt":
  channels=["ch7",]
  cat_text = "#mu#mu+#mu#tau_{h}"
  lt_num = 60
if fs=="mmtt":
  channels=["ch8",]
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

nchan=len(channels)
print fs
print channels
print prepend+channels[0]

print file.Get(prepend+channels[0])
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
#XXX WH=file.Get(prepend+channels[0]).Get("WH_htt125")
#XXX ZH=file.Get(prepend+channels[0]).Get("ZH_htt125")
AZH=file.Get(prepend+channels[0]).Get("azh").Clone()
VH=file.Get(prepend+channels[0]).Get("ZH_htt125").Clone()
smHiggs=file.Get(prepend+channels[0]).Get("ZH_htt125").Clone()
if file.Get(prepend+channels[0]).Get("WH_htt125"):
  VH.Add(file.Get(prepend+channels[0]).Get("WH_htt125").Clone())
  smHiggs.Add(file.Get(prepend+channels[0]).Get("WH_htt125").Clone())
#Total=file.Get(prepend+channels[0]).Get("total_background")
Total=file.Get(prepend+channels[0]).Get("total_background")
#TotalAll=file.Get(prepend+channels[0]).Get("total")
TotalAll=file.Get(prepend+channels[0]).Get("total_background")
if file.Get(prepend+channels[0]).Get("DY"):
  Rare.Add(file.Get(prepend+channels[0]).Get("DY"))
if file.Get(prepend+channels[0]).Get("ttW"): 
  Rare.Add(file.Get(prepend+channels[0]).Get("ttW"))
if file.Get(prepend+channels[0]).Get("TriBoson"):
  Rare.Add(file.Get(prepend+channels[0]).Get("TriBoson"))
if file.Get(prepend+channels[0]).Get("WH_hww125"):
  smHiggs.Add(file.Get(prepend+channels[0]).Get("WH_hww125"))
if file.Get(prepend+channels[0]).Get("ZH_hww125"):
  smHiggs.Add(file.Get(prepend+channels[0]).Get("ZH_hww125"))
if file.Get(prepend+channels[0]).Get("ggH_hzz125"):
  smHiggs.Add(file.Get(prepend+channels[0]).Get("ggH_hzz125"))
if file.Get(prepend+channels[0]).Get("ttH_other125"):
  smHiggs.Add(file.Get(prepend+channels[0]).Get("ttH_other125"))
if file.Get(prepend+channels[0]).Get("ttHnonBB"):
  smHiggs.Add(file.Get(prepend+channels[0]).Get("ttHnonBB"))
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
   #XXX WH.Add(file.Get(prepend+channels[i]).Get("WH_htt125"))
   #XXX ZH.Add(file.Get(prepend+channels[i]).Get("ZH_htt125"))
   AZH.Add(file.Get(prepend+channels[i]).Get("azh").Clone())
   VH.Add(file.Get(prepend+channels[i]).Get("ZH_htt125").Clone())
   smHiggs.Add(file.Get(prepend+channels[i]).Get("ZH_htt125").Clone())
   if file.Get(prepend+channels[i]).Get("WH_htt125"):
     VH.Add(file.Get(prepend+channels[i]).Get("WH_htt125").Clone())
     smHiggs.Add(file.Get(prepend+channels[i]).Get("WH_htt125").Clone())
   if file.Get(prepend+channels[i]).Get("ttZ"):
     Rare.Add(file.Get(prepend+channels[i]).Get("ttZ"))
   if file.Get(prepend+channels[i]).Get("ttW"):
     Rare.Add(file.Get(prepend+channels[i]).Get("ttW"))
   if file.Get(prepend+channels[i]).Get("TriBoson"):
     Rare.Add(file.Get(prepend+channels[i]).Get("TriBoson"))
   if file.Get(prepend+channels[i]).Get("WH_hww125"):
     smHiggs.Add(file.Get(prepend+channels[i]).Get("WH_hww125"))
   if file.Get(prepend+channels[i]).Get("ZH_hww125"):
     smHiggs.Add(file.Get(prepend+channels[i]).Get("ZH_hww125"))
   if file.Get(prepend+channels[i]).Get("ggH_hzz125"): 
     smHiggs.Add(file.Get(prepend+channels[i]).Get("ggH_hzz125"))
   if file.Get(prepend+channels[i]).Get("ttH_other125"):
     smHiggs.Add(file.Get(prepend+channels[i]).Get("ttH_other125"))
   if file.Get(prepend+channels[i]).Get("ttHnonBB"):
     smHiggs.Add(file.Get(prepend+channels[i]).Get("ttHnonBB"))
   if channels[i] not in wh_channels and file.Get(prepend+channels[i]).Get("WZ"):
     Rare.Add(file.Get(prepend+channels[i]).Get("WZ"))

   Total.Add(file.Get(prepend+channels[i]).Get("total_background"))
   #TotalAll.Add(file.Get(prepend+channels[i]).Get("total"))
   TotalAll.Add(file.Get(prepend+channels[i]).Get("total_background"))

#if fit == "prefit" :
#    WH.Scale(5./6.5 / 2.34)
#    ZH.Scale(5./6.5 / 2.34)
#if fit == "postfit" :
#    WH.Scale(5. / 2.34) # 2.34 is signal str
#    ZH.Scale(5. / 2.34)
AZH.Scale( azhScale )

#XXX WH.GetXaxis().SetTitle("")
#XXX WH.GetXaxis().SetTitleSize(0)
#XXX WH.GetXaxis().SetNdivisions(505)
#XXX WH.GetYaxis().SetLabelFont(42)
#XXX WH.GetYaxis().SetLabelOffset(0.01)
#XXX WH.GetYaxis().SetLabelSize(0.06)
#XXX WH.GetYaxis().SetTitleSize(0.075)
#XXX WH.GetYaxis().SetTitleOffset(1.04)
#XXX WH.SetTitle("")
#XXX if channels[0] in wh_channels :
#XXX     WH.GetYaxis().SetTitle("Events / 10 GeV")
#XXX else :
#XXX     WH.GetYaxis().SetTitle("Events / 20 GeV")
#XXX WH.SetMinimum(0)
#XXX WH.SetMarkerStyle(20)
#XXX WH.SetMarkerSize(1)
#XXX WH.GetXaxis().SetLabelSize(0)

AZH.GetXaxis().SetTitle("")
AZH.GetXaxis().SetTitleSize(0)
#FIXME AZH.GetXaxis().SetNdivisions(505)
AZH.GetYaxis().SetLabelFont(42)
AZH.GetYaxis().SetLabelOffset(0.01)
AZH.GetYaxis().SetLabelSize(0.06)
AZH.GetYaxis().SetTitleSize(0.075)
AZH.GetYaxis().SetTitleOffset(1.04)
AZH.SetTitle("")
AZH.GetYaxis().SetTitle("Events / 20 GeV")
AZH.SetMinimum(0)
AZH.SetMarkerStyle(20)
AZH.SetMarkerSize(1)
AZH.GetXaxis().SetLabelSize(0)

Data.Sumw2(ROOT.kFALSE)
Data.SetBinErrorOption(ROOT.TH1.kPoisson)
Data.GetXaxis().SetTitle("")
Data.GetXaxis().SetTitleSize(0)
#FIXME Data.GetXaxis().SetNdivisions(505)
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
smHiggs.SetFillColor(ROOT.kRed)
#XXX WH.SetLineWidth(4)
#XXX ZH.SetLineWidth(4)
#XXX VH.SetLineWidth(4)
AZH.SetLineWidth(4)
#smHiggs = VH.Clone()

Data.SetMarkerStyle(20)
Data.SetLineColor(1)
Data.SetMarkerSize(1)
Fake.SetLineColor(1)
if channels[0] in wh_channels :
  WZ.SetLineColor(1)
ZZ.SetLineColor(1)
Rare.SetLineColor(1)
smHiggs.SetLineColor(1)
Total.SetLineColor(1)
#XXX ZH.SetLineColor(2)
#XXX WH.SetLineColor(9)
#XXX VH.SetLineColor(ROOT.kRed)
AZH.SetLineColor(ROOT.kRed)

stack=ROOT.THStack("stack","stack")
stack.Add(Fake)
stack.Add(Rare)
stack.Add(ZZ)
if channels[0] in wh_channels :
  stack.Add(WZ)
stack.Add(smHiggs)

#errorBand=TotalAll.Clone()
errorBand=stack.GetStack().Last().Clone()
for b in range( 1, errorBand.GetNbinsX()+1 ) :
    errorBand.SetBinError( b, Total.GetBinError( b ) )

#print "ZZ: %.2f" % ZZ.Integral()
print_yields( ZZ, 'ZZ' )
if channels[0] in wh_channels :
  #print "WZ: %.2f" % WZ.Integral()
  print_yields( WZ, 'WZ' )
print_yields( Rare, 'Other' )
print_yields( Fake, 'Fake' )
#XXX print_yields( WH, 'WH' )
#XXX print_yields( ZH, 'ZH' )
print_yields( VH, 'VH' )
print_yields( AZH, 'AZH' )
print_yields( Data, 'Data' )
total_bkg = ZZ.Integral() + Rare.Integral() + Fake.Integral() + VH.Integral()
print "Data/Bkg %.3f" % (Data.Integral() / total_bkg )

#XXX print "WH / VH = %.4f" % (( WH.Integral() / VH.Integral() ) * 100.)
#XXX print "ZH / VH = %.4f" % (( ZH.Integral() / VH.Integral() ) * 100.)
#print "Rare: %.2f" % Rare.Integral()
#print "Fake: %.2f" % Fake.Integral()
#print "WH: %.2f" % WH.Integral()
#print "ZH: %.2f" % ZH.Integral()
#print "Data: %.2f" % Data.Integral()

errorBand.SetMarkerSize(0)
errorBand.SetFillColor(new_idx)
errorBand.SetFillStyle(3001)
errorBand.SetLineWidth(0)

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
         s=AZH.GetBinContent(k)
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
#FIXME Poisson.GetXaxis().SetNdivisions(505)
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

# Remove the horizontal error bars
x, y = ROOT.Double(0.), ROOT.Double(0.)
for p in range( 0, Poisson.GetN() ) :
    Poisson.SetPointEXhigh(p, 0.)
    Poisson.SetPointEXlow(p, 0.)

# Poisson errors are large, make max 10 or greater
AZH.SetMaximum( 
    max( Poisson.GetMaximum()*1.9, stack.GetMaximum()*1.9,
    Data.GetMaximum()*1.9,stack.GetMaximum()*1.9,AZH.GetMaximum()*1.9) )
#XXX AZH.SetMaximum( 
#XXX     max( Poisson.GetMaximum()*2.0, stack.GetMaximum()*2.0,
#XXX     Data.GetMaximum()*2.0,stack.GetMaximum()*2.0, set_max) )

AZH.GetXaxis().SetRange(6,30)

#Poisson.Draw("AP")
#Data.Draw("e0")
AZH.Draw("hist")
stack.Draw("histsame")
errorBand.Draw("e2same")
AZH.Draw("histsame")
#Data.Draw("e0same")
if unblind :
  Poisson.Draw("P 0")


legende=make_legend()
legende.AddEntry(Data,"Observed","elp")
if channels[0] in wh_channels :
  legende.AddEntry(WZ,"WZ#rightarrow 3l#nu","f")
legende.AddEntry(ZZ,"ZZ#rightarrow 4l","f")
legende.AddEntry(Rare,"Other","f")
legende.AddEntry(Fake,"Reducible","f")
legende.AddEntry(smHiggs,"SM Higgs","f")
legende.AddEntry(AZH,"AZh m_{A}=300GeV, #sigmaxBR=%i(fb)" % azhScale,"l")
legende.AddEntry(errorBand,"Uncertainty","f")
legende.Draw()
# To make sure it is on top!
if unblind :
  Poisson.Draw("P 0")

l1=add_lumi()
l1.Draw("same")
l2=add_CMS()
l2.Draw("same")
l3=add_Preliminary()
l3.Draw("same")

pad1.RedrawAxis()

if 'combined' not in cat_text :
    #XXX categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.38, 0.75+0.155, "NDC")
    categ  = ROOT.TPaveText(0.21, 0.5, 0.38, 0.73, "NDC")
    categ.SetTextSize ( 0.07 )
else :
    categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.38, 0.75+0.155, "NDC")
    categ.SetTextSize ( 0.05 )
categ.SetBorderSize(   0 )
categ.SetFillStyle(    0 )
categ.SetTextAlign(   12 )
categ.SetTextColor(    1 )
categ.SetTextFont (   42 )
categ.AddText( cat_text )

categ.Draw()


c.cd()
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
hp=Poisson.Clone()
#hp.SetMaximum(2.0)#FIXME(1.5)
#hp.SetMinimum(0.0)#FIXME(0.5)
hp.SetMarkerStyle(20)
#h1.SetMaximum(2.0)#FIXME(1.5)
#h1.SetMinimum(0.0)#FIXME(0.5)
h1.SetMarkerStyle(20)
h3=errorBand.Clone()
hwoE=errorBand.Clone()
p_x=hp.GetX()
p_y=hp.GetY()

# If an empty data bin was set to negative for plotting purposes,
# reset it to zero for ration plot.
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
h1.Divide(hwoE)
h3.Divide(hwoE)
h1.GetXaxis().SetTitle("m_{ll#tau#tau}^{c} (GeV)")
h1.GetYaxis().SetTitle("Obs./(Bkg. + Sig.)")
#FIXME h1.GetXaxis().SetNdivisions(505)
#FIXME h1.GetYaxis().SetNdivisions(5)

h3.GetXaxis().SetTitle("m_{ll#tau#tau}^{c} (GeV)")
h3.GetYaxis().SetTitle("Obs./(Bkg. + Sig.)")
#FIXME h3.GetXaxis().SetNdivisions(505)
#FIXME h3.GetYaxis().SetNdivisions(5)
h3.SetTitle("")
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
h3.SetMaximum(maxi)#FIXME(1.5)
h3.SetMinimum(mini)#FIXME(0.5)

h3.Draw("e2")
print h3.GetXaxis().GetLabelOffset()
h3.GetXaxis().SetLabelOffset( h3.GetXaxis().GetLabelOffset() * 2 )
ROOT.gPad.SetGridx(0)
#h3.GetXaxis().ChangeLabel(-1,-1,-1,-1,-1,-1,"-#pi")
#XXX if fs in ["emt", "ett", "mmt", "mtt","whhad","whlep","wh"] :
#XXX     if fs in ["ett", "mtt", "whhad", "wh"] : # had
#XXX         h3.GetXaxis().SetNdivisions(12, ROOT.kFALSE)
#XXX         for j in range( 1, 14 ) :
#XXX             h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % (j*10 + 10))
#XXX     else : # semilep
#XXX         h3.GetXaxis().SetNdivisions(11, ROOT.kFALSE)
#XXX         for j in range( 1, 31 ) :
#XXX             h3.GetXaxis().ChangeLabel(j,45,-1,-1,-1,-1,"%s" % (j*10 + 10))
#h3.GetXaxis().SetNdivisions(11, ROOT.kFALSE)
for j in range( 1, 31 ) :
    h3.GetXaxis().ChangeLabel(j,0,-1,-1,-1,-1,"%s" % ( (j-1)*100 + 100))

h3.GetXaxis().SetRange(6,30)

h3.Draw("e2")
if unblind :
  hp.Draw("P 0")


c.cd()
pad1.Draw()

ROOT.gPad.RedrawAxis()

c.Modified()
#c.SaveAs(output_dir+"/"+fs+"_"+fit+".C")
#c.SaveAs(output_dir+"/"+fs+"_"+fit+".root")
c.SaveAs(output_dir+"/"+fs+"_"+fit+".pdf")
c.SaveAs(output_dir+"/"+fs+"_"+fit+".png")


