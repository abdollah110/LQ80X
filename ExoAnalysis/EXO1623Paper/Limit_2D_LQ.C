#include <vector>
//#include "setTDRStyle.C"
//#include "TDRStyle.C"

using namespace std;

double intersection(double m1, double m2,
                    double y11, double y12, double y21, double y22) {
    // y = ax + b
    // y11 = am1 + b
    // y12 = am2 + b
    double a1 = (y11 - y12)/(m1 - m2);
    double b1 = y11 - a1*m1;
    
    double a2 = (y21 - y22)/(m1 - m2);
    double b2 = y21 - a2*m1;
    
    // overlap: a1*m + b1 = a2*m + b2 => (a1 - a2)*m = (b2 - b1)
    double m = (b2 - b1)/(a1 - a2);
    if ( m > m2 || m < m1 ) return 0;
    return m;
}


void Limit_2D_LQ() {
    
    //  setTDRStyle();
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetLineWidth(2);
    gROOT->ForceStyle();
    
    
    TCanvas *c = new TCanvas("c1", "c1",0,45,600,600);
    gStyle->SetOptStat(0);
    c->SetHighLightColor(2);
    c->Range(0,0,1,1);
    c->SetFillColor(0);
    c->SetBorderMode(0);
    c->SetBorderSize(2);
    c->SetLeftMargin(0.12);
    c->SetRightMargin(0.04);
    c->SetTopMargin(0.06);
    c->SetBottomMargin(0.12);
    c->SetFrameFillStyle(0);
    c->SetFrameLineWidth(2);
    c->SetFrameBorderMode(0);
    
    c->cd();
    
    //  const int nMass = 15;
    //  Double_t mData[] = {200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900};
    //  Double_t limit_observed[] = {0.0827284, 0.0981056, 0.0646578, 0.0733808, 0.115078, 0.154828, 0.227671, 0.307448, 0.39362, 0.554267, 0.783352, 1.07813, 1.5539, 2.21602, 3.46142};
    //  Double_t limit_expected[] = {0.088132, 0.100218, 0.0708202, 0.0703361, 0.090391, 0.131143, 0.175555, 0.247355, 0.34838, 0.487021, 0.693413, 0.979308, 1.406, 2.00591, 3.09258};
    ////
    //
    //
    //
    //    //    //    https://twiki.cern.ch/twiki/bin/view/CMS/Exo2015LQ1AndLQ2Analyses
    float XS_200 =  60.6;
    float XS_250 =  20.3;
    float XS_300 =      8.05E+00;
    float XS_350 =      3.58E+00;
    float XS_400 =      1.74E+00;
    float XS_450 =      9.05E-01;
    float XS_500 =      4.96E-01;
    float XS_550 =      2.84E-01;
    float XS_600 =      1.69E-01;
    float XS_650 =      1.03E-01;
    float XS_700 =      6.48E-02;
    float XS_750 =      4.16E-02;
    float XS_800 =      2.73E-02;
    float XS_850 =      1.82E-02;
    float XS_900 =      1.23E-02;
    float XS_950 =      8.45E-03;
    float XS_1000 =      5.86E-03;
    float XS_1050 =      4.11E-03;
    float XS_1100 =      2.91E-03;
    float XS_1150 =      2.08E-03;
    float XS_1200 =      1.50E-03;
    float XS_1250 =      1.09E-03;
    float XS_1300 =      7.95E-04;
    float XS_1350 =      5.85E-04;
    float XS_1400 =      4.33E-04;
    float XS_1450 =      3.21E-04;
    float XS_1500 =      2.40E-04;
    //
    
    
    const int nMass = 27;
    Double_t mData[] = {
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
    //
    //
    //
    Double_t limit_expected[] = {
        4.390625/XS_200,
        1.992188/XS_250,
        0.6269531 / XS_300,
        0.3388672 / XS_350,
        0.175293 / XS_400,
        0.09814453 / XS_450,
        0.06005859 / XS_500,
        0.04345703 / XS_550,
        0.03271484 / XS_600,
        0.02490234 / XS_650,
        0.02001953 / XS_700,
        0.01611328 / XS_750,
        0.01318359 / XS_800,
        0.01123047 / XS_850,
        0.01025391 / XS_900,
        0.008300781 / XS_950,
        0.007324219 / XS_1000,
        0.006347656 / XS_1050,
        0.006347656 / XS_1100,
        0.005371094 / XS_1150,
        0.005371094 / XS_1200,
        0.004394531 / XS_1250,
        0.004394531 / XS_1300,
        0.004394531 / XS_1350,
        0.004394531 / XS_1400,
        0.003417969 / XS_1450,
        0.003417969 / XS_1500};
    //
    //
    Double_t limit_observed[] = {
        4.290325 / XS_200,
        1.529551 / XS_250,
        0.7555034 / XS_300,
        0.4360767 / XS_350,
        0.217999 / XS_400,
        0.1353539 / XS_450,
        0.08324244 / XS_500,
        0.05594456 / XS_550,
        0.04043446 / XS_600,
        0.03101383 / XS_650,
        0.02521476 / XS_700,
        0.0196628 / XS_750,
        0.0164327 / XS_800,
        0.0139788 / XS_850,
        0.01262523 / XS_900,
        0.01021711 / XS_950,
        0.008648229 / XS_1000,
        0.007460774 / XS_1050,
        0.006675119 / XS_1100,
        0.005865333 / XS_1150,
        0.005098765 / XS_1200,
        0.004850521 / XS_1250,
        0.004428081 / XS_1300,
        0.003886634 / XS_1350,
        0.00387614 / XS_1400,
        0.003507627 / XS_1450,
        0.003459288 / XS_1500};
    
    
    
    
    
    
    
    
    
    
    
    /* //Asympt CLs
     Double_t limit_observed[] = {0.0594621, 0.0843084, 0.0609738, 0.0718055, 0.110206, 0.147462, 0.217648, 0.294432, 0.367942, 0.525929, 0.739963, 1.01469, 1.45093, 2.07904, 3.25821};
     Double_t limit_expected[] = {0.074707, 0.103027, 0.0668945, 0.0737305, 0.0942383, 0.130371, 0.175293, 0.250977, 0.338867, 0.482422, 0.689453, 0.964844, 1.37109, 1.94531, 2.99219};
     */
    
    std::vector<double> limExp;
    std::vector<double> betaExp;
    
    std::vector<double> limObs;
    std::vector<double> betaObs;
    // find intersection
    
    for(int i = 0; i != 1; ++i) {
        double lim1 = limit_expected[i];
        double lim2 = limit_expected[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            
            cout << m1 <<" "<< m2 <<" "<< 1<<" "<< 1<<" "<< lim1/beta/beta<<" "<<  lim2/beta/beta <<" "<< "  --->  "<< result<<"\n";
            
            
            if ( result != 0 ) {
                limExp.push_back(result);
                betaExp.push_back(beta);
                cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 1; i != 2; ++i) {
        double lim1 = limit_expected[i];
        double lim2 = limit_expected[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 1.001; beta >= 0; beta -= 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limExp.push_back(result);
                betaExp.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 2; i != nMass; ++i) {
        double lim1 = limit_expected[i];
        double lim2 = limit_expected[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limExp.push_back(result);
                betaExp.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    
    
    
    // observed limit
    for(int i = 0; i != 1; ++i) {
        double lim1 = limit_observed[i];
        double lim2 = limit_observed[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limObs.push_back(result);
                betaObs.push_back(beta);
            }
        }
    }
    for(int i = 1; i != 2; ++i) {
        double lim1 = limit_observed[i];
        double lim2 = limit_observed[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 1.001; beta >= 0; beta -= 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limObs.push_back(result);
                betaObs.push_back(beta);
            }
        }
    }
    for(int i = 2; i != nMass; ++i) {
        double lim1 = limit_observed[i];
        double lim2 = limit_observed[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limObs.push_back(result);
                betaObs.push_back(beta);
            }
        }
    }
    
    const int nexp = limExp.size();
    float massExp[nexp+4];
    float bExp[nexp+4];
    for(int i = 0; i != nexp; ++i) {
        massExp[i] = limExp[i];
        bExp[i] = betaExp[i];
    }
    massExp[nexp] = massExp[nexp-1];
    bExp[nexp]    = 1;
    
    massExp[nexp+1] = 200;
    bExp[nexp+1]    = 1;
    
    massExp[nexp+2] = 200;
    bExp[nexp+2] = bExp[0];
    massExp[nexp+3] = massExp[0];
    bExp[nexp+3] = bExp[0];
    
    const int nobs = limObs.size();
    float massObs[nobs+4];
    float bObs[nobs+4];
    for(int i = 0; i != nobs; ++i) {
        massObs[i] = limObs[i];
        bObs[i] = betaObs[i];
    }
    massObs[nobs] = massObs[nobs-1];
    bObs[nobs]    = 1;
    
    massObs[nobs+1] = 200;
    bObs[nobs+1]    = 1;
    
    massObs[nobs+2] = 200;
    bObs[nobs+2] = bObs[0];
    massObs[nobs+3] = massObs[0];
    bObs[nobs+3] = bObs[0];
    
    TGraph* grExp = new TGraph(nexp+4, massExp, bExp);
    TGraph* grObs = new TGraph(nobs+4, massObs, bObs);
    
    //  for(int i = 0; i < nexp+3; ++i) {
    //    cout << i << "\t" << massExp[i] << "\t" << bExp[i] << endl;
    //  }
    
    
    
    // ------------>Primitives in pad: pad_plot
    TPad *pad_plot = new TPad("pad_plot", "pad_plot",0,0,1,1);
    pad_plot->Draw();
    pad_plot->cd();
    pad_plot->Range(10.71429,-5.02439,1500,3.512195);
    pad_plot->SetFillColor(0);
    pad_plot->SetFillStyle(4000);
    pad_plot->SetBorderMode(0);
    pad_plot->SetBorderSize(2);
    //    pad_plot->SetLogy();
    //    pad_plot->SetGridx();
    //    pad_plot->SetGridy();
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
    
    
    
    TH2F* frame = new TH2F("frame", "", 100, 200, 1500, 100, 0.2, 1);
    TAxis* ax = frame->GetXaxis();
    TAxis* ay = frame->GetYaxis();
    ax->SetTitle("M_{LQ} (GeV)");
    //  ax->SetLabelOffset(0.01);
    ay->SetTitle("#Beta(LQ#rightarrow#tau b)");
    //    ax->SetTitleFont(132);
    ax->SetTitleSize(0.05);
    //    ay->SetTitleFont(132);
    ay->SetTitleSize(0.05);
    ay->SetRangeUser(0.21,1);
    frame->Draw();
    
    grExp->SetLineColor(TColor::GetColor(0, 0, 333));
    grExp->SetFillColor(TColor::GetColor(200, 222, 285));
    
    //  grObs->SetFillColor(kBlack);
    grObs->SetLineColor(kBlack);
    grObs->SetLineWidth(2);
    grObs->SetLineStyle(7);
    //    grObs->SetFillStyle(3005);
    //  grExp->SetLineWidth(2);
    //  grObs->SetLineWidth(2);
    //  grObs->SetFillStyle(3005);
    grExp->Draw("F");
    grObs->Draw("L");
    grExp->Draw("L");
    
    
//    TLatex* tx = new TLatex(250,0.93,"CMS");
//    tx->SetTextFont(61);
//    tx->SetTextSize(0.05);
//    tx->Draw("SAME");
//    TLatex* tx2 = new TLatex(1000,1.03101,"12.9 fb^{-1} (13 TeV)");
//    tx2->SetTextSize(0.04);
//    tx2->SetTextAlign(   12 );
//    tx2->SetTextColor(    1 );
//    tx2->SetTextFont (   42 );
//    tx2->Draw("SAME");
    
    
    
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
    
    
    
    
    
    
    //  TLegend* leg = new TLegend(0.50, 0.14, 0.90, 0.35,"CMS 19.7 fb^{-1}, #sqrt{s} = 8 TeV", "brNDC");
    //  TLegend* leg = new TLegend(0.50, 0.14, 0.90, 0.35,"19.7 fb^{-1}, #sqrt{s} = 8 TeV", "brNDC");
    TLegend* leg = new TLegend(0.65, 0.60, 0.90, 0.80,"", "brNDC");
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->SetMargin(0.15);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(grExp, "Expected limit","f");
    leg->AddEntry(grObs, "Observed limit","L");
    leg->Draw();
    
    //gPad->RedrawAxis();
    //    c->RedrawAxis();
    //    pad_plot->Modified();
    pad_plot->Draw();
    c->cd();
    c->Modified();
    //    c->Print("limit_beta_vs_mass.eps");
    c->Print("limit_2D_LQ.pdf");
    //  c->Print("limit_beta_vs_mass.png");
    
    
}
