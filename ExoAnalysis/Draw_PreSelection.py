TTSCALEXXXXXXX=1  #based om the TT from emu channel
#!/usr/bin/env python
import ROOT
import re
from array import array


#
#----------------------------------------------------------
#lq_mt_1_13TeV             LQ_                  0.86708
#lq_mt_1_13TeV             QCD                  0.98690
#lq_mt_1_13TeV             SingleTop            0.88731
#lq_mt_1_13TeV             TT                   0.82758
#lq_mt_1_13TeV             VV                   0.86718
#lq_mt_1_13TeV             W                    0.87289
#lq_mt_1_13TeV             ZTT                  0.88400
#[abdollah@cmslpc39 out]$ PostFitShapes -o final_lq_et_1000.root -m 1000 -f mlfit.root:fit_b --postfit --sampling --print -d ../lq_et_1_13TeV.txt
#Bin                       Total relative bkg uncert. (prefit)
#----------------------------------------------------------
#lq_et_1_13TeV             0.11467
#
#Bin                       Total relative bkg uncert. (postfit)
#----------------------------------------------------------
#lq_et_1_13TeV             0.02897
#
#Bin                       Process              Scale factor
#----------------------------------------------------------
#lq_et_1_13TeV             LQ_                  0.83664
#lq_et_1_13TeV             QCD                  0.98690
#lq_et_1_13TeV             SingleTop            0.85616
#lq_et_1_13TeV             TT                   0.79853
#lq_et_1_13TeV             VV                   0.83674
#lq_et_1_13TeV             W                    0.84225
#lq_et_1_13TeV             ZTT                  0.85297
#
#lq_mt_1_13TeV             QCD
#lq_mt_1_13TeV             SingleTop
#lq_mt_1_13TeV             TT                   0.86226
#lq_mt_1_13TeV             VV                   0.89715
#lq_mt_1_13TeV             W                    0.87024
#lq_mt_1_13TeV             ZTT                  0.90582
#[abdollah@cmslpc39 out]$ PostFitShapes -o final_lq_et_1000.root -m 1000 -f mlfit.root:fit_b --postfit --sampling --print -d ../lq_et_1_13TeV.txt
#Bin                       Total relative bkg uncert. (prefit)
#----------------------------------------------------------
#lq_et_1_13TeV             0.11484
#
#Bin                       Total relative bkg uncert. (postfit)
#----------------------------------------------------------
#lq_et_1_13TeV             0.02559
#
#Bin                       Process              Scale factor
#----------------------------------------------------------
#lq_et_1_13TeV             LQ_                  0.89526
#lq_et_1_13TeV             QCD                  0.97588
#lq_et_1_13TeV             SingleTop            0.90265
#lq_et_1_13TeV             TT                   0.86658
#lq_et_1_13TeV             VV                   0.90163
#lq_et_1_13TeV             W                    0.87459
#lq_et_1_13TeV             ZTT                  0.91035


def _GetSF(Channel,process):
    
    return 1
