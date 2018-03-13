#include <string>
#include <map>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
#include <cstdlib>
#include "CombineHarvester/CombineTools/interface/CombineHarvester.h"
#include "CombineHarvester/CombineTools/interface/Observation.h"
#include "CombineHarvester/CombineTools/interface/Process.h"
#include "CombineHarvester/CombineTools/interface/Utilities.h"
#include "CombineHarvester/CombineTools/interface/Systematics.h"
#include "CombineHarvester/CombineTools/interface/BinByBin.h"

using namespace std;

int main() {
  // input files directory
  string input = "/home-pbs/gbourgat/cmssw/IPHCCombineExercise/CMSSW_8_1_0/src/Test/";

  // Create an empty CombineHarvester instance that will hold all of the
  // datacard configuration and histograms etc.
  ch::CombineHarvester cb;

  // Uncomment this next line to see a *lot* of debug information
  // cb.SetVerbosity(3);

  // Categories
  // Each entry in the vector below specifies a bin name and corresponding bin_id.
  ch::Categories cats = {
      {1, "zerojet"}
    };
  // ch::Categories is just a typedef of vector<pair<int, string>>
 
  //Data
  //Respectively the mass, analysis, dataset, channel and categories
  cb.AddObservations({"*"}, {"ztt"}, {"13TeV"}, {"tautau"}, cats);
 
  //Background
  //false if background, true if signal
  vector<string> bkg_procs = {"Wlnu", "WW2l2nu", "ZZ2l2nu", "ZZ2l2q","ZZ4l","WZ","ttbar","stop","zmumuee","QCD"};
  cb.AddProcesses({"*"}, {"ztt"}, {"13TeV"}, {"tautau"}, bkg_procs, cats, false);

  //Signal
  vector<string> sig_procs = {"ztautau"};
  cb.AddProcesses({"*"}, {"ztt"}, {"13TeV"}, {"tautau"}, sig_procs, cats, true);
  
  using ch::syst::SystMap;
 
  //Add a simple systematic to signal
  cb.cp().signals()
    .AddSyst(cb, "DummySyst1", "lnN", SystMap<>::init(1.17));

 cb.cp().backgrounds()
    .AddSyst(cb, "DummySyst2", "lnN", SystMap<>::init(1.25));

  //Write the path of root file and histograms names
  cb.cp().backgrounds().ExtractShapes(
      input + "ztautau_datacard.root",
      "$PROCESS",
      "");
  cb.cp().signals().ExtractShapes(
      input + "ztautau_datacard.root",
      "$PROCESS",
      "");


  // We create the output root file that will contain all the shapes.
  TFile output("Test.root", "RECREATE");
  cb.cp().WriteDatacard("Datacard.txt", output);

}
