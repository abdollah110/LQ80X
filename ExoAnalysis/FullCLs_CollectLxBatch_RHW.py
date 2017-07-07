import os
qList=["","--expectedFromGrid 0.50","--expectedFromGrid 0.160","--expectedFromGrid 0.025","--expectedFromGrid 0.975","--expectedFromGrid 0.840"]

def my_range(start, end, step):
    while start <= end:
        yield start
        start += step

#for Mass in my_range(1, 54, 1):
for Mass in my_range(27, 54, 1):
    os.system("hadd -f Tot_"+str(Mass)+".root higgsCombine.Test.POINT*.mH"+str(Mass)+".*.root")
    for quantile in qList:
	os.system("combine -d LIMITS/"+str(Mass)+"/workspace.root -M HybridNew --freq --testStat LHC --grid=Tot_"+str(Mass)+".root -m "+str(Mass)+"  "+ quantile)
    os.system("hadd  -f LIMITS/"+str(Mass)+"/HybridNew.root  higgsCombineTest.HybridNew.mH"+str(Mass)+"*.root")

os.system("combineTool.py -M CollectLimits */*/HybridNew.root --use-dirs -o limits_Hybrid.json")

