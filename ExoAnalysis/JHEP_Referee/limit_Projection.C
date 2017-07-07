void limit()
{
//=========Macro generated from canvas: limit/limit
//=========  (Fri Apr 28 13:46:39 2017) by ROOT version6.02/05
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
   pad->Range(-59.99999,-1221.574,1565,8958.209);
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
   tmp01->SetMaximum(8347.422);
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
   tmp02->SetMaximum(8347.422);
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
   2999,
   1460.75,
   706.625,
   284.625,
   142.25,
   74.25,
   43.625,
   30.625,
   22.8125,
   17.1875,
   13.8125,
   10.90625,
   8.90625,
   7.3125,
   6.78125,
   5.640625,
   4.953125,
   4.375,
   3.859375,
   3.609375,
   3.234375,
   3.039062,
   2.789062,
   2.554688,
   2.523438,
   2.304688,
   2.210938};
   Double_t Graph0_felx3001[27] = {
   3.808841e-316,
   0,
   0,
   0,
   6.928136e-310,
   3.884205e-316,
   2.121996e-314,
   3.885643e-316,
   0,
   3.885648e-316,
   3.884205e-316,
   0,
   3.885645e-316,
   1.36031e-316,
   1.360511e-316,
   3.88565e-316,
   2.124327e-314,
   3.885654e-316,
   5.582942e-322,
   6.928136e-310,
   0,
   3.884206e-316,
   3.885644e-316,
   3.885648e-316,
   1.58101e-322,
   3.885516e-316,
   5.582942e-322};
   Double_t Graph0_fely3001[27] = {
   1446.783,
   736.0811,
   340.8914,
   132.8621,
   66.40186,
   34.65967,
   20.70483,
   14.59473,
   11.00525,
   8.425903,
   6.825317,
   5.389221,
   4.47052,
   3.699097,
   3.483337,
   2.963531,
   2.621674,
   2.366943,
   2.103058,
   2.009125,
   1.800385,
   1.72728,
   1.596085,
   1.471939,
   1.463791,
   1.345901,
   1.291153};
   Double_t Graph0_fehx3001[27] = {
   3.884156e-316,
   3.853103e-316,
   0,
   1.630417e-322,
   1.630417e-322,
   0,
   1.038253e-312,
   0,
   0,
   1.038253e-312,
   1.038253e-312,
   0,
   0,
   0,
   0,
   0,
   1.630417e-322,
   1.630417e-322,
   1.038253e-312,
   1.038253e-312,
   0,
   3.888087e-316,
   3.891822e-316,
   1.58101e-322,
   1.58101e-322,
   1.630417e-322,
   1.630417e-322};
   Double_t Graph0_fehy3001[27] = {
   3261.566,
   1787.747,
   756.3442,
   277.5471,
   141.2464,
   73.72617,
   45.17841,
   32.40121,
   24.75471,
   19.19595,
   16.22575,
   12.99174,
   11.11241,
   9.443363,
   9.142384,
   8.076417,
   7.349932,
   6.831431,
   6.259697,
   6.160611,
   5.739717,
   5.658485,
   5.372968,
   5.082478,
   5.12435,
   4.68042,
   4.490031};
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
   Graph_Graph3001->SetMaximum(6886.531);
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
   2999,
   1460.75,
   706.625,
   284.625,
   142.25,
   74.25,
   43.625,
   30.625,
   22.8125,
   17.1875,
   13.8125,
   10.90625,
   8.90625,
   7.3125,
   6.78125,
   5.640625,
   4.953125,
   4.375,
   3.859375,
   3.609375,
   3.234375,
   3.039062,
   2.789062,
   2.554688,
   2.523438,
   2.304688,
   2.210938};
   Double_t Graph1_felx3002[27] = {
   3.880936e-316,
   2.121996e-314,
   3.874284e-316,
   0,
   2.420922e-322,
   3.880893e-316,
   0,
   2.11372e-314,
   0,
   4.940656e-323,
   8.744962e-322,
   0,
   0,
   4.940656e-323,
   0,
   6.928137e-310,
   5.33769e+160,
   0,
   3.874024e-316,
   6.928137e-310,
   0,
   2.121996e-314,
   3.880299e-316,
   0,
   1.58101e-322,
   3.872427e-316,
   1.630417e-322};
   Double_t Graph1_fely3002[27] = {
   898.5879,
   462.926,
   211.7255,
   81.48181,
   40.72301,
   21.5269,
   12.85964,
   9.064693,
   6.835291,
   5.299103,
   4.292484,
   3.389315,
   2.811538,
   2.355284,
   2.217906,
   1.910089,
   1.689751,
   1.525569,
   1.355486,
   1.31064,
   1.174469,
   1.133527,
   1.053665,
   0.9717097,
   0.9663308,
   0.8885052,
   0.8523626};
   Double_t Graph1_fehx3002[27] = {
   1.038253e-312,
   2.121996e-314,
   3.874284e-316,
   0,
   2.420922e-322,
   3.880926e-316,
   0,
   2.113722e-314,
   0,
   4.940656e-323,
   8.744962e-322,
   0,
   0,
   4.940656e-323,
   0,
   6.928137e-310,
   2.139459e+161,
   0,
   3.874024e-316,
   6.928137e-310,
   0,
   2.121996e-314,
   3.880299e-316,
   0,
   1.58101e-322,
   3.872472e-316,
   1.630417e-322};
   Double_t Graph1_fehy3002[27] = {
   1398.635,
   751.1169,
   323.9133,
   121.3944,
   61.8046,
   32.26004,
   19.30191,
   14.03835,
   10.54807,
   8.152702,
   6.772038,
   5.434097,
   4.57959,
   3.876676,
   3.649097,
   3.215179,
   2.902275,
   2.685596,
   2.430614,
   2.388262,
   2.191701,
   2.107807,
   1.978883,
   1.853323,
   1.870887,
   1.745451,
   1.674449};
   grae = new TGraphAsymmErrors(27,Graph1_fx3002,Graph1_fy3002,Graph1_felx3002,Graph1_fehx3002,Graph1_fely3002,Graph1_fehy3002);
   grae->SetName("Graph1");
   grae->SetTitle("Graph");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   
   TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","Graph",100,-8.010917e+160,2.406781e+161);
   Graph_Graph3002->SetMinimum(0);
   Graph_Graph3002->SetMaximum(4837.262);
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
   2999,
   1460.75,
   706.625,
   284.625,
   142.25,
   74.25,
   43.625,
   30.625,
   22.8125,
   17.1875,
   13.8125,
   10.90625,
   8.90625,
   7.3125,
   6.78125,
   5.640625,
   4.953125,
   4.375,
   3.859375,
   3.609375,
   3.234375,
   3.039062,
   2.789062,
   2.554688,
   2.523438,
   2.304688,
   2.210938};
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
   Graph_Graph1->SetMaximum(3298.679);
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
   2995.963,
   1462.856,
   706.0056,
   284.2198,
   142.4488,
   74.17205,
   43.58878,
   30.72685,
   22.82964,
   17.15747,
   13.76272,
   10.88782,
   8.909028,
   7.321482,
   6.764183,
   5.637997,
   4.958678,
   4.377788,
   3.869307,
   3.607253,
   3.251664,
   3.04292,
   2.780702,
   2.558312,
   2.528807,
   2.300875,
   2.208464};
   graph = new TGraph(27,Graph3_fx2,Graph3_fy2);
   graph->SetName("Graph3");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(2);
   graph->SetMarkerStyle(20);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","Graph",100,70,1630);
   Graph_Graph2->SetMinimum(0);
   Graph_Graph2->SetMaximum(3295.339);
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
   tmp0_copy3->SetMaximum(6886.531);
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
   tmp0_copy4->SetMaximum(6886.531);
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
