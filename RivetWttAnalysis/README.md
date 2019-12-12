## setup environment

```
asetup 21.6.13,AthGeneration,here
source setupRivet.sh
```

## build plugin

```
rivet-buildplugin Rivetttw_ttH-ml.so ttw_ttH-ml.cc
rivet-buildplugin Rivetttwqq.so ttwqq.cc
```

## local runs

```
athena -c 'xs=1' ttw_tth_grjo.py
```

## submit jobs
setup environment: 
```
 lsetup rucio pyami panda
```

run ```pathena``` commands:
```
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc15_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.evgen.EVNT.e7286 --outDS=user.kgrevtso.rvt413008_off_1209_v0 ttw_tth_grjo.py 
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc15_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.evgen.EVNT.e5070 --outDS=user.kgrevtso.rvt410155_off_1209_v0 ttw_tth_grjo.py
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc16_13TeV.700000.Sh_228_ttW.merge.EVNT.e7793_e7400 --outDS=user.kgrevtso.rvt700000_off_1209_v0 ttw_tth_grjo.py
```


Submit ttWqq

#ttW 0.00065206 nb
pathena -c 'xs=0.00065206' --noBuild --extFile=Rivetttwqq.so --extOutFile ttwqq.yoda --inDS=mc15_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.evgen.EVNT.e7286 --outDS=user.kgrevtso.rvt413008_wqq_1212_v0 ttw_tth_grjo.py 

# ttW(qq)  0.00052821 nb
pathena -c 'xs=0.00052821' --noBuild --extFile=Rivetttwqq.so --extOutFile ttwqq.yoda --inDS=mc15_13TeV.410157.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttZqq.evgen.EVNT.e5070 --outDS=user.kgrevtso.rvt410157_wqq_1212_v0 ttw_tth_grjo.py

# ttbar 0.72977 nb
pathena -c 'xs=0.72977' --noBuild --extFile=Rivetttwqq.so --extOutFile ttwqq.yoda --inDS=mc15_13TeV.410472.PhPy8EG_A14_ttbar_hdamp258p75_dil.evgen.EVNT.e6348 --outDS=user.kgrevtso.rvt410472_wqq_1212_v0 ttw_tth_grjo.py 
