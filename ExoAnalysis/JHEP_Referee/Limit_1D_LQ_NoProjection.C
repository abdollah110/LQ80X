void Limit_1D_LQ()
{
    //=========Macro generated from canvas: c1/c1
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
    
    TLegend *leg = new TLegend(0.20,0.01,0.85,0.91,NULL,"NBNDC");
    leg->SetBorderSize(0);
    leg->SetTextFont(62);
    leg->SetTextSize(0.15);
    leg->SetLineColor(1);
    leg->SetLineStyle(2);
    leg->SetLineWidth(2);
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
    
    TLegendEntry * entry=leg->AddEntry("Graph1","Theory (#beta=1)","L");
    entry->SetLineColor(4);
    entry->SetLineStyle(2);
    entry->SetLineWidth(4);
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
    
    
    entry=leg->AddEntry("","68% expected","F");
    
    
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
    
    
    entry=leg->AddEntry("","95% expected","F");
    
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
    pad_plot->Range(10.71429,-5.02439,1500,3.512195);
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
    
    TH1F *hist1d__1 = new TH1F("hist1d__1","",27,200,1525);
    hist1d__1->SetMinimum(0.0001);
    hist1d__1->SetMaximum(1000000);
    hist1d__1->SetDirectory(0);
    hist1d__1->SetLineStyle(0);
    hist1d__1->SetMarkerStyle(20);
    hist1d__1->GetXaxis()->SetTitle("M_{LQ} [GeV]");
    hist1d__1->GetXaxis()->SetMoreLogLabels();
    hist1d__1->GetXaxis()->SetNoExponent();
    hist1d__1->GetXaxis()->SetNdivisions(50005);
    hist1d__1->GetXaxis()->SetLabelFont(42);
    hist1d__1->GetXaxis()->SetTitleSize(0.05);
    hist1d__1->GetXaxis()->SetTickLength(0.02);
    hist1d__1->GetXaxis()->SetTitleOffset(1.08);
    hist1d__1->GetXaxis()->SetTitleFont(42);
    hist1d__1->GetYaxis()->SetTitle("#sigma#font[42]{}#upoint#font[52]{#beta}^{2} [pb]");
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
    
    
    Double_t Graph0_fx3001[27] = {
        200,
        250,
        300,
        350,
        400,
        450,
        500,
        550,
        600,
        650,
        700,
        750,
        800,
        850,
        900,
        950,
        1000,
        1050,
        1100,
        1150,
        1200,
        1250,
        1300,
        1350,
        1400,
        1450,
        1500};
    Double_t Graph0_fy3001[27] = {
        4000,
        2283.5,
        984.75,
        386.5,
        199.5,
        109.25,
        66.25,
        47.625,
        35.90625,
        27.375,
        22.5625,
        18,
        14.9375,
        12.40625,
        11.53125,
        9.78125,
        8.71875,
        7.78125,
        6.96875,
        6.59375,
        6.015625,
        5.6875,
        5.265625,
        4.859375,
        4.828125,
        4.421875,
        4.265625};
    Double_t Graph0_felx3001[27] = {
        3.286146e-316,
        0,
        0,
        0,
        6.915387e-310,
        3.28723e-316,
        2.121996e-314,
        3.288524e-316,
        0,
        3.288529e-316,
        3.28723e-316,
        0,
        3.288526e-316,
        7.625109e-317,
        7.627117e-317,
        3.288531e-316,
        2.124327e-314,
        3.288535e-316,
        5.582942e-322,
        6.915387e-310,
        0,
        3.287231e-316,
        3.288525e-316,
        3.288529e-316,
        1.58101e-322,
        3.288397e-316,
        5.582942e-322};
    Double_t Graph0_fely3001[27] = {
        1570.312,
        1172.97,
        486.605,
        184.9463,
        95.46387,
        52.70459,
        32.21924,
        23.34741,
        17.74274,
        13.63403,
        11.50159,
        9.175781,
        7.731323,
        6.518127,
        6.103455,
        5.291809,
        4.785095,
        4.33136,
        3.933533,
        3.799133,
        3.489532,
        3.365845,
        3.136749,
        2.913727,
        2.923279,
        2.685944,
        2.611862};
    Double_t Graph0_fehx3001[27] = {
        3.291578e-316,
        6.952719e-310,
        0,
        3.270357e-316,
        3.270357e-316,
        0,
        6.952719e-310,
        0,
        0,
        6.952719e-310,
        6.952719e-310,
        0,
        0,
        0,
        0,
        0,
        3.270367e-316,
        3.270357e-316,
        6.952719e-310,
        6.952719e-310,
        0,
        0,
        0,
        0,
        1.58101e-322,
        3.270377e-316,
        5.143223e-321};
    Double_t Graph0_fehy3001[27] = {
        6325.103,
        2948.912,
        1128.434,
        407.0027,
        211.0707,
        116.937,
        73.68011,
        53.99405,
        41.74464,
        33.05804,
        28.78028,
        23.2452,
        20.2483,
        17.47852,
        16.84906,
        15.00021,
        14.04523,
        13.11364,
        12.36674,
        12.42815,
        11.597,
        11.55033,
        10.69423,
        9.869759,
        9.806889,
        8.982265,
        8.665401};

    TGraphAsymmErrors *grae = new TGraphAsymmErrors(27,Graph0_fx3001,Graph0_fy3001,Graph0_felx3001,Graph0_fehx3001,Graph0_fely3001,Graph0_fehy3001);
    grae->SetName("");
    grae->SetTitle("");
    
    ci = TColor::GetColor("#fcf10f");
    grae->SetFillColor(ci);
    grae->SetMarkerStyle(20);
    
    TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","",100,70,1630);
    Graph_Graph3001->SetMinimum(0);
    Graph_Graph3001->SetMaximum(9.939362);
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
    Graph_Graph3001->GetYaxis()->SetTitleOffset(1.08);
    Graph_Graph3001->GetYaxis()->SetTitleFont(42);
    Graph_Graph3001->GetZaxis()->SetNdivisions(506);
    Graph_Graph3001->GetZaxis()->SetLabelFont(42);
    Graph_Graph3001->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph3001->GetZaxis()->SetTitleSize(0.05);
    Graph_Graph3001->GetZaxis()->SetTickLength(0.02);
    Graph_Graph3001->GetZaxis()->SetTitleFont(42);
    grae->SetHistogram(Graph_Graph3001);
    
    grae->Draw("3");
    
    Double_t Graph1_fx3002[27] = {
        200,
        250,
        300,
        350,
        400,
        450,
        500,
        550,
        600,
        650,
        700,
        750,
        800,
        850,
        900,
        950,
        1000,
        1050,
        1100,
        1150,
        1200,
        1250,
        1300,
        1350,
        1400,
        1450,
        1500};
    Double_t Graph1_fy3002[27] = {
        4000,
        2283.5,
        984.75,
        386.5,
        199.5,
        109.25,
        66.25,
        47.625,
        35.90625,
        27.375,
        22.5625,
        18,
        14.9375,
        12.40625,
        11.53125,
        9.78125,
        8.71875,
        7.78125,
        6.96875,
        6.59375,
        6.015625,
        5.6875,
        5.265625,
        4.859375,
        4.828125,
        4.421875,
        4.265625};
    Double_t Graph1_felx3002[27] = {
        3.283148e-316,
        2.121996e-314,
        3.276171e-316,
        0,
        2.420922e-322,
        3.283104e-316,
        0,
        2.11372e-314,
        0,
        4.940656e-323,
        8.744962e-322,
        0,
        0,
        4.940656e-323,
        0,
        6.915388e-310,
        5.33769e+160,
        0,
        3.248384e-316,
        6.915388e-310,
        0,
        2.121996e-314,
        3.282506e-316,
        0,
        1.58101e-322,
        3.278395e-316,
        1.630417e-322};
    Double_t Graph1_fely3002[27] = {
        674.7437,
        746.8518,
        304.1281,
        114.869,
        59.29201,
        32.73449,
        20.26288,
        14.50093,
        11.15852,
        8.574528,
        7.233419,
        5.842392,
        4.922678,
        4.150214,
        3.933867,
        3.431407,
        3.102835,
        2.825536,
        2.566015,
        2.478341,
        2.303637,
        2.221983,
        2.095251,
        1.946279,
        1.952659,
        1.804618,
        1.754845};
    Double_t Graph1_fehx3002[27] = {
        1.038253e-312,
        2.121996e-314,
        3.276171e-316,
        0,
        2.420922e-322,
        3.283137e-316,
        0,
        2.113722e-314,
        0,
        4.940656e-323,
        8.744962e-322,
        0,
        0,
        4.940656e-323,
        0,
        6.915388e-310,
        2.139459e+161,
        0,
        3.248384e-316,
        6.915388e-310,
        0,
        2.121996e-314,
        3.282506e-316,
        0,
        1.58101e-322,
        3.282182e-316,
        1.630417e-322};
    Double_t Graph1_fehy3002[27] = {
        3156.946,
        1210.583,
        474.9559,
        174.0884,
        91.4498,
        50.07965,
        30.89681,
        22.97007,
        17.60423,
        13.85798,
        11.7815,
        9.542587,
        8.27627,
        7.071613,
        6.756716,
        5.848272,
        5.491023,
        5.148722,
        4.722215,
        4.678369,
        4.364094,
        4.307418,
        4.071867,
        3.835196,
        3.887513,
        3.630911,
        3.570622};
    grae = new TGraphAsymmErrors(27,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
    grae->SetName("");
    grae->SetTitle("");
    
    ci = TColor::GetColor("#00ff00");
    grae->SetFillColor(ci);
    grae->SetMarkerStyle(20);
    
    TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,70,1630);
    Graph_Graph3002->SetMinimum(0);
    Graph_Graph3002->SetMaximum(7.043383);
    Graph_Graph3002->SetDirectory(0);
    Graph_Graph3002->SetStats(0);
    Graph_Graph3002->SetLineStyle(0);
    Graph_Graph3002->SetMarkerStyle(20);
    Graph_Graph3002->GetXaxis()->SetNdivisions(506);
    Graph_Graph3002->GetXaxis()->SetLabelFont(42);
    Graph_Graph3002->GetXaxis()->SetTitleSize(0.05);
    Graph_Graph3002->GetXaxis()->SetTickLength(0.02);
    Graph_Graph3002->GetXaxis()->SetTitleOffset(1.08);
    Graph_Graph3002->GetXaxis()->SetTitleFont(42);
    Graph_Graph3002->GetYaxis()->SetNdivisions(506);
    Graph_Graph3002->GetYaxis()->SetLabelFont(42);
    Graph_Graph3002->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph3002->GetYaxis()->SetTitleSize(0.05);
    Graph_Graph3002->GetYaxis()->SetTickLength(0.02);
    Graph_Graph3002->GetYaxis()->SetTitleOffset(1.08);
    Graph_Graph3002->GetYaxis()->SetTitleFont(42);
    Graph_Graph3002->GetZaxis()->SetNdivisions(506);
    Graph_Graph3002->GetZaxis()->SetLabelFont(42);
    Graph_Graph3002->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph3002->GetZaxis()->SetTitleSize(0.05);
    Graph_Graph3002->GetZaxis()->SetTickLength(0.02);
    Graph_Graph3002->GetZaxis()->SetTitleFont(42);
    grae->SetHistogram(Graph_Graph3002);
    
    grae->Draw("3");
    Double_t Graph2_fx1[27] = {
        200,
        250,
        300,
        350,
        400,
        450,
        500,
        550,
        600,
        650,
        700,
        750,
        800,
        850,
        900,
        950,
        1000,
        1050,
        1100,
        1150,
        1200,
        1250,
        1300,
        1350,
        1400,
        1450,
        1500};
    Double_t Graph2_fy1[27] = {
        4000,
        2283.5,
        984.75,
        386.5,
        199.5,
        109.25,
        66.25,
        47.625,
        35.90625,
        27.375,
        22.5625,
        18,
        14.9375,
        12.40625,
        11.53125,
        9.78125,
        8.71875,
        7.78125,
        6.96875,
        6.59375,
        6.015625,
        5.6875,
        5.265625,
        4.859375,
        4.828125,
        4.421875,
        4.265625};

    TGraph *graph = new TGraph(27,Graph2_fx1,Graph2_fy1);
    graph->SetName("Graph0");
    graph->SetTitle("Graph");
    graph->SetFillColor(1);
    
    ci = TColor::GetColor("#ff0000");
    graph->SetLineColor(ci);
    graph->SetLineWidth(3);
    
    TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,70,1630);
    Graph_Graph1->SetMinimum(0);
    Graph_Graph1->SetMaximum(4.829346);
    Graph_Graph1->SetDirectory(0);
    Graph_Graph1->SetStats(0);
    Graph_Graph1->SetLineStyle(0);
    Graph_Graph1->SetMarkerStyle(20);
    Graph_Graph1->GetXaxis()->SetNdivisions(506);
    Graph_Graph1->GetXaxis()->SetLabelFont(42);
    Graph_Graph1->GetXaxis()->SetTitleSize(0.05);
    Graph_Graph1->GetXaxis()->SetTickLength(0.02);
    Graph_Graph1->GetXaxis()->SetTitleOffset(1.08);
    Graph_Graph1->GetXaxis()->SetTitleFont(42);
    Graph_Graph1->GetYaxis()->SetNdivisions(506);
    Graph_Graph1->GetYaxis()->SetLabelFont(42);
    Graph_Graph1->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph1->GetYaxis()->SetTitleSize(0.05);
    Graph_Graph1->GetYaxis()->SetTickLength(0.02);
    Graph_Graph1->GetYaxis()->SetTitleOffset(1.08);
    Graph_Graph1->GetYaxis()->SetTitleFont(42);
    Graph_Graph1->GetZaxis()->SetNdivisions(506);
    Graph_Graph1->GetZaxis()->SetLabelFont(42);
    Graph_Graph1->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph1->GetZaxis()->SetTitleSize(0.05);
    Graph_Graph1->GetZaxis()->SetTickLength(0.02);
    Graph_Graph1->GetZaxis()->SetTitleFont(42);
    graph->SetHistogram(Graph_Graph1);
    
    graph->Draw("l");
    Double_t Graph3_fx2[27] = {
        200,
        250,
        300,
        350,
        400,
        450,
        500,
        550,
        600,
        650,
        700,
        750,
        800,
        850,
        900,
        950,
        1000,
        1050,
        1100,
        1150,
        1200,
        1250,
        1300,
        1350,
        1400,
        1450,
        1500};
    Double_t Graph3_fy2[27] = {
        4800.226,
        2285.424,
        983.5759,
        386.0807,
        199.7247,
        109.0601,
        66.10181,
        47.61486,
        35.85314,
        27.33548,
        22.55836,
        18.01876,
        14.98129,
        12.4202,
        11.54183,
        9.766936,
        8.718939,
        7.8106,
        6.984066,
        6.625801,
        6.007968,
        5.6849,
        5.260232,
        4.870766,
        4.830231,
        4.425818,
        4.260048};
    graph = new TGraph(27,Graph3_fx2,Graph3_fy2);
    graph->SetName("Graph1");
    graph->SetTitle("Graph");
    graph->SetFillColor(1);
    graph->SetLineWidth(3);
    graph->SetMarkerStyle(20);
    
    TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,70,1630);
    Graph_Graph2->SetMinimum(0);
    Graph_Graph2->SetMaximum(4.719012);
    Graph_Graph2->SetDirectory(0);
    Graph_Graph2->SetStats(0);
    Graph_Graph2->SetLineStyle(0);
    Graph_Graph2->SetMarkerStyle(20);
    Graph_Graph2->GetXaxis()->SetNdivisions(506);
    Graph_Graph2->GetXaxis()->SetLabelFont(42);
    Graph_Graph2->GetXaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetXaxis()->SetTickLength(0.02);
    Graph_Graph2->GetXaxis()->SetTitleOffset(1.08);
    Graph_Graph2->GetXaxis()->SetTitleFont(42);
    Graph_Graph2->GetYaxis()->SetNdivisions(506);
    Graph_Graph2->GetYaxis()->SetLabelFont(42);
    Graph_Graph2->GetYaxis()->SetLabelOffset(0.007);
    Graph_Graph2->GetYaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetYaxis()->SetTickLength(0.02);
    Graph_Graph2->GetYaxis()->SetTitleOffset(1.08);
    Graph_Graph2->GetYaxis()->SetTitleFont(42);
    Graph_Graph2->GetZaxis()->SetNdivisions(506);
    Graph_Graph2->GetZaxis()->SetLabelFont(42);
    Graph_Graph2->GetZaxis()->SetLabelOffset(0.007);
    Graph_Graph2->GetZaxis()->SetTitleSize(0.05);
    Graph_Graph2->GetZaxis()->SetTickLength(0.02);
    Graph_Graph2->GetZaxis()->SetTitleFont(42);
    graph->SetHistogram(Graph_Graph2);
    
    graph->Draw("pl");
    
    
    
    
    const int nTH=122;
    
    Double_t mTh[nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0,1500};
    
    
