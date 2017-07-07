import ROOT
from ROOT import *

can=TCanvas("can")
F1=TFile("datatestOldLQroot.root")
H1=F1.Get("MuEle_EleEta_DiJet")
H2=F1.Get("MuEle_EleEta_DiJetExtra")
H1.Draw()
H2.Draw("same")
can.SaveAs("a.pdf")