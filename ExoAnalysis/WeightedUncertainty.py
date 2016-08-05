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
import array

def _PlotMaker(file1, histo1, pave, title, reB,col,XMax,Anal):

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
    canvas.SetLogx()
    






    File_1 = TFile(file1, "OPEN")
    Histo_1 = File_1.Get(histo1)
    
    
    SFFile=TFile("../interface/pileup-hists/SingleMuonTrigger_Z_RunBCD_prompt80X_7p65.root","OPEN")
    SFHisto=SFFile.Get("Mu45_eta2p1_PtEtaBins_Run274094_to_276097/efficienciesDATA/pt_abseta_DATA")
    
    





#    MyOut=TFile("out.root","recreate")

##    reB=10
#    xbins=array.array("d",[0,500,1000])
#    ybins=array.array("d",[-2.5,0,2.5])
#    NewT2 =TH2F("oldrebin",Histo_1.GetTitle(),len(xbins)-1,xbins,len(ybins)-1,ybins)

    OverallTrgEff=0
    OverallTrgUnc=0
    xaxis=Histo_1.GetXaxis()
    yaxis=Histo_1.GetYaxis()
    for i in range(xaxis.GetNbins()):
        for j in range(yaxis.GetNbins()):
            print i , i, xaxis.GetBinCenter(i+1),yaxis.GetBinCenter(j+1), Histo_1.GetBinContent(i+1,j+1), SFHisto.GetBinContent(i+1,j+1), SFHisto.GetBinError(i+1,j+1)
            
            trgEff=SFHisto.GetBinContent(i+1,j+1)
            trgUnc=SFHisto.GetBinError(i+1,j+1)


            if i==4:
                trgEff=SFHisto.GetBinContent(5,j+1) ; print "-->", SFHisto.GetBinContent(5,j+1)
                trgUnc= SFHisto.GetBinError(5,j+1) * 2
            
            if i==5:
                trgEff=SFHisto.GetBinContent(5,j+1) ; print "-->", SFHisto.GetBinContent(5,j+1)
                trgUnc= SFHisto.GetBinError(5,j+1) * 5

            OverallTrgEff += (Histo_1.GetBinContent(i+1,j+1)*trgEff)
            OverallTrgUnc += (Histo_1.GetBinContent(i+1,j+1)* trgUnc/trgEff)
#            OverallTrgEff += (Histo_1.GetBinContent(i+1,j+1)*1)
#            OverallTrgUnc += (Histo_1.GetBinContent(i+1,j+1)* .1)

    print "\n\nOverallTrgEff = ", OverallTrgEff/Histo_1.Integral()
    print "OverallTrgUnc = ", OverallTrgUnc/Histo_1.Integral()

#            NewT2.Fill(xaxis.GetBinCenter(i),yaxis.GetBinCenter(j),Histo_1.GetBinContent(i,j))
#
#
#    NewT2.Draw("text")
#    NewT2.Write()
#    MyOut.Close()

    

#    Binning = array.array("d",[0,100,200,300,400,500,600,700,800,900,1000,1150,1300,1450,1600,1800,2000,5000])

    Histo_1.Rebin(reB)
#    Histo_1.SetFillColor(col)
#    Histo_1.SetLineWidth(3)
#    Histo_1.GetXaxis().SetRangeUser(0, XMax)
#    Histo_1.GetXaxis().SetOptStat(0)
    Histo_1.SetTitle(title)
    Histo_1.GetYaxis().SetTitle("muon #eta")
    Histo_1.GetXaxis().SetTitle("muon p_{T}")
    Histo_1.GetYaxis().SetTitleOffset(1.3)
#    Histo_1.GetYaxis().SetRangeUser(0, 2* Histo_1.GetMaximum())
    Histo_1.GetYaxis().SetLabelSize(0.02)
    Histo_1.GetYaxis().SetTitleOffset(1.4)
#    Histo_1.GetYaxis().SetRangeUser(0,2*Histo_1.GetMaximum() );
#
#
#    Histo_1.SetMarkerSize(1.2)
#    Histo_1.SetMarkerStyle(24)
#    Histo_1.SetLineColor(4)
#    Histo_1.SetMarkerColor(4)
#    cout.precision(2)
    Histo_1.Scale(1/Histo_1.Integral())
    Histo_1.Draw("text")



#    fitInfo  =TPaveText(.10,0.6,.60,0.7, "NDC");
#    fitInfo.SetBorderSize(   0 );
#    fitInfo.SetFillStyle(    0 );
#    fitInfo.SetTextAlign(   12 );
#    fitInfo.SetTextSize ( 0.03 );
#    fitInfo.SetTextColor(    1 );
#    fitInfo.SetTextFont (   62 );
#    fitInfo.AddText(pave)
#    fitInfo.Draw()




    ChannelName = "_plots_MuonUncTest_2D_"+histo1 +"_" +Anal+".pdf"
    canvas.SaveAs(ChannelName)


def _PlotMakerPt(file1, histo1, pave, title, reB,col,XMax,Anal):
    
    canvas = TCanvas("canvas", "", 600, 600)
    gStyle.SetOptStat(1111111)
#    gStyle.SetStatStatistics(0);
    canvas.SetFillColor(0)
    canvas.SetTitle("")
    canvas.SetName("")
    canvas.SetBorderMode(0)
    canvas.SetBorderSize(2)
    canvas.SetFrameBorderMode(0)
    canvas.SetFrameLineWidth(2)
    canvas.SetFrameBorderMode(0)
#    canvas.SetLogx()

    
    
    
    
    
    
    File_1 = TFile(file1, "OPEN")
    Histo_1 = File_1.Get(histo1)

    Histo_1.Rebin(20)
    Histo_1.SetTitle(title)
    Histo_1.GetYaxis().SetTitle("# of events")
    Histo_1.GetXaxis().SetTitle("muon p_{T}")
    Histo_1.GetYaxis().SetTitleOffset(1.3)
    Histo_1.GetYaxis().SetLabelSize(0.02)
    Histo_1.GetYaxis().SetTitleOffset(1.4)
    Histo_1.Draw()


    ChannelName = "_plots_MuonUncTest_1D_"+histo1 +"_" +Anal+".pdf"
    canvas.SaveAs(ChannelName)






if __name__ == "__main__":
    
    _PlotMaker("TestMuPt_RHW3000.root", "MuTau_RW_LepPtEta_NoWeight_DiJet", "MuTau RHW_3000_Nu_1500","RH W_3000_Nu1500",1,5,4000,"RHW")
    _PlotMaker("TestMuPt_LQ900.root", "MuTau_RW_LepPtEta_NoWeight_DiJet", "MuTau LQ_900","LQ_900",1,5,4000,"LQ")

    _PlotMakerPt("TestMuPt_RHW3000.root", "MuTau_RW_LepPt_NoWeight_DiJet", "MuTau RHW_3000_Nu_1500","RH W_3000_Nu1500",1,5,4000,"RHW")
    _PlotMakerPt("TestMuPt_LQ900.root", "MuTau_RW_LepPt_NoWeight_DiJet", "MuTau LQ_900","LQ_900",1,5,4000,"LQ")