#    print "----->     Channel,process", Channel,process
#    
#    if Channel=="MuTau_DiJet":
#
#        #MuTau   DiJet     BASED ON THE ST Fit
#        if  process=="QCD"        :            return 0.97588
#        if  process=="SingleTop"    :            return 0.89815
#        if  process=="TT"           :            return 0.85865
#        if  process=="VV"           :            return 0.89172
#        if  process=="W"            :            return 0.87075
#        if  process=="ZTT"          :            return 0.89964
#
##        if  process=="QCD"        :            return 0.98152
##        if  process=="SingleTop"    :            return 0.86487
##        if  process=="TT"           :            return 0.83686
##        if  process=="VV"           :            return 0.87436
##        if  process=="W"            :            return 1.08430
##        if  process=="ZTT"          :            return 0.87517
#
#    
#
#    
#    
#    
#
#    if Channel=="EleTau_DiJet":
#        #EleTau   DiJet
#        if  process=="QCD"          :            return 0.97752
#        if  process=="SingleTop"    :            return 0.90099
#        if  process=="TT"           :            return 0.86775
#        if  process=="VV"           :            return 0.90117
#        if  process=="W"            :            return 0.87998
#        if  process=="ZTT"          :            return 0.90917
#
##EleTau   DiJet
##        if  process=="QCD"          :            return 0.98152
##        if  process=="SingleTop"    :            return 0.86728
##        if  process=="TT"           :            return 0.83919
##        if  process=="VV"           :            return 0.87679
##        if  process=="W"            :            return 1.08732
##        if  process=="ZTT"          :            return 0.87761
#
#
#
#
#
#    if Channel=="MuTau_JetBJet":
#        #MuTau   JetBJet
#        if  process=="QCD"          :            return 0.98603
#        if  process=="SingleTop"    :            return 0.88067
#        if  process=="TT"           :            return 0.82611
#        if  process=="VV"           :            return 0.86442
#        if  process=="W"            :            return 0.86417
#        if  process=="ZTT"          :            return 0.87969
#
#    if Channel=="EleTau_JetBJet":
#        #EleTau   JetBJet
#        if  process=="QCD"          :            return 0.98603
#        if  process=="SingleTop"    :            return 0.85370
#        if  process=="TT"           :            return 0.80080
#        if  process=="VV"           :            return 0.83794
#        if  process=="W"            :            return 0.83770
#        if  process=="ZTT"          :            return 0.85275


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
    lumi.AddText("9.2 fb^{-1} (13 TeV)")
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
        output = ROOT.TLegend(0.65, 0.4, 0.92, 0.82, "", "brNDC")
        output.SetLineWidth(0)
        output.SetLineStyle(0)
        output.SetFillStyle(0)
        output.SetBorderSize(0)
        output.SetTextFont(62)
        return output


def MakePlot(FileName,categoriy,HistName,Xaxis,Info,RB_,channel):
    ROOT.gStyle.SetFrameLineWidth(3)
    ROOT.gStyle.SetLineWidth(3)
    ROOT.gStyle.SetOptStat(0)

    c=ROOT.TCanvas("canvas","",0,0,600,600)
    c.cd()

    file=ROOT.TFile(FileName,"r")

    adapt=ROOT.gROOT.GetColor(12)
    new_idx=ROOT.gROOT.GetListOfColors().GetSize() + 1
#    trans=ROOT.TColor(new_idx, adapt.GetRed(), adapt.GetGreen(),adapt.GetBlue(), "",0.5)

