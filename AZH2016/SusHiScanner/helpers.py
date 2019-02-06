from setup import TranslateCosB_To_sinA


# Pair together Tan(beta) and cos(alpha-beta) values for scanning
def get_pairs() :
    #nPointsTanBeta = 90
    #nPointsTanBeta = 5
    #tan_b_min = 1.0
    #tan_b_max = 10.0
    tanBetaLowRange = [0.5,2]
    tanBetaLowStep  = 0.05
    tanBetasLow = [ tanBetaLowRange[0]+tanBetaLowStep*i for i in range(int((tanBetaLowRange[1]-tanBetaLowRange[0])/tanBetaLowStep)) ]
    tanBetaRange = [2.,10.]
    tanBetaStep = 0.5
    tanBetas = [ tanBetaRange[0]+tanBetaStep*i for i in range(int((tanBetaRange[1]-tanBetaRange[0])/tanBetaStep+1)) ]
    tanBetas = tanBetasLow + tanBetas
    
    
    #SinB_A_min = -1.0
    #SinB_A_max = 1.0
    #nPoints_SinB_A_min = 20 
    cosB_A_Range = [0,1]
    cosB_A_step = 0.005
    cosB_A_step = 0.05
    cosB_As = [cosB_A_Range[0] + cosB_A_step* i for i in range(int((cosB_A_Range[1] - cosB_A_Range[0])/cosB_A_step + 1))]
    sinB_As = TranslateCosB_To_sinA(cosB_As)
    
    pairs = []
    for tan_b in tanBetas :
        for sinB_A in sinB_As :
            pairs.append( [tan_b, sinB_A] )
    return pairs
