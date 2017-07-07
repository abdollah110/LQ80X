import os
import ROOT
from ROOT import *



def make_legend():
    output = ROOT.TLegend(0.65, 0.4, 0.92, 0.82, "", "brNDC")
    output.SetLineWidth(0)
    output.SetLineStyle(0)
    output.SetFillStyle(0)
    output.SetBorderSize(0)
    output.SetTextFont(62)
    return output



def getFileName(MainFile,file,histo):
    F=TFile(file)
    H=F.Get(histo)
    MainF=TFile(MainFile)
    MainH=MainF.Get("hcount")
    TotNum=MainH.GetBinContent(2)
    print " histo=",histo, " TotalNumEvent=" , TotNum, " numEntryAfterSelection=", H.GetEntries(),  " integral=", H.Integral()




getFileName("../ROOT80X/rootSkim/LQToBTau_M-200.root", "lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet/LQ_200")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-250.root", "lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet/LQ_250")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-300.root", "lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet/LQ_300")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-350.root", "lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet/LQ_350")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-400.root", "lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet/LQ_400")
print "\n"
getFileName("../ROOT80X/rootSkim/LQToBTau_M-200.root", "lq_et.inputs-sm-13TeV.root","EleTau_JetBJet/LQ_200")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-250.root", "lq_et.inputs-sm-13TeV.root","EleTau_JetBJet/LQ_250")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-300.root", "lq_et.inputs-sm-13TeV.root","EleTau_JetBJet/LQ_300")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-350.root", "lq_et.inputs-sm-13TeV.root","EleTau_JetBJet/LQ_350")
getFileName("../ROOT80X/rootSkim/LQToBTau_M-400.root", "lq_et.inputs-sm-13TeV.root","EleTau_JetBJet/LQ_400")



def CompareShape(file,Dir):

    F=TFile(file)
    H200=F.Get(Dir+"/LQ_200")
    H250=F.Get(Dir+"/LQ_250")
    H300=F.Get(Dir+"/LQ_300")
    H350=F.Get(Dir+"/LQ_350")
#    H400=F.Get(Dir+"/LQ_400")

    Can=TCanvas("can")
    H200.SetLineColor(1)
    H200.DrawNormalized()
    
    H250.SetLineColor(2)
    H250.DrawNormalized("same")
    
    H300.SetLineColor(3)
    H300.DrawNormalized("same")
    
    H350.SetLineColor(4)
    H350.DrawNormalized("same")
    
#    H400.DrawNormalized("same")


    legende=make_legend()
    legende.AddEntry(H200,"H200","elp")
    legende.AddEntry(H250,"H250","elp")
    legende.AddEntry(H300,"H300","elp")
    legende.AddEntry(H350,"H350","elp")
    legende.Draw()
    
    Can.SaveAs("compareShape_LQ"+Dir+".pdf")


CompareShape("lq_mt.inputs-sm-13TeV.root","MuTau_JetBJet")
CompareShape("lq_et.inputs-sm-13TeV.root","EleTau_JetBJet")



