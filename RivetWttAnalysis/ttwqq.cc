#include "Rivet/Analysis.hh"
#include "Rivet/Projections/FinalState.hh"
#include "Rivet/Projections/TauFinder.hh"
#include "Rivet/Projections/HeavyHadrons.hh"
#include "Rivet/Projections/VetoedFinalState.hh"
#include "Rivet/Projections/ChargedLeptons.hh"
#include "Rivet/Projections/PromptFinalState.hh"
#include "Rivet/Projections/ChargedFinalState.hh"
#include "Rivet/Projections/MissingMomentum.hh"
#include "Rivet/Projections/IdentifiedFinalState.hh"
//#include "Rivet/Projections/UnstableFinalState.hh"
#include "Rivet/Projections/UnstableParticles.hh"
#include "Rivet/Projections/DressedLeptons.hh"
#include "Rivet/Projections/FastJets.hh"
#include "Rivet/Projections/WFinder.hh"
#include "Rivet/AnalysisLoader.hh"

#include <numeric>
#include <functional>

/* 
 *
 * Author : Kirill Grevtsov (kirill.grevtsov@cern.ch)
 *
 *
 */

namespace Rivet {
  
  
  class ttwqq: public Analysis {
    
  public:
    
    /// Minimal constructor
    ttwqq() : Analysis("ttwqq")
    {
    }
    
