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
#include "det.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "generateAstralNetwork_types.h"
#include "indexShapeCheck.h"
#include "rand.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "sort.h"
#include "sumMatrixIncludeNaN.h"
#include "warning.h"
#include "coder_array.h"
#include "mwmathutil.h"
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

static emlrtRSInfo n_emlrtRSI{
    288,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    279,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    263,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    253,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    245,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    238,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    225,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    216,                                                           // lineNo
    "defineSprings",                                               // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    152,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    165,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    167,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    168,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    171,                                                           // lineNo
    "sortNodes",                                                   // fcnName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    35,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    158,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    138,                                                           // lineNo
    "eml_find",                                                    // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    253,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    254,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    255,                                                           // lineNo
    "find_first_nonempty_triples",                                 // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    70,                                                             // lineNo
    "dot",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    37,                                                              // lineNo
    "sort",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/sort.m" // pathName
};

static emlrtRSInfo qc_emlrtRSI{
    40,                  // lineNo
    "reshapeSizeChecks", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    75,                                                             // lineNo
    40,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    75,                                                             // lineNo
    57,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    79,                                                             // lineNo
    30,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    79,                                                             // lineNo
    51,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    80,                                                             // lineNo
    29,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    80,                                                             // lineNo
    50,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    82,                                                             // lineNo
    49,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    83,                                                             // lineNo
    25,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    83,                                                             // lineNo
    42,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    88,                                                             // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    89,                                                             // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    89,                                                             // lineNo
    58,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    104,                                                            // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    104,                                                            // lineNo
    55,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    111,                                                            // lineNo
    30,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo emlrtDCI{
    111,                                                            // lineNo
    39,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    111,                                                            // lineNo
    39,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    111,                                                            // lineNo
    66,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    111,                                                            // lineNo
    75,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    111,                                                            // lineNo
    75,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    112,                                                            // lineNo
    29,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    112,                                                            // lineNo
    38,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    112,                                                            // lineNo
    65,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    112,                                                            // lineNo
    74,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo w_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    114,                                                            // lineNo
    54,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    115,                                                            // lineNo
    25,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    115,                                                            // lineNo
    47,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ab_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    120,                                                            // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    120,                                                            // lineNo
    72,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    121,                                                            // lineNo
    33,                                                             // colNo
    "centers",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    121,                                                            // lineNo
    63,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    121,                                                            // lineNo
    72,                                                             // colNo
    "orients",                                                      // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    90,                                                             // lineNo
    23,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    122,                                                            // lineNo
    23,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo hb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    132,                                                            // lineNo
    19,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    132,                                                            // lineNo
    21,                                                             // colNo
    "nodes",                                                        // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    91,                                                             // lineNo
    26,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    123,                                                            // lineNo
    26,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    133,                                                            // lineNo
    25,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    133,                                                            // lineNo
    27,                                                             // colNo
    "filCross",                                                     // aName
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    81,                  // lineNo
    23,                  // colNo
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
    74,                  // lineNo
    13,                  // colNo
    "reshapeSizeChecks", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "reshapeSizeChecks.m" // pName
};

static emlrtDCInfo c_emlrtDCI{
    67,                                                             // lineNo
    15,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    68,                                                             // lineNo
    18,                                                             // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    67,                                                             // lineNo
    1,                                                              // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    68,                                                             // lineNo
    1,                                                              // colNo
    "findNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo nb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    266,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ob_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    292,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo pb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    246,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo qb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    245,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo rb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    226,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo sb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    225,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo tb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    220,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ub_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    257,                                                            // lineNo
    18,                                                             // colNo
    "ends",                                                         // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    209,                                                            // lineNo
    1,                                                              // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    208,                                                            // lineNo
    1,                                                              // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    209,                                                            // lineNo
    14,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    4                                                               // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    209,                                                            // lineNo
    14,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    208,                                                            // lineNo
    17,                                                             // colNo
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    1                                                               // checkKind
};

static emlrtBCInfo vb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    299,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo wb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    299,                                                            // lineNo
    23,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                                                            // nDims
    265,                                                           // lineNo
    13,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo xb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    265,                                                            // lineNo
    21,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo yb_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    287,                                                            // lineNo
    30,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ac_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    278,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo bc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    277,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo cc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    276,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo dc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    275,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ec_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    269,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo fc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    262,                                                            // lineNo
    32,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo gc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    261,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo e_emlrtRTEI{
    252,                                                           // lineNo
    15,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtBCInfo hc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    244,                                                            // lineNo
    30,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo ic_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    237,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo jc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    236,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo kc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    235,                                                            // lineNo
    31,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo lc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    234,                                                            // lineNo
    38,                                                             // colNo
    "thisOrder",                                                    // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo mc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    229,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo nc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    224,                                                            // lineNo
    32,                                                             // colNo
    "nodes",                                                        // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo oc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    223,                                                            // lineNo
    26,                                                             // colNo
    "centers",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo f_emlrtRTEI{
    215,                                                           // lineNo
    15,                                                            // colNo
    "defineSprings",                                               // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    13,                                                            // lineNo
    9,                                                             // colNo
    "sqrt",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/sqrt.m" // pName
};

static emlrtBCInfo pc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    290,                                                            // lineNo
    21,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo qc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    241,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo rc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    282,                                                            // lineNo
    25,                                                             // colNo
    "springs",                                                      // aName
    "defineSprings",                                                // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo sc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    163,                                                            // lineNo
    14,                                                             // colNo
    "centers",                                                      // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtECInfo b_emlrtECI{
    1,                                                             // nDims
    167,                                                           // lineNo
    16,                                                            // colNo
    "sortNodes",                                                   // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    239,                                                           // lineNo
    1,                                                             // colNo
    "find_first_nonempty_triples",                                 // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    12,                                                             // lineNo
    23,                                                             // colNo
    "dot",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pName
};

static emlrtBCInfo tc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    161,                                                            // lineNo
    25,                                                             // colNo
    "nodes",                                                        // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtBCInfo uc_emlrtBCI{
    -1,                                                             // iFirst
    -1,                                                             // iLast
    172,                                                            // lineNo
    27,                                                             // colNo
    "nodesOnFil",                                                   // aName
    "sortNodes",                                                    // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m", // pName
    0                                                               // checkKind
};

