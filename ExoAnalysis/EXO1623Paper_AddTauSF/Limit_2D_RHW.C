#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TGraph.h"
#include "TF1.h"
#include "TLegend.h"
#include "TPolyLine.h"
#include "TPad.h"
#include "TLatex.h"
#include "TMath.h"
#include "stdio.h"
#include "TBox.h"
#include "TPave.h"
#include "TPaveText.h"
#include "TColor.h"
#include "TGraphErrors.h"
#include <TPaletteAxis.h>
#include <iostream>     // std::cout, std::ostream, std::ios
#include <fstream>      // std::filebuf
#include <string>


template <typename T> string tostr(const T& t) {
    ostringstream os;
    os<<t;
    return os.str();
}


void  SayHi(){
    
    std::cout<<"Hi  ---->\n";
};


#include <string>
#include <ostream>
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH1.h"
#include "TH2.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "math.h"
#include "TGaxis.h"
#include "TLegend.h"
#include "TGraph.h"
#include "TGraphAsymmErrors.h"
#include "TInterpreter.h"
#include "TSystem.h"
#include "TNtuple.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include "TFrame.h"
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <utility>
#include <iostream>
#include <map>
#include "TLorentzVector.h"



#include <stdlib.h>



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
    cout<< m1<< "  "<< m2<<"  "<<y11<<"  "<<  y12<<"  "<< y21<<"  "<<  y22<< " ---> m=  "<<  m <<"  \n";
    if ( m > m2 || m < m1 ) return 0;
//    if ( m > m2 ) return 0;
    return m;
}




