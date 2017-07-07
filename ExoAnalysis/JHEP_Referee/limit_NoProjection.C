void limit()
{
//=========Macro generated from canvas: limit/limit
//=========  (Fri Apr 28 13:46:20 2017) by ROOT version6.02/05
   TCanvas *limit = new TCanvas("limit", "limit",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   limit->SetHighLightColor(2);
   limit->Range(0,0,1,1);
   limit->SetFillColor(0);
   limit->SetBorderMode(0);
   limit->SetBorderSize(2);
   limit->SetLeftMargin(0.16);
   limit->SetRightMargin(0.04);
   limit->SetTopMargin(0.06);
   limit->SetBottomMargin(0.12);
   limit->SetFrameFillStyle(0);
   limit->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad
   TPad *pad = new TPad("pad", "pad",0,0,1,1);
   pad->Draw();
   pad->cd();
   pad->Range(-59.99999,-2014.654,1565,14774.13);
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
   
   TH1F *tmp01 = new TH1F("tmp01","Graph",100,200,1500);
   tmp01->SetMinimum(0);
   tmp01->SetMaximum(13766.8);
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
   
   TH1F *tmp02 = new TH1F("tmp02","Graph",100,200,1500);
   tmp02->SetMinimum(0);
   tmp02->SetMaximum(13766.8);
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
   -nan,
   3.270357e-316,
   3.270357e-316,
   -nan,
   6.952719e-310,
   -nan,
   0,
   6.952719e-310,
   6.952719e-310,
   -nan,
   -nan,
   -nan,
   -nan,
   -nan,
   3.270367e-316,
   3.270357e-316,
   6.952719e-310,
   6.952719e-310,
   -nan,
   -nan,
   -nan,
   -nan,
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
   grae->SetName("Graph0");
   grae->SetTitle("Graph");

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#ffff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3001 = new TH1F("Graph_Graph3001","Graph",100,70,1630);
   Graph_Graph3001->SetMinimum(0);
   Graph_Graph3001->SetMaximum(11357.45);
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
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,-8.010917e+160,2.406781e+161);
   Graph_Graph3002->SetMinimum(0);
   Graph_Graph3002->SetMaximum(7872.389);
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
   graph->SetName("Graph2");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,70,1630);
   Graph_Graph1->SetMinimum(0);
   Graph_Graph1->SetMaximum(4399.573);
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
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,70,1630);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(5279.823);
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
   
   TH1F *tmp0_copy3 = new TH1F("tmp0_copy3","Graph",100,200,1500);
   tmp0_copy3->SetMinimum(0);
   tmp0_copy3->SetMaximum(11357.45);
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
   
   TH1F *tmp0_copy4 = new TH1F("tmp0_copy4","Graph",100,200,1500);
   tmp0_copy4->SetMinimum(0);
   tmp0_copy4->SetMaximum(11357.45);
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
      tex = new TLatex(0.196,0.8537,"Internal");
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
   limit->cd();
   limit->Modified();
   limit->cd();
   limit->SetSelected(limit);
}
