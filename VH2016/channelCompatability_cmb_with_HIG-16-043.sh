

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=.*/WH_htt:r_WH[1,-100,100]' \
    --PO 'map=.*/ZH_htt:r_ZH[1,-20,20]' \
    --PO 'map=.*/ggH_htt:r_ggH[1,-5,5]' \
    --PO 'map=.*/qqH_htt:r_qqH[1,-2,5]' \
    big_cmb_125.txt -o workspace_signal_breakdown.root -m 125
#
#
## Run for each signal
#for SIGNAL in r_WH r_ZH r_qqH r_ggH; do
#    echo ""
#    echo "group: Channel " ${SIGNAL}
#    #combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --robustFit=1 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _MuBlind${SIGNAL} -t -1 --expectSignal=1
#    combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL}
#done

SIGNAL=r_WH
combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL} --setParameterRanges r_WH=1.0,6.0
SIGNAL=r_ZH
combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL} --setParameterRanges r_ZH=-1.0,4.0
SIGNAL=r_qqH
combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL} --setParameterRanges r_qqH=0.2,5.0:r_WH=-20,30
SIGNAL=r_ggH
combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1,r_qqH=1,r_ggH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL} --setParameterRanges r_ggH=0.5,1.8:r_qqH=0.2,5.0:r_WH=-20,30 --setRobustFitTolerance=0.5


SIGNAL=r_cmb
CMB=big_cmb
#combine -M FitDiagnostics workspace_${CMB}_125.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --rMin=0.5 --rMax=5 --robustFit=1 -n _MuBlind${SIGNAL} -t -1 --expectSignal=1
combine -M FitDiagnostics workspace_${CMB}_125.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --rMin=0.5 --rMax=5 --robustFit=1 -n _Mu${SIGNAL}
