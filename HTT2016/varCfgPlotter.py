### Nov 13, 2016
### File to store all of the configurations for the
### SM HTT postfit/postfit plotter
###
###
# FIXME FIXME FIXME
# Once the most updated root files are uploaded, the default paths can be set
# in getFile()
# ETau, MuTau and EMu need to double check getBinMap() whic
# provides the number of times unrolled and number of mass bins per
# unroll and labeling

from collections import OrderedDict

# Provide the category names (folder names)
# where we should look for histograms
#def getCategories( channel="tt", prefix="" ) :
#    preCategories=["_0jet","_boosted","_VBF"] 
#    if channel == "em" or channel == "et" or channel == "mt": # FIXME vbf --> VBF when ready
#        preCategories=["_0jet","_boosted","_vbf"] 
#    categories=[prefix+channel+cat for cat in preCategories]
#    return categories

def getCategories( channel="tt", prefix="" ) :
    preCategories=["_1_","_2_","_3_"]
    #preCategories=["_3_"]
    #categories=["htt_"+channel+cat+"13TeV_postfit" for cat in preCategories]
    categories=["htt_"+channel+cat+"13TeV_postfit" for cat in preCategories]
    return categories

# Provide standard mapping to our files
# this can be overridden with --inputFile
def getFile( channel ) :
    fileMap = {
        "et" : "shapes/USCMS/htt_et.inputs-sm-13TeV-mvis.root", # Not up to date
        "mt" : "shapes/USCMS/htt_mt.inputs-sm-13TeV-mvis.root", # Not up to date
        "em" : "emu_unrolled.root", # Not saved publically
        #"em" : "shapes/USCMS/htt_em.inputs-sm-13TeV-mvis.root", # Not up to date
        "tt" : "tautau.root",
        #"tt" : "shapes/USCMS/htt_tt.inputs-sm-13TeV-svfitmass2D.root", # Not up to date
    }
    return fileMap[ channel ]

def getInfoMap( higgsSF, channel ) :
    if channel == "mt" : sub = ("h", "#mu") 
    if channel == "et" : sub = ("h", "e")
    if channel == "em" : sub = ("e", "#mu")
    if channel == "tt" : sub = ("h", "h")
    
    infoMap = OrderedDict()
    # Name : Add these shapes [...], legend name, leg type, fill color
    infoMap["data_obs"] = [["data_obs",],"Observed","elp",1]
    infoMap["ZTT"] = [["ZTT","EWKZ"],"Z#rightarrow#tau#tau","f","#ffcc66"]
    infoMap["ZJ"] = [["ZJ","ZL",],"Z#rightarrow#mu#mu/ee","f","#4496c8"]
    if channel == "em" :
        # This is intentional and will not be changed
        infoMap["TT"] = [["TT",],"t#bar{t}+jets","f","#9999cc"]
    else :
        infoMap["TT"] = [["TTT","TTJ",],"t#bar{t}+jets","f","#9999cc"]
    infoMap["W"] = [["W",],"W+jets","f","#de5a6a"]
    infoMap["QCD"] = [["QCD",],"QCD multijet","f","#ffccff"]
    if channel == "tt" :
        infoMap["VV"] = [["VVT","VVJ",],"Others","f","#12cadd"]
    elif channel == "em" :
        infoMap["VV"] = [["VV","HWW_qq125","HWW_gg125",],"Others","f","#12cadd"]
    else:
        infoMap["VV"] = [["VV",],"Others","f","#12cadd"]
    #infoMap["H125"] = [["ggH125","WH125","ZH125","qqH125",],"H#rightarrow#tau#tau 125 (X%i)"%higgsSF,"l","#000000"]
    infoMap["H125"] = [["ggH","WH","ZH","qqH",],"H#rightarrow#tau#tau (#mu = 1.06)","l","#000000"]
    return infoMap


def getBackgrounds() :    
    bkgs=["VV", "QCD", "W", "TT", "ZJ", "ZTT"]
    return bkgs

def getSignals() :
    signals=["H125"]
    return signals

# Labeling map, this provides, for each channel
# and category :
# unrolling binning in "binning"
# the number of times unrolled in a variable "nx"
# the number of mass bins per unroll "ny"
# and labeling for the divider lines
def getBinMap() :
    binMap = {
        "em" : {
            "htt_em_1_13TeV_postfit" : {
                "nx" : 3,
                "ny" : 12,
                "binning" : [15,25,35],
                "name" : "p_{T}(#mu)",
            },
            "htt_em_2_13TeV_postfit" : {
                "nx" : 6,
                "ny" : 10,
                "binning" : [0,100,150,200,250,300],
                "name" : "p_{T}^{#tau#tau}",
            },
            "htt_em_3_13TeV_postfit" : { # FIXME vbf --> VBF when ready
                "nx" : 4,
                "ny" : 5,
                "binning" : [300,700,1100,1500],
                "name" : "m_{jj}",
            },
        }, # end 'em'
        "mt" : {
            "htt_mt_1_13TeV_postfit" : {
                "nx" : 3,
                "ny" : 12,
                "binning" : ["1 prong","1 prong + #pi^{0}", "3 prongs"],
                "name" : "p_{T}(#tau_{h})",
            },
            "htt_mt_2_13TeV_postfit" : {
                "nx" : 6,
                "ny" : 10,
                "binning" : [0,100,150,200,250,300],
                "name" : "p_{T}^{#tau#tau}",
            },
            "htt_mt_3_13TeV_postfit" : { 
                "nx" : 4,
                "ny" : 5,
                "binning" : [300,700,1100,1500],
                "name" : "m_{jj}",
            },
        }, # end 'mt'
        "et" : {
            "htt_et_1_13TeV_postfit" : {
                "nx" : 3,
                "ny" : 12,
                "binning" : ["1 prong","1 prong + #pi^{0}", "3 prongs"],
                "name" : "p_{T}(#tau_{h})",
            },
            "htt_et_2_13TeV_postfit" : {
                "nx" : 6,
                "ny" : 10,
                "binning" : [0,100,150,200,250,300],
                "name" : "p_{T}^{#tau#tau}",
            },
            "htt_et_3_13TeV_postfit" : { 
                "nx" : 4,
                "ny" : 5,
                "binning" : [300,700,1100,1500],
                "name" : "m_{jj}",
            },
        }, # end 'et'
        "tt" : {
            "htt_tt_1_13TeV_postfit" : {
                "nx" : 1,
                "ny" : 30,
                "binning" : [0,],
                "name" : "N/A",
            },
            "htt_tt_2_13TeV_postfit" : {
                "nx" : 4,
                "ny" : 12,
                "binning" : [0,100,170,300],
                "name" : "p_{T}^{#tau#tau}",
            },
            "htt_tt_3_13TeV_postfit" : {
                "nx" : 4,
                "ny" : 12,
                "binning" : [0,300,500,800],
                "name" : "m_{jj}",
            },
        }, # end 'tt'
    }
    return binMap

