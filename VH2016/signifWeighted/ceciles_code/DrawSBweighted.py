#!/usr/bin/env python
import ROOT
import re
import math
from array import array
from collections import OrderedDict
import varCfgPlotter
import argparse
import os

def add_lumi():
    lowX=0.65
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.04)
    lumi.SetTextFont (   42 )
    lumi.AddText("35.9 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.14
    lowY=0.745
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.14
    lowY=0.690
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.04)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
        output = ROOT.TLegend(0.14, 0.46, 0.54, 0.82, "", "brNDC")
	#output.SetNColumns(2)
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(1)
        #output.SetFillColor(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output


def make_legend_inset():
        #output = ROOT.TLegend(0.5, 0.5, 0.95, 0.85, "", "brNDC")
        output = ROOT.TLegend(0.22, 0.5, 0.9, 0.85, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetFillColor(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output


ROOT.gStyle.SetFrameLineWidth(2)
ROOT.gStyle.SetLineWidth(2)
ROOT.gStyle.SetOptStat(0)
ROOT.gROOT.SetBatch(True)
#ROOT.gStyle.SetErrorX(0)

c=ROOT.TCanvas("canvas","",0,0,600,600)
c2=ROOT.TCanvas("canvas2","",0,0,600,600)
c3=ROOT.TCanvas("canvas3","",0,0,600,600)
c.cd()


myfile=ROOT.TFile("official_plotted_fitDiagnostics.root","read")

adapt=ROOT.gROOT.GetColor(12)
new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.4)

categ=["ch1","ch2","ch3","ch4","ch5","ch6","ch7","ch8","ch9","ch10","ch11","ch12"]

#histB_wh=ROOT.TH1F("histwh","histwh",7,-3.7,-0.3)
#histB_zh=ROOT.TH1F("histzh","histzh",7,-3.7,-0.3)
#histS=ROOT.TH1F("hists","hists",7,-3.7,-0.3)
#histD=ROOT.TH1F("histd","",7,-3.7,-0.3)

histB_wh=ROOT.TH1F("histwh","histwh",9,-2.3,-0.3)
histB_zh=ROOT.TH1F("histzh","histzh",9,-2.3,-0.3)
histS=ROOT.TH1F("hists","hists",9,-2.3,-0.3)
histD=ROOT.TH1F("histd","",9,-2.3,-0.3)

for mycat in categ:
    B=myfile.Get("shapes_fit_s").Get(mycat).Get("total_background")
    S=myfile.Get("shapes_fit_s").Get(mycat).Get("total_signal")
    D=myfile.Get("shapes_fit_s").Get(mycat).Get("data")
    for j in range(1,B.GetSize()-1):
     if B.GetBinContent(j)>0:
       if math.log(((0.00000000000001+S.GetBinContent(j))/(0.0000000000001+S.GetBinContent(j)+max(0,B.GetBinContent(j)))),10) > -0.52 :
	 print mycat
       bin=histS.FindBin(math.log(((0.00000000000001+S.GetBinContent(j))/(0.0000000000001+S.GetBinContent(j)+max(0,B.GetBinContent(j)))),10))
       if (math.log(((0.00000000000001+S.GetBinContent(j))/(0.0000000000001+S.GetBinContent(j)+max(0,B.GetBinContent(j)))),10)>-0.4):
	   print B.GetBinContent(j),B.GetBinError(j),math.log(((0.00000000000001+S.GetBinContent(j))/(0.0000000000001+S.GetBinContent(j)+max(0,B.GetBinContent(j)))),10)
       if "ch9" in mycat or "ch10" in mycat or "ch11" in mycat or "ch12" in mycat:
          histB_wh.SetBinError(bin,(histB_wh.GetBinError(bin)*histB_wh.GetBinError(bin)+B.GetBinError(j)*B.GetBinError(j))**0.5)
          histB_wh.SetBinContent(bin,histB_wh.GetBinContent(bin)+B.GetBinContent(j))
       else :
          histB_zh.SetBinError(bin,(histB_zh.GetBinError(bin)*histB_zh.GetBinError(bin)+B.GetBinError(j)*B.GetBinError(j))**0.5)
          histB_zh.SetBinContent(bin,histB_zh.GetBinContent(bin)+B.GetBinContent(j))
       histS.SetBinError(bin,(histS.GetBinError(bin)*histS.GetBinError(bin)+S.GetBinError(j)*S.GetBinError(j))**0.5)
       histS.SetBinContent(bin,histS.GetBinContent(bin)+S.GetBinContent(j))
       #histD.SetBinError(bin,(histD.GetBinError(bin)*histD.GetBinError(bin)+D.GetBinError(j)*D.GetBinError(j))**0.5)
       myy=D.GetY()
       histD.SetBinError(bin,(histD.GetBinError(bin)*histD.GetBinError(bin)+myy[j-1])**0.5)
       histD.SetBinContent(bin,histD.GetBinContent(bin)+myy[j-1])


c.cd()
pad1 = ROOT.TPad("pad1","pad1",0,0,1,1)
pad1.Draw()
pad1.cd()
pad1.SetFillColor(0)
pad1.SetBorderMode(0)
pad1.SetBorderSize(10)
pad1.SetTickx(1)
pad1.SetTicky(1)
pad1.SetLeftMargin(0.12)
pad1.SetRightMargin(0.05)
pad1.SetTopMargin(0.10)
pad1.SetBottomMargin(0.12)
pad1.SetFrameFillStyle(0)
pad1.SetFrameLineStyle(0)
pad1.SetFrameLineWidth(2)
pad1.SetFrameBorderMode(0)
pad1.SetFrameBorderSize(10)
pad1.SetLogy()
histB_zh.SetFillColor(ROOT.TColor.GetColor(200,222,85))
histB_wh.SetFillColor(ROOT.TColor.GetColor(250,22,144))
histB_wh.SetLineColor(1)
histB_zh.SetLineColor(1)

histD.SetLineColor(1)
errorBand=histB_wh.Clone()
errorBand.Add(histB_zh)
errorBand.SetMarkerSize(0)
errorBand.SetFillColor(new_idx)
errorBand.SetLineWidth(1)
histS.SetLineColor(2)
histS.SetLineWidth(2)
mystack=ROOT.THStack("mystack","mystack")
mystack.Add(histB_wh)
mystack.Add(histB_zh)
mystack.Add(histS)
histD.SetMarkerStyle(20)
histD.GetXaxis().SetTitle("log_{10}(S/(S+B))")
histD.GetYaxis().SetTitle("Events")
histD.GetXaxis().SetTitleSize(0.05)
histD.GetYaxis().SetTitleSize(0.05)
#histD.SetErrorX(0)
#setex2 = ROOT.TExec("setex2","ROOT.gStyle.SetErrorX(0)");
#setex2.Draw();
histD.Draw("epX0")
histD.SetMinimum(0.1)
histD.SetMaximum(100000)
mystack.Draw("histsame")
errorBand.Draw("e2same")
histD.Draw("epx0same")
legend=make_legend()
legend.AddEntry(histD,"Observed","elp")
legend.AddEntry(histB_wh,"Bkg. in WH channels","f")
legend.AddEntry(histB_zh,"Bkg. in ZH channels","f")
legend.AddEntry(histS,"H#rightarrow#tau#tau (#mu=2.5)","l")
legend.AddEntry(errorBand,"Bkg. unc.","f")
legend.Draw()

l1=add_lumi()
l1.Draw("same")
l2=add_CMS()
l2.Draw("same")
l3=add_Preliminary()
#l3.Draw("same")

pad1.RedrawAxis()


pad2 = ROOT.TPad("pad2","pad2",0.47,0.53,0.94,0.92)
pad2.Draw()
pad2.cd()
pad2.SetFillStyle(0)
pad2.SetBorderMode(0)
pad2.SetBorderSize(10)
pad2.SetTickx(1)
pad2.SetTicky(1)
pad2.SetLeftMargin(0.20)
pad2.SetRightMargin(0.05)
pad2.SetTopMargin(0.122)
pad2.SetBottomMargin(0.20)
pad2.SetFrameFillStyle(0)
pad2.SetFrameLineStyle(0)
pad2.SetFrameLineWidth(2)
pad2.SetFrameBorderMode(0)
pad2.SetFrameBorderSize(10)
bnoerror=errorBand.Clone()
for k in range (1,bnoerror.GetSize()-1):
  bnoerror.SetBinError(k,0)
suberror=errorBand.Clone()
suberror.Add(bnoerror,-1)
suberror.Divide(bnoerror)
suberror.SetMarkerSize(0)
suberror.SetFillColor(new_idx)
#suberror.SetFillStyle(2008)
suberror.SetLineWidth(1)
subD=histD.Clone()
subD.GetYaxis().SetTitle("")
subD.GetXaxis().SetTitleSize(0.08)
subD.GetXaxis().SetLabelSize(0.07)
subD.GetXaxis().SetNdivisions(506)
subD.GetYaxis().SetTitleOffset(1.10)
subD.GetYaxis().SetTitleSize(0.08)
subD.GetYaxis().SetLabelSize(0.07)
subD.GetXaxis().SetRangeUser(-2,-0.3)
subD.Add(bnoerror,-1)
subD.Divide(bnoerror)
subD.SetMaximum(1.25)
subS=histS.Clone()
subS.Divide(bnoerror)
subD.Draw("epx0")
suberror.Draw("e2same")
subS.SetMarkerSize(0)
subS.Draw("histsame")
subD.Draw("epx0same")
myline=ROOT.TLine(-2.05,0,-0.3,0)
myline.SetLineWidth(1)
myline.Draw("same")
legend_inset=make_legend_inset()
legend_inset.AddEntry(subD,"(Obs. - bkg.)/bkg.","elp")
legend_inset.AddEntry(histS,"(H#rightarrow#tau#tau)/bkg. (#mu=2.5)","l")
legend_inset.AddEntry(suberror,"Bkg. unc./bkg.","f")
legend_inset.Draw()
pad2.RedrawAxis()
c.Modified()
c.SaveAs("sbweight.pdf")
c.SaveAs("sbweight.png")
c.SaveAs("sbweight.C")

