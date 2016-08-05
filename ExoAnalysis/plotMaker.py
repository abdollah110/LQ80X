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
from ROOT import Double
from ROOT import TAxis
from ROOT import TCanvas
from ROOT import TFile
from ROOT import TH1F
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

def _PlotMaker(file1,file2,file3, histo1, pave, title, reB,col,XMax):

    canvas = TCanvas("canvas", "", 600, 600)
    gStyle.SetOptStat("");
#    gStyle.SetStatistics(0);
    canvas.SetFillColor(0)
    canvas.SetTitle("")
    canvas.SetName("")
    canvas.SetBorderMode(0)
    canvas.SetBorderSize(2)
    canvas.SetFrameBorderMode(0)
    canvas.SetFrameLineWidth(2)
    canvas.SetFrameBorderMode(0)
#    canvas.SetLogy();



    File_1 = TFile(file1, "OPEN")
    Histo_1 = File_1.Get(histo1)
    
    File_2 = TFile(file2, "OPEN")
    Histo_2 = File_2.Get(histo1)

    File_3 = TFile(file3, "OPEN")
    Histo_3 = File_3.Get(histo1)
    
    reB=10
    Histo_1.SetTitle("")
    Histo_1.Rebin(reB)
#    Histo_1.SetFillColor(col)
#    Histo_1.SetLineWidth(3)
    Histo_1.GetXaxis().SetRangeUser(0, XMax)
#    Histo_1.GetXaxis().SetOptStat(0)
    Histo_1.GetXaxis().SetTitle(title)
    Histo_1.GetYaxis().SetTitle("# of events")
    Histo_1.GetYaxis().SetTitleOffset(1.3)
    Histo_1.GetYaxis().SetRangeUser(0, 2* Histo_1.GetMaximum())
    Histo_1.GetYaxis().SetLabelSize(0.02)
    Histo_1.GetYaxis().SetTitleOffset(1.4)
#    Histo_1.GetYaxis().SetRangeUser(0,2*Histo_1.GetMaximum() );


    Histo_1.SetMarkerSize(1.2)
    Histo_1.SetMarkerStyle(24)
    Histo_1.SetLineColor(4)
    Histo_1.SetMarkerColor(4)
    Histo_1.Draw("hist")
    

    Histo_2.SetMarkerSize(1.2)
    Histo_2.SetMarkerStyle(21)
    Histo_2.SetLineColor(2)
    Histo_2.SetMarkerColor(2)
    Histo_2.Rebin(reB)
    Histo_2.Draw("histsame")


    Histo_3.SetMarkerSize(1.2)
    Histo_3.SetMarkerStyle(23)
    Histo_3.SetLineColor(3)
    Histo_3.SetMarkerColor(3)
    Histo_3.Rebin(reB)
    Histo_3.Draw("histsame")



    fitInfo  =TPaveText(.10,0.6,.60,0.7, "NDC");
    fitInfo.SetBorderSize(   0 );
    fitInfo.SetFillStyle(    0 );
    fitInfo.SetTextAlign(   12 );
    fitInfo.SetTextSize ( 0.03 );
    fitInfo.SetTextColor(    1 );
    fitInfo.SetTextFont (   62 );
    fitInfo.AddText(pave)
    fitInfo.Draw()


    legend_ = TLegend(0.5, 0.75, 0.8, 0.87)
    legend_.SetFillColor(0)
    legend_.SetBorderSize(0)
    legend_.SetTextSize(.03)
    legend_.AddEntry(Histo_1,  "UnclusteredEn Up", "l")
    legend_.AddEntry(Histo_2,  "Nominal ", "l")
    legend_.AddEntry(Histo_3,  "UnclusteredEn Down", "l")
#    legend_.AddEntry(Histo_1,  "UnclusteredEn Up ("+str(Histo_1.Integral())+")", "l")
#    legend_.AddEntry(Histo_2,  "Nominal ("+str(Histo_2.Integral())+")", "l")
#    legend_.AddEntry(Histo_3,  "UnclusteredEn Down ("+str(Histo_3.Integral())+")", "l")

    legend_.Draw()


    ChannelName = "_plots_METUnc_"+histo1 + ".pdf"
    canvas.SaveAs(ChannelName)


if __name__ == "__main__":
    OutFile1="RHW_3000_MET_Up.root"
    OutFile2="RHW_3000_MET_nominal.root"
    OutFile3="RHW_3000_MET_Down.root"
    _PlotMaker(OutFile1,OutFile2,OutFile3, "MuTau_RW_ST_MET_DiJet", "MuTau RHW_3000_Nu_1500","ST_{#mu#taujjMET} ( GeV)",1,5,4000)
    _PlotMaker(OutFile1,OutFile2,OutFile3, "EleTau_RW_ST_MET_DiJet", "EleTau RHW_3000_Nu_1500","ST_{#mu#taujjMET} ( GeV)",1,5,4000)
    _PlotMaker(OutFile1,OutFile2,OutFile3, "MuTau_RW_XXX_MET_DiJet", "MuTau RHW_3000_Nu_1500","E_{T}^{miss} ( GeV)",1,5,1000)
#    _PlotMaker(OutFile1,OutFile2,OutFile3, "EleTau_RW_XXX_MET_DiJet", "EleTau RHW_3000_Nu_1500","E_{T}^{miss} ( GeV)",1,5)

#    _PlotMaker(OutFile,OutFile2, "Tau_W_pt", "p_T of Tau from RH W boson","p_{T} ( GeV)",1,5)
#    _PlotMaker(OutFile,OutFile2, "Tau_Nu_pt", "p_T of Tau from RH Nu","p_{T} ( GeV)",1,5)
#    _PlotMaker(OutFile,OutFile2, "jet_plus_pt", "p_T of Jet1 from RH Nu","p_{T} ( GeV)",1,5)


