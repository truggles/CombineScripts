import ROOT
from array import array

f = ROOT.TFile('higgsCombineCvCf.MultiDimFit.mH125.root', 'r')
t = f.Get('limit')

c = ROOT.TCanvas("c","Graph2D example",0,0,600,400)
g = ROOT.TGraph2D()

cfx = array('d', [])
cvx = array('d', [])
dnllx = array('d', [])

cnt = 0
for row in t :
    cf = row.CF
    cv = row.CV
    dnll = row.deltaNLL
    g.SetPoint(cnt,cf,cv,dnll)
    cnt += 1

ROOT.gStyle.SetPalette(1)
g.Draw("surf1")
g.SaveAs('tmp.root')
c.SaveAs('tmp.png')

