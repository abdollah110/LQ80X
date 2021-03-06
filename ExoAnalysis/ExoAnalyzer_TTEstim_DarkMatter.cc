#include "../interface/LQ3Analyzer.h"
#include "../interface/WeightCalculator.h"
#include "../interface/Corrector.h"
#include <string>
#include <ostream>


int main(int argc, char** argv) {
    using namespace std;
    
    std::string out = *(argv + 1);
    
    cout << "\n\n\n OUTPUT NAME IS:    " << out << endl;     //PRINTING THE OUTPUT name
    TFile *fout = TFile::Open(out.c_str(), "RECREATE");
    
    myMap1 = new std::map<std::string, TH1F*>();
    myMap2 = new map<string, TH2F*>();
    
    std::vector<string> input;
    for (int f = 2; f < argc; f++) {
        input.push_back(*(argv + f));
        cout << "\n INPUT NAME IS:   " << input[f - 2] << "\n";
    }

    
    
    
    TFile * PUData= TFile::Open("../interface/pileup-hists/MyDataPileupHistogram2016.root");
    TH1F * HistoPUData= (TH1F *) PUData->Get("pileup");
    HistoPUData->Scale(1.0/HistoPUData->Integral());
    
    TFile * PUMC= TFile::Open("../interface/pileup-hists/Sprin16_MC.root");
    TH1F * HistoPUMC= (TH1F *) PUMC->Get("pileup");
    HistoPUMC->Scale(1.0/HistoPUMC->Integral());
    
    TFile * MuCorrId= TFile::Open("../interface/pileup-hists/MuonID_Z_RunBCD_prompt80X_7p65.root");
//    TFile * MuCorrId= TFile::Open("../interface/pileup-hists/MuonID_Z_2016runB_2p6fb.root");
    TH2F * HistoMuId= (TH2F *) MuCorrId->Get("MC_NUM_TightIDandIPCut_DEN_genTracks_PAR_pt_spliteta_bin1/pt_abseta_ratio");
    
    TFile * MuCorrIso= TFile::Open("../interface/pileup-hists/MuonIso_Z_RunBCD_prompt80X_7p65.root");
//    TFile * MuCorrIso= TFile::Open("../interface/pileup-hists/MuonISO_Z_2016runB_2p6fb.root");
    TH2F * HistoMuIso= (TH2F *) MuCorrIso->Get("MC_NUM_TightRelIso_DEN_TightID_PAR_pt_spliteta_bin1/pt_abseta_ratio");
    
    TFile * MuCorrTrg= TFile::Open("../interface/pileup-hists/SingleMuonTrigger_Z_RunBCD_prompt80X_7p65.root");
//    TFile * MuCorrTrg= TFile::Open("../interface/pileup-hists/SingleMuonTrigger_Z_RunCD_Reco76X_Feb15.root");
    TH2F * HistoMuTrg= (TH2F *) MuCorrTrg->Get("Mu45_eta2p1_PtEtaBins_Run274094_to_276097/efficienciesDATA/pt_abseta_DATA");

    
    //    TFile * ElectronSF0p5= TFile::Open("../interface/pileup-hists/egammaEffi.txt_SF2D_80X_0p5.root");
    TFile * ElectronSF= TFile::Open("../interface/pileup-hists/egammaEffi.txt_SF2D_80X.root");
    TH2F * HistoEleSF= (TH2F *) ElectronSF->Get("EGamma_SF2D");
    
    //    TFile * ElectronSF5= TFile::Open("../interface/pileup-hists/egammaEffi.txt_SF2D_80X_5.root");
    //    TH2F * HistoEleSF5= (TH2F *) ElectronSF5->Get("EGamma_SF2D");

    
    
    
    for (int k = 0; k < input.size(); k++) {
        
        //std::string input = *(argv + 2);
        TFile *f_Double = TFile::Open(input[k].c_str());
        cout << "\n  Now is running on ------->   " << std::string(f_Double->GetName()) << "\n";
        
        std::string InputROOT= std::string(f_Double->GetName());
        TFile * myFile = TFile::Open(f_Double->GetName());
        TH1F * HistoTot = (TH1F*) myFile->Get("hcount");
        
        //        TTree *Run_Tree = (TTree*) f_Double->Get("ggNtuplizer/EventTree");
        TTree *Run_Tree = (TTree*) f_Double->Get("EventTree");
        
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(6);
        
        
        std::string ROOTLoc= "/Users/abdollah1/GIT_abdollah110/DarkMatter/ROOT80X/";
//        std::string ROOTLoc= "/Users/abdollah1/GIT_abdollah110/LQ80X/ROOT80X/rootTT/";
        vector<float> DY_Events = DY_HTBin(ROOTLoc);
        vector<float> W_Events = W_HTBin(ROOTLoc);
        
        /////////////////////////   General Info
        Run_Tree->SetBranchAddress("isData", &isData);
        Run_Tree->SetBranchAddress("run", &run);
        Run_Tree->SetBranchAddress("lumis", &lumis);
        Run_Tree->SetBranchAddress("event", &event);
        Run_Tree->SetBranchAddress("genWeight",&genWeight);
        Run_Tree->SetBranchAddress("HLTEleMuX", &HLTEleMuX);
        Run_Tree->SetBranchAddress("puTrue", &puTrue);
        Run_Tree->SetBranchAddress("nVtx",&nVtx);
        
        /////////////////////////   MC Info
        Run_Tree->SetBranchAddress("nMC", &nMC);
        Run_Tree->SetBranchAddress("mcPID", &mcPID);
        Run_Tree->SetBranchAddress("mcStatus", &mcStatus);
        Run_Tree->SetBranchAddress("mcPt", &mcPt );
        Run_Tree->SetBranchAddress("mcEta", &mcEta );
        Run_Tree->SetBranchAddress("mcPhi", &mcPhi );
        Run_Tree->SetBranchAddress("mcE", &mcE );
        Run_Tree->SetBranchAddress("mcMass", &mcMass );
        Run_Tree->SetBranchAddress("eleSCEta", &eleSCEta );
        
        
        /////////////////////////   Tau Info
        Run_Tree->SetBranchAddress("nTau", &nTau);
        Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
        Run_Tree->SetBranchAddress("tauEta"  ,&tauEta);
        Run_Tree->SetBranchAddress("tauPhi"  ,&tauPhi);
        Run_Tree->SetBranchAddress("tauMass"  ,&tauMass);
        Run_Tree->SetBranchAddress("tauCharge"  ,&tauCharge);
        Run_Tree->SetBranchAddress("taupfTausDiscriminationByDecayModeFinding", &taupfTausDiscriminationByDecayModeFinding);
        Run_Tree->SetBranchAddress("tauByTightMuonRejection3", &tauByTightMuonRejection3);
        Run_Tree->SetBranchAddress("tauByLooseMuonRejection3", &tauByLooseMuonRejection3);
        Run_Tree->SetBranchAddress("tauByMVA6MediumElectronRejection"  ,&tauByMVA6MediumElectronRejection);
        Run_Tree->SetBranchAddress("tauByLooseCombinedIsolationDeltaBetaCorr3Hits",&tauByLooseCombinedIsolationDeltaBetaCorr3Hits);
        Run_Tree->SetBranchAddress("tauByMediumCombinedIsolationDeltaBetaCorr3Hits",&tauByMediumCombinedIsolationDeltaBetaCorr3Hits);
        Run_Tree->SetBranchAddress("tauByMVA6LooseElectronRejection", &tauByMVA6LooseElectronRejection);
        Run_Tree->SetBranchAddress("tauDxy",&tauDxy);
        
        /////////////////////////   Mu Info
        Run_Tree->SetBranchAddress("nMu", &nMu);
        Run_Tree->SetBranchAddress("muPt"  ,&muPt);
        Run_Tree->SetBranchAddress("muEta"  ,&muEta);
        Run_Tree->SetBranchAddress("muPhi"  ,&muPhi);
        Run_Tree->SetBranchAddress("muIsoTrk", &muIsoTrk);
        Run_Tree->SetBranchAddress("muCharge",&muCharge);
        Run_Tree->SetBranchAddress("muIsTightID",&muIsTightID);
        Run_Tree->SetBranchAddress("muIsMediumID",&muIsMediumID);
        Run_Tree->SetBranchAddress("muIsLooseID",&muIsLooseID);
        Run_Tree->SetBranchAddress("muPFChIso", &muPFChIso);
        Run_Tree->SetBranchAddress("muPFPhoIso", &muPFPhoIso);
        Run_Tree->SetBranchAddress("muPFNeuIso", &muPFNeuIso);
        Run_Tree->SetBranchAddress("muPFPUIso", &muPFPUIso);
        Run_Tree->SetBranchAddress("muD0",&muD0);
        Run_Tree->SetBranchAddress("muDz",&muDz);
        
        /////////////////////////   Ele Info
        Run_Tree->SetBranchAddress("nEle", &nEle);
        Run_Tree->SetBranchAddress("elePt"  ,&elePt);
        Run_Tree->SetBranchAddress("eleEta"  ,&eleEta);
        Run_Tree->SetBranchAddress("elePhi"  ,&elePhi);
        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
        Run_Tree->SetBranchAddress("eleIDMVANonTrg", &eleIDMVANonTrg);
        Run_Tree->SetBranchAddress("eleCharge",&eleCharge);
        Run_Tree->SetBranchAddress("eleSCEta",&eleSCEta);
        Run_Tree->SetBranchAddress("elePFChIso", &elePFChIso);
        Run_Tree->SetBranchAddress("elePFPhoIso", &elePFPhoIso);
        Run_Tree->SetBranchAddress("elePFNeuIso", &elePFNeuIso);
        Run_Tree->SetBranchAddress("elePFPUIso", &elePFPUIso);
        Run_Tree->SetBranchAddress("eleD0",&eleD0);
        Run_Tree->SetBranchAddress("eleDz",&eleDz);
        Run_Tree->SetBranchAddress("eleMissHits", &eleMissHits);
        Run_Tree->SetBranchAddress("eleConvVeto", &eleConvVeto);
        
        /////////////////////////   Jet Info
        Run_Tree->SetBranchAddress("nJet",&nJet);
        Run_Tree->SetBranchAddress("jetPt",&jetPt);
        Run_Tree->SetBranchAddress("jetEta",&jetEta);
        Run_Tree->SetBranchAddress("jetPhi",&jetPhi);
        Run_Tree->SetBranchAddress("jetEn",&jetEn);
        Run_Tree->SetBranchAddress("jetpfCombinedInclusiveSecondaryVertexV2BJetTags",&jetpfCombinedInclusiveSecondaryVertexV2BJetTags);
        Run_Tree->SetBranchAddress("jetPFLooseId",&jetPFLooseId);
        Run_Tree->SetBranchAddress("jetPUidFullDiscriminant",&jetPUidFullDiscriminant);
        /////////////////////////   MET Info
        Run_Tree->SetBranchAddress("pfMET",&pfMET);
        Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
        Run_Tree->SetBranchAddress("metFilters",&metFilters);
        Run_Tree->SetBranchAddress("genHT",&genHT);
        Run_Tree->SetBranchAddress("jetHadFlvr",&jetHadFlvr);
        
        
        
        
        
        
        
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_Mu_=60;
        float LeptonPtCut_Ele_=50;
        //                float TauPtCut_=50;
        float JetPtCut=50;
//        float BJetPtCut=50;
        float LooseCSV= 0.460 ;                    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation74X
        float LeptonIsoCut=0.15;
        
        
        
        
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        for (Int_t i = 0; i < nentries_wtn; i++) {
//for (Int_t i = 0; i < 100; i++) {
            Run_Tree->GetEntry(i);
            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
//            cout <<pfMET<<"   metFilters = "<<metFilters<<"\n";
            if (isData && (metFilters!=0)) continue;
            
            
            
            //###############################################################################################
            //  Weight Calculation
            //###############################################################################################
            
            //############ Top Reweighting
            float GenTopPt=0;
            float GenAntiTopPt=0;
            float TopPtReweighting = 1;
            for (int igen=0;igen < nMC; igen++){
                if (mcPID->at(igen) == 6 && mcStatus->at(igen) ==62) GenTopPt=mcPt->at(igen) ;
                if (mcPID->at(igen) == -6 && mcStatus->at(igen) ==62) GenAntiTopPt=mcPt->at(igen);
            }
            size_t isTTJets = InputROOT.find("TTJets");
            if (isTTJets!= string::npos) TopPtReweighting = compTopPtWeight(GenTopPt, GenAntiTopPt);
            //###############################################################################################
            float LumiWeight = 1;
            float GetGenWeight=1;
            float PUWeight = 1;
            
            if (!isData){
                
                if (HistoTot) LumiWeight = weightCalc(HistoTot, InputROOT, genHT, W_Events, DY_Events);
                GetGenWeight=genWeight;
                
                int puNUmmc=int(puTrue->at(0)*10);
                int puNUmdata=int(puTrue->at(0)*10);
                float PUMC_=HistoPUMC->GetBinContent(puNUmmc+1);
                float PUData_=HistoPUData->GetBinContent(puNUmdata+1);
                PUWeight= PUData_/PUMC_;
            }
            float TotalWeight = LumiWeight * GetGenWeight * PUWeight * TopPtReweighting;
            //###############################################################################################
            //  Histogram Filling
            //###############################################################################################
            plotFill("WeightLumi",LumiWeight,10000,0,100);
            plotFill("WeightPU",PUWeight,50,0,5);
            plotFill("WeightTotal",TotalWeight,200,0,2);
            plotFill("nVtx_NoPUCorr",nVtx,60,0,60);
            plotFill("nVtx_PUCorr",nVtx,60,0,60,PUWeight);
            for (int qq=0; qq < 60;qq++){
                if ((HLTEleMuX >> qq & 1) == 1)
                    plotFill("HLT",qq,60,0,60,TotalWeight);
            }
            
            //###############################################################################################
            //  Doing MuEle Analysis
            //###############################################################################################
            
            
            //Loop over MuEle events
            for  (int imu=0 ; imu < nMu; imu++){
                for  (int iele=0 ; iele < nEle; iele++){
                    
                    
                    
                    //  Check Muons ##########################################################################################
                    float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                    if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                        IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                    
                    bool MuPtCut = muPt->at(imu) > LeptonPtCut_Mu_ && fabs(muEta->at(imu)) < 2.1 ;
                    bool MuIdIso=(muIsTightID->at(imu) > 0 && IsoMu < LeptonIsoCut && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2);
                    
                    //  Check Electrons ##########################################################################################
                    float IsoEle=elePFChIso->at(iele)/elePt->at(iele);
                    if ( (elePFNeuIso->at(iele) + elePFPhoIso->at(iele) - 0.5* elePFPUIso->at(iele))  > 0.0)
                        IsoEle= (elePFChIso->at(iele)/elePt->at(iele) + elePFNeuIso->at(iele) + elePFPhoIso->at(iele) - 0.5* elePFPUIso->at(iele))/elePt->at(iele);
                    
                    bool eleMVAId= false;
                    if (fabs (eleSCEta->at(iele)) < 0.8 && eleIDMVANonTrg->at(iele) > 0.967083) eleMVAId= true;
                    else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <  1.444 && eleIDMVANonTrg->at(iele) > 0.929117) eleMVAId= true;
                    else if ( fabs (eleSCEta->at(iele)) >=  1.444 && eleIDMVANonTrg->at(iele) > 0.726311 ) eleMVAId= true;
                    else eleMVAId= false;
                    
                    bool elePtCut = elePt->at(iele) > LeptonPtCut_Ele_ && fabs(eleEta->at(iele)) < 2.1 ;
                    bool eleIdIso= eleMVAId ;
                    
                    
                    //  Check General Selection and OverLap ##########################################################################################
                    TLorentzVector Mu4Momentum,  Ele4Momentum, Z4Momentum, Jet4Momentum,ExtraMu4Momentum, ExtraEle4Momentum;;
                    Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                    Ele4Momentum.SetPtEtaPhiM(elePt->at(iele),eleEta->at(iele),elePhi->at(iele),eleMass);
                    Z4Momentum=Ele4Momentum+Mu4Momentum;
                    
                    bool  GeneralMuEleSelection=  MuPtCut && MuIdIso && Mu4Momentum.DeltaR(Ele4Momentum) > 0.5 && elePtCut &&  eleIdIso;
                    if (! GeneralMuEleSelection) continue;
                    
                    
                    float muCorr=getCorrFactorMuon74X(isData,  muPt->at(imu), muEta->at(imu) , HistoMuId,HistoMuIso,HistoMuTrg);
//                    float eleCorr=getCorrFactorElectron74X(isData,  elePt->at(iele), eleSCEta->at(iele) , HistoEleSF);
                    float eleCorr=getCorrFactorElectron74X_IDOnly(isData,  elePt->at(iele), eleSCEta->at(iele) , HistoEleSF);
                    
                    plotFill("Weight_Mu",muCorr,200,0,2);
                    plotFill("Weight_Ele",eleCorr,200,0,2);
                    
                    
                    
                    //###########      Jet definition   ###########################################################
                    vector<TLorentzVector> JetVector;
                    vector<TLorentzVector> BJetBVector;
                    vector<float> BJetVectorSF;
                    JetVector.clear();
                    BJetBVector.clear();
                    BJetVectorSF.clear();
                    
                    for (int ijet= 0 ; ijet < nJet ; ijet++){
                        Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                        //cout << jetPFLooseId->at(ijet)  << "   pu    "<< jetPUidFullDiscriminant->at(ijet)<<"\n";
                        
                        if (jetPFLooseId->at(ijet) > 0.5 && jetPt->at(ijet) > JetPtCut && fabs(jetEta->at(ijet)) < 2.4 && Jet4Momentum.DeltaR(Ele4Momentum) > 0.5 && Jet4Momentum.DeltaR(Mu4Momentum) > 0.5 ){
                            JetVector.push_back(Jet4Momentum);
                            if (jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  LooseCSV  ){
                                BJetBVector.push_back(Jet4Momentum);
                                if (!isData) BJetVectorSF.push_back(GetBJetSF(jetPt->at(ijet),jetEta->at(ijet),jetHadFlvr->at(ijet)));
//                                cout <<  "Btag Scale Factor is --> " << jetPt->at(ijet)<<"  "<<jetEta->at(ijet)<<"  "<<jetHadFlvr->at(ijet)<<"  -->  " << GetBJetSF(jetPt->at(ijet),jetEta->at(ijet),jetHadFlvr->at(ijet))<<"\n";
                                
                            }
                        }
                    }
                    
                    
                    // get the SF For Bjet multiplicity
                    float SFBJetMultiplicity =1;
                    for (int bsf =0; bsf < BJetVectorSF.size() ; bsf++){
                        SFBJetMultiplicity *= BJetVectorSF[bsf];
                    }
                    
                    
                    
                    float ST_JetBjet,M_muj0,M_muj1,M_ej0,M_ej1, M_MuJet,M_eJet,ST_DiJet=0;
                    float ST_MET=0;
                    float leadJetPt_=0;
                    float leadJetEta_=-2.5;
                    float subLeadJetPt_=0;
                    float subLeadJetEta_=-2.5;
                                        
                    
                    bool DiJet_Selection=JetVector.size() > 1;
                    bool JetBJet_Selection=JetVector.size() > 1& BJetBVector.size()> 0 && (BJetBVector[0].Pt()== JetVector[0].Pt() || BJetBVector[0].Pt() ==JetVector[1].Pt());
                    float BtagSFLeadBJet=1;
                    if (!isData && JetBJet_Selection) BtagSFLeadBJet= BJetVectorSF[0];
                    
                    
                    
                    if (DiJet_Selection){
                        ST_DiJet=JetVector[0].Pt()+JetVector[1].Pt()+muPt->at(imu)+elePt->at(iele);
                        ST_MET=JetVector[0].Pt()+JetVector[1].Pt()+muPt->at(imu)+elePt->at(iele)+pfMET;
                        
                        
                        M_muj0= (Mu4Momentum+JetVector[0]).M();
                        M_muj1= (Mu4Momentum+JetVector[1]).M();
                        M_ej0= (Ele4Momentum+JetVector[0]).M();
                        M_ej1= (Ele4Momentum+JetVector[1]).M();
                        
                        leadJetPt_=JetVector[0].Pt();
                        subLeadJetPt_=JetVector[1].Pt();
                        leadJetEta_=JetVector[0].Eta();
                        subLeadJetEta_=JetVector[1].Eta();
                        
                        
                        M_MuJet=M_muj0;
                        M_eJet=M_ej1;
                        if ( fabs(M_muj0-M_ej1) > fabs(M_muj1-M_ej0)){
                            M_MuJet=M_muj1;
                            M_eJet=M_ej0;
                            
                        }
                    }
                    
                    //###############################################################################################
                    //   Lep Charge Categorization
                    //###############################################################################################
                    const int size_Q = 2;
                    bool charge_No = 1;
                    bool charge_OS = muCharge->at(imu) * eleCharge->at(iele) < 0;
                    bool charge_SS = muCharge->at(imu) * eleCharge->at(iele) > 0;
                    bool charge_category[size_Q] = {charge_No,charge_OS};
                    std::string q_Cat[size_Q] = {"","_OS"};
                    
                    //###############################################################################################
                    //   Isolation Categorization
                    //###############################################################################################
                    const int size_isoCat = 1;
                    bool TightIso = 1;
                    //                    bool RelaxIso = 1;
                    bool Iso_category[size_isoCat] = {TightIso};
                    std::string iso_Cat[size_isoCat] = {""};
                    //###############################################################################################
                    //  MT Categorization
                    //###############################################################################################
                    float tmassMuMET= TMass_F(muPt->at(imu), muPt->at(imu)*cos(muPhi->at(imu)),muPt->at(imu)*sin(muPhi->at(imu)) , pfMET, pfMETPhi);
                    float tmassEleMET= TMass_F(elePt->at(iele), elePt->at(iele)*cos(elePhi->at(iele)),elePt->at(iele)*sin(elePhi->at(iele)) , pfMET, pfMETPhi);
                    const int size_mTCat = 1;
                    //                    bool NoMT = 1 && pfMET > 50 && Z4Momentum.M() > 150;  for RHW
                    //                    bool NoMT = 1 && (M_eJet > 250 || M_MuJet > 250);   //For LQ
                    bool NoMT = 1 ;   //For General
                    bool MT_category[size_mTCat] = {NoMT};
                    std::string MT_Cat[size_mTCat] = {""};
                    //###############################################################################################
                    //  Trigger Categorization
                    //###############################################################################################
                    const int size_trgCat = 1;
                    bool PassTrigger=1;
                    if (isData) PassTrigger = (HLTEleMuX >> 26 & 1) == 1; //  else if (name.find("HLT_Mu45_eta2p1_v") != string::npos) bitEleMuX = 26;
                    
                    bool Trigger_category[size_trgCat] = {PassTrigger};
                    std::string trg_Cat[size_trgCat] = {""};
                    //###############################################################################################
                    //  ST Categorization
                    //###############################################################################################
                    const int size_ST = 5;
                    bool LQExtraCuts= JetBJet_Selection && (M_eJet > 250 || M_MuJet > 250);
                    bool WRExtraCuts= DiJet_Selection && pfMET > 50 && Z4Momentum.M() > 150;
                    bool ST_category[size_ST] = {1,JetBJet_Selection,DiJet_Selection,  LQExtraCuts,WRExtraCuts};
                    std::string ST_Cat[size_ST] = {"_inclusive","_JetBJet","_DiJet","_JetBJetExtra","_DiJetExtra"};
                    //###############################################################################################
                    
                    
                    if (GeneralMuEleSelection){
                        for (int qcat = 0; qcat < size_Q; qcat++) {
                            if (charge_category[qcat]) {
                                for (int iso = 0; iso < size_isoCat; iso++) {
                                    if (Iso_category[iso]) {
                                        for (int imt = 0; imt < size_mTCat; imt++) {
                                            if (MT_category[imt]) {
                                                for (int ist = 0; ist < size_ST; ist++) {
                                                    if (ST_category[ist]) {
                                                        
                                                        
                                                        for (int trg = 0; trg < size_trgCat; trg++) {
                                                            
                                                            if (Trigger_category[trg]) {
                                                                
                                                                float FullWeight= TotalWeight * muCorr * eleCorr * BtagSFLeadBJet;
                                                                std::string FullStringName = MT_Cat[imt] +q_Cat[qcat] + iso_Cat[iso] + trg_Cat[trg] +ST_Cat[ist];
                                                                
                                                                plotFill("MuEle_tmassMuMET"+FullStringName,tmassMuMET,50,0,500,FullWeight);
                                                                plotFill("MuEle_tmassEleMET"+FullStringName,tmassEleMET,50,0,500,FullWeight);
                                                                plotFill("MuEle_MET"+FullStringName,pfMET,50,0,500,FullWeight);
                                                                plotFill("MuEle_VisMass"+FullStringName,Z4Momentum.M(),50,0,500,FullWeight);
                                                                plotFill("MuEle_MuPt"+FullStringName,muPt->at(imu),200,0,200,FullWeight);
                                                                plotFill("MuEle_MuEta"+FullStringName,muEta->at(imu),100,-2.5,2.5,FullWeight);
                                                                plotFill("MuEle_ElePt"+FullStringName,elePt->at(iele),200,0,200,FullWeight);
                                                                plotFill("MuEle_EleEta"+FullStringName,eleEta->at(iele),100,-2.5,2.5,FullWeight);
                                                                plotFill("MuEle_NumJet"+FullStringName,JetVector.size(),10,0,10,FullWeight);
                                                                plotFill("MuEle_NumBJet"+FullStringName,BJetBVector.size(),10,0,10,TotalWeight * muCorr * eleCorr* SFBJetMultiplicity);
                                                                plotFill("MuEle_NumBJet_noBCor"+FullStringName,BJetBVector.size(),10,0,10,TotalWeight * muCorr * eleCorr);
                                                                plotFill("MuEle_NumBJet_usualBCor"+FullStringName,BJetBVector.size(),10,0,10,FullWeight);
                                                                plotFill("MuEle_ST_MET"+FullStringName,ST_MET,500,0,5000,FullWeight);
                                                                plotFill("MuEle_ST_MET_NoTOP"+FullStringName,ST_MET,500,0,5000,FullWeight/TopPtReweighting);
                                                                plotFill("MuEle_LeadJetPt"+FullStringName,leadJetPt_,50,0,500,FullWeight);
                                                                plotFill("MuEle_SubLeadJetPt"+FullStringName,subLeadJetPt_,50,0,500,FullWeight);
                                                                plotFill("MuEle_LeadJetEta"+FullStringName,leadJetEta_,100,-2.5,2.5,FullWeight);
                                                                plotFill("MuEle_SubLeadJetEta"+FullStringName,subLeadJetEta_,100,-2.5,2.5,FullWeight);
                                                                
                                                                
                                                                
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            
            
            
            //###############################################################################################
            
            //##############  end of dielectron
            
        }
        
    }
    
    fout->cd();
    //    BG_Tree->Write();
    
    map<string, TH1F*>::const_iterator iMap1 = myMap1->begin();
    map<string, TH1F*>::const_iterator jMap1 = myMap1->end();
    
    for (; iMap1 != jMap1; ++iMap1)
        nplot1(iMap1->first)->Write();
    
    map<string, TH2F*>::const_iterator iMap2 = myMap2->begin();
    map<string, TH2F*>::const_iterator jMap2 = myMap2->end();
    
    for (; iMap2 != jMap2; ++iMap2)
        nplot2(iMap2->first)->Write();
    
    fout->Close();
    
    
}
