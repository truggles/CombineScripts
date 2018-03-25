# Basic limits and significance and signal strength


echo "Blinded Asimove limits"
for MASS in 110 120 125 130 140; do
    for CAT in llet llmt llem lltt whLep whHad zh wh cmb; do
        echo ""
        echo ${MASS} ${CAT}
        combine -M Asymptotic workspace_${CAT}_${MASS}.root -m ${MASS} -t -1 -n .limit.${CAT} &
    done
done


echo "Expected significance for the combination"
combine -M Significance workspace_cmb.root -t -1 --expectSignal=1


echo "Expected signal strength for the combination"
combine -M FitDiagnostics workspace_cmb.root -t -1 --expectSignal=1



