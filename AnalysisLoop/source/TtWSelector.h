//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Oct 29 13:28:40 2019 by ROOT version 6.15/02
// from TTree nominal/tree
// found on file: ../../../Files/pflow_tests/413008aPF.root
//////////////////////////////////////////////////////////

#ifndef TtWSelector_h
#define TtWSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>



class TtWSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Float_t> weight_mc = {fReader, "weight_mc"};
   TTreeReaderValue<Float_t> weight_pileup = {fReader, "weight_pileup"};
   TTreeReaderValue<Float_t> weight_leptonSF = {fReader, "weight_leptonSF"};
   TTreeReaderValue<Float_t> weight_photonSF = {fReader, "weight_photonSF"};
   TTreeReaderValue<Float_t> weight_tauSF = {fReader, "weight_tauSF"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF = {fReader, "weight_globalLeptonTriggerSF"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF = {fReader, "weight_oldTriggerSF"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77 = {fReader, "weight_bTagSF_MV2c10_77"};
   TTreeReaderValue<Float_t> weight_trackjet_bTagSF_MV2c10_77 = {fReader, "weight_trackjet_bTagSF_MV2c10_77"};
   TTreeReaderValue<Float_t> weight_jvt = {fReader, "weight_jvt"};
   TTreeReaderValue<Float_t> weight_pileup_UP = {fReader, "weight_pileup_UP"};
   TTreeReaderValue<Float_t> weight_pileup_DOWN = {fReader, "weight_pileup_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Trigger_UP = {fReader, "weight_leptonSF_EL_SF_Trigger_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Trigger_DOWN = {fReader, "weight_leptonSF_EL_SF_Trigger_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Reco_UP = {fReader, "weight_leptonSF_EL_SF_Reco_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Reco_DOWN = {fReader, "weight_leptonSF_EL_SF_Reco_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_ID_UP = {fReader, "weight_leptonSF_EL_SF_ID_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_ID_DOWN = {fReader, "weight_leptonSF_EL_SF_ID_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Isol_UP = {fReader, "weight_leptonSF_EL_SF_Isol_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_EL_SF_Isol_DOWN = {fReader, "weight_leptonSF_EL_SF_Isol_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_STAT_UP = {fReader, "weight_leptonSF_MU_SF_Trigger_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_Trigger_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_SYST_UP = {fReader, "weight_leptonSF_MU_SF_Trigger_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Trigger_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_Trigger_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_UP = {fReader, "weight_leptonSF_MU_SF_ID_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_UP = {fReader, "weight_leptonSF_MU_SF_ID_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP = {fReader, "weight_leptonSF_MU_SF_ID_STAT_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_STAT_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP = {fReader, "weight_leptonSF_MU_SF_ID_SYST_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN = {fReader, "weight_leptonSF_MU_SF_ID_SYST_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_STAT_UP = {fReader, "weight_leptonSF_MU_SF_Isol_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_Isol_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_SYST_UP = {fReader, "weight_leptonSF_MU_SF_Isol_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_Isol_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_Isol_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_STAT_UP = {fReader, "weight_leptonSF_MU_SF_TTVA_STAT_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_STAT_DOWN = {fReader, "weight_leptonSF_MU_SF_TTVA_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_SYST_UP = {fReader, "weight_leptonSF_MU_SF_TTVA_SYST_UP"};
   TTreeReaderValue<Float_t> weight_leptonSF_MU_SF_TTVA_SYST_DOWN = {fReader, "weight_leptonSF_MU_SF_TTVA_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_EL_Trigger_UP = {fReader, "weight_globalLeptonTriggerSF_EL_Trigger_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_EL_Trigger_DOWN = {fReader, "weight_globalLeptonTriggerSF_EL_Trigger_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_STAT_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_SYST_UP"};
   TTreeReaderValue<Float_t> weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN = {fReader, "weight_globalLeptonTriggerSF_MU_Trigger_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_EL_Trigger_UP = {fReader, "weight_oldTriggerSF_EL_Trigger_UP"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_EL_Trigger_DOWN = {fReader, "weight_oldTriggerSF_EL_Trigger_DOWN"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_MU_Trigger_STAT_UP = {fReader, "weight_oldTriggerSF_MU_Trigger_STAT_UP"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_MU_Trigger_STAT_DOWN = {fReader, "weight_oldTriggerSF_MU_Trigger_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_MU_Trigger_SYST_UP = {fReader, "weight_oldTriggerSF_MU_Trigger_SYST_UP"};
   TTreeReaderValue<Float_t> weight_oldTriggerSF_MU_Trigger_SYST_DOWN = {fReader, "weight_oldTriggerSF_MU_Trigger_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Reco = {fReader, "weight_indiv_SF_EL_Reco"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Reco_UP = {fReader, "weight_indiv_SF_EL_Reco_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Reco_DOWN = {fReader, "weight_indiv_SF_EL_Reco_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ID = {fReader, "weight_indiv_SF_EL_ID"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ID_UP = {fReader, "weight_indiv_SF_EL_ID_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ID_DOWN = {fReader, "weight_indiv_SF_EL_ID_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Isol = {fReader, "weight_indiv_SF_EL_Isol"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Isol_UP = {fReader, "weight_indiv_SF_EL_Isol_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_Isol_DOWN = {fReader, "weight_indiv_SF_EL_Isol_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeID = {fReader, "weight_indiv_SF_EL_ChargeID"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeID_UP = {fReader, "weight_indiv_SF_EL_ChargeID_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeID_DOWN = {fReader, "weight_indiv_SF_EL_ChargeID_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeMisID = {fReader, "weight_indiv_SF_EL_ChargeMisID"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeMisID_STAT_UP = {fReader, "weight_indiv_SF_EL_ChargeMisID_STAT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeMisID_STAT_DOWN = {fReader, "weight_indiv_SF_EL_ChargeMisID_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeMisID_SYST_UP = {fReader, "weight_indiv_SF_EL_ChargeMisID_SYST_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_EL_ChargeMisID_SYST_DOWN = {fReader, "weight_indiv_SF_EL_ChargeMisID_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID = {fReader, "weight_indiv_SF_MU_ID"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_STAT_UP = {fReader, "weight_indiv_SF_MU_ID_STAT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_STAT_DOWN = {fReader, "weight_indiv_SF_MU_ID_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_SYST_UP = {fReader, "weight_indiv_SF_MU_ID_SYST_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_SYST_DOWN = {fReader, "weight_indiv_SF_MU_ID_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_STAT_LOWPT_UP = {fReader, "weight_indiv_SF_MU_ID_STAT_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN = {fReader, "weight_indiv_SF_MU_ID_STAT_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_SYST_LOWPT_UP = {fReader, "weight_indiv_SF_MU_ID_SYST_LOWPT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN = {fReader, "weight_indiv_SF_MU_ID_SYST_LOWPT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_Isol = {fReader, "weight_indiv_SF_MU_Isol"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_Isol_STAT_UP = {fReader, "weight_indiv_SF_MU_Isol_STAT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_Isol_STAT_DOWN = {fReader, "weight_indiv_SF_MU_Isol_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_Isol_SYST_UP = {fReader, "weight_indiv_SF_MU_Isol_SYST_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_Isol_SYST_DOWN = {fReader, "weight_indiv_SF_MU_Isol_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_TTVA = {fReader, "weight_indiv_SF_MU_TTVA"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_TTVA_STAT_UP = {fReader, "weight_indiv_SF_MU_TTVA_STAT_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_TTVA_STAT_DOWN = {fReader, "weight_indiv_SF_MU_TTVA_STAT_DOWN"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_TTVA_SYST_UP = {fReader, "weight_indiv_SF_MU_TTVA_SYST_UP"};
   TTreeReaderValue<Float_t> weight_indiv_SF_MU_TTVA_SYST_DOWN = {fReader, "weight_indiv_SF_MU_TTVA_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_ELEOLR_TOTAL_UP = {fReader, "weight_tauSF_EFF_ELEOLR_TOTAL_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_ELEOLR_TOTAL_DOWN = {fReader, "weight_tauSF_EFF_ELEOLR_TOTAL_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_STATHIGHMU_UP = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_STATHIGHMU_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_STATHIGHMU_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_STATHIGHMU_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_STATLOWMU_UP = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_STATLOWMU_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_STATLOWMU_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_STATLOWMU_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_SYST_UP = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_SYST_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEOLR_SYST_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEOLR_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_STATMC16A_UP = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_STATMC16A_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_STATMC16A_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_STATMC16A_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_STATMC16D_UP = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_STATMC16D_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_STATMC16D_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_STATMC16D_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_SYST_UP = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_SYST_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_ELE_EFF_ELEBDT_SYST_DOWN = {fReader, "weight_tauSF_ELE_EFF_ELEBDT_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P2025_UP = {fReader, "weight_tauSF_EFF_JETID_1P2025_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P2025_DOWN = {fReader, "weight_tauSF_EFF_JETID_1P2025_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P2530_UP = {fReader, "weight_tauSF_EFF_JETID_1P2530_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P2530_DOWN = {fReader, "weight_tauSF_EFF_JETID_1P2530_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P3040_UP = {fReader, "weight_tauSF_EFF_JETID_1P3040_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1P3040_DOWN = {fReader, "weight_tauSF_EFF_JETID_1P3040_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1PGE40_UP = {fReader, "weight_tauSF_EFF_JETID_1PGE40_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_1PGE40_DOWN = {fReader, "weight_tauSF_EFF_JETID_1PGE40_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_3P2030_UP = {fReader, "weight_tauSF_EFF_JETID_3P2030_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_3P2030_DOWN = {fReader, "weight_tauSF_EFF_JETID_3P2030_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_3PGE30_UP = {fReader, "weight_tauSF_EFF_JETID_3PGE30_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_3PGE30_DOWN = {fReader, "weight_tauSF_EFF_JETID_3PGE30_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_HIGHPT_UP = {fReader, "weight_tauSF_EFF_JETID_HIGHPT_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_HIGHPT_DOWN = {fReader, "weight_tauSF_EFF_JETID_HIGHPT_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_SYST_UP = {fReader, "weight_tauSF_EFF_JETID_SYST_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_SYST_DOWN = {fReader, "weight_tauSF_EFF_JETID_SYST_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_AFII_UP = {fReader, "weight_tauSF_EFF_JETID_AFII_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_JETID_AFII_DOWN = {fReader, "weight_tauSF_EFF_JETID_AFII_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_HIGHPT_UP = {fReader, "weight_tauSF_EFF_RECO_HIGHPT_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_HIGHPT_DOWN = {fReader, "weight_tauSF_EFF_RECO_HIGHPT_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_TOTAL_UP = {fReader, "weight_tauSF_EFF_RECO_TOTAL_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_TOTAL_DOWN = {fReader, "weight_tauSF_EFF_RECO_TOTAL_DOWN"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_AFII_UP = {fReader, "weight_tauSF_EFF_RECO_AFII_UP"};
   TTreeReaderValue<Float_t> weight_tauSF_EFF_RECO_AFII_DOWN = {fReader, "weight_tauSF_EFF_RECO_AFII_DOWN"};
   TTreeReaderValue<Float_t> weight_photonSF_ID_UP = {fReader, "weight_photonSF_ID_UP"};
   TTreeReaderValue<Float_t> weight_photonSF_ID_DOWN = {fReader, "weight_photonSF_ID_DOWN"};
   TTreeReaderValue<Float_t> weight_photonSF_effIso = {fReader, "weight_photonSF_effIso"};
   TTreeReaderValue<Float_t> weight_photonSF_effIso_UP = {fReader, "weight_photonSF_effIso_UP"};
   TTreeReaderValue<Float_t> weight_photonSF_effIso_DOWN = {fReader, "weight_photonSF_effIso_DOWN"};
   TTreeReaderValue<Float_t> weight_jvt_UP = {fReader, "weight_jvt_UP"};
   TTreeReaderValue<Float_t> weight_jvt_DOWN = {fReader, "weight_jvt_DOWN"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_B_up = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_B_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_C_up = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_C_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_Light_up = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_Light_up"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_B_down = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_B_down"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_C_down = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_C_down"};
   TTreeReaderArray<float> weight_bTagSF_MV2c10_77_eigenvars_Light_down = {fReader, "weight_bTagSF_MV2c10_77_eigenvars_Light_down"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77_extrapolation_up = {fReader, "weight_bTagSF_MV2c10_77_extrapolation_up"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77_extrapolation_down = {fReader, "weight_bTagSF_MV2c10_77_extrapolation_down"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77_extrapolation_from_charm_up = {fReader, "weight_bTagSF_MV2c10_77_extrapolation_from_charm_up"};
   TTreeReaderValue<Float_t> weight_bTagSF_MV2c10_77_extrapolation_from_charm_down = {fReader, "weight_bTagSF_MV2c10_77_extrapolation_from_charm_down"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_B_up = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_B_up"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_C_up = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_C_up"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_Light_up = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_Light_up"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_B_down = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_B_down"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_C_down = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_C_down"};
   TTreeReaderArray<float> weight_trackjet_bTagSF_MV2c10_77_eigenvars_Light_down = {fReader, "weight_trackjet_bTagSF_MV2c10_77_eigenvars_Light_down"};
   TTreeReaderValue<Float_t> weight_trackjet_bTagSF_MV2c10_77_extrapolation_up = {fReader, "weight_trackjet_bTagSF_MV2c10_77_extrapolation_up"};
   TTreeReaderValue<Float_t> weight_trackjet_bTagSF_MV2c10_77_extrapolation_down = {fReader, "weight_trackjet_bTagSF_MV2c10_77_extrapolation_down"};
   TTreeReaderValue<Float_t> weight_trackjet_bTagSF_MV2c10_77_extrapolation_from_charm_up = {fReader, "weight_trackjet_bTagSF_MV2c10_77_extrapolation_from_charm_up"};
   TTreeReaderValue<Float_t> weight_trackjet_bTagSF_MV2c10_77_extrapolation_from_charm_down = {fReader, "weight_trackjet_bTagSF_MV2c10_77_extrapolation_from_charm_down"};
   TTreeReaderValue<ULong64_t> eventNumber = {fReader, "eventNumber"};
   TTreeReaderValue<UInt_t> runNumber = {fReader, "runNumber"};
   TTreeReaderValue<UInt_t> randomRunNumber = {fReader, "randomRunNumber"};
   TTreeReaderValue<UInt_t> mcChannelNumber = {fReader, "mcChannelNumber"};
   TTreeReaderValue<Float_t> mu = {fReader, "mu"};
   TTreeReaderValue<Float_t> mu_actual = {fReader, "mu_actual"};
   TTreeReaderValue<UInt_t> backgroundFlags = {fReader, "backgroundFlags"};
   TTreeReaderValue<UInt_t> hasBadMuon = {fReader, "hasBadMuon"};
   TTreeReaderArray<float> el_pt = {fReader, "el_pt"};
   TTreeReaderArray<float> el_eta = {fReader, "el_eta"};
   TTreeReaderArray<float> el_cl_eta = {fReader, "el_cl_eta"};
   TTreeReaderArray<float> el_phi = {fReader, "el_phi"};
   TTreeReaderArray<float> el_e = {fReader, "el_e"};
   TTreeReaderArray<float> el_charge = {fReader, "el_charge"};
   TTreeReaderArray<float> el_topoetcone20 = {fReader, "el_topoetcone20"};
   TTreeReaderArray<float> el_ptvarcone20 = {fReader, "el_ptvarcone20"};
   TTreeReaderArray<char> el_CF = {fReader, "el_CF"};
   TTreeReaderArray<float> el_d0sig = {fReader, "el_d0sig"};
   TTreeReaderArray<float> el_delta_z0_sintheta = {fReader, "el_delta_z0_sintheta"};
   TTreeReaderArray<int> el_true_type = {fReader, "el_true_type"};
   TTreeReaderArray<int> el_true_origin = {fReader, "el_true_origin"};
   TTreeReaderArray<int> el_true_firstEgMotherTruthType = {fReader, "el_true_firstEgMotherTruthType"};
   TTreeReaderArray<int> el_true_firstEgMotherTruthOrigin = {fReader, "el_true_firstEgMotherTruthOrigin"};
   TTreeReaderArray<int> el_true_firstEgMotherPdgId = {fReader, "el_true_firstEgMotherPdgId"};
   TTreeReaderArray<char> el_true_isPrompt = {fReader, "el_true_isPrompt"};
   TTreeReaderArray<char> el_true_isChargeFl = {fReader, "el_true_isChargeFl"};
   TTreeReaderArray<float> mu_pt = {fReader, "mu_pt"};
   TTreeReaderArray<float> mu_eta = {fReader, "mu_eta"};
   TTreeReaderArray<float> mu_phi = {fReader, "mu_phi"};
   TTreeReaderArray<float> mu_e = {fReader, "mu_e"};
   TTreeReaderArray<float> mu_charge = {fReader, "mu_charge"};
   TTreeReaderArray<float> mu_topoetcone20 = {fReader, "mu_topoetcone20"};
   TTreeReaderArray<float> mu_ptvarcone30 = {fReader, "mu_ptvarcone30"};
   TTreeReaderArray<float> mu_d0sig = {fReader, "mu_d0sig"};
   TTreeReaderArray<float> mu_delta_z0_sintheta = {fReader, "mu_delta_z0_sintheta"};
   TTreeReaderArray<int> mu_true_type = {fReader, "mu_true_type"};
   TTreeReaderArray<int> mu_true_origin = {fReader, "mu_true_origin"};
   TTreeReaderArray<char> mu_true_isPrompt = {fReader, "mu_true_isPrompt"};
   TTreeReaderArray<float> ph_pt = {fReader, "ph_pt"};
   TTreeReaderArray<float> ph_eta = {fReader, "ph_eta"};
   TTreeReaderArray<float> ph_phi = {fReader, "ph_phi"};
   TTreeReaderArray<float> ph_e = {fReader, "ph_e"};
   TTreeReaderArray<float> ph_iso = {fReader, "ph_iso"};
   TTreeReaderArray<float> tau_pt = {fReader, "tau_pt"};
   TTreeReaderArray<float> tau_eta = {fReader, "tau_eta"};
   TTreeReaderArray<float> tau_phi = {fReader, "tau_phi"};
   TTreeReaderArray<float> tau_charge = {fReader, "tau_charge"};
   TTreeReaderArray<float> jet_pt = {fReader, "jet_pt"};
   TTreeReaderArray<float> jet_eta = {fReader, "jet_eta"};
   TTreeReaderArray<float> jet_phi = {fReader, "jet_phi"};
   TTreeReaderArray<float> jet_e = {fReader, "jet_e"};
   TTreeReaderArray<float> jet_mv2c00 = {fReader, "jet_mv2c00"};
   TTreeReaderArray<float> jet_mv2c10 = {fReader, "jet_mv2c10"};
   TTreeReaderArray<float> jet_mv2c20 = {fReader, "jet_mv2c20"};
   TTreeReaderArray<float> jet_ip3dsv1 = {fReader, "jet_ip3dsv1"};
   TTreeReaderArray<float> jet_jvt = {fReader, "jet_jvt"};
   TTreeReaderArray<char> jet_passfjvt = {fReader, "jet_passfjvt"};
   TTreeReaderArray<int> jet_truthflav = {fReader, "jet_truthflav"};
   TTreeReaderArray<int> jet_truthPartonLabel = {fReader, "jet_truthPartonLabel"};
   TTreeReaderArray<char> jet_isTrueHS = {fReader, "jet_isTrueHS"};
   TTreeReaderArray<int> jet_truthflavExtended = {fReader, "jet_truthflavExtended"};
   TTreeReaderArray<char> jet_isbtagged_MV2c10_77 = {fReader, "jet_isbtagged_MV2c10_77"};
   TTreeReaderArray<float> jet_MV2r = {fReader, "jet_MV2r"};
   TTreeReaderArray<float> jet_MV2rmu = {fReader, "jet_MV2rmu"};
   TTreeReaderArray<float> jet_DL1 = {fReader, "jet_DL1"};
   TTreeReaderArray<float> jet_DL1r = {fReader, "jet_DL1r"};
   TTreeReaderArray<float> jet_DL1rmu = {fReader, "jet_DL1rmu"};
   TTreeReaderArray<float> jet_MV2cl100 = {fReader, "jet_MV2cl100"};
   TTreeReaderArray<float> jet_MV2c100 = {fReader, "jet_MV2c100"};
   TTreeReaderArray<float> jet_DL1_pu = {fReader, "jet_DL1_pu"};
   TTreeReaderArray<float> jet_DL1_pc = {fReader, "jet_DL1_pc"};
   TTreeReaderArray<float> jet_DL1_pb = {fReader, "jet_DL1_pb"};
   TTreeReaderArray<float> jet_DL1r_pu = {fReader, "jet_DL1r_pu"};
   TTreeReaderArray<float> jet_DL1r_pc = {fReader, "jet_DL1r_pc"};
   TTreeReaderArray<float> jet_DL1r_pb = {fReader, "jet_DL1r_pb"};
   TTreeReaderArray<float> jet_DL1rmu_pu = {fReader, "jet_DL1rmu_pu"};
   TTreeReaderArray<float> jet_DL1rmu_pc = {fReader, "jet_DL1rmu_pc"};
   TTreeReaderArray<float> jet_DL1rmu_pb = {fReader, "jet_DL1rmu_pb"};
   TTreeReaderArray<float> ljet_pt = {fReader, "ljet_pt"};
   TTreeReaderArray<float> ljet_eta = {fReader, "ljet_eta"};
   TTreeReaderArray<float> ljet_phi = {fReader, "ljet_phi"};
   TTreeReaderArray<float> ljet_e = {fReader, "ljet_e"};
   TTreeReaderArray<float> ljet_m = {fReader, "ljet_m"};
   TTreeReaderArray<float> ljet_sd12 = {fReader, "ljet_sd12"};
   TTreeReaderArray<char> ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkInclusive50 = {fReader, "ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkInclusive50"};
   TTreeReaderArray<char> ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkInclusive80 = {fReader, "ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkInclusive80"};
   TTreeReaderArray<char> ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkContained50 = {fReader, "ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkContained50"};
   TTreeReaderArray<char> ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkContained80 = {fReader, "ljet_isTagged_JSSWTopTaggerDNN_DNNTaggerTopQuarkContained80"};
   TTreeReaderArray<float> tjet_pt = {fReader, "tjet_pt"};
   TTreeReaderArray<float> tjet_eta = {fReader, "tjet_eta"};
   TTreeReaderArray<float> tjet_phi = {fReader, "tjet_phi"};
   TTreeReaderArray<float> tjet_e = {fReader, "tjet_e"};
   TTreeReaderArray<float> tjet_mv2c00 = {fReader, "tjet_mv2c00"};
   TTreeReaderArray<float> tjet_mv2c10 = {fReader, "tjet_mv2c10"};
   TTreeReaderArray<float> tjet_mv2c20 = {fReader, "tjet_mv2c20"};
   TTreeReaderArray<float> tjet_DL1 = {fReader, "tjet_DL1"};
   TTreeReaderArray<float> tjet_DL1r = {fReader, "tjet_DL1r"};
   TTreeReaderArray<float> tjet_DL1rmu = {fReader, "tjet_DL1rmu"};
   TTreeReaderArray<char> tjet_isbtagged_MV2c10_77 = {fReader, "tjet_isbtagged_MV2c10_77"};
   TTreeReaderValue<Float_t> met_met = {fReader, "met_met"};
   TTreeReaderValue<Float_t> met_phi = {fReader, "met_phi"};
   TTreeReaderValue<Int_t> ss = {fReader, "ss"};
   TTreeReaderValue<Int_t> tril_2j = {fReader, "tril_2j"};
   TTreeReaderValue<Int_t> tril_3j = {fReader, "tril_3j"};


   TtWSelector(TTree * /*tree*/ =0) { }
   virtual ~TtWSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TtWSelector,0);

};

#endif

#ifdef TtWSelector_cxx
void TtWSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t TtWSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef TtWSelector_cxx
