void limit()
{
//=========Macro generated from canvas: limit/limit
//=========  (Tue May 29 21:00:41 2018) by ROOT version6.02/05
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
   0.7931027,
   0.7241373,
   0.6831796,
   0.6551719,
   0.5862065,
   0.5323517,
   0.5172411,
   0.4482757,
   0.4363618,
   0.3793104,
   0.3751724,
   0.3459241,
   0.3497309,
   0.3793104,
   0.3831713,
   0.4400569,
   0.4482757,
   0.5172411,
   0.5184077,
   0.5862065,
   0.6214889,
   0.6551719,
   0.7241373,
   0.7650893,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9999988,
   1.068964,
   1.125115,
   1.13793,
   1.148218,
   1.206895,
   1.27586,
   1.344826,
   1.413791,
   1.458961,
   1.482757,
   1.551264,
   1.551722,
   1.589389,
   1.597523,
   1.582191,
   1.551722,
   1.549984,
   1.501188,
   1.482757,
   1.439752,
   1.413791,
   1.364349,
   1.344826,
   1.27586,
   1.269211,
   1.206895,
   1.13793,
   1.128384,
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027};
   Double_t Graph0_fy1[61] = {
   1.372096,
   1.357013,
   1.344826,
   1.334351,
   1.303147,
   1.27586,
   1.265503,
   1.215524,
   1.206895,
   1.142372,
   1.13793,
   1.068964,
   0.9999988,
   0.9396109,
   0.9310335,
   0.8620681,
   0.8549731,
   0.7941076,
   0.7931027,
   0.746612,
   0.7241373,
   0.7057632,
   0.6722935,
   0.6551719,
   0.6447819,
   0.6236676,
   0.6071653,
   0.5952675,
   0.5881786,
   0.5862065,
   0.585817,
   0.5862065,
   0.5888203,
   0.5977416,
   0.6131138,
   0.6355466,
   0.6551719,
   0.6695741,
   0.7241373,
   0.7247859,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9963944,
   0.9999988,
   1.068964,
   1.090145,
   1.13793,
   1.162469,
   1.206895,
   1.222138,
   1.271668,
   1.27586,
   1.309743,
   1.341506,
   1.344826,
   1.362592,
   1.376095,
   1.38214,
   1.380697,
   1.372096};
   TGraph *graph = new TGraph(61,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ccccff");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,0.2207642,1.722683);
   Graph_Graph1->SetMinimum(0.5061847);
   Graph_Graph1->SetMaximum(1.461772);
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
   0.7931027,
   0.7241373,
   0.6831796,
   0.6551719,
   0.5862065,
   0.5323517,
   0.5172411,
   0.4482757,
   0.4363618,
   0.3793104,
   0.3751724,
   0.3459241,
   0.3497309,
   0.3793104,
   0.3831713,
   0.4400569,
   0.4482757,
   0.5172411,
   0.5184077,
   0.5862065,
   0.6214889,
   0.6551719,
   0.7241373,
   0.7650893,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9999988,
   1.068964,
   1.125115,
   1.13793,
   1.148218,
   1.206895,
   1.27586,
   1.344826,
   1.413791,
   1.458961,
   1.482757,
   1.551264,
   1.551722,
   1.589389,
   1.597523,
   1.582191,
   1.551722,
   1.549984,
   1.501188,
   1.482757,
   1.439752,
   1.413791,
   1.364349,
   1.344826,
   1.27586,
   1.269211,
   1.206895,
   1.13793,
   1.128384,
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027};
   Double_t Graph0_fy2[61] = {
   1.372096,
   1.357013,
   1.344826,
   1.334351,
   1.303147,
   1.27586,
   1.265503,
   1.215524,
   1.206895,
   1.142372,
   1.13793,
   1.068964,
   0.9999988,
   0.9396109,
   0.9310335,
   0.8620681,
   0.8549731,
   0.7941076,
   0.7931027,
   0.746612,
   0.7241373,
   0.7057632,
   0.6722935,
   0.6551719,
   0.6447819,
   0.6236676,
   0.6071653,
   0.5952675,
   0.5881786,
   0.5862065,
   0.585817,
   0.5862065,
   0.5888203,
   0.5977416,
   0.6131138,
   0.6355466,
   0.6551719,
   0.6695741,
   0.7241373,
   0.7247859,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9963944,
   0.9999988,
   1.068964,
   1.090145,
   1.13793,
   1.162469,
   1.206895,
   1.222138,
   1.271668,
   1.27586,
   1.309743,
   1.341506,
   1.344826,
   1.362592,
   1.376095,
   1.38214,
   1.380697,
   1.372096};
   graph = new TGraph(61,Graph0_fx2,Graph0_fy2);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#ccccff");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph12 = new TH1F("Graph_Graph_Graph12","Graph",100,0.2207642,1.722683);
   Graph_Graph_Graph12->SetMinimum(0.5061847);
   Graph_Graph_Graph12->SetMaximum(1.461772);
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
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027,
   0.7835099,
   0.7241373,
   0.6826105,
   0.6551719,
   0.6423526,
   0.640834,
   0.6551719,
   0.6729308,
   0.7241373,
   0.7419662,
   0.7931027,
   0.8620681,
   0.8687168,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.286298,
   1.344826,
   1.351946,
   1.360437,
   1.344826,
   1.339031,
   1.291163,
   1.27586,
   1.217677,
   1.206895,
   1.13793,
   1.092473,
   1.068964};
   Double_t Graph1_fy3[37] = {
   1.215331,
   1.230254,
   1.234815,
   1.228307,
   1.21072,
   1.206895,
   1.171149,
   1.13793,
   1.093568,
   1.068964,
   0.9999988,
   0.9673246,
   0.9310335,
   0.8779398,
   0.8620681,
   0.8306213,
   0.7956645,
   0.7931027,
   0.7742526,
   0.7600617,
   0.7531113,
   0.754083,
   0.7647591,
   0.7876361,
   0.7931027,
   0.8513334,
   0.8620681,
   0.9310335,
   0.9823571,
   0.9999988,
   1.068964,
   1.084473,
   1.13793,
   1.14558,
   1.186088,
   1.206895,
   1.215331};
   graph = new TGraph(37,Graph1_fx3,Graph1_fy3);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9999cc");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3 = new TH1F("Graph_Graph3","Graph",100,0.5688737,1.432397);
   Graph_Graph3->SetMinimum(0.7049409);
   Graph_Graph3->SetMaximum(1.282986);
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
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027,
   0.7835099,
   0.7241373,
   0.6826105,
   0.6551719,
   0.6423526,
   0.640834,
   0.6551719,
   0.6729308,
   0.7241373,
   0.7419662,
   0.7931027,
   0.8620681,
   0.8687168,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.286298,
   1.344826,
   1.351946,
   1.360437,
   1.344826,
   1.339031,
   1.291163,
   1.27586,
   1.217677,
   1.206895,
   1.13793,
   1.092473,
   1.068964};
   Double_t Graph1_fy4[37] = {
   1.215331,
   1.230254,
   1.234815,
   1.228307,
   1.21072,
   1.206895,
   1.171149,
   1.13793,
   1.093568,
   1.068964,
   0.9999988,
   0.9673246,
   0.9310335,
   0.8779398,
   0.8620681,
   0.8306213,
   0.7956645,
   0.7931027,
   0.7742526,
   0.7600617,
   0.7531113,
   0.754083,
   0.7647591,
   0.7876361,
   0.7931027,
   0.8513334,
   0.8620681,
   0.9310335,
   0.9823571,
   0.9999988,
   1.068964,
   1.084473,
   1.13793,
   1.14558,
   1.186088,
   1.206895,
   1.215331};
   graph = new TGraph(37,Graph1_fx4,Graph1_fy4);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");

   ci = TColor::GetColor("#9999cc");
   graph->SetFillColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph34 = new TH1F("Graph_Graph_Graph34","Graph",100,0.5688737,1.432397);
   Graph_Graph_Graph34->SetMinimum(0.7049409);
   Graph_Graph_Graph34->SetMaximum(1.282986);
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
   
   Double_t Graph2_fx5[37] = {
   1.098238,
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681,
   0.7931027,
   0.7648548,
   0.7241373,
   0.6551719,
   0.6547152,
   0.6142328,
   0.6140554,
   0.6492827,
   0.6551719,
   0.7235379,
   0.7241373,
   0.7931027,
   0.8582722,
   0.8620681,
   0.9310335,
   0.9999988,
   1.068964,
   1.13793,
   1.206895,
   1.27586,
   1.297101,
   1.344826,
   1.366796,
   1.37819,
   1.357068,
   1.344826,
   1.307535,
   1.27586,
   1.229919,
   1.206895,
   1.13793,
   1.098238};
   Double_t Graph2_fy5[37] = {
   1.206895,
   1.2165,
   1.23053,
   1.235495,
   1.230805,
   1.216417,
   1.206895,
   1.186076,
   1.138309,
   1.13793,
   1.068964,
   0.9999988,
   0.9310335,
   0.9250623,
   0.8620681,
   0.861682,
   0.8233778,
   0.7931027,
   0.7917096,
   0.7723982,
   0.7590958,
   0.7523433,
   0.7530418,
   0.7625925,
   0.7830478,
   0.7931027,
   0.8337616,
   0.8620681,
   0.9310335,
   0.9999988,
   1.017975,
   1.068964,
   1.098782,
   1.13793,
   1.152827,
   1.190197,
   1.206895};
   graph = new TGraph(37,Graph2_fx5,Graph2_fy5);
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetLineStyle(2);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph5 = new TH1F("Graph_Graph5","Graph",100,0.537642,1.454603);
   Graph_Graph5->SetMinimum(0.7040281);
   Graph_Graph5->SetMaximum(1.283811);
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
   
   Double_t Graph3_fx6[65] = {
   0.8620681,
   0.7931027,
   0.7241373,
   0.6551719,
   0.6468068,
   0.5862065,
   0.5172411,
   0.4811408,
   0.4482757,
   0.3793104,
   0.3706971,
   0.310345,
   0.2968262,
   0.2628693,
   0.2726422,
   0.310345,
   0.3195675,
   0.3793104,
   0.3907855,
   0.4482757,
   0.4814005,
   0.5172411,
   0.5862065,
   0.5936225,
   0.6551719,
   0.7241373,
   0.7448223,
   0.7931027,
   0.8620681,
   0.9310335,
   0.9999988,
   1.061292,
   1.068964,
   1.13793,
   1.203551,
   1.206895,
   1.27586,
   1.344826,
   1.413791,
   1.47194,
   1.482757,
   1.551722,
   1.565522,
   1.609132,
   1.620687,
   1.621362,
   1.620687,
   1.608319,
   1.576255,
   1.551722,
   1.528101,
   1.482757,
   1.465068,
   1.413791,
   1.385539,
   1.344826,
   1.284824,
   1.27586,
   1.206895,
   1.13793,
   1.137094,
   1.068964,
   0.9999988,
   0.9310335,
   0.8620681};
   Double_t Graph3_fy6[65] = {
   1.382758,
   1.37637,
   1.364292,
   1.347329,
   1.344826,
   1.321906,
   1.292295,
   1.27586,
   1.255385,
   1.212029,
   1.206895,
   1.149464,
   1.13793,
   1.068964,
   0.9999988,
   0.9463782,
   0.9310335,
   0.8740209,
   0.8620681,
   0.8187771,
   0.7931027,
   0.7706089,
   0.7283907,
   0.7241373,
   0.6937007,
   0.6631396,
   0.6551719,
   0.6385531,
   0.6189084,
   0.6034504,
   0.592243,
   0.5862065,
   0.5855405,
   0.5837357,
   0.5862065,
   0.586353,
   0.594942,
   0.6096616,
   0.6310664,
   0.6551719,
   0.6612396,
   0.7115438,
   0.7241373,
   0.7931027,
   0.8574109,
   0.8620681,
   0.865839,
   0.9310335,
   0.9999988,
   1.035766,
   1.068964,
   1.119131,
   1.13793,
   1.183242,
   1.206895,
   1.236084,
   1.27586,
   1.281035,
   1.315342,
   1.344557,
   1.344826,
   1.363641,
   1.376517,
   1.382899,
   1.382758};
   graph = new TGraph(65,Graph3_fx6,Graph3_fy6);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetLineStyle(7);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph6 = new TH1F("Graph_Graph6","Graph",100,0.12702,1.757211);
   Graph_Graph6->SetMinimum(0.5038194);
   Graph_Graph6->SetMaximum(1.462815);
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
   
   TLegend *leg = new TLegend(0.15,0.15,0.85,0.35,NULL,"NBNDC");
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

   entry=leg->AddEntry("Graph5","Expected for 125 GeV SM Higgs","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(33);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);

   entry=leg->AddEntry("Graph4","Best fit","P");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(34);
   entry->SetMarkerSize(3);
   entry->SetTextFont(42);
   //entry=leg->AddEntry("Graph5","Expected for 125 GeV SM Higgs","P");
   //entry->SetLineColor(1);
   //entry->SetLineStyle(1);
   //entry->SetLineWidth(1);
   //entry->SetMarkerColor(1);
   //entry->SetMarkerStyle(33);
   //entry->SetMarkerSize(3);
   //entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.1578,0.9113,"CMS");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.06);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.1578,0.8393,"Preliminary");
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
   
   leg = new TLegend(0.15,0.15,0.85,0.35,NULL,"NBNDC");
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
   limit->SaveAs("lim.root");
}
