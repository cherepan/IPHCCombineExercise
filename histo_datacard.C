void histo_datacard(){

TFile* inputfile = new TFile("LOCAL_COMBINED_ztautau_default_LumiScaled.root","READ");
TFile* outputfile=new TFile("ztautau_datacard.root","RECREATE");

TH1D* data= (TH1D*)inputfile->Get("ztautau_default_TauTauMassData");
TH1D* ztautau= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_DY_tautau");
TH1D* zmumuee= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_DY_eemumu");
TH1D* QCD= (TH1D*)inputfile->Get("ztautau_default_TauTauMassQCD");
TH1D* Wlnu= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_W_lnu");
TH1D* WW2l2nu= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_WW_2l2nu");
TH1D* ZZ2l2nu= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_ZZ_2l2nu");
TH1D* ZZ2l2q= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_ZZ_2l2q");
TH1D* ZZ4l= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_ZZ_4l");
TH1D* WZ= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_WZ");
TH1D* ttbar= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_ttbar");
TH1D* stop= (TH1D*)inputfile->Get("ztautau_default_TauTauMassMC_stop");

data->SetName("data_obs");
ztautau->SetName("ztautau");
zmumuee->SetName("zmumuee");
QCD->SetName("QCD");
Wlnu->SetName("Wlnu");
WW2l2nu->SetName("WW2l2nu");
ZZ2l2nu->SetName("ZZ2l2nu");
ZZ2l2q->SetName("ZZ2l2q");
ZZ4l->SetName("ZZ4l");
WZ->SetName("WZ");
ttbar->SetName("ttbar");
stop->SetName("stop");

data->Write();
ztautau->Write();
zmumuee->Write();
QCD->Write();
Wlnu->Write();
WW2l2nu->Write();
ZZ2l2nu->Write();
ZZ2l2q->Write();
ZZ4l->Write();
WZ->Write();
ttbar->Write();
stop->Write();

outputfile->Close();
}
