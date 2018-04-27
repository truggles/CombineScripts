for M in 110 120 125 130 140; do
  echo "Starting from mass = " $M
  for TYPE in _vh_ _diTau_ _cmb_; do
    echo $TYPE $M
    #combine -M Significance --significance ../april26Workspace${TYPE}${M}.root -t -1 --toysFrequentist --expectSignal=1 -m $M -n ${TYPE}_Exp
    #combine -M Significance --significance ../april26Workspace${TYPE}${M}.root -t -1 --expectSignal=1 -m $M -n ${TYPE}_ExpNoToys
    #combine -M Significance --significance ../april26Workspace${TYPE}${M}.root -m $M -n ${TYPE}_Obs
    combine -M Significance --significance --pvalue ../april26Workspace${TYPE}${M}.root -t -1 --toysFrequentist --expectSignal=1 -m $M -n ${TYPE}${M}_Exp
    combine -M Significance --significance --pvalue ../april26Workspace${TYPE}${M}.root -t -1 --expectSignal=1 -m $M -n ${TYPE}${M}_ExpNoToys
    combine -M Significance --significance --pvalue ../april26Workspace${TYPE}${M}.root -m $M -n ${TYPE}${M}_Obs
  done
done
#hadd -f Tot_pvalue_Exp.root higgsCombine_Exp.ProfileLikelihood.mH*.root
#hadd -f Tot_pvalue_Obs.root higgsCombine_Obs.ProfileLikelihood.mH*.root
#python $PWD/../../../scripts/makeSignificancePlots.py -d $PWD/../../../scripts/Significance.dat
