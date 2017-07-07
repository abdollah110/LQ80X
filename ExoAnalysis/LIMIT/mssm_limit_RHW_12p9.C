void mssm_limit_RHW_12p9()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Jul 27 09:42:19 2016) by ROOT version6.04/14
    //=========  (Wed Jul 27 09:41:49 2016) by ROOT version6.04/14
    TCanvas *c1 = new TCanvas("c1", "c1",0,45,600,600);
    gStyle->SetOptStat(0);
    c1->SetHighLightColor(2);
    c1->Range(0,0,1,1);
    c1->SetFillColor(0);
    c1->SetBorderMode(0);
    c1->SetBorderSize(2);
    c1->SetLeftMargin(0.12);
    c1->SetRightMargin(0.04);
    c1->SetTopMargin(0.06);
    c1->SetBottomMargin(0.12);
    c1->SetFrameFillStyle(0);
    c1->SetFrameLineWidth(2);
    c1->SetFrameBorderMode(0);
    
    // ------------>Primitives in pad: pad_leg
    TPad *pad_leg = new TPad("pad_leg", "pad_leg",0.4,0.65,0.9,0.9);
    pad_leg->Draw();
    pad_leg->cd();
    pad_leg->Range(0,0,1,1);
    pad_leg->SetFillColor(0);
    pad_leg->SetFillStyle(4000);
    pad_leg->SetBorderMode(0);
    pad_leg->SetBorderSize(2);
    pad_leg->SetLeftMargin(0.12);
    pad_leg->SetRightMargin(0.04);
    pad_leg->SetTopMargin(0.06);
    pad_leg->SetBottomMargin(0.12);
    pad_leg->SetFrameFillStyle(0);
    pad_leg->SetFrameLineWidth(2);
    pad_leg->SetFrameBorderMode(0);
    
    TLegend *leg = new TLegend(0.29,0.01,0.79,0.91,NULL,"NBNDC");
    leg->SetBorderSize(0);
    leg->SetTextFont(62);
    leg->SetTextSize(0.15);
    leg->SetLineColor(1);
    leg->SetLineStyle(1);
    leg->SetLineWidth(1);
    leg->SetFillColor(0);
    leg->SetFillStyle(1001);
    
    //    TLegendEntry *entry=leg->AddEntry("NULL","95% CL Excluded:","h");
    //   entry->SetLineColor(1);
    //   entry->SetLineStyle(1);
    //   entry->SetLineWidth(1);
    //   entry->SetMarkerColor(1);
    //   entry->SetMarkerStyle(21);
    //   entry->SetMarkerSize(1);
    //   entry->SetTextFont(62);
    
    TLegendEntry * entry=leg->AddEntry("Graph1","Theory (M_{Nu}=M_{W}/2)","L");
    entry->SetLineColor(4);
    entry->SetLineStyle(1);
    entry->SetLineWidth(3);
    entry->SetMarkerColor(4);
    entry->SetMarkerStyle(21);
    entry->SetMarkerSize(1);
    entry->SetTextFont(62);
    
    entry=leg->AddEntry("Graph","Observed","L");
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(3);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(21);
    entry->SetMarkerSize(1);
    entry->SetTextFont(62);
    
    entry=leg->AddEntry("Graph","Expected","L");
    
    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
    
    ci = TColor::GetColor("#ff0000");
    entry->SetLineColor(ci);
    entry->SetLineStyle(1);
    entry->SetLineWidth(3);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(21);
    entry->SetMarkerSize(1);
    entry->SetTextFont(62);
    
    
    entry=leg->AddEntry("","#pm 1#sigma Expected","F");
    
    
    ci = TColor::GetColor("#00ff00");
    entry->SetFillColor(ci);
    entry->SetFillStyle(1001);
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(1);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(21);
    entry->SetMarkerSize(1);
    entry->SetTextFont(62);
    
    
    entry=leg->AddEntry("","#pm 2#sigma Expected","F");
    
    ci = TColor::GetColor("#fcf10f");
    entry->SetFillColor(ci);
    entry->SetFillStyle(1001);
    entry->SetLineColor(1);
    entry->SetLineStyle(1);
    entry->SetLineWidth(1);
    entry->SetMarkerColor(1);
    entry->SetMarkerStyle(21);
    entry->SetMarkerSize(1);
    entry->SetTextFont(62);
    leg->Draw();
    pad_leg->Modified();
    c1->cd();
    
    // ------------>Primitives in pad: pad_plot
    TPad *pad_plot = new TPad("pad_plot", "pad_plot",0,0,1,1);
    pad_plot->Draw();
    pad_plot->cd();
    pad_plot->Range(10.71429,-5.02439,1588.095,3.512195);
    pad_plot->SetFillColor(0);
    pad_plot->SetFillStyle(4000);
    pad_plot->SetBorderMode(0);
    pad_plot->SetBorderSize(2);
    pad_plot->SetLogy();
    pad_plot->SetGridx();
    pad_plot->SetGridy();
    pad_plot->SetLeftMargin(0.12);
    pad_plot->SetRightMargin(0.04);
    pad_plot->SetTopMargin(0.06);
    pad_plot->SetBottomMargin(0.12);
    pad_plot->SetFrameFillStyle(0);
    pad_plot->SetFrameLineWidth(2);
    pad_plot->SetFrameBorderMode(0);
    pad_plot->SetFrameFillStyle(0);
    pad_plot->SetFrameLineWidth(2);
    pad_plot->SetFrameBorderMode(0);

    
    
  
   
   TH1F *hist1d__1 = new TH1F("hist1d__1","",4,1000,4000);
   hist1d__1->SetMinimum(0.0001);
   hist1d__1->SetMaximum(10);
   hist1d__1->SetDirectory(0);
   hist1d__1->SetLineStyle(0);
   hist1d__1->SetMarkerStyle(20);
   hist1d__1->GetXaxis()->SetTitle("M_{W_{R}} [GeV]");
   hist1d__1->GetXaxis()->SetMoreLogLabels();
   hist1d__1->GetXaxis()->SetNoExponent();
   hist1d__1->GetXaxis()->SetNdivisions(50005);
   hist1d__1->GetXaxis()->SetLabelFont(42);
   hist1d__1->GetXaxis()->SetTitleSize(0.05);
   hist1d__1->GetXaxis()->SetTickLength(0.02);
   hist1d__1->GetXaxis()->SetTitleOffset(1.08);
   hist1d__1->GetXaxis()->SetTitleFont(42);
   hist1d__1->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{}(pp#rightarrowW)#timesB(W#rightarrow#tau#taujj)[pb]");
   hist1d__1->GetYaxis()->SetNdivisions(506);
   hist1d__1->GetYaxis()->SetLabelFont(42);
   hist1d__1->GetYaxis()->SetLabelOffset(0.007);
   hist1d__1->GetYaxis()->SetTitleSize(0.045);
   hist1d__1->GetYaxis()->SetTickLength(0.02);
   hist1d__1->GetYaxis()->SetTitleOffset(1.08);
   hist1d__1->GetYaxis()->SetTitleFont(42);
   hist1d__1->GetZaxis()->SetNdivisions(506);
   hist1d__1->GetZaxis()->SetLabelFont(42);
   hist1d__1->GetZaxis()->SetLabelOffset(0.007);
   hist1d__1->GetZaxis()->SetTitleSize(0.05);
   hist1d__1->GetZaxis()->SetTickLength(0.02);
   hist1d__1->GetZaxis()->SetTitleFont(42);
   hist1d__1->Draw("");
   
   Double_t _fx3001[4] = {
   1000,
   2000,
   3000,
   4000};
   Double_t _fy3001[4] = {
   0.1017046,
   0.006637573,
   0.001922607,
   0.0009155273};
   Double_t _felx3001[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3001[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehx3001[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3001[4] = {
   0.253551,
   0.02293857,
   0.008620317,
   0.006080244};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(4,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#fcf10f");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph13001 = new TH1F("Graph_Graph_Graph13001","",100,700,4300);
   Graph_Graph_Graph13001->SetMinimum(0.0008239746);
   Graph_Graph_Graph13001->SetMaximum(0.3906896);
   Graph_Graph_Graph13001->SetDirectory(0);
   Graph_Graph_Graph13001->SetStats(0);
   Graph_Graph_Graph13001->SetLineStyle(0);
   Graph_Graph_Graph13001->SetMarkerStyle(20);
   Graph_Graph_Graph13001->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph13001->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph13001->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph13001->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph13001->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph13001->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph13001->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph13001->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph13001->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph13001->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph13001->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph13001->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph13001->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph13001->GetZaxis()->SetNdivisions(506);
   Graph_Graph_Graph13001->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph13001->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph13001->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph13001->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph13001->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph13001);
   
   grae->Draw("3");
   
   Double_t _fx3002[4] = {
   1000,
   2000,
   3000,
   4000};
   Double_t _fy3002[4] = {
   0.1350721,
   0.009928703,
   0.002849579,
   0.001296997};
   Double_t _felx3002[4] = {
   0,
   0,
   0,
   0};
   Double_t _fely3002[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehx3002[4] = {
   0,
   0,
   0,
   0};
   Double_t _fehy3002[4] = {
   0.1270998,
   0.01100461,
   0.00406737,
   0.002701457};
   grae = new TGraphAsymmErrors(4,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph23002 = new TH1F("Graph_Graph_Graph23002","",100,700,4300);
   Graph_Graph_Graph23002->SetMinimum(0.001167297);
   Graph_Graph_Graph23002->SetMaximum(0.2882594);
   Graph_Graph_Graph23002->SetDirectory(0);
   Graph_Graph_Graph23002->SetStats(0);
   Graph_Graph_Graph23002->SetLineStyle(0);
   Graph_Graph_Graph23002->SetMarkerStyle(20);
   Graph_Graph_Graph23002->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph23002->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph23002->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph23002->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph23002->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph23002->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph23002->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph23002->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph23002->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph23002->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph23002->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph23002->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph23002->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph23002->GetZaxis()->SetNdivisions(506);
   Graph_Graph_Graph23002->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph23002->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph23002->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph23002->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph23002->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(Graph_Graph_Graph23002);
   
   grae->Draw("3");
   
   Double_t Graph0_fx1[4] = {
   1000,
   2000,
   3000,
   4000};
   Double_t Graph0_fy1[4] = {
   0.1879883,
   0.01416016,
   0.004394531,
   0.002441406};
   TGraph *graph = new TGraph(4,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Graph",100,700,4300);
   Graph_Graph_Graph11->SetMinimum(0.002197266);
   Graph_Graph_Graph11->SetMaximum(0.206543);
   Graph_Graph_Graph11->SetDirectory(0);
   Graph_Graph_Graph11->SetStats(0);
   Graph_Graph_Graph11->SetLineStyle(0);
   Graph_Graph_Graph11->SetMarkerStyle(20);
   Graph_Graph_Graph11->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph11->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph11->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph11->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph11->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetNdivisions(506);
   Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph11->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph11->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph11);
   
   graph->Draw("l");
   
   Double_t Graph1_fx2[4] = {
   1000,
   2000,
   3000,
   4000};
   Double_t Graph1_fy2[4] = {
   0.2550263,
   0.01361321,
   0.004516363,
   0.002601394};
   graph = new TGraph(4,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph22 = new TH1F("Graph_Graph_Graph22","Graph",100,700,4300);
   Graph_Graph_Graph22->SetMinimum(0.002341255);
   Graph_Graph_Graph22->SetMaximum(0.2802688);
   Graph_Graph_Graph22->SetDirectory(0);
   Graph_Graph_Graph22->SetStats(0);
   Graph_Graph_Graph22->SetLineStyle(0);
   Graph_Graph_Graph22->SetMarkerStyle(20);
   Graph_Graph_Graph22->GetXaxis()->SetNdivisions(506);
   Graph_Graph_Graph22->GetXaxis()->SetLabelFont(42);
   Graph_Graph_Graph22->GetXaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph22->GetXaxis()->SetTickLength(0.02);
   Graph_Graph_Graph22->GetXaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph22->GetXaxis()->SetTitleFont(42);
   Graph_Graph_Graph22->GetYaxis()->SetNdivisions(506);
   Graph_Graph_Graph22->GetYaxis()->SetLabelFont(42);
   Graph_Graph_Graph22->GetYaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph22->GetYaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph22->GetYaxis()->SetTickLength(0.02);
   Graph_Graph_Graph22->GetYaxis()->SetTitleOffset(1.08);
   Graph_Graph_Graph22->GetYaxis()->SetTitleFont(42);
   Graph_Graph_Graph22->GetZaxis()->SetNdivisions(506);
   Graph_Graph_Graph22->GetZaxis()->SetLabelFont(42);
   Graph_Graph_Graph22->GetZaxis()->SetLabelOffset(0.007);
   Graph_Graph_Graph22->GetZaxis()->SetTitleSize(0.05);
   Graph_Graph_Graph22->GetZaxis()->SetTickLength(0.02);
   Graph_Graph_Graph22->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(Graph_Graph_Graph22);
   
   graph->Draw("pl");
    
    
    
    const int nTH=7;
    
    Double_t mTh[nTH] = {1000,1500,2000,2500,3000,3500,4000};
    
    
    
    
//    Double_t xsTh[nTH] = {1.692E0,2.9E-1,6.563E-02,1.92E-02,6.030E-03,1.92E-03,6.030E-04};
    Double_t xsTh[nTH] = {1.692E0,2.9E-1,6.563E-02,1.92E-02,6.030E-03,0.00209,0.000801};
    
    
    
    TGraph *xsTh_vs_m = new TGraph(nTH, mTh, xsTh);
    
    xsTh_vs_m->SetLineWidth(2);
    
    xsTh_vs_m->SetLineColor(kBlue);
    
    xsTh_vs_m->SetFillColor(kCyan-6);
    
    xsTh_vs_m->SetMarkerSize(0.00001);
    
    xsTh_vs_m->SetMarkerStyle(22);
    
    xsTh_vs_m->SetMarkerColor(kBlue);
    
    
    //    TGraph *grshade = new TGraph(2*nTH,x_pdf,y_pdf);
    //
    //    grshade->SetFillColor(kCyan-6);
    //
    //    grshade->SetFillStyle(3001);
    
    
    xsTh_vs_m->Draw("L");
    
    //    grshade->Draw("f");
    
    
    
    tex = new TLatex(0.1578,0.9113,"");
    tex->SetNDC();
    tex->SetTextAlign(13);
    tex->SetTextSize(0.048);
    tex->SetLineWidth(2);
    tex->Draw();
    tex = new TLatex(0.2,0.88,"CMS  ");
    tex->SetNDC();
    tex->SetTextAlign(12);
    tex->SetTextFont(61);
    tex->SetTextSize(0.06);
    tex->SetLineWidth(2);
    tex->Draw();
    tex = new TLatex(0.2,0.8," Preliminary ");
    tex->SetNDC();
    tex->SetTextAlign(12);
    tex->SetTextFont(52);
    tex->SetTextSize(0.055);
    tex->SetLineWidth(2);
    tex->Draw();
    
    tex = new TLatex(0.96,0.952,"12.9 fb^{-1} (13 TeV)");
    tex->SetNDC();
    tex->SetTextAlign(31);
    tex->SetTextFont(42);
    tex->SetTextSize(0.056);
    tex->SetLineWidth(2);
    tex->Draw();
   
    TH1F *hist1d__2 = new TH1F("hist1d__2","",3,2000,4000);
    hist1d__2->SetMinimum(0.0001);
    hist1d__2->SetMaximum(10);
    hist1d__2->SetDirectory(0);
    
    ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
    ptstats->SetName("stats");
    ptstats->SetBorderSize(1);
    ptstats->SetFillColor(0);
    ptstats->SetTextAlign(12);
    ptstats->SetTextFont(42);
    AText = ptstats->AddText("hist1d");
    AText->SetTextSize(0.0368);
    //   AText = ptstats->AddText("Entries = 0      ");
    //   AText = ptstats->AddText("Mean  =      0");
    //   AText = ptstats->AddText("Std Dev   =      0");
    ptstats->SetOptStat(0);
    ptstats->SetOptFit(0);
    //   ptstats->Draw();
    hist1d__2->GetListOfFunctions()->Add(ptstats);
    ptstats->SetParent(hist1d__2);
    hist1d__2->SetLineStyle(0);
    hist1d__2->SetMarkerStyle(20);
    hist1d__2->GetXaxis()->SetTitle("M_{W_{R}} [GeV]");
    hist1d__2->GetXaxis()->SetMoreLogLabels();
    hist1d__2->GetXaxis()->SetNoExponent();
    hist1d__2->GetXaxis()->SetNdivisions(50005);
    hist1d__2->GetXaxis()->SetLabelFont(42);
    hist1d__2->GetXaxis()->SetTitleSize(0.05);
    hist1d__2->GetXaxis()->SetTickLength(0.02);
    hist1d__2->GetXaxis()->SetTitleOffset(1.08);
    hist1d__2->GetXaxis()->SetTitleFont(42);
    hist1d__2->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{}(pp#rightarrowW)#timesB(W#rightarrow#tau#taujj)[pb]");
    hist1d__2->GetYaxis()->SetNdivisions(506);
    hist1d__2->GetYaxis()->SetLabelFont(42);
    hist1d__2->GetYaxis()->SetLabelOffset(0.007);
    hist1d__2->GetYaxis()->SetTitleSize(0.045);
    hist1d__2->GetYaxis()->SetTickLength(0.02);
    hist1d__2->GetYaxis()->SetTitleOffset(1.08);
    hist1d__2->GetYaxis()->SetTitleFont(42);
    hist1d__2->GetZaxis()->SetNdivisions(506);
    hist1d__2->GetZaxis()->SetLabelFont(42);
    hist1d__2->GetZaxis()->SetLabelOffset(0.007);
    hist1d__2->GetZaxis()->SetTitleSize(0.05);
    hist1d__2->GetZaxis()->SetTickLength(0.02);
    hist1d__2->GetZaxis()->SetTitleFont(42);
    hist1d__2->Draw("sameaxis");
    pad_plot->Modified();
    c1->cd();
    c1->Modified();
    c1->cd();
    c1->SetSelected(c1);
}