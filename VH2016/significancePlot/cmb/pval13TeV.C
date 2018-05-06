void pval13TeV()
{
//=========Macro generated from canvas: c/c
//=========  (Fri Apr 27 15:48:30 2018) by ROOT version6.02/05
   TCanvas *c = new TCanvas("c", "c",597,1463,800,755);
   gStyle->SetOptStat(0);
   c->SetHighLightColor(2);
   c->Range(100,-9.786341,150,1.087371);
   c->SetFillColor(0);
   c->SetBorderMode(0);
   c->SetBorderSize(2);
   c->SetLogy();
   c->SetTickx(1);
   c->SetTicky(1);
   c->SetFrameBorderMode(0);
   c->SetFrameBorderMode(0);
   
   TH1D *dummy1 = new TH1D("dummy1","",1,105,145);
   dummy1->SetMinimum(2e-09);
   dummy1->SetMaximum(1);
   dummy1->SetStats(0);
   dummy1->SetLineColor(0);
   dummy1->GetXaxis()->SetTitle("m_{H} (GeV)");
   dummy1->GetXaxis()->SetLabelFont(42);
   dummy1->GetXaxis()->SetLabelSize(0.035);
   dummy1->GetXaxis()->SetTitleSize(0.05);
   dummy1->GetXaxis()->SetTitleOffset(0.9);
   dummy1->GetXaxis()->SetTitleFont(42);
   dummy1->GetYaxis()->SetTitle("Local p-value");
   dummy1->GetYaxis()->SetLabelFont(42);
   dummy1->GetYaxis()->SetLabelSize(0.035);
   dummy1->GetYaxis()->SetTitleSize(0.05);
   dummy1->GetYaxis()->SetTitleFont(42);
   dummy1->GetZaxis()->SetLabelFont(42);
   dummy1->GetZaxis()->SetLabelSize(0.035);
   dummy1->GetZaxis()->SetTitleSize(0.035);
   dummy1->GetZaxis()->SetTitleFont(42);
   dummy1->Draw("AXIS");
   
   TMultiGraph *multigraph = new TMultiGraph();
   multigraph->SetName("");
   multigraph->SetTitle("");
   
   Double_t _fx1[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t _fy1[5] = {
   2.712551e-06,
   1.987012e-08,
   2.268319e-08,
   3.258179e-07,
   1.943227e-05};
   TGraph *graph = new TGraph(5,_fx1,_fy1);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineColor(2);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","",100,107,143);
   Graph_Graph1->SetMinimum(1.788311e-08);
   Graph_Graph1->SetMaximum(2.137351e-05);
   Graph_Graph1->SetDirectory(0);
   Graph_Graph1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   Graph_Graph1->SetLineColor(ci);
   Graph_Graph1->GetXaxis()->SetLabelFont(42);
   Graph_Graph1->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetXaxis()->SetTitleFont(42);
   Graph_Graph1->GetYaxis()->SetLabelFont(42);
   Graph_Graph1->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetYaxis()->SetTitleFont(42);
   Graph_Graph1->GetZaxis()->SetLabelFont(42);
   Graph_Graph1->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph1->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph1);
   
   multigraph->Add(graph,"");
   
   Double_t _fx2[5] = {
   110,
   120,
   125,
   130,
   140};
   Double_t _fy2[5] = {
   7.486246e-05,
   2.17509e-06,
   1.707949e-06,
   3.157411e-06,
   1.019045e-05};
   graph = new TGraph(5,_fx2,_fy2);
   graph->SetName("");
   graph->SetTitle("");
   graph->SetFillColor(1);
   graph->SetLineColor(4);
   graph->SetLineStyle(2);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,107,143);
   Graph_Graph2->SetMinimum(1.537154e-06);
   Graph_Graph2->SetMaximum(8.217791e-05);
   Graph_Graph2->SetDirectory(0);
   Graph_Graph2->SetStats(0);

   ci = TColor::GetColor("#000099");
   Graph_Graph2->SetLineColor(ci);
   Graph_Graph2->GetXaxis()->SetLabelFont(42);
   Graph_Graph2->GetXaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetXaxis()->SetTitleFont(42);
   Graph_Graph2->GetYaxis()->SetLabelFont(42);
   Graph_Graph2->GetYaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetYaxis()->SetTitleFont(42);
   Graph_Graph2->GetZaxis()->SetLabelFont(42);
   Graph_Graph2->GetZaxis()->SetLabelSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleSize(0.035);
   Graph_Graph2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph2);
   
   multigraph->Add(graph,"");
   multigraph->Draw("L");
   
   TH1D *dummy2 = new TH1D("dummy2","",1,105,145);
   dummy2->SetMinimum(2e-09);
   dummy2->SetMaximum(1);
   dummy2->SetStats(0);
   dummy2->SetLineColor(0);
   dummy2->GetXaxis()->SetTitle("m_{H} (GeV)");
   dummy2->GetXaxis()->SetLabelFont(42);
   dummy2->GetXaxis()->SetLabelSize(0.035);
   dummy2->GetXaxis()->SetTitleSize(0.05);
   dummy2->GetXaxis()->SetTitleOffset(0.9);
   dummy2->GetXaxis()->SetTitleFont(42);
   dummy2->GetYaxis()->SetTitle("Local p-value");
   dummy2->GetYaxis()->SetLabelFont(42);
   dummy2->GetYaxis()->SetLabelSize(0.035);
   dummy2->GetYaxis()->SetTitleSize(0.05);
   dummy2->GetYaxis()->SetTitleFont(42);
   dummy2->GetZaxis()->SetLabelFont(42);
   dummy2->GetZaxis()->SetLabelSize(0.035);
   dummy2->GetZaxis()->SetTitleSize(0.035);
   dummy2->GetZaxis()->SetTitleFont(42);
   dummy2->Draw("AXIGSAME");
   TLine *line = new TLine(105,0.1586553,145,0.1586553);
   line->SetLineColor(13);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
   TLatex *   tex = new TLatex(140,0.1745208,"1 #sigma");
   tex->SetTextColor(13);
   tex->SetLineWidth(2);
   tex->Draw();
   line = new TLine(105,0.02275013,145,0.02275013);
   line->SetLineColor(13);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(140,0.02502515,"2 #sigma");
   tex->SetTextColor(13);
   tex->SetLineWidth(2);
   tex->Draw();
   line = new TLine(105,0.001349898,145,0.001349898);
   line->SetLineColor(13);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(140,0.001484888,"3 #sigma");
   tex->SetTextColor(13);
   tex->SetLineWidth(2);
   tex->Draw();
   line = new TLine(105,3.167124e-05,145,3.167124e-05);
   line->SetLineColor(13);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(140,3.483837e-05,"4 #sigma");
   tex->SetTextColor(13);
   tex->SetLineWidth(2);
   tex->Draw();
   line = new TLine(105,2.866516e-07,145,2.866516e-07);
   line->SetLineColor(13);
   line->SetLineStyle(2);
   line->SetLineWidth(2);
   line->Draw();
      tex = new TLatex(140,3.153167e-07,"5 #sigma");
   tex->SetTextColor(13);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TLegend *leg = new TLegend(0.14,0.65,0.4,0.8,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("","Observed","L");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   entry=leg->AddEntry("","Expected","L");
   entry->SetLineColor(4);
   entry->SetLineStyle(2);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(42);
   leg->Draw();
      tex = new TLatex(0.1,0.92,"#bf{CMS} #scale[0.75]{#it{Preliminary}}");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.6,0.92,"35.9 fb^{-1} (13TeV)");
tex->SetNDC();
   tex->SetTextFont(42);
   tex->SetTextSize(0.045);
   tex->SetLineWidth(2);
   tex->Draw();
   c->Modified();
   c->cd();
   c->SetSelected(c);
}
