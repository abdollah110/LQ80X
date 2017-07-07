{
//=========Macro generated from canvas: c1/c1
//=========  (Mon May 23 13:39:03 2016) by ROOT version5.34/18
   TCanvas *c1 = new TCanvas("c1", "c1",0,0,600,600);
   gStyle->SetOptFit(1);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
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
   entry=leg->AddEntry("Graph","Observed","L");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(3);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(62);
   entry=leg->AddEntry("","#pm 1#sigma Expected","F");

   Int_t ci;   // for color index setting
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
   pad_plot = new TPad("pad_plot", "pad_plot",0,0,1,0.82);
   pad_plot->Draw();
   pad_plot->cd();
   pad_plot->Range(10.71429,-2.731707,1588.095,3.365854);
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
   
   TH1F *hist1d = new TH1F("hist1d","",27,200,1525);
   hist1d->SetMinimum(0.01);
   hist1d->SetMaximum(1000);
   hist1d->SetLineStyle(0);
   hist1d->SetMarkerStyle(20);
   hist1d->GetXaxis()->SetTitle("m_{LQ} [GeV]");
   hist1d->GetXaxis()->SetMoreLogLabels();
   hist1d->GetXaxis()->SetNoExponent();
   hist1d->GetXaxis()->SetNdivisions(50005);
   hist1d->GetXaxis()->SetLabelFont(42);
   hist1d->GetXaxis()->SetTitleSize(0.05);
   hist1d->GetXaxis()->SetTickLength(0.02);
   hist1d->GetXaxis()->SetTitleOffset(1.08);
   hist1d->GetXaxis()->SetTitleFont(42);
   hist1d->GetYaxis()->SetTitle("95% CL limit on #sigma#font[42]{}#upoint#font[52]{B}#font[42]{}^2 [pb]");
   hist1d->GetYaxis()->SetNdivisions(506);
   hist1d->GetYaxis()->SetLabelFont(42);
   hist1d->GetYaxis()->SetLabelOffset(0.007);
   hist1d->GetYaxis()->SetTitleSize(0.05);
   hist1d->GetYaxis()->SetTickLength(0.02);
   hist1d->GetYaxis()->SetTitleOffset(1.08);
   hist1d->GetYaxis()->SetTitleFont(42);
   hist1d->GetZaxis()->SetNdivisions(506);
   hist1d->GetZaxis()->SetLabelFont(42);
   hist1d->GetZaxis()->SetLabelOffset(0.007);
   hist1d->GetZaxis()->SetTitleSize(0.05);
   hist1d->GetZaxis()->SetTickLength(0.02);
   hist1d->GetZaxis()->SetTitleFont(42);
   hist1d->Draw("");
   
   TGraphAsymmErrors *grae = new TGraphAsymmErrors(27);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#fcf10f");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,200,0.08570957);
   grae->SetPointError(0,0,0,0,0.2659076);
   grae->SetPoint(1,250,0.07750225);
   grae->SetPointError(1,0,0,0,0.2330063);
   grae->SetPoint(2,300,0.1070309);
   grae->SetPointError(2,0,0,0,0.326108);
   grae->SetPoint(3,350,0.09255123);
   grae->SetPointError(3,0,0,0,0.2782502);
   grae->SetPoint(4,400,0.1209698);
   grae->SetPointError(4,0,0,0,0.3714969);
   grae->SetPoint(5,450,0.1398869);
   grae->SetPointError(5,0,0,0,0.4342911);
   grae->SetPoint(6,500,0.1767254);
   grae->SetPointError(6,0,0,0,0.5486596);
   grae->SetPoint(7,550,0.2460747);
   grae->SetPointError(7,0,0,0,0.7880164);
   grae->SetPoint(8,600,0.3107796);
   grae->SetPointError(8,0,0,0,1.013174);
   grae->SetPoint(9,650,0.3948212);
   grae->SetPointError(9,0,0,0,1.36724);
   grae->SetPoint(10,700,0.5245209);
   grae->SetPointError(10,0,0,0,1.818774);
   grae->SetPoint(11,750,0.6878281);
   grae->SetPointError(11,0,0,0,2.508899);
   grae->SetPoint(12,800,0.908432);
   grae->SetPointError(12,0,0,0,3.451314);
   grae->SetPoint(13,850,1.17308);
   grae->SetPointError(13,0,0,0,4.557231);
   grae->SetPoint(14,900,1.598419);
   grae->SetPointError(14,0,0,0,6.455317);
   grae->SetPoint(15,950,2.02652);
   grae->SetPointError(15,0,0,0,8.613849);
   grae->SetPoint(16,1000,2.808685);
   grae->SetPointError(16,0,0,0,12.07957);
   grae->SetPoint(17,1050,3.651672);
   grae->SetPointError(17,0,0,0,16.12446);
   grae->SetPoint(18,1100,4.502869);
   grae->SetPointError(18,0,0,0,20.54173);
   grae->SetPoint(19,1150,5.960083);
   grae->SetPointError(19,0,0,0,27.87265);
   grae->SetPoint(20,1200,7.351685);
   grae->SetPointError(20,0,0,0,36.3867);
   grae->SetPoint(21,1250,9.474487);
   grae->SetPointError(21,0,0,0,48.56038);
   grae->SetPoint(22,1300,12.11646);
   grae->SetPointError(22,0,0,0,64.20963);
   grae->SetPoint(23,1350,15.41382);
   grae->SetPointError(23,0,0,0,86.30737);
   grae->SetPoint(24,1400,19.57642);
   grae->SetPointError(24,0,0,0,114.4549);
   grae->SetPoint(25,1450,25.31738);
   grae->SetPointError(25,0,0,0,153.3487);
   grae->SetPoint(26,1500,29.19507);
   grae->SetPointError(26,0,0,0,189.0398);
   
   TH1F *GrapX1 = new TH1F("GrapX1","",100,70,1630);
   GrapX1->SetMinimum(0.06975203);
   GrapX1->SetMaximum(240.0506);
   GrapX1->SetDirectory(0);
   GrapX1->SetStats(0);
   GrapX1->SetLineStyle(0);
   GrapX1->SetMarkerStyle(20);
   GrapX1->GetXaxis()->SetNdivisions(506);
   GrapX1->GetXaxis()->SetLabelFont(42);
   GrapX1->GetXaxis()->SetTitleSize(0.05);
   GrapX1->GetXaxis()->SetTickLength(0.02);
   GrapX1->GetXaxis()->SetTitleOffset(1.08);
   GrapX1->GetXaxis()->SetTitleFont(42);
   GrapX1->GetYaxis()->SetNdivisions(506);
   GrapX1->GetYaxis()->SetLabelFont(42);
   GrapX1->GetYaxis()->SetLabelOffset(0.007);
   GrapX1->GetYaxis()->SetTitleSize(0.05);
   GrapX1->GetYaxis()->SetTickLength(0.02);
   GrapX1->GetYaxis()->SetTitleOffset(1.08);
   GrapX1->GetYaxis()->SetTitleFont(42);
   GrapX1->GetZaxis()->SetNdivisions(506);
   GrapX1->GetZaxis()->SetLabelFont(42);
   GrapX1->GetZaxis()->SetLabelOffset(0.007);
   GrapX1->GetZaxis()->SetTitleSize(0.05);
   GrapX1->GetZaxis()->SetTickLength(0.02);
   GrapX1->GetZaxis()->SetTitleFont(42);
   grae->SetHistogram(GrapX1);
   
   grae->Draw("3");
   
   grae = new TGraphAsymmErrors(27);
   grae->SetName("");
   grae->SetTitle("");

   ci = TColor::GetColor("#00ff00");
   grae->SetFillColor(ci);
   grae->SetMarkerStyle(20);
   grae->SetPoint(0,200,0.1174331);
   grae->SetPointError(0,0,0,0,0.1310187);
   grae->SetPoint(1,250,0.1053051);
   grae->SetPointError(1,0,0,0,0.1147359);
   grae->SetPoint(2,300,0.1460317);
   grae->SetPointError(2,0,0,0,0.1618481);
   grae->SetPoint(3,350,0.1257527);
   grae->SetPointError(3,0,0,0,0.1370147);
   grae->SetPoint(4,400,0.1650498);
   grae->SetPointError(4,0,0,0,0.182926);
   grae->SetPoint(5,450,0.1908601);
   grae->SetPointError(5,0,0,0,0.2137193);
   grae->SetPoint(6,500,0.2411221);
   grae->SetPointError(6,0,0,0,0.2700013);
   grae->SetPoint(7,550,0.3385883);
   grae->SetPointError(7,0,0,0,0.3880916);
   grae->SetPoint(8,600,0.4276195);
   grae->SetPointError(8,0,0,0,0.4950754);
   grae->SetPoint(9,650,0.5483696);
   grae->SetPointError(9,0,0,0,0.6631103);
   grae->SetPoint(10,700,0.7285103);
   grae->SetPointError(10,0,0,0,0.8852256);
   grae->SetPoint(11,750,0.9616779);
   grae->SetPointError(11,0,0,0,1.214289);
   grae->SetPoint(12,800,1.273759);
   grae->SetPointError(12,0,0,0,1.670291);
   grae->SetPoint(13,850,1.652287);
   grae->SetPointError(13,0,0,0,2.200854);
   grae->SetPoint(14,900,2.272199);
   grae->SetPointError(14,0,0,0,3.094164);
   grae->SetPoint(15,950,2.90806);
   grae->SetPointError(15,0,0,0,4.118865);
   grae->SetPoint(16,1000,4.004194);
   grae->SetPointError(16,0,0,0,5.734878);
   grae->SetPoint(17,1050,5.230692);
   grae->SetPointError(17,0,0,0,7.702363);
   grae->SetPoint(18,1100,6.512469);
   grae->SetPointError(18,0,0,0,9.716268);
   grae->SetPoint(19,1150,8.662504);
   grae->SetPointError(19,0,0,0,13.22534);
   grae->SetPoint(20,1200,10.84801);
   grae->SetPointError(20,0,0,0,17.16409);
   grae->SetPoint(21,1250,14.02462);
   grae->SetPointError(21,0,0,0,23.10737);
   grae->SetPoint(22,1300,18.16246);
   grae->SetPointError(22,0,0,0,30.23406);
   grae->SetPoint(23,1350,23.3095);
   grae->SetPointError(23,0,0,0,40.65004);
   grae->SetPoint(24,1400,29.93608);
   grae->SetPointError(24,0,0,0,53.68401);
   grae->SetPoint(25,1450,39.04811);
   grae->SetPointError(25,0,0,0,70.7165);
   grae->SetPoint(26,1500,45.52624);
   grae->SetPointError(26,0,0,0,87.76553);
   
   TH1F *Graph_Graph2 = new TH1F("Graph_Graph2","",100,70,1630);
   Graph_Graph2->SetMinimum(0.09477461);
   Graph_Graph2->SetMaximum(146.6104);
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
   grae->SetHistogram(Graph_Graph2);
   
   grae->Draw("3");
   
   TGraph *graph = new TGraph(27);
   graph->SetName("Graph0");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);

   ci = TColor::GetColor("#ff0000");
   graph->SetLineColor(ci);
   graph->SetLineWidth(3);
   graph->SetPoint(0,200,0.1694335938);
   graph->SetPoint(1,250,0.1508789062);
   graph->SetPoint(2,300,0.2099609375);
   graph->SetPoint(3,350,0.1801757812);
   graph->SetPoint(4,400,0.2373046875);
   graph->SetPoint(5,450,0.2744140625);
   graph->SetPoint(6,500,0.3466796875);
   graph->SetPoint(7,550,0.490234375);
   graph->SetPoint(8,600,0.619140625);
   graph->SetPoint(9,650,0.80859375);
   graph->SetPoint(10,700,1.07421875);
   graph->SetPoint(11,750,1.42578125);
   graph->SetPoint(12,800,1.9140625);
   graph->SetPoint(13,850,2.4921875);
   graph->SetPoint(14,900,3.453125);
   graph->SetPoint(15,950,4.453125);
   graph->SetPoint(16,1000,6.171875);
   graph->SetPoint(17,1050,8.09375);
   graph->SetPoint(18,1100,10.15625);
   graph->SetPoint(19,1150,13.5625);
   graph->SetPoint(20,1200,17.1875);
   graph->SetPoint(21,1250,22.5625);
   graph->SetPoint(22,1300,29.125);
   graph->SetPoint(23,1350,38.125);
   graph->SetPoint(24,1400,49.375);
   graph->SetPoint(25,1450,64.8125);
   graph->SetPoint(26,1500,77.25);
   
   TH1F *Graph_Graph1 = new TH1F("Graph_Graph1","Graph",100,70,1630);
   Graph_Graph1->SetMinimum(0.135791);
   Graph_Graph1->SetMaximum(84.95991);
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
   
   graph = new TGraph(27);
   graph->SetName("Graph1");
   graph->SetTitle("Graph");
   graph->SetFillColor(1);
   graph->SetLineWidth(3);
   graph->SetMarkerStyle(20);
   graph->SetPoint(0,200,0.1099463282);
   graph->SetPoint(1,250,0.0856102309);
   graph->SetPoint(2,300,0.1207123556);
   graph->SetPoint(3,350,0.09549126285);
   graph->SetPoint(4,400,0.1175321471);
   graph->SetPoint(5,450,0.1452240092);
   graph->SetPoint(6,500,0.1931701904);
   graph->SetPoint(7,550,0.2781324006);
   graph->SetPoint(8,600,0.4595716023);
   graph->SetPoint(9,650,0.5977298698);
   graph->SetPoint(10,700,0.8639380082);
   graph->SetPoint(11,750,1.154684831);
   graph->SetPoint(12,800,1.464909666);
   graph->SetPoint(13,850,2.098376952);
   graph->SetPoint(14,900,2.987469954);
   graph->SetPoint(15,950,4.353400595);
   graph->SetPoint(16,1000,6.19508528);
   graph->SetPoint(17,1050,8.573650389);
   graph->SetPoint(18,1100,10.62260102);
   graph->SetPoint(19,1150,15.34494947);
   graph->SetPoint(20,1200,19.9684087);
   graph->SetPoint(21,1250,27.57599423);
   graph->SetPoint(22,1300,37.70644644);
   graph->SetPoint(23,1350,49.83188475);
   graph->SetPoint(24,1400,68.2780816);
   graph->SetPoint(25,1450,91.25083526);
   graph->SetPoint(26,1500,114.447722);
   
   TH1F *GrapX2 = new TH1F("GrapX2","Graph",100,70,1630);
   GrapX2->SetMinimum(0.07704921);
   GrapX2->SetMaximum(125.8839);
   GrapX2->SetDirectory(0);
   GrapX2->SetStats(0);
   GrapX2->SetLineStyle(0);
   GrapX2->SetMarkerStyle(20);
   GrapX2->GetXaxis()->SetNdivisions(506);
   GrapX2->GetXaxis()->SetLabelFont(42);
   GrapX2->GetXaxis()->SetTitleSize(0.05);
   GrapX2->GetXaxis()->SetTickLength(0.02);
   GrapX2->GetXaxis()->SetTitleOffset(1.08);
   GrapX2->GetXaxis()->SetTitleFont(42);
   GrapX2->GetYaxis()->SetNdivisions(506);
   GrapX2->GetYaxis()->SetLabelFont(42);
   GrapX2->GetYaxis()->SetLabelOffset(0.007);
   GrapX2->GetYaxis()->SetTitleSize(0.05);
   GrapX2->GetYaxis()->SetTickLength(0.02);
   GrapX2->GetYaxis()->SetTitleOffset(1.08);
   GrapX2->GetYaxis()->SetTitleFont(42);
   GrapX2->GetZaxis()->SetNdivisions(506);
   GrapX2->GetZaxis()->SetLabelFont(42);
   GrapX2->GetZaxis()->SetLabelOffset(0.007);
   GrapX2->GetZaxis()->SetTitleSize(0.05);
   GrapX2->GetZaxis()->SetTickLength(0.02);
   GrapX2->GetZaxis()->SetTitleFont(42);
   graph->SetHistogram(GrapX2);
   
   graph->Draw("pl");
    
    
    
    
    const int nTH=121;
    
    Double_t mTh[nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0};
    
    
    Double_t x_pdf[2*nTH] = {200.0,210.0,220.0,230.0,240.0,250.0,260.0,270.0,280.0,290.0,300.0,310.0,320.0,330.0,340.0,350.0,360.0,370.0,380.0,390.0,400.0,410.0,420.0,430.0,440.0,450.0,460.0,470.0,480.0,490.0,500.0,510.0,520.0,530.0,540.0,550.0,560.0,570.0,580.0,590.0,600.0,610.0,620.0,630.0,640.0,650.0,660.0,670.0,680.0,690.0,700.0,710.0,720.0,730.0,740.0,750.0,760.0,770.0,780.0,790.0,800.0,810.0,820.0,830.0,840.0,850.0,860.0,870.0,880.0,890.0,900.0,910.0,920.0,930.0,940.0,950.0,960.0,970.0,980.0,990.0,1000.0,1010.0,1020.0,1030.0,1040.0,1050.0,1060.0,1070.0,1080.0,1090.0,1100.0,1110.0,1120.0,1130.0,1140.0,1150.0,1160.0,1170.0,1180.0,1190.0,1200.0,1210.0,1220.0,1230.0,1240.0,1250.0,1260.0,1270.0,1280.0,1290.0,1300.0,1310.0,1320.0,1330.0,1340.0,1350.0,1360.0,1370.0,1380.0,1390.0,1400.0,1400.0,1390.0,1380.0,1370.0,1360.0,1350.0,1340.0,1330.0,1320.0,1310.0,1300.0,1290.0,1280.0,1270.0,1260.0,1250.0,1240.0,1230.0,1220.0,1210.0,1200.0,1190.0,1180.0,1170.0,1160.0,1150.0,1140.0,1130.0,1120.0,1110.0,1100.0,1090.0,1080.0,1070.0,1060.0,1050.0,1040.0,1030.0,1020.0,1010.0,1000.0,990.0,980.0,970.0,960.0,950.0,940.0,930.0,920.0,910.0,900.0,890.0,880.0,870.0,860.0,850.0,840.0,830.0,820.0,810.0,800.0,790.0,780.0,770.0,760.0,750.0,740.0,730.0,720.0,710.0,700.0,690.0,680.0,670.0,660.0,650.0,640.0,630.0,620.0,610.0,600.0,590.0,580.0,570.0,560.0,550.0,540.0,530.0,520.0,510.0,500.0,490.0,480.0,470.0,460.0,450.0,440.0,430.0,420.0,410.0,400.0,390.0,380.0,370.0,360.0,350.0,340.0,330.0,320.0,310.0,300.0,290.0,280.0,270.0,260.0,250.0,240.0,230.0,220.0,210.0,200.0};
    
    //for beta=1
    
     Double_t xsTh[nTH] = {6.06E+01,4.79E+01,3.82E+01,3.07E+01,2.49E+01,2.03E+01,1.67E+01,1.38E+01,1.15E+01,9.60E+00,8.04E+00,6.80E+00,5.75E+00,4.90E+00,4.18E+00,3.59E+00,3.09E+00,2.66E+00,2.31E+00,2.00E+00,1.74E+00,1.52E+00,1.33E+00,1.17E+00,1.03E+00,9.06E-01,8.00E-01,7.07E-01,6.27E-01,5.58E-01,4.96E-01,4.43E-01,3.95E-01,3.54E-01,3.16E-01,2.84E-01,2.55E-01,2.29E-01,2.07E-01,1.87E-01,1.69E-01,1.53E-01,1.38E-01,1.25E-01,1.14E-01,1.03E-01,9.39E-02,8.54E-02,7.78E-02,7.10E-02,6.48E-02,5.92E-02,5.42E-02,4.97E-02,4.55E-02,4.16E-02,3.82E-02,3.51E-02,3.22E-02,2.97E-02,2.73E-02,2.51E-02,2.31E-02,2.13E-02,1.97E-02,1.82E-02,1.68E-02,1.55E-02,1.44E-02,1.33E-02,1.23E-02,1.14E-02,1.06E-02,9.79E-03,9.09E-03,8.45E-03,7.84E-03,7.28E-03,6.77E-03,6.30E-03,5.86E-03,5.45E-03,5.08E-03,4.73E-03,4.41E-03,4.11E-03,3.83E-03,3.58E-03,3.34E-03,3.12E-03,2.91E-03,2.72E-03,2.54E-03,2.38E-03,2.22E-03,2.08E-03,1.95E-03,1.82E-03,1.71E-03,1.60E-03,1.50E-03,1.41E-03,1.32E-03,1.24E-03,1.16E-03,1.09E-03,1.02E-03,9.59E-04,9.01E-04,8.46E-04,7.95E-04,7.48E-04,7.03E-04,6.61E-04,6.22E-04,5.85E-04,5.50E-04,5.18E-04,4.87E-04,4.59E-04,4.33E-04};
    //,4.07E-04,3.84E-04,3.61E-04,3.41E-04,3.21E-04,3.03E-04,2.85E-04,2.69E-04,2.54E-04,2.40E-04,2.26E-04,2.13E-04,2.02E-04,1.90E-04,1.80E-04,1.70E-04,1.60E-04,1.51E-04,1.43E-04,1.35E-04,1.28E-04,1.21E-04,1.14E-04,1.08E-04,1.02E-04,9.66E-05,9.13E-05,8.64E-05,8.18E-05,7.74E-05,7.32E-05,6.93E-05,6.56E-05,6.21E-05,5.88E-05,5.57E-05,5.27E-05,5.00E-05,4.73E-05,4.48E-05,4.25E-05,4.02E-05,3.81E-05,3.61E-05,3.43E-05,3.25E-05,3.08E-05,2.92E-05,2.77E-05,2.62E-05,2.49E-05,2.36E-05,2.24E-05,2.12E-05,2.01E-05,1.91E-05,1.81E-05,1.72E-05,1.63E-05,1.55E-05,1.47E-05,1.39E-05,1.32E-05,1.26E-05,1.19E-05,1.13E-05,1.07E-05,1.02E-05,9.68E-06,9.20E-06,8.73E-06,8.29E-06,7.87E-06,7.47E-06,7.10E-06,6.74E-06,6.41E-06,6.08E-06,5.78E-06,5.49E-06,5.22E-06,4.96E-06,4.71E-06,4.47E-06,4.26E-06,4.04E-06,3.84E-06,3.65E-06,3.46E-06,3.30E-06,3.13E-06,2.97E-06,2.83E-06,2.69E-06,2.55E-06,2.43E-06,2.31E-06,2.19E-06,2.08E-06,1.98E-06,1.88E-06,1.79E-06,1.70E-06,1.62E-06,1.54E-06,1.46E-06,1.39E-06,1.32E-06,1.25E-06,1.19E-06,1.13E-06,1.08E-06,1.03E-06,9.74E-07,9.27E-07,8.81E-07,8.37E-07,7.96E-07,7.57E-07,7.20E-07,6.84E-07,6.50E-07,6.19E-07,5.88E-07,5.60E-07,5.32E-07,5.05E-07,4.80E-07,4.57E-07,4.35E-07,4.13E-07,3.92E-07,3.73E-07,3.55E-07,3.38E-07,3.21E-07,3.05E-07,2.90E-07,2.75E-07,2.62E-07,2.49E-07,2.36E-07,2.25E-07,2.14E-07,2.03E-07,1.93E-07,1.83E-07,1.74E-07,1.66E-07,1.58E-07,1.50E-07,1.42E-07,1.35E-07,1.28E-07,1.22E-07,1.16E-07,1.10E-07,1.05E-07,9.95E-08,9.46E-08}
    
    
    //for beta=1
    
    Double_t y_pdf[2*nTH] = {63.1,49.97,39.99,32.2,26.17,21.39,17.632,14.61,12.204,10.216,8.575,7.273,6.168,5.268,4.504,3.875,3.345,2.888,2.512,2.182,1.901,1.665,1.461,1.287,1.136,1.0012,0.886,0.7851,0.6978,0.6223,0.5538,0.4959,0.4433,0.3979,0.3562,0.3209,0.2885,0.2597,0.2352,0.2129,0.1927,0.1748,0.158,0.1435,0.131,0.1187,0.1083,0.0988,0.0902,0.0824,0.0754,0.06898,0.06324,0.0581,0.05326,0.04887,0.04491,0.04134,0.038,0.0351,0.03233,0.02978,0.02747,0.02538,0.02351,0.02175,0.02011,0.0186,0.0173,0.01602,0.01483,0.01377,0.01282,0.01187,0.01105,0.01028,0.00955,0.00889,0.00828,0.00772,0.00719,0.0067,0.00626,0.00584,0.00545,0.005092,0.004751,0.004447,0.004157,0.003889,0.003635,0.003404,0.003185,0.002988,0.002794,0.002621,0.002461,0.002303,0.002166,0.002031,0.001907,0.001795,0.001684,0.001584,0.001485,0.001399,0.001312,0.001235,0.001162,0.001093,0.001029,0.00097,0.000913,0.00086,0.000811,0.000764,0.00072,0.000679,0.00064,0.000604,0.000571,0.000295,0.000314,0.000334,0.000357,0.00038,0.000406,0.000433,0.000462,0.000493,0.000526,0.000561,0.000599,0.00064,0.000683,0.000728,0.000781,0.000835,0.000896,0.000956,0.001025,0.001093,0.001169,0.001254,0.001337,0.001439,0.001539,0.001646,0.001772,0.001895,0.002036,0.002185,0.002351,0.002523,0.002713,0.002909,0.003128,0.00337,0.00362,0.0039,0.0042,0.00453,0.00488,0.00526,0.00567,0.00613,0.00662,0.00713,0.00771,0.00838,0.00903,0.00977,0.01058,0.0115,0.0124,0.01349,0.01465,0.01589,0.01722,0.01873,0.02042,0.02227,0.0243,0.0264,0.02886,0.03149,0.03433,0.03774,0.0413,0.04516,0.04942,0.0542,0.0596,0.0654,0.072,0.0795,0.0873,0.097,0.1065,0.118,0.1312,0.1453,0.1611,0.1788,0.1983,0.2215,0.2471,0.2758,0.3101,0.3467,0.3901,0.4382,0.4937,0.5562,0.6289,0.714,0.8108,0.924,1.053,1.199,1.375,1.579,1.818,2.108,2.432,2.835,3.305,3.856,4.532,5.332,6.327,7.505,8.984,10.796,12.99,15.768,19.21,23.63,29.2,36.41,45.83,58.1};
    
    
    TGraph *xsTh_vs_m = new TGraph(nTH, mTh, xsTh);
    
    xsTh_vs_m->SetLineWidth(2);
    
    xsTh_vs_m->SetLineColor(kBlue);
    
    xsTh_vs_m->SetFillColor(kCyan-6);
    
    xsTh_vs_m->SetMarkerSize(0.00001);
    
    xsTh_vs_m->SetMarkerStyle(22);
    
    xsTh_vs_m->SetMarkerColor(kBlue);
    
    
    TGraph *grshade = new TGraph(2*nTH,x_pdf,y_pdf);
    
    grshade->SetFillColor(kCyan-6);
    
    grshade->SetFillStyle(3001);
    
    
    xsTh_vs_m->Draw("L");
    
    grshade->Draw("f");
    
    
    
    
    
   TLatex *   tex = new TLatex(0.1578,0.9113,"");
tex->SetNDC();
   tex->SetTextAlign(13);
   tex->SetTextSize(0.048);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.96,0.952,"CMS Preliminary       2.3 fb^{-1} (13 TeV)");
tex->SetNDC();
   tex->SetTextAlign(31);
   tex->SetTextFont(42);
   tex->SetTextSize(0.036);
   tex->SetLineWidth(2);
   tex->Draw();
   
   TH1F *hist1d__1 = new TH1F("hist1d__1","",27,200,1525);
   hist1d__1->SetMinimum(0.01);
   hist1d__1->SetMaximum(1000);
   hist1d__1->SetDirectory(0);
   hist1d__1->SetLineStyle(0);
   hist1d__1->SetMarkerStyle(20);
   hist1d__1->GetXaxis()->SetTitle("m_{LQ} [GeV]");
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
   hist1d__1->Draw("sameaxis");
   pad_plot->Modified();
   c1->cd();
   c1->Modified();
   c1->cd();
   c1->SetSelected(c1);
}
