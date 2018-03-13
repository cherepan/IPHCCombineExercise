# IPHCCombineExercise



Run ./todo.pl for an instruction. This simple installer only checksout and compile CombineHarvester base so far. More comes later...

Create a working directory

Use the histo_datacard.C script to extract some histograms from a root file and rename its. Note that data histograms has to be named data_obs. Put this new root file in your working directory

Now you have to create a datacard.
You can use an example code called "Example.cpp" located in CombineHarvester/CombineTools/bin/. Comments in this file will help you to understand. You need to add a line to CombineHarvester/CombineTools/bin/BuildFile.xml. You can now launch "Example" in your working directory.
Please have a look at the other files in the directory of Example.cpp or at this link to have more examples: http://cms-analysis.github.io/CombineHarvester/index.html 

You have to compile with "scram b" before next steps.

Now you can go back to your working directory and write: YourDataCard.

A new DataCard is created.
Please for next commands, use "--help" in order to know all available options.
Then you have to build the workspaces: combineTool.py -M T2W -i . -o workspace.root

Next you have to run the MaxLikelihoodFit: combine -M FitDiagnostics workspace.root --robustFit=1  --rMin 0.5 --rMax 1.5

Finally create postfit plots: PostFitShapes -o postfit_shapes.root -f fitDiagnostics.root:fit_s --postfit --sampling --print -d combined.txt.cmb