#    categories=["MuTau_DiJet","MuTau_JetBJet"]
#    ncat=

    Data=file.Get(categoriy).Get("data_obs")
    Data.Rebin(RB_)
    
    QCD=file.Get(categoriy).Get("QCD")
    QCD.Rebin(RB_)
    QCD.Scale(_GetSF(channel,"QCD"))
    
    W=file.Get(categoriy).Get("W")
    W.Rebin(RB_)
    W.Scale(_GetSF(channel,"W"))
    
    TT=file.Get(categoriy).Get("TT")
    TT.Rebin(RB_)
    TT.Scale(_GetSF(channel,"TT"))

    VV=file.Get(categoriy).Get("VV")
    VV.Rebin(RB_)
    VV.Scale(_GetSF(channel,"VV"))
    
    SingleT=file.Get(categoriy).Get("SingleTop")
    SingleT.Rebin(RB_)
    SingleT.Scale(_GetSF(channel,"SingleTop"))
    
    DYS=file.Get(categoriy).Get("ZTT")
    DYS.Rebin(RB_)

    Data.GetXaxis().SetTitle("")
    Data.GetXaxis().SetTitleSize(0)
    Data.GetXaxis().SetNdivisions(505)
    Data.GetYaxis().SetLabelFont(42)
    Data.GetYaxis().SetLabelOffset(0.01)
    Data.GetYaxis().SetLabelSize(0.06)
    Data.GetYaxis().SetTitleSize(0.075)
    Data.GetYaxis().SetTitleOffset(1.04)
    Data.SetTitle("")
    Data.GetYaxis().SetTitle("Events")



    QCD.SetFillColor(ROOT.TColor.GetColor(408, 106, 154))
    W.SetFillColor(ROOT.TColor.GetColor(200, 2, 285))
    TT.SetFillColor(ROOT.TColor.GetColor(208, 376, 124))
    SingleT.SetFillColor(ROOT.TColor.GetColor(150, 132, 232))
    VV.SetFillColor(ROOT.TColor.GetColor(200, 282, 232))
    DYS.SetFillColor(ROOT.TColor.GetColor(108, 226, 354))
    
    
    
    ######  Add OverFlow Bin
    QCD.SetBinContent(QCD.GetNbinsX(),QCD.GetBinContent(QCD.GetNbinsX()+1)+QCD.GetBinContent(QCD.GetNbinsX()))
    W.SetBinContent(W.GetNbinsX(),W.GetBinContent(W.GetNbinsX()+1)+W.GetBinContent(W.GetNbinsX()))
    TT.SetBinContent(TT.GetNbinsX(),TT.GetBinContent(TT.GetNbinsX()+1)+TT.GetBinContent(TT.GetNbinsX()))
    SingleT.SetBinContent(SingleT.GetNbinsX(),SingleT.GetBinContent(SingleT.GetNbinsX()+1)+SingleT.GetBinContent(SingleT.GetNbinsX()))
    VV.SetBinContent(VV.GetNbinsX(),VV.GetBinContent(VV.GetNbinsX()+1)+VV.GetBinContent(VV.GetNbinsX()))
    DYS.SetBinContent(DYS.GetNbinsX(),DYS.GetBinContent(DYS.GetNbinsX()+1)+DYS.GetBinContent(DYS.GetNbinsX()))
    Data.SetBinContent(Data.GetNbinsX(),Data.GetBinContent(Data.GetNbinsX()+1)+Data.GetBinContent(Data.GetNbinsX()))

    Data.SetMarkerStyle(20)
    Data.SetMarkerSize(1)
    QCD.SetLineColor(ROOT.kBlack)
    W.SetLineColor(ROOT.kBlack)
    TT.SetLineColor(ROOT.kBlack)
    DYS.SetLineColor(ROOT.kBlack)
    VV.SetLineColor(ROOT.kBlack)
    SingleT.SetLineColor(ROOT.kBlack)
    Data.SetLineColor(ROOT.kBlack)
    Data.SetLineWidth(2)

    stack=ROOT.THStack("stack","stack")
    stack.Add(QCD)
    stack.Add(W)
    stack.Add(VV)
    stack.Add(DYS)
    stack.Add(SingleT)
    stack.Add(TT)

    errorBand = QCD.Clone()
    errorBand.Add(W)
    errorBand.Add(TT)
    errorBand.Add(VV)
    errorBand.Add(SingleT)
    errorBand.Add(DYS)
    errorBand.SetMarkerSize(0)
    errorBand.SetFillColor(16)
    errorBand.SetFillStyle(3001)
    errorBand.SetLineWidth(1)

    pad1 = ROOT.TPad("pad1","pad1",0,0.35,1,1)
    pad1.Draw()
    pad1.cd()
    pad1.SetFillColor(0)
    pad1.SetBorderMode(0)
    pad1.SetBorderSize(10)
    pad1.SetTickx(1)
    pad1.SetTicky(1)
    pad1.SetLeftMargin(0.18)
    pad1.SetRightMargin(0.05)
    pad1.SetTopMargin(0.122)
    pad1.SetBottomMargin(0.026)
    pad1.SetFrameFillStyle(0)
    pad1.SetFrameLineStyle(0)
    pad1.SetFrameLineWidth(3)
    pad1.SetFrameBorderMode(0)
    pad1.SetFrameBorderSize(10)

    Data.GetXaxis().SetLabelSize(0)
    Data.SetMaximum(Data.GetMaximum()*2.5)
    Data.SetMinimum(0)
    Data.Draw("e")
    stack.Draw("histsame")
    errorBand.Draw("e2same")
    Data.Draw("esame")

    legende=make_legend()
    legende.AddEntry(Data,"Observed","elp")
    legende.AddEntry(TT,"t#bar{t}+jets","f")
    legende.AddEntry(SingleT,"SingleTop","f")
    legende.AddEntry(DYS,"DY #rightarrowll ","f")
    legende.AddEntry(VV,"Diboson","f")
    legende.AddEntry(W,"W","f")
    legende.AddEntry(QCD,"QCD multijet","f")
    legende.AddEntry(errorBand,"Uncertainty","f")

    legende.Draw()

    l1=add_lumi()
    l1.Draw("same")
    l2=add_CMS()
    l2.Draw("same")
    l3=add_Preliminary()
    l3.Draw("same")

    pad1.RedrawAxis()

    categ  = ROOT.TPaveText(0.21, 0.5+0.013, 0.43, 0.70+0.155, "NDC")
    categ.SetBorderSize(   0 )
    categ.SetFillStyle(    0 )
    categ.SetTextAlign(   12 )
    categ.SetTextSize ( 0.06 )
    categ.SetTextColor(    1 )
    categ.SetTextFont (   41 )
    #       if i==1 or i==3: 
    categ.AddText(channel)
    #       else :
    #        categ.AddText("SS")
    categ.Draw()

    c.cd()
    pad2 = ROOT.TPad("pad2","pad2",0,0,1,0.35);
    pad2.SetTopMargin(0.05);
    pad2.SetBottomMargin(0.35);
    pad2.SetLeftMargin(0.18);
    pad2.SetRightMargin(0.05);
    pad2.SetTickx(1)
    pad2.SetTicky(1)
    pad2.SetFrameLineWidth(3)
    pad2.SetGridx()
    pad2.SetGridy()
    pad2.Draw()
    pad2.cd()
    
    h1=errorBand.Clone()
    h1.SetMaximum(2)
    h1.SetMinimum(0.1)
    h1.SetMarkerStyle(20)

    h3=Data.Clone()
    
    h3.Sumw2()
    h1.Sumw2()
    
    
    h1.SetStats(0)
    h3.SetStats(0)
    h1.SetTitle("")
    
    h1.Divide(errorBand)
    h3.Divide(errorBand)


    h1.GetXaxis().SetTitle(Xaxis)
    h1.GetXaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetLabelSize(0.08)
    h1.GetYaxis().SetTitle("Obs./Exp.")
    h1.GetXaxis().SetNdivisions(505)
    h1.GetYaxis().SetNdivisions(5)
    h1.GetXaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleSize(0.15)
    h1.GetYaxis().SetTitleOffset(0.56)
    h1.GetXaxis().SetTitleOffset(1.04)
    h1.GetXaxis().SetLabelSize(0.11)
    h1.GetYaxis().SetLabelSize(0.11)
    h1.GetXaxis().SetTitleFont(42)
    h1.GetYaxis().SetTitleFont(42)
    
    h1.Draw("e2")
    h3.Draw("epsame")

    c.cd()
    pad1.Draw()

    ROOT.gPad.RedrawAxis()

    c.Modified()
    c.SaveAs("_plot"+HistName+"_"+categoriy+".pdf")
    #       c.SaveAs("mvis"+categoriy+".png")


