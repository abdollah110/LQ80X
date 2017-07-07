import CombineHarvester.CombineTools.ch as ch
# import CombineHarvester.CombineTools.pdgRounding as pdgRounding
import ROOT

import math



ROOT.PyConfig.IgnoreCommandLineOptions = True
ROOT.gROOT.SetBatch(ROOT.kTRUE)

ROOT.gSystem.Load('libHiggsAnalysisCombinedLimit')


### WORKSPACE PATH  [CHANGE BOTH WORKSPACE AND MLFIT ROOT FILE AT THE SAME TIME]
### ======= CONSTRAINED =========
# fin = ROOT.TFile('output/CONSTRAINED-svfit/cmb/wsp.root')
# fin = ROOT.TFile('output/CONSTRAINED-mvis/cmb/wsp.root')

### ======= UNCONSTRAINED =========
# fin = ROOT.TFile('output/LIMITS-svfit/cmb/wsp.root')
fin = ROOT.TFile('ws.root')

wsp = fin.Get('w')

cmb = ch.CombineHarvester()
cmb.SetFlag("workspaces-use-clone", True)
ch.ParseCombineWorkspace(cmb, wsp, 'ModelConfig', 'data_obs', False)

### MLFIT ROOT FILE PATH [CHANGE BOTH WORKSPACE AND MLFIT ROOT FILE AT THE SAME TIME]
### ======= CONSTRAINED =========
# mlf = ROOT.TFile('output/CONSTRAINED-svfit/cmb/mlfit.Test.root')
# mlf = ROOT.TFile('output/CONSTRAINED-mvis/cmb/mlfit.Test.root')

### ======= UNCONSTRAINED =========
# mlf = ROOT.TFile('output/LIMITS-svfit/cmb/mlfit.Test.root')
mlf = ROOT.TFile('mlfit.root')




rfr = mlf.Get('fit_s')


def AddSystQuad(a,b):
    a2 = math.pow(a, 2.) 
    b2 = math.pow(b, 2.)
    x  = a2 + b2 
    quad =  math.sqrt(x)
    return quad




def PrintTables(cmb, uargs):
    c_et = cmb.cp().bin(['lq_et_1_13TeV'])
    c_mt = cmb.cp().bin(['lq_mt_1_13TeV'])
    c_em = cmb.cp().bin(['em_inclusive'])
    c_tt = cmb.cp().bin(['tt_inclusive'])
    c_mm = cmb.cp().bin(['mm_inclusive'])



#    print  c_et.cp().PrintAll()

    print r"""
\begin{tabular}{|l|r@{$ \,\,\pm\,\, $}lr@{$ \,\,\pm\,\, $}l|}
\hline
Process & \multicolumn{2}{c}{e$\tauh$} & \multicolumn{2}{c|}{$\mu\tauh$} \\
\hline
\hline"""
    
    print r'Electroweak                                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
        c_et.cp().process(['ZTT','W','VV']).GetRate(), c_et.cp().process(['ZTT','W','VV']).GetUncertainty(*uargs),
        c_mt.cp().process(['ZTT','W','VV']).GetRate(), c_mt.cp().process(['ZTT','W','VV']).GetUncertainty(*uargs))
        
    print r'QCD multijet                                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
        c_et.cp().process(['QCD']).GetRate(), c_et.cp().process(['QCD']).GetUncertainty(*uargs),
        c_mt.cp().process(['QCD']).GetRate(), c_mt.cp().process(['QCD']).GetUncertainty(*uargs))
        
        
    # print r'$\PW$+jets                                       & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
    #     c_et.cp().process(['W']).GetRate(), c_et.cp().process(['W']).GetUncertainty(*uargs),
    #     c_mt.cp().process(['W']).GetRate(), c_mt.cp().process(['W']).GetUncertainty(*uargs))
    # print r'$\cPZ$+jets (jet faking $\Pgt$)                  & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
    #     c_et.cp().process(['ZJ']).GetRate(), c_et.cp().process(['ZJ']).GetUncertainty(*uargs),
    #     c_mt.cp().process(['ZJ']).GetRate(), c_mt.cp().process(['ZJ']).GetUncertainty(*uargs))

    print r'TT                & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
         c_et.cp().process(['TT']).GetRate(), c_et.cp().process(['TT']).GetUncertainty(*uargs),
         c_mt.cp().process(['TT']).GetRate(), c_mt.cp().process(['TT']).GetUncertainty(*uargs))
         
    # print r'\hline'
    # print r'$\cPqt\cPaqt$                                    & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
    #    c_et.cp().process(['TT']).GetRate(), c_et.cp().process(['TT']).GetUncertainty(*uargs),
    #    c_mt.cp().process(['TT']).GetRate(), c_mt.cp().process(['TT']).GetUncertainty(*uargs))
