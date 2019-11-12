
## setup environment

```
asetup 21.6.3,AthGeneration,here
source setupRivet.sh
```

## build plugin

```
rivet-buildplugin Rivetttw_ttH-ml.so ttw_ttH-ml.cc
```

## submit jobs

```
pathena -c 'xs=1' --noBuild --extFile=ivetttw_ttH-ml.so --extOutFile ttw_ttH.yoda --inDS=mc15_13TeV.413008.Sherpa_221_NN30NNLO_ttW_multilegNLO.evgen.EVNT.e7286 --outDS=user.kgrevtso.rvt41300\
8_xs1_2510_v0
```
