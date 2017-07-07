import os
import json
from pprint import pprint

with open('limits_LIMITS.json') as data_file:
    data = json.load(data_file)
#pprint(data)

#print "---->", data["1000"+".0"]["exp0"]




def my_range(start, end, step):
    while start <= end:
        yield start
        start += step

for Mass in my_range(44, 54, 1):

	space=":"
	num1=data[str(Mass)+".0"]["exp0"]/5
        num2=data[str(Mass)+".0"]["exp0"]*5
	seq=(str(num1),str(num2),str(num1))
	slash="/"
	WS=("LIMITS",str(Mass),"workspace.root")
	

	#print "combineTool.py -M HybridNew -d ",slash.join(WS)," --testStat LHC --freq --singlePoint",space.join(seq)," limits_LIMITS.json -T 2000 -s -1 --saveToys --saveHybridResult --dry-run"+" -m",Mass

	print "combineTool.py -d ",slash.join(WS)," -M HybridNew --freq --clsAcc 0 --testStat LHC -T 8000 -s -1 --singlePoint ",space.join(seq)," --saveToys --saveHybridResult "," -m",Mass ," --job-mode lxbatch --task-name lxbatch-test --sub-opts='-q 8nh' --MassB ", Mass 
