void VH_channel()
{
//=========Macro generated from canvas: VH_channel/VH_channel
//=========  (Mon Apr  2 15:11:07 2018) by ROOT version6.02/05
   TCanvas *VH_channel = new TCanvas("VH_channel", "VH_channel",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   VH_channel->SetHighLightColor(2);
   VH_channel->Range(0,0,1,1);
   VH_channel->SetFillColor(0);
   VH_channel->SetBorderMode(0);
   VH_channel->SetBorderSize(2);
   VH_channel->SetLeftMargin(0.16);
   VH_channel->SetRightMargin(0.04);
   VH_channel->SetTopMargin(0.06);
   VH_channel->SetBottomMargin(0.12);
   VH_channel->SetFrameFillStyle(0);
   VH_channel->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-18,-1.463415,32,10.73171);
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
   
   TH2F *axis1 = new TH2F("axis1","",1,-10,30,10,0,10);
   axis1->SetLineStyle(0);
   axis1->SetMarkerStyle(20);
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
   TLatex *   tex = new TLatex(15,7.701923,"eeet");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,7.701923,"8.4#splitline{ +9.1}{ -6.45}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,7.125,"eemt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,7.125,"-0.63#splitline{ +2.89}{ -2.35}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,6.548077,"eett");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,6.548077,"-6.07#splitline{ +1.44}{ -0.39}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,5.971154,"eeem");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,5.971154,"15.48#splitline{ +12.54}{ -8.93}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,5.394231,"mmet");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,5.394231,"6.55#splitline{ +5.28}{ -4.21}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,4.817308,"mmmt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,4.817308,"3.54#splitline{ +3.73}{ -3.0}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,4.240385,"mmtt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,4.240385,"-5.72#splitline{ +2.23}{ -2.0}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,3.663462,"mmem");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,3.663462,"8.5#splitline{ +8.5}{ -6.89}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,3.086538,"emt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,3.086538,"3.88#splitline{ +2.98}{ -2.69}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,2.509615,"ett");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,2.509615,"2.43#splitline{ +3.12}{ -2.45}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,1.932692,"mmt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,1.932692,"4.0#splitline{ +3.28}{ -2.92}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,1.355769,"mtt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,1.355769,"2.93#splitline{ +2.79}{ -2.48}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(15,0.7788462,"cmb");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(22,0.7788462,"2.54#splitline{ +1.36}{ -1.25}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph0_fx3001[13] = {
   8.4,
   -0.63,
   -6.07,
   15.48,
   6.55,
   3.54,
   -5.72,
   8.5,
   3.88,
   2.43,
   4,
   2.93,
   2.54};
   Double_t Graph0_fy3001[13] = {
   7.5,
   6.923077,
   6.346154,
   5.769231,
   5.192308,
   4.615385,
   4.038462,
   3.461538,
   2.884615,
   2.307692,
   1.730769,
   1.153846,
   0.5769231};
   Double_t Graph0_felx3001[13] = {
   6.45,
   2.35,
   0.39,
   8.93,
   4.21,
   3,
   2,
   6.89,
   2.69,
   2.45,
   2.92,
   2.48,
   1.25};
   Double_t Graph0_fely3001[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehx3001[13] = {
   9.1,
   2.89,
   1.44,
   12.54,
   5.28,
   3.73,
   2.23,
   8.5,
   2.98,
   3.12,
   3.28,
   2.79,
   1.36};
   Double_t Graph0_fehy3001[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(13,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,-11.294,31.594);
   Graph_Graph3001->SetMinimum(0);
   Graph_Graph3001->SetMaximum(8.192308);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineStyle(0);
   Graph_Graph3001->SetMarkerStyle(20);
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
   TBox *box = new TBox(1.29,0,3.9,10);

   ci = TColor::GetColor("#ffff00");
   box->SetFillColor(ci);
   box->Draw();
   TLine *line = new TLine(2.54,0,2.54,10);
   line->Draw();
   
   Double_t Graph0_fx3002[13] = {
   8.4,
   -0.63,
   -6.07,
   15.48,
   6.55,
   3.54,
   -5.72,
   8.5,
   3.88,
   2.43,
   4,
   2.93,
   2.54};
   Double_t Graph0_fy3002[13] = {
   7.5,
   6.923077,
   6.346154,
   5.769231,
   5.192308,
   4.615385,
   4.038462,
   3.461538,
   2.884615,
   2.307692,
   1.730769,
   1.153846,
   0.5769231};
   Double_t Graph0_felx3002[13] = {
   6.45,
   2.35,
   0.39,
   8.93,
   4.21,
   3,
   2,
   6.89,
   2.69,
   2.45,
   2.92,
   2.48,
   1.25};
   Double_t Graph0_fely3002[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   Double_t Graph0_fehx3002[13] = {
   9.1,
   2.89,
   1.44,
   12.54,
   5.28,
   3.73,
   2.23,
   8.5,
   2.98,
   3.12,
   3.28,
   2.79,
   1.36};
   Double_t Graph0_fehy3002[13] = {
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(13,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","Graph",100,-11.294,31.594);
   Graph_Graph_Graph30013002->SetMinimum(0);
   Graph_Graph_Graph30013002->SetMaximum(8.192308);
   Graph_Graph_Graph30013002->SetDirectory(0);
   Graph_Graph_Graph30013002->SetStats(0);
   Graph_Graph_Graph30013002->SetLineStyle(0);
   Graph_Graph_Graph30013002->SetMarkerStyle(20);
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
   
   TH2F *axis_copy2 = new TH2F("axis_copy2","",1,-10,30,10,0,10);
   axis_copy2->SetDirectory(0);
   axis_copy2->SetLineStyle(0);
   axis_copy2->SetMarkerStyle(20);
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
      tex = new TLatex(0.196,0.839,"Preliminary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.952,"35.9 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   pad->Modified();
   VH_channel->cd();
   VH_channel->Modified();
   VH_channel->cd();
   VH_channel->SetSelected(VH_channel);
}
