void VH_channel_blind()
{
//=========Macro generated from canvas: VH_channel_blind/VH_channel_blind
//=========  (Mon Apr  2 15:11:05 2018) by ROOT version6.02/05
   TCanvas *VH_channel_blind = new TCanvas("VH_channel_blind", "VH_channel_blind",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   VH_channel_blind->SetHighLightColor(2);
   VH_channel_blind->Range(0,0,1,1);
   VH_channel_blind->SetFillColor(0);
   VH_channel_blind->SetBorderMode(0);
   VH_channel_blind->SetBorderSize(2);
   VH_channel_blind->SetLeftMargin(0.16);
   VH_channel_blind->SetRightMargin(0.04);
   VH_channel_blind->SetTopMargin(0.06);
   VH_channel_blind->SetBottomMargin(0.12);
   VH_channel_blind->SetFrameFillStyle(0);
   VH_channel_blind->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-11.4,-1.463415,16.1,10.73171);
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
   
   TH2F *axis1 = new TH2F("axis1","",1,-7,15,10,0,10);
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
   TLatex *   tex = new TLatex(9,7.517308,"eeet");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,7.517308,"1.0#splitline{ +6.3}{ -4.97}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,6.940385,"eemt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,6.940385,"1.0#splitline{ +3.99}{ -3.01}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,6.363462,"eett");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,6.363462,"1.0#splitline{ +4.53}{ -3.28}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,5.786538,"eeem");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,5.786538,"1.0#splitline{ +8.4}{ -4.81}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,5.209615,"mmet");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,5.209615,"1.0#splitline{ +4.36}{ -2.88}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,4.632692,"mmmt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,4.632692,"1.0#splitline{ +3.18}{ -2.37}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,4.055769,"mmtt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,4.055769,"1.0#splitline{ +3.54}{ -3.04}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,3.478846,"mmem");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,3.478846,"1.0#splitline{ +6.38}{ -4.49}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,2.901923,"emt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,2.901923,"1.0#splitline{ +2.82}{ -2.44}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,2.325,"ett");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,2.325,"1.0#splitline{ +3.15}{ -2.78}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,1.748077,"mmt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,1.748077,"1.0#splitline{ +3.05}{ -2.63}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,1.171154,"mtt");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,1.171154,"1.0#splitline{ +2.67}{ -2.35}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(9,0.5942308,"cmb");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(12,0.5942308,"1.0#splitline{ +1.08}{ -0.97}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph0_fx3001[13] = {
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1};
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
   4.97,
   3.01,
   3.28,
   4.81,
   2.88,
   2.37,
   3.04,
   4.49,
   2.44,
   2.78,
   2.63,
   2.35,
   0.97};
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
   6.3,
   3.99,
   4.53,
   8.4,
   4.36,
   3.18,
   3.54,
   6.38,
   2.82,
   3.15,
   3.05,
   2.67,
   1.08};
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
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,-5.307,10.737);
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
   TBox *box = new TBox(0.03,0,2.08,10);

   ci = TColor::GetColor("#ffff00");
   box->SetFillColor(ci);
   box->Draw();
   TLine *line = new TLine(1,0,1,10);
   line->Draw();
   
   Double_t Graph0_fx3002[13] = {
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1,
   1};
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
   4.97,
   3.01,
   3.28,
   4.81,
   2.88,
   2.37,
   3.04,
   4.49,
   2.44,
   2.78,
   2.63,
   2.35,
   0.97};
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
   6.3,
   3.99,
   4.53,
   8.4,
   4.36,
   3.18,
   3.54,
   6.38,
   2.82,
   3.15,
   3.05,
   2.67,
   1.08};
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
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","Graph",100,-5.307,10.737);
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
   
   TH2F *axis_copy2 = new TH2F("axis_copy2","",1,-7,15,10,0,10);
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
   VH_channel_blind->cd();
   VH_channel_blind->Modified();
   VH_channel_blind->cd();
   VH_channel_blind->SetSelected(VH_channel_blind);
}