void Limit_2D_RHW(){
    using namespace std;
    //=========Macro generated from canvas: can2/can2
    //=========  (Wed Oct 14 14:57:25 2015) by ROOT version5.32/04
    //   TCanvas *can2 = new TCanvas("can2", "can2",183,30,800,746);
    TCanvas* can2 = new TCanvas("can2", "can2",850,850);
    SayHi();
    gStyle->SetOptStat(0);
    gStyle->SetOptTitle(0);
    can2->Range(-20.96775,-3.205128,785.4839,48.07692);
    can2->SetFillColor(0);
    can2->SetBorderMode(0);
    can2->SetBorderSize(2);
    can2->SetTickx(1);
    can2->SetTicky(1);
    
    can2->SetBottomMargin(0.16);
    
    can2->SetLeftMargin(0.15);
    
    can2->SetRightMargin(0.23);
    
    can2->SetTopMargin(0.06);
    
    can2->SetFrameFillColor(1);
    can2->SetFrameFillStyle(0);
    can2->SetFrameLineStyle(0);
    can2->SetFrameBorderMode(0);
    can2->SetFrameFillColor(1);
    can2->SetFrameFillStyle(0);
    can2->SetFrameLineStyle(0);
    can2->SetFrameBorderMode(0);
    can2->SetLogz();
    
    
    
    
    //    hlimitxsec2->SetBinContent(1,1,32.71484375); //1500-1000
    //    hlimitxsec2->SetBinContent(1,2,37.59765625); //1500-1250
    //
    //    hlimitxsec2->SetBinContent(2,1,14.16015625); //2000-1000
    //    hlimitxsec2->SetBinContent(2,2,13.18359375); //2000-1250
    //    hlimitxsec2->SetBinContent(2,3,13.18359375); //2000-1500
    //    hlimitxsec2->SetBinContent(2,4,15.13671875);  //2000-1750
    //
    //    hlimitxsec2->SetBinContent(3,1,7.32421875);  //2500-1000
    //    hlimitxsec2->SetBinContent(3,2,7.32421875); //2500-1250
    //    hlimitxsec2->SetBinContent(3,3,6.34765625); //2500-1500
    //    hlimitxsec2->SetBinContent(3,4,6.34765625); //2500-1750
    //    hlimitxsec2->SetBinContent(3,5,6.34765625); //2500-2000
    //    hlimitxsec2->SetBinContent(3,6,7.32421875); //2500-2250
    //
    //    hlimitxsec2->SetBinContent(4,1,5.37109375); //3000-1000
    //    hlimitxsec2->SetBinContent(4,2,4.39453125); //3000-1250
    //    hlimitxsec2->SetBinContent(4,3,4.39453125); //3000-1500
    //    hlimitxsec2->SetBinContent(4,4,4.39453125); //3000-1750
    //    hlimitxsec2->SetBinContent(4,5,3.41796875); //3000-2000
    //    hlimitxsec2->SetBinContent(4,6,3.41796875);  //3000-2250
    //    hlimitxsec2->SetBinContent(4,7,3.41796875); //3000-2500
    //    hlimitxsec2->SetBinContent(4,8,4.39453125); //3000-2750
    //
    //
    //    hlimitxsec2->SetBinContent(5,1,4.39453125); //3500-1000
    //    hlimitxsec2->SetBinContent(5,2,3.41796875); //3500-1250
    //    hlimitxsec2->SetBinContent(5,3,3.41796875); //3500-1500
    //    hlimitxsec2->SetBinContent(5,4,3.41796875); //3500-1750
    //    hlimitxsec2->SetBinContent(5,5,3.41796875); //3500-2000
    //    hlimitxsec2->SetBinContent(5,6,2.44140625);  //3500-2250
    //    hlimitxsec2->SetBinContent(5,7,2.44140625); //3500-2500
    //    hlimitxsec2->SetBinContent(5,8,2.44140625); //3500-2750
    //    hlimitxsec2->SetBinContent(5,9,3.41796875); //3500-3000
    //    hlimitxsec2->SetBinContent(5,10,3.41796875); //3500-3250
    //
    //
    //    hlimitxsec2->SetBinContent(6,1,4.39453125); //4000-1000
    //    hlimitxsec2->SetBinContent(6,2,3.41796875); //4000-1250
    //    hlimitxsec2->SetBinContent(6,3,2.44140625); //4000-1500
    //    hlimitxsec2->SetBinContent(6,4,2.44140625); //4000-1750
    //    hlimitxsec2->SetBinContent(6,5,2.44140625); //4000-2000
    //    hlimitxsec2->SetBinContent(6,6,2.44140625);  //4000-2250
    //    hlimitxsec2->SetBinContent(6,7,2.44140625); //4000-2500
    //    hlimitxsec2->SetBinContent(6,8,2.44140625); //4000-2750
    //    hlimitxsec2->SetBinContent(6,9,2.44140625); //4000-3000
    //    hlimitxsec2->SetBinContent(6,10,2.44140625); //4000-3250
    //    hlimitxsec2->SetBinContent(6,11,2.44140625); //4000-3500
    //    hlimitxsec2->SetBinContent(6,12,3.41796875); //4000-3750
    
    
//    
//    
//    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",6,1250,4250,12,875,3875);
//    hlimitxsec2->SetBinContent( 1 , 1 , 34.2712402344 ); // 1500_MNu-1000
//    hlimitxsec2->SetBinContent( 1 , 2 , 40.0085449219 ); // 1500_MNu-1250
//    hlimitxsec2->SetBinContent( 2 , 1 , 14.8696899414 ); // 2000_MNu-1000
//    hlimitxsec2->SetBinContent( 2 , 2 , 14.1830444336 ); // 2000_MNu-1250
//    hlimitxsec2->SetBinContent( 2 , 3 , 13.3666992188 ); // 2000_MNu-1500
//    hlimitxsec2->SetBinContent( 2 , 4 , 15.6097412109 ); // 2000_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 1 , 8.20922851562 ); // 2500_MNu-1000
//    hlimitxsec2->SetBinContent( 3 , 2 , 7.42340087891 ); // 2500_MNu-1250
//    hlimitxsec2->SetBinContent( 3 , 3 , 6.93893432617 ); // 2500_MNu-1500
//    hlimitxsec2->SetBinContent( 3 , 4 , 6.86645507812 ); // 2500_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 5 , 6.87026977539 ); // 2500_MNu-2000
//    hlimitxsec2->SetBinContent( 3 , 6 , 7.58743286133 ); // 2500_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 1 , 5.32150268555 ); // 3000_MNu-1000
//    hlimitxsec2->SetBinContent( 4 , 2 , 4.7492980957 ); // 3000_MNu-1250
//    hlimitxsec2->SetBinContent( 4 , 3 , 4.4059753418 ); // 3000_MNu-1500
//    hlimitxsec2->SetBinContent( 4 , 4 , 4.22286987305 ); // 3000_MNu-1750
//    hlimitxsec2->SetBinContent( 4 , 5 , 3.90243530273 ); // 3000_MNu-2000
//    hlimitxsec2->SetBinContent( 4 , 6 , 3.95584106445 ); // 3000_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 7 , 4.02450561523 ); // 3000_MNu-2500
//    hlimitxsec2->SetBinContent( 4 , 8 , 4.72640991211 ); // 3000_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 1 , 4.40979003906 ); // 3500_MNu-1000
//    hlimitxsec2->SetBinContent( 5 , 2 , 3.73649597168 ); // 3500_MNu-1250
//    hlimitxsec2->SetBinContent( 5 , 3 , 3.40843200684 ); // 3500_MNu-1500
//    hlimitxsec2->SetBinContent( 5 , 4 , 3.22151184082 ); // 3500_MNu-1750
//    hlimitxsec2->SetBinContent( 5 , 5 , 3.02886962891 ); // 3500_MNu-2000
//    hlimitxsec2->SetBinContent( 5 , 6 , 2.96592712402 ); // 3500_MNu-2250
//    hlimitxsec2->SetBinContent( 5 , 7 , 2.90489196777 ); // 3500_MNu-2500
//    hlimitxsec2->SetBinContent( 5 , 8 , 3.00788879395 ); // 3500_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 9 , 3.11088562012 ); // 3500_MNu-3000
//    hlimitxsec2->SetBinContent( 5 , 10 , 3.68118286133 ); // 3500_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 1 , 4.18090820312 ); // 4000_MNu-1000
//    hlimitxsec2->SetBinContent( 6 , 2 , 3.4351348877 ); // 4000_MNu-1250
//    hlimitxsec2->SetBinContent( 6 , 3 , 3.00407409668 ); // 4000_MNu-1500
//    hlimitxsec2->SetBinContent( 6 , 4 , 2.85911560059 ); // 4000_MNu-1750
//    hlimitxsec2->SetBinContent( 6 , 5 , 2.70462036133 ); // 4000_MNu-2000
//    hlimitxsec2->SetBinContent( 6 , 6 , 2.57110595703 ); // 4000_MNu-2250
//    hlimitxsec2->SetBinContent( 6 , 7 , 2.49862670898 ); // 4000_MNu-2500
//    hlimitxsec2->SetBinContent( 6 , 8 , 2.5577545166 ); // 4000_MNu-2750
//    hlimitxsec2->SetBinContent( 6 , 9 , 2.53105163574 ); // 4000_MNu-3000
//    hlimitxsec2->SetBinContent( 6 , 10 , 2.59208679199 ); // 4000_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 11 , 2.77328491211 ); // 4000_MNu-3500
//    hlimitxsec2->SetBinContent( 6 , 12 , 3.2787322998 ); // 4000_MNu-3750
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
//    ExpctedExclusionLimit->SetBinContent( 1 , 1 , 0.118176690463 ); // 1500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 1 , 2 , 0.137960499731 ); // 1500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 2 , 1 , 0.226568489127 ); // 2000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 2 , 2 , 0.216106116617 ); // 2000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 2 , 3 , 0.203667518189 ); // 2000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 2 , 4 , 0.237844601721 ); // 2000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 3 , 1 , 0.427563985189 ); // 2500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 3 , 2 , 0.386635462443 ); // 2500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 3 , 3 , 0.361402829488 ); // 2500_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 3 , 4 , 0.357627868652 ); // 2500_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 3 , 5 , 0.357826550802 ); // 2500_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 3 , 6 , 0.395178794861 ); // 2500_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 4 , 1 , 0.882504591301 ); // 3000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 4 , 2 , 0.787611624495 ); // 3000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 4 , 3 , 0.730675844411 ); // 3000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 4 , 4 , 0.700310095033 ); // 3000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 4 , 5 , 0.647170033621 ); // 3000_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 4 , 6 , 0.656026710523 ); // 3000_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 4 , 7 , 0.66741386654 ); // 3000_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 4 , 8 , 0.783815905822 ); // 3000_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 5 , 1 , 2.10994738711 ); // 3500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 5 , 2 , 1.78779711564 ); // 3500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 5 , 3 , 1.6308287114 ); // 3500_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 5 , 4 , 1.54139322527 ); // 3500_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 5 , 5 , 1.44921991814 ); // 3500_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 5 , 6 , 1.41910388709 ); // 3500_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 5 , 7 , 1.38990046305 ); // 3500_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 5 , 8 , 1.43918124112 ); // 3500_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 5 , 9 , 1.48846201919 ); // 3500_MNu-3000
//    ExpctedExclusionLimit->SetBinContent( 5 , 10 , 1.7613315126 ); // 3500_MNu-3250
//    ExpctedExclusionLimit->SetBinContent( 6 , 1 , 5.21961074048 ); // 4000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 6 , 2 , 4.28855791223 ); // 4000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 6 , 3 , 3.75040461508 ); // 4000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 6 , 4 , 3.56943270985 ); // 4000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 6 , 5 , 3.37655475821 ); // 4000_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 6 , 6 , 3.20987010865 ); // 4000_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 6 , 7 , 3.11938415604 ); // 4000_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 6 , 8 , 3.1932016437 ); // 4000_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 6 , 9 , 3.15986471379 ); // 4000_MNu-3000
//    ExpctedExclusionLimit->SetBinContent( 6 , 10 , 3.23606341073 ); // 4000_MNu-3250
//    ExpctedExclusionLimit->SetBinContent( 6 , 11 , 3.46227829227 ); // 4000_MNu-3500
//    ExpctedExclusionLimit->SetBinContent( 6 , 12 , 4.09329875132 ); // 4000_MNu-3750
//    
//    
//    
//    
//    
//    
//    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
//    ObservedExclusionLimit->SetBinContent( 1 , 1 , 0.0894773265131 ); // 1500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 1 , 2 , 0.0995421178147 ); // 1500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 2 , 1 , 0.217437661516 ); // 2000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 2 , 2 , 0.214086103273 ); // 2000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 2 , 3 , 0.21403374328 ); // 2000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 2 , 4 , 0.253664371739 ); // 2000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 3 , 1 , 0.472444317097 ); // 2500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 3 , 2 , 0.423123292611 ); // 2500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 3 , 3 , 0.397295032609 ); // 2500_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 3 , 4 , 0.402149820067 ); // 2500_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 3 , 5 , 0.385687606383 ); // 2500_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 3 , 6 , 0.427974740674 ); // 2500_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 4 , 1 , 0.92404447683 ); // 3000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 4 , 2 , 0.861305458568 ); // 3000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 4 , 3 , 0.792349262876 ); // 3000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 4 , 4 , 0.754348734763 ); // 3000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 4 , 5 , 0.688449734731 ); // 3000_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 4 , 6 , 0.696938225749 ); // 3000_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 4 , 7 , 0.708457091858 ); // 3000_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 4 , 8 , 0.830278411978 ); // 3000_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 5 , 1 , 2.26342801309 ); // 3500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 5 , 2 , 1.90752001227 ); // 3500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 5 , 3 , 1.73984804292 ); // 3500_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 5 , 4 , 1.69266492288 ); // 3500_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 5 , 5 , 1.53132413718 ); // 3500_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 5 , 6 , 1.52054319494 ); // 3500_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 5 , 7 , 1.464077786 ); // 3500_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 5 , 8 , 1.51620971822 ); // 3500_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 5 , 9 , 1.55906603276 ); // 3500_MNu-3000
//    ObservedExclusionLimit->SetBinContent( 5 , 10 , 1.87715991409 ); // 3500_MNu-3250
//    ObservedExclusionLimit->SetBinContent( 6 , 1 , 5.49617498868 ); // 4000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 6 , 2 , 4.48336278166 ); // 4000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 6 , 3 , 3.98066827591 ); // 4000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 6 , 4 , 3.86094330831 ); // 4000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 6 , 5 , 3.56422583263 ); // 4000_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 6 , 6 , 3.38592190669 ); // 4000_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 6 , 7 , 3.27327788319 ); // 4000_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 6 , 8 , 3.38070716554 ); // 4000_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 6 , 9 , 3.3033928981 ); // 4000_MNu-3000
//    ObservedExclusionLimit->SetBinContent( 6 , 10 , 3.47023394456 ); // 4000_MNu-3250
//    ObservedExclusionLimit->SetBinContent( 6 , 11 , 3.65772802097 ); // 4000_MNu-3500
//    ObservedExclusionLimit->SetBinContent( 6 , 12 , 4.32486001676 ); // 4000_MNu-3750
//    
//    
    
    
    
    
    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",6,1250,4250,12,875,3875);
    hlimitxsec2->SetBinContent( 1 , 1 , 36.7736816406 ); // 1500_MNu-1000
    hlimitxsec2->SetBinContent( 1 , 2 , 42.2058105469 ); // 1500_MNu-1250
    hlimitxsec2->SetBinContent( 2 , 1 , 17.0440673828 ); // 2000_MNu-1000
    hlimitxsec2->SetBinContent( 2 , 2 , 15.8233642578 ); // 2000_MNu-1250
    hlimitxsec2->SetBinContent( 2 , 3 , 14.6179199219 ); // 2000_MNu-1500
    hlimitxsec2->SetBinContent( 2 , 4 , 16.7083740234 ); // 2000_MNu-1750
    hlimitxsec2->SetBinContent( 3 , 1 , 10.1013183594 ); // 2500_MNu-1000
    hlimitxsec2->SetBinContent( 3 , 2 , 8.92639160156 ); // 2500_MNu-1250
    hlimitxsec2->SetBinContent( 3 , 3 , 8.17108154297 ); // 2500_MNu-1500
    hlimitxsec2->SetBinContent( 3 , 4 , 7.88116455078 ); // 2500_MNu-1750
    hlimitxsec2->SetBinContent( 3 , 5 , 7.63702392578 ); // 2500_MNu-2000
    hlimitxsec2->SetBinContent( 3 , 6 , 8.30841064453 ); // 2500_MNu-2250
    hlimitxsec2->SetBinContent( 4 , 1 , 7.32040405273 ); // 3000_MNu-1000
    hlimitxsec2->SetBinContent( 4 , 2 , 6.25228881836 ); // 3000_MNu-1250
    hlimitxsec2->SetBinContent( 4 , 3 , 5.58853149414 ); // 3000_MNu-1500
    hlimitxsec2->SetBinContent( 4 , 4 , 5.22232055664 ); // 3000_MNu-1750
    hlimitxsec2->SetBinContent( 4 , 5 , 4.71878051758 ); // 3000_MNu-2000
    hlimitxsec2->SetBinContent( 4 , 6 , 4.61196899414 ); // 3000_MNu-2250
    hlimitxsec2->SetBinContent( 4 , 7 , 4.54330444336 ); // 3000_MNu-2500
    hlimitxsec2->SetBinContent( 4 , 8 , 5.24520874023 ); // 3000_MNu-2750
    hlimitxsec2->SetBinContent( 5 , 1 , 6.8244934082 ); // 3500_MNu-1000
    hlimitxsec2->SetBinContent( 5 , 2 , 5.42068481445 ); // 3500_MNu-1250
    hlimitxsec2->SetBinContent( 5 , 3 , 4.80270385742 ); // 3500_MNu-1500
    hlimitxsec2->SetBinContent( 5 , 4 , 4.37164306641 ); // 3500_MNu-1750
    hlimitxsec2->SetBinContent( 5 , 5 , 4.00924682617 ); // 3500_MNu-2000
    hlimitxsec2->SetBinContent( 5 , 6 , 3.7784576416 ); // 3500_MNu-2250
    hlimitxsec2->SetBinContent( 5 , 7 , 3.58581542969 ); // 3500_MNu-2500
    hlimitxsec2->SetBinContent( 5 , 8 , 3.61824035645 ); // 3500_MNu-2750
    hlimitxsec2->SetBinContent( 5 , 9 , 3.61251831055 ); // 3500_MNu-3000
    hlimitxsec2->SetBinContent( 5 , 10 , 4.18472290039 ); // 3500_MNu-3250
    hlimitxsec2->SetBinContent( 6 , 1 , 7.38143920898 ); // 4000_MNu-1000
    hlimitxsec2->SetBinContent( 6 , 2 , 5.69152832031 ); // 4000_MNu-1250
    hlimitxsec2->SetBinContent( 6 , 3 , 4.81414794922 ); // 4000_MNu-1500
    hlimitxsec2->SetBinContent( 6 , 4 , 4.32586669922 ); // 4000_MNu-1750
    hlimitxsec2->SetBinContent( 6 , 5 , 3.96347045898 ); // 4000_MNu-2000
    hlimitxsec2->SetBinContent( 6 , 6 , 3.68118286133 ); // 4000_MNu-2250
    hlimitxsec2->SetBinContent( 6 , 7 , 3.44657897949 ); // 4000_MNu-2500
    hlimitxsec2->SetBinContent( 6 , 8 , 3.40270996094 ); // 4000_MNu-2750
    hlimitxsec2->SetBinContent( 6 , 9 , 3.27491760254 ); // 4000_MNu-3000
    hlimitxsec2->SetBinContent( 6 , 10 , 3.21388244629 ); // 4000_MNu-3250
    hlimitxsec2->SetBinContent( 6 , 11 , 3.34358215332 ); // 4000_MNu-3500
    hlimitxsec2->SetBinContent( 6 , 12 , 3.86428833008 ); // 4000_MNu-3750
    
    
    
    
    
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent( 1 , 1 , 0.126805798761 ); // 1500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 1 , 2 , 0.145537277748 ); // 1500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 1 , 0.259699335408 ); // 2000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 2 , 2 , 0.241099562057 ); // 2000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 3 , 0.222732285873 ); // 2000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 2 , 4 , 0.254584397736 ); // 2000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 1 , 0.526110331217 ); // 2500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 3 , 2 , 0.464916229248 ); // 2500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 3 , 3 , 0.425577163696 ); // 2500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 3 , 4 , 0.410477320353 ); // 2500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 5 , 0.397761662801 ); // 2500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 3 , 6 , 0.432729721069 ); // 2500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 1 , 1.21399735535 ); // 3000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 4 , 2 , 1.03686381731 ); // 3000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 4 , 3 , 0.926787975811 ); // 3000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 4 , 4 , 0.866056477055 ); // 3000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 4 , 5 , 0.782550666265 ); // 3000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 4 , 6 , 0.764837312461 ); // 3000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 7 , 0.753450156444 ); // 3000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 4 , 8 , 0.869852195727 ); // 3000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 1 , 3.26530785081 ); // 3500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 5 , 2 , 2.59362909782 ); // 3500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 5 , 3 , 2.29794442939 ); // 3500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 5 , 4 , 2.09169524708 ); // 3500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 5 , 5 , 1.91829991683 ); // 3500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 5 , 6 , 1.80787446967 ); // 3500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 5 , 7 , 1.71570116253 ); // 3500_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 5 , 8 , 1.73121548155 ); // 3500_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 9 , 1.72847766055 ); // 3500_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 5 , 10 , 2.00225976095 ); // 3500_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 1 , 9.21527991134 ); // 4000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 6 , 2 , 7.10552848978 ); // 4000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 6 , 3 , 6.01017222125 ); // 4000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 6 , 4 , 5.40058264572 ); // 4000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 6 , 5 , 4.94815288263 ); // 4000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 6 , 6 , 4.59573390927 ); // 4000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 6 , 7 , 4.30284516791 ); // 4000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 6 , 8 , 4.24807735448 ); // 4000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 6 , 9 , 4.08853633276 ); // 4000_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 6 , 10 , 4.01233763582 ); // 4000_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 11 , 4.17425986682 ); // 4000_MNu-3500
    ExpctedExclusionLimit->SetBinContent( 6 , 12 , 4.8243300001 ); // 4000_MNu-3750
    
    
    
    
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent( 1 , 1 , 0.0950307813835 ); // 1500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 1 , 2 , 0.10411667902 ); // 1500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 1 , 0.261020243298 ); // 2000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 2 , 2 , 0.246039425294 ); // 2000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 3 , 0.242039646103 ); // 2000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 2 , 4 , 0.280198430338 ); // 2000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 1 , 0.627917893487 ); // 2500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 3 , 2 , 0.548818389725 ); // 2500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 3 , 3 , 0.503434819895 ); // 2500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 3 , 4 , 0.49001636764 ); // 2500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 5 , 0.447376110257 ); // 2500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 3 , 6 , 0.482911528781 ); // 2500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 1 , 1.37117271551 ); // 3000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 4 , 2 , 1.19948551417 ); // 3000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 4 , 3 , 1.06336148981 ); // 3000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 4 , 4 , 0.982686014038 ); // 3000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 4 , 5 , 0.86955472597 ); // 3000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 4 , 6 , 0.839443716863 ); // 3000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 7 , 0.818356396888 ); // 3000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 4 , 8 , 0.936254041373 ); // 3000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 1 , 3.80769703634 ); // 3500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 5 , 2 , 2.96112011129 ); // 3500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 5 , 3 , 2.60040562123 ); // 3500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 5 , 4 , 2.39352890711 ); // 3500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 5 , 5 , 2.10939712902 ); // 3500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 5 , 6 , 2.0032994527 ); // 3500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 5 , 7 , 1.85492759262 ); // 3500_MNu-2500
    ObservedExclusionLimit->SetBinContent( 5 , 8 , 1.86335874013 ); // 3500_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 9 , 1.84123123965 ); // 3500_MNu-3000
    ObservedExclusionLimit->SetBinContent( 5 , 10 , 2.16386453388 ); // 3500_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 1 , 10.8314092636 ); // 4000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 6 , 2 , 8.06335449207 ); // 4000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 6 , 3 , 6.85797626702 ); // 4000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 6 , 4 , 6.22107128551 ); // 4000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 6 , 5 , 5.46303578685 ); // 4000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 6 , 6 , 5.051333824 ); // 4000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 6 , 7 , 4.66172013909 ); // 4000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 6 , 8 , 4.62821358741 ); // 4000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 6 , 9 , 4.40761294997 ); // 4000_MNu-3000
    ObservedExclusionLimit->SetBinContent( 6 , 10 , 4.39137604584 ); // 4000_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 11 , 4.50247326165 ); // 4000_MNu-3500
    ObservedExclusionLimit->SetBinContent( 6 , 12 , 5.1747618871 ); // 4000_MNu-3750
    
    
    
//    
//    
//    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",6,1250,4250,12,875,3875);
//    hlimitxsec2->SetBinContent( 1 , 1 , 36.7737 ); // 1500_MNu-1000
//    hlimitxsec2->SetBinContent( 1 , 2 , 42.2058 ); // 1500_MNu-1250
//    hlimitxsec2->SetBinContent( 2 , 1 , 17.0441 ); // 2000_MNu-1000
//    hlimitxsec2->SetBinContent( 2 , 2 , 15.8234 ); // 2000_MNu-1250
//    hlimitxsec2->SetBinContent( 2 , 3 , 14.6179 ); // 2000_MNu-1500
//    hlimitxsec2->SetBinContent( 2 , 4 , 16.7084 ); // 2000_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 1 , 10.1013 ); // 2500_MNu-1000
//    hlimitxsec2->SetBinContent( 3 , 2 , 8.92639 ); // 2500_MNu-1250
//    hlimitxsec2->SetBinContent( 3 , 3 , 8.17108 ); // 2500_MNu-1500
//    hlimitxsec2->SetBinContent( 3 , 4 , 7.88116 ); // 2500_MNu-1750
//    hlimitxsec2->SetBinContent( 3 , 5 , 7.63702 ); // 2500_MNu-2000
//    hlimitxsec2->SetBinContent( 3 , 6 , 8.30841 ); // 2500_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 1 , 7.3204 ); // 3000_MNu-1000
//    hlimitxsec2->SetBinContent( 4 , 2 , 6.25229 ); // 3000_MNu-1250
//    hlimitxsec2->SetBinContent( 4 , 3 , 5.58853 ); // 3000_MNu-1500
//    hlimitxsec2->SetBinContent( 4 , 4 , 5.22232 ); // 3000_MNu-1750
//    hlimitxsec2->SetBinContent( 4 , 5 , 4.71878 ); // 3000_MNu-2000
//    hlimitxsec2->SetBinContent( 4 , 6 , 4.61197 ); // 3000_MNu-2250
//    hlimitxsec2->SetBinContent( 4 , 7 , 4.5433 ); // 3000_MNu-2500
//    hlimitxsec2->SetBinContent( 4 , 8 , 5.24521 ); // 3000_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 1 , 6.82449 ); // 3500_MNu-1000
//    hlimitxsec2->SetBinContent( 5 , 2 , 5.42068 ); // 3500_MNu-1250
//    hlimitxsec2->SetBinContent( 5 , 3 , 4.8027 ); // 3500_MNu-1500
//    hlimitxsec2->SetBinContent( 5 , 4 , 4.37164 ); // 3500_MNu-1750
//    hlimitxsec2->SetBinContent( 5 , 5 , 4.00925 ); // 3500_MNu-2000
//    hlimitxsec2->SetBinContent( 5 , 6 , 3.77846 ); // 3500_MNu-2250
//    hlimitxsec2->SetBinContent( 5 , 7 , 3.58582 ); // 3500_MNu-2500
//    hlimitxsec2->SetBinContent( 5 , 8 , 3.61824 ); // 3500_MNu-2750
//    hlimitxsec2->SetBinContent( 5 , 9 , 3.61252 ); // 3500_MNu-3000
//    hlimitxsec2->SetBinContent( 5 , 10 , 4.18472 ); // 3500_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 1 , 8.85773 ); // 4000_MNu-1000
//    hlimitxsec2->SetBinContent( 6 , 2 , 6.82983 ); // 4000_MNu-1250
//    hlimitxsec2->SetBinContent( 6 , 3 , 4.81415 ); // 4000_MNu-1500
//    hlimitxsec2->SetBinContent( 6 , 4 , 4.32587 ); // 4000_MNu-1750
//    hlimitxsec2->SetBinContent( 6 , 5 , 3.96347 ); // 4000_MNu-2000
//    hlimitxsec2->SetBinContent( 6 , 6 , 4.41742 ); // 4000_MNu-2250
//    hlimitxsec2->SetBinContent( 6 , 7 , 3.44658 ); // 4000_MNu-2500
//    hlimitxsec2->SetBinContent( 6 , 8 , 3.40271 ); // 4000_MNu-2750
//    hlimitxsec2->SetBinContent( 6 , 9 , 3.27492 ); // 4000_MNu-3000
//    hlimitxsec2->SetBinContent( 6 , 10 , 3.21388 ); // 4000_MNu-3250
//    hlimitxsec2->SetBinContent( 6 , 11 , 3.34358 ); // 4000_MNu-3500
//    hlimitxsec2->SetBinContent( 6 , 12 , 3.86429 ); // 4000_MNu-3750
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
//    ExpctedExclusionLimit->SetBinContent( 1 , 1 , 0.126805862069 ); // 1500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 1 , 2 , 0.145537241379 ); // 1500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 2 , 1 , 0.259699832394 ); // 2000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 2 , 2 , 0.241100106659 ); // 2000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 2 , 3 , 0.222731982325 ); // 2000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 2 , 4 , 0.25458479354 ); // 2000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 3 , 1 , 0.526109375 ); // 2500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 3 , 2 , 0.464916145833 ); // 2500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 3 , 3 , 0.425577083333 ); // 2500_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 3 , 4 , 0.410477083333 ); // 2500_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 3 , 5 , 0.397761458333 ); // 2500_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 3 , 6 , 0.4327296875 ); // 2500_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 4 , 1 , 1.21399668325 ); // 3000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 4 , 2 , 1.03686401327 ); // 3000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 4 , 3 , 0.926787728027 ); // 3000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 4 , 4 , 0.866056384743 ); // 3000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 4 , 5 , 0.782550580431 ); // 3000_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 4 , 6 , 0.76483747927 ); // 3000_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 4 , 7 , 0.753449419569 ); // 3000_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 4 , 8 , 0.869852404643 ); // 3000_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 5 , 1 , 3.2653062201 ); // 3500_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 5 , 2 , 2.59362679426 ); // 3500_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 5 , 3 , 2.29794258373 ); // 3500_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 5 , 4 , 2.0916937799 ); // 3500_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 5 , 5 , 1.91830143541 ); // 3500_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 5 , 6 , 1.80787559809 ); // 3500_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 5 , 7 , 1.71570334928 ); // 3500_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 5 , 8 , 1.731215311 ); // 3500_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 5 , 9 , 1.7284784689 ); // 3500_MNu-3000
//    ExpctedExclusionLimit->SetBinContent( 5 , 10 , 2.00225837321 ); // 3500_MNu-3250
//    ExpctedExclusionLimit->SetBinContent( 6 , 1 , 11.0583395755 ); // 4000_MNu-1000
//    ExpctedExclusionLimit->SetBinContent( 6 , 2 , 8.52662921348 ); // 4000_MNu-1250
//    ExpctedExclusionLimit->SetBinContent( 6 , 3 , 6.01017478152 ); // 4000_MNu-1500
//    ExpctedExclusionLimit->SetBinContent( 6 , 4 , 5.40058676654 ); // 4000_MNu-1750
//    ExpctedExclusionLimit->SetBinContent( 6 , 5 , 4.94815230961 ); // 4000_MNu-2000
//    ExpctedExclusionLimit->SetBinContent( 6 , 6 , 5.51488139825 ); // 4000_MNu-2250
//    ExpctedExclusionLimit->SetBinContent( 6 , 7 , 4.30284644195 ); // 4000_MNu-2500
//    ExpctedExclusionLimit->SetBinContent( 6 , 8 , 4.24807740325 ); // 4000_MNu-2750
//    ExpctedExclusionLimit->SetBinContent( 6 , 9 , 4.08853932584 ); // 4000_MNu-3000
//    ExpctedExclusionLimit->SetBinContent( 6 , 10 , 4.01233458177 ); // 4000_MNu-3250
//    ExpctedExclusionLimit->SetBinContent( 6 , 11 , 4.17425717853 ); // 4000_MNu-3500
//    ExpctedExclusionLimit->SetBinContent( 6 , 12 , 4.82433208489 ); // 4000_MNu-3750
//    
//    
//    
//    
//    
//    
//    
//    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
//    ObservedExclusionLimit->SetBinContent( 1 , 1 , 0.101444482759 ); // 1500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 1 , 2 , 0.116429655172 ); // 1500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 2 , 1 , 0.259699832394 ); // 2000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 2 , 2 , 0.289318909036 ); // 2000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 2 , 3 , 0.267278683529 ); // 2000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 2 , 4 , 0.305500533293 ); // 2000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 3 , 1 , 0.631333333333 ); // 2500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 3 , 2 , 0.557901041667 ); // 2500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 3 , 3 , 0.510692708333 ); // 2500_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 3 , 4 , 0.574666666667 ); // 2500_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 3 , 5 , 0.4773140625 ); // 2500_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 3 , 6 , 0.519275520833 ); // 2500_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 4 , 1 , 1.4567960199 ); // 3000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 4 , 2 , 1.45160862355 ); // 3000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 4 , 3 , 1.29750248756 ); // 3000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 4 , 4 , 1.03926699834 ); // 3000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 4 , 5 , 0.939061359867 ); // 3000_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 4 , 6 , 0.917804311774 ); // 3000_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 4 , 7 , 0.904140961857 ); // 3000_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 4 , 8 , 1.0438225539 ); // 3000_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 5 , 1 , 4.57143062201 ); // 3500_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 5 , 2 , 3.63108133971 ); // 3500_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 5 , 3 , 3.21712440191 ); // 3500_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 5 , 4 , 2.92837320574 ); // 3500_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 5 , 5 , 2.30196172249 ); // 3500_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 5 , 6 , 2.16944976077 ); // 3500_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 5 , 7 , 2.05884210526 ); // 3500_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 5 , 8 , 2.07745933014 ); // 3500_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 5 , 9 , 2.0741722488 ); // 3500_MNu-3000
//    ObservedExclusionLimit->SetBinContent( 5 , 10 , 2.40271291866 ); // 3500_MNu-3250
//    ObservedExclusionLimit->SetBinContent( 6 , 1 , 14.7444444444 ); // 4000_MNu-1000
//    ObservedExclusionLimit->SetBinContent( 6 , 2 , 9.94774032459 ); // 4000_MNu-1250
//    ObservedExclusionLimit->SetBinContent( 6 , 3 , 8.41424469413 ); // 4000_MNu-1500
//    ObservedExclusionLimit->SetBinContent( 6 , 4 , 7.56081148564 ); // 4000_MNu-1750
//    ObservedExclusionLimit->SetBinContent( 6 , 5 , 6.92741573034 ); // 4000_MNu-2000
//    ObservedExclusionLimit->SetBinContent( 6 , 6 , 6.43403245943 ); // 4000_MNu-2250
//    ObservedExclusionLimit->SetBinContent( 6 , 7 , 5.1634082397 ); // 4000_MNu-2500
//    ObservedExclusionLimit->SetBinContent( 6 , 8 , 5.09769038702 ); // 4000_MNu-2750
//    ObservedExclusionLimit->SetBinContent( 6 , 9 , 4.90624219725 ); // 4000_MNu-3000
//    ObservedExclusionLimit->SetBinContent( 6 , 10 , 4.81480649189 ); // 4000_MNu-3250
//    ObservedExclusionLimit->SetBinContent( 6 , 11 , 5.00911360799 ); // 4000_MNu-3500
//    ObservedExclusionLimit->SetBinContent( 6 , 12 , 5.78920099875 ); // 4000_MNu-3750
    
    
    

    /*
    TH2D *hlimitxsec2 = new TH2D("hlimitxsec2","hlimitxsec2",6,1250,4250,12,875,3875);
    hlimitxsec2->SetBinContent( 1 , 1 , 32.6232910156 ); // 1500_MNu-1000
    hlimitxsec2->SetBinContent( 1 , 2 , 38.0249023438 ); // 1500_MNu-1250
    hlimitxsec2->SetBinContent( 2 , 1 , 14.16015625 ); // 2000_MNu-1000
    hlimitxsec2->SetBinContent( 2 , 2 , 13.5498046875 ); // 2000_MNu-1250
    hlimitxsec2->SetBinContent( 2 , 3 , 12.7563476562 ); // 2000_MNu-1500
    hlimitxsec2->SetBinContent( 2 , 4 , 14.9002075195 ); // 2000_MNu-1750
    hlimitxsec2->SetBinContent( 3 , 1 , 7.80487060547 ); // 2500_MNu-1000
    hlimitxsec2->SetBinContent( 3 , 2 , 7.06481933594 ); // 2500_MNu-1250
    hlimitxsec2->SetBinContent( 3 , 3 , 6.6032409668 ); // 2500_MNu-1500
    hlimitxsec2->SetBinContent( 3 , 4 , 6.54983520508 ); // 2500_MNu-1750
    hlimitxsec2->SetBinContent( 3 , 5 , 6.53457641602 ); // 2500_MNu-2000
    hlimitxsec2->SetBinContent( 3 , 6 , 7.23648071289 ); // 2500_MNu-2250
    hlimitxsec2->SetBinContent( 4 , 1 , 5.06591796875 ); // 3000_MNu-1000
    hlimitxsec2->SetBinContent( 4 , 2 , 4.52041625977 ); // 3000_MNu-1250
    hlimitxsec2->SetBinContent( 4 , 3 , 4.18472290039 ); // 3000_MNu-1500
    hlimitxsec2->SetBinContent( 4 , 4 , 4.02069091797 ); // 3000_MNu-1750
    hlimitxsec2->SetBinContent( 4 , 5 , 3.71932983398 ); // 3000_MNu-2000
    hlimitxsec2->SetBinContent( 4 , 6 , 3.77082824707 ); // 3000_MNu-2250
    hlimitxsec2->SetBinContent( 4 , 7 , 3.84902954102 ); // 3000_MNu-2500
    hlimitxsec2->SetBinContent( 4 , 8 , 4.52041625977 ); // 3000_MNu-2750
    hlimitxsec2->SetBinContent( 5 , 1 , 4.20761108398 ); // 3500_MNu-1000
    hlimitxsec2->SetBinContent( 5 , 2 , 3.56674194336 ); // 3500_MNu-1250
    hlimitxsec2->SetBinContent( 5 , 3 , 3.24440002441 ); // 3500_MNu-1500
    hlimitxsec2->SetBinContent( 5 , 4 , 3.07083129883 ); // 3500_MNu-1750
    hlimitxsec2->SetBinContent( 5 , 5 , 2.89344787598 ); // 3500_MNu-2000
    hlimitxsec2->SetBinContent( 5 , 6 , 2.83241271973 ); // 3500_MNu-2250
    hlimitxsec2->SetBinContent( 5 , 7 , 2.77519226074 ); // 3500_MNu-2500
    hlimitxsec2->SetBinContent( 5 , 8 , 2.86674499512 ); // 3500_MNu-2750
    hlimitxsec2->SetBinContent( 5 , 9 , 2.97546386719 ); // 3500_MNu-3000
    hlimitxsec2->SetBinContent( 5 , 10 , 3.51715087891 ); // 3500_MNu-3250
    hlimitxsec2->SetBinContent( 6 , 1 , 3.99398803711 ); // 4000_MNu-1000
    hlimitxsec2->SetBinContent( 6 , 2 , 3.2787322998 ); // 4000_MNu-1250
    hlimitxsec2->SetBinContent( 6 , 3 , 2.87246704102 ); // 4000_MNu-1500
    hlimitxsec2->SetBinContent( 6 , 4 , 2.72750854492 ); // 4000_MNu-1750
    hlimitxsec2->SetBinContent( 6 , 5 , 2.58445739746 ); // 4000_MNu-2000
    hlimitxsec2->SetBinContent( 6 , 6 , 2.45475769043 ); // 4000_MNu-2250
    hlimitxsec2->SetBinContent( 6 , 7 , 2.38418579102 ); // 4000_MNu-2500
    hlimitxsec2->SetBinContent( 6 , 8 , 2.4471282959 ); // 4000_MNu-2750
    hlimitxsec2->SetBinContent( 6 , 9 , 2.41661071777 ); // 4000_MNu-3000
    hlimitxsec2->SetBinContent( 6 , 10 , 2.48146057129 ); // 4000_MNu-3250
    hlimitxsec2->SetBinContent( 6 , 11 , 2.64930725098 ); // 4000_MNu-3500
    hlimitxsec2->SetBinContent( 6 , 12 , 3.13186645508 ); // 4000_MNu-3750
    hlimitxsec2->SetStats(0);
    
    
    TH2D *ExpctedExclusionLimit = new TH2D("ExpctedExclusionLimit","ExpctedExclusionLimit",6,1250,4250,12,875,3875);
    ExpctedExclusionLimit->SetBinContent( 1 , 1 , 0.11249410695 ); // 1500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 1 , 2 , 0.131120352909 ); // 1500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 1 , 0.215757370867 ); // 2000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 2 , 2 , 0.206457484192 ); // 2000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 2 , 3 , 0.194367631514 ); // 2000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 2 , 4 , 0.227033483461 ); // 2000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 1 , 0.406503677368 ); // 2500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 3 , 2 , 0.367959340413 ); // 2500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 3 , 3 , 0.343918800354 ); // 2500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 3 , 4 , 0.341137250264 ); // 2500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 3 , 5 , 0.340342521667 ); // 2500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 3 , 6 , 0.37690003713 ); // 2500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 1 , 0.840119066128 ); // 3000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 4 , 2 , 0.749654437772 ); // 3000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 4 , 3 , 0.693983897246 ); // 3000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 4 , 4 , 0.666781246761 ); // 3000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 4 , 5 , 0.616804284243 ); // 3000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 4 , 6 , 0.625344651255 ); // 3000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 4 , 7 , 0.638313356719 ); // 3000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 4 , 8 , 0.749654437772 ); // 3000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 1 , 2.01321104497 ); // 3500_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 5 , 2 , 1.70657509252 ); // 3500_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 5 , 3 , 1.55234450929 ); // 3500_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 5 , 4 , 1.46929727217 ); // 3500_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 5 , 5 , 1.38442482104 ); // 3500_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 5 , 6 , 1.355221397 ); // 3500_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 5 , 7 , 1.32784318696 ); // 3500_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 5 , 8 , 1.37164832302 ); // 3500_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 5 , 9 , 1.4236669221 ); // 3500_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 5 , 10 , 1.68284731048 ); // 3500_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 1 , 4.9862522311 ); // 4000_MNu-1000
    ExpctedExclusionLimit->SetBinContent( 6 , 2 , 4.09329875132 ); // 4000_MNu-1250
    ExpctedExclusionLimit->SetBinContent( 6 , 3 , 3.5861011748 ); // 4000_MNu-1500
    ExpctedExclusionLimit->SetBinContent( 6 , 4 , 3.40512926957 ); // 4000_MNu-1750
    ExpctedExclusionLimit->SetBinContent( 6 , 5 , 3.22653857361 ); // 4000_MNu-2000
    ExpctedExclusionLimit->SetBinContent( 6 , 6 , 3.06461634261 ); // 4000_MNu-2250
    ExpctedExclusionLimit->SetBinContent( 6 , 7 , 2.97651159927 ); // 4000_MNu-2500
    ExpctedExclusionLimit->SetBinContent( 6 , 8 , 3.05509150549 ); // 4000_MNu-2750
    ExpctedExclusionLimit->SetBinContent( 6 , 9 , 3.01699215702 ); // 4000_MNu-3000
    ExpctedExclusionLimit->SetBinContent( 6 , 10 , 3.09795327252 ); // 4000_MNu-3250
    ExpctedExclusionLimit->SetBinContent( 6 , 11 , 3.30749968911 ); // 4000_MNu-3500
    ExpctedExclusionLimit->SetBinContent( 6 , 12 , 3.9099456368 ); // 4000_MNu-3750
    
    
    
    TH2D *ObservedExclusionLimit = new TH2D("ObservedExclusionLimit","ObservedExclusionLimit",6,1250,4250,12,875,3875);
    ObservedExclusionLimit->SetBinContent( 1 , 1 , 0.0867198000441 ); // 1500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 1 , 2 , 0.0964587313766 ); // 1500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 1 , 0.210151261151 ); // 2000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 2 , 2 , 0.206822160919 ); // 2000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 2 , 3 , 0.206925322287 ); // 2000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 2 , 4 , 0.24610437222 ); // 2000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 1 , 0.457822367237 ); // 2500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 3 , 2 , 0.41018695303 ); // 2500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 3 , 3 , 0.385738381953 ); // 2500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 3 , 4 , 0.391313604015 ); // 2500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 3 , 5 , 0.375260343716 ); // 2500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 3 , 6 , 0.417252195936 ); // 2500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 1 , 0.893406596714 ); // 3000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 4 , 2 , 0.832920315873 ); // 3000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 4 , 3 , 0.765433199336 ); // 3000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 4 , 4 , 0.730965273344 ); // 3000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 4 , 5 , 0.667181473362 ); // 3000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 4 , 6 , 0.674997335559 ); // 3000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 4 , 7 , 0.687224583644 ); // 3000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 4 , 8 , 0.803991412645 ); // 3000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 1 , 2.18824722656 ); // 3500_MNu-1000
    ObservedExclusionLimit->SetBinContent( 5 , 2 , 1.84498942273 ); // 3500_MNu-1250
    ObservedExclusionLimit->SetBinContent( 5 , 3 , 1.67739601401 ); // 3500_MNu-1500
    ObservedExclusionLimit->SetBinContent( 5 , 4 , 1.63292581897 ); // 3500_MNu-1750
    ObservedExclusionLimit->SetBinContent( 5 , 5 , 1.48085945307 ); // 3500_MNu-2000
    ObservedExclusionLimit->SetBinContent( 5 , 6 , 1.47088358351 ); // 3500_MNu-2250
    ObservedExclusionLimit->SetBinContent( 5 , 7 , 1.41413351862 ); // 3500_MNu-2500
    ObservedExclusionLimit->SetBinContent( 5 , 8 , 1.46200158269 ); // 3500_MNu-2750
    ObservedExclusionLimit->SetBinContent( 5 , 9 , 1.50882543008 ); // 3500_MNu-3000
    ObservedExclusionLimit->SetBinContent( 5 , 10 , 1.81201317 ); // 3500_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 1 , 5.31482490424 ); // 4000_MNu-1000
    ObservedExclusionLimit->SetBinContent( 6 , 2 , 4.32759361637 ); // 4000_MNu-1250
    ObservedExclusionLimit->SetBinContent( 6 , 3 , 3.84695132865 ); // 4000_MNu-1500
    ObservedExclusionLimit->SetBinContent( 6 , 4 , 3.72092090253 ); // 4000_MNu-1750
    ObservedExclusionLimit->SetBinContent( 6 , 5 , 3.44033698051 ); // 4000_MNu-2000
    ObservedExclusionLimit->SetBinContent( 6 , 6 , 3.26475687131 ); // 4000_MNu-2250
    ObservedExclusionLimit->SetBinContent( 6 , 7 , 3.15737356277 ); // 4000_MNu-2500
    ObservedExclusionLimit->SetBinContent( 6 , 8 , 3.26431826486 ); // 4000_MNu-2750
    ObservedExclusionLimit->SetBinContent( 6 , 9 , 3.18695121406 ); // 4000_MNu-3000
    ObservedExclusionLimit->SetBinContent( 6 , 10 , 3.35018631936 ); // 4000_MNu-3250
    ObservedExclusionLimit->SetBinContent( 6 , 11 , 3.5253601511 ); // 4000_MNu-3500
    ObservedExclusionLimit->SetBinContent( 6 , 12 , 4.16719658227 ); // 4000_MNu-3750
    
    */
    

    
    
    Double_t XS[6] = {2.9E-1,6.563E-02,1.92E-02,6.030E-03,0.00209,0.000801};
    
    
    Double_t WMass[7] = {
        1500,
        2000,
        2500,
        3000,
        3500,
        4000,
        4001};
    
    
    Double_t NuMass[12] = {
        1000,
        1250,
        1500,
        1750,
        2000,
        2250,
        2500,
        2750,
        3000,
        3250,
        3500,
        3750
    };
    
    
    
    vector <float> exclusion_expected;
    vector <float> exclusion_observed;
    exclusion_expected.clear();
    exclusion_observed.clear();
    
    
    //    for (int ii =1 ; ii < ExpctedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
    //        for (int jj =1 ; jj < ExpctedExclusionLimit->GetYaxis()->GetNbins()+1; jj++){
    //
    //            ExpctedExclusionLimit->SetBinContent(ii,jj, hlimitxsec2->GetBinContent(ii,jj)/(XS[ii-1]*1000));
    //            cout<<ii<<" "<< jj<< " "<< ExpctedExclusionLimit->GetBinContent(ii,jj)<<"\n";
    //
    //        }
    //
    //
    //    }
    
    
    
    for (int jj =1 ; jj < ExpctedExclusionLimit->GetYaxis()->GetNbins()+1; jj++){
        float ExpLim =0;
        float ObsLim =0;
        
        for (int ii =1 ; ii < ExpctedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
            
            
            
             ExpLim = intersection(WMass[ii-1], WMass[ii], 1, 1, ExpctedExclusionLimit->GetBinContent(ii,jj), ExpctedExclusionLimit->GetBinContent(ii+1,jj));
            
            
            if (ExpLim) break;
        }
        
        
        for (int ii =1 ; ii < ObservedExclusionLimit->GetXaxis()->GetNbins()+1; ii++){
            
            
            
            ObsLim = intersection(WMass[ii-1], WMass[ii], 1, 1, ObservedExclusionLimit->GetBinContent(ii,jj), ObservedExclusionLimit->GetBinContent(ii+1,jj));
            
            
            if (ObsLim) break;
        }
       
        
        if (ExpLim && ExpLim < 4000) {
                
            cout <<NuMass[jj-1] <<" Exp="<<ExpLim<< "    &&&&&&&  Obs="<<ObsLim<<"\n";
                
                
//                if (ExpLim > NuMass[jj-1] &&  ObsLim > NuMass[jj-1]){
                exclusion_expected.push_back(ExpLim);
                exclusion_observed.push_back(ObsLim);
//                }
            
        }
    }
    
    
    cout<<exclusion_expected.size()<<"    "<<exclusion_observed.size()<<"\n";
    
    
    
    
//    hlimitxsec2->SetContour(2);
//    hlimitxsec2->SetContourLevel(0,40);
//    hlimitxsec2->SetContourLevel(1,1);
    
//    
//    hlimitxsec2->SetContour(36);
//    hlimitxsec2->SetContourLevel(1,1);
//    hlimitxsec2->SetContourLevel(1,2);
//    hlimitxsec2->SetContourLevel(2,2.2);
//    hlimitxsec2->SetContourLevel(3,2.4);
//    hlimitxsec2->SetContourLevel(4,2.6);
//    hlimitxsec2->SetContourLevel(5,2.8);
//    hlimitxsec2->SetContourLevel(6,3);
//    hlimitxsec2->SetContourLevel(7,3.2);
//    hlimitxsec2->SetContourLevel(8,3.4);
//    hlimitxsec2->SetContourLevel(9,3.6);
//    hlimitxsec2->SetContourLevel(10,3.8);
//    hlimitxsec2->SetContourLevel(11,4);
//    hlimitxsec2->SetContourLevel(12,4.2);
//    hlimitxsec2->SetContourLevel(13,4.4);
//    hlimitxsec2->SetContourLevel(14,4.6);
//    hlimitxsec2->SetContourLevel(15,4.8);
//    hlimitxsec2->SetContourLevel(16,5);
//    hlimitxsec2->SetContourLevel(17,5.5);
//    hlimitxsec2->SetContourLevel(18,6);
//    hlimitxsec2->SetContourLevel(19,6.5);
//    hlimitxsec2->SetContourLevel(20,7);
//    hlimitxsec2->SetContourLevel(21,7.5);
//    hlimitxsec2->SetContourLevel(22,8);
//    hlimitxsec2->SetContourLevel(23,9);
//    hlimitxsec2->SetContourLevel(24,9.5);
//    hlimitxsec2->SetContourLevel(25,10);
//    hlimitxsec2->SetContourLevel(26,10.5);
//    hlimitxsec2->SetContourLevel(27,11);
//    hlimitxsec2->SetContourLevel(28,12);
//    hlimitxsec2->SetContourLevel(29,13);
//    hlimitxsec2->SetContourLevel(30,14);
//    hlimitxsec2->SetContourLevel(31,16);
//    hlimitxsec2->SetContourLevel(32,18);
//    hlimitxsec2->SetContourLevel(33,20);
//    hlimitxsec2->SetContourLevel(34,22);
//    hlimitxsec2->SetContourLevel(35,30);
//    hlimitxsec2->SetContourLevel(36,40);
    
    
    Int_t ck;   // for color index setting
    ck = TColor::GetColor("#000099");
    hlimitxsec2->SetLineColor(ck);
    hlimitxsec2->GetYaxis()->SetTitle("M_{Nu} [GeV]");
    hlimitxsec2->GetXaxis()->SetNdivisions(505);
    hlimitxsec2->GetXaxis()->SetLabelFont(42);
    hlimitxsec2->GetXaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetXaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetXaxis()->SetTitleSize(0.05);
    hlimitxsec2->GetXaxis()->SetTitleFont(42);
    hlimitxsec2->GetXaxis()->SetTitle("M_{W_{R}} [GeV]");
    hlimitxsec2->GetYaxis()->SetNdivisions(505);
    hlimitxsec2->GetYaxis()->SetLabelFont(42);
    hlimitxsec2->GetYaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetYaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetYaxis()->SetTitleSize(0.05);
    hlimitxsec2->GetYaxis()->SetTitleFont(42);
    hlimitxsec2->GetZaxis()->SetNdivisions(505);
    hlimitxsec2->GetZaxis()->SetLabelFont(42);
    hlimitxsec2->GetZaxis()->SetLabelOffset(0.007);
    hlimitxsec2->GetZaxis()->SetLabelSize(0.035);
    hlimitxsec2->GetZaxis()->SetTitleSize(0.045);
    hlimitxsec2->GetZaxis()->SetTitleFont(42);
    hlimitxsec2->GetZaxis()->SetRangeUser(2, 43);
    hlimitxsec2->Draw("COLZ");
    
    
    
    
    
    TGraphErrors *gre = new TGraphErrors(exclusion_observed.size()-2);
    gre->SetName("Graph");
    gre->SetTitle("Graph");
    gre->SetFillColor(1);
//    gre->SetLineStyle(10);
    gre->SetLineWidth(4);
    
    
    for (int kk=0;kk<exclusion_observed.size()-2;kk++){
        
        gre->SetPoint(kk, exclusion_observed[kk], NuMass[kk]);
        gre->SetPointError(kk,0,0);
        cout <<"Obs----->"<<kk<< " " <<exclusion_observed[kk]<< " "  <<NuMass[kk]<<"\n";
        
    }
    
    
    TH1F *Graph_Graph_Graph11 = new TH1F("Graph_Graph_Graph11","Graph",12,875,3875);
    Graph_Graph_Graph11->SetDirectory(0);
    Graph_Graph_Graph11->SetStats(0);
    
    cj = TColor::GetColor("#000099");
//    Graph_Graph_Graph11->SetLineColor(cj);
//    Graph_Graph_Graph11->GetXaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11->GetXaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11->GetXaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11->GetXaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11->GetXaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11->GetXaxis()->SetTitleFont(42);
//    Graph_Graph_Graph11->GetYaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11->GetYaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11->GetYaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11->GetYaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11->GetYaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11->GetYaxis()->SetTitleFont(42);
//    Graph_Graph_Graph11->GetZaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11->GetZaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11->GetZaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11->GetZaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11->GetZaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11->GetZaxis()->SetTitleFont(42);
    gre->SetHistogram(Graph_Graph_Graph11);
    
    gre->Draw("c");
    
    
    
    
    
    
    TGraphErrors *greExp = new TGraphErrors(exclusion_observed.size()-2);
    greExp->SetName("Graph");
    greExp->SetTitle("Graph");
    greExp->SetFillColor(1);
    greExp->SetLineStyle(2);
    greExp->SetLineWidth(3);

    for (int kk=0;kk<exclusion_expected.size()-2;kk++){
        
        greExp->SetPoint(kk, exclusion_expected[kk], NuMass[kk]);
        greExp->SetPointError(kk,0,0);
        cout <<"Exp----->"<<kk<< " " <<exclusion_expected[kk]<< " "  <<NuMass[kk]<<"\n";
        
    }
    
    
    TH1F *Graph_Graph_Graph11Exp = new TH1F("Graph_Graph_Graph11Exp","Graph",1100,1000,3250);
    Graph_Graph_Graph11Exp->SetDirectory(0);
    Graph_Graph_Graph11Exp->SetStats(0);
    
//    Int_t ci;
//    ci = TColor::GetColor("#000099");
//    Graph_Graph_Graph11Exp->SetLineColor(ci);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11Exp->GetXaxis()->SetTitleFont(42);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11Exp->GetYaxis()->SetTitleFont(42);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetNdivisions(505);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelFont(42);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelOffset(0.007);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetLabelSize(0.035);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetTitleSize(0.045);
//    Graph_Graph_Graph11Exp->GetZaxis()->SetTitleFont(42);
    greExp->SetHistogram(Graph_Graph_Graph11Exp);
    
           greExp->Draw("c");
    
    TLegend *legendr = new TLegend(0.18,0.65,0.47,0.80,NULL,"brNDC");
    
    legendr->SetShadowColor(0);
    legendr->SetBorderSize(0);
    legendr->SetFillColor(0);
    legendr->AddEntry(gre,"Observed","L");
    legendr->AddEntry(greExp, "Expected", "L");
    legendr->SetFillStyle(0);
    legendr->SetTextSize(.04);
    
    legendr->SetTextFont(42);
    
    legendr->SetFillColor(0);
    
    legendr->SetBorderSize(0);
    
    legendr->Draw();
    
    
    

//    
////    
//    TPaveText *pt = new TPaveText(0.1072864,0.7618663,0.3080402,0.7820056,"brNDC");
//    
//    pt->SetBorderSize(0);
//    
//    pt->SetFillColor(0);
//    
//    pt->SetLineColor(0);
//    pt->SetTextSize(0.05);
//    
//    
//    TText *textL = pt->AddText("CMS     ");
////    textL->SetTextFont(42);
//    pt->Draw();
//    
//    TText *textL2 = pt->AddText("                                                                                           12.9 fb^{-1} (13 TeV)");
//    pt->SetTextSize(0.04);
//    pt->Draw("same");
    
    
    
    float lowX=0.55;
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
    
    lowX=0.18;
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
    
    
    
    
    
 
//    string ARR[8]={"0.3","0.4","0.5","0.6","0.7","0.8","0.9","1.0"};
//    float y1=0;
//    float x1=0;
//    float x2=4250;
//    
//    for (int jj=3; jj< 11; jj++){
//        float y2=jj* .1 * x2 ;
//        
//        if (jj <= 7){
//            y1=875;
//            x1=y1/(jj* .1);}
//        if (jj > 7){
//            x1=1250;
//            y1= (jj* .1) * x1;
//            
//        }
//        if (y2> 3875){
//            
//            y2=3875;
//            x2=y2/(jj* .1);
//        }
//            
//        
//        
//        cout << jj <<"  "<< x2 <<"  "<<y2<<"\n";
//        TLine *line = new TLine(x1,y1,x2,y2);
//        line->Draw();
//    
//        lowX=0.63;
//        lowY=jj/10. - 0.2;
//        TPaveText * lumi2  = new TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC");
//        lumi2->SetTextFont(61);
//        lumi2->SetTextSize(0.02);
//        lumi2->SetBorderSize(   0 );
//        lumi2->SetFillStyle(    0 );
//        lumi2->SetTextAlign(   12 );
//        lumi2->SetTextColor(    1 );
////        char * myCharPointer;
////        sprintf(myCharPointer, "%01.1f", jj/10.);
//        lumi2->AddText(ARR[jj-3].c_str());
//        lumi2->Draw();
//    }
//
    
    
    TText *text = new TText(4900,1404.522,"Cross section UL at 95% CL [fb]");
    text->SetTextFont(42);
    text->SetTextSize(0.04748603);
    text->SetTextAngle(90);
    text->Draw();
    can2->Modified();
    can2->cd();
    can2->SetSelected(can2);
    can2->SaveAs("limit_2D_RHW.pdf");
    //     dofile("rhw.json");
    
}

