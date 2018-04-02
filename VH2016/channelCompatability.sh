

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=ch.*/WH_htt:r_WH[1,-5,20]' \
    --PO 'map=ch.*/ZH_htt:r_ZH[1,-5,20]' \
    cmb_125.txt -o workspace_signal_breakdown.root -m 125


text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=ch1/.*_htt:r_eeem[1,-5,30]' \
    --PO 'map=ch2/.*_htt:r_eeet[1,-20,20]' \
    --PO 'map=ch3/.*_htt:r_eemt[1,-20,20]' \
    --PO 'map=ch4/.*_htt:r_eett[1,-20,10]' \
    --PO 'map=ch5/.*_htt:r_emmm[1,-20,20]' \
    --PO 'map=ch6/.*_htt:r_emmt[1,-20,20]' \
    --PO 'map=ch7/.*_htt:r_mmmt[1,-20,20]' \
    --PO 'map=ch8/.*_htt:r_mmtt[1,-20,20]' \
    --PO 'map=ch9/.*_htt:r_emt[1,-20,20]' \
    --PO 'map=ch10/.*_htt:r_ett[1,-20,20]' \
    --PO 'map=ch11/.*_htt:r_mmt[1,-20,20]' \
    --PO 'map=ch12/.*_htt:r_mtt[1,-20,20]' \
    cmb_125.txt -o workspace_channel_breakdown.root -m 125


## Run for each signal
for SIGNAL in r_WH r_ZH; do
    echo ""
    echo "group: Channel " ${SIGNAL}
    combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --robustFit=1 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1 --redefineSignalPOIs ${SIGNAL} -n _MuBlind${SIGNAL} -t -1 --expectSignal=1
    combine -M FitDiagnostics workspace_signal_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_WH=1,r_ZH=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL}
done


# Run for each channel
for SIGNAL in r_eeem r_eeet r_eemt r_eett r_emmt r_mmmt r_mmtt r_emmm r_emt r_ett r_mmt r_mtt; do
    echo ""
    echo "group: Channel " ${SIGNAL}
    combine -M FitDiagnostics workspace_channel_breakdown.root -m 125 --robustFit=1 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_eeem=1,r_eeet=1,r_eemt=1,r_eett=1,r_emmt=1,r_mmmt=1,r_mmtt=1,r_emmm=1,r_emt=1,r_ett=1,r_mmt=1,r_mtt=1 --redefineSignalPOIs ${SIGNAL} -n _MuBlind${SIGNAL} -t -1 --expectSignal=1
    combine -M FitDiagnostics workspace_channel_breakdown.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND --setParameters r_eeem=1,r_eeet=1,r_eemt=1,r_eett=1,r_emmt=1,r_mmmt=1,r_mmtt=1,r_emmm=1,r_emt=1,r_ett=1,r_mmt=1,r_mtt=1 --redefineSignalPOIs ${SIGNAL} -n _Mu${SIGNAL}
done

SIGNAL=r_cmb
combine -M FitDiagnostics workspace_cmb_125.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND -n _MuBlind${SIGNAL} -t -1 --expectSignal=1
combine -M FitDiagnostics workspace_cmb_125.root -m 125 --X-rtd FITTER_NEW_CROSSING_ALGO --X-rtd FITTER_NEVER_GIVE_UP --X-rtd FITTER_BOUND -n _Mu${SIGNAL} --rMin=-5


