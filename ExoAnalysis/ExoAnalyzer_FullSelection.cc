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
        
        
        std::string ROOTLoc= "/Users/abdollah1/GIT_abdollah110/LQ80X/ROOT80X/rootSkim/";
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
        
        /////////////////////////   Tau Info
        Run_Tree->SetBranchAddress("nTau", &nTau);
        Run_Tree->SetBranchAddress("tauPt"  ,&tauPt);
        Run_Tree->SetBranchAddress("tauPx"  ,&tauPx);
        Run_Tree->SetBranchAddress("tauPy"  ,&tauPy);
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
        Run_Tree->SetBranchAddress("tauDecayMode",&tauDecayMode);
        Run_Tree->SetBranchAddress("tauByLooseIsolationMVArun2v1DBoldDMwLT",&tauByLooseIsolationMVArun2v1DBoldDMwLT);
        
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
        Run_Tree->SetBranchAddress("eleSCEta", &eleSCEta );
        
        /////////////////////////   Jet Info
        Run_Tree->SetBranchAddress("nJet",&nJet);
        Run_Tree->SetBranchAddress("jetPt",&jetPt);
        Run_Tree->SetBranchAddress("jetEta",&jetEta);
        Run_Tree->SetBranchAddress("jetPhi",&jetPhi);
        Run_Tree->SetBranchAddress("jetEn",&jetEn);
        Run_Tree->SetBranchAddress("jetpfCombinedInclusiveSecondaryVertexV2BJetTags",&jetpfCombinedInclusiveSecondaryVertexV2BJetTags);
        Run_Tree->SetBranchAddress("jetPFLooseId",&jetPFLooseId);
        Run_Tree->SetBranchAddress("jetPUidFullDiscriminant",&jetPUidFullDiscriminant);
        Run_Tree->SetBranchAddress("jetHadFlvr",&jetHadFlvr);
        
        Run_Tree->SetBranchAddress("jetRawPt",&jetRawPt);
        Run_Tree->SetBranchAddress("jetRawEn",&jetRawEn);
        Run_Tree->SetBranchAddress("jetJECUnc",&jetJECUnc);
        
        
        
        
        /////////////////////////   MET Info
        Run_Tree->SetBranchAddress("pfMET",&pfMET);
        Run_Tree->SetBranchAddress("pfMETPhi",&pfMETPhi);
        Run_Tree->SetBranchAddress("genHT",&genHT);
        Run_Tree->SetBranchAddress("metFilters",&metFilters);
        
        
        
        //###############################################################################################
        //  Weight Calculation
        //###############################################################################################
        Int_t nBin=500;
        Int_t binMin=0;
        Int_t binMax= 5000;
        
        
        float WSCALEFACTORE=1.00;  //measured July 4th from WEstimaOutPut/_16_80X
        float WSF_mutau=1.0;
        float WSF_etau=1.0;
        float MuMass= 0.10565837;
        float eleMass= 0.000511;
        float LeptonPtCut_=50;
        float TauPtCut_=50;
        float JetPtCut=50;
        float BJetPtCut=20;
        float LooseCSV= 0.460 ;                    //https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation74X
        float LeptonIsoCut=0.15;
        float tauES[3]={0.97,1.00,1.03};
        std::string Scale_Cat[3] = {"Down", "", "Up"};
        float jetES[3]={-1,0,1};
        std::string ScaleJet_Cat[3] = {"JetDown", "", "JetUp"};
        
        
        
        Int_t nentries_wtn = (Int_t) Run_Tree->GetEntries();
        cout<<"nentries_wtn===="<<nentries_wtn<<"\n";
        //        for (Int_t i = 0; i < 50000; i++) {
        for (Int_t i = 0; i < nentries_wtn; i++) {
            Run_Tree->GetEntry(i);
            if (i % 10000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
            fflush(stdout);
            
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
            plotFill("WeightTotal",TotalWeight,50,0,5);
            plotFill("nVtx_NoPUCorr",nVtx,60,0,60);
            plotFill("nVtx_PUCorr",nVtx,60,0,60,PUWeight);
            for (int qq=0; qq < 50;qq++){
                if ((HLTEleMuX >> qq & 1) == 1)
                    plotFill("HLT",qq,50,0,50);
            }
            //###############################################################################################
            size_t isSingleMu = InputROOT.find("SingleMu");
            size_t isSingleEle = InputROOT.find("SingleEle");
            //            size_t isTTJets = InputROOT.find("TTJets");
            size_t isWJets = InputROOT.find("WJets");
            //###############################################################################################
            
            
            
            //  Doing MuTau Analysis
            //###############################################################################################
            bool DoMuTauAnalysis=1;
            
            if (DoMuTauAnalysis &&   isSingleEle== string::npos) {
                //Loop over MuTau events
                for  (int imu=0 ; imu < nMu; imu++){
                    for  (int itau=0 ; itau < nTau; itau++){
                        for (int scale=0;scale < 3;scale++){
                            for (int jetScl=0;jetScl<3;jetScl++){
                                
                                if (scale !=1 && jetScl !=1 ) continue;
                                
                                
                                TLorentzVector Tau4Momentum;
                                Tau4Momentum.SetPtEtaPhiM(tauPt->at(itau)*tauES[scale],tauEta->at(itau),tauPhi->at(itau),tauMass->at(itau));
                                
                                float NewMET_x = pfMET * TMath::Cos(pfMETPhi) - (Tau4Momentum.Px()- tauPx->at(itau)) ;
                                float NewMET_y = pfMET * TMath::Sin(pfMETPhi) - (Tau4Momentum.Py()- tauPy->at(itau)) ;
                                float NewMET = sqrt (pow(NewMET_x,2)+ pow(NewMET_y,2));
                                float NewMETPhi = atan(NewMET_y / NewMET_x);
                                if (pfMETPhi > (TMath::Pi() / 2)) NewMETPhi += TMath::Pi();
                                if (pfMETPhi < (-TMath::Pi() / 2)) NewMETPhi -= TMath::Pi();
                                
                                
                                float IsoMu=muPFChIso->at(imu)/muPt->at(imu);
                                if ( (muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu) )  > 0.0)
                                    IsoMu= ( muPFChIso->at(imu)/muPt->at(imu) + muPFNeuIso->at(imu) + muPFPhoIso->at(imu) - 0.5* muPFPUIso->at(imu))/muPt->at(imu);
                                
                                bool MuPtCut = muPt->at(imu) > LeptonPtCut_ && fabs(muEta->at(imu)) < 2.1 ;
                                bool MuIdIso=(muIsTightID->at(imu) > 0  && fabs(muD0->at(imu)) < 0.045 && fabs(muDz->at(imu)) < 0.2);
                                bool TauPtCut = Tau4Momentum.Pt() > TauPtCut_  && fabs(Tau4Momentum.Eta()) < 2.3 ;
                                bool TauIdIso =  taupfTausDiscriminationByDecayModeFinding->at(itau) > 0.5 &&  tauByTightMuonRejection3->at(itau) > 0 && tauByMVA6LooseElectronRejection->at(itau) > 0 && fabs(tauDxy->at(itau)) < 0.05;
                                
                                
                                
                                float LepCorr=getCorrFactorMuon74X(isData,  muPt->at(imu), muEta->at(imu) , HistoMuId,HistoMuIso,HistoMuTrg);
                                plotFill("Weight_Mu",LepCorr,200,0,2);
                                
                                
                                
                                TLorentzVector Mu4Momentum, Z4Momentum, NewJet4Collection,ExtraMu4Momentum, ExtraEle4Momentum,Close4JetFinder,JetRaw4Momentum,Jet4Momentum;
                                Mu4Momentum.SetPtEtaPhiM(muPt->at(imu),muEta->at(imu),muPhi->at(imu),MuMass);
                                
                                Z4Momentum=Mu4Momentum+Tau4Momentum;
                                
                                
                                
                                //###########      Finding the close jet near tau   ###########################################################
                                float CLoseJetTauPt=Tau4Momentum.Pt();
                                float CLoseJetTauEta=Tau4Momentum.Eta();
                                float CLoseJetMuPt=muPt->at(imu);
                                float CLoseJetMuEta=muEta->at(imu);
                                
                                if (TauPtCut&& TauIdIso && MuPtCut && MuIdIso ){
                                    double Refer_R_jettau = 5;
                                    double Refer_R_jetmu = 5;
                                    
                                    for (int kjet= 0 ; kjet < nJet ; kjet++){
                                        Close4JetFinder.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
                                        
                                        if (Close4JetFinder.DeltaR(Tau4Momentum) < Refer_R_jettau) {
                                            Refer_R_jettau = Close4JetFinder.DeltaR(Tau4Momentum);
                                            if (Refer_R_jettau < 0.5 && jetPt->at(kjet)  >= Tau4Momentum.Pt()) {
                                                CLoseJetTauPt = jetPt->at(kjet);
                                                CLoseJetTauEta = jetEta->at(kjet);
                                                
                                            }
                                            
                                            
                                        }
                                        
                                        if (Close4JetFinder.DeltaR(Mu4Momentum) < Refer_R_jetmu) {
                                            Refer_R_jetmu = Close4JetFinder.DeltaR(Mu4Momentum);
                                            if (Refer_R_jetmu < 0.5 && jetPt->at(kjet)  >= muPt->at(imu)) {
                                                CLoseJetMuPt = jetPt->at(kjet);
                                                CLoseJetMuEta = jetEta->at(kjet);
                                                
                                            }
                                            
                                        }
                                        
                                        
                                    }
                                }
                                
                                
                                //###########      Extra Mu Veto   ###########################################################
                                bool extraMuonExist= false;
                                for  (int jmu=0 ; jmu < nMu; jmu++){
                                    ExtraMu4Momentum.SetPtEtaPhiM(muPt->at(jmu),muEta->at(jmu),muPhi->at(jmu),MuMass);
                                    
                                    if (ExtraMu4Momentum.DeltaR(Mu4Momentum) < 0.5  || ExtraMu4Momentum.DeltaR(Tau4Momentum) < 0.5 ) continue;
                                    if  ( muPt->at(jmu) < 15 ||  fabs(muEta->at(jmu)) > 2.4 ) continue ;
                                    
                                    float IsoMuExtra=muPFChIso->at(jmu)/muPt->at(jmu);
                                    if ( (muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu) )  > 0.0)
                                        IsoMuExtra= ( muPFChIso->at(jmu)/muPt->at(jmu) + muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu))/muPt->at(jmu);
                                    
                                    if (! (muIsLooseID->at(jmu) > 0 && IsoMuExtra < 0.25) ) continue;
                                    
                                    extraMuonExist=true;
                                }
                                //###########      Extra Ele Veto   ###########################################################
                                
                                bool extraElectronExist= false;
                                for  (int jele=0 ; jele < nEle; jele++){
                                    ExtraEle4Momentum.SetPtEtaPhiM(elePt->at(jele),eleEta->at(jele),elePhi->at(jele),eleMass);
                                    
                                    if (ExtraEle4Momentum.DeltaR(Mu4Momentum) < 0.5  || ExtraEle4Momentum.DeltaR(Tau4Momentum) < 0.5 ) continue;
                                    if ( elePt->at(jele) < 15 || fabs(eleEta->at(jele)) > 2.5) continue;
                                    
                                    float IsoEleExtra=elePFChIso->at(jele)/elePt->at(jele);
                                    if ( (elePFNeuIso->at(jele) + elePFPhoIso->at(jele) - 0.5* elePFPUIso->at(jele))  > 0.0)
                                        IsoEleExtra= (elePFChIso->at(jele)/elePt->at(jele) + elePFNeuIso->at(jele) + elePFPhoIso->at(jele) - 0.5* elePFPUIso->at(jele))/elePt->at(jele);
                                    
                                    bool eleMVAIdExtra= false;
                                    if (fabs (eleSCEta->at(jele)) < 0.8 && eleIDMVANonTrg->at(jele) >  0.913286 ) eleMVAIdExtra= true;
                                    else if (fabs (eleSCEta->at(jele)) >  0.8 &&fabs (eleSCEta->at(jele)) <  1.5 && eleIDMVANonTrg->at(jele) >  0.805013 ) eleMVAIdExtra= true;
                                    else if ( fabs (eleSCEta->at(jele)) >  1.5 && eleIDMVANonTrg->at(jele) >  0.358969  ) eleMVAIdExtra= true;
                                    else eleMVAIdExtra= false;
                                    
                                    
                                    if (!(eleMVAIdExtra && IsoEleExtra < 0.25)) continue;
                                    extraElectronExist= true;
                                    
                                }
                                
                                //###########      General   ###########################################################
                                
                                bool  GeneralMuTauSelection=  !extraMuonExist && !extraElectronExist && MuPtCut && TauPtCut && MuIdIso && TauIdIso && Mu4Momentum.DeltaR(Tau4Momentum) > 0.5;
                                
                                if (!GeneralMuTauSelection) continue;
                                
                                //###########      Jet definition   ###########################################################
                                vector<TLorentzVector> CentralJetVector;
                                vector<TLorentzVector> JetVector;
                                vector<TLorentzVector> BJetBVector;
                                vector<TLorentzVector> BJet20Vector;
                                vector<float> BJetVectorSF;
                                vector<float> BJetVectorSFUp;
                                vector<float> BJetVectorSFDown;
                                CentralJetVector.clear();
                                JetVector.clear();
                                BJetBVector.clear();
                                BJetVectorSF.clear();
                                BJetVectorSFUp.clear();
                                BJetVectorSFDown.clear();
                                BJet20Vector.clear();
                                
                                for (int ijet= 0 ; ijet < nJet ; ijet++){
                                    Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
//                                    JetRaw4Momentum.SetPtEtaPhiE(jetRawPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetRawEn->at(ijet));
                                    
//                                    jetScl=1;
//                                    float JetUncCor=jetJECUnc->at(ijet)*Jet4Momentum.Pt();
//                                    
//                                    
//                                    cout<< JetUncCor<< "  "<<jetJECUnc->at(ijet)<< "  "<< Jet4Momentum.Pt()<< "  "<<JetRaw4Momentum.Pt()<< " \t ";
                                    
                                    NewJet4Collection.SetPtEtaPhiE(Jet4Momentum.Pt()*(1+ jetES[jetScl]*jetJECUnc->at(ijet)) ,jetEta->at(ijet),jetPhi->at(ijet),Jet4Momentum.E()*(1+ jetES[jetScl]*jetJECUnc->at(ijet)));
//                                    cout<<NewJet4Collection.Pt()<<"\n";
                                    
                                    if (jetPFLooseId->at(ijet) > 0.5 && NewJet4Collection.Pt() > JetPtCut && fabs(NewJet4Collection.Eta()) < 2.4 && NewJet4Collection.DeltaR(Tau4Momentum) > 0.5 && NewJet4Collection.DeltaR(Mu4Momentum) > 0.5 ){
                                        JetVector.push_back(NewJet4Collection);
                                        CentralJetVector.push_back(Jet4Momentum);
                                        
                                        
                                        if (jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  LooseCSV  ){
                                            BJetBVector.push_back(NewJet4Collection);
                                            if (!isData) {
                                                
                                                BJetVectorSF.push_back(GetBJetSF(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                BJetVectorSFUp.push_back(GetBJetSFUp(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                BJetVectorSFDown.push_back(GetBJetSFDown(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                
                                            }
                                        }
                                    }
                                    if (jetPFLooseId->at(ijet) > 0.5 && NewJet4Collection.Pt() > BJetPtCut && fabs(NewJet4Collection.Eta()) < 2.4 && NewJet4Collection.DeltaR(Tau4Momentum) > 0.5 && NewJet4Collection.DeltaR(Mu4Momentum) > 0.5 && jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  LooseCSV ){
                                        BJet20Vector.push_back(NewJet4Collection);
                                    }
                                    
                                }
                                
                                
                                float ST_JetBjet,M_muj0,M_muj1,M_tauj0,M_tauj1, M_MuJet,M_TauJet,ST_DiJet,ST_MET =0;
                                
                                bool DiJet_Selection=JetVector.size() > 1;
                                bool DiNonBJet_Selection=JetVector.size() > 1 && BJet20Vector.size() < 1 ;
                                bool JetBJet_Selection=JetVector.size() > 1& BJetBVector.size()> 0 && (BJetBVector[0].Pt()== JetVector[0].Pt() || BJetBVector[0].Pt() ==JetVector[1].Pt());
                                float BtagSFLeadBJet=1;
                                float BtagSFLeadBJetUp=1;
                                float BtagSFLeadBJetDown=1;
                                if (!isData && JetBJet_Selection){
                                    
                                    BtagSFLeadBJet= BJetVectorSF[0];
                                    BtagSFLeadBJetUp= BJetVectorSFUp[0];
                                    BtagSFLeadBJetDown= BJetVectorSFDown[0];
                                    
                                }
                                
                                float jetMET=NewMET;
                                float jetMETPhi=NewMETPhi;
                                if (DiJet_Selection){
                                    
                                    if (CentralJetVector.size() < 2) CentralJetVector= JetVector;
                                    
                            float jetMET_x = NewMET * TMath::Cos(NewMETPhi) - (JetVector[0].Px()- CentralJetVector[0].Px())-(JetVector[1].Px()- CentralJetVector[1].Px())   ;
                            float jetMET_y = NewMET * TMath::Sin(NewMETPhi) - (JetVector[0].Py()- CentralJetVector[0].Py())-(JetVector[1].Py()- CentralJetVector[1].Py())   ;
//                                    cout << " jetMET_x="<<jetMET_x<<"   jetMET_y="<<jetMET_y<<"\n";
                             jetMET = sqrt (pow(jetMET_x,2)+ pow(jetMET_y,2));
                             jetMETPhi = atan(jetMET_y / jetMET_x);
                            if (NewMETPhi > (TMath::Pi() / 2)) jetMETPhi += TMath::Pi();
                            if (NewMETPhi < (-TMath::Pi() / 2)) jetMETPhi -= TMath::Pi();
//                                    cout <<jetScl <<" jetMET=  " <<jetMET << "  NewMET= " <<NewMET << "  0.Pt()" << JetVector[0].Pt() << "  Ce[0].Pt()" << CentralJetVector[0].Pt() << " [1].Pt()" << JetVector[1].Pt() << "  Cen[1].Pt()" << CentralJetVector[1].Pt()    <<"\n";
                                    
                                    
                                    
                                    
                                    
                                    ST_DiJet=JetVector[0].Pt()+JetVector[1].Pt()+muPt->at(imu)+Tau4Momentum.Pt();
                                    ST_MET=JetVector[0].Pt()+JetVector[1].Pt()+muPt->at(imu)+Tau4Momentum.Pt()+jetMET;
                                }
                                if (JetBJet_Selection){
                                    
                                    M_muj0= (Mu4Momentum+JetVector[0]).M();
                                    M_muj1= (Mu4Momentum+JetVector[1]).M();
                                    M_tauj0= (Tau4Momentum+JetVector[0]).M();
                                    M_tauj1= (Tau4Momentum+JetVector[1]).M();
                                    
                                    M_MuJet=M_muj0;
                                    M_TauJet=M_tauj1;
                                    if ( fabs(M_muj0-M_tauj1) > fabs(M_muj1-M_tauj0)){
                                        M_MuJet=M_muj1;
                                        M_TauJet=M_tauj0;
                                        
                                    }
                                }
                                
                                
                                
                                //###############################################################################################
                                // Tau Pt Reweighting
                                //###############################################################################################
                                float tauPtReweightingUp = 1 + 0.2 * (Tau4Momentum.Pt() / 1000);
                                float tauPtReweightingDown = 1 - 0.2 * (Tau4Momentum.Pt() / 1000);
                                //###############################################################################################
                                //  Tau Lep Charge Categorization
                                //###############################################################################################
                                const int size_Q = 3;
                                bool charge_No = 1;
                                bool charge_OS = muCharge->at(imu) * tauCharge->at(itau) < 0;
                                bool charge_SS = muCharge->at(imu) * tauCharge->at(itau) > 0;
                                bool charge_category[size_Q] = {1,charge_OS, charge_SS};
                                std::string q_Cat[size_Q] = {"","_OS", "_SS"};
                                
                                //###############################################################################################
                                //  Isolation Categorization
                                //###############################################################################################
                                bool TauPassIsolation= tauByLooseIsolationMVArun2v1DBoldDMwLT->at(itau) > 0.5 ;
                                bool LepPassIsolation= IsoMu < LeptonIsoCut;
                                //                        bool TauPassIsolation= tauByLooseCombinedIsolationDeltaBetaCorr3Hits->at(itau) > 0.5 ;
                                const int size_isoCat = 9;
                                bool Isolation = TauPassIsolation && LepPassIsolation;
                                bool AntiIsolation = !TauPassIsolation && !LepPassIsolation;
                                bool TauIsoLepAntiIso = TauPassIsolation && !LepPassIsolation;
                                bool TauAntiIsoLepIso = !TauPassIsolation && LepPassIsolation;
                                bool TauIso = TauPassIsolation;
                                bool TauAntiIso = !TauPassIsolation;
                                bool LepIso = LepPassIsolation;
                                bool LepAntiIso = !LepPassIsolation;
                                bool Total = 1;
                                
                                
                                bool Iso_category[size_isoCat] = {Isolation, AntiIsolation,TauIsoLepAntiIso,TauAntiIsoLepIso,TauIso,TauAntiIso,LepIso,LepAntiIso,Total};
                                std::string iso_Cat[size_isoCat] = {
                                    "", "_AntiIso","_TauIsoLepAntiIso","_TauAntiIsoLepIso","_TauIso","_TauAntiIso","_LepIso","_LepAntiIso","_Total"};
                                
                                //###############################################################################################
                                //  MT Categorization
                                //###############################################################################################
                                float tmass= TMass_F(muPt->at(imu), muPt->at(imu)*cos(muPhi->at(imu)),muPt->at(imu)*sin(muPhi->at(imu)) , jetMET, jetMETPhi);
                                const int size_mTCat = 1;
                                bool NoMT = 1;
                                bool LoWMT = tmass < 30;
                                bool HighMT = tmass > 70;
                                //                        bool MT_category[size_mTCat] = {NoMT,LoWMT,HighMT};
                                //                        std::string MT_Cat[size_mTCat] = {"", "_LowMT","_HighMT"};
                                bool MT_category[size_mTCat] = {NoMT};
                                std::string MT_Cat[size_mTCat] = {""};
                                
                                //###############################################################################################
                                //  Trigger Categorization
                                //###############################################################################################
                                //                        else if (name.find("HLT_Mu45_eta2p1_v") != string::npos) bitEleMuX = 26;
                                const int size_trgCat = 1;
                                bool PassTrigger=1;
                                if (isData) PassTrigger = (HLTEleMuX >> 26 & 1) == 1; //  else if (name.find("HLT_Mu45_eta2p1_v") != string::npos) bitEleMuX = 26;
                                //                        bool PassTrigger = (HLTEleMuX >> 25 & 1) == 1; // Exist both in data and MC HLT_IsoMu27_v
                                //                  bool PassTrigger = ((HLTEleMuX >> 29 & 1) == 1 && !isData) || ((HLTEleMuX >> 30 & 1) == 1 && isData); //IsoMu17_eta2p1 MC && IsoMu18 Data
                                bool NoTrigger = 1;
                                //                    bool Trigger_category[size_trgCat] = {PassTrigger, NoTrigger};
                                //                    std::string trg_Cat[size_trgCat] = {"", "_NoTrigger"};
                                bool Trigger_category[size_trgCat] = {PassTrigger};
                                std::string trg_Cat[size_trgCat] = {""};
                                
                                //###############################################################################################
                                //  ST Categorization
                                //###############################################################################################
                                const int size_ST = 2;
                                bool ST_category[size_ST] = {JetBJet_Selection,DiJet_Selection};
                                std::string ST_Cat[size_ST] = {"_JetBJet","_DiJet"};
                                //                            float TTScaleFactor[size_ST]={0.91,0.91};
                                float TTScaleFactor[size_ST]={1,1};
                                
                                //###############################################################################################
                                //  Analysis Categorization
                                //###############################################################################################
                                const int size_AN = 2;
                                bool PassLQ= M_TauJet > 250 ;
                                bool PassRW= jetMET > 50 && Z4Momentum.M() > 150 && Tau4Momentum.Pt() > 60;
                                bool AN_category[size_AN] = {PassLQ, PassRW};
                                std::string AN_Cat[size_AN] = {"_LQ","_RW"};
                                
                                
                                //###############################################################################################
                                
                                std::string CHANNEL="MuTau";
                                if (GeneralMuTauSelection){
                                    
                                    for (int an = 0; an < size_AN; an++) {
                                        if (AN_category[an]) {
                                            
                                            for (int qcat = 0; qcat < size_Q; qcat++) {
                                                if (charge_category[qcat]) {
                                                    for (int iso = 0; iso < size_isoCat; iso++) {
                                                        if (Iso_category[iso]) {
                                                            for (int imt = 0; imt < size_mTCat; imt++) {
                                                                if (MT_category[imt]) {
                                                                    for (int ist = 0; ist < size_ST; ist++) {
                                                                        if (ST_category[ist]) {
                                                                            
                                                                            //                                                                        if (isTTJets!= string::npos) NewTotalWeight=TotalWeight * TTScaleFactor[ist];  // Add TT scale factor
                                                                                if (isWJets!= string::npos) WSCALEFACTORE=WSF_mutau;  // Add W scale factor
                                                                            
                                                                            
                                                                            for (int trg = 0; trg < size_trgCat; trg++) {
                                                                                
                                                                                if (Trigger_category[trg]) {
                                                                                    
                                                                                    
                                                                                    std::string FullStringName = MT_Cat[imt] +q_Cat[qcat] + iso_Cat[iso] + trg_Cat[trg] +ST_Cat[ist]+Scale_Cat[scale]  + ScaleJet_Cat[jetScl];
                                                                                    float FullWeight= TotalWeight * LepCorr * BtagSFLeadBJet * WSCALEFACTORE;
                                                                                    
                                                                                    //                                                                    plotFill(CHANNEL+AN_Cat[an]+"_TauPt"+FullStringName,tauPt->at(itau),200,0,200,FullWeight);
                                                                                    plotFill(CHANNEL+AN_Cat[an]+"_CloseJetTauPt"+FullStringName,CLoseJetTauPt,1000,0,1000,FullWeight);
                                                                                    
                                                                                    plotFill(CHANNEL+AN_Cat[an]+"_ST_MET"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight);
                                                                                    
                                                                                    
                                                                                    
                                                                                    //////////////////////////////////////////////////////////////////////
                                                                                    /////Uncertainty on Btag Eff. and Mistag Rate
                                                                                    //////////////////////////////////////////////////////////////////////
                                                                                    
                                                                                    if ( scale==1 && jetScl==1){
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_MET_BtagUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight  * BtagSFLeadBJetUp/BtagSFLeadBJet) ;
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_MET_BtagDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * BtagSFLeadBJetDown/BtagSFLeadBJet) ;
                                                                                        
                                                                                        
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_METTauHighPtRWDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight *  tauPtReweightingDown);
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_METTauHighPtRWUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * tauPtReweightingUp);
                                                                                        
                                                                                        if (isTTJets!= string::npos) plotFill(CHANNEL+AN_Cat[an]+"_ST_METTopPtRWUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * TopPtReweighting);
                                                                                        if (isTTJets!= string::npos) plotFill(CHANNEL+AN_Cat[an]+"_ST_METTopPtRWDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight / TopPtReweighting);
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
                                }
                            }
                        }
                    }
                }
            }
            
            
            //###############################################################################################
            //  Doing EleTau Analysis
            //###############################################################################################
            bool DoEleTauAnalysis=1;
            if (DoEleTauAnalysis  &&   isSingleMu== string::npos) {
                
                
                
                //loop over eleTau Channels
                
                for  (int iele=0 ; iele < nEle; iele++){
                    for  (int itau=0 ; itau < nTau; itau++){
                        
                        
                        for (int scale=0;scale < 3;scale++){
                            for (int jetScl=0;jetScl<3;jetScl++){
                                
                                if (scale !=1 && jetScl !=1 ) continue;
                                
                                TLorentzVector Tau4Momentum;
                                Tau4Momentum.SetPtEtaPhiM(tauPt->at(itau)*tauES[scale],tauEta->at(itau),tauPhi->at(itau),tauMass->at(itau));
                                
                                float NewMET_x = pfMET * TMath::Cos(pfMETPhi) - (Tau4Momentum.Px()- tauPx->at(itau)) ;
                                float NewMET_y = pfMET * TMath::Sin(pfMETPhi) - (Tau4Momentum.Py()- tauPy->at(itau)) ;
                                float NewMET = sqrt (pow(NewMET_x,2)+ pow(NewMET_y,2));
                                float NewMETPhi = atan(NewMET_y / NewMET_x);
                                if (pfMETPhi > (TMath::Pi() / 2)) NewMETPhi += TMath::Pi();
                                if (pfMETPhi < (-TMath::Pi() / 2)) NewMETPhi -= TMath::Pi();
                                
                                
                                
                                float IsoEle=elePFChIso->at(iele)/elePt->at(iele);
                                if ( (elePFNeuIso->at(iele) + elePFPhoIso->at(iele) - 0.5* elePFPUIso->at(iele))  > 0.0)
                                    IsoEle= (elePFChIso->at(iele)/elePt->at(iele) + elePFNeuIso->at(iele) + elePFPhoIso->at(iele) - 0.5* elePFPUIso->at(iele))/elePt->at(iele);
                                
                                bool eleMVAId= false;
                                if (fabs (eleSCEta->at(iele)) < 0.8 && eleIDMVANonTrg->at(iele) > 0.967083) eleMVAId= true;
                                else if (fabs (eleSCEta->at(iele)) >  0.8 &&fabs (eleSCEta->at(iele)) <  1.5 && eleIDMVANonTrg->at(iele) > 0.929117) eleMVAId= true;
                                else if ( fabs (eleSCEta->at(iele)) >  1.5 && eleIDMVANonTrg->at(iele) > 0.726311 ) eleMVAId= true;
                                else eleMVAId= false;
                                
                                
                                TLorentzVector Ele4Momentum, Z4Momentum, NewJet4Collection,ExtraMu4Momentum, ExtraEle4Momentum,Close4JetFinder,JetRaw4Momentum,Jet4Momentum;
                                
                                Ele4Momentum.SetPtEtaPhiM(elePt->at(iele),eleEta->at(iele),elePhi->at(iele),eleMass);
                                Z4Momentum=Ele4Momentum+Tau4Momentum;
                                
                                
                                bool ElePtCut = elePt->at(iele) > LeptonPtCut_ && fabs(eleEta->at(iele)) < 2.1 ;
                                bool TauPtCut = Tau4Momentum.Pt() > TauPtCut_  && fabs(Tau4Momentum.Eta()) < 2.3 ;
                                bool EleIdIso= 1;
                                bool TauIdIso = taupfTausDiscriminationByDecayModeFinding->at(itau) > 0.5 &&  tauByLooseMuonRejection3->at(itau) > 0 && tauByMVA6MediumElectronRejection->at(itau) > 0 &&  fabs(tauDxy->at(itau)) < 0.05;
                                
                                
                                
                                
                                //###########      Finding the close jet near tau   ###########################################################
                                float CLoseJetTauPt=Tau4Momentum.Pt();
                                float CLoseJetTauEta=Tau4Momentum.Eta();
                                float CLoseJetElePt=elePt->at(iele);
                                float CLoseJetEleEta=eleEta->at(iele);
                                
                                if (TauPtCut&& TauIdIso && ElePtCut && EleIdIso ){
                                    double Refer_R_jettau = 5;
                                    double Refer_R_jetele = 5;
                                    
                                    for (int kjet= 0 ; kjet < nJet ; kjet++){
                                        Close4JetFinder.SetPtEtaPhiE(jetPt->at(kjet),jetEta->at(kjet),jetPhi->at(kjet),jetEn->at(kjet));
                                        
                                        if (Close4JetFinder.DeltaR(Tau4Momentum) < Refer_R_jettau) {
                                            Refer_R_jettau = Close4JetFinder.DeltaR(Tau4Momentum);
                                            if (Refer_R_jettau < 0.5 && jetPt->at(kjet)  >= Tau4Momentum.Pt()) {
                                                CLoseJetTauPt = jetPt->at(kjet);
                                                CLoseJetTauEta = jetEta->at(kjet);
                                                
                                            }
                                            
                                            
                                        }
                                        
                                        if (Close4JetFinder.DeltaR(Ele4Momentum) < Refer_R_jetele) {
                                            Refer_R_jetele = Close4JetFinder.DeltaR(Ele4Momentum);
                                            if (Refer_R_jetele < 0.5 && jetPt->at(kjet)  >= elePt->at(iele)) {
                                                CLoseJetElePt = jetPt->at(kjet);
                                                CLoseJetEleEta = jetEta->at(kjet);
                                                
                                            }
                                        }
                                    }
                                }
                                

                                
                                //###########      Extra Mu Veto   ###########################################################
                                bool extraMuonExist= false;
                                for  (int jmu=0 ; jmu < nMu; jmu++){
                                    
                                    ExtraMu4Momentum.SetPtEtaPhiM(muPt->at(jmu),muEta->at(jmu),muPhi->at(jmu),MuMass);
                                    
                                    if (ExtraMu4Momentum.DeltaR(Ele4Momentum) < 0.5  || ExtraMu4Momentum.DeltaR(Tau4Momentum) < 0.5 ) continue;
                                    if  ( muPt->at(jmu) < 15 ||  fabs(muEta->at(jmu)) > 2.4 ) continue ;
                                    
                                    float IsoMuExtra=muPFChIso->at(jmu)/muPt->at(jmu);
                                    if ( (muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu) )  > 0.0)
                                        IsoMuExtra= ( muPFChIso->at(jmu)/muPt->at(jmu) + muPFNeuIso->at(jmu) + muPFPhoIso->at(jmu) - 0.5* muPFPUIso->at(jmu))/muPt->at(jmu);
                                    
                                    if (! (muIsLooseID->at(jmu) > 0 && IsoMuExtra < 0.25) ) continue;
                                    
                                    extraMuonExist=true;
                                }
                                //###########      Extra Ele Veto   ###########################################################
                                
                                bool extraElectronExist= false;
                                for  (int jele=0 ; jele < nEle; jele++){
                                    
                                    ExtraEle4Momentum.SetPtEtaPhiM(elePt->at(jele),eleEta->at(jele),elePhi->at(jele),eleMass);
                                    
                                    if (ExtraEle4Momentum.DeltaR(Ele4Momentum) < 0.5  || ExtraEle4Momentum.DeltaR(Tau4Momentum) < 0.5 ) continue;
                                    if ( elePt->at(jele) < 15 || fabs(eleEta->at(jele)) > 2.5) continue;
                                    
                                    float IsoEleExtra=elePFChIso->at(jele)/elePt->at(jele);
                                    if ( (elePFNeuIso->at(jele) + elePFPhoIso->at(jele) - 0.5* elePFPUIso->at(jele))  > 0.0)
                                        IsoEleExtra= (elePFChIso->at(jele)/elePt->at(jele) + elePFNeuIso->at(jele) + elePFPhoIso->at(jele) - 0.5* elePFPUIso->at(jele))/elePt->at(jele);
                                    
                                    bool eleMVAIdExtra= false;
                                    if (fabs (eleSCEta->at(jele)) < 0.8 && eleIDMVANonTrg->at(jele) >  0.913286 ) eleMVAIdExtra= true;
                                    else if (fabs (eleSCEta->at(jele)) >  0.8 &&fabs (eleSCEta->at(jele)) <  1.5 && eleIDMVANonTrg->at(jele) >  0.805013 ) eleMVAIdExtra= true;
                                    else if ( fabs (eleSCEta->at(jele)) >  1.5 && eleIDMVANonTrg->at(jele) >  0.358969  ) eleMVAIdExtra= true;
                                    else eleMVAIdExtra= false;
                                    
                                    
                                    if (!(eleMVAIdExtra && IsoEleExtra < 0.25)) continue;
                                    extraElectronExist= true;
                                    
                                }
                                
                                //###########      General  ###########################################################
                                
                                bool GeneralEleTauSelection=  !extraMuonExist && !extraElectronExist && ElePtCut && TauPtCut && EleIdIso && TauIdIso  && Ele4Momentum.DeltaR(Tau4Momentum) > 0.5;
                                if (! GeneralEleTauSelection) continue;
                                
                                float LepCorr=getCorrFactorElectron74X(isData,  elePt->at(iele), eleSCEta->at(iele) , HistoEleSF);
                                plotFill("Weight_Ele",LepCorr,200,0,2);
                                
                                
                                
                                //###########      Jet definition   ###########################################################
                                vector<TLorentzVector> CentralJetVector;
                                vector<TLorentzVector> JetVector;
                                vector<TLorentzVector> BJetBVector;
                                vector<TLorentzVector> BJet20Vector;
                                vector<float> BJetVectorSF;
                                vector<float> BJetVectorSFUp;
                                vector<float> BJetVectorSFDown;
                                CentralJetVector.clear();
                                JetVector.clear();
                                BJetBVector.clear();
                                BJetVectorSF.clear();
                                BJetVectorSFUp.clear();
                                BJetVectorSFDown.clear();
                                BJet20Vector.clear();
                                
                                for (int ijet= 0 ; ijet < nJet ; ijet++){
                                    Jet4Momentum.SetPtEtaPhiE(jetPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetEn->at(ijet));
                                    //                                    JetRaw4Momentum.SetPtEtaPhiE(jetRawPt->at(ijet),jetEta->at(ijet),jetPhi->at(ijet),jetRawEn->at(ijet));
                                    
                                    //                                    jetScl=1;
                                    //                                    float JetUncCor=jetJECUnc->at(ijet)*Jet4Momentum.Pt();
                                    //
                                    //
                                    //                                    cout<< JetUncCor<< "  "<<jetJECUnc->at(ijet)<< "  "<< Jet4Momentum.Pt()<< "  "<<JetRaw4Momentum.Pt()<< " \t ";
                                    
                                    NewJet4Collection.SetPtEtaPhiE(Jet4Momentum.Pt()*(1+ jetES[jetScl]*jetJECUnc->at(ijet)) ,jetEta->at(ijet),jetPhi->at(ijet),Jet4Momentum.E()*(1+ jetES[jetScl]*jetJECUnc->at(ijet)));
                                    //                                    cout<<NewJet4Collection.Pt()<<"\n";
                                    
                                    if (jetPFLooseId->at(ijet) > 0.5 && NewJet4Collection.Pt() > JetPtCut && fabs(NewJet4Collection.Eta()) < 2.4 && NewJet4Collection.DeltaR(Tau4Momentum) > 0.5 && NewJet4Collection.DeltaR(Ele4Momentum) > 0.5 ){
                                        JetVector.push_back(NewJet4Collection);
                                        CentralJetVector.push_back(Jet4Momentum);
                                        
                                        
                                        if (jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  LooseCSV  ){
                                            BJetBVector.push_back(NewJet4Collection);
                                            if (!isData) {
                                                
                                                BJetVectorSF.push_back(GetBJetSF(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                BJetVectorSFUp.push_back(GetBJetSFUp(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                BJetVectorSFDown.push_back(GetBJetSFDown(NewJet4Collection.Pt(),NewJet4Collection.Eta(),jetHadFlvr->at(ijet)));
                                                
                                            }
                                        }
                                    }
                                    if (jetPFLooseId->at(ijet) > 0.5 && NewJet4Collection.Pt() > BJetPtCut && fabs(NewJet4Collection.Eta()) < 2.4 && NewJet4Collection.DeltaR(Tau4Momentum) > 0.5 && NewJet4Collection.DeltaR(Ele4Momentum) > 0.5 && jetpfCombinedInclusiveSecondaryVertexV2BJetTags->at(ijet) >  LooseCSV ){
                                        BJet20Vector.push_back(NewJet4Collection);
                                    }
                                    
                                }
                                
                                
                                float ST_JetBjet,M_elej0,M_elej1,M_tauj0,M_tauj1, M_EleJet,M_TauJet,ST_DiJet,ST_MET =0;
                                
                                bool DiJet_Selection=JetVector.size() > 1;
                                bool DiNonBJet_Selection=JetVector.size() > 1 && BJet20Vector.size() < 1 ;
                                bool JetBJet_Selection=JetVector.size() > 1& BJetBVector.size()> 0 && (BJetBVector[0].Pt()== JetVector[0].Pt() || BJetBVector[0].Pt() ==JetVector[1].Pt());
                                float BtagSFLeadBJet=1;
                                float BtagSFLeadBJetUp=1;
                                float BtagSFLeadBJetDown=1;
                                if (!isData && JetBJet_Selection){
                                    
                                    BtagSFLeadBJet= BJetVectorSF[0];
                                    BtagSFLeadBJetUp= BJetVectorSFUp[0];
                                    BtagSFLeadBJetDown= BJetVectorSFDown[0];
                                    
                                }
                                float jetMET=NewMET;
                                float jetMETPhi=NewMETPhi;
                                if (DiJet_Selection){
                                    
                                    if (CentralJetVector.size() < 2) CentralJetVector= JetVector;
                                    
                                    float jetMET_x = NewMET * TMath::Cos(NewMETPhi) - (JetVector[0].Px()- CentralJetVector[0].Px())-(JetVector[1].Px()- CentralJetVector[1].Px())   ;
                                    float jetMET_y = NewMET * TMath::Sin(NewMETPhi) - (JetVector[0].Py()- CentralJetVector[0].Py())-(JetVector[1].Py()- CentralJetVector[1].Py())   ;
                                     jetMET = sqrt (pow(jetMET_x,2)+ pow(jetMET_y,2));
                                     jetMETPhi = atan(jetMET_y / jetMET_x);
                                    if (NewMETPhi > (TMath::Pi() / 2)) jetMETPhi += TMath::Pi();
                                    if (NewMETPhi < (-TMath::Pi() / 2)) jetMETPhi -= TMath::Pi();
//                                    cout <<jetScl <<" jetMET=  " <<jetMET << "  NewMET= " <<NewMET << "  0.Pt()" << JetVector[0].Pt() << "  Ce[0].Pt()" << CentralJetVector[0].Pt() << " [1].Pt()" << JetVector[1].Pt() << "  Cen[1].Pt()" << CentralJetVector[1].Pt()    <<"\n";
                                    
                                    
                                    
                                    
                                    
                                    ST_DiJet=JetVector[0].Pt()+JetVector[1].Pt()+elePt->at(iele)+Tau4Momentum.Pt();
                                    ST_MET=JetVector[0].Pt()+JetVector[1].Pt()+elePt->at(iele)+Tau4Momentum.Pt()+jetMET;
                                }

                                
                                if (JetBJet_Selection){
                                    
                                    M_elej0= (Ele4Momentum+JetVector[0]).M();
                                    M_elej1= (Ele4Momentum+JetVector[1]).M();
                                    M_tauj0= (Tau4Momentum+JetVector[0]).M();
                                    M_tauj1= (Tau4Momentum+JetVector[1]).M();
                                    
                                    M_EleJet=M_elej0;
                                    M_TauJet=M_tauj1;
                                    if ( fabs(M_elej0-M_tauj1) > fabs(M_elej1-M_tauj0)){
                                        M_EleJet=M_elej1;
                                        M_TauJet=M_tauj0;
                                        
                                    }
                                }
                                
                                
                                
                                //###############################################################################################
                                // Tau Pt Reweighting
                                //###############################################################################################
                                float tauPtReweightingUp = 1 + 0.2 * (Tau4Momentum.Pt() / 1000);
                                float tauPtReweightingDown = 1 - 0.2 * (Tau4Momentum.Pt() / 1000);
                                //###############################################################################################
                                //  Tau Lep Charge Categorization
                                //###############################################################################################
                                const int size_Q = 3;
                                bool charge_No = 1;
                                bool charge_OS = eleCharge->at(iele) * tauCharge->at(itau) < 0;
                                bool charge_SS = eleCharge->at(iele) * tauCharge->at(itau) > 0;
                                bool charge_category[size_Q] = {1,charge_OS, charge_SS};
                                std::string q_Cat[size_Q] = {"","_OS", "_SS"};
                                
                                //###############################################################################################
                                // Isolation Categorization
                                //###############################################################################################
                                bool TauPassIsolation= tauByLooseIsolationMVArun2v1DBoldDMwLT->at(itau) > 0.5 ;
                                const int size_isoCat = 9;
                                bool Isolation = TauPassIsolation && eleMVAId;
                                bool AntiIsolation = !TauPassIsolation&&  !eleMVAId;
                                bool TauIsoLepAntiIso = TauPassIsolation &&!eleMVAId;
                                bool TauAntiIsoLepIso = !TauPassIsolation && eleMVAId;
                                bool TauIso = TauPassIsolation;
                                bool TauAntiIso = !TauPassIsolation;
                                bool LepIso = eleMVAId;
                                bool LepAntiIso = !eleMVAId;
                                bool Total = 1;
                                
                                
                                bool Iso_category[size_isoCat] = {Isolation, AntiIsolation,TauIsoLepAntiIso,TauAntiIsoLepIso,TauIso,TauAntiIso,LepIso,LepAntiIso,Total};
                                std::string iso_Cat[size_isoCat] = {
                                    "", "_AntiIso","_TauIsoLepAntiIso","_TauAntiIsoLepIso","_TauIso","_TauAntiIso","_LepIso","_LepAntiIso","_Total"};
                                
                                
                                
                                //###############################################################################################
                                //  MT Categorization
                                //###############################################################################################
                                float tmass= TMass_F(elePt->at(iele), elePt->at(iele)*cos(elePhi->at(iele)),elePt->at(iele)*sin(elePhi->at(iele)) ,  jetMET, jetMETPhi);
                                const int size_mTCat = 1;
                                bool NoMT = 1;
                                bool LoWMT = tmass < 30;
                                bool HighMT = tmass > 70;
                                bool MT_category[size_mTCat] = {NoMT};
                                std::string MT_Cat[size_mTCat] = {""};
                                //                        bool MT_category[size_mTCat] = {NoMT,LoWMT,HighMT};
                                //                        std::string MT_Cat[size_mTCat] = {"", "_LowMT","_HighMT"};
                                
                                //###############################################################################################
                                //  Trigger Categorization
                                //###############################################################################################
                                //https://twiki.cern.ch/twiki/bin/view/CMS/ElectronScaleFactorsRun2
                                const int size_trgCat = 1;
                                //                            bool PassTrigger = (HLTEleMuX >> 0 & 1) == 1 || (HLTEleMuX >> 11 & 1) == 1;
                                //                            bool PassTrigger = (HLTEleMuX >> 0 & 1) == 1 || (HLTEleMuX >> 1 & 1) == 1 || (HLTEleMuX >> 6 & 1) == 1|| (HLTEleMuX >> 11 & 1) == 1;
                                bool PassTrigger = 1;
                                if (isData) PassTrigger = (HLTEleMuX >> 54 & 1) == 1; //   else if (name.find("HLT_Ele45_WPLoose_Gsf_v") != string::npos) bitEleMuX = 54;
//                                if (isData) PassTrigger = (HLTEleMuX >> 2 & 1) == 1; //   else if (name.find("HLT_Ele27_ep1_WPLoose_Gsf_v") != string::npos)
                                //                        bool PassTrigger =   ((HLTEleMuX >> 6 & 1) == 1 && isData )|| ((HLTEleMuX >> 11 & 1) == 1 && !isData );
                                
                                bool NoTrigger = 1;
                                //                    bool Trigger_category[size_trgCat] = {PassTrigger, NoTrigger};
                                //                    std::string trg_Cat[size_trgCat] = {"", "_NoTrigger"};
                                bool Trigger_category[size_trgCat] = {PassTrigger};
                                std::string trg_Cat[size_trgCat] = {""};
                                
                                //###############################################################################################
                                //  ST Categorization
                                //###############################################################################################
                                const int size_ST = 2;
                                bool ST_category[size_ST] = {JetBJet_Selection,DiJet_Selection};
                                std::string ST_Cat[size_ST] = {"_JetBJet","_DiJet"};
                                //                            float TTScaleFactor[size_ST]={0.91,0.91};
                                float TTScaleFactor[size_ST]={1,1};
                                
                                //###############################################################################################
                                //  Analysis Categorization
                                //###############################################################################################
                                const int size_AN = 2;
                                bool PassLQ= M_TauJet > 250;                                
                                bool PassRW= jetMET > 50 && Z4Momentum.M() > 150 && Tau4Momentum.Pt() > 60;
                                
                                bool AN_category[size_AN] = {PassLQ, PassRW};
                                std::string AN_Cat[size_AN] = {"_LQ","_RW"};
                                
                                
                                //###############################################################################################
                                
                                
                                std::string CHANNEL="EleTau";
                                for (int an = 0; an < size_AN; an++) {
                                    if (AN_category[an]) {
                                        
                                        if (GeneralEleTauSelection){
                                            for (int qcat = 0; qcat < size_Q; qcat++) {
                                                if (charge_category[qcat]) {
                                                    for (int iso = 0; iso < size_isoCat; iso++) {
                                                        if (Iso_category[iso]) {
                                                            for (int imt = 0; imt < size_mTCat; imt++) {
                                                                if (MT_category[imt]) {
                                                                    for (int ist = 0; ist < size_ST; ist++) {
                                                                        if (ST_category[ist]) {
                                                                            
                                                                            //                                                                        if (isTTJets!= string::npos) NewTotalWeight=TotalWeight * TTScaleFactor[ist];  // Add TT scale factor
                                                                            if (isWJets!= string::npos) WSCALEFACTORE=WSF_etau;  // Add W scale factor
                                                                            
                                                                            
                                                                            
                                                                            for (int trg = 0; trg < size_trgCat; trg++) {
                                                                                if (Trigger_category[trg]) {
                                                                                    
                                                                                    
                                                                                    std::string FullStringName = MT_Cat[imt] +q_Cat[qcat] + iso_Cat[iso] +trg_Cat[trg]+ST_Cat[ist] + Scale_Cat[scale] + ScaleJet_Cat[jetScl];
                                                                                    float FullWeight= TotalWeight * LepCorr * BtagSFLeadBJet * WSCALEFACTORE;
                                                                                    
                                                                                    plotFill(CHANNEL+AN_Cat[an]+"_CloseJetTauPt"+FullStringName,CLoseJetTauPt,1000,0,1000,FullWeight);
                                                                                    
                                                                                    plotFill(CHANNEL+AN_Cat[an]+"_ST_MET"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight);
                                                                                    
                                                                                    //////////////////////////////////////////////////////////////////////
                                                                                    /////Uncertainty on Btag Eff. and Mistag Rate
                                                                                    //////////////////////////////////////////////////////////////////////
                                                                                    if ( scale==1 && jetScl==1){
                                                                                        
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_MET_BtagUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight  * BtagSFLeadBJetUp/BtagSFLeadBJet) ;
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_MET_BtagDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * BtagSFLeadBJetDown/BtagSFLeadBJet) ;
                                                                                        
                                                                                        
                                                                                        
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_METTauHighPtRWDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight *  tauPtReweightingDown);
                                                                                        plotFill(CHANNEL+AN_Cat[an]+"_ST_METTauHighPtRWUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * tauPtReweightingUp );
                                                                                        
                                                                                        if (isTTJets!= string::npos) plotFill(CHANNEL+AN_Cat[an]+"_ST_METTopPtRWUp"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight * TopPtReweighting);
                                                                                        if (isTTJets!= string::npos) plotFill(CHANNEL+AN_Cat[an]+"_ST_METTopPtRWDown"+FullStringName,ST_MET,nBin,binMin,binMax,FullWeight / TopPtReweighting);
                                                                                        
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
                                }
                            }
                        }
                    }
                    
                    
                } //End of Tree
            }//End of file
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


