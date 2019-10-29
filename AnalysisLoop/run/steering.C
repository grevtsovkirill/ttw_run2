void steering(string dsid="413008", string comp="a", string jet_alg="PF"){

  TChain *ch=new TChain("nominal");
  string path="../../../Files/pflow_tests/"+dsid+comp+jet_alg+".root";;
  cout << "path = " << path<< endl;

  ch->Add(path.c_str());
  cout << ch->GetNtrees()<< ", entr: "<< ch->GetEntries()<< endl;
  string  option="_"+dsid+"-"+comp; //to_string(sum_w)

  ch->Process("../source/TtWSelector.C+",option.c_str());

}
