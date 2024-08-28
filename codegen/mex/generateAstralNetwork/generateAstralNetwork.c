/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * generateAstralNetwork.c
 *
 * Code generation for function 'generateAstralNetwork'
 *
 */

/* Include files */
#include "generateAstralNetwork.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "generateAstralNetwork_emxutil.h"
#include "generateAstralNetwork_types.h"
#include "indexShapeCheck.h"
#include "mod.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sin.h"
#include "sort.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    29,                                                            /* lineNo */
    "generateAstralNetwork",                                       /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo b_emlrtRSI = {
    30,                                                            /* lineNo */
    "generateAstralNetwork",                                       /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo c_emlrtRSI = {
    31,                                                            /* lineNo */
    "generateAstralNetwork",                                       /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo d_emlrtRSI = {
    34,                                                            /* lineNo */
    "generateAstralNetwork",                                       /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo e_emlrtRSI = {
    44,                                                            /* lineNo */
    "generateAstralNetwork",                                       /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo i_emlrtRSI = {
    123,                                                           /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo j_emlrtRSI = {
    121,                                                           /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo k_emlrtRSI = {
    120,                                                           /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo l_emlrtRSI = {
    89,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo m_emlrtRSI = {
    87,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo n_emlrtRSI = {
    86,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo o_emlrtRSI = {
    78,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo p_emlrtRSI = {
    77,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo q_emlrtRSI = {
    76,                                                            /* lineNo */
    "findNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo r_emlrtRSI = {
    11,                                                           /* lineNo */
    "cos",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/cos.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/matfun/mpower.m" /* pathName
                                                                       */
};

static emlrtRSInfo w_emlrtRSI = {
    71,                                                           /* lineNo */
    "power",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/power.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    28,                                                           /* lineNo */
    "colon",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    125,                                                          /* lineNo */
    "colon",                                                      /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtRSInfo jb_emlrtRSI = {
    40,                  /* lineNo */
    "reshapeSizeChecks", /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pathName */
};

static emlrtRSInfo kb_emlrtRSI = {
    321,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo lb_emlrtRSI = {
    312,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo nb_emlrtRSI = {
    296,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo ob_emlrtRSI = {
    286,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo pb_emlrtRSI = {
    278,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo qb_emlrtRSI = {
    271,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo rb_emlrtRSI = {
    258,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo sb_emlrtRSI = {
    249,                                                           /* lineNo */
    "defineSprings",                                               /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo tb_emlrtRSI = {
    185,                                                           /* lineNo */
    "sortNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo ub_emlrtRSI = {
    198,                                                           /* lineNo */
    "sortNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo vb_emlrtRSI = {
    200,                                                           /* lineNo */
    "sortNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo wb_emlrtRSI = {
    201,                                                           /* lineNo */
    "sortNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo xb_emlrtRSI = {
    204,                                                           /* lineNo */
    "sortNodes",                                                   /* fcnName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pathName
                                                                    */
};

static emlrtRSInfo yb_emlrtRSI = {
    35,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo ac_emlrtRSI = {
    158,                                                           /* lineNo */
    "eml_find",                                                    /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo bc_emlrtRSI = {
    138,                                                           /* lineNo */
    "eml_find",                                                    /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo cc_emlrtRSI = {
    253,                                                           /* lineNo */
    "find_first_nonempty_triples",                                 /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo dc_emlrtRSI = {
    254,                                                           /* lineNo */
    "find_first_nonempty_triples",                                 /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo ec_emlrtRSI = {
    255,                                                           /* lineNo */
    "find_first_nonempty_triples",                                 /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo gc_emlrtRSI = {
    70,    /* lineNo */
    "dot", /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" /* pathName
                                                                     */
};

static emlrtRSInfo hc_emlrtRSI = {
    37,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/sort.m" /* pathName
                                                                      */
};

static emlrtRTEInfo emlrtRTEI = {
    74,                  /* lineNo */
    13,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    79,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    81,                  /* lineNo */
    23,                  /* colNo */
    "reshapeSizeChecks", /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    166,                                                            /* lineNo */
    27,                                                             /* colNo */
    "filCross",                                                     /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    166,                                                            /* lineNo */
    25,                                                             /* colNo */
    "filCross",                                                     /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    156,                                                            /* lineNo */
    26,                                                             /* colNo */
    "filCross",                                                     /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    111,                                                            /* lineNo */
    26,                                                             /* colNo */
    "filCross",                                                     /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    165,                                                            /* lineNo */
    21,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    165,                                                            /* lineNo */
    19,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    155,                                                            /* lineNo */
    23,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    110,                                                            /* lineNo */
    23,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    154,                                                            /* lineNo */
    66,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    154,                                                            /* lineNo */
    57,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    154,                                                            /* lineNo */
    33,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    153,                                                            /* lineNo */
    68,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    153,                                                            /* lineNo */
    59,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    150,                                                            /* lineNo */
    32,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    150,                                                            /* lineNo */
    23,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    149,                                                            /* lineNo */
    36,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    125,                                                           /* lineNo */
    19,                                                            /* colNo */
    "findNodes",                                                   /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    1,                                                             /* nDims */
    121,                                                           /* lineNo */
    29,                                                            /* colNo */
    "findNodes",                                                   /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtBCInfo q_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    121,                                                            /* lineNo */
    44,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    118,                                                           /* lineNo */
    15,                                                            /* colNo */
    "findNodes",                                                   /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    109,                                                            /* lineNo */
    52,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    109,                                                            /* lineNo */
    33,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    108,                                                            /* lineNo */
    54,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    108,                                                            /* lineNo */
    33,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    105,                                                            /* lineNo */
    43,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    105,                                                            /* lineNo */
    27,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    91,                                                             /* lineNo */
    36,                                                             /* colNo */
    "closeEnough",                                                  /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtECInfo b_emlrtECI = {
    1,                                                             /* nDims */
    87,                                                            /* lineNo */
    29,                                                            /* colNo */
    "findNodes",                                                   /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    87,                                                             /* lineNo */
    44,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    79,                                                             /* lineNo */
    15,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    80,                                                             /* lineNo */
    18,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    79,                                                             /* lineNo */
    1,                                                              /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    80,                                                             /* lineNo */
    1,                                                              /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    88,                                                             /* lineNo */
    21,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    88,                                                             /* lineNo */
    21,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    122,                                                            /* lineNo */
    47,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    122,                                                            /* lineNo */
    47,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    89,                                                             /* lineNo */
    33,                                                             /* colNo */
    "otherFils",                                                    /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    129,                                                            /* lineNo */
    23,                                                             /* colNo */
    "tooFar",                                                       /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    100,                                                            /* lineNo */
    29,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    100,                                                            /* lineNo */
    44,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    101,                                                            /* lineNo */
    23,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    101,                                                            /* lineNo */
    36,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    102,                                                            /* lineNo */
    27,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    102,                                                            /* lineNo */
    49,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    103,                                                            /* lineNo */
    49,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    104,                                                            /* lineNo */
    30,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    104,                                                            /* lineNo */
    54,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    143,                                                            /* lineNo */
    29,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    143,                                                            /* lineNo */
    38,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    143,                                                            /* lineNo */
    38,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    143,                                                            /* lineNo */
    57,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    143,                                                            /* lineNo */
    66,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    143,                                                            /* lineNo */
    66,                                                             /* colNo */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    144,                                                            /* lineNo */
    23,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    144,                                                            /* lineNo */
    32,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    144,                                                            /* lineNo */
    51,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    144,                                                            /* lineNo */
    60,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    145,                                                            /* lineNo */
    27,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    145,                                                            /* lineNo */
    49,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    146,                                                            /* lineNo */
    49,                                                             /* colNo */
    "centers",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    147,                                                            /* lineNo */
    30,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    147,                                                            /* lineNo */
    39,                                                             /* colNo */
    "sines",                                                        /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    148,                                                            /* lineNo */
    28,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    148,                                                            /* lineNo */
    37,                                                             /* colNo */
    "cosines",                                                      /* aName */
    "findNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    299,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    325,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    279,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    278,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    259,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    258,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    253,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    290,                                                            /* lineNo */
    18,                                                             /* colNo */
    "ends",                                                         /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    242,                                                            /* lineNo */
    1,                                                              /* colNo */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    241,                                                            /* lineNo */
    1,                                                              /* colNo */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    242,                                                            /* lineNo */
    14,                                                             /* colNo */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    4 /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    242,                                                            /* lineNo */
    14,                                                             /* colNo */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    241,                                                            /* lineNo */
    17,                                                             /* colNo */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    1 /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    332,                                                            /* lineNo */
    25,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo mc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    332,                                                            /* lineNo */
    23,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                                            /* nDims */
    298,                                                           /* lineNo */
    13,                                                            /* colNo */
    "defineSprings",                                               /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    298,                                                            /* lineNo */
    21,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    320,                                                            /* lineNo */
    30,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    311,                                                            /* lineNo */
    31,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    310,                                                            /* lineNo */
    38,                                                             /* colNo */
    "thisOrder",                                                    /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    309,                                                            /* lineNo */
    31,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    308,                                                            /* lineNo */
    38,                                                             /* colNo */
    "thisOrder",                                                    /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    302,                                                            /* lineNo */
    26,                                                             /* colNo */
    "centers",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    295,                                                            /* lineNo */
    32,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    294,                                                            /* lineNo */
    26,                                                             /* colNo */
    "centers",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo i_emlrtRTEI = {
    285,                                                           /* lineNo */
    15,                                                            /* colNo */
    "defineSprings",                                               /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    277,                                                            /* lineNo */
    30,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    270,                                                            /* lineNo */
    31,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    269,                                                            /* lineNo */
    38,                                                             /* colNo */
    "thisOrder",                                                    /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    268,                                                            /* lineNo */
    31,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    267,                                                            /* lineNo */
    38,                                                             /* colNo */
    "thisOrder",                                                    /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    262,                                                            /* lineNo */
    26,                                                             /* colNo */
    "centers",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    257,                                                            /* lineNo */
    32,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    256,                                                            /* lineNo */
    26,                                                             /* colNo */
    "centers",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    248,                                                           /* lineNo */
    15,                                                            /* colNo */
    "defineSprings",                                               /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    13,                                                            /* lineNo */
    9,                                                             /* colNo */
    "sqrt",                                                        /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/sqrt.m" /* pName */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    323,                                                            /* lineNo */
    21,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    274,                                                            /* lineNo */
    25,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    315,                                                            /* lineNo */
    25,                                                             /* colNo */
    "springs",                                                      /* aName */
    "defineSprings",                                                /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    196,                                                            /* lineNo */
    14,                                                             /* colNo */
    "centers",                                                      /* aName */
    "sortNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    1,                                                             /* nDims */
    200,                                                           /* lineNo */
    16,                                                            /* colNo */
    "sortNodes",                                                   /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    239,                                                           /* lineNo */
    1,                                                             /* colNo */
    "find_first_nonempty_triples",                                 /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    12,                                                             /* lineNo */
    23,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    194,                                                            /* lineNo */
    25,                                                             /* colNo */
    "nodes",                                                        /* aName */
    "sortNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,                                                             /* iFirst */
    -1,                                                             /* iLast */
    205,                                                            /* lineNo */
    27,                                                             /* colNo */
    "nodesOnFil",                                                   /* aName */
    "sortNodes",                                                    /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", /* pName */
    0 /* checkKind */
};

static emlrtRTEInfo p_emlrtRTEI = {
    29,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    30,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    76,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    77,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    79,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    80,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    165,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    86,                                                            /* lineNo */
    9,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    34,                                                            /* lineNo */
    43,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    120,                                                           /* lineNo */
    9,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    166,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    88,                                                            /* lineNo */
    13,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    122,                                                           /* lineNo */
    39,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI =
    {
        31,            /* lineNo */
        30,            /* colNo */
        "unsafeSxfun", /* fName */
        "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    1,                                                             /* lineNo */
    39,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    34,                                                            /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    123,                                                           /* lineNo */
    9,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    87,                                                            /* lineNo */
    9,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    121,                                                           /* lineNo */
    29,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    89,                                                            /* lineNo */
    33,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    241,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    242,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    284,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    247,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    332,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    249,                                                           /* lineNo */
    9,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    185,                                                           /* lineNo */
    23,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    195,                                                           /* lineNo */
    24,                                                            /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    36,                                                            /* lineNo */
    5,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    253,                                                           /* lineNo */
    5,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    190,                                                           /* lineNo */
    5,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    194,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    200,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    60,                                                             /* lineNo */
    20,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    205,                                                           /* lineNo */
    16,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    205,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    201,                                                           /* lineNo */
    1,                                                             /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    170,                                                           /* lineNo */
    25,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    247,                                                           /* lineNo */
    17,                                                            /* colNo */
    "find",                                                        /* fName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    201,                                                           /* lineNo */
    19,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    87,                                                            /* lineNo */
    29,                                                            /* colNo */
    "generateAstralNetwork",                                       /* fName */
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" /* pName */
};

/* Function Declarations */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emlrtRSInfo in2, const emxArray_real_T *in4,
                             const emxArray_real_T *in5);

static void defineSprings(const emlrtStack *sp, const emxArray_real_T *nodes,
                          const emxArray_real_T *filCross,
                          const emxArray_real_T *centers, real_T l,
                          real_T astralNum, emxArray_real_T *augNodes,
                          emxArray_real_T *springs, emxArray_real_T *ends);

static void sortNodes(const emlrtStack *sp, real_T filIdx,
                      const emxArray_real_T *nodes,
                      const emxArray_real_T *filCross,
                      const emxArray_real_T *centers, real_T astralNum,
                      emxArray_real_T *nodeOrdering);

/* Function Definitions */
static void binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                             const emlrtRSInfo in2, const emxArray_real_T *in4,
                             const emxArray_real_T *in5)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  emxArray_real_T *b_in4;
  emxArray_real_T *r;
  const real_T *in4_data;
  const real_T *in5_data;
  real_T b_varargin_1;
  real_T *b_in4_data;
  real_T *r1;
  int32_T b_loop_ub;
  int32_T binary_expand_op_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = sp;
  st.tls = sp->tls;
  in5_data = in5->data;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in4, 2, &sc_emlrtRTEI);
  if (in5->size[0] == 1) {
    loop_ub = in4->size[0];
  } else {
    loop_ub = in5->size[0];
  }
  i = b_in4->size[0] * b_in4->size[1];
  b_in4->size[0] = loop_ub;
  b_in4->size[1] = 2;
  emxEnsureCapacity_real_T(sp, b_in4, i, &sc_emlrtRTEI);
  b_in4_data = b_in4->data;
  stride_0_0 = (in4->size[0] != 1);
  stride_1_0 = (in5->size[0] != 1);
  b_loop_ub = loop_ub << 1;
  i = (b_loop_ub < 3200);
  if (i) {
    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in4_data[i2 + b_in4->size[0] * i1] =
            in4_data[i2 * stride_0_0 + in4->size[0] * i1] -
            in5_data[i2 * stride_1_0 + in5->size[0] * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    binary_expand_op_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_numThreads) private(i2)

    for (i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in4_data[i2 + b_in4->size[0] * i1] =
            in4_data[i2 * stride_0_0 + in4->size[0] * i1] -
            in5_data[i2 * stride_1_0 + in5->size[0] * i1];
      }
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  emxInit_real_T(sp, &r, 2, &db_emlrtRTEI);
  stride_0_0 = r->size[0] * r->size[1];
  r->size[0] = loop_ub;
  r->size[1] = 2;
  emxEnsureCapacity_real_T(sp, r, stride_0_0, &db_emlrtRTEI);
  r1 = r->data;
  if (i) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      real_T varargin_1;
      varargin_1 = b_in4_data[i1];
      r1[i1] = varargin_1 * varargin_1;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    binary_expand_op_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_numThreads) private(     \
        b_varargin_1)

    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_varargin_1 = b_in4_data[i1];
      r1[i1] = b_varargin_1 * b_varargin_1;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  emxFree_real_T(sp, &b_in4);
  st.site = (emlrtRSInfo *)&in2;
  sum(&st, r, in1);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void defineSprings(const emlrtStack *sp, const emxArray_real_T *nodes,
                          const emxArray_real_T *filCross,
                          const emxArray_real_T *centers, real_T l,
                          real_T astralNum, emxArray_real_T *augNodes,
                          emxArray_real_T *springs, emxArray_real_T *ends)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack st;
  emxArray_real_T *thisOrder;
  const real_T *centers_data;
  const real_T *nodes_data;
  real_T numFil;
  real_T numSpringsGuess;
  real_T *augNodes_data;
  real_T *ends_data;
  real_T *springs_data;
  int32_T iv[2];
  int32_T newSpring_size[2];
  int32_T defineSprings_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T idx;
  int32_T jdx;
  int32_T loop_ub;
  int32_T numAsters;
  int32_T numAsters_tmp;
  uint32_T springCount;
  st.prev = sp;
  st.tls = sp->tls;
  centers_data = centers->data;
  nodes_data = nodes->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  DEFINESPRINGS partitions filaments into node-bounded sub-segments  */
  /*  (springs) and dangling ends */
  /*    Inputs: */
  /*        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
   */
  /*        crossings (EXCLUDING astral centers) */
  /*        filCross (numNodes x 2 double): list of pairs of filament indices */
  /*        corresponding to the filaments that cross at a particular node; */
  /*        listed so that filCross(idx,1) < filCross(idx,2) */
  /*        centers (numAsters x 2 double): (x,y) coordinates of astral centers
   */
  /*        l (scalar): length of individual filament */
  /*        astralNum (scalar): number of filaments per aster */
  /*    Outputs: */
  /*        augNodes (numAsters+numNodes x 2 double)**: conditionally augmented
   */
  /*        node list; if astralNum >= 2, rows 1:numAsters contain (x,y)  */
  /*        coordinates of astral centers, remaining rows contain (x,y)  */
  /*        coordinates of inter-aster nodes */
  /*        **NOTE: if astralNum == 1, augNodes is the same as nodes (centers */
  /*        are fictitious), so its size is (numNodes x 2) */
  /*        springs (numSprings x 4 double): descriptions of segments bounded */
  /*        by nodes at each end, each row has the structure */
  /*            (1) lesser augNode index at one end of the spring */
  /*            (2) greater augNode index at the other end of the spring */
  /*            (3) filament index (which filament is the spring on) */
  /*            (4) the original distance between the nodes */
  /*        ends (numFil x 2 double): lengths of segments on the ends of each */
  /*        filament. ends(:,2) lists the "right" dangling ends, distal to the
   */
  /*        astral center. ends(:,1) lists the "left" dangling ends, proximal */
  /*        to the astral center; these are all 0 if astralNum >= 2. */
  numAsters_tmp = centers->size[0];
  numAsters = centers->size[0];
  numFil = (real_T)centers->size[0] * astralNum;
  numSpringsGuess = 10.0 * (real_T)nodes->size[0];
  if (numSpringsGuess != (int32_T)numSpringsGuess) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &n_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = springs->size[0] * springs->size[1];
  springs->size[0] = (int32_T)numSpringsGuess;
  springs->size[1] = 4;
  emxEnsureCapacity_real_T(sp, springs, i, &ob_emlrtRTEI);
  springs_data = springs->data;
  if (numSpringsGuess != (int32_T)numSpringsGuess) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &k_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = (int32_T)numSpringsGuess << 2;
  if (loop_ub < 3200) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      springs_data[i1] = 0.0;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    defineSprings_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

    for (i1 = 0; i1 < loop_ub; i1++) {
      springs_data[i1] = 0.0;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  if (!(numFil >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numFil, &l_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = (int32_T)muDoubleScalarFloor(numFil);
  if (numFil != i) {
    emlrtIntegerCheckR2012b(numFil, &m_emlrtDCI, (emlrtConstCTX)sp);
  }
  i2 = (int32_T)numFil;
  i3 = ends->size[0] * ends->size[1];
  ends->size[0] = i2;
  ends->size[1] = 2;
  emxEnsureCapacity_real_T(sp, ends, i3, &pb_emlrtRTEI);
  ends_data = ends->data;
  if (i2 != i) {
    emlrtIntegerCheckR2012b(numFil, &j_emlrtDCI, (emlrtConstCTX)sp);
  }
  loop_ub = i2 << 1;
  if (loop_ub < 3200) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      ends_data[i1] = 0.0;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
    emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    defineSprings_numThreads = emlrtAllocRegionTLSs(
        sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

    for (i1 = 0; i1 < loop_ub; i1++) {
      ends_data[i1] = 0.0;
    }
    emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
    emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
  }
  springCount = 0U;
  augNodes->size[0] = 0;
  augNodes->size[1] = 2;
  emxInit_real_T(sp, &thisOrder, 2, &tb_emlrtRTEI);
  if (astralNum == 1.0) {
    /*  routine for "Classical Mikado" networks */
    numAsters = nodes->size[0];
    i = augNodes->size[0] * augNodes->size[1];
    augNodes->size[0] = nodes->size[0];
    augNodes->size[1] = 2;
    emxEnsureCapacity_real_T(sp, augNodes, i, &rb_emlrtRTEI);
    augNodes_data = augNodes->data;
    loop_ub = nodes->size[0] << 1;
    if (loop_ub < 3200) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        augNodes_data[i1] = nodes_data[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      defineSprings_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

      for (i1 = 0; i1 < loop_ub; i1++) {
        augNodes_data[i1] = nodes_data[i1];
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
    /*  centers are fictitious */
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  (int32_T)numFil, &j_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (idx = 0; idx < i2; idx++) {
      st.site = &sb_emlrtRSI;
      sortNodes(&st, (real_T)idx + 1.0, nodes, filCross, centers, 1.0,
                thisOrder);
      augNodes_data = thisOrder->data;
      if ((thisOrder->size[0] == 0) || (thisOrder->size[1] == 0)) {
        /*  0 nodes = filament doesn't touch any other asters! */
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &jc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = l;
        /*  treat unused filament as "right" dangling end */
      } else if (thisOrder->size[0] == 1) {
        real_T y[2];
        /*  1 node + astralNum == 1 -> two dangling ends */
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &ed_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        if (((int32_T)augNodes_data[0] < 1) ||
            ((int32_T)augNodes_data[0] > numAsters)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)augNodes_data[0], 1, numAsters,
                                        &dd_emlrtBCI, (emlrtConstCTX)sp);
        }
        numFil = nodes_data[(int32_T)augNodes_data[0] - 1] - centers_data[idx];
        y[0] = numFil * numFil;
        numFil = nodes_data[((int32_T)augNodes_data[0] + nodes->size[0]) - 1] -
                 centers_data[idx + centers->size[0]];
        y[1] = numFil * numFil;
        numFil = sumColumnB(y);
        st.site = &rb_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &ic_emlrtBCI, &st);
        }
        ends_data[idx] = muDoubleScalarSqrt(numFil);
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &hc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = l - ends_data[idx + ends->size[0]];
      } else {
        real_T y[2];
        real_T totSpringLength;
        int32_T n;
        /*  >=2 nodes = there are certainly springs along this filament */
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &cd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        totSpringLength = 0.0;
        /*  pair adjacent nodes to form springs */
        n = thisOrder->size[0] - 2;
        loop_ub = thisOrder->size[0];
        for (jdx = 0; jdx <= n; jdx++) {
          real_T springLength;
          springCount++;
          if (jdx + 1 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, loop_ub, &bd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          i = (int32_T)augNodes_data[jdx];
          if ((i < 1) || (i > numAsters)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, numAsters, &ad_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (jdx + 2 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, loop_ub, &yc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          i3 = (int32_T)augNodes_data[jdx + 1];
          if ((i3 < 1) || (i3 > numAsters)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, numAsters, &xc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          numFil = nodes_data[i - 1] - nodes_data[i3 - 1];
          y[0] = numFil * numFil;
          numFil = nodes_data[(i + nodes->size[0]) - 1] -
                   nodes_data[(i3 + nodes->size[0]) - 1];
          y[1] = numFil * numFil;
          springLength = sumColumnB(y);
          st.site = &qb_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          springLength = muDoubleScalarSqrt(springLength);
          numSpringsGuess = augNodes_data[jdx + 1];
          if ((augNodes_data[jdx] > numSpringsGuess) ||
              (muDoubleScalarIsNaN(augNodes_data[jdx]) &&
               (!muDoubleScalarIsNaN(numSpringsGuess)))) {
            numFil = augNodes_data[jdx + 1];
          } else {
            numFil = augNodes_data[jdx];
          }
          if ((!(augNodes_data[jdx] < numSpringsGuess)) &&
              ((!muDoubleScalarIsNaN(augNodes_data[jdx])) ||
               muDoubleScalarIsNaN(numSpringsGuess))) {
            numSpringsGuess = augNodes_data[jdx];
          }
          if (((int32_T)springCount < 1) ||
              ((int32_T)springCount > springs->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)springCount, 1,
                                          springs->size[0], &gd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          springs_data[(int32_T)springCount - 1] = numFil;
          springs_data[((int32_T)springCount + springs->size[0]) - 1] =
              numSpringsGuess;
          springs_data[((int32_T)springCount + springs->size[0] * 2) - 1] =
              (real_T)idx + 1.0;
          springs_data[((int32_T)springCount + springs->size[0] * 3) - 1] =
              springLength;
          totSpringLength += springLength;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
        if (((int32_T)augNodes_data[0] < 1) ||
            ((int32_T)augNodes_data[0] > numAsters)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)augNodes_data[0], 1, numAsters,
                                        &wc_emlrtBCI, (emlrtConstCTX)sp);
        }
        numFil = nodes_data[(int32_T)augNodes_data[0] - 1] - centers_data[idx];
        y[0] = numFil * numFil;
        numFil = nodes_data[((int32_T)augNodes_data[0] + nodes->size[0]) - 1] -
                 centers_data[idx + centers->size[0]];
        y[1] = numFil * numFil;
        numFil = sumColumnB(y);
        st.site = &pb_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &gc_emlrtBCI, &st);
        }
        ends_data[idx] = muDoubleScalarSqrt(numFil);
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &fc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = (l - totSpringLength) - ends_data[idx];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
  } else if (astralNum >= 2.0) {
    int32_T loop_ub_tmp;
    /*  routine for "Astral Mikado" networks */
    i = augNodes->size[0] * augNodes->size[1];
    augNodes->size[0] = centers->size[0] + nodes->size[0];
    augNodes->size[1] = 2;
    emxEnsureCapacity_real_T(sp, augNodes, i, &qb_emlrtRTEI);
    augNodes_data = augNodes->data;
    loop_ub_tmp = nodes->size[0];
    loop_ub = nodes->size[0];
    if ((muIntScalarMax_sint32(numAsters_tmp, loop_ub_tmp) << 1) < 3200) {
      for (i1 = 0; i1 < 2; i1++) {
        for (i4 = 0; i4 < numAsters_tmp; i4++) {
          augNodes_data[i4 + augNodes->size[0] * i1] =
              centers_data[i4 + centers->size[0] * i1];
        }
        for (i4 = 0; i4 < loop_ub_tmp; i4++) {
          augNodes_data[(i4 + centers->size[0]) + augNodes->size[0] * i1] =
              nodes_data[i4 + nodes->size[0] * i1];
        }
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      defineSprings_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads) private(i4)

      for (i1 = 0; i1 < 2; i1++) {
        for (i4 = 0; i4 < numAsters_tmp; i4++) {
          augNodes_data[i4 + augNodes->size[0] * i1] =
              centers_data[i4 + centers->size[0] * i1];
        }
        for (i4 = 0; i4 < loop_ub; i4++) {
          augNodes_data[(i4 + centers->size[0]) + augNodes->size[0] * i1] =
              nodes_data[i4 + nodes->size[0] * i1];
        }
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  (int32_T)numFil, &i_emlrtRTEI,
                                  (emlrtConstCTX)sp);
    for (idx = 0; idx < i2; idx++) {
      st.site = &ob_emlrtRSI;
      sortNodes(&st, (real_T)idx + 1.0, nodes, filCross, centers, astralNum,
                thisOrder);
      augNodes_data = thisOrder->data;
      loop_ub =
          (int32_T)muDoubleScalarFloor((((real_T)idx + 1.0) - 1.0) / astralNum);
      if ((thisOrder->size[0] == 0) || (thisOrder->size[1] == 0)) {
        /*  0 nodes = filament doesn't touch any other asters! */
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &kc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = l;
        /*  treat unused filament as "right" dangling end */
      } else if (thisOrder->size[0] == 1) {
        real_T y[2];
        real_T springLength;
        /*  1 node + astralNum >=2 -> spring between astral center & node */
        springCount++;
        if (loop_ub + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, numAsters_tmp,
                                        &vc_emlrtBCI, (emlrtConstCTX)sp);
        }
        if (((int32_T)augNodes_data[0] < 1) ||
            ((int32_T)augNodes_data[0] > loop_ub_tmp)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)augNodes_data[0], 1,
                                        loop_ub_tmp, &uc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        numFil =
            nodes_data[(int32_T)augNodes_data[0] - 1] - centers_data[loop_ub];
        y[0] = numFil * numFil;
        numFil = nodes_data[((int32_T)augNodes_data[0] + nodes->size[0]) - 1] -
                 centers_data[loop_ub + centers->size[0]];
        y[1] = numFil * numFil;
        springLength = sumColumnB(y);
        st.site = &nb_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        augNodes_data[0] += (real_T)numAsters;
        newSpring_size[0] = 1;
        newSpring_size[1] = 4;
        numFil = augNodes_data[0];
        if (((int32_T)springCount < 1) ||
            ((int32_T)springCount > springs->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)springCount, 1,
                                        springs->size[0], &nc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        iv[0] = 1;
        iv[1] = 4;
        emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &newSpring_size[0], 2,
                                      &c_emlrtECI, (emlrtCTX)sp);
        springs_data[(int32_T)springCount - 1] = loop_ub + 1;
        springs_data[((int32_T)springCount + springs->size[0]) - 1] = numFil;
        springs_data[((int32_T)springCount + springs->size[0] * 2) - 1] =
            idx + 1;
        springs_data[((int32_T)springCount + springs->size[0] * 3) - 1] =
            springLength;
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &dc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = l - springLength;
      } else {
        real_T y[2];
        real_T springLength;
        real_T totSpringLength;
        int32_T n;
        /*  >=2 nodes = there are certainly springs along this filament */
        if (loop_ub + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, numAsters_tmp,
                                        &tc_emlrtBCI, (emlrtConstCTX)sp);
        }
        totSpringLength = 0.0;
        /*  like "Classical", but proximal segment to center is spring */
        /*  also need to account for augmented node indices */
        n = thisOrder->size[0] - 2;
        for (jdx = 0; jdx <= n; jdx++) {
          springCount++;
          if (jdx + 1 > thisOrder->size[0]) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, thisOrder->size[0],
                                          &sc_emlrtBCI, (emlrtConstCTX)sp);
          }
          i = (int32_T)augNodes_data[jdx];
          if ((i < 1) || (i > loop_ub_tmp)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub_tmp, &rc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          if (jdx + 2 > thisOrder->size[0]) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, thisOrder->size[0],
                                          &qc_emlrtBCI, (emlrtConstCTX)sp);
          }
          i3 = (int32_T)augNodes_data[jdx + 1];
          if ((i3 < 1) || (i3 > loop_ub_tmp)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub_tmp, &pc_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          numFil = nodes_data[i - 1] - nodes_data[i3 - 1];
          y[0] = numFil * numFil;
          numFil = nodes_data[(i + nodes->size[0]) - 1] -
                   nodes_data[(i3 + nodes->size[0]) - 1];
          y[1] = numFil * numFil;
          springLength = sumColumnB(y);
          st.site = &lb_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          springLength = muDoubleScalarSqrt(springLength);
          numFil = augNodes_data[jdx + 1];
          if ((!(augNodes_data[jdx] > numFil)) &&
              ((!muDoubleScalarIsNaN(augNodes_data[jdx])) ||
               muDoubleScalarIsNaN(numFil))) {
            numFil = augNodes_data[jdx];
          }
          numSpringsGuess = augNodes_data[jdx + 1];
          if ((!(augNodes_data[jdx] < numSpringsGuess)) &&
              ((!muDoubleScalarIsNaN(augNodes_data[jdx])) ||
               muDoubleScalarIsNaN(numSpringsGuess))) {
            numSpringsGuess = augNodes_data[jdx];
          }
          if (((int32_T)springCount < 1) ||
              ((int32_T)springCount > springs->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)springCount, 1,
                                          springs->size[0], &hd_emlrtBCI,
                                          (emlrtConstCTX)sp);
          }
          springs_data[(int32_T)springCount - 1] = (real_T)numAsters + numFil;
          springs_data[((int32_T)springCount + springs->size[0]) - 1] =
              (real_T)numAsters + numSpringsGuess;
          springs_data[((int32_T)springCount + springs->size[0] * 2) - 1] =
              (real_T)idx + 1.0;
          springs_data[((int32_T)springCount + springs->size[0] * 3) - 1] =
              springLength;
          totSpringLength += springLength;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)sp);
          }
        }
        /*  recording proximal segment as spring */
        springCount++;
        if (((int32_T)augNodes_data[0] < 1) ||
            ((int32_T)augNodes_data[0] > loop_ub_tmp)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)augNodes_data[0], 1,
                                        loop_ub_tmp, &oc_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        numFil =
            nodes_data[(int32_T)augNodes_data[0] - 1] - centers_data[loop_ub];
        y[0] = numFil * numFil;
        numFil = nodes_data[((int32_T)augNodes_data[0] + nodes->size[0]) - 1] -
                 centers_data[loop_ub + centers->size[0]];
        y[1] = numFil * numFil;
        springLength = sumColumnB(y);
        st.site = &kb_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        if (((int32_T)springCount < 1) ||
            ((int32_T)springCount > springs->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)springCount, 1,
                                        springs->size[0], &fd_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        springs_data[(int32_T)springCount - 1] = (real_T)loop_ub + 1.0;
        springs_data[((int32_T)springCount + springs->size[0]) - 1] =
            (real_T)numAsters + augNodes_data[0];
        springs_data[((int32_T)springCount + springs->size[0] * 2) - 1] =
            (real_T)idx + 1.0;
        springs_data[((int32_T)springCount + springs->size[0] * 3) - 1] =
            springLength;
        totSpringLength += springLength;
        if ((int32_T)((uint32_T)idx + 1U) > ends->size[0]) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        ends->size[0], &ec_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        ends_data[idx + ends->size[0]] = l - totSpringLength;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
  }
  emxFree_real_T(sp, &thisOrder);
  if ((int32_T)springCount == 0) {
    springs->size[0] = 0;
    springs->size[1] = 4;
  } else {
    if (springs->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, springs->size[0], &mc_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    loop_ub = (int32_T)springCount;
    if (((int32_T)springCount < 1) ||
        ((int32_T)springCount > springs->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)springCount, 1, springs->size[0],
                                    &lc_emlrtBCI, (emlrtConstCTX)sp);
    }
    for (i = 0; i < 4; i++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        springs_data[i2 + (int32_T)springCount * i] =
            springs_data[i2 + springs->size[0] * i];
      }
    }
    i = springs->size[0] * springs->size[1];
    springs->size[0] = (int32_T)springCount;
    springs->size[1] = 4;
    emxEnsureCapacity_real_T(sp, springs, i, &sb_emlrtRTEI);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void sortNodes(const emlrtStack *sp, real_T filIdx,
                      const emxArray_real_T *nodes,
                      const emxArray_real_T *filCross,
                      const emxArray_real_T *centers, real_T astralNum,
                      emxArray_real_T *nodeOrdering)
{
  __m128d r;
  __m128d r1;
  jmp_buf emlrtJBEnviron;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_boolean_T *x;
  emxArray_int32_T *i_tmp;
  emxArray_int32_T *nodesOnFil;
  emxArray_real_T *a;
  emxArray_real_T *dotProducts;
  emxArray_real_T *nodeCoordsOnFil;
  real_T a_tmp[2];
  real_T b_nodesOnFil[2];
  real_T y[2];
  const real_T *centers_data;
  const real_T *filCross_data;
  const real_T *nodes_data;
  real_T d;
  real_T d1;
  real_T d2;
  real_T y_tmp;
  real_T *dotProducts_data;
  real_T *nodeCoordsOnFil_data;
  real_T *nodeOrdering_data;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T sortNodes_numThreads;
  int32_T *i_tmp_data;
  int32_T *nodesOnFil_data;
  boolean_T emlrtHadParallelError = false;
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T p;
  boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  centers_data = centers->data;
  filCross_data = filCross->data;
  nodes_data = nodes->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  SORTNODES orders the node indices along a filament */
  /*    Inputs: */
  /*        filIdx (scalar): filament index (see note in findNodes for details)
   */
  /*        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
   */
  /*        crossings (EXCLUDING astral centers) */
  /*        filCross (numNodes x 2 double): list of pairs of filament indices */
  /*        corresponding to the filaments that cross at a particular node; */
  /*        listed so that filCross(idx,1) < filCross(idx,2) */
  /*        centers (numAsters x 2 double): (x,y) coordinates of astral centers
   */
  /*        astralNum (scalar): number of filaments per aster */
  /*    Outputs: */
  /*        nodeOrdering (double vector): sorted list of node indices appearing
   */
  /*        on the specified filament. First element is the node closest to the
   */
  /*        astral center. If there are no nodes on this filament, returns [].
   */
  st.site = &tb_emlrtRSI;
  emxInit_boolean_T(&st, &x, 2, &ub_emlrtRTEI);
  i = x->size[0] * x->size[1];
  x->size[0] = filCross->size[0];
  x->size[1] = 2;
  emxEnsureCapacity_boolean_T(&st, x, i, &ub_emlrtRTEI);
  x_data = x->data;
  loop_ub_tmp = filCross->size[0] << 1;
  if (loop_ub_tmp < 3200) {
    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      x_data[i1] = (filCross_data[i1] == filIdx);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    sortNodes_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      x_data[i1] = (filCross_data[i1] == filIdx);
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
  b_st.site = &yb_emlrtRSI;
  emxInit_int32_T(&b_st, &i_tmp, &hc_emlrtRTEI);
  i_tmp_data = i_tmp->data;
  if (loop_ub_tmp == 0) {
    i_tmp->size[0] = 0;
  } else {
    c_st.site = &bc_emlrtRSI;
    idx = 0;
    i = i_tmp->size[0];
    i_tmp->size[0] = loop_ub_tmp;
    emxEnsureCapacity_int32_T(&c_st, i_tmp, i, &vb_emlrtRTEI);
    i_tmp_data = i_tmp->data;
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      guard1 = false;
      if (x_data[(ii + x->size[0] * (jj - 1)) - 1]) {
        idx++;
        i_tmp_data[idx - 1] = ii;
        if (idx >= loop_ub_tmp) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        ii++;
        if (ii > x->size[0]) {
          ii = 1;
          jj++;
        }
      }
    }
    if (idx > loop_ub_tmp) {
      emlrtErrorWithMessageIdR2018a(&c_st, &l_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (loop_ub_tmp == 1) {
      if (idx == 0) {
        i_tmp->size[0] = 0;
      }
    } else {
      if (idx < 1) {
        i = 0;
      } else {
        i = idx;
      }
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &cc_emlrtRSI;
      indexShapeCheck(&d_st, i_tmp->size[0], iv);
      ii = i_tmp->size[0];
      i_tmp->size[0] = i;
      emxEnsureCapacity_int32_T(&c_st, i_tmp, ii, &xb_emlrtRTEI);
      i_tmp_data = i_tmp->data;
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &dc_emlrtRSI;
      indexShapeCheck(&d_st, loop_ub_tmp, iv);
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &ec_emlrtRSI;
      indexShapeCheck(&d_st, loop_ub_tmp, iv);
    }
  }
  if ((x->size[0] == 1) && (i_tmp->size[0] != 1)) {
    c_st.site = &ac_emlrtRSI;
    warning(&c_st);
  }
  emxFree_boolean_T(&b_st, &x);
  emxInit_int32_T(&st, &nodesOnFil, &gc_emlrtRTEI);
  loop_ub = i_tmp->size[0];
  i = nodesOnFil->size[0];
  nodesOnFil->size[0] = i_tmp->size[0];
  emxEnsureCapacity_int32_T(&st, nodesOnFil, i, &wb_emlrtRTEI);
  nodesOnFil_data = nodesOnFil->data;
  loop_ub_tmp = i_tmp->size[0];
  if (i_tmp->size[0] < 3200) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      nodesOnFil_data[i1] = i_tmp_data[i1];
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    sortNodes_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

    for (i1 = 0; i1 < loop_ub_tmp; i1++) {
      nodesOnFil_data[i1] = i_tmp_data[i1];
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
  emxInit_real_T(sp, &nodeCoordsOnFil, 2, &ac_emlrtRTEI);
  emxInit_real_T(sp, &dotProducts, 1, &fc_emlrtRTEI);
  emxInit_real_T(sp, &a, 2, &ic_emlrtRTEI);
  if (nodesOnFil->size[0] == 0) {
    nodeOrdering->size[0] = 0;
    nodeOrdering->size[1] = 0;
  } else if (nodesOnFil->size[0] == 1) {
    i = nodeOrdering->size[0] * nodeOrdering->size[1];
    nodeOrdering->size[0] = 1;
    nodeOrdering->size[1] = 1;
    emxEnsureCapacity_real_T(sp, nodeOrdering, i, &yb_emlrtRTEI);
    nodeOrdering_data = nodeOrdering->data;
    nodeOrdering_data[0] = nodesOnFil_data[0];
  } else {
    ii = nodes->size[0];
    i = nodeCoordsOnFil->size[0] * nodeCoordsOnFil->size[1];
    nodeCoordsOnFil->size[0] = loop_ub;
    nodeCoordsOnFil->size[1] = 2;
    emxEnsureCapacity_real_T(sp, nodeCoordsOnFil, i, &ac_emlrtRTEI);
    nodeCoordsOnFil_data = nodeCoordsOnFil->data;
    if ((nodesOnFil->size[0] << 1) < 3200) {
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          if ((nodesOnFil_data[i2] < 1) || (nodesOnFil_data[i2] > ii)) {
            emlrtDynamicBoundsCheckR2012b(nodesOnFil_data[i2], 1, ii,
                                          &jd_emlrtBCI, (emlrtConstCTX)sp);
          }
          nodeCoordsOnFil_data[i2 + nodeCoordsOnFil->size[0] * i1] =
              nodes_data[(nodesOnFil_data[i2] + nodes->size[0] * i1) - 1];
        }
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      sortNodes_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(sortNodes_numThreads) private(                \
        i2, e_st, emlrtJBEnviron) firstprivate(emlrtHadParallelError)
      {
        if (setjmp(emlrtJBEnviron) == 0) {
          e_st.prev = sp;
          e_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
          e_st.site = NULL;
          emlrtSetJmpBuf(&e_st, &emlrtJBEnviron);
        } else {
          emlrtHadParallelError = true;
        }
#pragma omp for nowait
        for (i1 = 0; i1 < 2; i1++) {
          if (emlrtHadParallelError) {
            continue;
          }
          if (setjmp(emlrtJBEnviron) == 0) {
            for (i2 = 0; i2 < loop_ub; i2++) {
              if ((nodesOnFil_data[i2] < 1) || (nodesOnFil_data[i2] > ii)) {
                emlrtDynamicBoundsCheckR2012b(nodesOnFil_data[i2], 1, ii,
                                              &jd_emlrtBCI, &e_st);
              }
              nodeCoordsOnFil_data[i2 + nodeCoordsOnFil->size[0] * i1] =
                  nodes_data[(nodesOnFil_data[i2] + nodes->size[0] * i1) - 1];
            }
          } else {
            emlrtHadParallelError = true;
          }
        }
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
    y_tmp = muDoubleScalarFloor((filIdx - 1.0) / astralNum);
    if (((int32_T)(y_tmp + 1.0) < 1) ||
        ((int32_T)(y_tmp + 1.0) > centers->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(y_tmp + 1.0), 1, centers->size[0],
                                    &id_emlrtBCI, (emlrtConstCTX)sp);
    }
    d = centers_data[(int32_T)(y_tmp + 1.0) - 1];
    d1 = nodeCoordsOnFil_data[0] - d;
    a_tmp[0] = d1;
    y[0] = d1 * d1;
    d2 = centers_data[((int32_T)(y_tmp + 1.0) + centers->size[0]) - 1];
    d1 = nodeCoordsOnFil_data[nodeCoordsOnFil->size[0]] - d2;
    a_tmp[1] = d1;
    y[1] = d1 * d1;
    y_tmp = sumColumnB(y);
    st.site = &ub_emlrtRSI;
    if (y_tmp < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    y_tmp = muDoubleScalarSqrt(y_tmp);
    /*  next two lines find dot product "direction * (node - r0)" for all nodes
     */
    y[0] = d;
    y[1] = d2;
    idx = nodesOnFil->size[0];
    b_nodesOnFil[0] = nodesOnFil->size[0];
    b_nodesOnFil[1] = 1.0;
    st.site = &vb_emlrtRSI;
    repmat(&st, y, b_nodesOnFil, a);
    nodeOrdering_data = a->data;
    if ((loop_ub != a->size[0]) && (a->size[0] != 1)) {
      emlrtDimSizeImpxCheckR2021b(loop_ub, a->size[0], &d_emlrtECI,
                                  (emlrtConstCTX)sp);
    }
    loop_ub_tmp = nodeCoordsOnFil->size[0] << 1;
    i = nodeCoordsOnFil->size[0] * nodeCoordsOnFil->size[1];
    nodeCoordsOnFil->size[1] = 2;
    emxEnsureCapacity_real_T(sp, nodeCoordsOnFil, i, &bc_emlrtRTEI);
    nodeCoordsOnFil_data = nodeCoordsOnFil->data;
    ii = (loop_ub_tmp / 2) << 1;
    jj = ii - 2;
    for (i1 = 0; i1 <= jj; i1 += 2) {
      r = _mm_loadu_pd(&nodeCoordsOnFil_data[i1]);
      r1 = _mm_loadu_pd(&nodeOrdering_data[i1]);
      _mm_storeu_pd(&nodeCoordsOnFil_data[i1], _mm_sub_pd(r, r1));
    }
    if (loop_ub_tmp - ii < 3200) {
      for (i1 = ii; i1 < loop_ub_tmp; i1++) {
        nodeCoordsOnFil_data[i1] -= nodeOrdering_data[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      sortNodes_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

      for (i1 = ii; i1 < loop_ub_tmp; i1++) {
        nodeCoordsOnFil_data[i1] -= nodeOrdering_data[i1];
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
    st.site = &wb_emlrtRSI;
    r = _mm_loadu_pd(&a_tmp[0]);
    _mm_storeu_pd(&a_tmp[0], _mm_div_pd(r, _mm_set1_pd(y_tmp)));
    b_nodesOnFil[0] = idx;
    b_nodesOnFil[1] = 1.0;
    b_st.site = &wb_emlrtRSI;
    repmat(&b_st, a_tmp, b_nodesOnFil, a);
    nodeOrdering_data = a->data;
    a_tmp[0] = a->size[0];
    y[0] = nodeCoordsOnFil->size[0];
    a_tmp[1] = 2.0;
    y[1] = 2.0;
    p = true;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 2)) {
      if (a_tmp[ii] != y[ii]) {
        p = false;
        exitg1 = true;
      } else {
        ii++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                    "MATLAB:dot:InputSizeMismatch",
                                    "MATLAB:dot:InputSizeMismatch", 0);
    }
    i = a->size[0];
    ii = dotProducts->size[0];
    dotProducts->size[0] = a->size[0];
    emxEnsureCapacity_real_T(&st, dotProducts, ii, &cc_emlrtRTEI);
    dotProducts_data = dotProducts->data;
    ii = -1;
    b_st.site = &gc_emlrtRSI;
    if (a->size[0] > 2147483646) {
      c_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (idx = 0; idx < i; idx++) {
      ii++;
      jj = ii + i;
      dotProducts_data[idx] = nodeOrdering_data[ii] * nodeCoordsOnFil_data[ii] +
                              nodeOrdering_data[jj] * nodeCoordsOnFil_data[jj];
    }
    /*  now sort the dot products in increasing order and sort the node indices
     */
    /*  using the same permutation */
    st.site = &xb_emlrtRSI;
    b_st.site = &hc_emlrtRSI;
    sort(&b_st, dotProducts, i_tmp);
    i_tmp_data = i_tmp->data;
    loop_ub_tmp = i_tmp->size[0];
    i = dotProducts->size[0];
    dotProducts->size[0] = i_tmp->size[0];
    emxEnsureCapacity_real_T(sp, dotProducts, i, &dc_emlrtRTEI);
    dotProducts_data = dotProducts->data;
    ii = i_tmp->size[0];
    i = (i_tmp->size[0] < 3200);
    if (i) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        if ((i_tmp_data[i1] < 1) || (i_tmp_data[i1] > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(i_tmp_data[i1], 1, loop_ub,
                                        &kd_emlrtBCI, (emlrtConstCTX)sp);
        }
        dotProducts_data[i1] = nodesOnFil_data[i_tmp_data[i1] - 1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      sortNodes_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(sortNodes_numThreads) private(                \
        emlrtJBEnviron, f_st) firstprivate(emlrtHadParallelError)
      {
        if (setjmp(emlrtJBEnviron) == 0) {
          f_st.prev = sp;
          f_st.tls = emlrtAllocTLS((emlrtCTX)sp, omp_get_thread_num());
          f_st.site = NULL;
          emlrtSetJmpBuf(&f_st, &emlrtJBEnviron);
        } else {
          emlrtHadParallelError = true;
        }
#pragma omp for nowait
        for (i1 = 0; i1 < ii; i1++) {
          if (emlrtHadParallelError) {
            continue;
          }
          if (setjmp(emlrtJBEnviron) == 0) {
            if ((i_tmp_data[i1] < 1) || (i_tmp_data[i1] > loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(i_tmp_data[i1], 1, loop_ub,
                                            &kd_emlrtBCI, &f_st);
            }
            dotProducts_data[i1] = nodesOnFil_data[i_tmp_data[i1] - 1];
          } else {
            emlrtHadParallelError = true;
          }
        }
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
    ii = nodeOrdering->size[0] * nodeOrdering->size[1];
    nodeOrdering->size[0] = loop_ub_tmp;
    nodeOrdering->size[1] = 1;
    emxEnsureCapacity_real_T(sp, nodeOrdering, ii, &ec_emlrtRTEI);
    nodeOrdering_data = nodeOrdering->data;
    if (i) {
      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        nodeOrdering_data[i1] = dotProducts_data[i1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      sortNodes_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

      for (i1 = 0; i1 < loop_ub_tmp; i1++) {
        nodeOrdering_data[i1] = dotProducts_data[i1];
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
  }
  emxFree_real_T(sp, &a);
  emxFree_int32_T(sp, &i_tmp);
  emxFree_int32_T(sp, &nodesOnFil);
  emxFree_real_T(sp, &dotProducts);
  emxFree_real_T(sp, &nodeCoordsOnFil);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

emlrtCTX emlrtGetRootTLSGlobal(void)
{
  return emlrtRootTLSGlobal;
}

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData)
{
  omp_set_lock(&emlrtLockGlobal);
  emlrtCallLockeeFunction(aLockee, aTLS, aData);
  omp_unset_lock(&emlrtLockGlobal);
}

void generateAstralNetwork(const emlrtStack *sp, real_T numAsters, real_T l,
                           real_T D, real_T astralNum, boolean_T nodesOnly,
                           struct0_T *network, struct1_T *crossings,
                           struct2_T *asters)
{
  __m128d r;
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_boolean_T *tooFar;
  emxArray_int32_T *r4;
  emxArray_real_T *centerSepSQR;
  emxArray_real_T *cosines;
  emxArray_real_T *otherAsters;
  emxArray_real_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *r3;
  emxArray_real_T *sines;
  real_T b_numAsters[2];
  real_T b_otherAsters[2];
  real_T a;
  real_T c;
  real_T numNodesGuess;
  real_T *centerSepSQR_data;
  real_T *cosines_data;
  real_T *otherAsters_data;
  real_T *r5;
  real_T *r6;
  real_T *sines_data;
  int32_T b_asters;
  int32_T b_astralNum;
  int32_T c_numAsters;
  int32_T generateAstralNetwork_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T idx;
  int32_T jdx;
  int32_T k;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T numAsters_tmp;
  int32_T numFil;
  int32_T vectorUB;
  int32_T *r7;
  uint32_T nodeCount;
  boolean_T out;
  boolean_T *tooFar_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  /*  GENERATEASTRALNETWORK Constructs an astral network and reports properties
   */
  /*    Inputs: */
  /*        numAsters (scalar): (whole) number of asters to distribute */
  /*        l (scalar): length of individual filament */
  /*        D (scalar): domain size; asters are distributed in the square */
  /*        with corners at (0,0) and (D,D) */
  /*        astralNum (scalar): (whole) number of filaments per aster */
  /*        nodesOnly (boolean): passing true generates nodes only and skips */
  /*        creation of network fields augNodes, springs, & ends, pass false to
   */
  /*        generate all fields */
  /*    Outputs: */
  /*        network (struct): has fields 'nodes', 'augNodes', 'springs', 'ends'
   */
  /*            'nodes': see findNodes auxiliary function */
  /*            'augNodes': see defineSprings auxiliary function */
  /*            'springs': see defineSprings auxiliary function */
  /*            'ends': see defineSprings auxiliary function */
  /*        crossings (struct): has fields 'filCross' and 'centerCross' */
  /*            'filCross': see findNodes auxiliary function */
  /*            'centerCross': which filaments cross at each astral center; */
  /*            each row represents a center */
  /*        asters (struct): has fields 'centers', 'orients' */
  /*            'centers': (x,y) coordinates of astral centers */
  /*            'orients': angles giving each filament's orientation about its
   */
  /*            astral center */
  /*    Note: currently no boundary/edge is constructed, and the implementation
   */
  /*    does not store/compile information for running Metropolis-Hastings */
  b_numAsters[0] = numAsters;
  b_numAsters[1] = 2.0;
  st.site = &emlrtRSI;
  b_rand(&st, b_numAsters, network->nodes);
  i = asters->centers->size[0] * asters->centers->size[1];
  asters->centers->size[0] = network->nodes->size[0];
  asters->centers->size[1] = 2;
  emxEnsureCapacity_real_T(sp, asters->centers, i, &p_emlrtRTEI);
  loop_ub = network->nodes->size[0] << 1;
  maxdimlen = (loop_ub / 2) << 1;
  vectorUB = maxdimlen - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&network->nodes->data[i]);
    _mm_storeu_pd(&asters->centers->data[i], _mm_mul_pd(_mm_set1_pd(D), r));
  }
  for (i = maxdimlen; i < loop_ub; i++) {
    asters->centers->data[i] = D * network->nodes->data[i];
  }
  b_numAsters[0] = numAsters;
  b_numAsters[1] = astralNum;
  emxInit_real_T(sp, &cosines, 2, &r_emlrtRTEI);
  st.site = &b_emlrtRSI;
  c_rand(&st, b_numAsters, cosines);
  cosines_data = cosines->data;
  i = asters->orients->size[0] * asters->orients->size[1];
  asters->orients->size[0] = cosines->size[0];
  asters->orients->size[1] = cosines->size[1];
  emxEnsureCapacity_real_T(sp, asters->orients, i, &q_emlrtRTEI);
  loop_ub = cosines->size[0] * cosines->size[1];
  maxdimlen = (loop_ub / 2) << 1;
  vectorUB = maxdimlen - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&cosines_data[i]);
    _mm_storeu_pd(&asters->orients->data[i],
                  _mm_mul_pd(_mm_set1_pd(6.2831853071795862), r));
  }
  for (i = maxdimlen; i < loop_ub; i++) {
    asters->orients->data[i] = 6.2831853071795862 * cosines_data[i];
  }
  st.site = &c_emlrtRSI;
  /*  Auxiliary functions */
  /*  FINDNODES identifies where filaments cross and records which filaments */
  /*  crossed  */
  /*  (Note: filaments are indexed as one would read left to right across the */
  /*  rows of 'orients', and each row represents an aster. This function does */
  /*  NOT search for intersections between filaments on the same aster) */
  /*    Inputs: */
  /*        centers (numAsters x 2 double): (x,y) coordinates of astral centers
   */
  /*        orients (numAsters x astralNum double): angles giving each  */
  /*        filament's orientation about its astral center */
  /*        l (scalar): length of individual filament */
  /*        centerCross (numAsters x astralNum double): filament indices */
  /*        grouped by each aster */
  /*    Outputs: */
  /*        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
   */
  /*        crossings (EXCLUDING astral centers) */
  /*        filCross (numNodes x 2 double): list of pairs of filament indices */
  /*        corresponding to the filaments that cross at a particular node; */
  /*        listed so that filCross(idx,1) < filCross(idx,2) */
  vectorUB = asters->orients->size[1];
  b_astralNum = asters->orients->size[1];
  numAsters_tmp = asters->orients->size[0];
  c_numAsters = asters->orients->size[0];
  numFil = asters->orients->size[0] * asters->orients->size[1];
  b_st.site = &q_emlrtRSI;
  i = cosines->size[0] * cosines->size[1];
  cosines->size[0] = asters->orients->size[0];
  cosines->size[1] = asters->orients->size[1];
  emxEnsureCapacity_real_T(&b_st, cosines, i, &r_emlrtRTEI);
  cosines_data = cosines->data;
  for (i = 0; i < numFil; i++) {
    cosines_data[i] = asters->orients->data[i];
  }
  c_st.site = &r_emlrtRSI;
  d_st.site = &s_emlrtRSI;
  if (numFil > 2147483646) {
    e_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  if (numFil < 3200) {
    for (k = 0; k < numFil; k++) {
      cosines_data[k] = muDoubleScalarCos(cosines_data[k]);
    }
  } else {
    emlrtEnterParallelRegion(&c_st, omp_in_parallel());
    emlrtPushJmpBuf(&c_st, &emlrtJBStack);
    generateAstralNetwork_numThreads =
        emlrtAllocRegionTLSs(c_st.tls, omp_in_parallel(), omp_get_max_threads(),
                             omp_get_num_procs());
#pragma omp parallel for num_threads(generateAstralNetwork_numThreads)

    for (k = 0; k < numFil; k++) {
      cosines_data[k] = muDoubleScalarCos(cosines_data[k]);
    }
    emlrtPopJmpBuf(&c_st, &emlrtJBStack);
    emlrtExitParallelRegion(&c_st, omp_in_parallel());
  }
  emxInit_real_T(&st, &sines, 2, &s_emlrtRTEI);
  i = sines->size[0] * sines->size[1];
  sines->size[0] = numAsters_tmp;
  sines->size[1] = vectorUB;
  emxEnsureCapacity_real_T(&st, sines, i, &s_emlrtRTEI);
  sines_data = sines->data;
  for (i = 0; i < numFil; i++) {
    sines_data[i] = asters->orients->data[i];
  }
  b_st.site = &p_emlrtRSI;
  b_sin(&b_st, sines);
  sines_data = sines->data;
  b_st.site = &o_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  d_st.site = &w_emlrtRSI;
  numNodesGuess = muDoubleScalarRound((real_T)numFil * (real_T)numFil / 10.0);
  if (numNodesGuess != (int32_T)numNodesGuess) {
    emlrtIntegerCheckR2012b(numNodesGuess, &emlrtDCI, &st);
  }
  i = network->nodes->size[0] * network->nodes->size[1];
  network->nodes->size[0] = (int32_T)numNodesGuess;
  network->nodes->size[1] = 2;
  emxEnsureCapacity_real_T(&st, network->nodes, i, &t_emlrtRTEI);
  if (numNodesGuess != (int32_T)numNodesGuess) {
    emlrtIntegerCheckR2012b(numNodesGuess, &c_emlrtDCI, &st);
  }
  maxdimlen = (int32_T)numNodesGuess << 1;
  for (i = 0; i < maxdimlen; i++) {
    network->nodes->data[i] = 0.0;
  }
  if (numNodesGuess != (int32_T)numNodesGuess) {
    emlrtIntegerCheckR2012b(numNodesGuess, &b_emlrtDCI, &st);
  }
  i = crossings->filCross->size[0] * crossings->filCross->size[1];
  crossings->filCross->size[0] = (int32_T)numNodesGuess;
  crossings->filCross->size[1] = 2;
  emxEnsureCapacity_real_T(&st, crossings->filCross, i, &u_emlrtRTEI);
  if (numNodesGuess != (int32_T)numNodesGuess) {
    emlrtIntegerCheckR2012b(numNodesGuess, &d_emlrtDCI, &st);
  }
  for (i = 0; i < maxdimlen; i++) {
    crossings->filCross->data[i] = 0.0;
  }
  nodeCount = 0U;
  emxInit_real_T(&st, &centerSepSQR, 1, &hb_emlrtRTEI);
  emxInit_real_T(&st, &otherAsters, 2, &y_emlrtRTEI);
  otherAsters_data = otherAsters->data;
  emxInit_real_T(&st, &r1, 2, &ib_emlrtRTEI);
  emxInit_real_T(&st, &r2, 2, &ib_emlrtRTEI);
  emxInit_real_T(&st, &r3, 2, &db_emlrtRTEI);
  if (asters->orients->size[1] == 1) {
    /*  routine for "Classical Mikado" networks */
    if (numFil - 2 >= 0) {
      b_otherAsters[1] = 1.0;
      b_asters = asters->centers->size[0];
      a = 2.0 * l;
    }
    emxInit_int32_T(&st, &r4, &jb_emlrtRTEI);
    for (idx = 0; idx <= numFil - 2; idx++) {
      /*  only look for intersections if filaments are close enough */
      b_st.site = &n_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      if (numFil < ((real_T)idx + 1.0) + 1.0) {
        otherAsters->size[0] = 1;
        otherAsters->size[1] = 0;
      } else {
        i = otherAsters->size[0] * otherAsters->size[1];
        otherAsters->size[0] = 1;
        i1 = numFil - idx;
        otherAsters->size[1] = i1 - 1;
        emxEnsureCapacity_real_T(&c_st, otherAsters, i, &w_emlrtRTEI);
        otherAsters_data = otherAsters->data;
        loop_ub = i1 - 2;
        for (i = 0; i <= loop_ub; i++) {
          otherAsters_data[i] = (real_T)((uint32_T)idx + (uint32_T)i) + 2.0;
        }
      }
      i = asters->centers->size[0];
      if (((int32_T)((uint32_T)idx + 1U) < 1) ||
          ((int32_T)((uint32_T)idx + 1U) > asters->centers->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                      asters->centers->size[0], &y_emlrtBCI,
                                      &st);
      }
      b_numAsters[0] = asters->centers->data[idx];
      b_numAsters[1] = asters->centers->data[idx + asters->centers->size[0]];
      b_otherAsters[0] = otherAsters->size[1];
      b_st.site = &m_emlrtRSI;
      repmat(&b_st, b_numAsters, b_otherAsters, r1);
      centerSepSQR_data = r1->data;
      loop_ub = otherAsters->size[1];
      i1 = r2->size[0] * r2->size[1];
      r2->size[0] = otherAsters->size[1];
      r2->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r2, i1, &bb_emlrtRTEI);
      r5 = r2->data;
      for (i1 = 0; i1 < 2; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          i3 = (int32_T)otherAsters_data[i2];
          if (otherAsters_data[i2] != i3) {
            emlrtIntegerCheckR2012b(otherAsters_data[i2], &e_emlrtDCI, &st);
          }
          if ((i3 < 1) || (i3 > b_asters)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, b_asters, &ab_emlrtBCI, &st);
          }
          r5[i2 + r2->size[0] * i1] =
              asters->centers->data[(i3 + asters->centers->size[0] * i1) - 1];
        }
      }
      if ((r1->size[0] != otherAsters->size[1]) &&
          ((r1->size[0] != 1) && (otherAsters->size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(r1->size[0], otherAsters->size[1],
                                    &b_emlrtECI, &st);
      }
      if (r1->size[0] == r2->size[0]) {
        i1 = r3->size[0] * r3->size[1];
        r3->size[0] = r1->size[0];
        r3->size[1] = 2;
        emxEnsureCapacity_real_T(&st, r3, i1, &db_emlrtRTEI);
        r6 = r3->data;
        loop_ub = r1->size[0] << 1;
        for (i1 = 0; i1 < loop_ub; i1++) {
          numNodesGuess = centerSepSQR_data[i1] - r5[i1];
          r6[i1] = numNodesGuess * numNodesGuess;
        }
        b_st.site = &m_emlrtRSI;
        sum(&b_st, r3, centerSepSQR);
        centerSepSQR_data = centerSepSQR->data;
      } else {
        b_st.site = &m_emlrtRSI;
        binary_expand_op(&b_st, centerSepSQR, m_emlrtRSI, r1, r2);
        centerSepSQR_data = centerSepSQR->data;
      }
      b_st.site = &l_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      d_st.site = &w_emlrtRSI;
      vectorUB = centerSepSQR->size[0] - 1;
      maxdimlen = 0;
      for (b_astralNum = 0; b_astralNum <= vectorUB; b_astralNum++) {
        if (centerSepSQR_data[b_astralNum] <= a * a) {
          maxdimlen++;
        }
      }
      i1 = r4->size[0];
      r4->size[0] = maxdimlen;
      emxEnsureCapacity_int32_T(&st, r4, i1, &eb_emlrtRTEI);
      r7 = r4->data;
      maxdimlen = 0;
      for (b_astralNum = 0; b_astralNum <= vectorUB; b_astralNum++) {
        if (centerSepSQR_data[b_astralNum] <= a * a) {
          r7[maxdimlen] = b_astralNum;
          maxdimlen++;
        }
      }
      maxdimlen = r4->size[0];
      for (i1 = 0; i1 < maxdimlen; i1++) {
        if (r7[i1] > otherAsters->size[1] - 1) {
          emlrtDynamicBoundsCheckR2012b(r7[i1], 0, otherAsters->size[1] - 1,
                                        &cb_emlrtBCI, &st);
        }
      }
      for (jdx = 0; jdx < maxdimlen; jdx++) {
        real_T b1;
        real_T b2;
        real_T denom;
        real_T denom_tmp;
        real_T t1;
        if (jdx + 1 > maxdimlen) {
          emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, maxdimlen, &x_emlrtBCI,
                                        &st);
        }
        /*  legacy code in these comments for readability */
        /*  A = [cosines(idx), - cosines(filOfJdx); */
        /*      sines(idx), - sines(filOfJdx)]; */
        /*  denom = det(A); */
        /*  b = 1/l * [centers(filOfJdx,1) - centers(idx,1); */
        /*      centers(filOfJdx,2) - centers(idx,2)]; */
        /*  t1 = det([b,A(:,2)]) / denom; */
        /*  t2 = det([A(:,1),b]) / denom; */
        if (((int32_T)((uint32_T)idx + 1U) < 1) ||
            ((int32_T)((uint32_T)idx + 1U) > numFil)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1,
                                        numFil, &eb_emlrtBCI, &st);
        }
        i1 = sines->size[0] * sines->size[1];
        i2 = (int32_T)otherAsters_data[r7[jdx]];
        if ((i2 < 1) || (i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &fb_emlrtBCI, &st);
        }
        if (((int32_T)((uint32_T)idx + 1U) < 1) ||
            ((int32_T)((uint32_T)idx + 1U) > i1)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1, i1,
                                        &gb_emlrtBCI, &st);
        }
        if (i2 > numFil) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, numFil, &hb_emlrtBCI, &st);
        }
        t1 = -sines_data[i2 - 1];
        denom_tmp = cosines_data[i2 - 1];
        denom = cosines_data[idx] * t1 + sines_data[idx] * denom_tmp;
        if (i2 > i) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ib_emlrtBCI, &st);
        }
        if (((int32_T)((uint32_T)idx + 1U) < 1) ||
            ((int32_T)((uint32_T)idx + 1U) > i)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1, i,
                                        &jb_emlrtBCI, &st);
        }
        b1 = (asters->centers->data[i2 - 1] - asters->centers->data[idx]) / l;
        if (((int32_T)((uint32_T)idx + 1U) < 1) ||
            ((int32_T)((uint32_T)idx + 1U) > i)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)((uint32_T)idx + 1U), 1, i,
                                        &kb_emlrtBCI, &st);
        }
        b2 = (asters->centers->data[(i2 + asters->centers->size[0]) - 1] -
              asters->centers->data[idx + asters->centers->size[0]]) /
             l;
        if (i2 > i1) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &lb_emlrtBCI, &st);
        }
        if (i2 > numFil) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, numFil, &mb_emlrtBCI, &st);
        }
        t1 = (b1 * t1 + b2 * denom_tmp) / denom;
        if ((idx + 1 < 1) || (idx + 1 > numFil)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numFil, &w_emlrtBCI, &st);
        }
        if ((idx + 1 < 1) || (idx + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &v_emlrtBCI, &st);
        }
        if ((muDoubleScalarAbs(t1 - 0.5) <= 0.5) &&
            (muDoubleScalarAbs((cosines_data[idx] * b2 - sines_data[idx] * b1) /
                                   denom -
                               0.5) <= 0.5)) {
          nodeCount++;
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &u_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > numFil)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numFil, &t_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > i)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &s_emlrtBCI, &st);
          }
          if ((idx + 1 < 1) || (idx + 1 > i1)) {
            emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &r_emlrtBCI, &st);
          }
          if (((int32_T)nodeCount < 1) ||
              ((int32_T)nodeCount > network->nodes->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)nodeCount, 1,
                                          network->nodes->size[0], &h_emlrtBCI,
                                          &st);
          }
          network->nodes->data[(int32_T)nodeCount - 1] =
              asters->centers->data[idx] + l * cosines_data[idx] * t1;
          network->nodes
              ->data[((int32_T)nodeCount + network->nodes->size[0]) - 1] =
              asters->centers->data[idx + asters->centers->size[0]] +
              l * sines_data[idx] * t1;
          if (((int32_T)nodeCount < 1) ||
              ((int32_T)nodeCount > crossings->filCross->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)nodeCount, 1,
                                          crossings->filCross->size[0],
                                          &d_emlrtBCI, &st);
          }
          crossings->filCross->data[(int32_T)nodeCount - 1] = (real_T)idx + 1.0;
          crossings->filCross
              ->data[((int32_T)nodeCount + crossings->filCross->size[0]) - 1] =
              otherAsters_data[r7[jdx]];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emxFree_int32_T(&st, &r4);
  } else if (asters->orients->size[1] >= 2) {
    real_T d;
    /*  routine for "Astral Mikado" networks */
    /*  loop only needs to run through the last filament on penultimate aster */
    d = ((real_T)asters->orients->size[0] - 1.0) *
        (real_T)asters->orients->size[1];
    i = (int32_T)d;
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)d,
                                  &e_emlrtRTEI, &st);
    if ((int32_T)d - 1 >= 0) {
      b_otherAsters[1] = 1.0;
      b_asters = asters->centers->size[0];
      a = 2.0 * l;
      c = a * a;
    }
    emxInit_boolean_T(&st, &tooFar, 1, &gb_emlrtRTEI);
    for (idx = 0; idx < i; idx++) {
      real_T b_numAsters_tmp;
      real_T c_numAsters_tmp;
      real_T y;
      y = muDoubleScalarFloor((((real_T)idx + 1.0) - 1.0) /
                              (real_T)b_astralNum);
      b_st.site = &k_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      if (c_numAsters < (y + 1.0) + 1.0) {
        otherAsters->size[0] = 1;
        otherAsters->size[1] = 0;
      } else if ((y + 1.0) + 1.0 == (y + 1.0) + 1.0) {
        i1 = otherAsters->size[0] * otherAsters->size[1];
        otherAsters->size[0] = 1;
        loop_ub = (int32_T)((real_T)c_numAsters - ((y + 1.0) + 1.0));
        otherAsters->size[1] = loop_ub + 1;
        emxEnsureCapacity_real_T(&c_st, otherAsters, i1, &y_emlrtRTEI);
        otherAsters_data = otherAsters->data;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          otherAsters_data[i1] = ((y + 1.0) + 1.0) + (real_T)i1;
        }
      } else {
        d_st.site = &y_emlrtRSI;
        eml_float_colon(&d_st, (y + 1.0) + 1.0, c_numAsters, otherAsters);
        otherAsters_data = otherAsters->data;
      }
      i1 = asters->centers->size[0];
      out = (((int32_T)(y + 1.0) < 1) ||
             ((int32_T)(y + 1.0) > asters->centers->size[0]));
      if (out) {
        emlrtDynamicBoundsCheckR2012b(
            (int32_T)(y + 1.0), 1, asters->centers->size[0], &q_emlrtBCI, &st);
      }
      b_numAsters_tmp = asters->centers->data[(int32_T)(y + 1.0) - 1];
      b_numAsters[0] = b_numAsters_tmp;
      c_numAsters_tmp =
          asters->centers
              ->data[((int32_T)(y + 1.0) + asters->centers->size[0]) - 1];
      b_numAsters[1] = c_numAsters_tmp;
      b_otherAsters[0] = otherAsters->size[1];
      b_st.site = &j_emlrtRSI;
      repmat(&b_st, b_numAsters, b_otherAsters, r1);
      centerSepSQR_data = r1->data;
      loop_ub = otherAsters->size[1];
      i2 = r2->size[0] * r2->size[1];
      r2->size[0] = otherAsters->size[1];
      r2->size[1] = 2;
      emxEnsureCapacity_real_T(&st, r2, i2, &cb_emlrtRTEI);
      r5 = r2->data;
      for (i2 = 0; i2 < 2; i2++) {
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (otherAsters_data[i3] !=
              (int32_T)muDoubleScalarFloor(otherAsters_data[i3])) {
            emlrtIntegerCheckR2012b(otherAsters_data[i3], &f_emlrtDCI, &st);
          }
          maxdimlen = (int32_T)otherAsters_data[i3];
          if ((maxdimlen < 1) || (maxdimlen > b_asters)) {
            emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, b_asters, &bb_emlrtBCI,
                                          &st);
          }
          r5[i3 + r2->size[0] * i2] =
              asters->centers
                  ->data[(maxdimlen + asters->centers->size[0] * i2) - 1];
        }
      }
      if ((r1->size[0] != otherAsters->size[1]) &&
          ((r1->size[0] != 1) && (otherAsters->size[1] != 1))) {
        emlrtDimSizeImpxCheckR2021b(r1->size[0], otherAsters->size[1],
                                    &emlrtECI, &st);
      }
      if (r1->size[0] == r2->size[0]) {
        i2 = r3->size[0] * r3->size[1];
        r3->size[0] = r1->size[0];
        r3->size[1] = 2;
        emxEnsureCapacity_real_T(&st, r3, i2, &db_emlrtRTEI);
        r6 = r3->data;
        loop_ub = r1->size[0] << 1;
        for (i2 = 0; i2 < loop_ub; i2++) {
          numNodesGuess = centerSepSQR_data[i2] - r5[i2];
          r6[i2] = numNodesGuess * numNodesGuess;
        }
        b_st.site = &j_emlrtRSI;
        sum(&b_st, r3, centerSepSQR);
        centerSepSQR_data = centerSepSQR->data;
      } else {
        b_st.site = &j_emlrtRSI;
        binary_expand_op(&b_st, centerSepSQR, j_emlrtRSI, r1, r2);
        centerSepSQR_data = centerSepSQR->data;
      }
      b_st.site = &i_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      d_st.site = &w_emlrtRSI;
      loop_ub = centerSepSQR->size[0];
      i2 = tooFar->size[0];
      tooFar->size[0] = centerSepSQR->size[0];
      emxEnsureCapacity_boolean_T(&st, tooFar, i2, &gb_emlrtRTEI);
      tooFar_data = tooFar->data;
      for (i2 = 0; i2 < loop_ub; i2++) {
        tooFar_data[i2] = (centerSepSQR_data[i2] > c);
      }
      /*  start second loop at first filament on the next aster */
      d = (y + 1.0) * (real_T)b_astralNum + 1.0;
      i2 = (int32_T)((real_T)numFil + (1.0 - d));
      emlrtForLoopVectorCheckR2021a(d, 1.0, numFil, mxDOUBLE_CLASS, i2,
                                    &d_emlrtRTEI, &st);
      for (jdx = 0; jdx < i2; jdx++) {
        real_T b_jdx;
        b_jdx = d + (real_T)jdx;
        a = muDoubleScalarFloor((b_jdx - 1.0) / (real_T)b_astralNum);
        /*  whichOtherAster finds corrent row in centerSepSQR, tooFar */
        i3 = (int32_T)((a + 1.0) - (y + 1.0));
        if ((i3 < 1) || (i3 > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub, &db_emlrtBCI, &st);
        }
        if (!tooFar_data[i3 - 1]) {
          real_T b1;
          real_T b2;
          real_T denom;
          real_T denom_tmp;
          real_T filSubIdx;
          real_T t1;
          /*  otherwise, check for intersection */
          numNodesGuess = b_mod((real_T)idx + 1.0, b_astralNum);
          filSubIdx =
              numNodesGuess + (real_T)(b_astralNum * (numNodesGuess == 0.0));
          numNodesGuess = b_mod(b_jdx, b_astralNum);
          numNodesGuess += (real_T)(b_astralNum * (numNodesGuess == 0.0));
          /*  legacy code in these comments for readability */
          /*  A = [cosines(asterIdx,filSubIdx), - cosines(asterJdx,filSubJdx);
           */
          /*      sines(asterIdx,filSubIdx), - sines(asterJdx,filSubJdx)]; */
          /*  denom = det(A); */
          /*  b = 1/l * [centers(asterJdx,1) - centers(asterIdx,1); */
          /*      centers(asterJdx,2) - centers(asterIdx,2)]; */
          /*  t1 = det([b,A(:,2)]) / denom; */
          /*  t2 = det([A(:,1),b]) / denom; */
          if (((int32_T)(y + 1.0) < 1) ||
              ((int32_T)(y + 1.0) > numAsters_tmp)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, numAsters_tmp,
                                          &nb_emlrtBCI, &st);
          }
          if (filSubIdx != (int32_T)muDoubleScalarFloor(filSubIdx)) {
            emlrtIntegerCheckR2012b(filSubIdx, &g_emlrtDCI, &st);
          }
          if (((int32_T)filSubIdx < 1) || ((int32_T)filSubIdx > vectorUB)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1, vectorUB,
                                          &ob_emlrtBCI, &st);
          }
          if (((int32_T)(a + 1.0) < 1) ||
              ((int32_T)(a + 1.0) > sines->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(a + 1.0), 1, sines->size[0],
                                          &pb_emlrtBCI, &st);
          }
          if (numNodesGuess != (int32_T)muDoubleScalarFloor(numNodesGuess)) {
            emlrtIntegerCheckR2012b(numNodesGuess, &h_emlrtDCI, &st);
          }
          if (((int32_T)numNodesGuess < 1) ||
              ((int32_T)numNodesGuess > sines->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)numNodesGuess, 1,
                                          sines->size[1], &qb_emlrtBCI, &st);
          }
          if (((int32_T)(y + 1.0) < 1) ||
              ((int32_T)(y + 1.0) > sines->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, sines->size[0],
                                          &rb_emlrtBCI, &st);
          }
          if (((int32_T)filSubIdx < 1) ||
              ((int32_T)filSubIdx > sines->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1, sines->size[1],
                                          &sb_emlrtBCI, &st);
          }
          if (((int32_T)(a + 1.0) < 1) ||
              ((int32_T)(a + 1.0) > numAsters_tmp)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(a + 1.0), 1, numAsters_tmp,
                                          &tb_emlrtBCI, &st);
          }
          if (((int32_T)numNodesGuess < 1) ||
              ((int32_T)numNodesGuess > vectorUB)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)numNodesGuess, 1, vectorUB,
                                          &ub_emlrtBCI, &st);
          }
          t1 = cosines_data[((int32_T)(a + 1.0) +
                             cosines->size[0] * ((int32_T)numNodesGuess - 1)) -
                            1];
          denom_tmp = sines_data[((int32_T)(y + 1.0) +
                                  sines->size[0] * ((int32_T)filSubIdx - 1)) -
                                 1];
          denom =
              cosines_data[((int32_T)(y + 1.0) +
                            cosines->size[0] * ((int32_T)filSubIdx - 1)) -
                           1] *
                  -sines_data[((int32_T)(a + 1.0) +
                               sines->size[0] * ((int32_T)numNodesGuess - 1)) -
                              1] +
              denom_tmp * t1;
          if (((int32_T)(a + 1.0) < 1) || ((int32_T)(a + 1.0) > i1)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(a + 1.0), 1, i1,
                                          &vb_emlrtBCI, &st);
          }
          if (((int32_T)(y + 1.0) < 1) || ((int32_T)(y + 1.0) > i1)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, i1,
                                          &wb_emlrtBCI, &st);
          }
          b1 = (asters->centers->data[(int32_T)(a + 1.0) - 1] -
                b_numAsters_tmp) /
               l;
          if (((int32_T)(y + 1.0) < 1) || ((int32_T)(y + 1.0) > i1)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, i1,
                                          &xb_emlrtBCI, &st);
          }
          b2 =
              (asters->centers
                   ->data[((int32_T)(a + 1.0) + asters->centers->size[0]) - 1] -
               c_numAsters_tmp) /
              l;
          if (((int32_T)(a + 1.0) < 1) ||
              ((int32_T)(a + 1.0) > sines->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(a + 1.0), 1, sines->size[0],
                                          &yb_emlrtBCI, &st);
          }
          if (((int32_T)numNodesGuess < 1) ||
              ((int32_T)numNodesGuess > sines->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)numNodesGuess, 1,
                                          sines->size[1], &ac_emlrtBCI, &st);
          }
          if (((int32_T)(a + 1.0) < 1) ||
              ((int32_T)(a + 1.0) > numAsters_tmp)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(a + 1.0), 1, numAsters_tmp,
                                          &bc_emlrtBCI, &st);
          }
          if (((int32_T)numNodesGuess < 1) ||
              ((int32_T)numNodesGuess > vectorUB)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)numNodesGuess, 1, vectorUB,
                                          &cc_emlrtBCI, &st);
          }
          t1 =
              (b1 *
                   -sines_data[((int32_T)(a + 1.0) +
                                sines->size[0] * ((int32_T)numNodesGuess - 1)) -
                               1] +
               b2 * t1) /
              denom;
          if (((int32_T)filSubIdx < 1) || ((int32_T)filSubIdx > vectorUB)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1, vectorUB,
                                          &p_emlrtBCI, &st);
          }
          if (((int32_T)(y + 1.0) < 1) ||
              ((int32_T)(y + 1.0) > sines->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, sines->size[0],
                                          &o_emlrtBCI, &st);
          }
          if (((int32_T)filSubIdx < 1) ||
              ((int32_T)filSubIdx > sines->size[1])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1, sines->size[1],
                                          &n_emlrtBCI, &st);
          }
          if (muDoubleScalarAbs(t1 - 0.5) <= 0.5) {
            numNodesGuess =
                cosines_data[((int32_T)(y + 1.0) +
                              cosines->size[0] * ((int32_T)filSubIdx - 1)) -
                             1];
            if (muDoubleScalarAbs(
                    (numNodesGuess * b2 - denom_tmp * b1) / denom - 0.5) <=
                0.5) {
              nodeCount++;
              if (((int32_T)(y + 1.0) < 1) ||
                  ((int32_T)(y + 1.0) > numAsters_tmp)) {
                emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1,
                                              numAsters_tmp, &m_emlrtBCI, &st);
              }
              if (((int32_T)filSubIdx < 1) || ((int32_T)filSubIdx > vectorUB)) {
                emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1, vectorUB,
                                              &l_emlrtBCI, &st);
              }
              if (((int32_T)(y + 1.0) < 1) || ((int32_T)(y + 1.0) > i1)) {
                emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1, i1,
                                              &k_emlrtBCI, &st);
              }
              if (((int32_T)(y + 1.0) < 1) ||
                  ((int32_T)(y + 1.0) > sines->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)(y + 1.0), 1,
                                              sines->size[0], &j_emlrtBCI, &st);
              }
              if (((int32_T)filSubIdx < 1) ||
                  ((int32_T)filSubIdx > sines->size[1])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)filSubIdx, 1,
                                              sines->size[1], &i_emlrtBCI, &st);
              }
              if (((int32_T)nodeCount < 1) ||
                  ((int32_T)nodeCount > network->nodes->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)nodeCount, 1,
                                              network->nodes->size[0],
                                              &g_emlrtBCI, &st);
              }
              network->nodes->data[(int32_T)nodeCount - 1] =
                  b_numAsters_tmp + l * numNodesGuess * t1;
              network->nodes
                  ->data[((int32_T)nodeCount + network->nodes->size[0]) - 1] =
                  c_numAsters_tmp + l * denom_tmp * t1;
              if (((int32_T)nodeCount < 1) ||
                  ((int32_T)nodeCount > crossings->filCross->size[0])) {
                emlrtDynamicBoundsCheckR2012b((int32_T)nodeCount, 1,
                                              crossings->filCross->size[0],
                                              &c_emlrtBCI, &st);
              }
              crossings->filCross->data[(int32_T)nodeCount - 1] =
                  (real_T)idx + 1.0;
              crossings->filCross
                  ->data[((int32_T)nodeCount + crossings->filCross->size[0]) -
                         1] = b_jdx;
            }
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emxFree_boolean_T(&st, &tooFar);
  }
  emxFree_real_T(&st, &r3);
  emxFree_real_T(&st, &r2);
  emxFree_real_T(&st, &r1);
  emxFree_real_T(&st, &centerSepSQR);
  emxFree_real_T(&st, &sines);
  emxFree_real_T(&st, &cosines);
  if ((int32_T)nodeCount == 0) {
    network->nodes->size[0] = 0;
    network->nodes->size[1] = 2;
    crossings->filCross->size[0] = 0;
    crossings->filCross->size[1] = 2;
  } else {
    if (network->nodes->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, network->nodes->size[0], &f_emlrtBCI,
                                    &st);
    }
    loop_ub = (int32_T)nodeCount;
    if (((int32_T)nodeCount < 1) ||
        ((int32_T)nodeCount > network->nodes->size[0])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)nodeCount, 1,
                                    network->nodes->size[0], &e_emlrtBCI, &st);
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        network->nodes->data[i1 + (int32_T)nodeCount * i] =
            network->nodes->data[i1 + network->nodes->size[0] * i];
      }
    }
    i = network->nodes->size[0] * network->nodes->size[1];
    network->nodes->size[0] = (int32_T)nodeCount;
    network->nodes->size[1] = 2;
    emxEnsureCapacity_real_T(&st, network->nodes, i, &v_emlrtRTEI);
    if (crossings->filCross->size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, crossings->filCross->size[0],
                                    &b_emlrtBCI, &st);
    }
    if (((int32_T)nodeCount < 1) ||
        ((int32_T)nodeCount > crossings->filCross->size[0])) {
      emlrtDynamicBoundsCheckR2012b(
          (int32_T)nodeCount, 1, crossings->filCross->size[0], &emlrtBCI, &st);
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        crossings->filCross->data[i1 + (int32_T)nodeCount * i] =
            crossings->filCross->data[i1 + crossings->filCross->size[0] * i];
      }
    }
    i = crossings->filCross->size[0] * crossings->filCross->size[1];
    crossings->filCross->size[0] = (int32_T)nodeCount;
    crossings->filCross->size[1] = 2;
    emxEnsureCapacity_real_T(&st, crossings->filCross, i, &ab_emlrtRTEI);
  }
  numNodesGuess = numAsters * astralNum;
  /*  aster idx 1 groups filaments 1,2,...,astralNum; and so on */
  if (muDoubleScalarIsNaN(numNodesGuess)) {
    i = otherAsters->size[0] * otherAsters->size[1];
    otherAsters->size[0] = 1;
    otherAsters->size[1] = 1;
    emxEnsureCapacity_real_T(sp, otherAsters, i, &x_emlrtRTEI);
    otherAsters_data = otherAsters->data;
    otherAsters_data[0] = rtNaN;
  } else if (numNodesGuess < 1.0) {
    otherAsters->size[0] = 1;
    otherAsters->size[1] = 0;
  } else {
    i = otherAsters->size[0] * otherAsters->size[1];
    otherAsters->size[0] = 1;
    otherAsters->size[1] = (int32_T)(numNodesGuess - 1.0) + 1;
    emxEnsureCapacity_real_T(sp, otherAsters, i, &x_emlrtRTEI);
    otherAsters_data = otherAsters->data;
    loop_ub = (int32_T)(numNodesGuess - 1.0);
    if ((int32_T)(numNodesGuess - 1.0) + 1 < 3200) {
      for (k = 0; k <= loop_ub; k++) {
        otherAsters_data[k] = (real_T)k + 1.0;
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp, omp_in_parallel());
      emlrtPushJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      generateAstralNetwork_numThreads =
          emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(),
                               omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(generateAstralNetwork_numThreads)

      for (k = 0; k <= loop_ub; k++) {
        otherAsters_data[k] = (real_T)k + 1.0;
      }
      emlrtPopJmpBuf((emlrtCTX)sp, &emlrtJBStack);
      emlrtExitParallelRegion((emlrtCTX)sp, omp_in_parallel());
    }
  }
  b_numAsters[0] = astralNum;
  b_numAsters[1] = numAsters;
  st.site = &d_emlrtRSI;
  maxdimlen = otherAsters->size[1];
  b_st.site = &jb_emlrtRSI;
  assertValidSizeArg(&b_st, b_numAsters);
  b_astralNum = (int32_T)astralNum;
  numAsters_tmp = (int32_T)numAsters;
  vectorUB = 1;
  if (otherAsters->size[1] > 1) {
    vectorUB = otherAsters->size[1];
  }
  maxdimlen = muIntScalarMax_sint32(maxdimlen, vectorUB);
  if ((int32_T)astralNum > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if ((int32_T)numAsters > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = ((int32_T)astralNum >= 0);
  if ((!out) || ((int32_T)numAsters < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if ((int32_T)astralNum * (int32_T)numAsters != otherAsters->size[1]) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  i = crossings->centerCross->size[0] * crossings->centerCross->size[1];
  crossings->centerCross->size[0] = (int32_T)numAsters;
  crossings->centerCross->size[1] = (int32_T)astralNum;
  emxEnsureCapacity_real_T(sp, crossings->centerCross, i, &fb_emlrtRTEI);
  for (i = 0; i < b_astralNum; i++) {
    for (i1 = 0; i1 < numAsters_tmp; i1++) {
      crossings->centerCross->data[i1 + crossings->centerCross->size[0] * i] =
          otherAsters_data[i + (int32_T)astralNum * i1];
    }
  }
  emxFree_real_T(sp, &otherAsters);
  if (nodesOnly) {
    /*  skip spring definition */
    network->augNodes->size[0] = 0;
    network->augNodes->size[1] = 2;
    network->springs->size[0] = 0;
    network->springs->size[1] = 4;
    network->ends->size[0] = 0;
    network->ends->size[1] = 2;
  } else {
    /*  full network generation */
    st.site = &e_emlrtRSI;
    defineSprings(&st, network->nodes, crossings->filCross, asters->centers, l,
                  astralNum, network->augNodes, network->springs,
                  network->ends);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (generateAstralNetwork.c) */