#    print r'$\cPZ$+jets ($\Pe$ or $\Pgm$ faking $\Pgt$)      & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_et.cp().process(['W']).GetRate(), c_et.cp().process(['W']).GetUncertainty(*uargs),
#        c_mt.cp().process(['W']).GetRate(), c_mt.cp().process(['W']).GetUncertainty(*uargs))
    # print r'$\cPqt\cPaqt$ (excl. jet faking $\Pgt$)          & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
    #     c_et.cp().process(['TT']).GetRate(), c_et.cp().process(['TT']).GetUncertainty(*uargs),
    #     c_mt.cp().process(['TT']).GetRate(), c_mt.cp().process(['TT']).GetUncertainty(*uargs))
    print r'SingleTop                             & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
        c_et.cp().process(['SingleTop']).GetRate(), c_et.cp().process(['SingleTop']).GetUncertainty(*uargs),
        c_mt.cp().process(['SingleTop']).GetRate(), c_mt.cp().process(['SingleTop']).GetUncertainty(*uargs))
    ## Not in all datacard inputs + no agreed naming convention. Leave empty for now.
    print r'LQ 900 GeV                                         & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
        c_et.cp().process(['LQ_']).GetRate(), c_et.cp().process(['LQ_']).GetUncertainty(*uargs),
        c_mt.cp().process(['LQ_']).GetRate(), c_mt.cp().process(['LQ_']).GetUncertainty(*uargs))
    print r'\hline'
    print r'Total expected background                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\ ' % (
        c_et.cp().backgrounds().GetRate(), c_et.cp().backgrounds().GetUncertainty(*uargs),
        c_mt.cp().backgrounds().GetRate(), c_mt.cp().backgrounds().GetUncertainty(*uargs))
    print r'\hline'
#    print r'SM expectation                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\ ' % (
#        (c_et.cp().backgrounds().GetRate() + c_et.cp().signals().GetRate()), AddSystQuad(c_et.cp().backgrounds().GetUncertainty(*uargs), c_et.cp().signals().GetUncertainty(*uargs)),
#        (c_mt.cp().backgrounds().GetRate() + c_mt.cp().signals().GetRate()), AddSystQuad(c_mt.cp().backgrounds().GetUncertainty(*uargs), c_mt.cp().signals().GetUncertainty(*uargs)) )
    print r'\hline'
    print r'Observed data                                    & \multicolumn{2}{c}{$%g$} & \multicolumn{2}{c|}{$%g$} \\' % (
        c_et.cp().GetObservedRate(), c_mt.cp().GetObservedRate())
    print r"""\hline
\end{tabular}"""

