## setup environment

```
asetup 21.6.3,AthGeneration,here
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

```
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc15_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.evgen.EVNT.e7286 --outDS=user.kgrevtso.rvt413008_xs1woNu_1122_v0 ttw_tth_grjo.py 
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc15_13TeV.410155.aMcAtNloPythia8EvtGen_MEN30NLO_A14N23LO_ttW.evgen.EVNT.e5070 --outDS=user.kgrevtso.rvt410155_xs1woNu_1122_v0 ttw_tth_grjo.py
pathena -c 'xs=1' --noBuild --extFile=Rivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc16_13TeV.700000.Sh_228_ttW.merge.EVNT.e7793_e7400 --outDS=user.kgrevtso.rvt700000_xs1woNu_1122_v0 ttw_tth_grjo.py
```
