#ifndef __WTT__
#define __WTT__ 1

#include <memory>
#include "TopEventSelectionTools/TreeManager.h"

#define MAXSYST 50

namespace top {
  enum LepType { ELECTRON, MUON, GENERIC };
  struct Lepton
  {
    float SFIDTight[MAXSYST];
    float SFIDLoose[MAXSYST];
    float SFTrigTight[MAXSYST];
    float SFTrigLoose[MAXSYST];
    float SFIsoTight[MAXSYST];
    float SFIsoLoose[MAXSYST];
    float SFReco[MAXSYST];
    float SFTTVA[MAXSYST];
    float SFObjTight[MAXSYST];
    float SFObjLoose[MAXSYST];
    float  d0;
    float  z0;
    float  vz;
    float  Pt;
    float  Eta;
    float  Phi;
    float  Charge;
    float  E;
    float  ID;

    char    BLayer_hit;
    char    conv;
    char    isTightPP;
    char    isMediumPP;
    char    isLoosePP;
    char    isMultiLepton;
    char    isVeryTightLH;
    char    isTightLH;
    char    isMediumLH;
    char    isLooseLH;
    char    isVeryLooseLH;
    char    isCombined;
    char    isTight;
    char    isMedium;
    char    isLoose;
    char    isHSG3Clear;
    char    isHSG3IsoClear;
    int    isolationLooseTrackOnly;
    int    isolationLoose;
    int    isolationGradient;
    int    isolationGradientLoose;
    int    isolationFixedCutTight;
    int    isolationFixedCutTightTrackOnly;
    int    isolationFixedCutLoose;

    char    isTrigMatch;
    char    isTrigMatchDLT;
    char    isFakable;
    int     Author;
    int     allAuthor;
    int     Index;
    int     D3PDIndex;
    int     Truth_parent_particle_ID;
    int     Truth_particle_ID;

    char    isPrompt;
    char    isFakeLep;
    char    isQMisID;
    char    isConvPh;
    char    isExtConvPh;
    char    isIntConvPh;
    char    isISR_FSR_Ph;
    char    isBrems;
   
    
    float   chargeIDBDTLoose;
    float   chargeIDBDTMedium;
    float   chargeIDBDTTight;

    char    isTruthMatched;


    int     truthPdgId;
    int     truthStatus;
    int     truthType;
    int     truthOrigin;
    int     truthParentPdgId;
    int     truthParentStatus;
    int     truthParentType;
    int     truthParentOrigin;
    int     firstEgMotherPdgId;
    int     firstEgMotherTruthType;
    int     firstEgMotherTruthOrigin;
    float   truthPt;
    float   truthEta;
    float   truthPhi;
    float   truthM;
    float   truthE;
    float   truthRapidity;

    float   EffTrigLoose[MAXSYST];
    float   EffTrigTight[MAXSYST];
    unsigned char ambiguityType;
    int nInnerPix;

    int     nTrackParticles;
    float   Mtrktrk_atPV_CO;
    float   Mtrktrk_atConvV_CO;
    float   RadiusCO;
    float   RadiusCOX;
    float   RadiusCOY;
    float   SeparationMinDCT;
    float   ClosestSiTracknIL;
    float   ClosestSiTrackeIL;
    float   ClosestSiTracknNIL;
    float   ClosestSiTrackeNIL;
    float   BestMatchTrackPt;
    float   BestMatchTrackEta;
    float   BestMatchTrackPhi;
    float   BestMatchTrackD0;
    float   BestMatchTrackZ0;
    float   BestMatchTrackQ;
    float   ClosestSiTrackPt;
    float   ClosestSiTrackEta;
    float   ClosestSiTrackPhi;
    float   ClosestSiTrackD0;
    float   ClosestSiTrackZ0;
    float   ClosestSiTrackQ;

    //void BootstrapTree(std::shared_ptr<top::TreeManager> tree, int index);

  };
}
#endif