    /// Set up projections and book histograms
    void init() {
      FinalState lepfs;

      Cut lep_cuts = (Cuts::abseta < 2.5) && (Cuts::pT > 20*GeV); //increasing cut of the lepton

      // Get photons to dress leptons
      IdentifiedFinalState all_photons(lepfs);
      all_photons.acceptIdPair(PID::PHOTON);  
      IdentifiedFinalState ph_id(lepfs);
      ph_id.acceptIdPair(PID::PHOTON);
      PromptFinalState photons(ph_id);
      photons.acceptTauDecays(false);
      addProjection(photons, "photons");


      //Projection to find prompt electrons
      IdentifiedFinalState el_id(lepfs);
      el_id.acceptIdPair(PID::ELECTRON);

      PromptFinalState electrons(el_id);
      electrons.acceptTauDecays(true);
      addProjection(electrons,"electrons");

      // Switching to new definition with the last boolean considered deprecated
      DressedLeptons dressedelectrons(photons, electrons, 0.1, lep_cuts, true);
      addProjection(dressedelectrons, "dressedelectrons");

      //Projection to find prompt muons
      IdentifiedFinalState mu_id(lepfs);
      mu_id.acceptIdPair(PID::MUON);
      PromptFinalState muons(mu_id);
      muons.acceptTauDecays(true);
      addProjection(muons,"muons");

      DressedLeptons dressedmuons(photons, muons, 0.1, lep_cuts, true);
      addProjection(dressedmuons, "dressedmuons");

        
      TauFinder tauhadronic(TauFinder::HADRONIC);
      addProjection(tauhadronic,"TauHadronic");

      FinalState fs_neutrino(Cuts::abseta < 2.5);
      // Projection to find neutrinos and produce MET
      IdentifiedFinalState nu_id(fs_neutrino);
      nu_id.acceptNeutrinos();
      addProjection(nu_id, "neutrinos");
      PromptFinalState neutrinos(nu_id);
      neutrinos.acceptTauDecays(true);

      // Jet clustering.
      VetoedFinalState vfs(lepfs);
      vfs.addVetoOnThisFinalState(dressedelectrons);
      vfs.addVetoOnThisFinalState(dressedmuons);
      vfs.addVetoOnThisFinalState(neutrinos);
      //baseline definition
      FastJets jets(vfs, FastJets::ANTIKT, 0.4); 
      jets.useInvisibles(true);

      //tt l+jet definition
      //https://rivet.hepforge.org/analyses/ATLAS_2018_I1656578.html does not work with latest rivet
      //FastJets jets(vfs, FastJets::ANTIKT, 0.4, JetAlg::Muons::ALL, JetAlg::Invisibles::DECAY);

      addProjection(jets, "Jets");


      addProjection(HeavyHadrons(Cuts::abseta < 5 && Cuts::pT > 5*GeV), "BCHadrons");
      //addProjection(FastJets(FinalState(-2.5,2.5,25*GeV),FastJets::ANTIKT,0.4),"Jets");
      addProjection(MissingMomentum(FinalState(-5,5,0*GeV)),"MissingET");

      
      ht_bins ={0,120,180,240,300,360,440,540,680,900,1500};
      ht_j_bins={0,90,140,180,240,300,380,460,540,650,850,1500};
      ht_l_bins={0,20,50,80,110,150,200,300,400,550,800}; 
      met_bins={0,20,50,80,120,180,300,500,1200}; 
      lep_bins={0,20,25,33,45,60,80,110,160,500}; 
      jet_bins={0,20,25,33,45,60,80,110,200}; 
      bjet_bins={0,20,25,33,45,60,80,110,150,200,300,500}; 


      //presel, two light-leptons , same sign  ,lepton0 pT, geq1b,geq3jet,regions
      //vector<string> s_cutDescs =  {  "Preselections","Nleps","SS","lepPt0>25","1b","3j",
      //			      "0t 1b 4j", "0t 2b 4j","0t 1b 3j", "0t 2b 3j","1t >1b >3j"};
      vector<string> s_cutDescs =  {   "presel","2L","OS","pt0>27","pt1>27","geq2b", "geq4jet", "found W->qq",
				       "0t 1b 4j", "0t 2b 4j","0t 1b 3j", "0t 2b 3j","1t >1b >3j"};

      int Ncuts = s_cutDescs.size();
      h_cutflow_2l[0] = bookHisto1D("cf2l",Ncuts,0,Ncuts );
      h_cutflow_2l[1] = bookHisto1D("cf2l_raw",Ncuts,0,Ncuts);
      

      vector<int> lep_bins_v={0,20,25,33,45,60,80,110,160,500};
      vector<string> region_names={"0t 1b 4j", "0t 2b 4j","0t 1b 3j", "0t 2b 3j","1t 1b 3j"};
      
      for(int i=0; i<(int)region_names.size();i++){
	_h_hist_Whmass[i] = bookHisto1D(("Whmass_"+to_string(i)).c_str(), 100, 60, 100);
	_h_hist_nJets[i] = bookHisto1D(("nJets_"+to_string(i)).c_str(), 7, 2.5, 9.5);
	_h_hist_lep_Pt_0[i] = bookHisto1D(("lep_Pt_0_"+to_string(i)).c_str(),{0,20,25,33,45,60,80,110,160,500});
	_h_hist_lep_Pt_1[i] = bookHisto1D(("lep_Pt_1_"+to_string(i)).c_str(), lep_bins);
	_h_hist_DRll01[i] = bookHisto1D(("DRll01_"+to_string(i)).c_str(), dr_bins, 0., dr_max);
	//jets:
	_h_hist_jet_Pt_1[i] = bookHisto1D(("jet_Pt_1_"+to_string(i)).c_str(), jet_bins);
	_h_hist_jet_Pt_2[i] = bookHisto1D(("jet_Pt_2_"+to_string(i)).c_str(), jet_bins);
	_h_hist_jet_Pt_3[i] = bookHisto1D(("jet_Pt_3_"+to_string(i)).c_str(), jet_bins);
	_h_hist_jet_Pt_4[i] = bookHisto1D(("jet_Pt_4_"+to_string(i)).c_str(), jet_bins);
	_h_hist_jet_Pt_5[i] = bookHisto1D(("jet_Pt_5_"+to_string(i)).c_str(), jet_bins);
	_h_hist_jet_Pt_6[i] = bookHisto1D(("jet_Pt_6_"+to_string(i)).c_str(), jet_bins);
	//bjets
	_h_hist_Bjet_Pt_0[i] = bookHisto1D(("Bjet_Pt_0_"+to_string(i)).c_str(),bjet_bins);
	_h_hist_Bjet_Pt_1[i] = bookHisto1D(("Bjet_Pt_1_"+to_string(i)).c_str(), jet_bins);
	
	_h_hist_min_DRl0j[i] = bookHisto1D(("min_DRl0j_"+to_string(i)).c_str(), dr_bins, 0., dr_max);
	_h_hist_min_DRl1j[i] = bookHisto1D(("min_DRl1j_"+to_string(i)).c_str(), dr_bins, 0., dr_max);
	_h_hist_maxEta_ll[i] = bookHisto1D(("maxEta_ll_"+to_string(i)).c_str(), 13, 0, 2.6); // maxEta = max( fabs( lep_Eta_0 ), fabs( lep_Eta_1 ) );
	_h_hist_HT_jets[i] = bookHisto1D(("HT_jets_"+to_string(i)).c_str(), ht_j_bins);
	_h_hist_HT_leps[i] = bookHisto1D(("HT_leps_"+to_string(i)).c_str(), ht_l_bins);
	_h_hist_HT[i] = bookHisto1D(("HT_"+to_string(i)).c_str(),ht_bins);// 100, 0., 1000.
	_h_hist_nBtagJets[i] = bookHisto1D(("nBtagJets_"+to_string(i)).c_str(), 3, 0.5, 3.5);
	_h_hist_MET[i] = bookHisto1D(("MET_"+to_string(i)).c_str(),met_bins);//100, 0., 1000.
	//
	_h_hist_lep_Eta_0[i] = bookHisto1D(("lep_Eta_0_"+to_string(i)).c_str(), 13, -2.6, 2.6);
	_h_hist_lep_Eta_1[i] = bookHisto1D(("lep_Eta_1_"+to_string(i)).c_str(),13, -2.6, 2.6);
	_h_hist_lep_Phi_0[i] = bookHisto1D(("lep_Phi_0_"+to_string(i)).c_str(),16, -3.2, 3.2);
	_h_hist_lep_Phi_1[i] = bookHisto1D(("lep_Phi_1_"+to_string(i)).c_str(),16, -3.2, 3.2);

	_h_hist_lep_dPhi[i] = bookHisto1D(("lep_dPhi_"+to_string(i)).c_str(),  16, 0, 6.4);
	
      }
      
      
    }

    
    void analyze(const Event& event) {
      const double weight = event.weight();


      
      const MissingMomentum& met = applyProjection<MissingMomentum>(event, "MissingET");
      const double event_met	 = met.vectorEt().mod();

      //Jets alljets;
      Jets alljets = applyProjection<FastJets>(event, "Jets").jetsByPt(Cuts::pT > 25*GeV && Cuts::abseta < 2.5);
      alljets    =   sortByPt(alljets);
      
      Particles tauVec,lepVec;
      bool orl_lf=false;
      foreach (const Particle & el, applyProjection<DressedLeptons>(event,"dressedelectrons").particlesByPt(Cuts::pT > 20*GeV && Cuts::abseta < 2.5)){
	orl_lf=false;
	foreach (const Jet& jet, alljets){
	  if( fabs(deltaR(jet,el))<0.4 ) orl_lf=true; 
	}
	
	if(!orl_lf) lepVec.push_back(el);
      }
      
      foreach (const Particle &mu, applyProjection<DressedLeptons>(event,"dressedmuons").particlesByPt(Cuts::pT > 20*GeV && Cuts::abseta < 2.5)){
	orl_lf=false;
	foreach (const Jet& jet, alljets){
	  if( fabs(deltaR(jet,mu))<0.4 ) orl_lf=true; 
	}
	
	if(!orl_lf) lepVec.push_back(mu);
	
      }
      
      const TauFinder &tauhad = applyProjection<TauFinder>(event,"TauHadronic");
      foreach (const Particle &tau, tauhad.taus()){
	if(tau.pT()>25*GeV && fabs(tau.eta()) < 2.5 ){
	  int nProng = 0;
	  foreach (Particle p , tau.children()){
	    if (p.threeCharge()!=0) nProng++;
	  }
	  if(nProng ==1 || nProng ==3){
	    tauVec.push_back(tau);
	  }
	}
      }
      
      tauVec= sortByPt(tauVec);
      lepVec= sortByPt(lepVec);
      
      int nLep = lepVec.size();

      double ht_jet = 0.0;
      double ht_lep = 0.0;
      foreach (const Jet& j, alljets) { ht_jet += j.pT(); }      
      foreach (const Particle & part, lepVec) { ht_lep += part.pT(); }

      double ht = ht_jet+ht_lep;

      /* Identify b-jets */
      const Particles bhadrons = sortByPt(applyProjection<HeavyHadrons>(event, "BCHadrons").bHadrons());
    
      Jets bjets, ljets;
      foreach (const Jet& jet, alljets) {
	if(jet.bTagged())   bjets.push_back(jet);	
	else ljets.push_back(jet);
	
      }
      
      bjets      =   sortByPt(bjets);
      ljets      =   sortByPt(ljets);
      
      int Njets=0;       int Nbjets=0;      int Nhtaus=0;
      Njets = alljets.size();
      Nbjets= bjets.size();
      Nhtaus= tauVec.size();

      float max_eta=999;
      if(nLep>1)
	max_eta=  max ( fabs( lepVec.at(0).eta() ), fabs( lepVec.at(1).eta() ) );

      float min_lj_deltaR=100; float min_l0j_deltaR=100;   float min_l1j_deltaR=100;
      foreach (const Jet& jet, alljets){
	if(nLep>0)
	  if(min_l0j_deltaR > fabs(deltaR(jet,lepVec.at(0)) ) ) {min_l0j_deltaR = fabs(deltaR(jet,lepVec.at(0))); }
	
	if(nLep>1)
	  if(min_l1j_deltaR > fabs(deltaR(jet,lepVec.at(1)))) {min_l1j_deltaR = fabs(deltaR(jet,lepVec.at(1))); }
	
	foreach (const Particle & part, lepVec){
	  if(min_lj_deltaR > fabs(deltaR(jet,part))) {min_lj_deltaR = fabs(deltaR(jet,part)); }
	}
      }
      

      bool sel_array[10];
      vector<string> region_names={"0t 1b 4j", "0t 2b 4j","0t 1b 3j", "0t 2b 3j","1t 1b 3j"};
      
      int cf_counter =0;
      
      //presel
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;
      
      //two light-leptons
      if(nLep!=2) vetoEvent;
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;	  

      //opposite sign 
      if(lepVec.at(0).charge()+lepVec.at(1).charge() !=0) vetoEvent;
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;
       
      //lepton pT 
      if( lepVec.at(0).pT()/GeV <27 ) vetoEvent;      
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;

      //lepton sublead pT 
      if( lepVec.at(1).pT()/GeV <27 ) vetoEvent;      
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;
      
      
      //geq2b
      if( Nbjets < 2 ) vetoEvent;
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;

      //geq4jet 
      if( Njets < 4) vetoEvent;
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;
      
      //Wqq finder:
      // for(int i=0; i<Njets;i++){
      // 	for(int j=0; j<Njets;j++){
      // 	  if(i!=j){
      // 	    alljets.at(i)
      // 	  }
      // 	}
      // }

      double bestWmass = 1000.0*TeV;
      double mWPDG = 80.399*GeV;
      int Wj1index = -1, Wj2index = -1;
      bool found_w=false;
      for (unsigned int i = 0; i < (ljets.size() - 1); ++i) {
        for (unsigned int j = i + 1; j < ljets.size(); ++j) {
          double wmass = (ljets[i].momentum() + ljets[j].momentum()).mass();
          if (fabs(wmass - mWPDG) < fabs(bestWmass - mWPDG)) {
            bestWmass = wmass;
            Wj1index = i;
            Wj2index = j;
	    found_w=true;
          }
        }
      }

      // found W->qq
      if (found_w==false) vetoEvent;
      h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
      cf_counter++;
      
      
      FourMomentum pjet1 = ljets[Wj1index].momentum();
      FourMomentum pjet2 = ljets[Wj2index].momentum();
      // compute hadronic W boson
      FourMomentum pWhadron = pjet1 + pjet2;
      

      sel_array[0]=(Nhtaus == 0 && Nbjets >= 2 && Njets >= 4 );  // Region 1
      
      
      for(int i=0; i<(int)region_names.size();i++){
	if(sel_array[i]){ 
	  
	  h_cutflow_2l[0]->fill(cf_counter,weight);  h_cutflow_2l[1]->fill(cf_counter,1);
	  cf_counter++;
		      
	  _h_hist_Whmass[i]->fill(pWhadron.mass()/GeV,weight);

	  _h_hist_nJets[i]->fill(Njets,weight);
	  _h_hist_nBtagJets[i]->fill(Nbjets,weight);
	  _h_hist_lep_Pt_0[i]->fill(lepVec.at(0).pT()/GeV,weight);
	  _h_hist_lep_Pt_1[i]->fill(lepVec.at(1).pT()/GeV,weight);

	  _h_hist_HT[i]->fill(ht,weight);
	  _h_hist_HT_jets[i]->fill(ht_jet,weight);
	  _h_hist_HT_leps[i]->fill(ht_lep,weight);

	  _h_hist_jet_Pt_1[i]->fill(alljets.at(0).pT()/GeV,weight);
	  _h_hist_jet_Pt_2[i]->fill(alljets.at(1).pT()/GeV,weight);
	  _h_hist_jet_Pt_3[i]->fill(alljets.at(2).pT()/GeV,weight);
	  if( Njets>3) _h_hist_jet_Pt_4[i]->fill(alljets.at(3).pT()/GeV,weight);
	  if( Njets>4) _h_hist_jet_Pt_5[i]->fill(alljets.at(4).pT()/GeV,weight);
	  if( Njets>5) _h_hist_jet_Pt_6[i]->fill(alljets.at(5).pT()/GeV,weight);

	  _h_hist_Bjet_Pt_0[i]->fill(bjets.at(0).pT()/GeV,weight);
	  if( Nbjets>1)_h_hist_Bjet_Pt_1[i]->fill(bjets.at(1).pT()/GeV,weight);
		     
	  _h_hist_min_DRl0j[i]->fill(min_l0j_deltaR,weight);
	  _h_hist_min_DRl1j[i]->fill(min_l1j_deltaR,weight);
	  _h_hist_DRll01[i]->fill(fabs(deltaR(lepVec.at(0),lepVec.at(1))),weight);

	  _h_hist_MET[i]->fill(event_met/GeV,weight);
	  _h_hist_maxEta_ll[i]->fill(max_eta,weight);
	  //https://rivet.hepforge.org/code/2.4.0/a00431.html#a20b7db1dfdcaeedded0f6a81c24ba6ab
	  // phi: [0,2pi]
	  // in atlas phi: [-pi,pi]
	  //apply 1pi shift 
	  _h_hist_lep_dPhi[i]->fill( lepVec.at(0).phi()-lepVec.at(1).phi(),weight);
	  _h_hist_lep_Phi_0[i]->fill(lepVec.at(0).phi()-pi,weight);
	  _h_hist_lep_Phi_1[i]->fill(lepVec.at(1).phi()-pi,weight);
	  _h_hist_lep_Eta_0[i]->fill(lepVec.at(0).eta(),weight);
	  _h_hist_lep_Eta_1[i]->fill(lepVec.at(1).eta(),weight);
		    
	}//region selection		
      } //region loop
    } //analyze loop
    
