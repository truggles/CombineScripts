'''
Convert a TH1 histogram into a TGraphAsymmErrors, with the proper poisson
statistics.
These use the Neyman construction, instead of simply sqrt(N).
Code taken from:
    https://twiki.cern.ch/twiki/bin/view/CMS/PoissonErrorBars
   double gamma_quantile_c(double z, double alpha, double theta) {
      return theta * ROOT::Math::Cephes::igami( alpha, z);
   }
   double gamma_quantile(double z, double alpha, double theta) {
      // if possible, should use MathMore function ROOT::Math::gamma_quantile for z close to zero
      // otherwise will always return zero for z  value smaller than eps
      return theta * ROOT::Math::Cephes::igami( alpha, 1.- z);
   }
'''

import ROOT
from array import array
from math import sqrt

def poisson_errors(N, coverage=0.6827):
    alpha = 1.0-coverage
    L, U = 0, 0
    if N>0:
      L = ROOT.Math.gamma_quantile(alpha/2, N, 1.)
    U = ROOT.Math.gamma_quantile_c(alpha/2,N+1,1)
    return L, U


def convert(histogram):
    ''' Convert a histogram into a TGraphAsymmErrors with Poisson errors '''
    output = ROOT.TGraphAsymmErrors(histogram)

    for i in range(0,histogram.GetSize()-2):
        yield_in_bin = output.GetY()[i]
    	if yield_in_bin<0:
    	    yield_in_bin=0
        # Next check the case where we set the bin to -0.000001 
        # to smooth out draw options, the Gamma function fails for non-integers 
    	if yield_in_bin<1 and yield_in_bin>0 :
    	    yield_in_bin=1
        N=int(yield_in_bin)

        L, U = poisson_errors(N)

        output.SetPointEYlow(i, N - L)
        output.SetPointEYhigh(i, U - N)

    return output

# Function to create TH1Fs from TGraphAsymmErrors
def getTH1FfromTGraphAsymmErrors( asym, name='asym' ) :

    # Holding vals for TH1F binning and y-vals
    xSpacing = array( 'd', [] )
    yVals = array( 'd', [] )
    yErrors = array( 'd', [] )

    nVals = asym.GetN()
    x, y = ROOT.Double(0.), ROOT.Double(0.)
    xEPlus, xEMin = 0., 0.
    yEPlus, yEMin = 0., 0.

    for n in range( nVals ) :
        asym.GetPoint( n, x, y )
        xEPlus = asym.GetErrorXhigh( n )
        xEMin = asym.GetErrorXlow( n )
        yEPlus = asym.GetErrorYhigh( n )
        yEMin = asym.GetErrorYlow( n )
        xSpacing.append( x-xEMin )
        yVals.append( y )
        # To simplify, take asymm errors and got to Gaussian
        # for TH1
        yErrors.append( sqrt(yEPlus**2 + yEMin**2) )

    # Don't forget to add the high end of last bin
    xSpacing.append( x+xEPlus )

    #print xSpacing
    #print yVals

    outH = ROOT.TH1F( name, name, len(xSpacing)-1, xSpacing )
    for bin in range( 1, outH.GetNbinsX()+1 ) :
        # If bin content is zero for data, set it to negative
        # so that the markers are not plotted in the 0 - max range
        if yVals[bin-1] == 0 :
            outH.SetBinContent( bin, -0.000001 )
        else :
            outH.SetBinContent( bin, yVals[bin-1] )
        #outH.SetBinContent( bin, yVals[bin-1] )
        outH.SetBinError( bin, yErrors[bin-1] )
    return outH

