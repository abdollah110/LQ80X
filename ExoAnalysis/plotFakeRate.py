#Test
#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array

RB_=10
def add_lumi():
    lowX=0.69
    lowY=0.835
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.30, lowY+0.16, "NDC")
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.SetTextSize(0.06)
    lumi.SetTextFont (   42 )
    lumi.AddText("6.26 fb^{-1} (13 TeV)")
    return lumi

def add_CMS():
    lowX=0.21
    lowY=0.70
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(61)
    lumi.SetTextSize(0.08)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("CMS")
    return lumi

def add_Preliminary():
    lowX=0.21
    lowY=0.63
    lumi  = ROOT.TPaveText(lowX, lowY+0.06, lowX+0.15, lowY+0.16, "NDC")
    lumi.SetTextFont(52)
    lumi.SetTextSize(0.06)
    lumi.SetBorderSize(   0 )
    lumi.SetFillStyle(    0 )
    lumi.SetTextAlign(   12 )
    lumi.SetTextColor(    1 )
    lumi.AddText("Preliminary")
    return lumi

def make_legend():
    output = ROOT.TLegend(0.35, 0.7, 0.92, 0.92, "", "brNDC")
    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
    output.SetBorderSize(0)
    output.SetTextFont(62)
    return output


OutFile1=TFile("TotalRootForLimit_tauFREtau_MuTau_ST_MET_OS.root")
HistoF1=OutFile1.Get("MuTau_DiJet/QCD")
HistoF1.SetMarkerStyle(20)
HistoF1.SetMarkerSize(1)
HistoF1.SetMarkerColor(3)
HistoF1= HistoF1.Rebin(10)

OutFile2=TFile("TotalRootForLimit_MuTau_ST_MET_OS.root")
HistoF2=OutFile2.Get("MuTau_DiJet/QCD")
HistoF2.SetMarkerStyle(23)
HistoF2.SetMarkerColor(2)
HistoF2.SetMarkerSize(1)

HistoF2= HistoF2.Rebin(10)



HistoF2.GetXaxis().SetTitle("")
#HistoF2.GetXaxis().SetTitleSize(0)
#HistoF2.GetXaxis().SetNdivisions(505)
#HistoF2.GetYaxis().SetLabelFont(42)
#HistoF2.GetYaxis().SetLabelOffset(0.01)
#HistoF2.GetYaxis().SetLabelSize(0.06)
#HistoF2.GetYaxis().SetTitleSize(0.075)
HistoF2.GetYaxis().SetTitleOffset(1.04)
HistoF2.SetTitle("")
HistoF2.GetYaxis().SetTitle("Events")
HistoF2.GetXaxis().SetTitle("ST_{l#taujjMET}  (GeV)")


ROOT.gStyle.SetFrameLineWidth(3)
ROOT.gStyle.SetLineWidth(3)
ROOT.gStyle.SetOptStat(0)
Canv = TCanvas("HistoF1", "histograms", 0, 0, 600, 600)


HistoF1.SetFillColor(0)
#HistoF1.SetStat(0)
HistoF2.GetYaxis().SetRangeUser(0,50)
#HistoF1.SetBorderMode(0)
#HistoF1.SetBorderSize(10)
#HistoF1.SetTickx(1)
#HistoF1.SetTicky(1)
#HistoF1.SetLeftMargin(0.18)
#HistoF1.SetRightMargin(0.05)
#HistoF1.SetTopMargin(0.122)
#HistoF1.SetBottomMargin(0.026)
#HistoF1.SetFrameFillStyle(0)
#HistoF1.SetFrameLineStyle(0)
#HistoF1.SetFrameLineWidth(3)
#HistoF1.SetFrameBorderMode(0)
#HistoF1.SetFrameBorderSize(10)
#HistoF1.Draw()

HistoF2.Draw()
HistoF1.Draw("same")


categ  = ROOT.TPaveText(0.11, 0.5+0.013, 0.23, 0.70+0.155, "NDC")
categ.SetBorderSize(   0 )
categ.SetFillStyle(    0 )
categ.SetTextAlign(   12 )
categ.SetTextSize ( 0.06 )
categ.SetTextColor(    1 )
categ.SetTextFont (   41 )
#       if i==1 or i==3:
categ.AddText("MuTau")
#       else :
#        categ.AddText("SS")
categ.Draw()





legende=make_legend()
legende.AddEntry(HistoF1,"QCD esti. using tau FR in #mu#tau channel","lp")
legende.AddEntry(HistoF2,"QCD esti. using tau FR in e#tau channel","lp")
legende.Draw()

#l1=add_lumi()
#l1.Draw("same")
#l2=add_CMS()
#l2.Draw("same")
#l3=add_Preliminary()
#l3.Draw("same")








Canv.SaveAs("plotcompare.pdf")
