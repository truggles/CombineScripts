void VH_signal()
{
//=========Macro generated from canvas: VH_signal/VH_signal
//=========  (Mon Apr  2 14:59:38 2018) by ROOT version6.02/05
   TCanvas *VH_signal = new TCanvas("VH_signal", "VH_signal",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   VH_signal->SetHighLightColor(2);
   VH_signal->Range(0,0,1,1);
   VH_signal->SetFillColor(0);
   VH_signal->SetBorderMode(0);
   VH_signal->SetBorderSize(2);
   VH_signal->SetLeftMargin(0.16);
   VH_signal->SetRightMargin(0.04);
   VH_signal->SetTopMargin(0.06);
   VH_signal->SetBottomMargin(0.12);
   VH_signal->SetFrameFillStyle(0);
   VH_signal->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-2.4,-1.463415,6.35,10.73171);
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
   
   TH2F *axis1 = new TH2F("axis1","",1,-1,6,10,0,10);
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
   TLatex *   tex = new TLatex(4,8.25,"WH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(5,8.25,"3.61#splitline{ +1.77}{ -1.6}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(4,5.75,"ZH");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(5,5.75,"1.42#splitline{ +1.58}{ -1.52}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(4,3.25,"cmb");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.035);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(5,3.25,"2.54#splitline{ +1.36}{ -1.25}");
   tex->SetTextAlign(12);
   tex->SetTextSize(0.025);
   tex->SetLineWidth(2);
   tex->Draw();
   
   Double_t Graph0_fx3001[3] = {
   3.61,
   1.42,
   2.54};
   Double_t Graph0_fy3001[3] = {
   7.5,
   5,
   2.5};
   Double_t Graph0_felx3001[3] = {
   1.6,
   1.52,
   1.25};
   Double_t Graph0_fely3001[3] = {
   0,
   0,
   0};
   Double_t Graph0_fehx3001[3] = {
   1.77,
   1.58,
   1.36};
   Double_t Graph0_fehy3001[3] = {
   0,
   0,
   0};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,-0.648,5.928);
   Graph_Graph3001->SetMinimum(2);
   Graph_Graph3001->SetMaximum(8);
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
   
   Double_t Graph0_fx3002[3] = {
   3.61,
   1.42,
   2.54};
   Double_t Graph0_fy3002[3] = {
   7.5,
   5,
   2.5};
   Double_t Graph0_felx3002[3] = {
   1.6,
   1.52,
   1.25};
   Double_t Graph0_fely3002[3] = {
   0,
   0,
   0};
   Double_t Graph0_fehx3002[3] = {
   1.77,
   1.58,
   1.36};
   Double_t Graph0_fehy3002[3] = {
   0,
   0,
   0};
   grae = new TGraphAsymmErrors(3,Graph0_fx3002,Graph0_fy3002,Graph0_felx3002,Graph0_fehx3002,Graph0_fely3002,Graph0_fehy3002);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");
   grae->SetFillColor(1);

   ci = TColor::GetColor("#0000ff");
   grae->SetLineColor(ci);
   grae->SetLineWidth(2);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph30013002 = new TH1F("Graph_Graph_Graph30013002","Graph",100,-0.648,5.928);
   Graph_Graph_Graph30013002->SetMinimum(2);
   Graph_Graph_Graph30013002->SetMaximum(8);
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
   
   TH2F *axis_copy2 = new TH2F("axis_copy2","",1,-1,6,10,0,10);
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
   VH_signal->cd();
   VH_signal->Modified();
   VH_signal->cd();
   VH_signal->SetSelected(VH_signal);
}