//    Double_t x_pdf[2*nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0,1500,1500,1400.0,1390.0,1380.0,1370.0,1360.0,1350.0,1340.0,1330.0,1320.0,1310.0,1300.0,1290.0,1280.0,1270.0,1260.0,1250.0,1240.0,1230.0,1220.0,1210.0,1200.0,1190.0,1180.0,1170.0,1160.0,1150.0,1140.0,1130.0,1120.0,1110.0,1100.0,1090.0,1080.0,1070.0,1060.0,1050.0,1040.0,1030.0,1020.0,1010.0,1000.0,990.0,980.0,970.0,960.0,950.0,940.0,930.0,920.0,910.0,900.0,890.0,880.0,870.0,860.0,850.0,840.0,830.0,820.0,810.0,800.0,790.0,780.0,770.0,760.0,750.0,740.0,730.0,720.0,710.0,700.0,690.0,680.0,670.0,660.0,650.0,640.0,630.0,620.0,610.0,600.0,590.0,580.0,570.0,560.0,550.0,540.0,530.0,520.0,510.0,500.0,490.0,480.0,470.0,460.0,450.0,440.0,430.0,420.0,410.0,400.0,390.0,380.0,370.0,360.0,350.0,340.0,330.0,320.0,310.0,300.0,290.0,280.0,270.0,260.0,250.0,240.0,230.0,220.0,210.0,200.0};
    
    //for beta=1
    
    Double_t xsTh[nTH] = {6.06E+01,4.79E+01,3.82E+01,3.07E+01,2.49E+01,2.03E+01,1.67E+01,1.38E+01,1.15E+01,9.60E+00,8.04E+00,6.80E+00,5.75E+00,4.90E+00,4.18E+00,3.59E+00,3.09E+00,2.66E+00,2.31E+00,2.00E+00,1.74E+00,1.52E+00,1.33E+00,1.17E+00,1.03E+00,9.06E-01,8.00E-01,7.07E-01,6.27E-01,5.58E-01,4.96E-01,4.43E-01,3.95E-01,3.54E-01,3.16E-01,2.84E-01,2.55E-01,2.29E-01,2.07E-01,1.87E-01,1.69E-01,1.53E-01,1.38E-01,1.25E-01,1.14E-01,1.03E-01,9.39E-02,8.54E-02,7.78E-02,7.10E-02,6.48E-02,5.92E-02,5.42E-02,4.97E-02,4.55E-02,4.16E-02,3.82E-02,3.51E-02,3.22E-02,2.97E-02,2.73E-02,2.51E-02,2.31E-02,2.13E-02,1.97E-02,1.82E-02,1.68E-02,1.55E-02,1.44E-02,1.33E-02,1.23E-02,1.14E-02,1.06E-02,9.79E-03,9.09E-03,8.45E-03,7.84E-03,7.28E-03,6.77E-03,6.30E-03,5.86E-03,5.45E-03,5.08E-03,4.73E-03,4.41E-03,4.11E-03,3.83E-03,3.58E-03,3.34E-03,3.12E-03,2.91E-03,2.72E-03,2.54E-03,2.38E-03,2.22E-03,2.08E-03,1.95E-03,1.82E-03,1.71E-03,1.60E-03,1.50E-03,1.41E-03,1.32E-03,1.24E-03,1.16E-03,1.09E-03,1.02E-03,9.59E-04,9.01E-04,8.46E-04,7.95E-04,7.48E-04,7.03E-04,6.61E-04,6.22E-04,5.85E-04,5.50E-04,5.18E-04,4.87E-04,4.59E-04,4.33E-04,2.40E-04};
    
    Double_t newXS[nTH]={0};
    
    for (int i=0; i < nTH; i++)
        newXS[i]=xsTh[i]*1000.;
    
    //,4.07E-04,3.84E-04,3.61E-04,3.41E-04,3.21E-04,3.03E-04,2.85E-04,2.69E-04,2.54E-04,2.40E-04,2.26E-04,2.13E-04,2.02E-04,1.90E-04,1.80E-04,1.70E-04,1.60E-04,1.51E-04,1.43E-04,1.35E-04,1.28E-04,1.21E-04,1.14E-04,1.08E-04,1.02E-04,9.66E-05,9.13E-05,8.64E-05,8.18E-05,7.74E-05,7.32E-05,6.93E-05,6.56E-05,6.21E-05,5.88E-05,5.57E-05,5.27E-05,5.00E-05,4.73E-05,4.48E-05,4.25E-05,4.02E-05,3.81E-05,3.61E-05,3.43E-05,3.25E-05,3.08E-05,2.92E-05,2.77E-05,2.62E-05,2.49E-05,2.36E-05,2.24E-05,2.12E-05,2.01E-05,1.91E-05,1.81E-05,1.72E-05,1.63E-05,1.55E-05,1.47E-05,1.39E-05,1.32E-05,1.26E-05,1.19E-05,1.13E-05,1.07E-05,1.02E-05,9.68E-06,9.20E-06,8.73E-06,8.29E-06,7.87E-06,7.47E-06,7.10E-06,6.74E-06,6.41E-06,6.08E-06,5.78E-06,5.49E-06,5.22E-06,4.96E-06,4.71E-06,4.47E-06,4.26E-06,4.04E-06,3.84E-06,3.65E-06,3.46E-06,3.30E-06,3.13E-06,2.97E-06,2.83E-06,2.69E-06,2.55E-06,2.43E-06,2.31E-06,2.19E-06,2.08E-06,1.98E-06,1.88E-06,1.79E-06,1.70E-06,1.62E-06,1.54E-06,1.46E-06,1.39E-06,1.32E-06,1.25E-06,1.19E-06,1.13E-06,1.08E-06,1.03E-06,9.74E-07,9.27E-07,8.81E-07,8.37E-07,7.96E-07,7.57E-07,7.20E-07,6.84E-07,6.50E-07,6.19E-07,5.88E-07,5.60E-07,5.32E-07,5.05E-07,4.80E-07,4.57E-07,4.35E-07,4.13E-07,3.92E-07,3.73E-07,3.55E-07,3.38E-07,3.21E-07,3.05E-07,2.90E-07,2.75E-07,2.62E-07,2.49E-07,2.36E-07,2.25E-07,2.14E-07,2.03E-07,1.93E-07,1.83E-07,1.74E-07,1.66E-07,1.58E-07,1.50E-07,1.42E-07,1.35E-07,1.28E-07,1.22E-07,1.16E-07,1.10E-07,1.05E-07,9.95E-08,9.46E-08}
    
    
    //for beta=1
    
