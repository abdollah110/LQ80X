import os
if __name__ == "__main__":
    inPutFile=open("2016FullRHW.txt","r")
    
    for samples in inPutFile.readlines():
#        print samples
        if (samples[0] == "\n"): continue
        if (samples[0] != "/"): continue

        if (samples.find("reHLT") > -10):  print samples


