#
# After making the working area in 74X combine harvester, we need
# to switch to 81X to use the autoMCStats function



echo "Adding autoMCStats"
for MASS in 110 120 125 130 140; do
    for CHAN in eeet eemt eeem eett emmt mmmt emmm mmtt emt ett mmt mtt; do
        echo "* autoMCStats 0" >> ${CHAN}/${MASS}/htt_${CHAN}_1_13TeV.txt
    done
done

echo "Making dedicated DCs by final state grouping"
# Be careful about wild cards
for MASS in 110 120 125 130 140; do
    combineCards.py eeet/${MASS}/htt_*_*_13TeV.txt emmt/${MASS}/htt_*_*_13TeV.txt > llet_${MASS}.txt
    combineCards.py eemt/${MASS}/htt_*_*_13TeV.txt mmmt/${MASS}/htt_*_*_13TeV.txt > llmt_${MASS}.txt
    combineCards.py eeem/${MASS}/htt_*_*_13TeV.txt emmm/${MASS}/htt_*_*_13TeV.txt > llem_${MASS}.txt
    combineCards.py eett/${MASS}/htt_*_*_13TeV.txt mmtt/${MASS}/htt_*_*_13TeV.txt > lltt_${MASS}.txt
    combineCards.py emt/${MASS}/htt_*_*_13TeV.txt mmt/${MASS}/htt_*_*_13TeV.txt > whLep_${MASS}.txt
    combineCards.py ett/${MASS}/htt_*_*_13TeV.txt mtt/${MASS}/htt_*_1_13TeV.txt > whHad_${MASS}.txt
    combineCards.py ????/${MASS}/htt_*_*_13TeV.txt > zh_${MASS}.txt
    combineCards.py ??t/${MASS}/htt_*_*_13TeV.txt > wh_${MASS}.txt
    combineCards.py ????/${MASS}/htt_*_*_13TeV.txt ??t/${MASS}/htt_*_*_13TeV.txt > cmb_${MASS}.txt
done


echo "Making workspace for all DCs"
for MASS in 110 120 125 130 140; do
    for CAT in llet llmt llem lltt whLep whHad zh wh cmb; do
        echo ""
        echo ${MASS} ${CAT}
        ### Text2Workspace
        text2workspace.py ${CAT}_${MASS}.txt -m ${MASS}  -o workspace_${CAT}_${MASS}.root
    done
done


