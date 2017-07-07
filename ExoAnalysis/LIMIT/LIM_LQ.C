void LIM_LQ()
{
//=========Macro generated from canvas: c1/c1
//=========  (Wed Aug  3 12:08:53 2016) by ROOT version6.04/14
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
   
   TLegend *leg = new TLegend(0.53,0.21,0.93,0.91,NULL,"NBNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(62);
   leg->SetTextSize(0.15);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("Graph","Observed","L");
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
   entry=leg->AddEntry("Graph","Expected","L");

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
   TPad *pad_plot = new TPad("pad_plot", "pad_plot",0,0,1,1);
   pad_plot->Draw();
   pad_plot->cd();
   pad_plot->Range(10.71429,-0.1536585,1588.095,1.126829);
   pad_plot->SetFillColor(0);
   pad_plot->SetFillStyle(4000);
   pad_plot->SetBorderMode(0);
   pad_plot->SetBorderSize(2);
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
   hist1d__1->SetDirectory(0);
   
   TPaveStats *ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
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
   AText = ptstats->AddText("Underflow =      0");
   AText = ptstats->AddText("Overflow  =      0");
   AText = ptstats->AddText("Integral =      0");
   ptstats->SetOptStat(1111111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hist1d__1->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hist1d__1);
   hist1d__1->SetLineStyle(0);
   hist1d__1->SetMarkerStyle(20);
   hist1d__1->GetXaxis()->SetTitle("m_{#phi} [GeV]");
   hist1d__1->GetXaxis()->SetNdivisions(506);
   hist1d__1->GetXaxis()->SetLabelFont(42);
   hist1d__1->GetXaxis()->SetTitleSize(0.05);
   hist1d__1->GetXaxis()->SetTickLength(0.02);
   hist1d__1->GetXaxis()->SetTitleOffset(1.08);
   hist1d__1->GetXaxis()->SetTitleFont(42);
   hist1d__1->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{(gg#phi)}#upoint#font[52]{B}#font[42]{(#phi#rightarrow#tau#tau)} [pb]");
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
   
   Double_t _fx3001[27] = {
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
   Double_t _fy3001[27] = {
   2.255341,
   1.015549,
   0.3367424,
   0.1820087,
   0.09483624,
   0.05252266,
   0.03143692,
   0.02274704,
   0.01712418,
   0.01284027,
   0.01032257,
   0.008308411,
   0.007003784,
   0.005264282,
   0.004806519,
   0.00440979,
   0.003662109,
   0.003570557,
   0.0027771,
   0.002349854,
   0.002349854,
   0.001922607,
   0.001922607,
   0.001922607,
   0.001922607,
   0.001281738,
   0.001281738};
   Double_t _felx3001[27] = {
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
   0,
   0,
   0};
   Double_t _fely3001[27] = {
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
   0,
   0,
   0};
   Double_t _fehx3001[27] = {
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
   0,
   0,
   0};
   Double_t _fehy3001[27] = {
   6.78056,
   3.109,
   0.8670255,
   0.4707839,
   0.2428476,
   0.1383214,
   0.08562975,
   0.06297199,
   0.04836455,
   0.03750722,
   0.03168649,
   0.02550376,
   0.02166246,
   0.01874104,
   0.01761207,
   0.01450373,
   0.01357369,
   0.01227801,
   0.01178107,
   0.01173487,
   0.01053594,
   0.01033696,
   0.009426089,
   0.008497699,
   0.008375082,
   0.00821261,
   0.00821261};
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(27,_fx3001,_fy3001,_felx3001,_fehx3001,_fely3001,_fehy3001);
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
   
   Double_t _fx3002[27] = {
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
   Double_t _fy3002[27] = {
   3.056072,
   1.385603,
   0.4489723,
   0.2426688,
   0.1259504,
   0.06998728,
   0.04261726,
   0.03083688,
   0.02345788,
   0.01698661,
   0.01426196,
   0.01172304,
   0.008934975,
   0.007874489,
   0.007189751,
   0.005868912,
   0.0050354,
   0.004611969,
   0.004116058,
   0.003482819,
   0.003482819,
   0.002849579,
   0.002849579,
   0.002849579,
   0.002849579,
   0.002082825,
   0.002082825};
   Double_t _felx3002[27] = {
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
   0,
   0,
   0};
   Double_t _fely3002[27] = {
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
   0,
   0,
   0};
   Double_t _fehx3002[27] = {
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
   0,
   0,
   0};
   Double_t _fehy3002[27] = {
   3.347193,
   1.519793,
   0.4353842,
   0.2353245,
   0.1213113,
   0.06923412,
   0.04185974,
   0.03098164,
   0.02360126,
   0.01863601,
   0.01565261,
   0.01235454,
   0.01139547,
   0.008727796,
   0.007968857,
   0.007461134,
   0.006492848,
   0.006188844,
   0.005065425,
   0.005656331,
   0.00497123,
   0.004627907,
   0.00406737,
   0.003787102,
   0.003506833,
   0.003515011,
   0.003515011};
   grae = new TGraphAsymmErrors(27,_fx3002,_fy3002,_felx3002,_fehx3002,_fely3002,_fehy3002);
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
   
   Double_t Graph0_fx1[27] = {
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
   Double_t Graph0_fy1[27] = {
   4.390625,
   1.992188,
   0.6269531,
   0.3388672,
   0.175293,
   0.09814453,
   0.06005859,
   0.04345703,
   0.03271484,
   0.02490234,
   0.02001953,
   0.01611328,
   0.01318359,
   0.01123047,
   0.01025391,
   0.008300781,
   0.007324219,
   0.006347656,
   0.006347656,
   0.005371094,
   0.005371094,
   0.004394531,
   0.004394531,
   0.004394531,
   0.004394531,
   0.003417969,
   0.003417969};
   TGraph *graph = new TGraph(27,Graph0_fx1,Graph0_fy1);
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
   
   Double_t Graph1_fx2[27] = {
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
   Double_t Graph1_fy2[27] = {
   4.290325,
   1.529551,
   0.7555034,
   0.4360767,
   0.217999,
   0.1353539,
   0.08324244,
   0.05594456,
   0.04043446,
   0.03101383,
   0.02521476,
   0.0196628,
   0.0164327,
   0.0139788,
   0.01262523,
   0.01021711,
   0.008648229,
   0.007460774,
   0.006675119,
   0.005865333,
   0.005098765,
   0.004850521,
   0.004428081,
   0.003886634,
   0.00387614,
   0.003507627,
   0.003459288};
   graph = new TGraph(27,Graph1_fx2,Graph1_fy2);
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
      tex = new TLatex(0.1578,0.9113,"");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.952,"19.8 fb^{-1} (8 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *hist1d__2 = new TH1F("hist1d__2","",27,200,1525);
   hist1d__2->SetDirectory(0);
   
   ptstats = new TPaveStats(0.78,0.655,0.98,0.935,"brNDC");
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
   AText = ptstats->AddText("Underflow =      0");
   AText = ptstats->AddText("Overflow  =      0");
   AText = ptstats->AddText("Integral =      0");
   ptstats->SetOptStat(1111111);
   ptstats->SetOptFit(0);
   ptstats->Draw();
   hist1d__2->GetListOfFunctions()->Add(ptstats);
   ptstats->SetParent(hist1d__2);
   hist1d__2->SetLineStyle(0);
   hist1d__2->SetMarkerStyle(20);
   hist1d__2->GetXaxis()->SetTitle("m_{#phi} [GeV]");
   hist1d__2->GetXaxis()->SetNdivisions(506);
   hist1d__2->GetXaxis()->SetLabelFont(42);
   hist1d__2->GetXaxis()->SetTitleSize(0.05);
   hist1d__2->GetXaxis()->SetTickLength(0.02);
   hist1d__2->GetXaxis()->SetTitleOffset(1.08);
   hist1d__2->GetXaxis()->SetTitleFont(42);
   hist1d__2->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{(gg#phi)}#upoint#font[52]{B}#font[42]{(#phi#rightarrow#tau#tau)} [pb]");
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
