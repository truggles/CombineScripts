void limit()
{
//=========Macro generated from canvas: limit/limit
//=========  (Mon May 28 22:01:25 2018) by ROOT version6.02/05
   TCanvas *limit = new TCanvas("limit", "limit",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   limit->SetHighLightColor(2);
   limit->Range(0,0,1,1);
   limit->SetFillColor(0);
   limit->SetBorderMode(0);
   limit->SetBorderSize(2);
   limit->SetLeftMargin(0.12);
   limit->SetRightMargin(0.04);
   limit->SetTopMargin(0.06);
   limit->SetBottomMargin(0.12);
   limit->SetFrameFillStyle(0);
   limit->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-0.2857143,-0.2926829,2.095238,2.146341);
   pad->SetFillColor(0);
   pad->SetBorderMode(0);
   pad->SetBorderSize(2);
   pad->SetLeftMargin(0.12);
   pad->SetRightMargin(0.04);
   pad->SetTopMargin(0.06);
   pad->SetBottomMargin(0.12);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   pad->SetFrameFillStyle(0);
   pad->SetFrameBorderMode(0);
   
   TH2D *prototype1 = new TH2D("prototype1","prototype",29,0,2,29,0,2);
   prototype1->SetLineStyle(0);
   prototype1->SetMarkerStyle(20);
   prototype1->GetXaxis()->SetTitle("#kappa_{v}");
   prototype1->GetXaxis()->SetLabelFont(42);
   prototype1->GetXaxis()->SetLabelSize(0.025);
   prototype1->GetXaxis()->SetTitleSize(0.05);
   prototype1->GetXaxis()->SetTickLength(0.02);
   prototype1->GetXaxis()->SetTitleOffset(1.08);
   prototype1->GetXaxis()->SetTitleFont(42);
   prototype1->GetYaxis()->SetTitle("#kappa_{f}");
   prototype1->GetYaxis()->SetLabelFont(42);
   prototype1->GetYaxis()->SetLabelOffset(0.007);
   prototype1->GetYaxis()->SetLabelSize(0.025);
   prototype1->GetYaxis()->SetTitleSize(0.05);
   prototype1->GetYaxis()->SetTickLength(0.02);
   prototype1->GetYaxis()->SetTitleOffset(1.08);
   prototype1->GetYaxis()->SetTitleFont(42);
   prototype1->GetZaxis()->SetLabelFont(42);
   prototype1->GetZaxis()->SetLabelOffset(0.007);
   prototype1->GetZaxis()->SetTitleSize(0.05);
   prototype1->GetZaxis()->SetTickLength(0.02);
   prototype1->GetZaxis()->SetTitleFont(42);
   prototype1->Draw("");
   
   Double_t Graph0_fx1[61] = {
   0.9310335,
   0.8620681,
   0.7931027,
   0.7466778,
   0.7241373,
   0.6551719,
   0.5862065,
   0.526245,
   0.5172411,
   0.4482757,
   0.3968948,
   0.3793104,
   0.3110539,
   0.310345,
   0.2675795,
   0.2750413,
   0.310345,
   0.3258283,
   0.3793104,
   0.405797,
   0.4482757,
   0.5109885,
   0.5172411,
   0.5862065,
   0.6501164,
   0.6551719,
   0.7241373,
   0.7931027,
   0.8620681,
   0.8734256,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.344826,
   1.359367,
   1.413791,
   1.482757,
   1.522708,
   1.551722,
   1.593606,
   1.619793,
   1.613635,
   1.581752,
   1.551722,
   1.530299,
   1.482757,
   1.46089,
   1.413791,
   1.372639,
   1.344826,
   1.27586,
   1.256694,
   1.206895,
   1.13793,
   1.068964,
   1.059351,
   0.9999988,
   0.9310335};
   Double_t Graph0_fy1[61] = {
   1.3591,
   1.358365,
   1.352214,
   1.344826,
   1.34031,
   1.321387,
   1.298343,
   1.27586,
   1.271289,
   1.234464,
   1.206895,
   1.192224,
   1.13793,
   1.136677,
   1.068964,
   0.9999988,
   0.9544837,
   0.9310335,
   0.8863213,
   0.8620681,
   0.8347222,
   0.7931027,
   0.7898267,
   0.7546523,
   0.7241373,
   0.7220957,
   0.6971871,
   0.6755196,
   0.657514,
   0.6551719,
   0.6447406,
   0.6358241,
   0.6306129,
   0.6293304,
   0.63215,
   0.6394647,
   0.6515554,
   0.6551719,
   0.6725174,
   0.7022022,
   0.7241373,
   0.7486151,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9999988,
   1.040742,
   1.068964,
   1.116666,
   1.13793,
   1.17553,
   1.206895,
   1.224898,
   1.265854,
   1.27586,
   1.297923,
   1.323362,
   1.343027,
   1.344826,
   1.354115,
   1.3591};
   TGraph *graph = new TGraph(61,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ccccff");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0.1323582,1.755014);
   Graph_Graph1->SetMinimum(0.5563534);
   Graph_Graph1->SetMaximum(1.432077);
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
   Graph_Graph1->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph1->GetZaxis()->SetTickLength(0.02);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   graph->Draw("f ");
   
   Double_t Graph0_fx2[61] = {
   0.9310335,
   0.8620681,
   0.7931027,
   0.7466778,
   0.7241373,
   0.6551719,
   0.5862065,
   0.526245,
   0.5172411,
   0.4482757,
   0.3968948,
   0.3793104,
   0.3110539,
   0.310345,
   0.2675795,
   0.2750413,
   0.310345,
   0.3258283,
   0.3793104,
   0.405797,
   0.4482757,
   0.5109885,
   0.5172411,
   0.5862065,
   0.6501164,
   0.6551719,
   0.7241373,
   0.7931027,
   0.8620681,
   0.8734256,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.344826,
   1.359367,
   1.413791,
   1.482757,
   1.522708,
   1.551722,
   1.593606,
   1.619793,
   1.613635,
   1.581752,
   1.551722,
   1.530299,
   1.482757,
   1.46089,
   1.413791,
   1.372639,
   1.344826,
   1.27586,
   1.256694,
   1.206895,
   1.13793,
   1.068964,
   1.059351,
   0.9999988,
   0.9310335};
   Double_t Graph0_fy2[61] = {
   1.3591,
   1.358365,
   1.352214,
   1.344826,
   1.34031,
   1.321387,
   1.298343,
   1.27586,
   1.271289,
   1.234464,
   1.206895,
   1.192224,
   1.13793,
   1.136677,
   1.068964,
   0.9999988,
   0.9544837,
   0.9310335,
   0.8863213,
   0.8620681,
   0.8347222,
   0.7931027,
   0.7898267,
   0.7546523,
   0.7241373,
   0.7220957,
   0.6971871,
   0.6755196,
   0.657514,
   0.6551719,
   0.6447406,
   0.6358241,
   0.6306129,
   0.6293304,
   0.63215,
   0.6394647,
   0.6515554,
   0.6551719,
   0.6725174,
   0.7022022,
   0.7241373,
   0.7486151,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9999988,
   1.040742,
   1.068964,
   1.116666,
   1.13793,
   1.17553,
   1.206895,
   1.224898,
   1.265854,
   1.27586,
   1.297923,
   1.323362,
   1.343027,
   1.344826,
   1.354115,
   1.3591};
   graph = new TGraph(61,Graph0_fx2,Graph0_fy2);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ccccff");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph12 = new TH1F("Graph_Graph_Graph12","Graph",100,0.1323582,1.755014);
   Graph_Graph_Graph12->SetMinimum(0.5563534);
   Graph_Graph_Graph12->SetMaximum(1.432077);
   Graph_Graph_Graph12->SetDirectory(0);
   Graph_Graph_Graph12->SetStats(0);
   Graph_Graph_Graph12->SetLineStyle(0);
   Graph_Graph_Graph12->SetMarkerStyle(20);
   Graph_Graph_Graph12->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph12->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph12->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph12->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph12->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph12->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph12->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph12->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph12->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph12->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph12->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph12->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph12->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph12->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph12);
   
   graph->Draw("l ");
   
   Double_t Graph1_fx3[37] = {
   1.058016,
   0.9999988,
   0.9310335,
   0.8620681,
   0.8118821,
   0.7931027,
   0.7241373,
   0.6689998,
   0.6551719,
   0.6179975,
   0.6150978,
   0.6534888,
   0.6551719,
   0.7241373,
   0.741459,
   0.7931027,
   0.8620681,
   0.9233202,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.236208,
   1.27586,
   1.344826,
   1.355491,
   1.37818,
   1.358977,
   1.344826,
   1.305813,
   1.27586,
   1.219835,
   1.206895,
   1.13793,
   1.068964,
   1.058016};
   Double_t Graph1_fy3[37] = {
   1.206895,
   1.217059,
   1.220951,
   1.216327,
   1.206895,
   1.201649,
   1.170824,
   1.13793,
   1.121593,
   1.068964,
   0.9999988,
   0.9310335,
   0.9295388,
   0.8741425,
   0.8620681,
   0.8378245,
   0.8112162,
   0.7931027,
   0.791349,
   0.7809648,
   0.7762242,
   0.7776548,
   0.7861598,
   0.7931027,
   0.8082258,
   0.8522283,
   0.8620681,
   0.9310335,
   0.9999988,
   1.019211,
   1.068964,
   1.094449,
   1.13793,
   1.145458,
   1.17844,
   1.204359,
   1.206895};
   graph = new TGraph(37,Graph1_fx3,Graph1_fy3);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9999cc");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0.5387895,1.454489);
   Graph_Graph3->SetMinimum(0.7317515);
   Graph_Graph3->SetMaximum(1.265424);
   Graph_Graph3->SetDirectory(0);
   Graph_Graph3->SetStats(0);
   Graph_Graph3->SetLineStyle(0);
   Graph_Graph3->SetMarkerStyle(20);
   Graph_Graph3->GetXaxis()->SetLabelFont(42);
   Graph_Graph3->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph3->GetXaxis()->SetTickLength(0.02);
   Graph_Graph3->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph3->GetXaxis()->SetTitleFont(42);
   Graph_Graph3->GetYaxis()->SetLabelFont(42);
   Graph_Graph3->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph3->GetYaxis()->SetTickLength(0.02);
   Graph_Graph3->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph3->GetYaxis()->SetTitleFont(42);
   Graph_Graph3->GetZaxis()->SetLabelFont(42);
   Graph_Graph3->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph3->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph3->GetZaxis()->SetTickLength(0.02);
   Graph_Graph3->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph3);
   
   graph->Draw("f ");
   
   Double_t Graph1_fx4[37] = {
   1.058016,
   0.9999988,
   0.9310335,
   0.8620681,
   0.8118821,
   0.7931027,
   0.7241373,
   0.6689998,
   0.6551719,
   0.6179975,
   0.6150978,
   0.6534888,
   0.6551719,
   0.7241373,
   0.741459,
   0.7931027,
   0.8620681,
   0.9233202,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.236208,
   1.27586,
   1.344826,
   1.355491,
   1.37818,
   1.358977,
   1.344826,
   1.305813,
   1.27586,
   1.219835,
   1.206895,
   1.13793,
   1.068964,
   1.058016};
   Double_t Graph1_fy4[37] = {
   1.206895,
   1.217059,
   1.220951,
   1.216327,
   1.206895,
   1.201649,
   1.170824,
   1.13793,
   1.121593,
   1.068964,
   0.9999988,
   0.9310335,
   0.9295388,
   0.8741425,
   0.8620681,
   0.8378245,
   0.8112162,
   0.7931027,
   0.791349,
   0.7809648,
   0.7762242,
   0.7776548,
   0.7861598,
   0.7931027,
   0.8082258,
   0.8522283,
   0.8620681,
   0.9310335,
   0.9999988,
   1.019211,
   1.068964,
   1.094449,
   1.13793,
   1.145458,
   1.17844,
   1.204359,
   1.206895};
   graph = new TGraph(37,Graph1_fx4,Graph1_fy4);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9999cc");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph34 = new TH1F("Graph_Graph_Graph34","Graph",100,0.5387895,1.454489);
   Graph_Graph_Graph34->SetMinimum(0.7317515);
   Graph_Graph_Graph34->SetMaximum(1.265424);
   Graph_Graph_Graph34->SetDirectory(0);
   Graph_Graph_Graph34->SetStats(0);
   Graph_Graph_Graph34->SetLineStyle(0);
   Graph_Graph_Graph34->SetMarkerStyle(20);
   Graph_Graph_Graph34->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph34->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph34->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph34->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph34->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph34->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph34->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph34->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph34->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph34->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph34->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph34->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph34->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph34->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph34->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph34->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph34);
   
   graph->Draw("l ");
   
   Double_t Graph2_fx5[39] = {
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027,
   0.7889615,
   0.7241373,
   0.6551719,
   0.6364565,
   0.5862065,
   0.5807069,
   0.5794827,
   0.5862065,
   0.6250438,
   0.6551719,
   0.719959,
   0.7241373,
   0.7931027,
   0.8620681,
   0.9149037,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.247499,
   1.27586,
   1.344826,
   1.372837,
   1.401066,
   1.381846,
   1.344826,
   1.328001,
   1.27586,
   1.235472,
   1.206895,
   1.13793,
   1.068964,
   1.064794,
   0.9999988};
   Double_t Graph2_fy5[39] = {
   1.217281,
   1.221364,
   1.218207,
   1.207896,
   1.206895,
   1.183382,
   1.149136,
   1.13793,
   1.076562,
   1.068964,
   0.9999988,
   0.9894909,
   0.9310335,
   0.9078869,
   0.8620681,
   0.8600541,
   0.8313067,
   0.8073368,
   0.7931027,
   0.789763,
   0.7802808,
   0.775828,
   0.7769679,
   0.7844753,
   0.7931027,
   0.8025326,
   0.8398638,
   0.8620681,
   0.9310335,
   0.9999988,
   1.048472,
   1.068964,
   1.109383,
   1.13793,
   1.152786,
   1.182596,
   1.206008,
   1.206895,
   1.217281};
   graph = new TGraph(39,Graph2_fx5,Graph2_fy5);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,0.4973243,1.483225);
   Graph_Graph5->SetMinimum(0.7312744);
   Graph_Graph5->SetMaximum(1.265917);
   Graph_Graph5->SetDirectory(0);
   Graph_Graph5->SetStats(0);
   Graph_Graph5->SetLineStyle(0);
   Graph_Graph5->SetMarkerStyle(20);
   Graph_Graph5->GetXaxis()->SetLabelFont(42);
   Graph_Graph5->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph5->GetXaxis()->SetTickLength(0.02);
   Graph_Graph5->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph5->GetXaxis()->SetTitleFont(42);
   Graph_Graph5->GetYaxis()->SetLabelFont(42);
   Graph_Graph5->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph5->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph5->GetYaxis()->SetTickLength(0.02);
   Graph_Graph5->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph5->GetYaxis()->SetTitleFont(42);
   Graph_Graph5->GetZaxis()->SetLabelFont(42);
   Graph_Graph5->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph5->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph5->GetZaxis()->SetTickLength(0.02);
   Graph_Graph5->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph5);
   
   graph->Draw("l ");
   
   Double_t Graph3_fx6[69] = {
   0.8620681,
   0.7931027,
   0.7241373,
   0.7124508,
   0.6551719,
   0.5862065,
   0.5172411,
   0.4651494,
   0.4482757,
   0.3793104,
   0.310345,
   0.305282,
   0.2413796,
   0.1785771,
   0.1724142,
   0.1034488,
   0.09809099,
   0.1034488,
   0.1287438,
   0.1724142,
   0.2271161,
   0.2413796,
   0.310345,
   0.3393019,
   0.3793104,
   0.4482757,
   0.4661862,
   0.5172411,
   0.5862065,
   0.6208766,
   0.6551719,
   0.7241373,
   0.7931027,
   0.8544866,
   0.8620681,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.344826,
   1.370093,
   1.413791,
   1.482757,
   1.53925,
   1.551722,
   1.616042,
   1.620687,
   1.646115,
   1.644485,
   1.620687,
   1.616851,
   1.565278,
   1.551722,
   1.493762,
   1.482757,
   1.413791,
   1.400576,
   1.344826,
   1.277283,
   1.27586,
   1.206895,
   1.13793,
   1.068964,
   1.066109,
   0.9999988,
   0.9310335,
   0.8620681};
   Double_t Graph3_fy6[69] = {
   1.359711,
   1.355344,
   1.346844,
   1.344826,
   1.332326,
   1.313761,
   1.29271,
   1.27586,
   1.26841,
   1.237934,
   1.208786,
   1.206895,
   1.168891,
   1.13793,
   1.130609,
   1.071409,
   1.068964,
   1.062427,
   0.9999988,
   0.9759044,
   0.9310335,
   0.9242807,
   0.8826347,
   0.8620681,
   0.8417471,
   0.8034031,
   0.7931027,
   0.7697865,
   0.7388223,
   0.7241373,
   0.7117905,
   0.6893669,
   0.6698025,
   0.6551719,
   0.6535692,
   0.6420767,
   0.6338483,
   0.6290533,
   0.6279132,
   0.6306952,
   0.6376932,
   0.6491981,
   0.6551719,
   0.6681488,
   0.6955743,
   0.7241373,
   0.7333955,
   0.7931027,
   0.8020646,
   0.8620681,
   0.9310335,
   0.9908604,
   0.9999988,
   1.068964,
   1.082395,
   1.13793,
   1.146517,
   1.197686,
   1.206895,
   1.239343,
   1.27586,
   1.276517,
   1.303677,
   1.326522,
   1.344332,
   1.344826,
   1.35441,
   1.359488,
   1.359711};
   graph = new TGraph(69,Graph3_fx6,Graph3_fy6);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetLineStyle(7);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,0,1.800917);
   Graph_Graph6->SetMinimum(0.5547334);
   Graph_Graph6->SetMaximum(1.432891);
   Graph_Graph6->SetDirectory(0);
   Graph_Graph6->SetStats(0);
   Graph_Graph6->SetLineStyle(0);
   Graph_Graph6->SetMarkerStyle(20);
   Graph_Graph6->GetXaxis()->SetLabelFont(42);
   Graph_Graph6->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph6->GetXaxis()->SetTickLength(0.02);
   Graph_Graph6->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph6->GetXaxis()->SetTitleFont(42);
   Graph_Graph6->GetYaxis()->SetLabelFont(42);
   Graph_Graph6->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph6->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph6->GetYaxis()->SetTickLength(0.02);
   Graph_Graph6->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph6->GetYaxis()->SetTitleFont(42);
   Graph_Graph6->GetZaxis()->SetLabelFont(42);
   Graph_Graph6->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph6->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph6->GetZaxis()->SetTickLength(0.02);
   Graph_Graph6->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph6);
   
   graph->Draw("l ");
   
   Double_t Graph4_fx7[1] = {
   1};
   Double_t Graph4_fy7[1] = {
   1};
   graph = new TGraph(1,Graph4_fx7,Graph4_fy7);
   graph->SetName("Graph4");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(34);
   graph->SetMarkerSize(3);
   
   TH1F *Graph_Graph7 = new TH1F("Graph_Graph7","Graph",100,0.9,2.1);
   Graph_Graph7->SetMinimum(0.9);
   Graph_Graph7->SetMaximum(2.1);
   Graph_Graph7->SetDirectory(0);
   Graph_Graph7->SetStats(0);
   Graph_Graph7->SetLineStyle(0);
   Graph_Graph7->SetMarkerStyle(20);
   Graph_Graph7->GetXaxis()->SetLabelFont(42);
   Graph_Graph7->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph7->GetXaxis()->SetTickLength(0.02);
   Graph_Graph7->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph7->GetXaxis()->SetTitleFont(42);
   Graph_Graph7->GetYaxis()->SetLabelFont(42);
   Graph_Graph7->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph7->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph7->GetYaxis()->SetTickLength(0.02);
   Graph_Graph7->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph7->GetYaxis()->SetTitleFont(42);
   Graph_Graph7->GetZaxis()->SetLabelFont(42);
   Graph_Graph7->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph7->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph7->GetZaxis()->SetTickLength(0.02);
   Graph_Graph7->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph7);
   
   graph->Draw("p ");
   
   Double_t Graph5_fx8[1] = {
   1};
   Double_t Graph5_fy8[1] = {
   1};
   graph = new TGraph(1,Graph5_fx8,Graph5_fy8);
   graph->SetName("Graph5");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(33);
   graph->SetMarkerSize(3);
   
   TH1F *Graph_Graph8 = new TH1F("Graph_Graph8","Graph",100,0.9,2.1);
   Graph_Graph8->SetMinimum(0.9);
   Graph_Graph8->SetMaximum(2.1);
   Graph_Graph8->SetDirectory(0);
   Graph_Graph8->SetStats(0);
   Graph_Graph8->SetLineStyle(0);
   Graph_Graph8->SetMarkerStyle(20);
   Graph_Graph8->GetXaxis()->SetLabelFont(42);
   Graph_Graph8->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph8->GetXaxis()->SetTickLength(0.02);
   Graph_Graph8->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph8->GetXaxis()->SetTitleFont(42);
   Graph_Graph8->GetYaxis()->SetLabelFont(42);
   Graph_Graph8->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph8->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph8->GetYaxis()->SetTickLength(0.02);
   Graph_Graph8->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph8->GetYaxis()->SetTitleFont(42);
   Graph_Graph8->GetZaxis()->SetLabelFont(42);
   Graph_Graph8->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph8->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph8->GetZaxis()->SetTickLength(0.02);
   Graph_Graph8->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph8);
   
   graph->Draw("p ");
   
   TLegend *leg = new TLegend(0.15,0.15,0.85,0.3,NULL,"NBNDC");
   leg->SetNColumns(2);
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("Graph1","68% CL - Combined, H#rightarrow#tau#tau","F");

   ci = TColor::GetColor("#9999cc");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph0","95% CL - Combined, H#rightarrow#tau#tau","F");

   ci = TColor::GetColor("#ccccff");
   entry->SetFillColor(ci);
   entry->SetFillStyle(1001);
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph2","68% CL - ggH + VBF, H#rightarrow#tau#tau","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(2);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph3","95% CL - ggH + VBF, H#rightarrow#tau#tau","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(7);
   entry->SetLineWidth(2);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph4","Best fit","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph5","Expected for 125 GeV SM Higgs","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   leg->Draw();
   leg->Draw("SAME");
   TLatex *   tex = new TLatex(0.1578,0.9113,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      //tex = new TLatex(0.1578,0.8393,"Preliminary");
      tex = new TLatex(0.1578,0.8393,"Supplementary");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextFont(52);
   tex->SetTextSize(0.0456);
   tex->SetLineWidth(2);
   tex->Draw();
   TLatex *text = new TLatex(0.7,0.96,"35.9 fb^{-1} (13 TeV)");
   text->SetNDC();
   text->SetTextSize(0.03);
   text->Draw();
      tex = new TLatex(0.96,0.952,"");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.12,0.952,"");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH2D *prototype_copy2 = new TH2D("prototype_copy2","prototype",29,0,2,29,0,2);
   prototype_copy2->SetDirectory(0);
   prototype_copy2->SetLineStyle(0);
   prototype_copy2->SetMarkerStyle(20);
   prototype_copy2->GetXaxis()->SetTitle("#kappa_{v}");
   prototype_copy2->GetXaxis()->SetLabelFont(42);
   prototype_copy2->GetXaxis()->SetLabelSize(0.025);
   prototype_copy2->GetXaxis()->SetTitleSize(0.05);
   prototype_copy2->GetXaxis()->SetTickLength(0.02);
   prototype_copy2->GetXaxis()->SetTitleOffset(1.08);
   prototype_copy2->GetXaxis()->SetTitleFont(42);
   prototype_copy2->GetYaxis()->SetTitle("#kappa_{f}");
   prototype_copy2->GetYaxis()->SetLabelFont(42);
   prototype_copy2->GetYaxis()->SetLabelOffset(0.007);
   prototype_copy2->GetYaxis()->SetLabelSize(0.025);
   prototype_copy2->GetYaxis()->SetTitleSize(0.05);
   prototype_copy2->GetYaxis()->SetTickLength(0.02);
   prototype_copy2->GetYaxis()->SetTitleOffset(1.08);
   prototype_copy2->GetYaxis()->SetTitleFont(42);
   prototype_copy2->GetZaxis()->SetLabelFont(42);
   prototype_copy2->GetZaxis()->SetLabelOffset(0.007);
   prototype_copy2->GetZaxis()->SetTitleSize(0.05);
   prototype_copy2->GetZaxis()->SetTickLength(0.02);
   prototype_copy2->GetZaxis()->SetTitleFont(42);
   prototype_copy2->Draw("sameaxis");
   
   Double_t Graph5_fx9[1] = {
   1};
   Double_t Graph5_fy9[1] = {
   1};
   graph = new TGraph(1,Graph5_fx9,Graph5_fy9);
   graph->SetName("Graph5");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerStyle(33);
   graph->SetMarkerSize(3);
   
   TH1F *Graph_Graph_Graph89 = new TH1F("Graph_Graph_Graph89","Graph",100,0.9,2.1);
   Graph_Graph_Graph89->SetMinimum(0.9);
   Graph_Graph_Graph89->SetMaximum(2.1);
   Graph_Graph_Graph89->SetDirectory(0);
   Graph_Graph_Graph89->SetStats(0);
   Graph_Graph_Graph89->SetLineStyle(0);
   Graph_Graph_Graph89->SetMarkerStyle(20);
   Graph_Graph_Graph89->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph89->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph89->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph89->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph89->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph89->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph89->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph89->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph89->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph89->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph89->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph89->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph89->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph89->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph89->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph89->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph89);
   
   graph->Draw("p ");
   
   Double_t Graph6_fx10[1] = {
   1};
   Double_t Graph6_fy10[1] = {
   1};
   graph = new TGraph(1,Graph6_fx10,Graph6_fy10);
   graph->SetName("Graph6");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetMarkerColor(2);
   graph->SetMarkerStyle(33);
   graph->SetMarkerSize(2);
   
   TH1F *Graph_Graph10 = new TH1F("Graph_Graph10","Graph",100,0.9,2.1);
   Graph_Graph10->SetMinimum(0.9);
   Graph_Graph10->SetMaximum(2.1);
   Graph_Graph10->SetDirectory(0);
   Graph_Graph10->SetStats(0);
   Graph_Graph10->SetLineStyle(0);
   Graph_Graph10->SetMarkerStyle(20);
   Graph_Graph10->GetXaxis()->SetLabelFont(42);
   Graph_Graph10->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph10->GetXaxis()->SetTickLength(0.02);
   Graph_Graph10->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph10->GetXaxis()->SetTitleFont(42);
   Graph_Graph10->GetYaxis()->SetLabelFont(42);
   Graph_Graph10->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph10->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph10->GetYaxis()->SetTickLength(0.02);
   Graph_Graph10->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph10->GetYaxis()->SetTitleFont(42);
   Graph_Graph10->GetZaxis()->SetLabelFont(42);
   Graph_Graph10->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph10->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph10->GetZaxis()->SetTickLength(0.02);
   Graph_Graph10->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph10);
   
   graph->Draw("p ");
   
   leg = new TLegend(0.15,0.15,0.5,0.35,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   entry=leg->AddEntry("NULL"," ","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("NULL"," ","");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("Graph6"," ","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(2);
   entry->SetTextFont(42);
   leg->Draw();
   pad->Modified();
   limit->cd();
   limit->Modified();
   limit->cd();
   limit->SetSelected(limit);
   limit->SaveAs("new_limit.png");
   limit->SaveAs("new_limit.pdf");
}
