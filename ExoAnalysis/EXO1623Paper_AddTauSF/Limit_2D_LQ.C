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
    c->SetTickx(1);
    c->SetTicky(1);
    
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
    
    std::map<int, float> XS;
    XS[200]=      60.6;
    XS[250]=      20.3;
    XS[300]=      8.05E+00;
    XS[350]=      3.58E+00;
    XS[400]=      1.74E+00;
    XS[450]=      9.05E-01;
    XS[500]=      4.96E-01;
    XS[550]=      2.84E-01;
    XS[600]=      1.69E-01;
    XS[650]=      1.03E-01;
    XS[700]=      6.48E-02;
    XS[750]=      4.16E-02;
    XS[800]=      2.73E-02;
    XS[850]=      1.82E-02;
    XS[900]=      1.23E-02;
    XS[950]=      8.45E-03;
    XS[1000]=      5.86E-03;
    XS[1050]=      4.11E-03;
    XS[1100]=      2.91E-03;
    XS[1150]=      2.08E-03;
    XS[1200]=      1.50E-03;
    XS[1250]=      1.09E-03;
    XS[1300]=      7.95E-04;
    XS[1350]=      5.85E-04;
    XS[1400]=      4.33E-04;
    XS[1450]=      3.21E-04;
    XS[1500]=      2.40E-04;
    
    
    
    const int nMass = 26;
    int mData[nMass] = {
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
//        1450,
        1500};
    
    
    
    // Observed!!!!!!!
    
    Double_t ObservedLimitValues[27] = {
        
        5.169031,
        2.127156,
        1.119, // new
        0.554736,
        0.279327,
        0.164877,
        0.10318,
        0.0695557,
        0.0507156,
        0.0386856,
        0.031826,
        0.0244583,
        0.0194931,
        0.0175816,
        0.0156609,
        0.0132805,
        0.0108856,
        0.00979614,
        0.0088028,
        0.00763702,
        0.00695305,
        0.00662155,
        0.0061306,
        0.0051651,
        0.0056942,
        0.00519066,
        0.00458145};
    
    
    // Expected !!!!!
    
    Double_t ExpectedLimitValues[27] = {
        5.212884,
        2.624342,
        1.0423, //new
        0.39624,
        0.206909,
        0.113708,
        0.0687866,
        0.0496826,
        0.0375671,
        0.028656,
        0.0247536,
        0.0197548,
        0.0155945,
        0.0136745,
        0.0126492,
        0.0102158,
        0.00997849,
        0.0089798,
        0.00806923,
        0.00694275,
        0.00632095,
        0.00601959,
        0.00557327,
        0.0051651,
        0.00517654,
        0.00471878,
        0.00458145};
    
    
    //Plus One sigma
    Double_t PlusOneSigmaLimitValues[27] = {
        2.541088,
        1.288593,
        0.502809,
        0.1918498,
        0.103455,
        0.051169,
        0.0343934,
        0.0248413,
        0.0187836,
        0.014328,
        0.0106086,
        0.0103477,
        0.0077972,
        0.0058606,
        0.005421,
        0.0061294,
        0.00362851,
        0.0040817,
        0.00366787,
        0.00485995,
        0.00379255,
        0.00361176,
        0.00334397,
        0.00361557,
        0.00258828,
        0.00377502,
        0.00320702};
    
    
    
    
    ////////////////////////////////////////////////////////////////
    //   -1 sigma
    ////////////////////////////////////////////////////////////////
    Double_t MinusOneSigmaLimitValues[27] = {
        1.480962,
        0.7831655,
        0.2920889,
        0.09906,
        0.051727,
        0.0341121,
        0.0171966,
        0.0149048,
        0.0093917,
        0.007164,
        0.0082512,
        0.0056442,
        0.0046784,
        0.0032558,
        0.00421643,
        0.00306477,
        0.00362854,
        0.00326538,
        0.0022007,
        0.00208283,
        0.00126419,
        0.00180588,
        0.00167198,
        0.00154953,
        0.0010353,
        0.00094376,
        0.00091629};

    
    
    
    //
    Double_t limit_expected[26];
    Double_t limit_plusOneSigma[26];
    Double_t limit_MinusOneSigma[26];
    Double_t limit_observed[26];
    
    for (int i=0; i < 26; i++){
        limit_expected[i]=ExpectedLimitValues[i]/XS[mData[i]];
        limit_plusOneSigma[i]=(ExpectedLimitValues[i]+PlusOneSigmaLimitValues[i])/XS[mData[i]];
        limit_MinusOneSigma[i]=(ExpectedLimitValues[i]-MinusOneSigmaLimitValues[i])/XS[mData[i]];
        limit_observed[i]=ObservedLimitValues[i]/XS[mData[i]];
    }
    
    
    
    /* //Asympt CLs
     Double_t limit_observed[] = {0.0594621, 0.0843084, 0.0609738, 0.0718055, 0.110206, 0.147462, 0.217648, 0.294432, 0.367942, 0.525929, 0.739963, 1.01469, 1.45093, 2.07904, 3.25821};
     Double_t limit_expected[] = {0.074707, 0.103027, 0.0668945, 0.0737305, 0.0942383, 0.130371, 0.175293, 0.250977, 0.338867, 0.482422, 0.689453, 0.964844, 1.37109, 1.94531, 2.99219};
     */
    
    std::vector<double> limExp;
    std::vector<double> betaExp;
    
    std::vector<double> limPlusSigma;
    std::vector<double> betaPlusSigma;
    
    std::vector<double> limMinusSigma;
    std::vector<double> betaMinusSigma;
    
    std::vector<double> limObs;
    std::vector<double> betaObs;
    
    
    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    // Expected limit
    ///////////////////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i != 1; ++i) {
        double lim1 = limit_expected[i];
        double lim2 = limit_expected[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            
//            cout << m1 <<" "<< m2 <<" "<< 1<<" "<< 1<<" "<< lim1/beta/beta<<" "<<  lim2/beta/beta <<" "<< "  --->  "<< result<<"\n";
            
            
            if ( result != 0 ) {
                limExp.push_back(result);
                betaExp.push_back(beta);
//                cout << beta << '\t' << result << endl; //KK
                
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

    
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    // Expected +1 sigma  limit
    ///////////////////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i != 1; ++i) {
        double lim1 = limit_plusOneSigma[i];
        double lim2 = limit_plusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            
//            cout << m1 <<" "<< m2 <<" "<< 1<<" "<< 1<<" "<< lim1/beta/beta<<" "<<  lim2/beta/beta <<" "<< "  --->  "<< result<<"\n";
            
            
            if ( result != 0 ) {
                limPlusSigma.push_back(result);
                betaPlusSigma.push_back(beta);
//                cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 1; i != 2; ++i) {
        double lim1 = limit_plusOneSigma[i];
        double lim2 = limit_plusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 1.001; beta >= 0; beta -= 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limPlusSigma.push_back(result);
                betaPlusSigma.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 2; i != nMass; ++i) {
        double lim1 = limit_plusOneSigma[i];
        double lim2 = limit_plusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limPlusSigma.push_back(result);
                betaPlusSigma.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
  
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    // Expected -1 sigma  limit
    ///////////////////////////////////////////////////////////////////////////////////////////
    for(int i = 0; i != 1; ++i) {
        double lim1 = limit_MinusOneSigma[i];
        double lim2 = limit_MinusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            
//            cout << m1 <<" "<< m2 <<" "<< 1<<" "<< 1<<" "<< lim1/beta/beta<<" "<<  lim2/beta/beta <<" "<< "  --->  "<< result<<"\n";
            
            
            if ( result != 0 ) {
                limMinusSigma.push_back(result);
                betaMinusSigma.push_back(beta);
//                cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 1; i != 2; ++i) {
        double lim1 = limit_MinusOneSigma[i];
        double lim2 = limit_MinusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 1.001; beta >= 0; beta -= 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limMinusSigma.push_back(result);
                betaMinusSigma.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    for(int i = 2; i != nMass; ++i) {
        double lim1 = limit_MinusOneSigma[i];
        double lim2 = limit_MinusOneSigma[i+1];
        double m1 = mData[i];
        double m2 = mData[i+1];
        
        for(double beta = 0.001; beta < 1.001; beta += 0.001) {
            double result = intersection(m1, m2, 1, 1, lim1/beta/beta, lim2/beta/beta);
            if ( result != 0 ) {
                limMinusSigma.push_back(result);
                betaMinusSigma.push_back(beta);
                //	cout << beta << '\t' << result << endl; //KK
                
            }
        }
    }
    
    
    ///////////////////////////////////////////////////////////////////////////////////////////
    // observed limit
    ///////////////////////////////////////////////////////////////////////////////////////////
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
    
    
    
    
    
    
    
    
    
    
    
    
    //////////////////////////////////////////////////////////////////
    // Expected
    //////////////////////////////////////////////////////////////////
    const int nexp = limExp.size();
    
//    cout <<"-------------------->   "<<nexp <<"\n\n\n\n";
    
    Double_t massExp[nexp+4];
    Double_t bExp[nexp+4];
    for(int i = 0; i != nexp; ++i) {
        massExp[i] = limExp[i];
        bExp[i] = betaExp[i];
//        cout <<"###### exp massExp[i] "<<massExp[i] << "   bExp[i] "<<bExp[i]<<"\n";
    }
    
    massExp[nexp] = massExp[nexp-1];
    bExp[nexp]    = 1;

    massExp[nexp+1] = 200;
    bExp[nexp+1]    = 1;
    
    massExp[nexp+2] = 200;
    bExp[nexp+2] = bExp[0];
    
    massExp[nexp+3] = massExp[0];
    bExp[nexp+3] = bExp[0];
    
    
    //////////////////////////////////////////////////////////////////
    // Plus One Sigma
    //////////////////////////////////////////////////////////////////
    const int nplusSig = limPlusSigma.size();
    
//    cout <<"-------------------->   "<<nplusSig <<"\n\n\n\n";
    
    Double_t massPlusOneSigma[nplusSig+4];
    Double_t bPlusOneSigma[nplusSig+4];
    for(int i = 0; i != nplusSig; ++i) {
        massPlusOneSigma[i] = limPlusSigma[i];
        bPlusOneSigma[i] = betaPlusSigma[i];
//        cout <<"###### exp massPlusOneSigma[i] "<<massPlusOneSigma[i] << "   bPlusOneSigma[i] "<<bPlusOneSigma[i]<<"\n";
    }
    
    massPlusOneSigma[nplusSig] = massPlusOneSigma[nplusSig-1];
    bPlusOneSigma[nplusSig]    = 1;
    
    massPlusOneSigma[nplusSig+1] = 200;
    bPlusOneSigma[nplusSig+1]    = 1;
    
    massPlusOneSigma[nplusSig+2] = 200;
    bPlusOneSigma[nplusSig+2] = bPlusOneSigma[0];
    
    massPlusOneSigma[nplusSig+3] = massPlusOneSigma[0];
    bPlusOneSigma[nplusSig+3] = bPlusOneSigma[0];
    
    Double_t NewbPlusOneSigma[nexp+4];
    for(int i = 0; i != nexp+4; ++i) {
        NewbPlusOneSigma[i]=bPlusOneSigma[i]-bExp[i];
    }
    
    //////////////////////////////////////////////////////////////////
    // Minus One Sigma
    //////////////////////////////////////////////////////////////////
    const int nMinusSig = limMinusSigma.size();
    
//    cout <<"-------------------->   "<<nMinusSig <<"\n\n\n\n";
    
    Double_t massMinusOneSigma[nMinusSig+4];
    Double_t bMinusOneSigma[nMinusSig+4];
    for(int i = 0; i != nMinusSig; ++i) {
        massMinusOneSigma[i] = limMinusSigma[i];
        bMinusOneSigma[i] = betaMinusSigma[i];
//        cout <<"###### exp massMinusOneSigma[i] "<<massMinusOneSigma[i] << "   bMinusOneSigma[i] "<<bMinusOneSigma[i]<<"\n";
    }
    
    massMinusOneSigma[nMinusSig] = massMinusOneSigma[nMinusSig-1];
    bMinusOneSigma[nMinusSig]    = 1;
    
    massMinusOneSigma[nMinusSig+1] = 200;
    bMinusOneSigma[nMinusSig+1]    = 1;
    
    massMinusOneSigma[nMinusSig+2] = 200;
    bMinusOneSigma[nMinusSig+2] = bMinusOneSigma[0];
    
    massMinusOneSigma[nMinusSig+3] = massMinusOneSigma[0];
    bMinusOneSigma[nMinusSig+3] = bMinusOneSigma[0];
    
    
    Double_t NewbMinusOneSigma[nexp+4];
    for(int i = 0; i != nexp+4; ++i) {
        NewbMinusOneSigma[i]=bExp[i]-bMinusOneSigma[i];
        
//        cout<<"  mas comaprison "<<massExp[i]<<"  "<<massMinusOneSigma[i]<<"  "<<massPlusOneSigma[i]<<"\n";
        
    }
    
    //////////////////////////////////////////////////////////////////
    // Observed
    //////////////////////////////////////////////////////////////////
    const int nobs = limObs.size();
    float massObs[nobs+4];
    float bObs[nobs+4];
    for(int i = 0; i != nobs; ++i) {
        massObs[i] = limObs[i];
        bObs[i] = betaObs[i];
//        cout <<"###### obs massObs[i] "<<massObs[i] << "   bObs[i] "<<bObs[i]<<"\n";
    }
    
    massObs[nobs] = massObs[nobs-1];
    bObs[nobs]    = 1;
    
    massObs[nobs+1] = 200;
    bObs[nobs+1]    = 1;

    massObs[nobs+2] = 200;
    bObs[nobs+2] = bObs[0];

    massObs[nobs+3] = massObs[0];
    bObs[nobs+3] = bObs[0];
    
    
    //////////////////////////////////////////////////////////////////
    // TGRAPH
    //////////////////////////////////////////////////////////////////
//    massExp.sort()
    TGraph* grExp = new TGraph(nexp+4, massExp, bExp);
    grExp->Sort(&TGraph::CompareX, 0, 0,-1111);
    
    TGraph* gPlusOneSigma = new TGraph(nplusSig+4, massPlusOneSigma, bPlusOneSigma);
    gPlusOneSigma->Sort(&TGraph::CompareX, 0, 0,-1111);
    
    TGraph* gMinusOneSigma = new TGraph(nMinusSig+4, massMinusOneSigma, bMinusOneSigma);
    gMinusOneSigma->Sort(&TGraph::CompareX, 0, 0,-1111);

    TGraph* grObs = new TGraph(nobs+4, massObs, bObs);
//    grObs->Sort();
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
    pad_plot->SetTickx(1);
    pad_plot->SetTicky(1);
    
    
    
    TH2F* frame = new TH2F("frame", "", 100, 200, 1000, 100, 0.001, 1);
    TAxis* ax = frame->GetXaxis();
    TAxis* ay = frame->GetYaxis();
    ax->SetTitle("M_{LQ} [GeV]");
    //  ax->SetLabelOffset(0.01);
    ay->SetTitle("#beta");
    //ay->SetTitle("#Beta(LQ#rightarrow#tau b)");
    //    ax->SetTitleFont(132);
    ax->SetTitleSize(0.05);
    //    ay->SetTitleFont(132);
    ay->SetTitleSize(0.05);
    ay->SetRangeUser(0.,1);
    frame->Draw();
    
//    grExp->SetLineColor(TColor::GetColor(0, 0, 333));
//    grExp->SetFillColorAlpha(TColor::GetColor(200, 222, 285), 0.65);
    
    
//    grObs->SetLineColor(TColor::GetColor(0, 0, 333));
    grObs->SetFillColorAlpha(TColor::GetColor(200, 222, 285), 0.65);
//    grObs->SetLineColor(kBlack);
    grObs->SetLineWidth(3);
    
    grExp->SetLineColor(kBlack);
    grExp->SetLineWidth(2);
    grExp->SetLineStyle(7);
    //    grObs->SetFillStyle(3005);
    //  grExp->SetLineWidth(2);
    //  grObs->SetLineWidth(2);
    //  grObs->SetFillStyle(3005);
//    grObs->Draw("F");
    
    grExp->Draw("L");
    
//    grExp->Draw("Lsame");
    
    
    

//    gMinusOneSigma->SetLineColor(kBlue);
    gMinusOneSigma->SetLineWidth(0);
//    gMinusOneSigma->SetLineStyle(2);
    ci = TColor::GetColor("#fcf10f");
    gMinusOneSigma->SetFillColorAlpha(15, 0.65);
    gMinusOneSigma->Draw("f");
    
    
//    gPlusOneSigma->SetLineColor(kBlue);
    gPlusOneSigma->SetLineWidth(0);
//    gPlusOneSigma->SetLineStyle(2);
//    ci = TColor::GetColor("#fcf10f");
    gPlusOneSigma->SetFillColor(0);
    gPlusOneSigma->Draw("fsame");
    
    

    
//    gMinusOneSigma->Draw("Lsame");
    grObs->Draw("LSame");
    grObs->Draw("fsame");
//    grExp->Draw("same");
//    frame->Draw("same");
    frame->Draw("sameaxis");

//        grExp->Draw("Lsame");
//    grObs->Draw("fsame");
//
//    Double_t x[5] = {200,300,400,500,600};
//    Double_t y[5] = {5,.1,.9,.7,.5};
//    TPolyLine *pline = new TPolyLine(nexp+4,massExp,bExp);
//    pline->SetFillColor(38);
//    pline->SetLineColor(2);
//    pline->SetLineWidth(4);
//    pline->Draw("f");
//    pline->Draw();
//
    
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
    
    
    
    
    
    

    Double_t Graph0_felx3001[1000] = {0};
    
    Double_t Graph0_fehx3001[1000] = {0};
    
    
    
    
//    for (int i=0;i < 100; i++){
//        
//        cout << "check--->>>>>"<<massExp[i]<<" "<<bExp[i]<<" "<<Graph0_felx3001[i]<<" "<<Graph0_fehx3001[i]<<" "<<NewbMinusOneSigma[i]<<" "<<NewbPlusOneSigma[i]<<"\n";
//    }
    
    
//    const Int_t n = 5;
//    Double_t x[n]   = {200, 250, 300, 350, 400};
//    Double_t y[n]   = {.2,.3,.4,.5,.6};
//    Double_t exl[n] = {0};
//    Double_t exh[n] = {0};
//    Double_t eyl[n] = {.1,.2,.3,.4,.5};
//    Double_t eyh[n] = {.3,.4,.5,.6,.7};
//    TGraphAsymmErrors *grae = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
    
    
    
    TGraphAsymmErrors *grae = new TGraphAsymmErrors(700,massExp,bExp,Graph0_felx3001,Graph0_fehx3001,NewbMinusOneSigma,NewbPlusOneSigma);
    grae->Sort(&TGraph::CompareX, 0, 0,-1111);
    grae->SetName("");
    grae->SetTitle("");
    
    ci = TColor::GetColor("#fcf10f");
    grae->SetFillColorAlpha(ci, 0.65);

//    grae->SetMarkerStyle(20);
    
    
//    TH1F *Graph_Graph3002 = new TH1F("Graph_Graph3002","",100,70,1630);
//    Graph_Graph3002->SetMinimum(0);
//    Graph_Graph3002->SetMaximum(7.043383);
//    Graph_Graph3002->SetDirectory(0);
//    Graph_Graph3002->SetStats(0);
//    Graph_Graph3002->SetLineStyle(0);
//    Graph_Graph3002->SetMarkerStyle(20);
//    Graph_Graph3002->GetXaxis()->SetNdivisions(506);
//    Graph_Graph3002->GetXaxis()->SetLabelFont(42);
//    Graph_Graph3002->GetXaxis()->SetTitleSize(0.05);
//    Graph_Graph3002->GetXaxis()->SetTickLength(0.02);
//    Graph_Graph3002->GetXaxis()->SetTitleOffset(1.08);
//    Graph_Graph3002->GetXaxis()->SetTitleFont(42);
//    Graph_Graph3002->GetYaxis()->SetNdivisions(506);
//    Graph_Graph3002->GetYaxis()->SetLabelFont(42);
//    Graph_Graph3002->GetYaxis()->SetLabelOffset(0.007);
//    Graph_Graph3002->GetYaxis()->SetTitleSize(0.05);
//    Graph_Graph3002->GetYaxis()->SetTickLength(0.02);
//    Graph_Graph3002->GetYaxis()->SetTitleOffset(1.08);
//    Graph_Graph3002->GetYaxis()->SetTitleFont(42);
//    Graph_Graph3002->GetZaxis()->SetNdivisions(506);
//    Graph_Graph3002->GetZaxis()->SetLabelFont(42);
//    Graph_Graph3002->GetZaxis()->SetLabelOffset(0.007);
//    Graph_Graph3002->GetZaxis()->SetTitleSize(0.05);
//    Graph_Graph3002->GetZaxis()->SetTickLength(0.02);
//    Graph_Graph3002->GetZaxis()->SetTitleFont(42);
//    grae->SetHistogram(Graph_Graph3002);
    
//    grae->Draw("3LP");
    
    
    
    //  TLegend* leg = new TLegend(0.50, 0.14, 0.90, 0.35,"CMS 19.7 fb^{-1}, #sqrt{s} = 8 TeV", "brNDC");
    //  TLegend* leg = new TLegend(0.50, 0.14, 0.90, 0.35,"19.7 fb^{-1}, #sqrt{s} = 8 TeV", "brNDC");
    TLegend* leg = new TLegend(0.45, 0.20, 0.8, 0.35,"", "brNDC");
    leg->SetTextFont(42);
    leg->SetTextSize(0.04);
    leg->SetMargin(0.15);
    leg->SetFillColor(0);
    leg->SetBorderSize(0);
    leg->AddEntry(grObs, "Observed exclusion","f");
    leg->AddEntry(grExp, "Median expected limit","L");
    leg->AddEntry(gMinusOneSigma, "68% expected limit","f");
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
