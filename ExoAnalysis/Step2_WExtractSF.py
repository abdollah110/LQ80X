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
#from Step7_TauFakeRate import Make_Tau_FakeRate
#from Step7_TauFakeRate import _FIT_Jet_Function
##### Get Jet to Tau FR

gROOT.Reset()
import os




ROOT.gROOT.SetBatch(True)
SubRootDir = 'OutFiles_WEstim/'
#SubRootDir = 'OutFiles_WEstimLooseIsoMu/'
#SubRootDir = 'OutFiles_WEstim-NoMETCut/'
#SubRootDir = 'OutFiles_WEstim-50GeVMET/'


verbos_ = False
OS_SS_Ratio=1.00
RB_=1

TauScale = [ ""]
#POSTFIX=["","Up","Down"]

signal = ['RHNu_']
signalName = ['RHW_']
mass = ['1000-500','1500-750','2000-1000','2500-1250','3000-1500']
Wmass = ['1000','1500','2000','2500','3000']

lenghtSig = len(signal) * len(mass) +1

#category = ["_inclusive"]
#category = ["_DiJet","_JetBJet"]
category = ["_DiNonBJet"]
#category = ["_inclNoBjet"]

#channelDirectory = [ "MuTau"]
#channelDirectory = ["MuTau", "EleTau"]



############################################################################################################
def _FileReturn(Name, channel,cat,HistoName):

    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name + '.root')
    print "##### --->>>>>>> File name is ", SubRootDir + Name + '.root'  "   and histo is -->  ", channel+HistoName + cat
    Histo =  myfile.Get(channel+HistoName + cat)
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    return NewFile


####################################################
##   Start Making the Datacard Histograms
####################################################
def MakeTheHistogram(channel,NormMC,NormQCD,ShapeQCD,chl,Binning):
    print "\n\n\n\n\n\n ****** ------------------------------>     Starting for ",NormMC, "in Channel= ",channel

    TauScaleOut = [ ""]






    for NameCat in category:
        myOut = TFile("TotalRootForLimit_"+channel + NormMC+NameCat+".root" , 'RECREATE') # Name Of the output file
        print "starting NameCat and channel and HistoName ", NameCat, channel, NormMC

        tDirectory= myOut.mkdir("beforeScale")
        tDirectory.cd()
        for tscale in range(len(TauScale)):



            ################################################
            #  Filling SingleTop
            ################################################
            print "--------------------------------------------------->     Processing SingleTop"
            tDirectory.cd()
        
            Name= "SingleTop"
            NameOut= "SingleTop"+str(TauScaleOut[tscale])
            
            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC)
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)
            ################################################
            #  Filling VV
            ################################################
            print "--------------------------------------------------->     Processing VV"
            tDirectory.cd()
        
            Name= "VV"
            NameOut= "VV"+str(TauScaleOut[tscale])
            
            
            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC)
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)


            ################################################
            #  Filling TOP
            ################################################
            print "--------------------------------------------------->     Processing TOP"
            tDirectory.cd()

            Name= "TTJets"
            NameOut= "TT"+str(TauScaleOut[tscale])

            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC)
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)
            
            ################################################
            #  Filling ZTT
            ################################################
            print "--------------------------------------------------->     Processing ZTT"
            tDirectory.cd()

            Name= "DYJetsToLL"
            NameOut= "ZTT"+str(TauScaleOut[tscale])
            
            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC)
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)


            ################################################
            #  Filling W
            ################################################
            print "--------------------------------------------------->     Processing W"
            tDirectory.cd()

            Name="WJetsToLNu"
            NameOut= "W"+str(TauScaleOut[tscale])
            
            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC)
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)
            tDirectory.WriteObject(RebinedHist,"W120"+str(TauScaleOut[tscale]))
            tDirectory.WriteObject(RebinedHist,"W125"+str(TauScaleOut[tscale]))

            ################################################
            #  Filling QCD
            ################################################
            if channel == "MuTau":
                print "--------------------------------------------------->     Processing QCD"
                tDirectory.cd()
                
    #            Name="QCD"
                Name="QCD"
                NameOut= "QCD"+str(TauScaleOut[tscale])
                
    #            NormFile= _FileReturn(Name, channel,NameCat, NormQCD)
    #            NormHisto=NormFile.Get("XXX")
    #            
    #            ShapeFile= _FileReturn(Name, channel,NameCat, ShapeQCD)
    #            ShapeHisto=ShapeFile.Get("XXX")

    #            ShapeHisto.Scale(NormHisto.Integral()/ShapeHisto.Integral())
    #            RebinedHist= ShapeHisto.Rebin(RB_)
    #            tDirectory.WriteObject(RebinedHist,NameOut)

                tauFRNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_HighMT_OS","_SS")+"_TauIso")
                tauFRNumHist=tauFRNum.Get("XXX")
                print tauFRNumHist.Integral()
                
                lepFRNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_HighMT_OS","_SS")+"_LepIso")
                lepFRNumHist=lepFRNum.Get("XXX")
                print lepFRNumHist.Integral()

                lepFRDeNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_HighMT_OS","_SS")+"_Total")
                lepFRDeNumHist=lepFRDeNum.Get("XXX")
                print lepFRDeNumHist.Integral()
        
                jetFRNum=_FileReturn(Name, channel,NameCat, NormMC.replace("_HighMT_OS","_SS")+"_Total")
                jetFRNumHist=jetFRNum.Get("XXX")
                print jetFRNumHist.Integral()
                
                jetFRDeNum=_FileReturn(Name, channel,"_inclNoBjet", NormMC.replace("_HighMT_OS","_SS")+"_Total")
                jetFRDeNumHist=jetFRDeNum.Get("XXX")
                print jetFRDeNumHist.Integral()

                XValu=_FileReturn(Name, channel,"_inclNoBjet", NormMC+"_Total")  #definedabove

                XValuHist=XValu.Get("XXX")
                print XValuHist.Integral()
                
                
                QCDEstim=  XValuHist.Integral() * (tauFRNumHist.Integral() / lepFRDeNumHist.Integral() ) * ( lepFRNumHist.Integral()/lepFRDeNumHist.Integral()) * (jetFRNumHist.Integral()/jetFRDeNumHist.Integral())

                print "QCDEstim --->  ", QCDEstim
                
                
                ShapeFile= _FileReturn(Name, channel,NameCat, ShapeQCD)
                ShapeHisto=ShapeFile.Get("XXX")

                ShapeHisto.Scale(QCDEstim/ShapeHisto.Integral())
                RebinedHist= ShapeHisto.Rebin(RB_)
                tDirectory.WriteObject(RebinedHist,NameOut)
            
            
            
            
            if channel == "EleTau":
                print "--------------------------------------------------->     Processing QCD"
                tDirectory.cd()
                
                #            Name="QCD"
                Name="Data"
                NameOut= "QCD"+str(TauScaleOut[tscale])
            
