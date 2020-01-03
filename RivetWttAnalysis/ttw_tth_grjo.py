from glob import glob
import sys,os


theApp.EvtMax = -1
#theApp.EvtMax=5000

import AthenaPoolCnvSvc.ReadAthenaPool

infile = "input.txt"
#infile = "in_ttz.txt"
if os.path.exists(infile):
    with open(infile) as f:
        rd=f.read()
        rd1=rd.replace("\n",",")
        inplist=[]
        for x in rd1.split(","):
            if not x=="":
                print ('x=',x)
                inplist.append(x)
        
        svcMgr.EventSelector.InputCollections = inplist
else:
    print ("no file")
    #sys.exit()

from AthenaCommon.AppMgr import ServiceMgr as svcMgr
from AthenaCommon.AlgSequence import AlgSequence
job = AlgSequence()

#OutputRoot="Rivet_"+fitt+".root"
from GaudiSvc.GaudiSvcConf import THistSvc
ServiceMgr += THistSvc()
ServiceMgr.THistSvc.Output = ["Rivet DATAFILE='Rivet.root' OPT='RECREATE'"]
ServiceMgr.MessageSvc.OutputLevel = 4 #INFO #DEBUG 

from Rivet_i.Rivet_iConf import Rivet_i

import os
rivet = Rivet_i()
rivet.AnalysisPath = os.environ['PWD']

#rivet.Analyses +=['ttw_ttH']
rivet.Analyses +=['ttwqq']
rivet.RunName = ""
# https://twiki.cern.ch/twiki/bin/view/AtlasProtected/RivetForAtlas#Use_with_Multiple_LHE_Weights
#rivet.WeightName="MUR0.5_MUF0.5_PDF261000"
#rivet.WeightName="MUR2_MUF2_PDF261000"
#rivet.HistoFile = "ttw_ttH"
rivet.HistoFile = "ttw_qq"
rivet.DoRootHistos=True
rivet.CrossSection = xs # xs to be read from athena or pathena commandline
print "CrossSection",xs
job += rivet
