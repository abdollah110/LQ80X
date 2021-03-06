#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.
#http://root.cern.ch/viewvc/trunk/tutorials/pyroot/hsimple.py?revision=20881&view=markup
__author__ = "abdollahmohammadi"
__date__ = "$Feb 23, 2013 10:39:33 PM$"

import math
import ROOT
from ROOT import Double
from ROOT import TCanvas
from ROOT import TFile
from ROOT import TH1F
from ROOT import TH2F
from ROOT import TNtuple
from ROOT import TProfile
from ROOT import gBenchmark
from ROOT import gROOT
from ROOT import gRandom
from ROOT import gSystem
from ctypes import *
import ROOT as r
import array

##### Get Jet to Tau FR
from Step4_TauFakeRateData import Make_Tau_FakeRate
from Step4_TauFakeRateData import _FIT_Jet_Function
##### Get Jet to Tau FR

gROOT.Reset()
import os




ROOT.gROOT.SetBatch(True)
#ROOT.gROOT.ProcessLine('.x rootlogon.C')
#SubRootDir = 'OutFiles_FullSelection_Buggy/'
#SubRootDir = 'OutFiles_FullSelection/'
#SubRootDir = 'OutFiles_FullSelection_MediumIso/'
#SubRootDir = 'OutFiles_FullSelection_TightIso/'
#SubRootDir = 'OutFiles_FullSelection/'
SubRootDir = 'OutFiles_FullSelection/'



verbos_ = False
#OS_SS_Ratio=1.06
OS_SS_Ratio=1.00
RB_=10

TauScale = ["Down", "", "Up"]
#TauScale = ["", "", ""]
JetScale = ["JetDown", "", "JetUp"]
SystematicHighPtTau = ["TauHighPtRWUp","TauHighPtRWDown"]
SystematicTopPtReWeight = ["TopPtRWUp","TopPtRWDown"]
#SystematicWShape = ["_WShapeUp","_WShapeDown"]
#TauScale = ["", "", ""]
#POSTFIX=["","Up","Down"]





#channelDirectory = ["MuTau", "eleTau"]
#channelDirectory = ["MuTau", "EleTau"]
FinalName = ["_mt", "_et"]

####################################################
##   Functions
####################################################






############################################################################################################
def _FileReturn(Name, channel,cat,HistoName,PostFix,PostFixJet,CoMEnergy):

    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name +CoMEnergy+ '.root')
    print "##### --->>>>>>> File name is ", SubRootDir + Name +CoMEnergy+ '.root'  "   and histo is -->  ", channel+HistoName + cat+ PostFix+PostFixJet
    Histo =  myfile.Get(channel+HistoName + cat+ PostFix+PostFixJet)
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD,CoMEnergy,chl,Binning,Analysis):
    
    
    if Analysis=="lq":
        signal = ['LQ_']
        signalName = ['LQ_']
        mass = [200,250, 300, 350, 400, 450, 500, 550,  600, 650, 700, 750, 800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]
        TOTMASS = [200,250, 300, 350, 400, 450, 500, 550,  600, 650, 700, 750, 800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]
#        mass = [700]
#        TOTMASS = [700]
        lenghtSig = len(signal) * len(mass) +1
        category = ["_JetBJet"]
        charge="_OS"

    if Analysis=="RHW":
        signal = ['RHW_']
        signalName = ['RHW_']
#        mass = ['2000-1000']
#        TOTMASS = ['2000']
#        mass = ['1000-500','1500-750','2000-1000','2500-1250','3000-1500']
#        TOTMASS = ['1000','1500','2000','2500','3000']
#        mass = ['1000-500','2000-1000','3000-1500','4000-2000','5000-2500','6000-3000']
#        TOTMASS = ['1000','2000','3000',4000,5000,6000]
        mass = ['1000-500', '1500-750' ,'2000-1000','2500-1250' ,'3000-1500','3500-1750' ,'4000-2000']
        
        mass = [
        
'1000_MNu-250',
'1000_MNu-500',
'1000_MNu-750',
'1500_MNu-1000',
'1500_MNu-1250',
'1500_MNu-250',
'1500_MNu-500',
'1500_MNu-750',
'2000_MNu-1000',
'2000_MNu-1250',
'2000_MNu-1500',
'2000_MNu-1750',
'2000_MNu-500',
'2000_MNu-750',
'2500_MNu-1000',
'2500_MNu-1250',
'2500_MNu-1500',
'2500_MNu-1750',
'2500_MNu-2000',
'2500_MNu-2250',
'2500_MNu-500',
'2500_MNu-750',
'3000_MNu-1000',
'3000_MNu-1250',
'3000_MNu-1500',
'3000_MNu-1750',
'3000_MNu-2000',
'3000_MNu-2250',
'3000_MNu-2500',
'3000_MNu-2750',
'3000_MNu-750',
'3500_MNu-1000',
'3500_MNu-1250',
'3500_MNu-1500',
'3500_MNu-1750',
'3500_MNu-2000',
'3500_MNu-2250',
'3500_MNu-2500',
'3500_MNu-2750',
'3500_MNu-3000',
'3500_MNu-3250',
'3500_MNu-750',
'4000_MNu-1000',
'4000_MNu-1250',
'4000_MNu-1500',
'4000_MNu-1750',
'4000_MNu-2000',
'4000_MNu-2250',
'4000_MNu-2500',
'4000_MNu-2750',
'4000_MNu-3000',
'4000_MNu-3250',
'4000_MNu-3500',
'4000_MNu-3750'
]
        
        
        
        TOTMASS = ['1000','1500','2000','2500','3000','3500',4000]
        lenghtSig = len(signal) * len(mass) +1
        category = ["_DiJet"]
        charge=""

    
