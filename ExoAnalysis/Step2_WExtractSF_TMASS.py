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
#SubRootDir = 'OutFiles_WEstim-NoFilter/'
#SubRootDir = 'OutFiles_WEstim-NoMETCut/'
#SubRootDir = 'OutFiles_WEstim-50GeVMET/'


verbos_ = False
OS_SS_Ratio=1.00
RB_=10

TauScale = [ ""]
#POSTFIX=["","Up","Down"]

signal = ['RHNu_']
signalName = ['RHW_']
mass = ['1000-500','1500-750','2000-1000','2500-1250','3000-1500']
Wmass = ['1000','1500','2000','2500','3000']

lenghtSig = len(signal) * len(mass) +1

#category = ["_inclusive"]
#category = ["_DiJet"]
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

                tauFRNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_OS","_SS")+"_TauIso")
                tauFRNumHist=tauFRNum.Get("XXX")
                print tauFRNumHist.Integral()
                
                lepFRNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_OS","_SS")+"_LepIso")
                lepFRNumHist=lepFRNum.Get("XXX")
                print lepFRNumHist.Integral()

                lepFRDeNum=_FileReturn(Name, channel,"_inclusive", NormMC.replace("_OS","_SS")+"_Total")
                lepFRDeNumHist=lepFRDeNum.Get("XXX")
                print lepFRDeNumHist.Integral()
        
                jetFRNum=_FileReturn(Name, channel,NameCat, NormMC.replace("_OS","_SS")+"_Total")
                jetFRNumHist=jetFRNum.Get("XXX")
                print jetFRNumHist.Integral()
                
                jetFRDeNum=_FileReturn(Name, channel,"_inclNoBjet", NormMC.replace("_OS","_SS")+"_Total")
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
            
#                ShapeFile= _FileReturn(Name, channel,NameCat, NormMC.replace("_OS","")+"_AntiIso") #for data Shape and Norm should be the same
                ShapeFileData= _FileReturn(Name, channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoData=ShapeFileData.Get("XXX")
                
                ShapeFileDY= _FileReturn("DYJetsToLL", channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoDY=ShapeFileDY.Get("XXX")
                
                ShapeFileW= _FileReturn("WJetsToLNu", channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoW=ShapeFileW.Get("XXX")
                
                ShapeFileTT= _FileReturn("TTJets", channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoTT=ShapeFileTT.Get("XXX")
                
                ShapeFileSTop= _FileReturn("SingleTop", channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoSTop=ShapeFileSTop.Get("XXX")
                
                ShapeFileVV= _FileReturn("VV", channel,NameCat, NormMC.replace("_OS","_SS")+"_LepAntiIso") #for data Shape and Norm should be the same
                ShapeHistoVV=ShapeFileVV.Get("XXX")
                
                print "--> Before subtracting other BG contamination QCD norm is =", ShapeHistoData.Integral()
                ShapeHistoData.Add(ShapeHistoDY,-1)
                ShapeHistoData.Add(ShapeHistoW,-1)
                ShapeHistoData.Add(ShapeHistoTT,-1)
                ShapeHistoData.Add(ShapeHistoSTop,-1)
                ShapeHistoData.Add(ShapeHistoVV,-1)
                print "--> After subtracting other BG contamination QCD norm is =", ShapeHistoData.Integral()
                
                
                RebinedHist= ShapeHistoData.Rebin(RB_)
                RebinedHist.Scale(107/RebinedHist.Integral())
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
    
#    NormMC="_ST_MET"
#    MakeTheHistogram("MuTau",NormMC+"_SS",NormMC+"_SS",NormMC+"_Total","",0,Binning)
#    MakeTheHistogram("EleTau",NormMC+"_SS",NormMC+"_SS",NormMC+"_Total","",1,Binning)
    PlotName= ["_tmass"]
#    PlotName= ["_tmass","_LepPt","_LepEta","_TauPt","_TauEta","_NumJet","_NumBJet","_MET","_ST_MET"]

    
    for NormMC in PlotName:
    
        MakeTheHistogram("MuTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total",0,Binning)
        MakeTheHistogram("EleTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total",1,Binning)
    #    NormMC="_NumJet"
    #    MakeTheHistogram("MuTau",NormMC+"_OS",NormMC+"_OS",NormMC+"_Total","",0,Binning)