    void finalize() {
	//MSG_INFO("CROSS SSECTION:"<<crossSection());
	//MSG_INFO("Sum of weights:"<<sumOfWeights());
      
      }
  
    //@}



  private:
    
    // @name Histogram data members
    //@{
    //
    Histo1DPtr h_cutflow_2l[2];
    Histo1DPtr _h_hist_Whmass[10]; 

    Histo1DPtr _h_hist_DRll01[10];
    Histo1DPtr _h_hist_jet_Pt_1[10];
    Histo1DPtr _h_hist_jet_Pt_2[10];
    Histo1DPtr _h_hist_jet_Pt_3[10];
    Histo1DPtr _h_hist_jet_Pt_4[10];
    Histo1DPtr _h_hist_jet_Pt_5[10];
    Histo1DPtr _h_hist_jet_Pt_6[10];
    Histo1DPtr _h_hist_Bjet_Pt_0[10];
    Histo1DPtr _h_hist_Bjet_Pt_1[10];
    Histo1DPtr _h_hist_lep_Pt_0[10];
    Histo1DPtr _h_hist_lep_Pt_1[10];
    Histo1DPtr _h_hist_min_DRl0j[10];
    Histo1DPtr _h_hist_min_DRl1j[10];
    Histo1DPtr _h_hist_maxEta_ll[10];
    Histo1DPtr _h_hist_HT_jets[10];
    Histo1DPtr _h_hist_HT_leps[10];
    Histo1DPtr _h_hist_HT[10];
    Histo1DPtr _h_hist_nJets[10]; 
    Histo1DPtr _h_hist_nBtagJets[10];
    Histo1DPtr _h_hist_MET[10];
    Histo1DPtr _h_hist_lep_Eta_0[10];
    Histo1DPtr _h_hist_lep_Eta_1[10];
    Histo1DPtr _h_hist_lep_Phi_0[10];
    Histo1DPtr _h_hist_lep_Phi_1[10];
    Histo1DPtr _h_hist_lep_dPhi[10];






    vector<double> lep_bins;
    vector<double> ht_bins;
    vector<double> ht_j_bins;
    vector<double> ht_l_bins;
    vector<double> met_bins;
    vector<double> bjet_bins;
    vector<double> jet_bins;
    float dr_max=4.8; int dr_bins=12;
    //@}

  };



  // The hook for the plugin system
  DECLARE_RIVET_PLUGIN(ttwqq);
}
