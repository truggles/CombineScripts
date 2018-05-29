void lim_obs_llem()
{
//=========Macro generated from canvas: lim_obs_llem/lim_obs_llem
//=========  (Thu Apr  5 17:47:34 2018) by ROOT version6.02/05
   TCanvas *lim_obs_llem = new TCanvas("lim_obs_llem", "lim_obs_llem",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   lim_obs_llem->SetHighLightColor(2);
   lim_obs_llem->Range(0,0,1,1);
   lim_obs_llem->SetFillColor(0);
   lim_obs_llem->SetBorderMode(0);
   lim_obs_llem->SetBorderSize(2);
   lim_obs_llem->SetLeftMargin(0.16);
   lim_obs_llem->SetRightMargin(0.04);
   lim_obs_llem->SetTopMargin(0.06);
   lim_obs_llem->SetBottomMargin(0.12);
   lim_obs_llem->SetFrameFillStyle(0);
   lim_obs_llem->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(104,-9.91452,141.5,72.70648);
   pad->SetFillColor(0);
   pad->SetBorderMode(0);
   pad->SetBorderSize(2);
   pad->SetTickx(1);
   pad->SetTicky(1);
   pad->SetLeftMargin(0.16);
   pad->SetRightMargin(0.04);
   pad->SetTopMargin(0.06);
   pad->SetBottomMargin(0.12);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   
   TH1F *tmp01 = new TH1F("tmp01","Graph",100,110,140);
   tmp01->SetMinimum(0);
   tmp01->SetMaximum(67.74922);
   tmp01->SetStats(0);
   tmp01->SetLineStyle(0);
   tmp01->SetMarkerStyle(20);
   tmp01->GetXaxis()->SetTitle("m_{H} (GeV)");
   tmp01->GetXaxis()->SetLabelFont(42);
   tmp01->GetXaxis()->SetLabelOffset(0.01);
   tmp01->GetXaxis()->SetTitleSize(0.05);
   tmp01->GetXaxis()->SetTickLength(0.02);
   tmp01->GetXaxis()->SetTitleOffset(1.08);
   tmp01->GetXaxis()->SetTitleFont(42);
   tmp01->GetYaxis()->SetTitle("95% CL limit on #sigma/#sigma_{SM}");
   tmp01->GetYaxis()->SetLabelFont(42);
   tmp01->GetYaxis()->SetLabelOffset(0.007);
   tmp01->GetYaxis()->SetTitleSize(0.05);
   tmp01->GetYaxis()->SetTickLength(0.02);
   tmp01->GetYaxis()->SetTitleOffset(1.56);
   tmp01->GetYaxis()->SetTitleFont(42);
   tmp01->GetZaxis()->SetLabelFont(42);
   tmp01->GetZaxis()->SetLabelOffset(0.007);
   tmp01->GetZaxis()->SetTitleSize(0.05);
   tmp01->GetZaxis()->SetTickLength(0.02);
   tmp01->GetZaxis()->SetTitleFont(42);
   tmp01->Draw("AXIS");
   
   TH1F *tmp02 = new TH1F("tmp02","Graph",100,110,140);
   tmp02->SetMinimum(0);
   tmp02->SetMaximum(67.74922);
   tmp02->SetStats(0);
   tmp02->SetLineStyle(0);
   tmp02->SetMarkerStyle(20);
   tmp02->GetXaxis()->SetTitle("m_{H} (GeV)");
   tmp02->GetXaxis()->SetLabelFont(42);
   tmp02->GetXaxis()->SetLabelOffset(0.01);
   tmp02->GetXaxis()->SetTitleSize(0.05);
   tmp02->GetXaxis()->SetTickLength(0.02);
   tmp02->GetXaxis()->SetTitleOffset(1.08);
   tmp02->GetXaxis()->SetTitleFont(42);
   tmp02->GetYaxis()->SetTitle("95% CL limit on #sigma/#sigma_{SM}");
   tmp02->GetYaxis()->SetLabelFont(42);
   tmp02->GetYaxis()->SetLabelOffset(0.007);
   tmp02->GetYaxis()->SetTitleSize(0.05);
   tmp02->GetYaxis()->SetTickLength(0.02);
   tmp02->GetYaxis()->SetTitleOffset(1.56);
   tmp02->GetYaxis()->SetTitleFont(42);
   tmp02->GetZaxis()->SetLabelFont(42);
   tmp02->GetZaxis()->SetLabelOffset(0.007);
   tmp02->GetZaxis()->SetTitleSize(0.05);
   tmp02->GetZaxis()->SetTickLength(0.02);
   tmp02->GetZaxis()->SetTitleFont(42);
   tmp02->Draw("AXIGSAME");
   
   Double_t Graph0_fx3001[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t Graph0_fy3001[5] = {
   7.09375,
   10.03125,
   11.78125,
   11.9375,
   20.9375};
   Double_t Graph0_felx3001[5] = {
   4.283227e-316,
   0,
   4.285376e-316,
   1.58101e-322,
   5.582942e-322};
   Double_t Graph0_fely3001[5] = {
   3.630005,
   5.250732,
   6.074707,
   6.248535,
   11.04126};
   Double_t Graph0_fehx3001[5] = {
   4.284878e-316,
   0,
   4.282197e-316,
   1.58101e-322,
   5.582942e-322};
   Double_t Graph0_fehy3001[5] = {
   9.077145,
   13.26799,
   14.93621,
   15.78932,
   28.38151};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(5,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
   grae->SetName("Graph0");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,107,143);
   Graph_Graph3001->SetMinimum(0);
   Graph_Graph3001->SetMaximum(53.90454);
   Graph_Graph3001->SetDirectory(0);
   Graph_Graph3001->SetStats(0);
   Graph_Graph3001->SetLineStyle(0);
   Graph_Graph3001->SetMarkerStyle(20);
   Graph_Graph3001->GetXaxis()->SetLabelFont(42);
   Graph_Graph3001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3001->GetXaxis()->SetTitleFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelFont(42);
   Graph_Graph3001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph3001->GetYaxis()->SetTitleFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelFont(42);
   Graph_Graph3001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3001->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3001);
   
   grae->Draw("3");
   
   Double_t Graph1_fx3002[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t Graph1_fy3002[5] = {
   7.09375,
   10.03125,
   11.78125,
   11.9375,
   20.9375};
   Double_t Graph1_felx3002[5] = {
   1.153004e-312,
   0,
   4.276667e-316,
   1.58101e-322,
   1.630417e-322};
   Double_t Graph1_fely3002[5] = {
   2.297112,
   3.322729,
   3.844151,
   4.002968,
   7.073307};
   Double_t Graph1_fehx3002[5] = {
   1.153004e-312,
   0,
   4.2767e-316,
   1.58101e-322,
   1.630417e-322};
   Double_t Graph1_fehy3002[5] = {
   3.760707,
   5.477944,
   6.245756,
   6.518925,
   11.60063};
   grae = new TGraphAsymmErrors(5,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,107,143);
   Graph_Graph3002->SetMinimum(2.022488);
   Graph_Graph3002->SetMaximum(35.31228);
   Graph_Graph3002->SetDirectory(0);
   Graph_Graph3002->SetStats(0);
   Graph_Graph3002->SetLineStyle(0);
   Graph_Graph3002->SetMarkerStyle(20);
   Graph_Graph3002->GetXaxis()->SetLabelFont(42);
   Graph_Graph3002->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3002->GetXaxis()->SetTitleFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelFont(42);
   Graph_Graph3002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph3002->GetYaxis()->SetTitleFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelFont(42);
   Graph_Graph3002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3002->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3002->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph3002);
   
   grae->Draw("3");
   
   Double_t Graph2_fx1[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t Graph2_fy1[5] = {
   7.09375,
   10.03125,
   11.78125,
   11.9375,
   20.9375};
   TGraph *graph = new TGraph(5,Graph2_fx1,Graph2_fy1);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,107,143);
   Graph_Graph1->SetMinimum(5.709375);
   Graph_Graph1->SetMaximum(22.32187);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);
   Graph_Graph1->SetLineStyle(0);
   Graph_Graph1->SetMarkerStyle(20);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetXaxis()->SetTickLength(0.02);
   Graph_Graph1->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetYaxis()->SetTickLength(0.02);
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetZaxis()->SetTickLength(0.02);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("l");
   
   Double_t Graph3_fx2[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t Graph3_fy2[5] = {
   11.67373,
   21.24957,
   24.79402,
   25.45012,
   50.81191};
   graph = new TGraph(5,Graph3_fx2,Graph3_fy2);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,107,143);
   Graph_Graph2->SetMinimum(7.759911);
   Graph_Graph2->SetMaximum(54.72573);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);
   Graph_Graph2->SetLineStyle(0);
   Graph_Graph2->SetMarkerStyle(20);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetXaxis()->SetTickLength(0.02);
   Graph_Graph2->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetYaxis()->SetTickLength(0.02);
   Graph_Graph2->GetYaxis()->SetTitleOffset(1.56);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph2->GetZaxis()->SetTickLength(0.02);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   graph->Draw("pl");
   
   TH1F *tmp0_copy3 = new TH1F("tmp0_copy3","Graph",100,110,140);
   tmp0_copy3->SetMinimum(0);
   tmp0_copy3->SetMaximum(53.90454);
   tmp0_copy3->SetDirectory(0);
   tmp0_copy3->SetStats(0);
   tmp0_copy3->SetLineStyle(0);
   tmp0_copy3->SetMarkerStyle(20);
   tmp0_copy3->GetXaxis()->SetLabelFont(42);
   tmp0_copy3->GetXaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetXaxis()->SetTickLength(0.02);
   tmp0_copy3->GetXaxis()->SetTitleOffset(1.08);
   tmp0_copy3->GetXaxis()->SetTitleFont(42);
   tmp0_copy3->GetYaxis()->SetLabelFont(42);
   tmp0_copy3->GetYaxis()->SetLabelOffset(0.007);
   tmp0_copy3->GetYaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetYaxis()->SetTickLength(0.02);
   tmp0_copy3->GetYaxis()->SetTitleOffset(1.56);
   tmp0_copy3->GetYaxis()->SetTitleFont(42);
   tmp0_copy3->GetZaxis()->SetLabelFont(42);
   tmp0_copy3->GetZaxis()->SetLabelOffset(0.007);
   tmp0_copy3->GetZaxis()->SetTitleSize(0.05);
   tmp0_copy3->GetZaxis()->SetTickLength(0.02);
   tmp0_copy3->GetZaxis()->SetTitleFont(42);
   tmp0_copy3->Draw("sameaxis");
   
   TH1F *tmp0_copy4 = new TH1F("tmp0_copy4","Graph",100,110,140);
   tmp0_copy4->SetMinimum(0);
   tmp0_copy4->SetMaximum(53.90454);
   tmp0_copy4->SetDirectory(0);
   tmp0_copy4->SetStats(0);
   tmp0_copy4->SetLineStyle(0);
   tmp0_copy4->SetMarkerStyle(20);
   tmp0_copy4->GetXaxis()->SetLabelFont(42);
   tmp0_copy4->GetXaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetXaxis()->SetTickLength(0.02);
   tmp0_copy4->GetXaxis()->SetTitleOffset(1.08);
   tmp0_copy4->GetXaxis()->SetTitleFont(42);
   tmp0_copy4->GetYaxis()->SetLabelFont(42);
   tmp0_copy4->GetYaxis()->SetLabelOffset(0.007);
   tmp0_copy4->GetYaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetYaxis()->SetTickLength(0.02);
   tmp0_copy4->GetYaxis()->SetTitleOffset(1.56);
   tmp0_copy4->GetYaxis()->SetTitleFont(42);
   tmp0_copy4->GetZaxis()->SetLabelFont(42);
   tmp0_copy4->GetZaxis()->SetLabelOffset(0.007);
   tmp0_copy4->GetZaxis()->SetTitleSize(0.05);
   tmp0_copy4->GetZaxis()->SetTickLength(0.02);
   tmp0_copy4->GetZaxis()->SetTitleFont(42);
   tmp0_copy4->Draw("sameaxig");
   
   TLegend *leg = new TLegend(0.495,0.825,0.945,0.925,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph3","Observed","LP");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","Expected","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","#pm1#sigma Expected","F");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","#pm2#sigma Expected","F");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TPave *pave = new TPave(0.16,0.81,0.96,0.94,1,"brNDC");
   pave->SetFillColor(0);
   pave->Draw();
   
   leg = new TLegend(0.495,0.825,0.945,0.925,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   entry=leg->AddEntry("Graph3","Observed","LP");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","Expected","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph1","#pm1#sigma Expected","F");

   ci = TColor::GetColor("#00ff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","#pm2#sigma Expected","F");

   ci = TColor::GetColor("#ffff00");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.196,0.9113,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.196,0.8537,"Preliminary(35.9 fb^{-1})");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.03648);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.952,"");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.16,0.952,"");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   pad->Modified();
   lim_obs_llem->cd();
   lim_obs_llem->Modified();
   lim_obs_llem->cd();
   lim_obs_llem->SetSelected(lim_obs_llem);
}