#    print "\n\n\n\n\n\n ****** ------------------------------>     Starting for ",NormMC, "in Channel= ",channel

    TauScaleOut = ["_CMS_scale_t_"+channel+CoMEnergy+"Down", "", "_CMS_scale_t_"+channel+CoMEnergy+"Up"]
    JetScaleOut = ["_CMS_scale_j"+CoMEnergy+"Down", "", "_CMS_scale_j"+CoMEnergy+"Up"]
    Signal_Unc_HighPtTau = ["_CMS_eff_t_HighPtTau_"+channel+CoMEnergy+"Up","_CMS_eff_t_HighPtTau_"+channel+CoMEnergy+"Down"]
    Signal_Unc_TopPTRW = ["_CMS_top_pt_Reweighting"+CoMEnergy+"Up","_CMS_top_pt_Reweighting"+CoMEnergy+"Down"]
    Signal_Unc_WShape = ["_CMS_W_Shape_"+channel+CoMEnergy+"Up","_CMS_W_Shape_"+channel+CoMEnergy+"Down"]

    myOut = TFile(Analysis+FinalName[chl]+"_AllMass.inputs-sm-13TeV.root" , 'RECREATE') # Name Of the output file


    icat=-1
    for NameCat in category:
        icat =icat +1
        print "starting NameCat and channel and HistoName ", NameCat, channel, NormMC

        tDirectory= myOut.mkdir(channel + str(NameCat))
        tDirectory.cd()
        for tscale in range(len(TauScale)):
            for jscale in range(len(JetScale)):
                if tscale != 1 and jscale!=1 : continue
               ################################################
               #   Filling Signal
    #           ################################################
                for sig in range(len(signal)):
                    for m in range(len(mass)):

                        print "--------------------------------------------------->     Processing  Signal ", signal[sig],mass[m]
                        tDirectory.cd()

                        Name= str(signal[sig])+str(mass[m])
                        if Analysis=="lq": NameOut= str(signalName[sig]) +str(TOTMASS[m])+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                        if Analysis=="RHW": NameOut= str(signalName[sig]) +str(m+1)+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                                
                        NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)
            
                        ###############  Systematics on Shape and Norm for  High Tau Pt ####
                        if  tscale==1 and jscale==1:
                            for systHighpt in range(len(SystematicHighPtTau)):
                                tDirectory.cd()
                                Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+charge
                                if Analysis=="lq": NameOut= str(signalName[sig]) +str(TOTMASS[m])+str(Signal_Unc_HighPtTau[systHighpt])
                                if Analysis=="RHW": NameOut= str(signalName[sig]) +str(m+1)+str(Signal_Unc_HighPtTau[systHighpt])
                                
                                NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                                NormHisto=NormFile.Get("XXX")
                                
                                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                                tDirectory.WriteObject(RebinedHist,NameOut)
            
                ################################################
                #  Filling SingleTop
                ################################################
                print "--------------------------------------------------->     Processing SingleTop"
                tDirectory.cd()
            
                Name= "SingleTop"
                NameOut= "SingleTop"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                
                NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHisto=NormFile.Get("XXX")
                
                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                tDirectory.WriteObject(RebinedHist,NameOut)
                
                ###############  Systematics on Shape and Norm for  High Tau Pt ####
                if  tscale==1 and jscale==1:
                    for systHighpt in range(len(SystematicHighPtTau)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+ charge
                        NameOut= "SingleTop"+str(Signal_Unc_HighPtTau[systHighpt])
                        
                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                        
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)
                ################################################
                #  Filling VV
                ################################################
                print "--------------------------------------------------->     Processing VV"
                tDirectory.cd()
            
                Name= "VV"
                NameOut= "VV"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                
                NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHisto=NormFile.Get("XXX")
                
                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                tDirectory.WriteObject(RebinedHist,NameOut)
                
                ###############  Systematics on Shape and Norm for  High Tau Pt ####
                if  tscale==1 and jscale==1:
                    for systHighpt in range(len(SystematicHighPtTau)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+ charge
                        NameOut= "VV"+str(Signal_Unc_HighPtTau[systHighpt])
                        
                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                        
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)


                ################################################
                #  Filling TOP
                ################################################
                print "--------------------------------------------------->     Processing TOP"
                tDirectory.cd()

                Name= "TTJets"
                NameOut= "TT"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])

                NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHisto=NormFile.Get("XXX")
            
                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                tDirectory.WriteObject(RebinedHist,NameOut)
                ###############  Systematics on Shape and Norm for  High Tau Pt ####
                if  tscale==1 and jscale==1:
                    for systHighpt in range(len(SystematicHighPtTau)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+ charge
                        NameOut= "TT"+str(Signal_Unc_HighPtTau[systHighpt])
                        
                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                        
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)
                    
                    for systTopRW in range(len(SystematicTopPtReWeight)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicTopPtReWeight[systTopRW]+ charge
                        NameOut= "TT"+str(Signal_Unc_TopPTRW[systTopRW])

                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")

                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)
                            
    
                ################################################
                #  Filling ZTT
                ################################################
                print "--------------------------------------------------->     Processing ZTT"
                tDirectory.cd()

                Name= "DYJetsToLL"
                NameOut= "ZTT"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                
                NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHisto=NormFile.Get("XXX")
                
                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                tDirectory.WriteObject(RebinedHist,NameOut)
                ###############  Systematics on Shape and Norm for  High Tau Pt ####
                if  tscale==1 and jscale==1:
                    for systHighpt in range(len(SystematicHighPtTau)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+ charge
                        NameOut= "ZTT"+str(Signal_Unc_HighPtTau[systHighpt])
                        
                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                        
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)


                ################################################
                #  Filling W
                ################################################
                print "--------------------------------------------------->     Processing W"
                tDirectory.cd()

                Name="WJetsToLNu"
                NameOut= "W"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])

                NormFileWNoCor= _FileReturn(Name, channel,NameCat, NormMC.replace("_OS","") +"_OS", TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHistoWNoCor=NormFileWNoCor.Get("XXX")
                WNoCorNormaliztaion=NormHistoWNoCor.Integral()
                
            
                NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                NormHisto=NormFile.Get("XXX")
                
                NormHisto.Scale(WNoCorNormaliztaion/NormHisto.Integral())
                RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                tDirectory.WriteObject(RebinedHist,NameOut)

                ###############  Systematics on Shape and Norm for  High Tau Pt ####
                if  tscale==1 and jscale==1:
                    for systHighpt in range(len(SystematicHighPtTau)):
                        tDirectory.cd()
                        Histogram = NormMC.replace("_OS","")+SystematicHighPtTau[systHighpt]+ charge
                        NameOut= "W"+str(Signal_Unc_HighPtTau[systHighpt])
                            
                        NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
                        NormHisto=NormFile.Get("XXX")
                        
                        RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                        tDirectory.WriteObject(RebinedHist,NameOut)
            
            
    #                for systW in range(len(SystematicWShape)):
    #                    tDirectory.cd()
    #                    Histogram = NormMC.replace("_OS","")+SystematicWShape[systW]+ charge
    #                    NameOut= "W"+str(Signal_Unc_WShape[systW])
    #                    
    #                    NormFile= _FileReturn(Name, channel,NameCat, Histogram, TauScale[tscale],JetScale[jscale],CoMEnergy)
    #                    NormHisto=NormFile.Get("XXX")
    #                    
    #                    NormHisto.Scale(WNoCorNormaliztaion/NormHisto.Integral())
    #                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
    #                    tDirectory.WriteObject(RebinedHist,NameOut)

            

                ################################################
                #  Filling QCD
                ################################################
                if tscale ==1 and jscale==1:
                    print "--------------------------------------------------->     Processing QCD"
                    tDirectory.cd()
                    
                    Name= "SingleTop"
                    SingleTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    SingleTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    
                    Name= "VV"
                    VVSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    VVSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)

                    Name= "TTJets"
                    TTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    TTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)

                    Name= "DYJetsToLL"
                    ZTTSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    ZTTSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)

                    Name= "WJetsToLNu"
                    WSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    WSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                                
                    Name="Data"
                    DataSampleQCDNorm= _FileReturn(Name, channel,NameCat, NormQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    DataSampleQCDShape= _FileReturn(Name, channel,NameCat, ShapeQCD, TauScale[tscale],JetScale[jscale],CoMEnergy)



                    SingleTSampleQCDShapeHist=SingleTSampleQCDShape.Get("XXX")
                    VVSampleQCDShapeHist=VVSampleQCDShape.Get("XXX")
                    TTSampleQCDShapeHist=TTSampleQCDShape.Get("XXX")
                    ZTTSampleQCDShapeHist=ZTTSampleQCDShape.Get("XXX")
                    WSampleQCDShapeHist=WSampleQCDShape.Get("XXX")
                    DataSampleQCDShapeHist=DataSampleQCDShape.Get("XXX")

                    print "\n---->   ##########\nlooseQCDShape before=",    DataSampleQCDShapeHist.Integral()
                    
#                    if (SingleTSampleQCDShapeHist) : DataSampleQCDShapeHist.Add(SingleTSampleQCDShapeHist, -1)
#                    if (VVSampleQCDShapeHist): DataSampleQCDShapeHist.Add(VVSampleQCDShapeHist, -1)
#                    DataSampleQCDShapeHist.Add(TTSampleQCDShapeHist, -1)
#                    DataSampleQCDShapeHist.Add(ZTTSampleQCDShapeHist, -1)
#                    DataSampleQCDShapeHist.Add(WSampleQCDShapeHist, -1)
                    print "\n---->   ##########\nlooseQCDShaoe after=",    DataSampleQCDShapeHist.Integral()


                    SingleTSampleQCDNormHist=SingleTSampleQCDNorm.Get("XXX")
                    VVSampleQCDNormHist=VVSampleQCDNorm.Get("XXX")
                    TTSampleQCDNormHist=TTSampleQCDNorm.Get("XXX")
                    ZTTSampleQCDNormHist=ZTTSampleQCDNorm.Get("XXX")
                    WSampleQCDNormHist=WSampleQCDNorm.Get("XXX")
                    DataSampleQCDNormHist=DataSampleQCDNorm.Get("XXX")
                    

                    if (SingleTSampleQCDNormHist) : DataSampleQCDNormHist.Add(SingleTSampleQCDNormHist, -1)
                    if (VVSampleQCDNormHist): DataSampleQCDNormHist.Add(VVSampleQCDNormHist, -1)
                    DataSampleQCDNormHist.Add(TTSampleQCDNormHist, -1)
                    DataSampleQCDNormHist.Add(ZTTSampleQCDNormHist, -1)
                    DataSampleQCDNormHist.Add(WSampleQCDNormHist, -1)
                    
                    print "\n##########\nlooseQCDNORM after=",    DataSampleQCDNormHist.Integral()
                    FR_FitMaram=Make_Tau_FakeRate(channel)
                    QCDEstimation=0
                    for bin in xrange(50,500):
                        value=DataSampleQCDNormHist.GetBinContent(bin)
                        if value < 0 : value=0
                        FR= _FIT_Jet_Function(bin+1.5,FR_FitMaram)
                        QCDEstimation += value * FR/(1-FR)
                    QCDEstimation    *= OS_SS_Ratio
                    print "\n##########\n QCDEstimation",    QCDEstimation

        #            QCDEstimation= (DataSampleQCDNormHist.Integral()- (TT_qcd+ZTT_qcd+W_qcd+SingleT_qcd+VV_qcd)) * OS_SS_Ratio

                    NameOut= "QCD"+str(TauScaleOut[tscale])+str(JetScaleOut[jscale])
                    DataSampleQCDShapeHist.Scale(QCDEstimation/DataSampleQCDShapeHist.Integral())  # The shape is from btag-Loose Need get back norm
                    RebinedHist= DataSampleQCDShapeHist.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)

                ################################################
                #  Filling Data
                ################################################
                if tscale ==1 and jscale==1:
                    print "--------------------------------------------------->     Processing Data"
                    tDirectory.cd()

                    Name='Data'
                    NameOut='data_obs'

                    NormFile= _FileReturn(Name, channel,NameCat, NormMC, TauScale[tscale],JetScale[jscale],CoMEnergy)
                    NormHisto=NormFile.Get("XXX")
                
                    RebinedHist= NormHisto.Rebin(len(Binning)-1,"",Binning)
                    tDirectory.WriteObject(RebinedHist,NameOut)




    myOut.Close()

if __name__ == "__main__":

    Binning = array.array("d",[0,100,200,300,400,500,600,700,800,900,1000,1150,1300,1450,1600,1800,2000,5000])

    NormMC="_RW_ST_MET"
    MakeTheHistogram("MuTau",NormMC,"_RW_CloseJetTauPt_TauAntiIsoLepIso",NormMC+"_LepAntiIso","",0,Binning,"RHW")
    MakeTheHistogram("EleTau",NormMC,"_RW_CloseJetTauPt_TauAntiIsoLepIso",NormMC+"_LepAntiIso","",1,Binning,"RHW")