//    Double_t y_pdf[2*nTH] = {63.1,49.97,39.99,32.2,26.17,21.39,17.632,14.61,12.204,10.216,8.575,7.273,6.168,5.268,4.504,3.875,3.345,2.888,2.512,2.182,1.901,1.665,1.461,1.287,1.136,1.0012,0.886,0.7851,0.6978,0.6223,0.5538,0.4959,0.4433,0.3979,0.3562,0.3209,0.2885,0.2597,0.2352,0.2129,0.1927,0.1748,0.158,0.1435,0.131,0.1187,0.1083,0.0988,0.0902,0.0824,0.0754,0.06898,0.06324,0.0581,0.05326,0.04887,0.04491,0.04134,0.038,0.0351,0.03233,0.02978,0.02747,0.02538,0.02351,0.02175,0.02011,0.0186,0.0173,0.01602,0.01483,0.01377,0.01282,0.01187,0.01105,0.01028,0.00955,0.00889,0.00828,0.00772,0.00719,0.0067,0.00626,0.00584,0.00545,0.005092,0.004751,0.004447,0.004157,0.003889,0.003635,0.003404,0.003185,0.002988,0.002794,0.002621,0.002461,0.002303,0.002166,0.002031,0.001907,0.001795,0.001684,0.001584,0.001485,0.001399,0.001312,0.001235,0.001162,0.001093,0.001029,0.00097,0.000913,0.00086,0.000811,0.000764,0.00072,0.000679,0.00064,0.000604,0.000571,  0.000322, 0.000158 ,0.000295,0.000314,0.000334,0.000357,0.00038,0.000406,0.000433,0.000462,0.000493,0.000526,0.000561,0.000599,0.00064,0.000683,0.000728,0.000781,0.000835,0.000896,0.000956,0.001025,0.001093,0.001169,0.001254,0.001337,0.001439,0.001539,0.001646,0.001772,0.001895,0.002036,0.002185,0.002351,0.002523,0.002713,0.002909,0.003128,0.00337,0.00362,0.0039,0.0042,0.00453,0.00488,0.00526,0.00567,0.00613,0.00662,0.00713,0.00771,0.00838,0.00903,0.00977,0.01058,0.0115,0.0124,0.01349,0.01465,0.01589,0.01722,0.01873,0.02042,0.02227,0.0243,0.0264,0.02886,0.03149,0.03433,0.03774,0.0413,0.04516,0.04942,0.0542,0.0596,0.0654,0.072,0.0795,0.0873,0.097,0.1065,0.118,0.1312,0.1453,0.1611,0.1788,0.1983,0.2215,0.2471,0.2758,0.3101,0.3467,0.3901,0.4382,0.4937,0.5562,0.6289,0.714,0.8108,0.924,1.053,1.199,1.375,1.579,1.818,2.108,2.432,2.835,3.305,3.856,4.532,5.332,6.327,7.505,8.984,10.796,12.99,15.768,19.21,23.63,29.2,36.41,45.83,58.1};
    
    
    TGraph *xsTh_vs_m = new TGraph(nTH, mTh, newXS);
    
    xsTh_vs_m->SetLineWidth(3);
    
    xsTh_vs_m->SetLineStyle(2);
    
    xsTh_vs_m->SetLineColor(kBlue);
    
    xsTh_vs_m->SetFillColor(kCyan-6);
    
    xsTh_vs_m->SetMarkerSize(0.00001);
    
    xsTh_vs_m->SetMarkerStyle(22);
    
    xsTh_vs_m->SetMarkerColor(kBlue);
    
    
