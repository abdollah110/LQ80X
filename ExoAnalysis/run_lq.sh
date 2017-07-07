combineTool.py -M T2W -i LIMITS/* -o workspace.root --parallel 8
combineTool.py -M Asymptotic -d */*/workspace.root --there -n .limit --parallel 8   --rAbsAcc 0 --rRelAcc 0.001
combineTool.py -M CollectLimits */*/*.limit.* --use-dirs -o limits.json



