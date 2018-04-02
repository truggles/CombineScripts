DIR=/afs/cern.ch/work/t/truggles/Z_to_tautau/newCombine81X/CMSSW_8_1_0/src/CombineHarvester/ZH2016/output/mar29_for81X_rmBBB2xxx


for SIGNAL in r_eeem r_eeet r_eemt r_eett r_emmt r_mmmt r_mmtt r_emmm r_emt r_ett r_mmt r_mtt r_WH r_ZH r_cmb; do
    combineTool.py -M CollectLimits ${DIR}/higgsCombine_Mu${SIGNAL}.FitDiagnostics.mH125.root -o Mu_${SIGNAL}.json
    combineTool.py -M CollectLimits ${DIR}/higgsCombine_MuBlind${SIGNAL}.FitDiagnostics.mH125.root -o Mu_${SIGNAL}_blind.json
done

python ../../scripts/muValuePlotter.py -t "VH_signal" --blind -o "VH_signal_blind"
python ../../scripts/muValuePlotter.py -t "VH_signal" -o "VH_signal"


python ../../scripts/muValuePlotter.py -t "VH_channel" --blind -o "VH_channel_blind"
python ../../scripts/muValuePlotter.py -t "VH_channel" -o "VH_channel"
