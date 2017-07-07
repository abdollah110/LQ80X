void rhw_9p23()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Jul 20 13:37:27 2016) by ROOT version6.04/14
   TCanvas *c1 = new TCanvas("c1", "c1",0,45,600,600);
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
   TPad *pad_leg = new TPad("pad_leg", "pad_leg",0,0.82,1,1);
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
   TLegendEntry *entry=leg->AddEntry("NULL","95% CL Excluded:","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("Graph1","Observed","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","#pm 1#sigma Expected","F");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
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
   entry=leg->AddEntry("Graph0","Expected","L");

   ci = TColor::GetColor("#ff0000");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
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
   TPad *pad_plot = new TPad("pad_plot", "pad_plot",0,0,1,0.82);
   pad_plot->Draw();
   pad_plot->cd();
   pad_plot->Range(1642.857,-4.731707,4619.048,1.365854);
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
   
   TH1F *hist1d__1 = new TH1F("hist1d__1","",3,2000,4500);
   hist1d__1->SetMinimum(0.0001);
   hist1d__1->SetMaximum(10);
   hist1d__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.775,0.98,0.935,"brNDC");
   ptstats->SetName("stats");
   ptstats->SetBorderSize(1);
   ptstats->SetFillColor(0);
   ptstats->SetTextAlign(12);
   ptstats->SetTextFont(42);
   TText *AText = ptstats->AddText("hist1d");
   AText->SetTextSize(0.0368);
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hist1d__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hist1d__1);
   hist1d__1->SetLineStyle(0);
   hist1d__1->SetMarkerStyle(20);
   hist1d__1->GetXaxis()->SetTitle("M_{W_RH} [GeV]");
    hist1d__1->GetXaxis()->SetRangeUser(2000,4000);
   hist1d__1->GetXaxis()->SetMoreLogLabels();
   hist1d__1->GetXaxis()->SetNoExponent();
   hist1d__1->GetXaxis()->SetNdivisions(50005);
   hist1d__1->GetXaxis()->SetLabelFont(42);
   hist1d__1->GetXaxis()->SetTitleSize(0.05);
   hist1d__1->GetXaxis()->SetTickLength(0.02);
   hist1d__1->GetXaxis()->SetTitleOffset(1.08);
   hist1d__1->GetXaxis()->SetTitleFont(42);
   hist1d__1->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{}#upoint#font[52]{B}#font[42]{}^2 [pb]");
   hist1d__1->GetYaxis()->SetNdivisions(506);
   hist1d__1->GetYaxis()->SetLabelFont(42);
   hist1d__1->GetYaxis()->SetLabelOffset(0.007);
   hist1d__1->GetYaxis()->SetTitleSize(0.05);
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
   
   Double_t _fx3001[3] = {
   2000,
   3000,
   4000};
   Double_t _fy3001[3] = {
   0.008041382,
   0.002349854,
   0.001281738};
   Double_t _felx3001[3] = {
   0,
   0,
   0};
   Double_t _fely3001[3] = {
   0,
   0,
   0};
   Double_t _fehx3001[3] = {
   0,
   0,
   0};
   Double_t _fehy3001[3] = {
   0.02487171,
   0.01053594,
   0.007613147};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(3,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#fcf10f");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph13001 = new TH1F("Graph_Graph_Graph13001","",100,1800,4200);
   Graph_Graph_Graph13001->SetMinimum(0.001153564);
   Graph_Graph_Graph13001->SetMaximum(0.03607623);
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
   
   Double_t _fx3002[3] = {
   2000,
   3000,
   4000};
   Double_t _fy3002[3] = {
   0.01025867,
   0.003482819,
   0.001548767};
   Double_t _felx3002[3] = {
   0,
   0,
   0};
   Double_t _fely3002[3] = {
   0,
   0,
   0};
   Double_t _fehx3002[3] = {
   0,
   0,
   0};
   Double_t _fehy3002[3] = {
   0.01308369,
   0.00497123,
   0.004049069};
   grae = new TGraphAsymmErrors(3,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph23002 = new TH1F("Graph_Graph_Graph23002","",100,1800,4200);
   Graph_Graph_Graph23002->SetMinimum(0.00139389);
   Graph_Graph_Graph23002->SetMaximum(0.02552172);
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
   
   Double_t Graph0_fx1[3] = {
   2000,
   3000,
   4000};
   Double_t Graph0_fy1[3] = {
   0.01513672,
   0.005371094,
   0.003417969};
   TGraph *graph = new TGraph(3,Graph0_fx1,Graph0_fy1);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   
   TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Graph",100,1800,4200);
   Graph_Graph_Graph11->SetMinimum(0.002246094);
   Graph_Graph_Graph11->SetMaximum(0.01630859);
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
   
   Double_t Graph1_fx2[3] = {
   2000,
   3000,
   4000};
   Double_t Graph1_fy2[3] = {
   0.02270817,
   0.0063587,
   0.003269134};
   graph = new TGraph(3,Graph1_fx2,Graph1_fy2);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph_Graph22 = new TH1F("Graph_Graph_Graph22","Graph",100,1800,4200);
   Graph_Graph_Graph22->SetMinimum(0.001325231);
   Graph_Graph_Graph22->SetMaximum(0.02465207);
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
    
    
    
    const int nTH=5;
    
    Double_t mTh[nTH] = {2000,2500,3000,3500,4000};
    
    
    
    //    else if (OutName.find("skimed_0_RHNu_2000-1000") != string::npos) return     6.563E-02;
    //    else if (OutName.find("skimed_0_RHNu_2500-1250") != string::npos) return     1.92E-02;
    //    else if (OutName.find("skimed_0_RHNu_3000-1500") != string::npos) return     6.030E-03;
    
    
//    Double_t x_pdf[2*nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0,1400.0,1390.0,1380.0,1370.0,1360.0,1350.0,1340.0,1330.0,1320.0,1310.0,1300.0,1290.0,1280.0,1270.0,1260.0,1250.0,1240.0,1230.0,1220.0,1210.0,1200.0,1190.0,1180.0,1170.0,1160.0,1150.0,1140.0,1130.0,1120.0,1110.0,1100.0,1090.0,1080.0,1070.0,1060.0,1050.0,1040.0,1030.0,1020.0,1010.0,1000.0,990.0,980.0,970.0,960.0,950.0,940.0,930.0,920.0,910.0,900.0,890.0,880.0,870.0,860.0,850.0,840.0,830.0,820.0,810.0,800.0,790.0,780.0,770.0,760.0,750.0,740.0,730.0,720.0,710.0,700.0,690.0,680.0,670.0,660.0,650.0,640.0,630.0,620.0,610.0,600.0,590.0,580.0,570.0,560.0,550.0,540.0,530.0,520.0,510.0,500.0,490.0,480.0,470.0,460.0,450.0,440.0,430.0,420.0,410.0,400.0,390.0,380.0,370.0,360.0,350.0,340.0,330.0,320.0,310.0,300.0,290.0,280.0,270.0,260.0,250.0,240.0,230.0,220.0,210.0,200.0};
    
    //for beta=1
    
    Double_t xsTh[nTH] = {6.563E-02,1.92E-02,6.030E-03,1.92E-03,6.030E-04};
    //,4.07E-04,3.84E-04,3.61E-04,3.41E-04,3.21E-04,3.03E-04,2.85E-04,2.69E-04,2.54E-04,2.40E-04,2.26E-04,2.13E-04,2.02E-04,1.90E-04,1.80E-04,1.70E-04,1.60E-04,1.51E-04,1.43E-04,1.35E-04,1.28E-04,1.21E-04,1.14E-04,1.08E-04,1.02E-04,9.66E-05,9.13E-05,8.64E-05,8.18E-05,7.74E-05,7.32E-05,6.93E-05,6.56E-05,6.21E-05,5.88E-05,5.57E-05,5.27E-05,5.00E-05,4.73E-05,4.48E-05,4.25E-05,4.02E-05,3.81E-05,3.61E-05,3.43E-05,3.25E-05,3.08E-05,2.92E-05,2.77E-05,2.62E-05,2.49E-05,2.36E-05,2.24E-05,2.12E-05,2.01E-05,1.91E-05,1.81E-05,1.72E-05,1.63E-05,1.55E-05,1.47E-05,1.39E-05,1.32E-05,1.26E-05,1.19E-05,1.13E-05,1.07E-05,1.02E-05,9.68E-06,9.20E-06,8.73E-06,8.29E-06,7.87E-06,7.47E-06,7.10E-06,6.74E-06,6.41E-06,6.08E-06,5.78E-06,5.49E-06,5.22E-06,4.96E-06,4.71E-06,4.47E-06,4.26E-06,4.04E-06,3.84E-06,3.65E-06,3.46E-06,3.30E-06,3.13E-06,2.97E-06,2.83E-06,2.69E-06,2.55E-06,2.43E-06,2.31E-06,2.19E-06,2.08E-06,1.98E-06,1.88E-06,1.79E-06,1.70E-06,1.62E-06,1.54E-06,1.46E-06,1.39E-06,1.32E-06,1.25E-06,1.19E-06,1.13E-06,1.08E-06,1.03E-06,9.74E-07,9.27E-07,8.81E-07,8.37E-07,7.96E-07,7.57E-07,7.20E-07,6.84E-07,6.50E-07,6.19E-07,5.88E-07,5.60E-07,5.32E-07,5.05E-07,4.80E-07,4.57E-07,4.35E-07,4.13E-07,3.92E-07,3.73E-07,3.55E-07,3.38E-07,3.21E-07,3.05E-07,2.90E-07,2.75E-07,2.62E-07,2.49E-07,2.36E-07,2.25E-07,2.14E-07,2.03E-07,1.93E-07,1.83E-07,1.74E-07,1.66E-07,1.58E-07,1.50E-07,1.42E-07,1.35E-07,1.28E-07,1.22E-07,1.16E-07,1.10E-07,1.05E-07,9.95E-08,9.46E-08}
    
    
    //for beta=1
    
//    Double_t y_pdf[2*nTH] = {63.1,49.97,39.99,32.2,26.17,21.39,17.632,14.61,12.204,10.216,8.575,7.273,6.168,5.268,4.504,3.875,3.345,2.888,2.512,2.182,1.901,1.665,1.461,1.287,1.136,1.0012,0.886,0.7851,0.6978,0.6223,0.5538,0.4959,0.4433,0.3979,0.3562,0.3209,0.2885,0.2597,0.2352,0.2129,0.1927,0.1748,0.158,0.1435,0.131,0.1187,0.1083,0.0988,0.0902,0.0824,0.0754,0.06898,0.06324,0.0581,0.05326,0.04887,0.04491,0.04134,0.038,0.0351,0.03233,0.02978,0.02747,0.02538,0.02351,0.02175,0.02011,0.0186,0.0173,0.01602,0.01483,0.01377,0.01282,0.01187,0.01105,0.01028,0.00955,0.00889,0.00828,0.00772,0.00719,0.0067,0.00626,0.00584,0.00545,0.005092,0.004751,0.004447,0.004157,0.003889,0.003635,0.003404,0.003185,0.002988,0.002794,0.002621,0.002461,0.002303,0.002166,0.002031,0.001907,0.001795,0.001684,0.001584,0.001485,0.001399,0.001312,0.001235,0.001162,0.001093,0.001029,0.00097,0.000913,0.00086,0.000811,0.000764,0.00072,0.000679,0.00064,0.000604,0.000571,0.000295,0.000314,0.000334,0.000357,0.00038,0.000406,0.000433,0.000462,0.000493,0.000526,0.000561,0.000599,0.00064,0.000683,0.000728,0.000781,0.000835,0.000896,0.000956,0.001025,0.001093,0.001169,0.001254,0.001337,0.001439,0.001539,0.001646,0.001772,0.001895,0.002036,0.002185,0.002351,0.002523,0.002713,0.002909,0.003128,0.00337,0.00362,0.0039,0.0042,0.00453,0.00488,0.00526,0.00567,0.00613,0.00662,0.00713,0.00771,0.00838,0.00903,0.00977,0.01058,0.0115,0.0124,0.01349,0.01465,0.01589,0.01722,0.01873,0.02042,0.02227,0.0243,0.0264,0.02886,0.03149,0.03433,0.03774,0.0413,0.04516,0.04942,0.0542,0.0596,0.0654,0.072,0.0795,0.0873,0.097,0.1065,0.118,0.1312,0.1453,0.1611,0.1788,0.1983,0.2215,0.2471,0.2758,0.3101,0.3467,0.3901,0.4382,0.4937,0.5562,0.6289,0.714,0.8108,0.924,1.053,1.199,1.375,1.579,1.818,2.108,2.432,2.835,3.305,3.856,4.532,5.332,6.327,7.505,8.984,10.796,12.99,15.768,19.21,23.63,29.2,36.41,45.83,58.1};
    
    
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
      tex = new TLatex(0.96,0.952,"CMS Preliminary        9.2 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *hist1d__2 = new TH1F("hist1d__2","",3,2000,4500);
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
   AText = ptstats->AddText("Entries = 0      ");
   AText = ptstats->AddText("Mean  =      0");
   AText = ptstats->AddText("Std Dev   =      0");
   ptstats->SetOptStat(1111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hist1d__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hist1d__2);
   hist1d__2->SetLineStyle(0);
   hist1d__2->SetMarkerStyle(20);
   hist1d__2->GetXaxis()->SetTitle("M_{W_RH} [GeV]");
   hist1d__2->GetXaxis()->SetMoreLogLabels();
   hist1d__2->GetXaxis()->SetNoExponent();
   hist1d__2->GetXaxis()->SetNdivisions(50005);
   hist1d__2->GetXaxis()->SetLabelFont(42);
   hist1d__2->GetXaxis()->SetTitleSize(0.05);
   hist1d__2->GetXaxis()->SetTickLength(0.02);
   hist1d__2->GetXaxis()->SetTitleOffset(1.08);
   hist1d__2->GetXaxis()->SetTitleFont(42);
   hist1d__2->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{}#upoint#font[52]{B}#font[42]{}^2 [pb]");
   hist1d__2->GetYaxis()->SetNdivisions(506);
   hist1d__2->GetYaxis()->SetLabelFont(42);
   hist1d__2->GetYaxis()->SetLabelOffset(0.007);
   hist1d__2->GetYaxis()->SetTitleSize(0.05);
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
