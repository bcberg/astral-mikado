//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// generateAstralNetwork.cpp
//
// Code generation for function 'generateAstralNetwork'
//

// Include files
#include "generateAstralNetwork.h"
#include "assertValidSizeArg.h"
#include "colon.h"
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "generateAstralNetwork_types.h"
#include "indexShapeCheck.h"
#include "mod.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sum.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include "omp.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    25,                                                            // lineNo
    "generateAstralNetwork",                                       // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    26,                                                            // lineNo
    "generateAstralNetwork",                                       // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    28,                                                            // lineNo
    "generateAstralNetwork",                                       // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    29,                                                            // lineNo
    "generateAstralNetwork",                                       // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    34,                                                            // lineNo
    "generateAstralNetwork",                                       // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    110,                                                           // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    108,                                                           // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    107,                                                           // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    78,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    76,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    75,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    68,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    67,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    66,                                                            // lineNo
    "findNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    11,                                                           // lineNo
    "cos",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/cos.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    33,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    11,                                                           // lineNo
    "sin",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/sin.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    44,                                                               // lineNo
    "mpower",                                                         // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/matfun/mpower.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    28,                                                           // lineNo
    "colon",                                                      // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/colon.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    125,                                                          // lineNo
    "colon",                                                      // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/ops/colon.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    298,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    289,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    273,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    263,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo ob_emlrtRSI{
    255,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo pb_emlrtRSI{
    248,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo qb_emlrtRSI{
    235,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo rb_emlrtRSI{
    226,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo sb_emlrtRSI{
    162,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    175,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    177,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo vb_emlrtRSI{
    178,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo wb_emlrtRSI{
    181,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo xb_emlrtRSI{
    35,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    158,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo ac_emlrtRSI{
    138,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo bc_emlrtRSI{
    253,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo cc_emlrtRSI{
    254,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo dc_emlrtRSI{
    255,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo fc_emlrtRSI{
    70,                                                             // lineNo
    "dot",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    37,                                                              // lineNo
    "sort",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/sort.m" // pathName
};

static emlrtRSInfo jd_emlrtRSI{
    40,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtRTEInfo emlrtRTEI{
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo b_emlrtRTEI{
    79,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtBCInfo emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    143,                                                            // lineNo
    27,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    143,                                                            // lineNo
    25,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    133,                                                            // lineNo
    26,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    98,                                                             // lineNo
    26,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    142,                                                            // lineNo
    21,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    142,                                                            // lineNo
    19,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    132,                                                            // lineNo
    23,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    97,                                                             // lineNo
    23,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    131,                                                            // lineNo
    66,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    131,                                                            // lineNo
    57,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    131,                                                            // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    130,                                                            // lineNo
    68,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    130,                                                            // lineNo
    59,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    125,                                                            // lineNo
    47,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    125,                                                            // lineNo
    25,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    124,                                                            // lineNo
    54,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    124,                                                            // lineNo
    32,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo d_emlrtRTEI{
    112,                                                           // lineNo
    19,                                                            // colNo
    "findNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtECInfo emlrtECI{
    1,                                                             // nDims
    108,                                                           // lineNo
    29,                                                            // colNo
    "findNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo r_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    108,                                                            // lineNo
    44,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo e_emlrtRTEI{
    105,                                                           // lineNo
    15,                                                            // colNo
    "findNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo s_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    96,                                                             // lineNo
    52,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    96,                                                             // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    95,                                                             // lineNo
    54,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    95,                                                             // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    90,                                                             // lineNo
    47,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    90,                                                             // lineNo
    25,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    89,                                                             // lineNo
    54,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    89,                                                             // lineNo
    32,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    85,                                                             // lineNo
    36,                                                             // colNo
    "closeEnough",                                                  // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo b_emlrtECI{
    1,                                                             // nDims
    76,                                                            // lineNo
    29,                                                            // colNo
    "findNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo cb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    76,                                                             // lineNo
    44,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo emlrtDCI{
    69,                                                             // lineNo
    15,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    70,                                                             // lineNo
    18,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    69,                                                             // lineNo
    1,                                                              // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    70,                                                             // lineNo
    1,                                                              // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    77,                                                             // lineNo
    21,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    77,                                                             // lineNo
    21,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    109,                                                            // lineNo
    47,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    109,                                                            // lineNo
    47,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    78,                                                             // lineNo
    33,                                                             // colNo
    "otherFils",                                                    // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    115,                                                            // lineNo
    23,                                                             // colNo
    "tooFar",                                                       // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo hb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    121,                                                            // lineNo
    18,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    121,                                                            // lineNo
    18,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    121,                                                            // lineNo
    47,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    121,                                                            // lineNo
    47,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    122,                                                            // lineNo
    17,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    122,                                                            // lineNo
    44,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    86,                                                             // lineNo
    18,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    86,                                                             // lineNo
    32,                                                             // colNo
    "cosines",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    87,                                                             // lineNo
    17,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ob_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    87,                                                             // lineNo
    29,                                                             // colNo
    "sines",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo pb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    276,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo qb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    302,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo rb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    256,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo sb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    255,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo tb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    236,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ub_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    235,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo vb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    230,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo wb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    267,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    219,                                                            // lineNo
    1,                                                              // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    218,                                                            // lineNo
    1,                                                              // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    219,                                                            // lineNo
    14,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    4                                                               // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    219,                                                            // lineNo
    14,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    218,                                                            // lineNo
    17,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo xb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    309,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo yb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    309,                                                            // lineNo
    23,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                                                            // nDims
    275,                                                           // lineNo
    13,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo ac_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    275,                                                            // lineNo
    21,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo bc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    297,                                                            // lineNo
    30,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo cc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    288,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo dc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    287,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ec_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    286,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo fc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    285,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo gc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    279,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo hc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    272,                                                            // lineNo
    32,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ic_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    271,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo i_emlrtRTEI{
    262,                                                           // lineNo
    15,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo jc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    254,                                                            // lineNo
    30,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo kc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    247,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo lc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    246,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo mc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    245,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo nc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    244,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo oc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    239,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo pc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    234,                                                            // lineNo
    32,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo qc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    233,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo j_emlrtRTEI{
    225,                                                           // lineNo
    15,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtBCInfo rc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    300,                                                            // lineNo
    21,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo sc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    251,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo tc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    292,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo uc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    173,                                                            // lineNo
    14,                                                             // colNo
    "centers",                                                      // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo d_emlrtECI{
    1,                                                             // nDims
    177,                                                           // lineNo
    16,                                                            // colNo
    "sortNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    239,                                                           // lineNo
    1,                                                             // colNo
    "find_first_nonempty_triples",                                 // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    12,                                                             // lineNo
    23,                                                             // colNo
    "dot",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pName
};

static emlrtBCInfo vc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    171,                                                            // lineNo
    25,                                                             // colNo
    "nodes",                                                        // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo wc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    182,                                                            // lineNo
    27,                                                             // colNo
    "nodesOnFil",                                                   // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo p_emlrtRTEI{
    25,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    26,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    28,                                                            // lineNo
    46,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    66,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    69,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    70,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    107,                                                           // lineNo
    9,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    109,                                                           // lineNo
    39,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo
    x_emlrtRTEI{
        31,            // lineNo
        30,            // colNo
        "unsafeSxfun", // fName
        "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" // pName
    };

static emlrtRTEInfo y_emlrtRTEI{
    110,                                                           // lineNo
    9,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    75,                                                            // lineNo
    9,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    77,                                                            // lineNo
    13,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    1,                                                             // lineNo
    39,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    142,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    143,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    139,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    140,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    34,                                                            // lineNo
    43,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    34,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    218,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    219,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    221,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    261,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    224,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    309,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ub_emlrtRTEI{
    307,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo vb_emlrtRTEI{
    162,                                                           // lineNo
    23,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    195,                                                           // lineNo
    24,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    253,                                                           // lineNo
    5,                                                             // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo yb_emlrtRTEI{
    247,                                                           // lineNo
    17,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo ac_emlrtRTEI{
    133,                                                           // lineNo
    13,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo bc_emlrtRTEI{
    36,                                                            // lineNo
    5,                                                             // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    171,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    177,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    60,                                                             // lineNo
    20,                                                             // colNo
    "dot",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pName
};

static emlrtRTEInfo fc_emlrtRTEI{
    182,                                                           // lineNo
    16,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo gc_emlrtRTEI{
    182,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    167,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    164,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    76,                                                            // lineNo
    29,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

// Function Declarations
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const emlrtRSInfo in2,
                             const coder::array<real_T, 2U> &in4,
                             const coder::array<real_T, 2U> &in5);

static void defineSprings(const emlrtStack &sp,
                          const coder::array<real_T, 2U> &nodes,
                          const coder::array<real_T, 2U> &filCross,
                          const coder::array<real_T, 2U> &centers, real_T l,
                          real_T astralNum, coder::array<real_T, 2U> &augNodes,
                          coder::array<real_T, 2U> &springs,
                          coder::array<real_T, 2U> &ends);

static void sortNodes(const emlrtStack &sp, real_T filIdx,
                      const coder::array<real_T, 2U> &nodes,
                      const coder::array<real_T, 2U> &filCross,
                      const coder::array<real_T, 2U> &centers, real_T astralNum,
                      coder::array<real_T, 2U> &nodeOrdering);

// Function Definitions
static void binary_expand_op(const emlrtStack &sp,
                             coder::array<real_T, 1U> &in1,
                             const emlrtRSInfo in2,
                             const coder::array<real_T, 2U> &in4,
                             const coder::array<real_T, 2U> &in5)
{
  coder::array<real_T, 2U> b_in4;
  coder::array<real_T, 2U> r;
  emlrtStack st;
  real_T b_varargin_1;
  int32_T b_loop_ub;
  int32_T binary_expand_op_numThreads;
  int32_T i;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  b_in4.set_size(&oc_emlrtRTEI, &sp, loop_ub, 2);
  stride_0_0 = (in4.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  b_loop_ub = loop_ub << 1;
  i = (b_loop_ub < 3200);
  if (i) {
    for (int32_T i1{0}; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in4[i2 + b_in4.size(0) * i1] =
            in4[i2 * stride_0_0 + in4.size(0) * i1] -
            in5[i2 * stride_1_0 + in5.size(0) * i1];
      }
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_numThreads) private(i2)

    for (int32_T i1 = 0; i1 < 2; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in4[i2 + b_in4.size(0) * i1] =
            in4[i2 * stride_0_0 + in4.size(0) * i1] -
            in5[i2 * stride_1_0 + in5.size(0) * i1];
      }
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  r.set_size(&x_emlrtRTEI, &sp, loop_ub, 2);
  if (i) {
    for (int32_T i1{0}; i1 < b_loop_ub; i1++) {
      real_T varargin_1;
      varargin_1 = b_in4[i1];
      r[i1] = varargin_1 * varargin_1;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    binary_expand_op_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(binary_expand_op_numThreads) private(     \
        b_varargin_1)

    for (int32_T i1 = 0; i1 < b_loop_ub; i1++) {
      b_varargin_1 = b_in4[i1];
      r[i1] = b_varargin_1 * b_varargin_1;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  st.site = const_cast<emlrtRSInfo *>(&in2);
  coder::sum(st, r, in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void defineSprings(const emlrtStack &sp,
                          const coder::array<real_T, 2U> &nodes,
                          const coder::array<real_T, 2U> &filCross,
                          const coder::array<real_T, 2U> &centers, real_T l,
                          real_T astralNum, coder::array<real_T, 2U> &augNodes,
                          coder::array<real_T, 2U> &springs,
                          coder::array<real_T, 2U> &ends)
{
  coder::array<real_T, 2U> thisOrder;
  emlrtStack st;
  real_T numFil;
  real_T numSpringsGuess;
  int32_T iv[2];
  int32_T newSpring_size[2];
  int32_T defineSprings_numThreads;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T numAsters;
  int32_T numAsters_tmp;
  uint32_T springCount;
  st.prev = &sp;
  st.tls = sp.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  DEFINESPRINGS partitions filaments into node-bounded sub-segments
  //  (springs) and dangling ends
  //    Inputs:
  //        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
  //        crossings (EXCLUDING astral centers)
  //        filCross (numNodes x 2 double): list of pairs of filament indices
  //        corresponding to the filaments that cross at a particular node;
  //        listed so that filCross(idx,1) < filCross(idx,2)
  //        centers (numAsters x 2 double): (x,y) coordinates of astral centers
  //        l (scalar): length of individual filament
  //        astralNum (scalar): number of filaments per aster
  //    Outputs:
  //        augNodes (numAsters+numNodes x 2 double)**: conditionally augmented
  //        node list; if astralNum >= 2, rows 1:numAsters contain (x,y)
  //        coordinates of astral centers, remaining rows contain (x,y)
  //        coordinates of inter-aster nodes
  //        **NOTE: if astralNum == 1, augNodes is the same as nodes (centers
  //        are fictitious), so its size is (numNodes x 2)
  //        springs (numSprings x 4 double): descriptions of segments bounded
  //        by nodes at each end, each row has the structure
  //            (1) lesser augNode index at one end of the spring
  //            (2) greater augNode index at the other end of the spring
  //            (3) filament index (which filament is the spring on)
  //            (4) the original distance between the nodes
  //        ends (numFil x 2 double): lengths of segments on the ends of each
  //        filament. ends(:,2) lists the "right" dangling ends, distal to the
  //        astral center. ends(:,1) lists the "left" dangling ends, proximal
  //        to the astral center; these are all 0 if astralNum >= 2.
  numAsters_tmp = centers.size(0);
  numAsters = centers.size(0);
  numFil = static_cast<real_T>(centers.size(0)) * astralNum;
  numSpringsGuess = 10.0 * static_cast<real_T>(nodes.size(0));
  if (numSpringsGuess != static_cast<int32_T>(numSpringsGuess)) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &n_emlrtDCI, (emlrtConstCTX)&sp);
  }
  springs.set_size(&ob_emlrtRTEI, &sp, static_cast<int32_T>(numSpringsGuess),
                   4);
  if (numSpringsGuess != static_cast<int32_T>(numSpringsGuess)) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &k_emlrtDCI, (emlrtConstCTX)&sp);
  }
  loop_ub = static_cast<int32_T>(numSpringsGuess) << 2;
  if (static_cast<int32_T>(loop_ub < 3200)) {
    for (int32_T i{0}; i < loop_ub; i++) {
      springs[i] = 0.0;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    defineSprings_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

    for (int32_T i = 0; i < loop_ub; i++) {
      springs[i] = 0.0;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  if (!(numFil >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numFil, &l_emlrtDCI, (emlrtConstCTX)&sp);
  }
  i1 = static_cast<int32_T>(muDoubleScalarFloor(numFil));
  if (numFil != i1) {
    emlrtIntegerCheckR2012b(numFil, &m_emlrtDCI, (emlrtConstCTX)&sp);
  }
  i2 = static_cast<int32_T>(numFil);
  ends.set_size(&pb_emlrtRTEI, &sp, i2, 2);
  if (i2 != i1) {
    emlrtIntegerCheckR2012b(numFil, &j_emlrtDCI, (emlrtConstCTX)&sp);
  }
  loop_ub = i2 << 1;
  if (static_cast<int32_T>(loop_ub < 3200)) {
    for (int32_T i{0}; i < loop_ub; i++) {
      ends[i] = 0.0;
    }
  } else {
    emlrtEnterParallelRegion((emlrtCTX)&sp,
                             static_cast<boolean_T>(omp_in_parallel()));
    defineSprings_numThreads =
        emlrtAllocRegionTLSs(sp.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

    for (int32_T i = 0; i < loop_ub; i++) {
      ends[i] = 0.0;
    }
    emlrtExitParallelRegion((emlrtCTX)&sp,
                            static_cast<boolean_T>(omp_in_parallel()));
  }
  springCount = 0U;
  augNodes.set_size(&qb_emlrtRTEI, &sp, 0, 2);
  if (astralNum == 1.0) {
    //  routine for "Classical Mikado" networks
    numAsters = nodes.size(0);
    augNodes.set_size(&sb_emlrtRTEI, &sp, nodes.size(0), 2);
    loop_ub = nodes.size(0) << 1;
    if (static_cast<int32_T>(loop_ub < 3200)) {
      for (int32_T i{0}; i < loop_ub; i++) {
        augNodes[i] = nodes[i];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      defineSprings_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads)

      for (int32_T i = 0; i < loop_ub; i++) {
        augNodes[i] = nodes[i];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    //  centers are fictitious
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(numFil), &j_emlrtRTEI,
                                  (emlrtConstCTX)&sp);
    for (int32_T idx{0}; idx < i2; idx++) {
      st.site = &rb_emlrtRSI;
      sortNodes(st, static_cast<real_T>(idx) + 1.0, nodes, filCross, centers,
                1.0, thisOrder);
      if ((thisOrder.size(0) == 0) || (thisOrder.size(1) == 0)) {
        //  0 nodes = filament doesn't touch any other asters!
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &vb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l;
        //  treat unused filament as "right" dangling end
      } else if (thisOrder.size(0) == 1) {
        real_T y[2];
        //  1 node + astralNum == 1 -> two dangling ends
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &qc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > numAsters)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        numAsters, &pc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[idx];
        y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[idx + centers.size(0)];
        y[1] = numFil * numFil;
        numFil = coder::sumColumnB(y);
        st.site = &qb_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &ub_emlrtBCI, &st);
        }
        ends[idx] = muDoubleScalarSqrt(numFil);
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &tb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l - ends[idx + ends.size(0)];
      } else {
        real_T y[2];
        real_T totSpringLength;
        int32_T n;
        //  >=2 nodes = there are certainly springs along this filament
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &oc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        totSpringLength = 0.0;
        //  pair adjacent nodes to form springs
        n = thisOrder.size(0) - 2;
        loop_ub = thisOrder.size(0);
        for (int32_T jdx{0}; jdx <= n; jdx++) {
          real_T springLength;
          int32_T i4;
          springCount++;
          if (jdx + 1 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, loop_ub, &nc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i1 = static_cast<int32_T>(thisOrder[jdx]);
          if ((i1 < 1) || (i1 > numAsters)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, numAsters, &mc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (jdx + 2 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, loop_ub, &lc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i4 = static_cast<int32_T>(thisOrder[jdx + 1]);
          if ((i4 < 1) || (i4 > numAsters)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, numAsters, &kc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          numFil = nodes[i1 - 1] - nodes[i4 - 1];
          y[0] = numFil * numFil;
          numFil =
              nodes[(i1 + nodes.size(0)) - 1] - nodes[(i4 + nodes.size(0)) - 1];
          y[1] = numFil * numFil;
          springLength = coder::sumColumnB(y);
          st.site = &pb_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          springLength = muDoubleScalarSqrt(springLength);
          numSpringsGuess = thisOrder[jdx + 1];
          if ((thisOrder[jdx] > numSpringsGuess) ||
              (muDoubleScalarIsNaN(thisOrder[jdx]) &&
               (!muDoubleScalarIsNaN(numSpringsGuess)))) {
            numFil = thisOrder[jdx + 1];
          } else {
            numFil = thisOrder[jdx];
          }
          if ((!(thisOrder[jdx] < numSpringsGuess)) &&
              ((!muDoubleScalarIsNaN(thisOrder[jdx])) ||
               muDoubleScalarIsNaN(numSpringsGuess))) {
            numSpringsGuess = thisOrder[jdx];
          }
          if ((static_cast<int32_T>(springCount) < 1) ||
              (static_cast<int32_T>(springCount) > springs.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                          springs.size(0), &sc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          springs[static_cast<int32_T>(springCount) - 1] = numFil;
          springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
              numSpringsGuess;
          springs[(static_cast<int32_T>(springCount) + springs.size(0) * 2) -
                  1] = static_cast<real_T>(idx) + 1.0;
          springs[(static_cast<int32_T>(springCount) + springs.size(0) * 3) -
                  1] = springLength;
          totSpringLength += springLength;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
          }
        }
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > numAsters)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        numAsters, &jc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[idx];
        y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[idx + centers.size(0)];
        y[1] = numFil * numFil;
        numFil = coder::sumColumnB(y);
        st.site = &ob_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &sb_emlrtBCI, &st);
        }
        ends[idx] = muDoubleScalarSqrt(numFil);
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &rb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = (l - totSpringLength) - ends[idx];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
      }
    }
  } else if (astralNum >= 2.0) {
    int32_T loop_ub_tmp;
    //  routine for "Astral Mikado" networks
    augNodes.set_size(&rb_emlrtRTEI, &sp, centers.size(0) + nodes.size(0), 2);
    loop_ub_tmp = nodes.size(0);
    loop_ub = nodes.size(0);
    if (static_cast<int32_T>(
            (muIntScalarMax_sint32(numAsters_tmp, loop_ub_tmp) << 1) < 3200)) {
      for (int32_T i{0}; i < 2; i++) {
        for (i3 = 0; i3 < numAsters_tmp; i3++) {
          augNodes[i3 + augNodes.size(0) * i] =
              centers[i3 + centers.size(0) * i];
        }
        for (i3 = 0; i3 < loop_ub_tmp; i3++) {
          augNodes[(i3 + centers.size(0)) + augNodes.size(0) * i] =
              nodes[i3 + nodes.size(0) * i];
        }
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      defineSprings_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(defineSprings_numThreads) private(i3)

      for (int32_T i = 0; i < 2; i++) {
        for (i3 = 0; i3 < numAsters_tmp; i3++) {
          augNodes[i3 + augNodes.size(0) * i] =
              centers[i3 + centers.size(0) * i];
        }
        for (i3 = 0; i3 < loop_ub; i3++) {
          augNodes[(i3 + centers.size(0)) + augNodes.size(0) * i] =
              nodes[i3 + nodes.size(0) * i];
        }
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(numFil), &i_emlrtRTEI,
                                  (emlrtConstCTX)&sp);
    for (int32_T idx{0}; idx < i2; idx++) {
      st.site = &nb_emlrtRSI;
      sortNodes(st, static_cast<real_T>(idx) + 1.0, nodes, filCross, centers,
                astralNum, thisOrder);
      loop_ub = static_cast<int32_T>(muDoubleScalarFloor(
          ((static_cast<real_T>(idx) + 1.0) - 1.0) / astralNum));
      if ((thisOrder.size(0) == 0) || (thisOrder.size(1) == 0)) {
        //  0 nodes = filament doesn't touch any other asters!
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &wb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l;
        //  treat unused filament as "right" dangling end
      } else if (thisOrder.size(0) == 1) {
        real_T y[2];
        real_T springLength;
        //  1 node + astralNum >=2 -> spring between astral center & node
        springCount++;
        if (loop_ub + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, numAsters_tmp,
                                        &ic_emlrtBCI, (emlrtConstCTX)&sp);
        }
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > loop_ub_tmp)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        loop_ub_tmp, &hc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil =
            nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[loop_ub];
        y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[loop_ub + centers.size(0)];
        y[1] = numFil * numFil;
        springLength = coder::sumColumnB(y);
        st.site = &mb_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        thisOrder[0] = static_cast<real_T>(numAsters) + thisOrder[0];
        newSpring_size[0] = 1;
        newSpring_size[1] = 4;
        numFil = thisOrder[0];
        if ((static_cast<int32_T>(springCount) < 1) ||
            (static_cast<int32_T>(springCount) > springs.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                        springs.size(0), &ac_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        iv[0] = 1;
        iv[1] = 4;
        emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &newSpring_size[0], 2,
                                      &c_emlrtECI, (emlrtCTX)&sp);
        springs[static_cast<int32_T>(springCount) - 1] = loop_ub + 1;
        springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
            numFil;
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 2) - 1] =
            idx + 1;
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 3) - 1] =
            springLength;
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &pb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l - springLength;
      } else {
        real_T y[2];
        real_T springLength;
        real_T totSpringLength;
        int32_T n;
        //  >=2 nodes = there are certainly springs along this filament
        if (loop_ub + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, numAsters_tmp,
                                        &gc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        totSpringLength = 0.0;
        //  like "Classical", but proximal segment to center is spring
        //  also need to account for augmented node indices
        n = thisOrder.size(0) - 2;
        for (int32_T jdx{0}; jdx <= n; jdx++) {
          int32_T i4;
          springCount++;
          if (jdx + 1 > thisOrder.size(0)) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, thisOrder.size(0),
                                          &fc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i1 = static_cast<int32_T>(thisOrder[jdx]);
          if ((i1 < 1) || (i1 > loop_ub_tmp)) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub_tmp, &ec_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (jdx + 2 > thisOrder.size(0)) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, thisOrder.size(0),
                                          &dc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i4 = static_cast<int32_T>(thisOrder[jdx + 1]);
          if ((i4 < 1) || (i4 > loop_ub_tmp)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, loop_ub_tmp, &cc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          numFil = nodes[i1 - 1] - nodes[i4 - 1];
          y[0] = numFil * numFil;
          numFil =
              nodes[(i1 + nodes.size(0)) - 1] - nodes[(i4 + nodes.size(0)) - 1];
          y[1] = numFil * numFil;
          springLength = coder::sumColumnB(y);
          st.site = &kb_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
          }
          springLength = muDoubleScalarSqrt(springLength);
          numFil = thisOrder[jdx + 1];
          if ((!(thisOrder[jdx] > numFil)) &&
              ((!muDoubleScalarIsNaN(thisOrder[jdx])) ||
               muDoubleScalarIsNaN(numFil))) {
            numFil = thisOrder[jdx];
          }
          numSpringsGuess = thisOrder[jdx + 1];
          if ((!(thisOrder[jdx] < numSpringsGuess)) &&
              ((!muDoubleScalarIsNaN(thisOrder[jdx])) ||
               muDoubleScalarIsNaN(numSpringsGuess))) {
            numSpringsGuess = thisOrder[jdx];
          }
          if ((static_cast<int32_T>(springCount) < 1) ||
              (static_cast<int32_T>(springCount) > springs.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                          springs.size(0), &tc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          springs[static_cast<int32_T>(springCount) - 1] =
              static_cast<real_T>(numAsters) + numFil;
          springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
              static_cast<real_T>(numAsters) + numSpringsGuess;
          springs[(static_cast<int32_T>(springCount) + springs.size(0) * 2) -
                  1] = static_cast<real_T>(idx) + 1.0;
          springs[(static_cast<int32_T>(springCount) + springs.size(0) * 3) -
                  1] = springLength;
          totSpringLength += springLength;
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
          }
        }
        //  recording proximal segment as spring
        springCount++;
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > loop_ub_tmp)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        loop_ub_tmp, &bc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil =
            nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[loop_ub];
        y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[loop_ub + centers.size(0)];
        y[1] = numFil * numFil;
        springLength = coder::sumColumnB(y);
        st.site = &jb_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        if ((static_cast<int32_T>(springCount) < 1) ||
            (static_cast<int32_T>(springCount) > springs.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                        springs.size(0), &rc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        springs[static_cast<int32_T>(springCount) - 1] =
            static_cast<real_T>(loop_ub) + 1.0;
        springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
            static_cast<real_T>(numAsters) + thisOrder[0];
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 2) - 1] =
            static_cast<real_T>(idx) + 1.0;
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 3) - 1] =
            springLength;
        totSpringLength += springLength;
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &qb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l - totSpringLength;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
      }
    }
  }
  if (static_cast<int32_T>(springCount) == 0) {
    springs.set_size(&ub_emlrtRTEI, &sp, 0, 4);
  } else {
    if (springs.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, springs.size(0), &yb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    loop_ub = static_cast<int32_T>(springCount);
    if ((static_cast<int32_T>(springCount) < 1) ||
        (static_cast<int32_T>(springCount) > springs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                    springs.size(0), &xb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    for (i1 = 0; i1 < 4; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        springs[i2 + static_cast<int32_T>(springCount) * i1] =
            springs[i2 + springs.size(0) * i1];
      }
    }
    springs.set_size(&tb_emlrtRTEI, &sp, static_cast<int32_T>(springCount), 4);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void sortNodes(const emlrtStack &sp, real_T filIdx,
                      const coder::array<real_T, 2U> &nodes,
                      const coder::array<real_T, 2U> &filCross,
                      const coder::array<real_T, 2U> &centers, real_T astralNum,
                      coder::array<real_T, 2U> &nodeOrdering)
{
  __m128d r;
  __m128d r1;
  coder::array<real_T, 2U> a;
  coder::array<real_T, 2U> nodeCoordsOnFil;
  coder::array<real_T, 1U> dotProducts;
  coder::array<int32_T, 1U> i_tmp;
  coder::array<int32_T, 1U> nodesOnFil;
  coder::array<boolean_T, 2U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T a_tmp[2];
  real_T b_nodesOnFil[2];
  real_T y[2];
  real_T d;
  real_T d1;
  real_T d2;
  real_T y_tmp;
  int32_T iv[2];
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T sortNodes_numThreads;
  boolean_T emlrtHadParallelError{false};
  boolean_T exitg1;
  boolean_T guard1;
  boolean_T p;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  //  SORTNODES orders the node indices along a filament
  //    Inputs:
  //        filIdx (scalar): filament index (see note in findNodes for details)
  //        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
  //        crossings (EXCLUDING astral centers)
  //        filCross (numNodes x 2 double): list of pairs of filament indices
  //        corresponding to the filaments that cross at a particular node;
  //        listed so that filCross(idx,1) < filCross(idx,2)
  //        centers (numAsters x 2 double): (x,y) coordinates of astral centers
  //        astralNum (scalar): number of filaments per aster
  //    Outputs:
  //        nodeOrdering (double vector): sorted list of node indices appearing
  //        on the specified filament. First element is the node closest to the
  //        astral center. If there are no nodes on this filament, returns [].
  st.site = &sb_emlrtRSI;
  x.set_size(&vb_emlrtRTEI, &st, filCross.size(0), 2);
  loop_ub_tmp = filCross.size(0) << 1;
  if (static_cast<int32_T>(loop_ub_tmp < 3200)) {
    for (i = 0; i < loop_ub_tmp; i++) {
      x[i] = (filCross[i] == filIdx);
    }
  } else {
    emlrtEnterParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
    sortNodes_numThreads =
        emlrtAllocRegionTLSs(st.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

    for (i = 0; i < loop_ub_tmp; i++) {
      x[i] = (filCross[i] == filIdx);
    }
    emlrtExitParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
  }
  b_st.site = &xb_emlrtRSI;
  if (loop_ub_tmp == 0) {
    i_tmp.set_size(&ac_emlrtRTEI, &b_st, 0);
  } else {
    c_st.site = &ac_emlrtRSI;
    idx = 0;
    i_tmp.set_size(&wb_emlrtRTEI, &c_st, loop_ub_tmp);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      guard1 = false;
      if (x[(ii + x.size(0) * (jj - 1)) - 1]) {
        idx++;
        i_tmp[idx - 1] = ii;
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
        if (ii > x.size(0)) {
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
        i_tmp.set_size(&yb_emlrtRTEI, &c_st, 0);
      }
    } else {
      if (idx < 1) {
        jj = 0;
      } else {
        jj = idx;
      }
      iv[0] = 1;
      iv[1] = jj;
      d_st.site = &bc_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, i_tmp.size(0), iv);
      i_tmp.set_size(&xb_emlrtRTEI, &c_st, jj);
      iv[0] = 1;
      iv[1] = jj;
      d_st.site = &cc_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, loop_ub_tmp, iv);
      iv[0] = 1;
      iv[1] = jj;
      d_st.site = &dc_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, loop_ub_tmp, iv);
    }
  }
  if ((x.size(0) == 1) && (i_tmp.size(0) != 1)) {
    c_st.site = &yb_emlrtRSI;
    coder::internal::warning(c_st);
  }
  loop_ub = i_tmp.size(0);
  nodesOnFil.set_size(&bc_emlrtRTEI, &st, i_tmp.size(0));
  loop_ub_tmp = i_tmp.size(0);
  if (static_cast<int32_T>(i_tmp.size(0) < 3200)) {
    for (i = 0; i < loop_ub; i++) {
      nodesOnFil[i] = i_tmp[i];
    }
  } else {
    emlrtEnterParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
    sortNodes_numThreads =
        emlrtAllocRegionTLSs(st.tls, static_cast<boolean_T>(omp_in_parallel()),
                             omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

    for (i = 0; i < loop_ub_tmp; i++) {
      nodesOnFil[i] = i_tmp[i];
    }
    emlrtExitParallelRegion(&st, static_cast<boolean_T>(omp_in_parallel()));
  }
  if (nodesOnFil.size(0) == 0) {
    nodeOrdering.set_size(&ic_emlrtRTEI, &sp, 0, 0);
  } else if (nodesOnFil.size(0) == 1) {
    nodeOrdering.set_size(&hc_emlrtRTEI, &sp, 1, 1);
    nodeOrdering[0] = nodesOnFil[0];
  } else {
    idx = nodes.size(0);
    nodeCoordsOnFil.set_size(&cc_emlrtRTEI, &sp, loop_ub, 2);
    if (static_cast<int32_T>((nodesOnFil.size(0) << 1) < 3200)) {
      for (i = 0; i < 2; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          if ((nodesOnFil[i1] < 1) || (nodesOnFil[i1] > idx)) {
            emlrtDynamicBoundsCheckR2012b(nodesOnFil[i1], 1, idx, &vc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          nodeCoordsOnFil[i1 + nodeCoordsOnFil.size(0) * i] =
              nodes[(nodesOnFil[i1] + nodes.size(0) * i) - 1];
        }
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      sortNodes_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(sortNodes_numThreads) private(i1, e_st)       \
    firstprivate(emlrtHadParallelError)
      {
        try {
          e_st.prev = &sp;
          e_st.tls = emlrtAllocTLS((emlrtCTX)&sp, omp_get_thread_num());
          e_st.site = nullptr;
        } catch (...) {
          emlrtHadParallelError = true;
        }
#pragma omp for nowait
        for (i = 0; i < 2; i++) {
          if (emlrtHadParallelError) {
            continue;
          }
          try {
            for (i1 = 0; i1 < loop_ub; i1++) {
              if ((nodesOnFil[i1] < 1) || (nodesOnFil[i1] > idx)) {
                emlrtDynamicBoundsCheckR2012b(nodesOnFil[i1], 1, idx,
                                              &vc_emlrtBCI, &e_st);
              }
              nodeCoordsOnFil[i1 + nodeCoordsOnFil.size(0) * i] =
                  nodes[(nodesOnFil[i1] + nodes.size(0) * i) - 1];
            }
          } catch (...) {
            emlrtHadParallelError = true;
          }
        }
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    y_tmp = muDoubleScalarFloor((filIdx - 1.0) / astralNum);
    if ((static_cast<int32_T>(y_tmp + 1.0) < 1) ||
        (static_cast<int32_T>(y_tmp + 1.0) > centers.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y_tmp + 1.0), 1,
                                    centers.size(0), &uc_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    d = centers[static_cast<int32_T>(y_tmp + 1.0) - 1];
    d1 = nodeCoordsOnFil[0] - d;
    a_tmp[0] = d1;
    y[0] = d1 * d1;
    d2 = centers[(static_cast<int32_T>(y_tmp + 1.0) + centers.size(0)) - 1];
    d1 = nodeCoordsOnFil[nodeCoordsOnFil.size(0)] - d2;
    a_tmp[1] = d1;
    y[1] = d1 * d1;
    y_tmp = coder::sumColumnB(y);
    st.site = &tb_emlrtRSI;
    if (y_tmp < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &k_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    y_tmp = muDoubleScalarSqrt(y_tmp);
    //  next two lines find dot product "direction * (node - r0)" for all nodes
    y[0] = d;
    y[1] = d2;
    idx = nodesOnFil.size(0);
    b_nodesOnFil[0] = nodesOnFil.size(0);
    b_nodesOnFil[1] = 1.0;
    st.site = &ub_emlrtRSI;
    coder::repmat(st, y, b_nodesOnFil, a);
    if ((loop_ub != a.size(0)) && (a.size(0) != 1)) {
      emlrtDimSizeImpxCheckR2021b(loop_ub, a.size(0), &d_emlrtECI,
                                  (emlrtConstCTX)&sp);
    }
    loop_ub_tmp = nodeCoordsOnFil.size(0) << 1;
    nodeCoordsOnFil.set_size(&dc_emlrtRTEI, &sp, nodeCoordsOnFil.size(0), 2);
    ii = (loop_ub_tmp / 2) << 1;
    jj = ii - 2;
    for (i = 0; i <= jj; i += 2) {
      r = _mm_loadu_pd(&nodeCoordsOnFil[i]);
      r1 = _mm_loadu_pd(&a[i]);
      _mm_storeu_pd(&nodeCoordsOnFil[i], _mm_sub_pd(r, r1));
    }
    if (static_cast<int32_T>(loop_ub_tmp - ii < 3200)) {
      for (i = ii; i < loop_ub_tmp; i++) {
        nodeCoordsOnFil[i] = nodeCoordsOnFil[i] - a[i];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      sortNodes_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

      for (i = ii; i < loop_ub_tmp; i++) {
        nodeCoordsOnFil[i] = nodeCoordsOnFil[i] - a[i];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    st.site = &vb_emlrtRSI;
    r = _mm_loadu_pd(&a_tmp[0]);
    _mm_storeu_pd(&a_tmp[0], _mm_div_pd(r, _mm_set1_pd(y_tmp)));
    b_nodesOnFil[0] = idx;
    b_nodesOnFil[1] = 1.0;
    b_st.site = &vb_emlrtRSI;
    coder::repmat(b_st, a_tmp, b_nodesOnFil, a);
    a_tmp[0] = a.size(0);
    y[0] = nodeCoordsOnFil.size(0);
    a_tmp[1] = 2.0;
    y[1] = 2.0;
    p = true;
    idx = 0;
    exitg1 = false;
    while ((!exitg1) && (idx < 2)) {
      if (a_tmp[idx] != y[idx]) {
        p = false;
        exitg1 = true;
      } else {
        idx++;
      }
    }
    if (!p) {
      emlrtErrorWithMessageIdR2018a(&st, &m_emlrtRTEI,
                                    "MATLAB:dot:InputSizeMismatch",
                                    "MATLAB:dot:InputSizeMismatch", 0);
    }
    jj = a.size(0);
    dotProducts.set_size(&ec_emlrtRTEI, &st, a.size(0));
    idx = -1;
    b_st.site = &fc_emlrtRSI;
    if (a.size(0) > 2147483646) {
      c_st.site = &t_emlrtRSI;
      coder::check_forloop_overflow_error(c_st);
    }
    for (loop_ub_tmp = 0; loop_ub_tmp < jj; loop_ub_tmp++) {
      idx++;
      ii = idx + jj;
      dotProducts[loop_ub_tmp] =
          a[idx] * nodeCoordsOnFil[idx] + a[ii] * nodeCoordsOnFil[ii];
    }
    //  now sort the dot products in increasing order and sort the node indices
    //  using the same permutation
    st.site = &wb_emlrtRSI;
    b_st.site = &gc_emlrtRSI;
    coder::internal::sort(b_st, dotProducts, i_tmp);
    loop_ub_tmp = i_tmp.size(0);
    dotProducts.set_size(&fc_emlrtRTEI, &sp, i_tmp.size(0));
    idx = i_tmp.size(0);
    jj = (i_tmp.size(0) < 3200);
    if (jj) {
      for (i = 0; i < loop_ub_tmp; i++) {
        if ((i_tmp[i] < 1) || (i_tmp[i] > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(i_tmp[i], 1, loop_ub, &wc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        dotProducts[i] = nodesOnFil[i_tmp[i] - 1];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      sortNodes_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel num_threads(sortNodes_numThreads) private(f_st)           \
    firstprivate(emlrtHadParallelError)
      {
        try {
          f_st.prev = &sp;
          f_st.tls = emlrtAllocTLS((emlrtCTX)&sp, omp_get_thread_num());
          f_st.site = nullptr;
        } catch (...) {
          emlrtHadParallelError = true;
        }
#pragma omp for nowait
        for (i = 0; i < idx; i++) {
          if (emlrtHadParallelError) {
            continue;
          }
          try {
            if ((i_tmp[i] < 1) || (i_tmp[i] > loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(i_tmp[i], 1, loop_ub, &wc_emlrtBCI,
                                            &f_st);
            }
            dotProducts[i] = nodesOnFil[i_tmp[i] - 1];
          } catch (...) {
            emlrtHadParallelError = true;
          }
        }
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
    nodeOrdering.set_size(&gc_emlrtRTEI, &sp, loop_ub_tmp, 1);
    if (jj) {
      for (i = 0; i < loop_ub_tmp; i++) {
        nodeOrdering[i] = dotProducts[i];
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)&sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      sortNodes_numThreads = emlrtAllocRegionTLSs(
          sp.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sortNodes_numThreads)

      for (i = 0; i < loop_ub_tmp; i++) {
        nodeOrdering[i] = dotProducts[i];
      }
      emlrtExitParallelRegion((emlrtCTX)&sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

emlrtCTX emlrtGetRootTLSGlobal()
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
                           real_T D, real_T astralNum, struct0_T *network,
                           struct1_T *crossings, struct2_T *asters)
{
  __m128d r;
  coder::array<real_T, 2U> b_otherAsters;
  coder::array<real_T, 2U> cosines;
  coder::array<real_T, 2U> r1;
  coder::array<real_T, 2U> r2;
  coder::array<real_T, 2U> r3;
  coder::array<real_T, 2U> sines;
  coder::array<real_T, 1U> centerSepSQR;
  coder::array<int32_T, 1U> r4;
  coder::array<boolean_T, 1U> tooFar;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T A[4];
  real_T b[2];
  real_T b_numAsters[2];
  real_T otherAsters[2];
  real_T a;
  real_T b_y;
  real_T c;
  real_T numNodesGuess;
  int32_T b_asters;
  int32_T c_numAsters;
  int32_T generateAstralNetwork_numThreads;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T maxdimlen;
  int32_T numFil;
  int32_T vectorUB;
  uint32_T nodeCount;
  boolean_T out;
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
  //  GENERATEASTRALNETWORK Constructs an astral network and reports properties
  //    Inputs:
  //        numAsters (scalar): (whole) number of asters to distribute
  //        l (scalar): length of individual filament
  //        D (scalar): domain size; asters are distributed in a square of size
  //        length D
  //        astralNum (scalar): (whole) number of filaments per aster
  //    Outputs:
  //        network (struct): has fields 'nodes', 'augNodes', 'springs', 'ends'
  //            'nodes': see findNodes auxiliary function
  //            'augNodes': see defineSprings auxiliary function
  //            'springs': see defineSprings auxiliary function
  //            'ends': see defineSprings auxiliary function
  //        crossings (struct): has fields 'filCross' and 'centerCross'
  //            'filCross': see findNodes auxiliary function
  //            'centerCross': which filaments cross at each astral center;
  //            each row represents a center
  //        asters (struct): has fields 'centers', 'orients'
  //            'centers': (x,y) coordinates of astral centers
  //            'orients': angles giving each filament's orientation about its
  //            astral center
  //    Note: currently no boundary/edge is constructed, and the implementation
  //    does not store/compile information for running Metropolis-Hastings
  b_numAsters[0] = numAsters;
  b_numAsters[1] = 2.0;
  st.site = &emlrtRSI;
  coder::b_rand(st, b_numAsters, network->nodes);
  asters->centers.set_size(&p_emlrtRTEI, sp, network->nodes.size(0), 2);
  loop_ub = network->nodes.size(0) << 1;
  maxdimlen = (loop_ub / 2) << 1;
  vectorUB = maxdimlen - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&network->nodes[i]);
    _mm_storeu_pd(&asters->centers[i], _mm_mul_pd(_mm_set1_pd(D), r));
  }
  for (i = maxdimlen; i < loop_ub; i++) {
    asters->centers[i] = D * network->nodes[i];
  }
  b_numAsters[0] = numAsters;
  b_numAsters[1] = astralNum;
  st.site = &b_emlrtRSI;
  coder::c_rand(st, b_numAsters, sines);
  asters->orients.set_size(&q_emlrtRTEI, sp, sines.size(0), sines.size(1));
  loop_ub = sines.size(0) * sines.size(1);
  maxdimlen = (loop_ub / 2) << 1;
  vectorUB = maxdimlen - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&sines[i]);
    _mm_storeu_pd(&asters->orients[i],
                  _mm_mul_pd(_mm_set1_pd(6.2831853071795862), r));
  }
  for (i = maxdimlen; i < loop_ub; i++) {
    asters->orients[i] = 6.2831853071795862 * sines[i];
  }
  st.site = &c_emlrtRSI;
  i = asters->orients.size(0);
  i1 = asters->orients.size(1);
  sines.set_size(&r_emlrtRTEI, &st, asters->orients.size(0),
                 asters->orients.size(1));
  numFil = asters->orients.size(0) * asters->orients.size(1);
  for (i2 = 0; i2 < numFil; i2++) {
    sines[i2] = asters->orients[i2];
  }
  //  Auxiliary functions
  //  FINDNODES identifies where filaments cross and records which filaments
  //  crossed
  //  (Note: filaments are indexed as one would read left to right across the
  //  rows of 'orients', and each row represents an aster. This function does
  //  NOT search for intersections between filaments on the same aster)
  //    Inputs:
  //        centers (numAsters x 2 double): (x,y) coordinates of astral centers
  //        orients (numAsters x astralNum double): angles giving each
  //        filament's orientation about its astral center
  //        l (scalar): length of individual filament
  //        centerCross (numAsters x astralNum double): filament indices
  //        grouped by each aster
  //    Outputs:
  //        nodes (numNodes x 2 double): list of (x,y) coordinates of filament
  //        crossings (EXCLUDING astral centers)
  //        filCross (numNodes x 2 double): list of pairs of filament indices
  //        corresponding to the filaments that cross at a particular node;
  //        listed so that filCross(idx,1) < filCross(idx,2)
  vectorUB = asters->orients.size(1);
  c_numAsters = asters->orients.size(0);
  b_st.site = &q_emlrtRSI;
  cosines.set_size(&s_emlrtRTEI, &b_st, asters->orients.size(0),
                   asters->orients.size(1));
  for (i2 = 0; i2 < numFil; i2++) {
    cosines[i2] = asters->orients[i2];
  }
  c_st.site = &r_emlrtRSI;
  d_st.site = &s_emlrtRSI;
  if (numFil > 2147483646) {
    e_st.site = &t_emlrtRSI;
    coder::check_forloop_overflow_error(e_st);
  }
  i2 = (numFil < 3200);
  if (i2) {
    for (int32_T k{0}; k < numFil; k++) {
      cosines[k] = muDoubleScalarCos(cosines[k]);
    }
  } else {
    emlrtEnterParallelRegion(&c_st, static_cast<boolean_T>(omp_in_parallel()));
    generateAstralNetwork_numThreads = emlrtAllocRegionTLSs(
        c_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(generateAstralNetwork_numThreads)

    for (int32_T k = 0; k < numFil; k++) {
      cosines[k] = muDoubleScalarCos(cosines[k]);
    }
    emlrtExitParallelRegion(&c_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  b_st.site = &p_emlrtRSI;
  c_st.site = &u_emlrtRSI;
  d_st.site = &s_emlrtRSI;
  if (i2) {
    for (int32_T k{0}; k < numFil; k++) {
      sines[k] = muDoubleScalarSin(sines[k]);
    }
  } else {
    emlrtEnterParallelRegion(&c_st, static_cast<boolean_T>(omp_in_parallel()));
    generateAstralNetwork_numThreads = emlrtAllocRegionTLSs(
        c_st.tls, static_cast<boolean_T>(omp_in_parallel()),
        omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(generateAstralNetwork_numThreads)

    for (int32_T k = 0; k < numFil; k++) {
      sines[k] = muDoubleScalarSin(sines[k]);
    }
    emlrtExitParallelRegion(&c_st, static_cast<boolean_T>(omp_in_parallel()));
  }
  b_st.site = &o_emlrtRSI;
  c_st.site = &v_emlrtRSI;
  d_st.site = &w_emlrtRSI;
  numNodesGuess = muDoubleScalarRound(static_cast<real_T>(numFil) *
                                      static_cast<real_T>(numFil) / 10.0);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &emlrtDCI, &st);
  }
  network->nodes.set_size(&t_emlrtRTEI, &st,
                          static_cast<int32_T>(numNodesGuess), 2);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &c_emlrtDCI, &st);
  }
  maxdimlen = static_cast<int32_T>(numNodesGuess) << 1;
  for (i2 = 0; i2 < maxdimlen; i2++) {
    network->nodes[i2] = 0.0;
  }
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &b_emlrtDCI, &st);
  }
  crossings->filCross.set_size(&u_emlrtRTEI, &st,
                               static_cast<int32_T>(numNodesGuess), 2);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &d_emlrtDCI, &st);
  }
  for (i2 = 0; i2 < maxdimlen; i2++) {
    crossings->filCross[i2] = 0.0;
  }
  nodeCount = 0U;
  if (sines.size(1) == 1) {
    //  routine for "Classical Mikado" networks
    if (numFil - 2 >= 0) {
      otherAsters[1] = 1.0;
      b_asters = asters->centers.size(0);
      a = 2.0 * l;
    }
    for (int32_T idx{0}; idx <= numFil - 2; idx++) {
      b_st.site = &n_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      if (numFil < (static_cast<real_T>(idx) + 1.0) + 1.0) {
        b_otherAsters.set_size(&ab_emlrtRTEI, &c_st, 1, 0);
      } else {
        i1 = numFil - idx;
        b_otherAsters.set_size(&ab_emlrtRTEI, &c_st, 1, i1 - 1);
        loop_ub = i1 - 2;
        for (i1 = 0; i1 <= loop_ub; i1++) {
          b_otherAsters[i1] = static_cast<real_T>(static_cast<uint32_T>(idx) +
                                                  static_cast<uint32_T>(i1)) +
                              2.0;
        }
      }
      i1 = asters->centers.size(0);
      if ((static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) < 1) ||
          (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
           asters->centers.size(0))) {
        emlrtDynamicBoundsCheckR2012b(
            static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
            asters->centers.size(0), &cb_emlrtBCI, &st);
      }
      b_numAsters[0] = asters->centers[idx];
      b_numAsters[1] = asters->centers[idx + asters->centers.size(0)];
      otherAsters[0] = b_otherAsters.size(1);
      b_st.site = &m_emlrtRSI;
      coder::repmat(b_st, b_numAsters, otherAsters, r1);
      loop_ub = b_otherAsters.size(1);
      r2.set_size(&bb_emlrtRTEI, &st, b_otherAsters.size(1), 2);
      for (i2 = 0; i2 < 2; i2++) {
        for (int32_T i3{0}; i3 < loop_ub; i3++) {
          int32_T i4;
          i4 = static_cast<int32_T>(b_otherAsters[i3]);
          if (b_otherAsters[i3] != i4) {
            emlrtIntegerCheckR2012b(b_otherAsters[i3], &e_emlrtDCI, &st);
          }
          if ((i4 < 1) || (i4 > b_asters)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, b_asters, &db_emlrtBCI, &st);
          }
          r2[i3 + r2.size(0) * i2] =
              asters->centers[(i4 + asters->centers.size(0) * i2) - 1];
        }
      }
      if ((r1.size(0) != b_otherAsters.size(1)) &&
          ((r1.size(0) != 1) && (b_otherAsters.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(r1.size(0), b_otherAsters.size(1),
                                    &b_emlrtECI, &st);
      }
      if (r1.size(0) == r2.size(0)) {
        r3.set_size(&x_emlrtRTEI, &st, r1.size(0), 2);
        loop_ub = r1.size(0) << 1;
        for (i2 = 0; i2 < loop_ub; i2++) {
          numNodesGuess = r1[i2] - r2[i2];
          r3[i2] = numNodesGuess * numNodesGuess;
        }
        b_st.site = &m_emlrtRSI;
        coder::sum(b_st, r3, centerSepSQR);
      } else {
        b_st.site = &m_emlrtRSI;
        binary_expand_op(b_st, centerSepSQR, m_emlrtRSI, r1, r2);
      }
      b_st.site = &l_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      d_st.site = &w_emlrtRSI;
      vectorUB = centerSepSQR.size(0) - 1;
      maxdimlen = 0;
      for (c_numAsters = 0; c_numAsters <= vectorUB; c_numAsters++) {
        if (centerSepSQR[c_numAsters] <= a * a) {
          maxdimlen++;
        }
      }
      r4.set_size(&cb_emlrtRTEI, &st, maxdimlen);
      maxdimlen = 0;
      for (c_numAsters = 0; c_numAsters <= vectorUB; c_numAsters++) {
        if (centerSepSQR[c_numAsters] <= a * a) {
          r4[maxdimlen] = c_numAsters;
          maxdimlen++;
        }
      }
      maxdimlen = r4.size(0);
      for (i2 = 0; i2 < maxdimlen; i2++) {
        if (r4[i2] > b_otherAsters.size(1) - 1) {
          emlrtDynamicBoundsCheckR2012b(r4[i2], 0, b_otherAsters.size(1) - 1,
                                        &fb_emlrtBCI, &st);
        }
      }
      if (r4.size(0) - 1 >= 0) {
        b_y = 1.0 / l;
      }
      if (maxdimlen - 1 >= 0) {
        A[0] = cosines[idx];
        A[1] = sines[idx];
      }
      for (int32_T jdx{0}; jdx < maxdimlen; jdx++) {
        real_T b_b[4];
        real_T denom;
        //  % if filaments are too far apart, don't look for intersections
        //  sepDistSQR = sum( (centers(jdx,:) - centers(idx,:)).^2 );
        //  if sepDistSQR > (2*l)^2
        //      continue
        //  end
        if (jdx + 1 > maxdimlen) {
          emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, maxdimlen, &bb_emlrtBCI,
                                        &st);
        }
        if ((static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) < 1) ||
            (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) > numFil)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1, numFil,
              &lb_emlrtBCI, &st);
        }
        i2 = static_cast<int32_T>(b_otherAsters[r4[jdx]]);
        if ((i2 < 1) || (i2 > numFil)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, numFil, &mb_emlrtBCI, &st);
        }
        A[2] = -cosines[i2 - 1];
        if ((static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) < 1) ||
            (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) > i)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1, i,
              &nb_emlrtBCI, &st);
        }
        if (i2 > i) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i, &ob_emlrtBCI, &st);
        }
        A[3] = -sines[i2 - 1];
        denom = coder::det(A);
        if (i2 > i1) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &ab_emlrtBCI, &st);
        }
        if ((idx + 1 < 1) || (idx + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &y_emlrtBCI, &st);
        }
        if (i2 > i1) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &x_emlrtBCI, &st);
        }
        if ((idx + 1 < 1) || (idx + 1 > i1)) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &w_emlrtBCI, &st);
        }
        b[0] = b_y * (asters->centers[i2 - 1] - asters->centers[idx]);
        b[1] = b_y * (asters->centers[(i2 + asters->centers.size(0)) - 1] -
                      asters->centers[idx + asters->centers.size(0)]);
        b_b[0] = b[0];
        b_b[2] = A[2];
        b_b[1] = b[1];
        b_b[3] = A[3];
        numNodesGuess = coder::det(b_b) / denom;
        if (muDoubleScalarAbs(numNodesGuess - 0.5) <= 0.5) {
          b_b[0] = A[0];
          b_b[2] = b[0];
          b_b[1] = A[1];
          b_b[3] = b[1];
          if (muDoubleScalarAbs(coder::det(b_b) / denom - 0.5) <= 0.5) {
            nodeCount++;
            if ((idx + 1 < 1) || (idx + 1 > i1)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &v_emlrtBCI, &st);
            }
            if ((idx + 1 < 1) || (idx + 1 > numFil)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numFil, &u_emlrtBCI,
                                            &st);
            }
            if ((idx + 1 < 1) || (idx + 1 > i1)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i1, &t_emlrtBCI, &st);
            }
            if ((idx + 1 < 1) || (idx + 1 > i)) {
              emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &s_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(nodeCount) < 1) ||
                (static_cast<int32_T>(nodeCount) > network->nodes.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                            network->nodes.size(0), &h_emlrtBCI,
                                            &st);
            }
            network->nodes[static_cast<int32_T>(nodeCount) - 1] =
                asters->centers[idx] + l * cosines[idx] * numNodesGuess;
            network->nodes[(static_cast<int32_T>(nodeCount) +
                            network->nodes.size(0)) -
                           1] = asters->centers[idx + asters->centers.size(0)] +
                                l * sines[idx] * numNodesGuess;
            if ((static_cast<int32_T>(nodeCount) < 1) ||
                (static_cast<int32_T>(nodeCount) >
                 crossings->filCross.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                            crossings->filCross.size(0),
                                            &d_emlrtBCI, &st);
            }
            crossings->filCross[static_cast<int32_T>(nodeCount) - 1] =
                static_cast<real_T>(idx) + 1.0;
            crossings->filCross[(static_cast<int32_T>(nodeCount) +
                                 crossings->filCross.size(0)) -
                                1] = b_otherAsters[r4[jdx]];
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
  } else if (sines.size(1) >= 2) {
    real_T d;
    //  routine for "Astral Mikado" networks
    //  loop only needs to run through the last filament on penultimate aster
    d = (static_cast<real_T>(sines.size(0)) - 1.0) *
        static_cast<real_T>(sines.size(1));
    i2 = static_cast<int32_T>(d);
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(d), &e_emlrtRTEI, &st);
    if (static_cast<int32_T>(d) - 1 >= 0) {
      otherAsters[1] = 1.0;
      b_asters = asters->centers.size(0);
      a = 2.0 * l;
      c = a * a;
    }
    for (int32_T idx{0}; idx < i2; idx++) {
      real_T b_numAsters_tmp;
      real_T numAsters_tmp;
      real_T y;
      int32_T i3;
      int32_T i4;
      int32_T i5;
      y = muDoubleScalarFloor(((static_cast<real_T>(idx) + 1.0) - 1.0) /
                              static_cast<real_T>(vectorUB));
      b_st.site = &k_emlrtRSI;
      c_st.site = &x_emlrtRSI;
      if (c_numAsters < (y + 1.0) + 1.0) {
        b_otherAsters.set_size(&v_emlrtRTEI, &c_st, 1, 0);
      } else if ((y + 1.0) + 1.0 == (y + 1.0) + 1.0) {
        loop_ub = static_cast<int32_T>(static_cast<real_T>(c_numAsters) -
                                       ((y + 1.0) + 1.0));
        b_otherAsters.set_size(&v_emlrtRTEI, &c_st, 1, loop_ub + 1);
        for (i3 = 0; i3 <= loop_ub; i3++) {
          b_otherAsters[i3] = ((y + 1.0) + 1.0) + static_cast<real_T>(i3);
        }
      } else {
        d_st.site = &y_emlrtRSI;
        coder::eml_float_colon(d_st, (y + 1.0) + 1.0,
                               static_cast<real_T>(c_numAsters), b_otherAsters);
      }
      i3 = asters->centers.size(0);
      out = ((static_cast<int32_T>(y + 1.0) < 1) ||
             (static_cast<int32_T>(y + 1.0) > asters->centers.size(0)));
      if (out) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                      asters->centers.size(0), &r_emlrtBCI,
                                      &st);
      }
      numAsters_tmp = asters->centers[static_cast<int32_T>(y + 1.0) - 1];
      b_numAsters[0] = numAsters_tmp;
      b_numAsters_tmp = asters->centers[(static_cast<int32_T>(y + 1.0) +
                                         asters->centers.size(0)) -
                                        1];
      b_numAsters[1] = b_numAsters_tmp;
      otherAsters[0] = b_otherAsters.size(1);
      b_st.site = &j_emlrtRSI;
      coder::repmat(b_st, b_numAsters, otherAsters, r1);
      loop_ub = b_otherAsters.size(1);
      r2.set_size(&w_emlrtRTEI, &st, b_otherAsters.size(1), 2);
      for (i4 = 0; i4 < 2; i4++) {
        for (i5 = 0; i5 < loop_ub; i5++) {
          if (b_otherAsters[i5] !=
              static_cast<int32_T>(muDoubleScalarFloor(b_otherAsters[i5]))) {
            emlrtIntegerCheckR2012b(b_otherAsters[i5], &f_emlrtDCI, &st);
          }
          maxdimlen = static_cast<int32_T>(b_otherAsters[i5]);
          if ((maxdimlen < 1) || (maxdimlen > b_asters)) {
            emlrtDynamicBoundsCheckR2012b(maxdimlen, 1, b_asters, &eb_emlrtBCI,
                                          &st);
          }
          r2[i5 + r2.size(0) * i4] =
              asters->centers[(maxdimlen + asters->centers.size(0) * i4) - 1];
        }
      }
      if ((r1.size(0) != b_otherAsters.size(1)) &&
          ((r1.size(0) != 1) && (b_otherAsters.size(1) != 1))) {
        emlrtDimSizeImpxCheckR2021b(r1.size(0), b_otherAsters.size(1),
                                    &emlrtECI, &st);
      }
      if (r1.size(0) == r2.size(0)) {
        r3.set_size(&x_emlrtRTEI, &st, r1.size(0), 2);
        loop_ub = r1.size(0) << 1;
        for (i4 = 0; i4 < loop_ub; i4++) {
          numNodesGuess = r1[i4] - r2[i4];
          r3[i4] = numNodesGuess * numNodesGuess;
        }
        b_st.site = &j_emlrtRSI;
        coder::sum(b_st, r3, centerSepSQR);
      } else {
        b_st.site = &j_emlrtRSI;
        binary_expand_op(b_st, centerSepSQR, j_emlrtRSI, r1, r2);
      }
      b_st.site = &i_emlrtRSI;
      c_st.site = &v_emlrtRSI;
      d_st.site = &w_emlrtRSI;
      loop_ub = centerSepSQR.size(0);
      tooFar.set_size(&y_emlrtRTEI, &st, centerSepSQR.size(0));
      for (i4 = 0; i4 < loop_ub; i4++) {
        tooFar[i4] = (centerSepSQR[i4] > c);
      }
      //  start second loop at first filament on the next aster
      d = (y + 1.0) * static_cast<real_T>(vectorUB) + 1.0;
      i4 = static_cast<int32_T>(static_cast<real_T>(numFil) + (1.0 - d));
      emlrtForLoopVectorCheckR2021a(d, 1.0, static_cast<real_T>(numFil),
                                    mxDOUBLE_CLASS, i4, &d_emlrtRTEI, &st);
      for (int32_T jdx{0}; jdx < i4; jdx++) {
        real_T b_jdx;
        b_jdx = d + static_cast<real_T>(jdx);
        b_y =
            muDoubleScalarFloor((b_jdx - 1.0) / static_cast<real_T>(vectorUB));
        i5 = static_cast<int32_T>((b_y + 1.0) - (y + 1.0));
        if ((i5 < 1) || (i5 > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, loop_ub, &gb_emlrtBCI, &st);
        }
        if (!tooFar[i5 - 1]) {
          real_T b_b[4];
          real_T A_tmp;
          real_T denom;
          real_T filSubIdx;
          //  otherwise, check for intersection
          numNodesGuess = coder::b_mod(static_cast<real_T>(idx) + 1.0,
                                       static_cast<real_T>(vectorUB));
          filSubIdx = numNodesGuess +
                      static_cast<real_T>(vectorUB * (numNodesGuess == 0.0));
          numNodesGuess = coder::b_mod(b_jdx, static_cast<real_T>(vectorUB));
          numNodesGuess +=
              static_cast<real_T>(vectorUB * (numNodesGuess == 0.0));
          if ((static_cast<int32_T>(y + 1.0) < 1) ||
              (static_cast<int32_T>(y + 1.0) > i)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1, i,
                                          &hb_emlrtBCI, &st);
          }
          if (filSubIdx !=
              static_cast<int32_T>(muDoubleScalarFloor(filSubIdx))) {
            emlrtIntegerCheckR2012b(filSubIdx, &g_emlrtDCI, &st);
          }
          if ((static_cast<int32_T>(filSubIdx) < 1) ||
              (static_cast<int32_T>(filSubIdx) > i1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx), 1,
                                          i1, &hb_emlrtBCI, &st);
          }
          A[0] = cosines[(static_cast<int32_T>(y + 1.0) +
                          cosines.size(0) *
                              (static_cast<int32_T>(filSubIdx) - 1)) -
                         1];
          if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
              (static_cast<int32_T>(b_y + 1.0) > i)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1, i,
                                          &ib_emlrtBCI, &st);
          }
          if (numNodesGuess !=
              static_cast<int32_T>(muDoubleScalarFloor(numNodesGuess))) {
            emlrtIntegerCheckR2012b(numNodesGuess, &h_emlrtDCI, &st);
          }
          if ((static_cast<int32_T>(numNodesGuess) < 1) ||
              (static_cast<int32_T>(numNodesGuess) > i1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numNodesGuess),
                                          1, i1, &ib_emlrtBCI, &st);
          }
          A[2] = -cosines[(static_cast<int32_T>(b_y + 1.0) +
                           cosines.size(0) *
                               (static_cast<int32_T>(numNodesGuess) - 1)) -
                          1];
          if ((static_cast<int32_T>(filSubIdx) < 1) ||
              (static_cast<int32_T>(filSubIdx) > i1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx), 1,
                                          i1, &jb_emlrtBCI, &st);
          }
          A_tmp =
              sines[(static_cast<int32_T>(y + 1.0) +
                     sines.size(0) * (static_cast<int32_T>(filSubIdx) - 1)) -
                    1];
          A[1] = A_tmp;
          if ((static_cast<int32_T>(numNodesGuess) < 1) ||
              (static_cast<int32_T>(numNodesGuess) > i1)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numNodesGuess),
                                          1, i1, &kb_emlrtBCI, &st);
          }
          A[3] = -sines[(static_cast<int32_T>(b_y + 1.0) +
                         sines.size(0) *
                             (static_cast<int32_T>(numNodesGuess) - 1)) -
                        1];
          denom = coder::det(A);
          a = 1.0 / l;
          if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
              (static_cast<int32_T>(b_y + 1.0) > i3)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                          i3, &q_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(y + 1.0) < 1) ||
              (static_cast<int32_T>(y + 1.0) > i3)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1, i3,
                                          &p_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
              (static_cast<int32_T>(b_y + 1.0) > i3)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                          i3, &o_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(y + 1.0) < 1) ||
              (static_cast<int32_T>(y + 1.0) > i3)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1, i3,
                                          &n_emlrtBCI, &st);
          }
          b[0] = a * (asters->centers[static_cast<int32_T>(b_y + 1.0) - 1] -
                      numAsters_tmp);
          b[1] = a * (asters->centers[(static_cast<int32_T>(b_y + 1.0) +
                                       asters->centers.size(0)) -
                                      1] -
                      b_numAsters_tmp);
          b_b[0] = b[0];
          b_b[2] = A[2];
          b_b[1] = b[1];
          b_b[3] = A[3];
          numNodesGuess = coder::det(b_b) / denom;
          if (muDoubleScalarAbs(numNodesGuess - 0.5) <= 0.5) {
            b_b[0] = A[0];
            b_b[2] = b[0];
            b_b[1] = A_tmp;
            b_b[3] = b[1];
            if (muDoubleScalarAbs(coder::det(b_b) / denom - 0.5) <= 0.5) {
              nodeCount++;
              if ((static_cast<int32_T>(y + 1.0) < 1) ||
                  (static_cast<int32_T>(y + 1.0) > i)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                              i, &m_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(filSubIdx) < 1) ||
                  (static_cast<int32_T>(filSubIdx) > i1)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx),
                                              1, i1, &l_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(y + 1.0) < 1) ||
                  (static_cast<int32_T>(y + 1.0) > i3)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                              i3, &k_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(y + 1.0) < 1) ||
                  (static_cast<int32_T>(y + 1.0) > i)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                              i, &j_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(filSubIdx) < 1) ||
                  (static_cast<int32_T>(filSubIdx) > i1)) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx),
                                              1, i1, &i_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(nodeCount) < 1) ||
                  (static_cast<int32_T>(nodeCount) > network->nodes.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                              1, network->nodes.size(0),
                                              &g_emlrtBCI, &st);
              }
              network->nodes[static_cast<int32_T>(nodeCount) - 1] =
                  numAsters_tmp +
                  l *
                      cosines[(static_cast<int32_T>(y + 1.0) +
                               cosines.size(0) *
                                   (static_cast<int32_T>(filSubIdx) - 1)) -
                              1] *
                      numNodesGuess;
              network->nodes[(static_cast<int32_T>(nodeCount) +
                              network->nodes.size(0)) -
                             1] = b_numAsters_tmp + l * A_tmp * numNodesGuess;
              if ((static_cast<int32_T>(nodeCount) < 1) ||
                  (static_cast<int32_T>(nodeCount) >
                   crossings->filCross.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                              1, crossings->filCross.size(0),
                                              &c_emlrtBCI, &st);
              }
              crossings->filCross[static_cast<int32_T>(nodeCount) - 1] =
                  static_cast<real_T>(idx) + 1.0;
              crossings->filCross[(static_cast<int32_T>(nodeCount) +
                                   crossings->filCross.size(0)) -
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
  }
  if (static_cast<int32_T>(nodeCount) == 0) {
    network->nodes.set_size(&fb_emlrtRTEI, &st, 0, 2);
    crossings->filCross.set_size(&gb_emlrtRTEI, &st, 0, 2);
  } else {
    if (network->nodes.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, network->nodes.size(0), &f_emlrtBCI,
                                    &st);
    }
    loop_ub = static_cast<int32_T>(nodeCount);
    if ((static_cast<int32_T>(nodeCount) < 1) ||
        (static_cast<int32_T>(nodeCount) > network->nodes.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                    network->nodes.size(0), &e_emlrtBCI, &st);
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        network->nodes[i1 + static_cast<int32_T>(nodeCount) * i] =
            network->nodes[i1 + network->nodes.size(0) * i];
      }
    }
    network->nodes.set_size(&db_emlrtRTEI, &st, static_cast<int32_T>(nodeCount),
                            2);
    if (crossings->filCross.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, crossings->filCross.size(0),
                                    &b_emlrtBCI, &st);
    }
    if ((static_cast<int32_T>(nodeCount) < 1) ||
        (static_cast<int32_T>(nodeCount) > crossings->filCross.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                    crossings->filCross.size(0), &emlrtBCI,
                                    &st);
    }
    for (i = 0; i < 2; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        crossings->filCross[i1 + static_cast<int32_T>(nodeCount) * i] =
            crossings->filCross[i1 + crossings->filCross.size(0) * i];
      }
    }
    crossings->filCross.set_size(&eb_emlrtRTEI, &st,
                                 static_cast<int32_T>(nodeCount), 2);
  }
  st.site = &d_emlrtRSI;
  defineSprings(st, network->nodes, crossings->filCross, asters->centers, l,
                astralNum, network->augNodes, network->springs, network->ends);
  numNodesGuess = numAsters * astralNum;
  //  aster idx 1 groups filaments 1,2,...,astralNum; and so on
  if (muDoubleScalarIsNaN(numNodesGuess)) {
    b_otherAsters.set_size(&hb_emlrtRTEI, sp, 1, 1);
    b_otherAsters[0] = rtNaN;
  } else if (numNodesGuess < 1.0) {
    b_otherAsters.set_size(&hb_emlrtRTEI, sp, 1, 0);
  } else {
    b_otherAsters.set_size(&hb_emlrtRTEI, sp, 1,
                           static_cast<int32_T>(numNodesGuess - 1.0) + 1);
    loop_ub = static_cast<int32_T>(numNodesGuess - 1.0);
    if (static_cast<int32_T>(static_cast<int32_T>(numNodesGuess - 1.0) + 1 <
                             3200)) {
      for (int32_T k{0}; k <= loop_ub; k++) {
        b_otherAsters[k] = static_cast<real_T>(k) + 1.0;
      }
    } else {
      emlrtEnterParallelRegion((emlrtCTX)sp,
                               static_cast<boolean_T>(omp_in_parallel()));
      generateAstralNetwork_numThreads = emlrtAllocRegionTLSs(
          sp->tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(generateAstralNetwork_numThreads)

      for (int32_T k = 0; k <= loop_ub; k++) {
        b_otherAsters[k] = static_cast<real_T>(k) + 1.0;
      }
      emlrtExitParallelRegion((emlrtCTX)sp,
                              static_cast<boolean_T>(omp_in_parallel()));
    }
  }
  b[0] = astralNum;
  b[1] = numAsters;
  st.site = &e_emlrtRSI;
  maxdimlen = b_otherAsters.size(1);
  b_st.site = &jd_emlrtRSI;
  coder::internal::assertValidSizeArg(b_st, b);
  c_numAsters = static_cast<int32_T>(astralNum);
  loop_ub = static_cast<int32_T>(numAsters);
  vectorUB = 1;
  if (b_otherAsters.size(1) > 1) {
    vectorUB = b_otherAsters.size(1);
  }
  maxdimlen = muIntScalarMax_sint32(maxdimlen, vectorUB);
  if (static_cast<int32_T>(astralNum) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (static_cast<int32_T>(numAsters) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  out = (static_cast<int32_T>(astralNum) >= 0);
  if ((!out) || (static_cast<int32_T>(numAsters) < 0)) {
    out = false;
  }
  if (!out) {
    emlrtErrorWithMessageIdR2018a(&st, &b_emlrtRTEI,
                                  "MATLAB:checkDimCommon:nonnegativeSize",
                                  "MATLAB:checkDimCommon:nonnegativeSize", 0);
  }
  if (static_cast<int32_T>(astralNum) * static_cast<int32_T>(numAsters) !=
      b_otherAsters.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  crossings->centerCross.set_size(&ib_emlrtRTEI, sp, loop_ub, c_numAsters);
  for (i = 0; i < c_numAsters; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      crossings->centerCross[i1 + crossings->centerCross.size(0) * i] =
          b_otherAsters[i + static_cast<int32_T>(astralNum) * i1];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (generateAstralNetwork.cpp)