#                ShapeFile= _FileReturn(Name, channel,NameCat, NormMC.replace("_HighMT_OS","_LowMT")+"_AntiIso") #for data Shape and Norm should be the same
                ShapeFile= _FileReturn(Name, channel,NameCat, NormMC.replace("_HighMT","_LowMT")+"_AntiIso") #for data Shape and Norm should be the same
                ShapeHisto=ShapeFile.Get("XXX")
                
                RebinedHist= ShapeHisto.Rebin(RB_)
                RebinedHist.Scale(1/RebinedHist.Integral())
                tDirectory.WriteObject(RebinedHist,NameOut)
            
            ################################################
            #  Filling Data
            ################################################
            print "--------------------------------------------------->     Processing Data"
            tDirectory.cd()

            Name='Data'
            NameOut='data_obs'
            
            ShapeFile= _FileReturn(Name, channel,NameCat, NormMC) #for data Shape and Norm should be the same
            ShapeHisto=ShapeFile.Get("XXX")
            
            RebinedHist= ShapeHisto.Rebin(RB_)
            tDirectory.WriteObject(RebinedHist,NameOut)

    myOut.Close()





if __name__ == "__main__":
    Binning = array.array("d",[0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,160,180,200,250,300,400,500])
    
#    NormMC="_ST_MET_HighMT"
#    MakeTheHistogram("MuTau",NormMC+"_SS",NormMC+"_SS",NormMC+"_Total","",0,Binning)
#    MakeTheHistogram("EleTau",NormMC+"_SS",NormMC+"_SS",NormMC+"_Total","",1,Binning)
    PlotName= ["_LepPt_HighMT","_LepEta_HighMT","_TauPt_HighMT","_TauEta_HighMT","_NumJet_HighMT","_NumBJet_HighMT","_MET_HighMT","_ST_MET_HighMT"]
    
    
    for NormMC in PlotName:
    
        MakeTheHistogram("MuTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total",0,Binning)
        MakeTheHistogram("EleTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total",1,Binning)
    #    NormMC="_NumJet"
    #    MakeTheHistogram("MuTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total","",0,Binning)