#
#    print r"""
#\begin{tabular}{|l|r@{$ \,\,\pm\,\, $}lr@{$ \,\,\pm\,\, $}l|}
#\hline
#Process & \multicolumn{2}{c}{$\taue\taum$} & \multicolumn{2}{c|}{$\taum\taum$} \\
#\hline
#\hline"""
#    print r'ZTT                                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_em.cp().process(['ZTT']).GetRate(), c_em.cp().process(['ZTT']).GetUncertainty(*uargs),
#        c_mm.cp().process(['ZTT']).GetRate(), c_mm.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print r'Multijet                                         & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_em.cp().process(['QCD']).GetRate(), c_em.cp().process(['QCD']).GetUncertainty(*uargs),
#        c_mm.cp().process(['QCD']).GetRate(), c_mm.cp().process(['QCD']).GetUncertainty(*uargs))
#    ## print r'$\PW$+jets                                       & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#    ##    c_em.cp().process(['W']).GetRate(), c_em.cp().process(['W']).GetUncertainty(*uargs), ## MERGED WITH EWK
#    ##    c_mm.cp().process(['W']).GetRate(), c_mm.cp().process(['W']).GetUncertainty(*uargs)) ## MERGED WITH EWK
#
#    # print r'$\cPZ$+jets (jet faking $\Pe$ or $\Pgm$)         & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#    #    c_em.cp().process(['ZJ', 'ZLL']).GetRate(), c_em.cp().process(['ZJ', 'ZLL']).GetUncertainty(*uargs),
#    #    c_mm.cp().process(['ZJ', 'ZLL']).GetRate(), c_mm.cp().process(['ZJ', 'ZLL']).GetUncertainty(*uargs))
#    # print r'$\cPqt\cPaqt$ (jet faking $\Pgt$)                & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#    #     c_em.cp().process(['TT']).GetRate(), c_em.cp().process(['TT']).GetUncertainty(*uargs),
#    #     c_mm.cp().process(['TT']).GetRate(), c_mm.cp().process(['TT']).GetUncertainty(*uargs))
#    # print r'\hline'
#    print r'$\cPZ$+jets ($\Pe$ or $\Pgm$ faking $\Pgt$)      & $%.1f$ & $%.1f$ \\' % (
#    ##    c_em.cp().process(['ZLL']).GetRate(), c_em.cp().process(['ZLL']).GetUncertainty(*uargs),  ## MERGED WITH EWK
#        c_mm.cp().process(['ZLL']).GetRate(), c_mm.cp().process(['ZLL']).GetUncertainty(*uargs))
#    print r'$\cPqt\cPaqt$                                    & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_em.cp().process(['TT']).GetRate(), c_em.cp().process(['TT']).GetUncertainty(*uargs),
#        c_mm.cp().process(['TT']).GetRate(), c_mm.cp().process(['TT']).GetUncertainty(*uargs))
#    # print r'$\cPqt\cPaqt$ (excl. jet faking $\Pgt$)          & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#    #     c_em.cp().process(['TT']).GetRate(), c_em.cp().process(['TT']).GetUncertainty(*uargs),
#    #     c_mm.cp().process(['TT']).GetRate(), c_mm.cp().process(['TT']).GetUncertainty(*uargs))
#    print r'Electroweak                             & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_em.cp().process(['W','ZLL','VV']).GetRate(), c_em.cp().process(['W','ZLL','VV']).GetUncertainty(*uargs),
#        c_mm.cp().process(['W','VV']).GetRate(), c_mm.cp().process(['W','VV']).GetUncertainty(*uargs))
#    ## Not in all datacard inputs + no agreed naming convention. Leave empty for now.
#    print r'SM Higgs                                         & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\' % (
#        c_em.cp().process(['ggH125','qqH125']).GetRate(), c_em.cp().process(['ggH125','qqH125']).GetUncertainty(*uargs),
#        c_mm.cp().process(['ggH125','qqH125']).GetRate(), c_mm.cp().process(['ggH125','qqH125']).GetUncertainty(*uargs))
#    print r'\hline'
#    print r'Total expected background                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\ ' % (
#        c_em.cp().backgrounds().GetRate(), c_em.cp().backgrounds().GetUncertainty(*uargs),
#        c_mm.cp().backgrounds().GetRate(), c_mm.cp().backgrounds().GetUncertainty(*uargs))
#    print r'\hline'
#    print r'SM expectation                        & $%.1f$ & $%.1f$ & $%.1f$ & $%.1f$ \\ ' % (
#        (c_em.cp().backgrounds().GetRate() + c_em.cp().signals().GetRate()), AddSystQuad(c_em.cp().backgrounds().GetUncertainty(*uargs), c_em.cp().signals().GetUncertainty(*uargs)),
#        (c_mm.cp().backgrounds().GetRate() + c_mm.cp().signals().GetRate()), AddSystQuad(c_mm.cp().backgrounds().GetUncertainty(*uargs), c_mm.cp().signals().GetUncertainty(*uargs)) )
#    print r'\hline'
#    print r'Observed data                                    & \multicolumn{2}{c}{$%g$} & \multicolumn{2}{c|}{$%g$} \\' % (
#        c_em.cp().GetObservedRate(), c_mm.cp().GetObservedRate())
#    print r"""\hline
#\end{tabular}"""

