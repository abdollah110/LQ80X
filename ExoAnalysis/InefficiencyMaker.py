#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.

__author__ = "abdollahmohammadi"
__date__ = "$Oct 31, 2013 12:02:55 PM$"

#! /usr/bin/python

# To change this template, choose Tools | Templates
# and open the template in the editor.

__author__ = "abdollahmohammadi"
__date__ = "$Mar 8, 2013 3:00:22 PM$"

import math

import ROOT
#from ROOT import *
from ROOT import Double
from ROOT import TAxis
from ROOT import TCanvas
from ROOT import TFile
from ROOT import TH1F
from ROOT import TF1
from ROOT import TH2F
from ROOT import TLatex
from ROOT import TLegend
from ROOT import TPaveText
from ROOT import TNtuple
from ROOT import TProfile
from ROOT import gBenchmark
from ROOT import gROOT
from ROOT import gRandom
from ROOT import gStyle
from ROOT import gSystem
import array




##############################################################################################################
###   Fit Functions
##############################################################################################################
def _FIT_Lepton( x,  par) :
    return par[0] + par[1] * x[0]
##############################################################################################################
def _PlotMaker():

    SFFile=TFile("../interface/pileup-hists/SingleMuonTrigger_Z_RunBCD_prompt80X_7p65.root","OPEN")
    SFHisto=SFFile.Get("Mu45_eta2p1_PtEtaBins_Run274094_to_276097/efficienciesDATA/pt_abseta_DATA")
    
    Binning = array.array("d",[45,50,60,120,200,250,500])
#    Binning = array.array("d",[45,50,60,120,200,500])

    for j in range(SFHisto.GetNbinsY()):
        canv = TCanvas("canv"+str(j), "histograms", 600, 600)
        MuTrgEff=TFile("muTrg_"+str(j)+".root","RECREATE")
        trgHist=TH1F("muTrg","",len(Binning)-1,Binning)
        for i in range(SFHisto.GetNbinsX()):
            
            
            trgEff=SFHisto.GetBinContent(i+1,j+1)
            trgUnc=SFHisto.GetBinError(i+1,j+1)

            print "trgEff=",trgEff," trgUnc=",trgUnc


            trgHist.SetBinContent(i+1,SFHisto.GetBinContent(i+1,j+1))
            trgHist.SetBinError(i+1,SFHisto.GetBinError(i+1,j+1))
                
            print trgHist.GetBinContent(i+1), "   v.s.   ", SFHisto.GetBinContent(i+1,j+1)

        npar=2
        theFit=TF1("theFit", _FIT_Lepton, 60, 250,npar)
        theFit.SetParameter(0, .2)
        theFit.SetParameter(1, 4)
        trgHist.Fit("theFit", "R0")
        trgHist.GetYaxis().SetRangeUser(0,1)
        trgHist.Draw("E1")
        theFit.Draw("same")
        FitParam=theFit.GetParameters()


        ChannelName1 = "_eff_"+str(j) +"_"+".pdf"
        ChannelName2 = "_eff_"+str(j) +"_"+".root"
        canv.SaveAs(ChannelName1)
        canv.SaveAs(ChannelName2)

        
    

        trgHist.Write()
        MuTrgEff.Close()
##############################################################################################################
if __name__ == "__main__":
    _PlotMaker()
##############################################################################################################


