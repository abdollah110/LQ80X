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
from ROOT import TF1
from ROOT import TPaveText
from ROOT import TMath
from ctypes import *
import ROOT as r
import array

gROOT.Reset()
import os
dataMCScale=1.0



ROOT.gROOT.SetBatch(True)
SubRootDir = 'OutFiles_WEstim/'

verbos_ = False
TauScale = [ ""]

############################################################################################################
def _FileReturn(Name, channel,cat,HistoName,PostFix,CoMEnergy):
    if not os.path.exists(SubRootDir):
        os.makedirs(SubRootDir)
    myfile = TFile(SubRootDir + Name +CoMEnergy+ '.root')
    print "1 --------->>>>>>  ", SubRootDir + Name +CoMEnergy+ '.root'
    Histo =  myfile.Get(channel+HistoName + cat+ PostFix)
    print "2 --------->>>>>>  ", channel+HistoName + cat+ PostFix
    if not os.path.exists("Extra"):
        os.makedirs("Extra")
    NewFile=TFile("Extra/XXX.root","RECREATE")
    NewFile.WriteObject(Histo,"XXX")
    myfile.Close()
    return NewFile





    ##########################################    ##########################################    ##########################################
    ##########################################    ##########################################    ##########################################
    ##########################################    ##########################################    ##########################################
RB_=1
def Make_W_Control_Plots(NameCat,channel,NormQCD,ShapeQCD):
    
        
    tscale=0
    CoMEnergy=""
            
    SingleTSampleQCDNorm= _FileReturn("SingleTop", channel,Cat, NormQCD, TauScale[tscale],CoMEnergy)
    SingleT=SingleTSampleQCDNorm.Get("XXX")
    SingleT=SingleT.Rebin(RB_)
    
    
    VVSampleQCDNorm= _FileReturn("VV", channel, Cat, NormQCD,TauScale[tscale],CoMEnergy)
    
    VV=VVSampleQCDNorm.Get("XXX")
    VV=VV.Rebin(RB_)

    
    TTSampleQCDNorm= _FileReturn( "TTJets", channel,Cat, NormQCD, TauScale[tscale],CoMEnergy)
    TT=TTSampleQCDNorm.Get("XXX")
    TT=TT.Rebin(RB_)
    
    
    ZTTSampleQCDNorm= _FileReturn("DYJetsToLL", channel,Cat, NormQCD, TauScale[tscale],CoMEnergy)
    ZTT=ZTTSampleQCDNorm.Get("XXX")
    ZTT=ZTT.Rebin(RB_)
    
    
    WSampleQCDNorm= _FileReturn("WJetsToLNu", channel,Cat, NormQCD, TauScale[tscale],CoMEnergy)
    W=WSampleQCDNorm.Get("XXX")
    W=W.Rebin(RB_)
    
    
    QCDSampleQCDNorm= _FileReturn("QCD", channel,NameCat, NormQCD, TauScale[tscale],CoMEnergy)
    QCD=QCDSampleQCDNorm.Get("XXX")
    QCD=QCD.Rebin(RB_)
    

    DataSampleQCDNorm= _FileReturn("Data", channel,Cat, NormQCD, TauScale[tscale],CoMEnergy)
    Data=DataSampleQCDNorm.Get("XXX")
    Data=Data.Rebin(RB_)




    myOut = TFile("WEstimation"+NormQCD+Cat+channel+".root" , 'RECREATE') # Name Of the output file


        
    tDirectory= myOut.mkdir("beforeScale")
    tDirectory.cd()
    tDirectory.WriteObject(VV,"VV")
    tDirectory.WriteObject(W,"W")
    tDirectory.WriteObject(W,"W120")
    tDirectory.WriteObject(W,"W125")
    tDirectory.WriteObject(TT,"TT")
    tDirectory.WriteObject(SingleT,"SingleTop")
    tDirectory.WriteObject(ZTT,"ZTT")
    tDirectory.WriteObject(QCD,"QCD")
    tDirectory.WriteObject(Data,"data_obs")

    tDirectory= myOut.mkdir("afterScale")
    tDirectory.cd()
    tDirectory.WriteObject(VV,"VV")
    W.Scale(  dataMCScale)
    tDirectory.WriteObject(W,"W")
    tDirectory.WriteObject(TT,"TT")
    tDirectory.WriteObject(SingleT,"SingleTop")
    tDirectory.WriteObject(ZTT,"ZTT")
    tDirectory.WriteObject(QCD,"QCD")
    tDirectory.WriteObject(Data,"data_obs")

    myOut.Close()


if __name__ == "__main__":

    category = ["_DiNonBJet"]
#    CHANNE = ["MuTau", "EleTau"]
    CHANNE = ["MuTau"]

    for Cat in category:
        for channel in CHANNE:

            Make_W_Control_Plots(Cat,channel,"_tmass_HighMT_OS","_tmass_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_ST_MET_HighMT_OS","_ST_MET_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_LepPt_HighMT_OS","_LepPt_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_TauPt_HighMT_OS","_TauPt_HighMT_OS_TauIsoLepAntiIso")
#            Make_W_Control_Plots(Cat,channel,"_ST_DiJet_HighMT_OS","_ST_DiJet_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_MET_HighMT_OS","_MET_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_LepEta_HighMT_OS","_LepEta_HighMT_OS_TauIsoLepAntiIso")
            Make_W_Control_Plots(Cat,channel,"_TauEta_HighMT_OS","_TauEta_HighMT_OS_TauIsoLepAntiIso")


