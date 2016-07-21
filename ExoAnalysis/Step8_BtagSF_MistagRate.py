#Test
#!/usr/bin/env python
import ROOT
from ROOT import *
import re
from array import array


import glob
print glob.glob("OutFiles_FullSelection/*.root")
ListMC= glob.glob("OutFiles_FullSelection/*.root")
channelDirectory = ["MuTau", "EleTau"]

for Sample in ListMC:
    for Channel in channelDirectory:

        print "\n%%%%%%%%% Now stating    ",Sample,Channel

        OutFile1=TFile(Sample)

        BtagCen =OutFile1.Get(Channel+"_LQ_ST_MET_OS_JetBJet")
        if not BtagCen: continue
        Cen=BtagCen.Integral()
#        print BtagCen.Integral()

        BtagUp =OutFile1.Get(Channel+"_LQ_ST_MET_BtagUp_OS_JetBJet")
        Up=BtagUp.Integral()
#        print BtagUp.Integral()

        BtagDown =OutFile1.Get(Channel+"_LQ_ST_MET_BtagDown_OS_JetBJet")
        Down=BtagDown.Integral()
#        print BtagDown.Integral()

        SF= (Down-Up)/(2*Cen)
        print Sample,Channel,"  -->SF= ",SF