static emlrtRTEInfo n_emlrtRTEI{
    25,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    26,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    67,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    68,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    132,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    133,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    129,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    130,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    34,                                                            // lineNo
    43,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    34,                                                            // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    208,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    209,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    211,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    251,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    214,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    299,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    297,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    152,                                                           // lineNo
    23,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    195,                                                           // lineNo
    24,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    253,                                                           // lineNo
    5,                                                             // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    247,                                                           // lineNo
    17,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    133,                                                           // lineNo
    13,                                                            // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    36,                                                            // lineNo
    5,                                                             // colNo
    "find",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/find.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    161,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    167,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    60,                                                             // lineNo
    20,                                                             // colNo
    "dot",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/specfun/dot.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    172,                                                           // lineNo
    16,                                                            // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    172,                                                           // lineNo
    1,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    157,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

static emlrtRTEInfo sb_emlrtRTEI{
    154,                                                           // lineNo
    5,                                                             // colNo
    "generateAstralNetwork",                                       // fName
    "/home/bcberg/Documents/astral-mikado/generateAstralNetwork.m" // pName
};

// Function Declarations
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
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
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
  numFil = static_cast<real_T>(centers.size(0)) * astralNum;
  numSpringsGuess = 10.0 * static_cast<real_T>(nodes.size(0));
  if (numSpringsGuess != static_cast<int32_T>(numSpringsGuess)) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &l_emlrtDCI, (emlrtConstCTX)&sp);
  }
  springs.set_size(&y_emlrtRTEI, &sp, static_cast<int32_T>(numSpringsGuess), 4);
  if (numSpringsGuess != static_cast<int32_T>(numSpringsGuess)) {
    emlrtIntegerCheckR2012b(numSpringsGuess, &i_emlrtDCI, (emlrtConstCTX)&sp);
  }
  loop_ub = static_cast<int32_T>(numSpringsGuess) << 2;
  for (i = 0; i < loop_ub; i++) {
    springs[i] = 0.0;
  }
  if (!(numFil >= 0.0)) {
    emlrtNonNegativeCheckR2012b(numFil, &j_emlrtDCI, (emlrtConstCTX)&sp);
  }
  i = static_cast<int32_T>(muDoubleScalarFloor(numFil));
  if (numFil != i) {
    emlrtIntegerCheckR2012b(numFil, &k_emlrtDCI, (emlrtConstCTX)&sp);
  }
  i1 = static_cast<int32_T>(numFil);
  ends.set_size(&ab_emlrtRTEI, &sp, i1, 2);
  if (i1 != i) {
    emlrtIntegerCheckR2012b(numFil, &h_emlrtDCI, (emlrtConstCTX)&sp);
  }
  loop_ub = i1 << 1;
  for (i = 0; i < loop_ub; i++) {
    ends[i] = 0.0;
  }
  springCount = 0U;
  augNodes.set_size(&bb_emlrtRTEI, &sp, 0, 2);
  if (astralNum == 1.0) {
    int32_T i2;
    //  routine for "Classical Mikado" networks
    i = nodes.size(0);
    augNodes.set_size(&db_emlrtRTEI, &sp, nodes.size(0), 2);
    loop_ub = nodes.size(0) << 1;
    for (i2 = 0; i2 < loop_ub; i2++) {
      augNodes[i2] = nodes[i2];
    }
    //  centers are fictitious
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(numFil), &f_emlrtRTEI,
                                  (emlrtConstCTX)&sp);
    for (int32_T idx{0}; idx < i1; idx++) {
      st.site = &v_emlrtRSI;
      sortNodes(st, static_cast<real_T>(idx) + 1.0, nodes, filCross, centers,
                1.0, thisOrder);
      if ((thisOrder.size(0) == 0) || (thisOrder.size(1) == 0)) {
        //  0 nodes = filament doesn't touch any other asters!
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &tb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l;
        //  treat unused filament as "right" dangling end
      } else if (thisOrder.size(0) == 1) {
        real_T b_y[2];
        //  1 node + astralNum == 1 -> two dangling ends
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &oc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > i)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        i, &nc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[idx];
        b_y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[idx + centers.size(0)];
        b_y[1] = numFil * numFil;
        numFil = coder::sumColumnB(b_y);
        st.site = &u_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
        ends[idx + ends.size(0)] = l - ends[idx + ends.size(0)];
      } else {
        real_T b_y[2];
        real_T totSpringLength;
        int32_T n;
        //  >=2 nodes = there are certainly springs along this filament
        if (idx + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, numAsters_tmp, &mc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        totSpringLength = 0.0;
        //  pair adjacent nodes to form springs
        n = thisOrder.size(0) - 2;
        loop_ub = thisOrder.size(0);
        for (int32_T jdx{0}; jdx <= n; jdx++) {
          real_T springLength;
          int32_T y;
          springCount++;
          if (jdx + 1 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, loop_ub, &lc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          i2 = static_cast<int32_T>(thisOrder[jdx]);
          if ((i2 < 1) || (i2 > i)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, i, &kc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (jdx + 2 > loop_ub) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, loop_ub, &jc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          y = static_cast<int32_T>(thisOrder[jdx + 1]);
          if ((y < 1) || (y > i)) {
            emlrtDynamicBoundsCheckR2012b(y, 1, i, &ic_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          numFil = nodes[i2 - 1] - nodes[y - 1];
          b_y[0] = numFil * numFil;
          numFil =
              nodes[(i2 + nodes.size(0)) - 1] - nodes[(y + nodes.size(0)) - 1];
          b_y[1] = numFil * numFil;
          springLength = coder::sumColumnB(b_y);
          st.site = &t_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
                                          springs.size(0), &qc_emlrtBCI,
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
            (static_cast<int32_T>(thisOrder[0]) > i)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        i, &hc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[idx];
        b_y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[idx + centers.size(0)];
        b_y[1] = numFil * numFil;
        numFil = coder::sumColumnB(b_y);
        st.site = &s_emlrtRSI;
        if (numFil < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &qb_emlrtBCI, &st);
        }
        ends[idx] = muDoubleScalarSqrt(numFil);
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &pb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = (l - totSpringLength) - ends[idx];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
      }
    }
  } else if (astralNum >= 2.0) {
    int32_T i2;
    //  routine for "Astral Mikado" networks
    augNodes.set_size(&cb_emlrtRTEI, &sp, centers.size(0) + nodes.size(0), 2);
    loop_ub = nodes.size(0);
    for (i = 0; i < 2; i++) {
      for (i2 = 0; i2 < numAsters_tmp; i2++) {
        augNodes[i2 + augNodes.size(0) * i] = centers[i2 + centers.size(0) * i];
      }
      for (i2 = 0; i2 < loop_ub; i2++) {
        augNodes[(i2 + centers.size(0)) + augNodes.size(0) * i] =
            nodes[i2 + nodes.size(0) * i];
      }
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, numFil, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(numFil), &e_emlrtRTEI,
                                  (emlrtConstCTX)&sp);
    for (int32_T idx{0}; idx < i1; idx++) {
      int32_T y;
      st.site = &r_emlrtRSI;
      sortNodes(st, static_cast<real_T>(idx) + 1.0, nodes, filCross, centers,
                astralNum, thisOrder);
      y = static_cast<int32_T>(muDoubleScalarFloor(
          ((static_cast<real_T>(idx) + 1.0) - 1.0) / astralNum));
      if ((thisOrder.size(0) == 0) || (thisOrder.size(1) == 0)) {
        //  0 nodes = filament doesn't touch any other asters!
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &ub_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l;
        //  treat unused filament as "right" dangling end
      } else if (thisOrder.size(0) == 1) {
        real_T b_y[2];
        real_T springLength;
        //  1 node + astralNum >=2 -> spring between astral center & node
        springCount++;
        if (y + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, numAsters_tmp, &gc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        if ((static_cast<int32_T>(thisOrder[0]) < 1) ||
            (static_cast<int32_T>(thisOrder[0]) > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        loop_ub, &fc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[y];
        b_y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[y + centers.size(0)];
        b_y[1] = numFil * numFil;
        springLength = coder::sumColumnB(b_y);
        st.site = &q_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        thisOrder[0] = static_cast<real_T>(numAsters_tmp) + thisOrder[0];
        newSpring_size[0] = 1;
        newSpring_size[1] = 4;
        numFil = thisOrder[0];
        if ((static_cast<int32_T>(springCount) < 1) ||
            (static_cast<int32_T>(springCount) > springs.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                        springs.size(0), &xb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        iv[0] = 1;
        iv[1] = 4;
        emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &newSpring_size[0], 2,
                                      &emlrtECI, (emlrtCTX)&sp);
        springs[static_cast<int32_T>(springCount) - 1] = y + 1;
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
              ends.size(0), &nb_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l - springLength;
      } else {
        real_T b_y[2];
        real_T springLength;
        real_T totSpringLength;
        int32_T n;
        //  >=2 nodes = there are certainly springs along this filament
        if (y + 1 > numAsters_tmp) {
          emlrtDynamicBoundsCheckR2012b(y + 1, 1, numAsters_tmp, &ec_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        totSpringLength = 0.0;
        //  like "Classical", but proximal segment to center is spring
        //  also need to account for augmented node indices
        n = thisOrder.size(0) - 2;
        for (int32_T jdx{0}; jdx <= n; jdx++) {
          springCount++;
          if (jdx + 1 > thisOrder.size(0)) {
            emlrtDynamicBoundsCheckR2012b(jdx + 1, 1, thisOrder.size(0),
                                          &dc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i = static_cast<int32_T>(thisOrder[jdx]);
          if ((i < 1) || (i > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(i, 1, loop_ub, &cc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          if (jdx + 2 > thisOrder.size(0)) {
            emlrtDynamicBoundsCheckR2012b(jdx + 2, 1, thisOrder.size(0),
                                          &bc_emlrtBCI, (emlrtConstCTX)&sp);
          }
          i2 = static_cast<int32_T>(thisOrder[jdx + 1]);
          if ((i2 < 1) || (i2 > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(i2, 1, loop_ub, &ac_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          numFil = nodes[i - 1] - nodes[i2 - 1];
          b_y[0] = numFil * numFil;
          numFil =
              nodes[(i + nodes.size(0)) - 1] - nodes[(i2 + nodes.size(0)) - 1];
          b_y[1] = numFil * numFil;
          springLength = coder::sumColumnB(b_y);
          st.site = &o_emlrtRSI;
          if (springLength < 0.0) {
            emlrtErrorWithMessageIdR2018a(
                &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
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
                                          springs.size(0), &rc_emlrtBCI,
                                          (emlrtConstCTX)&sp);
          }
          springs[static_cast<int32_T>(springCount) - 1] =
              static_cast<real_T>(numAsters_tmp) + numFil;
          springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
              static_cast<real_T>(numAsters_tmp) + numSpringsGuess;
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
            (static_cast<int32_T>(thisOrder[0]) > loop_ub)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(thisOrder[0]), 1,
                                        loop_ub, &yb_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        numFil = nodes[static_cast<int32_T>(thisOrder[0]) - 1] - centers[y];
        b_y[0] = numFil * numFil;
        numFil =
            nodes[(static_cast<int32_T>(thisOrder[0]) + nodes.size(0)) - 1] -
            centers[y + centers.size(0)];
        b_y[1] = numFil * numFil;
        springLength = coder::sumColumnB(b_y);
        st.site = &n_emlrtRSI;
        if (springLength < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
        }
        springLength = muDoubleScalarSqrt(springLength);
        if ((static_cast<int32_T>(springCount) < 1) ||
            (static_cast<int32_T>(springCount) > springs.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                        springs.size(0), &pc_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        springs[static_cast<int32_T>(springCount) - 1] =
            static_cast<real_T>(y) + 1.0;
        springs[(static_cast<int32_T>(springCount) + springs.size(0)) - 1] =
            static_cast<real_T>(numAsters_tmp) + thisOrder[0];
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 2) - 1] =
            static_cast<real_T>(idx) + 1.0;
        springs[(static_cast<int32_T>(springCount) + springs.size(0) * 3) - 1] =
            springLength;
        totSpringLength += springLength;
        if (static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U) >
            ends.size(0)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(idx) + 1U), 1,
              ends.size(0), &ob_emlrtBCI, (emlrtConstCTX)&sp);
        }
        ends[idx + ends.size(0)] = l - totSpringLength;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
      }
    }
  }
  if (static_cast<int32_T>(springCount) == 0) {
    springs.set_size(&fb_emlrtRTEI, &sp, 0, 4);
  } else {
    if (springs.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, springs.size(0), &wb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    loop_ub = static_cast<int32_T>(springCount);
    if ((static_cast<int32_T>(springCount) < 1) ||
        (static_cast<int32_T>(springCount) > springs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(springCount), 1,
                                    springs.size(0), &vb_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    for (i = 0; i < 4; i++) {
      for (i1 = 0; i1 < loop_ub; i1++) {
        springs[i1 + static_cast<int32_T>(springCount) * i] =
            springs[i1 + springs.size(0) * i];
      }
    }
    springs.set_size(&eb_emlrtRTEI, &sp, static_cast<int32_T>(springCount), 4);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

static void sortNodes(const emlrtStack &sp, real_T filIdx,
                      const coder::array<real_T, 2U> &nodes,
                      const coder::array<real_T, 2U> &filCross,
                      const coder::array<real_T, 2U> &centers, real_T astralNum,
                      coder::array<real_T, 2U> &nodeOrdering)
{
  coder::array<real_T, 2U> a;
  coder::array<real_T, 2U> nodeCoordsOnFil;
  coder::array<real_T, 1U> dotProducts;
  coder::array<int32_T, 1U> i_tmp;
  coder::array<int32_T, 1U> nodesOnFil;
  coder::array<boolean_T, 2U> x;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a_tmp[2];
  int32_T i;
  int32_T idx;
  int32_T ii;
  int32_T jj;
  int32_T loop_ub_tmp;
  boolean_T exitg1;
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
  st.site = &w_emlrtRSI;
  x.set_size(&gb_emlrtRTEI, &st, filCross.size(0), 2);
  loop_ub_tmp = filCross.size(0) << 1;
  for (i = 0; i < loop_ub_tmp; i++) {
    x[i] = (filCross[i] == filIdx);
  }
  b_st.site = &cb_emlrtRSI;
  if (loop_ub_tmp == 0) {
    i_tmp.set_size(&kb_emlrtRTEI, &b_st, 0);
  } else {
    c_st.site = &eb_emlrtRSI;
    idx = 0;
    i_tmp.set_size(&hb_emlrtRTEI, &c_st, loop_ub_tmp);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 2)) {
      boolean_T guard1;
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
      emlrtErrorWithMessageIdR2018a(&c_st, &h_emlrtRTEI,
                                    "Coder:builtins:AssertionFailed",
                                    "Coder:builtins:AssertionFailed", 0);
    }
    if (loop_ub_tmp == 1) {
      if (idx == 0) {
        i_tmp.set_size(&jb_emlrtRTEI, &c_st, 0);
      }
    } else {
      int32_T iv[2];
      if (idx < 1) {
        i = 0;
      } else {
        i = idx;
      }
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &fb_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, i_tmp.size(0), iv);
      i_tmp.set_size(&ib_emlrtRTEI, &c_st, i);
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &gb_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, loop_ub_tmp, iv);
      iv[0] = 1;
      iv[1] = i;
      d_st.site = &hb_emlrtRSI;
      coder::internal::indexShapeCheck(d_st, loop_ub_tmp, iv);
    }
  }
  if ((x.size(0) == 1) && (i_tmp.size(0) != 1)) {
    c_st.site = &db_emlrtRSI;
    coder::internal::warning(c_st);
  }
  loop_ub_tmp = i_tmp.size(0);
  nodesOnFil.set_size(&lb_emlrtRTEI, &st, i_tmp.size(0));
  for (i = 0; i < loop_ub_tmp; i++) {
    nodesOnFil[i] = i_tmp[i];
  }
  if (nodesOnFil.size(0) == 0) {
    nodeOrdering.set_size(&sb_emlrtRTEI, &sp, 0, 0);
  } else if (nodesOnFil.size(0) == 1) {
    nodeOrdering.set_size(&rb_emlrtRTEI, &sp, 1, 1);
    nodeOrdering[0] = nodesOnFil[0];
  } else {
    __m128d r;
    real_T b_nodesOnFil[2];
    real_T y[2];
    real_T d;
    real_T d1;
    real_T d2;
    real_T y_tmp;
    boolean_T p;
    nodeCoordsOnFil.set_size(&mb_emlrtRTEI, &sp, i_tmp.size(0), 2);
    for (i = 0; i < 2; i++) {
      for (idx = 0; idx < loop_ub_tmp; idx++) {
        if ((nodesOnFil[idx] < 1) || (nodesOnFil[idx] > nodes.size(0))) {
          emlrtDynamicBoundsCheckR2012b(nodesOnFil[idx], 1, nodes.size(0),
                                        &tc_emlrtBCI, (emlrtConstCTX)&sp);
        }
        nodeCoordsOnFil[idx + nodeCoordsOnFil.size(0) * i] =
            nodes[(nodesOnFil[idx] + nodes.size(0) * i) - 1];
      }
    }
    y_tmp = muDoubleScalarFloor((filIdx - 1.0) / astralNum);
    if ((static_cast<int32_T>(y_tmp + 1.0) < 1) ||
        (static_cast<int32_T>(y_tmp + 1.0) > centers.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y_tmp + 1.0), 1,
                                    centers.size(0), &sc_emlrtBCI,
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
    st.site = &x_emlrtRSI;
    if (y_tmp < 0.0) {
      emlrtErrorWithMessageIdR2018a(
          &st, &g_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    y_tmp = muDoubleScalarSqrt(y_tmp);
    //  next two lines find dot product "direction * (node - r0)" for all nodes
    y[0] = d;
    y[1] = d2;
    b_nodesOnFil[0] = nodesOnFil.size(0);
    b_nodesOnFil[1] = 1.0;
    st.site = &y_emlrtRSI;
    coder::repmat(st, y, b_nodesOnFil, a);
    if ((i_tmp.size(0) != a.size(0)) && (a.size(0) != 1)) {
      emlrtDimSizeImpxCheckR2021b(i_tmp.size(0), a.size(0), &b_emlrtECI,
                                  (emlrtConstCTX)&sp);
    }
    idx = nodeCoordsOnFil.size(0) << 1;
    nodeCoordsOnFil.set_size(&nb_emlrtRTEI, &sp, nodeCoordsOnFil.size(0), 2);
    ii = (idx / 2) << 1;
    jj = ii - 2;
    for (i = 0; i <= jj; i += 2) {
      __m128d r1;
      r = _mm_loadu_pd(&nodeCoordsOnFil[i]);
      r1 = _mm_loadu_pd(&a[i]);
      _mm_storeu_pd(&nodeCoordsOnFil[i], _mm_sub_pd(r, r1));
    }
    for (i = ii; i < idx; i++) {
      nodeCoordsOnFil[i] = nodeCoordsOnFil[i] - a[i];
    }
    st.site = &ab_emlrtRSI;
    r = _mm_loadu_pd(&a_tmp[0]);
    _mm_storeu_pd(&a_tmp[0], _mm_div_pd(r, _mm_set1_pd(y_tmp)));
    b_nodesOnFil[0] = nodesOnFil.size(0);
    b_nodesOnFil[1] = 1.0;
    b_st.site = &ab_emlrtRSI;
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
      emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
                                    "MATLAB:dot:InputSizeMismatch",
                                    "MATLAB:dot:InputSizeMismatch", 0);
    }
    i = a.size(0);
    dotProducts.set_size(&ob_emlrtRTEI, &st, a.size(0));
    idx = -1;
    b_st.site = &mb_emlrtRSI;
    if (a.size(0) > 2147483646) {
      c_st.site = &lb_emlrtRSI;
      coder::check_forloop_overflow_error(c_st);
    }
    for (jj = 0; jj < i; jj++) {
      idx++;
      ii = idx + i;
      dotProducts[jj] =
          a[idx] * nodeCoordsOnFil[idx] + a[ii] * nodeCoordsOnFil[ii];
    }
    //  now sort the dot products in increasing order and sort the node indices
    //  using the same permutation
    st.site = &bb_emlrtRSI;
    b_st.site = &nb_emlrtRSI;
    coder::internal::sort(b_st, dotProducts, i_tmp);
    idx = i_tmp.size(0);
    dotProducts.set_size(&pb_emlrtRTEI, &sp, i_tmp.size(0));
    for (i = 0; i < idx; i++) {
      if ((i_tmp[i] < 1) || (i_tmp[i] > loop_ub_tmp)) {
        emlrtDynamicBoundsCheckR2012b(i_tmp[i], 1, loop_ub_tmp, &uc_emlrtBCI,
                                      (emlrtConstCTX)&sp);
      }
      dotProducts[i] = nodesOnFil[i_tmp[i] - 1];
    }
    nodeOrdering.set_size(&qb_emlrtRTEI, &sp, i_tmp.size(0), 1);
    for (i = 0; i < idx; i++) {
      nodeOrdering[i] = dotProducts[i];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

void generateAstralNetwork(const emlrtStack *sp, real_T numAsters, real_T l,
                           real_T D, real_T astralNum, struct0_T *network,
                           struct1_T *crossings, struct2_T *asters)
{
  __m128d r;
  coder::array<real_T, 2U> b;
  coder::array<real_T, 2U> r1;
  emlrtStack b_st;
  emlrtStack st;
  real_T b_b[2];
  real_T b_numAsters[2];
  real_T a;
  real_T numNodesGuess;
  int32_T i;
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
  asters->centers.set_size(&n_emlrtRTEI, sp, network->nodes.size(0), 2);
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
  coder::c_rand(st, b_numAsters, b);
  asters->orients.set_size(&o_emlrtRTEI, sp, b.size(0), b.size(1));
  loop_ub = b.size(0) * b.size(1);
  maxdimlen = (loop_ub / 2) << 1;
  vectorUB = maxdimlen - 2;
  for (i = 0; i <= vectorUB; i += 2) {
    r = _mm_loadu_pd(&b[i]);
    _mm_storeu_pd(&asters->orients[i],
                  _mm_mul_pd(_mm_set1_pd(6.2831853071795862), r));
  }
  for (i = maxdimlen; i < loop_ub; i++) {
    asters->orients[i] = 6.2831853071795862 * b[i];
  }
  st.site = &c_emlrtRSI;
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
  loop_ub = asters->orients.size(0) * asters->orients.size(1);
  numFil = loop_ub - 2;
  numNodesGuess = muDoubleScalarRound(static_cast<real_T>(loop_ub) *
                                      static_cast<real_T>(loop_ub) / 10.0);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &c_emlrtDCI, &st);
  }
  network->nodes.set_size(&p_emlrtRTEI, &st,
                          static_cast<int32_T>(numNodesGuess), 2);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &e_emlrtDCI, &st);
  }
  maxdimlen = static_cast<int32_T>(numNodesGuess) << 1;
  for (i = 0; i < maxdimlen; i++) {
    network->nodes[i] = 0.0;
  }
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &d_emlrtDCI, &st);
  }
  crossings->filCross.set_size(&q_emlrtRTEI, &st,
                               static_cast<int32_T>(numNodesGuess), 2);
  if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
    emlrtIntegerCheckR2012b(numNodesGuess, &f_emlrtDCI, &st);
  }
  for (i = 0; i < maxdimlen; i++) {
    crossings->filCross[i] = 0.0;
  }
  nodeCount = 0U;
  if (asters->orients.size(1) == 1) {
    //  routine for "Classical Mikado" networks
    for (maxdimlen = 0; maxdimlen <= numFil; maxdimlen++) {
      i = (loop_ub - maxdimlen) - 2;
      if (i >= 0) {
        a = 2.0 * l;
      }
      for (int32_T jdx{0}; jdx <= i; jdx++) {
        real_T b_jdx;
        real_T d;
        real_T d1;
        real_T d2;
        b_jdx = ((static_cast<real_T>(maxdimlen) + 1.0) + 1.0) +
                static_cast<real_T>(jdx);
        //  if filaments are too far apart, don't look for intersections
        out = ((static_cast<int32_T>(b_jdx) < 1) ||
               (static_cast<int32_T>(b_jdx) > asters->centers.size(0)));
        if (out) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_jdx), 1,
                                        asters->centers.size(0), &emlrtBCI,
                                        &st);
        }
        if ((static_cast<int32_T>(static_cast<uint32_T>(maxdimlen) + 1U) < 1) ||
            (static_cast<int32_T>(static_cast<uint32_T>(maxdimlen) + 1U) >
             asters->centers.size(0))) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(static_cast<uint32_T>(maxdimlen) + 1U), 1,
              asters->centers.size(0), &b_emlrtBCI, &st);
        }
        d = asters->centers[static_cast<int32_T>(b_jdx) - 1];
        d1 = d - asters->centers[maxdimlen];
        b_numAsters[0] = d1 * d1;
        d2 = asters->centers[(static_cast<int32_T>(b_jdx) +
                              asters->centers.size(0)) -
                             1];
        d1 = d2 - asters->centers[maxdimlen + asters->centers.size(0)];
        b_numAsters[1] = d1 * d1;
        if (!(coder::sumColumnB(b_numAsters) > a * a)) {
          real_T A[4];
          real_T c_b[4];
          real_T A_tmp;
          real_T b_A_tmp;
          real_T c_A_tmp;
          real_T denom;
          if ((maxdimlen + 1 < 1) || (maxdimlen + 1 > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(maxdimlen + 1, 1, loop_ub,
                                          &c_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(b_jdx) < 1) ||
              (static_cast<int32_T>(b_jdx) > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_jdx), 1,
                                          loop_ub, &d_emlrtBCI, &st);
          }
          if ((maxdimlen + 1 < 1) || (maxdimlen + 1 > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(maxdimlen + 1, 1, loop_ub,
                                          &e_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(b_jdx) < 1) ||
              (static_cast<int32_T>(b_jdx) > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_jdx), 1,
                                          loop_ub, &f_emlrtBCI, &st);
          }
          A_tmp = muDoubleScalarCos(asters->orients[maxdimlen]);
          A[0] = A_tmp;
          b_A_tmp = asters->orients[static_cast<int32_T>(b_jdx) - 1];
          A[2] = -muDoubleScalarCos(b_A_tmp);
          c_A_tmp = muDoubleScalarSin(asters->orients[maxdimlen]);
          A[1] = c_A_tmp;
          A[3] = -muDoubleScalarSin(b_A_tmp);
          denom = coder::det(A);
          numNodesGuess = 1.0 / l;
          if ((maxdimlen + 1 < 1) ||
              (maxdimlen + 1 > asters->centers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(
                maxdimlen + 1, 1, asters->centers.size(0), &g_emlrtBCI, &st);
          }
          if ((static_cast<int32_T>(b_jdx) < 1) ||
              (static_cast<int32_T>(b_jdx) > asters->centers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_jdx), 1,
                                          asters->centers.size(0), &h_emlrtBCI,
                                          &st);
          }
          if ((maxdimlen + 1 < 1) ||
              (maxdimlen + 1 > asters->centers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(
                maxdimlen + 1, 1, asters->centers.size(0), &i_emlrtBCI, &st);
          }
          b_b[0] = numNodesGuess * (d - asters->centers[maxdimlen]);
          b_b[1] = numNodesGuess *
                   (d2 - asters->centers[maxdimlen + asters->centers.size(0)]);
          c_b[0] = b_b[0];
          c_b[2] = A[2];
          c_b[1] = b_b[1];
          c_b[3] = A[3];
          numNodesGuess = coder::det(c_b) / denom;
          if (muDoubleScalarAbs(numNodesGuess - 0.5) <= 0.5) {
            c_b[0] = A_tmp;
            c_b[2] = b_b[0];
            c_b[1] = c_A_tmp;
            c_b[3] = b_b[1];
            if (muDoubleScalarAbs(coder::det(c_b) / denom - 0.5) <= 0.5) {
              nodeCount++;
              if ((maxdimlen + 1 < 1) ||
                  (maxdimlen + 1 > asters->centers.size(0))) {
                emlrtDynamicBoundsCheckR2012b(maxdimlen + 1, 1,
                                              asters->centers.size(0),
                                              &j_emlrtBCI, &st);
              }
              if ((maxdimlen + 1 < 1) || (maxdimlen + 1 > loop_ub)) {
                emlrtDynamicBoundsCheckR2012b(maxdimlen + 1, 1, loop_ub,
                                              &l_emlrtBCI, &st);
              }
              if ((maxdimlen + 1 < 1) ||
                  (maxdimlen + 1 > asters->centers.size(0))) {
                emlrtDynamicBoundsCheckR2012b(maxdimlen + 1, 1,
                                              asters->centers.size(0),
                                              &k_emlrtBCI, &st);
              }
              if ((static_cast<int32_T>(nodeCount) < 1) ||
                  (static_cast<int32_T>(nodeCount) > network->nodes.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                              1, network->nodes.size(0),
                                              &fb_emlrtBCI, &st);
              }
              network->nodes[static_cast<int32_T>(nodeCount) - 1] =
                  asters->centers[maxdimlen] + l * A_tmp * numNodesGuess;
              network->nodes[(static_cast<int32_T>(nodeCount) +
                              network->nodes.size(0)) -
                             1] =
                  asters->centers[maxdimlen + asters->centers.size(0)] +
                  l * c_A_tmp * numNodesGuess;
              if ((static_cast<int32_T>(nodeCount) < 1) ||
                  (static_cast<int32_T>(nodeCount) >
                   crossings->filCross.size(0))) {
                emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                              1, crossings->filCross.size(0),
                                              &jb_emlrtBCI, &st);
              }
              crossings->filCross[static_cast<int32_T>(nodeCount) - 1] =
                  static_cast<real_T>(maxdimlen) + 1.0;
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
  } else if (asters->orients.size(1) >= 2) {
    //  routine for "Astral Mikado" networks
    for (maxdimlen = 0; maxdimlen <= numFil; maxdimlen++) {
      i = (loop_ub - maxdimlen) - 2;
      for (int32_T jdx{0}; jdx <= i; jdx++) {
        real_T b_jdx;
        real_T b_y;
        real_T y;
        b_jdx = ((static_cast<real_T>(maxdimlen) + 1.0) + 1.0) +
                static_cast<real_T>(jdx);
        y = muDoubleScalarFloor(((static_cast<real_T>(maxdimlen) + 1.0) - 1.0) /
                                static_cast<real_T>(vectorUB));
        b_y =
            muDoubleScalarFloor((b_jdx - 1.0) / static_cast<real_T>(vectorUB));
        //  skip this filament if it's on the same aster
        if (!(y + 1.0 == b_y + 1.0)) {
          real_T d;
          real_T d1;
          real_T d2;
          real_T d3;
          a = 2.0 * l;
          out = ((static_cast<int32_T>(b_y + 1.0) < 1) ||
                 (static_cast<int32_T>(b_y + 1.0) > asters->centers.size(0)));
          if (out) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                          asters->centers.size(0), &m_emlrtBCI,
                                          &st);
          }
          if ((static_cast<int32_T>(y + 1.0) < 1) ||
              (static_cast<int32_T>(y + 1.0) > asters->centers.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                          asters->centers.size(0), &n_emlrtBCI,
                                          &st);
          }
          d = asters->centers[static_cast<int32_T>(y + 1.0) - 1];
          d1 = asters->centers[static_cast<int32_T>(b_y + 1.0) - 1] - d;
          b_numAsters[0] = d1 * d1;
          d2 = asters->centers[(static_cast<int32_T>(y + 1.0) +
                                asters->centers.size(0)) -
                               1];
          d3 = asters->centers[(static_cast<int32_T>(b_y + 1.0) +
                                asters->centers.size(0)) -
                               1] -
               d2;
          b_numAsters[1] = d3 * d3;
          if (!(coder::sumColumnB(b_numAsters) > a * a)) {
            real_T A[4];
            real_T c_b[4];
            real_T A_tmp;
            real_T b_A_tmp;
            real_T c_A_tmp;
            real_T denom;
            real_T filSubIdx;
            //  otherwise, check for intersection
            numNodesGuess =
                muDoubleScalarRem(static_cast<real_T>(maxdimlen) + 1.0,
                                  static_cast<real_T>(vectorUB));
            filSubIdx = numNodesGuess +
                        static_cast<real_T>(vectorUB * (numNodesGuess == 0.0));
            numNodesGuess =
                muDoubleScalarRem(b_jdx, static_cast<real_T>(vectorUB));
            numNodesGuess +=
                static_cast<real_T>(vectorUB * (numNodesGuess == 0.0));
            out = ((static_cast<int32_T>(y + 1.0) < 1) ||
                   (static_cast<int32_T>(y + 1.0) > asters->orients.size(0)));
            if (out) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                            asters->orients.size(0),
                                            &o_emlrtBCI, &st);
            }
            if (filSubIdx != static_cast<int32_T>(filSubIdx)) {
              emlrtIntegerCheckR2012b(filSubIdx, &emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(filSubIdx) < 1) ||
                (static_cast<int32_T>(filSubIdx) > vectorUB)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx), 1,
                                            vectorUB, &p_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
                (static_cast<int32_T>(b_y + 1.0) > asters->orients.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                            asters->orients.size(0),
                                            &q_emlrtBCI, &st);
            }
            if (numNodesGuess != static_cast<int32_T>(numNodesGuess)) {
              emlrtIntegerCheckR2012b(numNodesGuess, &b_emlrtDCI, &st);
            }
            if ((static_cast<int32_T>(numNodesGuess) < 1) ||
                (static_cast<int32_T>(numNodesGuess) > vectorUB)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numNodesGuess),
                                            1, vectorUB, &r_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(y + 1.0) < 1) ||
                (static_cast<int32_T>(y + 1.0) > asters->orients.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                            asters->orients.size(0),
                                            &s_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(filSubIdx) < 1) ||
                (static_cast<int32_T>(filSubIdx) > vectorUB)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx), 1,
                                            vectorUB, &t_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
                (static_cast<int32_T>(b_y + 1.0) > asters->orients.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                            asters->orients.size(0),
                                            &u_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(numNodesGuess) < 1) ||
                (static_cast<int32_T>(numNodesGuess) > vectorUB)) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(numNodesGuess),
                                            1, vectorUB, &v_emlrtBCI, &st);
            }
            A_tmp =
                asters->orients[(static_cast<int32_T>(y + 1.0) +
                                 asters->orients.size(0) *
                                     (static_cast<int32_T>(filSubIdx) - 1)) -
                                1];
            b_A_tmp = muDoubleScalarCos(A_tmp);
            A[0] = b_A_tmp;
            c_A_tmp =
                asters
                    ->orients[(static_cast<int32_T>(b_y + 1.0) +
                               asters->orients.size(0) *
                                   (static_cast<int32_T>(numNodesGuess) - 1)) -
                              1];
            A[2] = -muDoubleScalarCos(c_A_tmp);
            A_tmp = muDoubleScalarSin(A_tmp);
            A[1] = A_tmp;
            A[3] = -muDoubleScalarSin(c_A_tmp);
            denom = coder::det(A);
            a = 1.0 / l;
            if ((static_cast<int32_T>(y + 1.0) < 1) ||
                (static_cast<int32_T>(y + 1.0) > asters->centers.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                            asters->centers.size(0),
                                            &w_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(b_y + 1.0) < 1) ||
                (static_cast<int32_T>(b_y + 1.0) > asters->centers.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_y + 1.0), 1,
                                            asters->centers.size(0),
                                            &x_emlrtBCI, &st);
            }
            if ((static_cast<int32_T>(y + 1.0) < 1) ||
                (static_cast<int32_T>(y + 1.0) > asters->centers.size(0))) {
              emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0), 1,
                                            asters->centers.size(0),
                                            &y_emlrtBCI, &st);
            }
            b_b[0] = a * d1;
            b_b[1] = a * d3;
            c_b[0] = b_b[0];
            c_b[2] = A[2];
            c_b[1] = b_b[1];
            c_b[3] = A[3];
            numNodesGuess = coder::det(c_b) / denom;
            if (muDoubleScalarAbs(numNodesGuess - 0.5) <= 0.5) {
              c_b[0] = b_A_tmp;
              c_b[2] = b_b[0];
              c_b[1] = A_tmp;
              c_b[3] = b_b[1];
              if (muDoubleScalarAbs(coder::det(c_b) / denom - 0.5) <= 0.5) {
                nodeCount++;
                if ((static_cast<int32_T>(filSubIdx) < 1) ||
                    (static_cast<int32_T>(filSubIdx) > vectorUB)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx),
                                                1, vectorUB, &bb_emlrtBCI, &st);
                }
                if ((static_cast<int32_T>(y + 1.0) < 1) ||
                    (static_cast<int32_T>(y + 1.0) > asters->centers.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0),
                                                1, asters->centers.size(0),
                                                &ab_emlrtBCI, &st);
                }
                if ((static_cast<int32_T>(y + 1.0) < 1) ||
                    (static_cast<int32_T>(y + 1.0) > asters->orients.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0),
                                                1, asters->orients.size(0),
                                                &db_emlrtBCI, &st);
                }
                if ((static_cast<int32_T>(filSubIdx) < 1) ||
                    (static_cast<int32_T>(filSubIdx) > vectorUB)) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(filSubIdx),
                                                1, vectorUB, &eb_emlrtBCI, &st);
                }
                if ((static_cast<int32_T>(y + 1.0) < 1) ||
                    (static_cast<int32_T>(y + 1.0) > asters->centers.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(y + 1.0),
                                                1, asters->centers.size(0),
                                                &cb_emlrtBCI, &st);
                }
                if ((static_cast<int32_T>(nodeCount) < 1) ||
                    (static_cast<int32_T>(nodeCount) >
                     network->nodes.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                                1, network->nodes.size(0),
                                                &gb_emlrtBCI, &st);
                }
                network->nodes[static_cast<int32_T>(nodeCount) - 1] =
                    d + l * b_A_tmp * numNodesGuess;
                network->nodes[(static_cast<int32_T>(nodeCount) +
                                network->nodes.size(0)) -
                               1] = d2 + l * A_tmp * numNodesGuess;
                if ((static_cast<int32_T>(nodeCount) < 1) ||
                    (static_cast<int32_T>(nodeCount) >
                     crossings->filCross.size(0))) {
                  emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount),
                                                1, crossings->filCross.size(0),
                                                &kb_emlrtBCI, &st);
                }
                crossings->filCross[static_cast<int32_T>(nodeCount) - 1] =
                    static_cast<real_T>(maxdimlen) + 1.0;
                crossings->filCross[(static_cast<int32_T>(nodeCount) +
                                     crossings->filCross.size(0)) -
                                    1] = b_jdx;
              }
            }
          } else {
            //  skip if astral centers (& filaments) are too far apart
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
    network->nodes.set_size(&t_emlrtRTEI, &st, 0, 2);
    crossings->filCross.set_size(&u_emlrtRTEI, &st, 0, 2);
  } else {
    if (network->nodes.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, network->nodes.size(0), &hb_emlrtBCI,
                                    &st);
    }
    loop_ub = static_cast<int32_T>(nodeCount);
    if ((static_cast<int32_T>(nodeCount) < 1) ||
        (static_cast<int32_T>(nodeCount) > network->nodes.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                    network->nodes.size(0), &ib_emlrtBCI, &st);
    }
    for (i = 0; i < 2; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        network->nodes[maxdimlen + static_cast<int32_T>(nodeCount) * i] =
            network->nodes[maxdimlen + network->nodes.size(0) * i];
      }
    }
    network->nodes.set_size(&r_emlrtRTEI, &st, static_cast<int32_T>(nodeCount),
                            2);
    if (crossings->filCross.size(0) < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, crossings->filCross.size(0),
                                    &lb_emlrtBCI, &st);
    }
    if ((static_cast<int32_T>(nodeCount) < 1) ||
        (static_cast<int32_T>(nodeCount) > crossings->filCross.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nodeCount), 1,
                                    crossings->filCross.size(0), &mb_emlrtBCI,
                                    &st);
    }
    for (i = 0; i < 2; i++) {
      for (maxdimlen = 0; maxdimlen < loop_ub; maxdimlen++) {
        crossings->filCross[maxdimlen + static_cast<int32_T>(nodeCount) * i] =
            crossings->filCross[maxdimlen + crossings->filCross.size(0) * i];
      }
    }
    crossings->filCross.set_size(&s_emlrtRTEI, &st,
                                 static_cast<int32_T>(nodeCount), 2);
  }
  st.site = &d_emlrtRSI;
  defineSprings(st, network->nodes, crossings->filCross, asters->centers, l,
                astralNum, network->augNodes, network->springs, network->ends);
  numNodesGuess = numAsters * astralNum;
  //  aster idx 1 groups filaments 1,2,...,astralNum; and so on
  if (muDoubleScalarIsNaN(numNodesGuess)) {
    r1.set_size(&v_emlrtRTEI, sp, 1, 1);
    r1[0] = rtNaN;
  } else if (numNodesGuess < 1.0) {
    r1.set_size(&v_emlrtRTEI, sp, 1, 0);
  } else {
    r1.set_size(&v_emlrtRTEI, sp, 1,
                static_cast<int32_T>(numNodesGuess - 1.0) + 1);
    loop_ub = static_cast<int32_T>(numNodesGuess - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      r1[i] = static_cast<real_T>(i) + 1.0;
    }
  }
  b_b[0] = astralNum;
  b_b[1] = numAsters;
  st.site = &e_emlrtRSI;
  maxdimlen = r1.size(1);
  b_st.site = &qc_emlrtRSI;
  coder::internal::assertValidSizeArg(b_st, b_b);
  loop_ub = static_cast<int32_T>(astralNum);
  numFil = static_cast<int32_T>(numAsters);
  vectorUB = 1;
  if (r1.size(1) > 1) {
    vectorUB = r1.size(1);
  }
  maxdimlen = muIntScalarMax_sint32(maxdimlen, vectorUB);
  if (static_cast<int32_T>(astralNum) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
                                  "Coder:toolbox:reshape_emptyReshapeLimit",
                                  "Coder:toolbox:reshape_emptyReshapeLimit", 0);
  }
  if (static_cast<int32_T>(numAsters) > maxdimlen) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
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
      r1.size(1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &emlrtRTEI, "Coder:MATLAB:getReshapeDims_notSameNumel",
        "Coder:MATLAB:getReshapeDims_notSameNumel", 0);
  }
  crossings->centerCross.set_size(&w_emlrtRTEI, sp, numFil, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    for (maxdimlen = 0; maxdimlen < numFil; maxdimlen++) {
      crossings->centerCross[maxdimlen + crossings->centerCross.size(0) * i] =
          r1[i + static_cast<int32_T>(astralNum) * maxdimlen];
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (generateAstralNetwork.cpp)
