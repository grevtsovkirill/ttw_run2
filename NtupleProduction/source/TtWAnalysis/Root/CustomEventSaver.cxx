/*
  Copyright (C) 2002-2017 CERN for the benefit of the ATLAS collaboration
*/

#include "Wtt/CustomEventSaver.h"
#include "TopEvent/Event.h"
#include "TopEventSelectionTools/TreeManager.h"
#include "TopConfiguration/TopConfig.h"

#include <TRandom3.h>



namespace top{
  ///-- Constrcutor --///
  CustomEventSaver::CustomEventSaver() :
    m_randomNumber(0.),
    m_totleptons(0.)
  {
    branchFilters().push_back(std::bind(&getBranchStatus, std::placeholders::_1, std::placeholders::_2));    
  }
  
  ///-- initialize - done once at the start of a job before the loop over events --///
  void CustomEventSaver::initialize(std::shared_ptr<top::TopConfig> config, TFile* file, const std::vector<std::string>& extraBranches)
  {
    ///-- Let the base class do all the hard work --///
    ///-- It will setup TTrees for each systematic with a standard set of variables --///
    
    top::EventSaverFlatNtuple::initialize(config, file, extraBranches);
    m_config = config;

    std::string lep_idx="";
    ///-- Loop over the systematic TTrees and add the custom variables --///
    for (auto systematicTree : treeManagers()) {
      systematicTree->makeOutputVariable(m_randomNumber, "randomNumber");
      systematicTree->makeOutputVariable(m_totleptons,"totleptons");
      
      for(int l_idx=0;l_idx<LEPTON_ARR_SIZE;l_idx++){
	lep_idx="lep_Pt_"+std::to_string(l_idx);
	systematicTree->makeOutputVariable(lep_Pt[l_idx], lep_idx.c_str());
      }
    }
  }



  // void CustomEventSaver::CopyElectron(const xAOD::Electron& el, ttHML::Lepton& lep) {
    
  // }

  void CopyIParticle(const xAOD::IParticle& part, Lepton& lep) {
    lep.Pt = part.pt();
    lep.E = part.e();
    lep.Eta = part.eta();
    lep.Phi = part.phi();
    lep.Index = part.index();
  }


  void CustomEventSaver::CopyLeptons(const xAOD::ElectronContainer& Electrons, const xAOD::MuonContainer& Muons){
    size_t idx = 0;   
    typedef std::tuple<const TLorentzVector*, int, LepType> sorttype_t;   
    std::vector<sorttype_t> sorter;   
    const int totleptons = Electrons.size() + Muons.size(); 
    for (const auto elItr : Electrons) {
      sorter.push_back(sorttype_t(&(elItr->p4()), idx++, ELECTRON));
    }
    idx = 0;
    for (const auto muItr : Muons) {
      sorter.push_back(sorttype_t(&(muItr->p4()), idx++, MUON));
    }

    std::sort(sorter.begin(), sorter.end(), 
	      [](sorttype_t a, sorttype_t b) { return std::get<0>(a)->Pt() > std::get<0>(b)->Pt(); }); 


    memset(&m_leptons, 0, sizeof(m_leptons));
    for (short idx = 0; idx < totleptons; ++idx) {    
      const TLorentzVector* p4; int lidx; LepType typ; 
      std::tie(p4, lidx, typ) = sorter[idx];
      if (typ == ELECTRON) {
	//m_leptons[idx].pushback(*((Electrons)[lidx]));
	//CopyIParticle(*((Electrons)[lidx],m_leptons[idx]);
	CopyIParticle(*((Electrons)[lidx]), m_leptons[idx]);
      }
      else {
	CopyIParticle(*((Muons)[lidx]), m_leptons[idx]);
	//m_leptons[idx].pushback(*((Muons)[lidx]));
      }

    }

  }

  ///-- saveEvent - run for every systematic and every event --///
  void CustomEventSaver::saveEvent(const top::Event& event) 
  {
    ///-- set our variables to zero --///
    m_randomNumber = 0.;
    m_totleptons = 0.;
 

    if (m_config->saveOnlySelectedEvents() && !event.m_saveEvent){
      return;
    }
    if(!m_config->saveOnlySelectedEvents()){
      top::EventSaverFlatNtuple::saveEvent(event);
      return;
    }



    //CopyLeptons(*Electrons,*Muons);
    ///-- Fill them - you should probably do something more complicated --///
    TRandom3 random( event.m_info->eventNumber() );
    //m_randomNumber = event.m_electrons;    
    xAOD::ElectronContainer Electrons=event.m_electrons;
    xAOD::MuonContainer Muons=event.m_muons;
    m_totleptons = Electrons.size()+Muons.size();
    CopyLeptons(Electrons,Muons);
    for (size_t idx = 0; idx < LEPTON_ARR_SIZE; ++idx) {  
      lep_Pt[idx]=m_leptons[idx].Pt;
    }

    top::EventSaverFlatNtuple::saveEvent(event);
    //std::cout<<m_randomNumber << "  "  << std::endl;
    
    
    ///-- Let the base class do all the hard work --///
  }
  


  int CustomEventSaver::getBranchStatus(top::TreeManager const * treeManager, std::string const & variableName) 
  { 
    std::vector<std::string> list_of_b_to_remove = {"tjet_","ljet_","jet_","tau_","ph_","weight_trackjet","weight_tauSF","weight_indiv_SF","weight_old"}; //"el_","mu_"
    for (int i=0; i< list_of_b_to_remove.size(); i++){
      if (variableName.find(list_of_b_to_remove[i])==0  )
	return 0;
    }

    return -1;
  }
  
}
