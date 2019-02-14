
#### Standard Work Flow
### creating datacards
newFolder=mar16_for81X
#MorphingVH2016 --output_folder=${newFolder} --postfix="_new" --input_folder="TEST"
### Building the workspaces:
#cd output/${newFolder}
#
#combineTool.py -M T2W -i {cmb,eeet,eemt,eeem,eett,emmt,mmmt,emmm,mmtt,emt,ett,mmt,mtt}/* -o workspace.root --parallel 16
#combineTool.py -M T2W -i cmb/125/htt_*.txt -o workspace.root --parallel 8

ALGO=KS
#ALGO=saturated
ALGO=AD

echo "Adding autoMCStats"
#for MASS in 110 120 125 130 140; do
for MASS in 125; do
    for CHAN in eeet eemt; do # eeem eett emmt mmmt emmm mmtt emt ett mmt mtt; do
        #echo "* autoMCStats 0" >> ${CHAN}/${MASS}/htt_${CHAN}_1_13TeV.txt
        #text2workspace.py ${CHAN}/${MASS}/htt_*_*_13TeV.txt -m ${MASS}  -o workspace_${CHAN}_${MASS}.root
        combine -M GoodnessOfFit workspace_${CHAN}_${MASS}.root --algo ${ALGO} -n .${ALGO}_${CHAN}
        for SEED in 123456 234567 345678 456789 567890; do
            combine -M GoodnessOfFit workspace_${CHAN}_${MASS}.root --algo ${ALGO} -t 100 -s ${SEED} -n .${ALGO}_${CHAN} &
        done
        sleep 20
        echo "Slept 120 seconds"
    done
done

#### Combine Channels Properly
#for MASS in 110 120 125 130 140; do
#    combineCards.py eeet/${MASS}/htt_*_*_13TeV.txt emmt/${MASS}/htt_*_*_13TeV.txt > llet_${MASS}.txt
#    combineCards.py eemt/${MASS}/htt_*_*_13TeV.txt mmmt/${MASS}/htt_*_*_13TeV.txt > llmt_${MASS}.txt
#    combineCards.py eeem/${MASS}/htt_*_*_13TeV.txt emmm/${MASS}/htt_*_*_13TeV.txt > llem_${MASS}.txt
#    combineCards.py eett/${MASS}/htt_*_*_13TeV.txt mmtt/${MASS}/htt_*_*_13TeV.txt > lltt_${MASS}.txt
#    combineCards.py emt/${MASS}/htt_*_*_13TeV.txt mmt/${MASS}/htt_*_*_13TeV.txt > whLep_${MASS}.txt
#    combineCards.py ett/${MASS}/htt_*_*_13TeV.txt mtt/${MASS}/htt_*_1_13TeV.txt > whHad_${MASS}.txt
#    combineCards.py ????/${MASS}/htt_*_*_13TeV.txt > zh_${MASS}.txt
#    combineCards.py ??t/${MASS}/htt_*_*_13TeV.txt > wh_${MASS}.txt
#    combineCards.py ????/${MASS}/htt_*_*_13TeV.txt ??t/${MASS}/htt_*_*_13TeV.txt > cmb_${MASS}.txt
#
#
#    for CHAN in llet llmt llem lltt whLep whHad zh wh cmb; do
#    #for CHAN in zh wh cmb; do
#        echo ""
#        echo ${MASS} ${CHAN}
#        ### Text2Workspace
#        text2workspace.py ${CHAN}_${MASS}.txt -m ${MASS}  -o workspace_${CHAN}_${MASS}.root
#        combine -M Asymptotic workspace_${CHAN}_${MASS}.root -m ${MASS} -t -1 -n .limit.${CHAN}
#        #combineTool.py -M CollectLimits higgsCombine.limit.${CHAN}.Asymptotic.mH125.root -o limits_${CHAN}.json
#    done
#done

#for CHAN in llet llmt llem lltt whLep whHad zh wh cmb; do
#    echo ""
#    echo ${CHAN}
#    combineTool.py -M CollectLimits higgsCombine.limit.${CHAN}.Asymptotic.mH*.root -o limits_${CHAN}.json
#done

#combineTool.py -M Asymptotic -t -1 -d cmb/125/workspace.root -m 125 -n .limit.CMB
##combineTool.py -M Asymptotic -d cmb/125/workspace.root -m 125 -n .limit.CMB
#combineTool.py -M CollectLimits cmb/125/higgsCombine.limit.CMB.Asymptotic.mH125.root -o limits_CMB.json



# combine -M Significance workspace_cmb.root -t -1 --expectSignal=1