//    TGraph *grshade = new TGraph(2*nTH,x_pdf,y_pdf);
//    
//    grshade->SetFillColor(kCyan-5);
//    
//    grshade->SetFillStyle(3008);
    
    
    xsTh_vs_m->Draw("L");
    
//    grshade->Draw("f");
    
    
    
    
    
    
    
    
    //    tex = new TLatex(0.1578,0.9113,"");
    //    tex->SetNDC();
    //    tex->SetTextAlign(13);
    //    tex->SetTextSize(0.048);
    //    tex->SetLineWidth(2);
    //    tex->Draw();
    //    tex = new TLatex(0.2,0.88,"CMS  ");
    //    tex->SetNDC();
    //    tex->SetTextAlign(12);
    //    tex->SetTextFont(61);
    //    tex->SetTextSize(0.06);
    //    tex->SetLineWidth(2);
    //    tex->Draw();
    //    tex = new TLatex(0.2,0.8," Preliminary ");
    //    tex->SetNDC();
    //    tex->SetTextAlign(12);
    //    tex->SetTextFont(52);
    //    tex->SetTextSize(0.055);
    //    tex->SetLineWidth(2);
    ////    tex->Draw();
    //
    //    tex = new TLatex(0.96,0.952,"12.9 fb^{-1} (13 TeV)");
    //    tex->SetNDC();
    //    tex->SetTextAlign(31);
    //    tex->SetTextFont(42);
    //    tex->SetTextSize(0.056);
    //    tex->SetLineWidth(2);
    //    tex->Draw();
    
    
    float lowX=0.65;
    float lowY=0.85;
    TPaveText * lumi  = new TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC");
    lumi->SetBorderSize(   0 );
    lumi->SetFillStyle(    0 );
    lumi->SetTextAlign(   12 );
    lumi->SetTextColor(    1 );
    lumi->SetTextSize(0.04);
    lumi->SetTextFont (   42 );
    lumi->AddText("12.9 fb^{-1} (13 TeV)");
    lumi->Draw();
    
    lowX=0.15;
    lowY=0.75;
    TPaveText * lumi1  = new TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC");
    lumi1->SetTextFont(61);
    lumi1->SetTextSize(0.05);
    lumi1->SetBorderSize(   0 );
    lumi1->SetFillStyle(    0 );
    lumi1->SetTextAlign(   12 );
    lumi1->SetTextColor(    1 );
    lumi1->AddText("CMS");
    lumi1->Draw();
    
    
    
    TH1F *hist1d__2 = new TH1F("hist1d__2","",27,200,1525);
    hist1d__2->SetMinimum(0.0001);
    hist1d__2->SetMaximum(1000000);
    hist1d__2->SetDirectory(0);
    hist1d__2->SetLineStyle(0);
    hist1d__2->SetMarkerStyle(20);
    hist1d__2->GetXaxis()->SetTitle("m_{LQ} [GeV]");
    hist1d__2->GetXaxis()->SetMoreLogLabels();
    hist1d__2->GetXaxis()->SetNoExponent();
    hist1d__2->GetXaxis()->SetNdivisions(50005);
    hist1d__2->GetXaxis()->SetLabelFont(42);
    hist1d__2->GetXaxis()->SetTitleSize(0.05);
    hist1d__2->GetXaxis()->SetTickLength(0.02);
    hist1d__2->GetXaxis()->SetTitleOffset(1.08);
    hist1d__2->GetXaxis()->SetTitleFont(42);
    hist1d__2->GetYaxis()->SetTitle("#sigma#font[42]{}#upoint#font[52]{B}^{2} [pb]");
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
    c1->SaveAs("limit_1D_LQ.pdf");
}
