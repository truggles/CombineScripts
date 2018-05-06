void signal_nom()
{
//=========Macro generated from canvas: signal_nom/signal_nom
//=========  (Mon Apr  9 15:09:57 2018) by ROOT version6.02/05
   TCanvas *signal_nom = new TCanvas("signal_nom", "signal_nom",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   signal_nom->SetHighLightColor(2);
   signal_nom->Range(0,0,1,1);
   signal_nom->SetFillColor(0);
   signal_nom->SetBorderMode(0);
   signal_nom->SetBorderSize(2);
   signal_nom->SetLeftMargin(0.16);
   signal_nom->SetRightMargin(0.04);
   signal_nom->SetTopMargin(0.06);
   signal_nom->SetBottomMargin(0.12);
   signal_nom->SetFrameFillStyle(0);
   signal_nom->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-3.8,-1.463415,7.45,10.73171);
   pad->SetFillColor(0);
   pad->SetBorderMode(0);
   pad->SetBorderSize(2);
   pad->SetTickx(1);
   pad->SetTicky(-1);
   pad->SetLeftMargin(0.16);
   pad->SetRightMargin(0.04);
   pad->SetTopMargin(0.06);
   pad->SetBottomMargin(0.12);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   
   TH2F *axis1 = new TH2F("axis1","",1,-2,7,10,0,10);
   axis1->SetLineStyle(0);
   axis1->SetMarkerStyle(21);
   axis1->GetXaxis()->SetTitle("Best fit #mu = #sigma/#sigma_{SM}");
   axis1->GetXaxis()->SetNdivisions(506);
   axis1->GetXaxis()->SetLabelFont(42);
   axis1->GetXaxis()->SetTitleSize(0.05);
   axis1->GetXaxis()->SetTickLength(0.02);
   axis1->GetXaxis()->SetTitleOffset(1.08);
   axis1->GetXaxis()->SetTitleFont(42);
   axis1->GetYaxis()->SetNdivisions(506);
   axis1->GetYaxis()->SetLabelFont(42);
   axis1->GetYaxis()->SetLabelOffset(0.007);
   axis1->GetYaxis()->SetLabelSize(0);
   axis1->GetYaxis()->SetTitleSize(0.05);
   axis1->GetYaxis()->SetTickLength(0.02);
   axis1->GetYaxis()->SetTitleOffset(1.56);
   axis1->GetYaxis()->SetTitleFont(42);
   axis1->GetZaxis()->SetNdivisions(506);
   axis1->GetZaxis()->SetLabelFont(42);
   axis1->GetZaxis()->SetLabelOffset(0.007);
   axis1->GetZaxis()->SetTitleSize(0.05);
   axis1->GetZaxis()->SetTickLength(0.02);
   axis1->GetZaxis()->SetTitleFont(42);
   axis1->Draw("");
   TLatex *   tex = new TLatex(2.5,7.95,"ggH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(3.5,7.95,"#mu=1.12#splitline{ +0.53}{ -0.5}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(2.5,6.45,"qqH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(3.5,6.45,"#mu=1.13#splitline{ +0.45}{ -0.42}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(2.5,4.95,"WH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(3.5,4.95,"#mu=3.39#splitline{ +1.68}{ -1.54}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(2.5,3.45,"ZH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(3.5,3.45,"#mu=1.23#splitline{ +1.62}{ -1.35}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      //tex = new TLatex(2.5,1.95,"cmb");
      tex = new TLatex(2,1.95,"Combined");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(4,1.95,"#mu=1.24#splitline{ +0.29}{ -0.27}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph0_fx3001[5] = {
   1.12,
   1.13,
   3.39,
   1.23,
   1.24};
   Double_t Graph0_fy3001[5] = {
   7.5,
   6,
   4.5,
   3,
   1.5};
   Double_t Graph0_felx3001[5] = {
   0.5,
   0.42,
   1.54,
   1.35,
   0.27};
   Double_t Graph0_fely3001[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehx3001[5] = {
   0.53,
   0.45,
   1.68,
   1.62,
   0.29};
   Double_t Graph0_fehy3001[5] = {
   0,
   0,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(kRed);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,-0.639,5.589);
   Graph_Graph3001->SetMinimum(0.9);
   Graph_Graph3001->SetMaximum(8.1);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineStyle(0);
   Graph_Graph3001->SetMarkerStyle(21);
   Graph_Graph3001->GetXaxis()->SetNdivisions(506);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetNdivisions(506);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetNdivisions(506);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("p");
   TBox *box = new TBox(0.97,0,1.53,10);

   ci = TColor::GetColor("#ffff00");
   //box->SetFillColor(ci);
   box->SetFillColor(kGreen+1);
   box->Draw();
   TLine *line = new TLine(1.24,0,1.24,10);
   line->Draw();
   
   Double_t Graph0_fx3002[5] = {
   1.12,
   1.13,
   3.39,
   1.23,
   1.24};
   Double_t Graph0_fy3002[5] = {
   7.5,
   6,
   4.5,
   3,
   1.5};
   Double_t Graph0_felx3002[5] = {
   0.5,
   0.42,
   1.54,
   1.35,
   0.27};
   Double_t Graph0_fely3002[5] = {
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehx3002[5] = {
   0.53,
   0.45,
   1.68,
   1.62,
   0.29};
   Double_t Graph0_fehy3002[5] = {
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(5,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(kRed);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(21);
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","Graph",100,-0.639,5.589);
   Graph_Graph_Graph30013002->SetMinimum(0.9);
   Graph_Graph_Graph30013002->SetMaximum(8.1);
   Graph_Graph_Graph30013002->SetDirectory(0);
   Graph_Graph_Graph30013002->SetStats(0);
   Graph_Graph_Graph30013002->SetLineStyle(0);
   Graph_Graph_Graph30013002->SetMarkerStyle(21);
   Graph_Graph_Graph30013002->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph30013002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph30013002->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph30013002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph30013002->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph_Graph30013002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetNdivisions(506);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph30013002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph30013002->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph30013002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph30013002);
   
   grae->Draw("p");
   
   TH2F *axis_copy2 = new TH2F("axis_copy2","",1,-2,7,10,0,10);
   axis_copy2->SetDirectory(0);
   axis_copy2->SetLineStyle(0);
   axis_copy2->SetMarkerStyle(21);
   axis_copy2->GetXaxis()->SetTitle("Best fit #mu = #sigma/#sigma_{SM}");
   axis_copy2->GetXaxis()->SetNdivisions(506);
   axis_copy2->GetXaxis()->SetLabelFont(42);
   axis_copy2->GetXaxis()->SetTitleSize(0.05);
   axis_copy2->GetXaxis()->SetTickLength(0.02);
   axis_copy2->GetXaxis()->SetTitleOffset(1.08);
   axis_copy2->GetXaxis()->SetTitleFont(42);
   axis_copy2->GetYaxis()->SetNdivisions(506);
   axis_copy2->GetYaxis()->SetLabelFont(42);
   axis_copy2->GetYaxis()->SetLabelOffset(0.007);
   axis_copy2->GetYaxis()->SetLabelSize(0);
   axis_copy2->GetYaxis()->SetTitleSize(0.05);
   axis_copy2->GetYaxis()->SetTickLength(0.02);
   axis_copy2->GetYaxis()->SetTitleOffset(1.56);
   axis_copy2->GetYaxis()->SetTitleFont(42);
   axis_copy2->GetZaxis()->SetNdivisions(506);
   axis_copy2->GetZaxis()->SetLabelFont(42);
   axis_copy2->GetZaxis()->SetLabelOffset(0.007);
   axis_copy2->GetZaxis()->SetTitleSize(0.05);
   axis_copy2->GetZaxis()->SetTickLength(0.02);
   axis_copy2->GetZaxis()->SetTitleFont(42);
   axis_copy2->Draw("sameaxis");
      tex = new TLatex(0.196,0.899,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
//      tex = new TLatex(0.196,0.839,"Preliminary");
//tex->SetNDC();
//   tex->SetTextAlign(13);
//   tex->SetTextFont(52);
//   tex->SetTextSize(0.0456);
//   tex->SetLineWidth(2);
//   tex->Draw();
      tex = new TLatex(0.96,0.952,"35.9 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   pad->Modified();
   signal_nom->cd();
   signal_nom->Modified();
   signal_nom->cd();
   signal_nom->SetSelected(signal_nom);
   //signal_nom->SaveAs("signal_nom.pdf");
   signal_nom->SaveAs("signal_nom_final.pdf");
}
