# IPHCCombineExercise

./todo.pl --setup <workdir>
Then source the Installer file

Create a working directory

Use the histo_datacard.C script to extract some histograms from a root file and rename its. Note that data histograms has to be named data_obs. Put this new root file in your working directory

Now create a datacard with for example CombineHarvester/CombineTools/bin/Example2.cpp.
Comments in this file will help you to understand.
Please have a look at this link to have more examples: http://cms-analysis.github.io/CombineHarvester/index.html.
If you create a new code file for DataCard, you have to add a line to the file /CombineHarvester/CombineTools/bin/BuildFile.xml: <bin file="YourDataCard.cpp" name="YourDatacard"></bin>

You have to compile with "scram b" before next steps.

Now you can go back to your working directory and write: YourDataCard.

A new DataCard is created.
Please for next commands, use "--help" in order to know all available options.
Then you have to build the workspaces: combineTool.py -M T2W -i . -o workspace.root

Next you have to run the MaxLikelihoodFit: combine -M FitDiagnostics workspace.root --robustFit=1  --rMin 0.5 --rMax 1.5

Finally create postfit plots: PostFitShapes -o postfit_shapes.root -f fitDiagnostics.root:fit_s --postfit --sampling --print -d combined.txt.cmb