channelDirectory = ["MuTau", "EleTau"]
#channelDirectory = ["MuTau"]
Category = ["_DiJet","_JetBJet"]
#Category = ["_JetBJet"]
#Category = ["_inclusive"]


FileNamesInfo=[
#               ["_tmass","M_{T}(lep,MET) (GeV)","",20],
#               ["_VisMass","M_{l#tau} (GeV)","",20],
               ["_LepPt","lepton p_{T} (GeV)","",10],
               ["_LepEta","lepton #eta ","",10],
               ["_TauPt","#tau p_{T} (GeV)","",10],
               ["_TauEta","#tau #eta ","",10],
               ["_NumJet","Jet multiplicity","",1],
               ["_NumBJet","B Jet multiplicity","",1],
#               ["_nVtx","# of vertex","",1],
#               ["_nVtx_NoPU","# of vertex before PU reweighting","",1],
               ["_MET","MET  (GeV)","",20],
#               ["_M_taujet","M_{#tauj}   (GeV)","",40],
               ["_LeadJetPt","Leading Jet p_{T}  (GeV)","",10],
               ["_SubLeadJetPt","subleading Jet p_{T}  (GeV)","",10],
               ["_LeadJetEta","Leading Jet #eta","",10],
               ["_SubLeadJetEta","subleading #eta","",10],
#               ["_ST_DiJet","ST_{l#taujj}  (GeV) ","",10],
               ["_ST_MET","ST_{l#taujjMET}  (GeV)","",10],
               
               
               ]


for ch in channelDirectory:
    for cat in Category:
        for i in range(0,len(FileNamesInfo)):

#            FileName="TotalRootForLimit_PreSelection_"+ch+FileNamesInfo[i][0]+"_OS.root"
            FileName="TotalRootForLimit_PreSelection_"+ch+FileNamesInfo[i][0]+".root"
            MakePlot(FileName,ch+cat,FileNamesInfo[i][0],FileNamesInfo[i][1],FileNamesInfo[i][2],FileNamesInfo[i][3],ch+cat)

