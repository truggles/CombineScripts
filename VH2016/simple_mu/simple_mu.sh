
# For making the final combined mu values and significances

combine -M Significance workspace_cmb_125.root -t -1 --expectSignal=1
combine -M FitDiagnostics workspace_cmb_125.root -t -1 --expectSignal=1
combine -M Significance workspace_cmb_125.root
combine -M FitDiagnostics workspace_cmb_125.root --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --robustFit=1 --rMax=4. --rMin=1.1
