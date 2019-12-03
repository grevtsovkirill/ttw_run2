# Ntuple Production code

based on AnalysisTop framework.

Process TOPQ1 derivations, save flat ntuples for further analysis.

Track changies with date stamps in ChangeLog



## Initialization
More info at [AT Guide](https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/TopxAODStartGuideR21#Introduction):
```
cd source
asetup AnalysisTop,21.2.XX,here
```
check for latest version at [release notes](https://twiki.cern.ch/twiki/bin/view/AtlasProtected/AnalysisTop21)

```
cd ../build/
 cmake ../source/
cmake --build ./
source x86_64-centos7-gcc8-opt/setup.sh 
```


### Run on grid
Setup tools:
``` 
lsetup rucio panda pyami
```

use submission folder (copy to your run from ...):
```
python grid/01SubmitToGrid_Tutorial.py
```