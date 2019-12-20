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

## Running with docker
ATLAS provides containers for AnalysisTop releases. 
Pull corresponding tag from: https://hub.docker.com/r/atlas/analysistop/tags

Make accessible local files to avoid loss of the changes in the code as well as option for accessing the local data:
```
docker run --rm -it -v $PWD:$PWD -w $PWD atlas/analysistop
```
In the ```source``` setup release:
```
source ~/release_setup.sh
```
Require to have default CMakeLists.txt in the source folder (with the main code) for compiling 

### Run on grid
Setup tools:
``` 
lsetup rucio panda pyami
```

use submission folder (copy to your run from ...):
```
python grid/01SubmitToGrid_Tutorial.py
```