#
#    print r"""
#\begin{tabular}{|l|r@{$ \,\,\pm\,\, $}l|}
#\hline
#Process & \multicolumn{2}{c|}{$\tauh\tauh$} \\
#\hline
#\hline"""
#    print r'ZTT                                        & $%.1f$ & $%.1f$ \\' % (
#        c_tt.cp().process(['ZTT']).GetRate(), c_tt.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print r'Fakes                                         & $%.1f$ & $%.1f$ \\' % (
#        c_tt.cp().process(['jetFakes']).GetRate(), c_tt.cp().process(['jetFakes']).GetUncertainty(*uargs))
#    ## print r'$\PW$+jets                                       & $%.1f$ & $%.1f$ \\' % (
#    ##    c_tt.cp().process(['W']).GetRate(), c_tt.cp().process(['W']).GetUncertainty(*uargs)) ## MERGED WITH EWK
#
#    # print r'$\cPZ$+jets (jet faking $\Pgt$)                  & $%.1f$ & $%.1f$ \\' % (
#    #    c_tt.cp().process(['ZJ', 'ZLL']).GetRate(), c_tt.cp().process(['ZJ', 'ZLL']).GetUncertainty(*uargs))
#    # print r'$\cPqt\cPaqt$ (jet faking $\Pgt$)                & $%.1f$ & $%.1f$ \\' % (
#    #     c_tt.cp().process(['TT']).GetRate(), c_tt.cp().process(['TT']).GetUncertainty(*uargs))
#    # print r'\hline'
#
#    print r'$\cPqt\cPaqt$                                    & $%.1f$ & $%.1f$ \\' % (
#        c_tt.cp().process(['TT']).GetRate(), c_tt.cp().process(['TT']).GetUncertainty(*uargs))
#
#    ## print r'$\cPZ\to\ell\ell$+jets                           & $%.1f$ & $%.1f$ \\' % (
#    ##    c_tt.cp().process(['ZL']).GetRate(), c_tt.cp().process(['ZL']).GetUncertainty(*uargs)) ## MERGED WITH EWK
#
#    # print r'$\cPqt\cPaqt$ (excl. jet faking $\Pgt$)          & $%.1f$ & $%.1f$ \\' % (
#    #     c_tt.cp().process(['TT']).GetRate(), c_tt.cp().process(['TT']).GetUncertainty(*uargs))
#    print r'Electroweak                             & $%.1f$ & $%.1f$ \\' % (
#        c_tt.cp().process(['W','ZL','VV']).GetRate(), c_tt.cp().process(['W','ZL','VV']).GetUncertainty(*uargs))
#    ## Not in all datacard inputs + no agreed naming convention. Leave empty for now.
#    print r'SM Higgs                                         & $%.1f$ & $%.1f$ \\' % (
#        c_tt.cp().process(['ggH125','qqH125']).GetRate(), c_tt.cp().process(['ggH125','qqH125']).GetUncertainty(*uargs))
#    print r'\hline'
#    print r'Total expected background                        & $%.1f$ & $%.1f$ \\ ' % (
#        c_tt.cp().backgrounds().GetRate(), c_tt.cp().backgrounds().GetUncertainty(*uargs))
#    print r'\hline'
#    print r'SM expectation                        & $%.1f$ & $%.1f$ \\ ' % (
#        (c_tt.cp().backgrounds().GetRate() + c_tt.cp().signals().GetRate()), AddSystQuad(c_tt.cp().backgrounds().GetUncertainty(*uargs), c_tt.cp().signals().GetUncertainty(*uargs)) )        
#    print r'\hline'
#    print r'Observed data        & \multicolumn{2}{c|}{$%g$} \\' % (
#        c_tt.cp().GetObservedRate())
#    print r"""\hline
#\end{tabular}"""

#    print 'et: %.1f +/- %.1f' % (c_et.cp().process(['ZTT']).GetRate(), c_et.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print 'mt: %.1f +/- %.1f' % (c_mt.cp().process(['ZTT']).GetRate(), c_mt.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print 'em: %.1f +/- %.1f' % (c_em.cp().process(['ZTT']).GetRate(), c_em.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print 'mm: %.1f +/- %.1f' % (c_mm.cp().process(['ZTT']).GetRate(), c_mm.cp().process(['ZTT']).GetUncertainty(*uargs))
#    print 'tt: %.1f +/- %.1f' % (c_tt.cp().process(['ZTT']).GetRate(), c_tt.cp().process(['ZTT']).GetUncertainty(*uargs))


print 'Pre-fit tables:'
PrintTables(cmb, tuple())

cmb.UpdateParameters(rfr)

print 'Post-fit tables:\n\n'
PrintTables(cmb, (rfr, 500))
