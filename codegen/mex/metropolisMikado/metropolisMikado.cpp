//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado.cpp
//
// Code generation for function 'metropolisMikado'
//

// Include files
#include "metropolisMikado.h"
#include "any1.h"
#include "fileManager.h"
#include "find.h"
#include "fwrite.h"
#include "metropolisMikado_data.h"
#include "metropolisMikado_types.h"
#include "mod.h"
#include "norm.h"
#include "rand.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    39,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    41,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    52,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    53,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    54,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    58,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    59,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    60,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    68,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    75,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    76,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo l_emlrtRSI{
    79,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo m_emlrtRSI{
    80,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo n_emlrtRSI{
    82,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    92,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo p_emlrtRSI{
    93,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    95,                 // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    108,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    111,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    113,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo u_emlrtRSI{
    114,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo v_emlrtRSI{
    115,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo w_emlrtRSI{
    145,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    156,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    163,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    164,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    166,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo cb_emlrtRSI{
    167,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo db_emlrtRSI{
    169,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    178,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    179,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    181,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    193,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    196,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    198,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    199,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    200,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    204,                // lineNo
    "metropolisMikado", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo nb_emlrtRSI{
    39,     // lineNo
    "find", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" // pathName
};

static emlrtRSInfo tb_emlrtRSI{
    51,      // lineNo
    "fopen", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fopen.m" // pathName
};

static emlrtRSInfo ub_emlrtRSI{
    12,       // lineNo
    "fclose", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fclose.m" // pathName
};

static emlrtRSInfo yb_emlrtRSI{
    15,       // lineNo
    "fclose", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fclose.m" // pathName
};

static emlrtRSInfo
    ac_emlrtRSI{
        22,            // lineNo
        "fileManager", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    bc_emlrtRSI{
        173,         // lineNo
        "fileclose", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo cc_emlrtRSI{
    81,      // lineNo
    "randi", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\randfun\\randi.m" // pathName
};

static emlrtRSInfo gc_emlrtRSI{
    244,               // lineNo
    "getEnergyChange", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtRSInfo hc_emlrtRSI{
    245,               // lineNo
    "getEnergyChange", // fcnName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pathName
};

static emlrtDCInfo emlrtDCI{
    75,                 // lineNo
    39,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    1                             // checkKind
};

static emlrtBCInfo emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    75,                 // lineNo
    39,                 // colNo
    "movingNodes",      // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo b_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    78,                 // lineNo
    37,                 // colNo
    "state",            // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    91,                 // lineNo
    37,                 // colNo
    "state",            // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    163,                // lineNo
    39,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    1                             // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    163,                // lineNo
    39,                 // colNo
    "movingNodes",      // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    165,                // lineNo
    37,                 // colNo
    "state",            // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                 // iFirst
    -1,                 // iLast
    177,                // lineNo
    37,                 // colNo
    "state",            // aName
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    231,               // lineNo
    26,                // colNo
    "catalog",         // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    234,               // lineNo
    22,                // colNo
    "state",           // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    239,               // lineNo
    35,                // colNo
    "alteredSprings",  // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    240,               // lineNo
    27,                // colNo
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    1                             // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    240,               // lineNo
    27,                // colNo
    "springs",         // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    242,               // lineNo
    22,                // colNo
    "state",           // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    242,               // lineNo
    22,                // colNo
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    1                             // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,                // iFirst
    -1,                // iLast
    243,               // lineNo
    21,                // colNo
    "springs",         // aName
    "getEnergyChange", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m", // pName
    0                             // checkKind
};

static emlrtRTEInfo i_emlrtRTEI{
    39,                 // lineNo
    20,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    39,                 // lineNo
    1,                  // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo k_emlrtRTEI{
    41,                 // lineNo
    17,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    43,                 // lineNo
    1,                  // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    44,                 // lineNo
    1,                  // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    57,                 // lineNo
    21,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    59,                 // lineNo
    28,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    76,                 // lineNo
    20,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    112,                // lineNo
    29,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    114,                // lineNo
    36,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    164,                // lineNo
    20,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    197,                // lineNo
    29,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    199,                // lineNo
    36,                 // colNo
    "metropolisMikado", // fName
    "C:\\Users\\bcber\\OneDrive\\Documents\\MATLAB\\astral-"
    "mikado\\metropolisMikado.m" // pName
};

// Function Declarations
static real_T getEnergyChange(const emlrtStack &sp, real_T alteredNode,
                              const real_T movedHere[2],
                              const coder::array<real_T, 2U> &state,
                              const coder::array<real_T, 2U> &springs,
                              const coder::array<real_T, 2U> &catalog,
                              real_T force, real_T springK);

// Function Definitions
static real_T getEnergyChange(const emlrtStack &sp, real_T alteredNode,
                              const real_T movedHere[2],
                              const coder::array<real_T, 2U> &state,
                              const coder::array<real_T, 2U> &springs,
                              const coder::array<real_T, 2U> &catalog,
                              real_T force, real_T springK)
{
  emlrtStack b_st;
  emlrtStack st;
  real_T alteredSprings_data[4];
  real_T otherEnd_data[4];
  real_T state_data[4];
  real_T deltaE;
  int32_T otherEnd_size[2];
  int32_T state_size[2];
  int32_T i;
  int32_T partialTrueCount;
  int32_T trueCount;
  int8_T tmp_data[4];
  int8_T b_tmp_data[2];
  boolean_T unnamed_idx_0;
  boolean_T unnamed_idx_1;
  boolean_T unnamed_idx_2;
  boolean_T unnamed_idx_3;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  //  GETENERGYCHANGE returns the energy change due to perturbing a single node
  //    Inputs:
  //        alteredNode (integer): index of node that was moved
  //        movedHere (1 x 2 double): position vector [x_perturb, y_perturb]
  //        state (Nnodes x 4 double): node information before perturbation;
  //            same format as nodes from above
  //        springs (Nsprings x 4 double): spring information; same format as
  //            above
  //        catalog (Nnodes x 4 double): list of spring indices connected
  //            to a particular node; for stick-based networks a max. of 4
  //            springs can be connected to a single node
  //        force (double): amount of force applied to a single node, if forced
  //        springK (double): Hookean spring constant
  //    Outputs:
  //        deltaE (double): change in energy due to perturbation
  if ((static_cast<int32_T>(alteredNode) < 1) ||
      (static_cast<int32_T>(alteredNode) > catalog.size(0))) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alteredNode), 1,
                                  catalog.size(0), &g_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  //  if <4 springs are connected to a node, alteredSprings has filler zeros
  unnamed_idx_0 = (catalog[static_cast<int32_T>(alteredNode) - 1] != 0.0);
  unnamed_idx_1 =
      (catalog[(static_cast<int32_T>(alteredNode) + catalog.size(0)) - 1] !=
       0.0);
  unnamed_idx_2 =
      (catalog[(static_cast<int32_T>(alteredNode) + catalog.size(0) * 2) - 1] !=
       0.0);
  unnamed_idx_3 =
      (catalog[(static_cast<int32_T>(alteredNode) + catalog.size(0) * 3) - 1] !=
       0.0);
  trueCount = 0;
  if (unnamed_idx_0) {
    trueCount = 1;
  }
  if (unnamed_idx_1) {
    trueCount++;
  }
  if (unnamed_idx_2) {
    trueCount++;
  }
  if (unnamed_idx_3) {
    trueCount++;
  }
  partialTrueCount = 0;
  if (unnamed_idx_0) {
    tmp_data[0] = 0;
    partialTrueCount = 1;
  }
  if (unnamed_idx_1) {
    tmp_data[partialTrueCount] = 1;
    partialTrueCount++;
  }
  if (unnamed_idx_2) {
    tmp_data[partialTrueCount] = 2;
    partialTrueCount++;
  }
  if (unnamed_idx_3) {
    tmp_data[partialTrueCount] = 3;
  }
  for (i = 0; i < trueCount; i++) {
    alteredSprings_data[i] = catalog[(static_cast<int32_T>(alteredNode) +
                                      catalog.size(0) * tmp_data[i]) -
                                     1];
  }
  unnamed_idx_0 = ((static_cast<int32_T>(alteredNode) < 1) ||
                   (static_cast<int32_T>(alteredNode) > state.size(0)));
  if (unnamed_idx_0) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(alteredNode), 1,
                                  state.size(0), &h_emlrtBCI,
                                  (emlrtConstCTX)&sp);
  }
  //  note: don't alter state here, alter in the main metropolis loop
  deltaE = 0.0;
  //  idx iterates over the *spring* index of each altered spring
  if (trueCount - 1 >= 0) {
    state_size[1] = 2;
    otherEnd_size[1] = 2;
  }
  for (int32_T idx{0}; idx < trueCount; idx++) {
    __m128d r;
    real_T newE;
    real_T oldE;
    real_T restL;
    int32_T b_trueCount;
    int32_T vectorUB;
    if (idx + 1 > trueCount) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, trueCount, &i_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    newE = alteredSprings_data[idx];
    if (newE != static_cast<int32_T>(muDoubleScalarFloor(newE))) {
      emlrtIntegerCheckR2012b(newE, &c_emlrtDCI, (emlrtConstCTX)&sp);
    }
    if ((static_cast<int32_T>(newE) < 1) ||
        (static_cast<int32_T>(newE) > springs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(newE), 1,
                                    springs.size(0), &j_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    b_trueCount = 0;
    unnamed_idx_1 = (springs[static_cast<int32_T>(newE) - 1] != alteredNode);
    unnamed_idx_0 = unnamed_idx_1;
    if (unnamed_idx_1) {
      b_trueCount = 1;
    }
    unnamed_idx_1 =
        (springs[(static_cast<int32_T>(newE) + springs.size(0)) - 1] !=
         alteredNode);
    if (unnamed_idx_1) {
      b_trueCount++;
    }
    partialTrueCount = 0;
    if (unnamed_idx_0) {
      b_tmp_data[0] = 0;
      partialTrueCount = 1;
    }
    if (unnamed_idx_1) {
      b_tmp_data[partialTrueCount] = 1;
    }
    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < b_trueCount; i1++) {
        restL = springs[(static_cast<int32_T>(newE) +
                         springs.size(0) * b_tmp_data[i1]) -
                        1];
        if (restL != static_cast<int32_T>(muDoubleScalarFloor(restL))) {
          emlrtIntegerCheckR2012b(restL, &d_emlrtDCI, (emlrtConstCTX)&sp);
        }
        if ((static_cast<int32_T>(restL) < 1) ||
            (static_cast<int32_T>(restL) > state.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(restL), 1,
                                        state.size(0), &k_emlrtBCI,
                                        (emlrtConstCTX)&sp);
        }
        otherEnd_data[i1 + b_trueCount * i] =
            state[(static_cast<int32_T>(restL) + state.size(0) * i) - 1];
      }
    }
    i = static_cast<int32_T>(alteredSprings_data[idx]);
    if ((i < 1) || (i > springs.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, springs.size(0), &l_emlrtBCI,
                                    (emlrtConstCTX)&sp);
    }
    restL = springs[(i + springs.size(0) * 3) - 1];
    st.site = &gc_emlrtRSI;
    state_size[0] = b_trueCount;
    partialTrueCount = (b_trueCount / 2) << 1;
    vectorUB = partialTrueCount - 2;
    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&otherEnd_data[b_trueCount * i]);
        _mm_storeu_pd(
            &state_data[b_trueCount * i],
            _mm_sub_pd(_mm_set1_pd(state[(static_cast<int32_T>(alteredNode) +
                                          state.size(0) * i) -
                                         1]),
                       r));
      }
      for (int32_T i1{partialTrueCount}; i1 < b_trueCount; i1++) {
        state_data[i1 + b_trueCount * i] =
            state[(static_cast<int32_T>(alteredNode) + state.size(0) * i) - 1] -
            otherEnd_data[i1 + b_trueCount * i];
      }
    }
    b_st.site = &gc_emlrtRSI;
    newE = coder::b_norm(b_st, state_data, state_size) - restL;
    oldE = 0.5 * springK * (newE * newE);
    st.site = &hc_emlrtRSI;
    partialTrueCount = (b_trueCount / 2) << 1;
    vectorUB = partialTrueCount - 2;
    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 <= vectorUB; i1 += 2) {
        r = _mm_loadu_pd(&otherEnd_data[b_trueCount * i]);
        _mm_storeu_pd(&state_data[b_trueCount * i],
                      _mm_sub_pd(_mm_set1_pd(movedHere[i]), r));
      }
      for (int32_T i1{partialTrueCount}; i1 < b_trueCount; i1++) {
        state_data[i1 + b_trueCount * i] =
            movedHere[i] - otherEnd_data[i1 + b_trueCount * i];
      }
    }
    otherEnd_size[0] = b_trueCount;
    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < b_trueCount; i1++) {
        otherEnd_data[i1 + b_trueCount * i] = state_data[i1 + b_trueCount * i];
      }
    }
    b_st.site = &hc_emlrtRSI;
    newE = coder::b_norm(b_st, otherEnd_data, otherEnd_size) - restL;
    newE = 0.5 * springK * (newE * newE);
    if (state[(static_cast<int32_T>(alteredNode) + state.size(0) * 3) - 1] ==
        1.0) {
      oldE -= force * state[static_cast<int32_T>(alteredNode) - 1];
      newE -= force * movedHere[0];
    }
    deltaE = (deltaE + newE) - oldE;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtConstCTX)&sp);
    }
  }
  return deltaE;
}

void metropolisMikado(const emlrtStack *sp,
                      const coder::array<real_T, 2U> &nodes,
                      const coder::array<real_T, 2U> &springs,
                      const coder::array<real_T, 2U> &springCatalog,
                      const struct0_T *param, const struct1_T *hyparam,
                      const struct2_T *directories, char_T startOrResume,
                      coder::array<real_T, 2U> &state,
                      coder::array<char_T, 2U> &energyLogFile,
                      struct3_T *resumeInfo)
{
  static const char_T cv[14]{'/', 'e', 'n', 'e', 'r', 'g', 'y',
                             'L', 'o', 'g', '.', 'b', 'i', 'n'};
  static const char_T frameLabel[14]{'/', 'f', 'r', 'a', 'm', 'e', '0',
                                     '0', '0', '0', '.', 'b', 'i', 'n'};
  coder::array<real_T, 2U> c_nodes;
  coder::array<int32_T, 1U> ii;
  coder::array<int32_T, 1U> movingNodes;
  coder::array<char_T, 2U> b_directories;
  coder::array<char_T, 2U> b_frameLabel;
  coder::array<boolean_T, 1U> b_nodes;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T force;
  int32_T i;
  int32_T loop_ub;
  int32_T numMovingNodes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  //  METROPOLISMIKADO perturbs a spring network using Metropolis-Hastings
  //    Inputs:
  //        nodes (Nnodes x 4 double): node information, each row has
  //            (1) x coordinate of crossing
  //            (2) y coordinate of crossing
  //            (3) boolean 0 or 1 indicating whether to allow node to move;
  //                0 indicates fixed
  //            (4) boolean 0 or 1 indicating whether node directly experiences
  //                external force; 1 indicates yes
  //        springs (Nsprings x 4 double): spring information, each row has
  //            (1) lesser node index that defines one end of the spring
  //            (2) greater node index that defines the other end of the spring
  //            (3) stick index of which stick this spring is a segment of
  //            (4) rest length of the spring (set to initial distance between
  //                the nodes)
  //        springCatalog (Nnodes x 4 double): list of spring indices connected
  //            to a particular node; for stick-based networks a max. of 4
  //            springs can be connected to a single node, filler zeros added
  //            as necessary
  //        param (1 x 1 struct): biophysical parameters; has fields totForce,
  //            kBT, springK
  //        hyparam (1 x 1 struct): algorithm parameters; has fields nt, E,
  //            ntCheck, maxConvChecks, ntAdmit, pAdmit, epsilonBulk,
  //            epsilonTop, ksSamples, ntWrite, ntWriteFrame, nextFrame
  //        directories (1 x 1 struct): locations for storing network configs,
  //            energy logs; has fields dir, subdir
  //        startOrResume (char vector): 's' (start) or 'r' (resume) network
  //            perturbations
  //    Outputs:
  //        state (Nnodes x 4 double): node positions after 3*ntCheck
  //            iterations; same format as input `nodes`
  //        energyLogFile (char vector): address of energyLog.bin relative to
  //            working directory
  //        resumeInfo (1 x 1 struct): other information needed to resume
  //            perturbing network after a convergence check; has fields nt, E,
  //            epsilonBulk, epsilonTop, nextFrame
  st.site = &emlrtRSI;
  b_nodes.set_size(&i_emlrtRTEI, &st, nodes.size(0));
  loop_ub = nodes.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_nodes[i] = (nodes[i + nodes.size(0) * 2] == 1.0);
  }
  b_st.site = &nb_emlrtRSI;
  coder::eml_find(b_st, b_nodes, ii);
  movingNodes.set_size(&j_emlrtRTEI, &st, ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    movingNodes[i] = ii[i];
  }
  //  returns indices of moving nodes
  numMovingNodes = movingNodes.size(0);
  st.site = &b_emlrtRSI;
  b_nodes.set_size(&k_emlrtRTEI, &st, nodes.size(0));
  loop_ub = nodes.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_nodes[i] = (nodes[i + nodes.size(0) * 3] == 1.0);
  }
  b_st.site = &nb_emlrtRSI;
  coder::eml_find(b_st, b_nodes, ii);
  //  returns indices of "top" nodes
  force = param->totForce / static_cast<real_T>(ii.size(0));
  state.set_size(&l_emlrtRTEI, sp, nodes.size(0), 4);
  loop_ub = nodes.size(0) << 2;
  for (i = 0; i < loop_ub; i++) {
    state[i] = nodes[i];
  }
  energyLogFile.set_size(&m_emlrtRTEI, sp, 1, directories->subdir.size(1) + 14);
  loop_ub = directories->subdir.size(1);
  for (i = 0; i < loop_ub; i++) {
    energyLogFile[i] = directories->subdir[i];
  }
  for (i = 0; i < 14; i++) {
    energyLogFile[i + directories->subdir.size(1)] = cv[i];
  }
  resumeInfo->nt = -1.0;
  resumeInfo->E = -1.0;
  resumeInfo->epsilonBulk = -1.0;
  resumeInfo->epsilonTop = -1.0;
  resumeInfo->nextFrame = -1.0;
  //  filler, will be redefined on all successful runs
  if (startOrResume == 's') {
    loop_ub = 0;
  } else if (startOrResume == 'r') {
    loop_ub = 1;
  } else {
    loop_ub = -1;
  }
  switch (loop_ub) {
  case 0: {
    real_T E;
    real_T epsBulk;
    real_T epsTop;
    real_T fileID;
    real_T frame;
    real_T frameFileID;
    real_T nt;
    real_T ntPause;
    real_T numAcceptsBulk;
    real_T numAcceptsTop;
    real_T numVisitsTop;
    //  start perturbing network from initial configuration
    nt = hyparam->nt;
    //  should be initialized at 0
    E = hyparam->E;
    //  should be initialized at 0
    //  write initial energy to disk
    st.site = &c_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    fileID = coder::internal::fileManager(b_st, energyLogFile);
    st.site = &d_emlrtRSI;
    coder::b_fwrite(st, fileID, hyparam->E);
    st.site = &e_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    c_st.site = &ac_emlrtRSI;
    d_st.site = &bc_emlrtRSI;
    coder::internal::cfclose(d_st, fileID);
    //  write initial network config to disk
    st.site = &f_emlrtRSI;
    b_directories.set_size(&n_emlrtRTEI, &st, 1,
                           directories->subdir.size(1) + 14);
    loop_ub = directories->subdir.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_directories[i] = directories->subdir[i];
    }
    for (i = 0; i < 14; i++) {
      b_directories[i + directories->subdir.size(1)] = frameLabel[i];
    }
    b_st.site = &tb_emlrtRSI;
    frameFileID = coder::internal::fileManager(b_st, b_directories);
    c_nodes.set_size(&o_emlrtRTEI, sp, nodes.size(0), 2);
    loop_ub = nodes.size(0);
    for (i = 0; i < 2; i++) {
      for (int32_T i1{0}; i1 < loop_ub; i1++) {
        c_nodes[i1 + c_nodes.size(0) * i] = nodes[i1 + nodes.size(0) * i];
      }
    }
    st.site = &g_emlrtRSI;
    coder::b_fwrite(st, frameFileID, c_nodes);
    st.site = &h_emlrtRSI;
    b_st.site = &yb_emlrtRSI;
    c_st.site = &ac_emlrtRSI;
    d_st.site = &bc_emlrtRSI;
    coder::internal::cfclose(d_st, frameFileID);
    //  adaptive step size counters
    numAcceptsBulk = 0.0;
    numAcceptsTop = 0.0;
    numVisitsTop = 0.0;
    //  prepare for perturbation loop
    st.site = &i_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    fileID = coder::internal::b_fileManager(b_st, energyLogFile);
    frame = hyparam->nextFrame;
    //  should be initialized at 1
    epsTop = hyparam->epsilonTop;
    epsBulk = hyparam->epsilonBulk;
    ntPause = 3.0 * hyparam->ntCheck;
    while (nt < ntPause) {
      st.site = &j_emlrtRSI;
      b_st.site = &cc_emlrtRSI;
      frameFileID = coder::b_rand();
      frameFileID = muDoubleScalarFloor(frameFileID *
                                        static_cast<real_T>(numMovingNodes));
      if (frameFileID + 1.0 != static_cast<int32_T>(frameFileID + 1.0)) {
        emlrtIntegerCheckR2012b(frameFileID + 1.0, &emlrtDCI,
                                (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(frameFileID + 1.0) < 1) ||
          (static_cast<int32_T>(frameFileID + 1.0) > movingNodes.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(frameFileID + 1.0),
                                      1, movingNodes.size(0), &emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_nodes.set_size(&p_emlrtRTEI, sp, ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_nodes[i] =
            (ii[i] == movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1]);
      }
      st.site = &k_emlrtRSI;
      if (coder::any(st, b_nodes)) {
        real_T newPosition[2];
        boolean_T b;
        numVisitsTop++;
        st.site = &l_emlrtRSI;
        coder::b_rand(newPosition);
        i = movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1];
        b = ((i < 1) || (i > state.size(0)));
        if (b) {
          emlrtDynamicBoundsCheckR2012b(i, 1, state.size(0), &b_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        newPosition[0] = state[i - 1] + epsTop * (2.0 * newPosition[0] - 1.0);
        newPosition[1] = state[(i + state.size(0)) - 1] +
                         epsTop * (2.0 * newPosition[1] - 1.0);
        st.site = &m_emlrtRSI;
        frameFileID =
            getEnergyChange(st, static_cast<real_T>(i), newPosition, state,
                            springs, springCatalog, force, param->springK);
        st.site = &n_emlrtRSI;
        if (coder::b_rand() < muDoubleScalarExp(-frameFileID / param->kBT)) {
          state[i - 1] = newPosition[0];
          state[(i + state.size(0)) - 1] = newPosition[1];
          E += frameFileID;
          numAcceptsTop++;
          //  else
          //  do not accept the perturbation (i.e., don't move
          //  the node)
        }
      } else {
        real_T newPosition[2];
        boolean_T b;
        st.site = &o_emlrtRSI;
        coder::b_rand(newPosition);
        i = movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1];
        b = ((i < 1) || (i > state.size(0)));
        if (b) {
          emlrtDynamicBoundsCheckR2012b(i, 1, state.size(0), &c_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        newPosition[0] = state[i - 1] + epsBulk * (2.0 * newPosition[0] - 1.0);
        newPosition[1] = state[(i + state.size(0)) - 1] +
                         epsBulk * (2.0 * newPosition[1] - 1.0);
        st.site = &p_emlrtRSI;
        frameFileID =
            getEnergyChange(st, static_cast<real_T>(i), newPosition, state,
                            springs, springCatalog, force, param->springK);
        st.site = &q_emlrtRSI;
        if (coder::b_rand() < muDoubleScalarExp(-frameFileID / param->kBT)) {
          state[i - 1] = newPosition[0];
          state[(i + state.size(0)) - 1] = newPosition[1];
          E += frameFileID;
          numAcceptsBulk++;
          //  else
          //  do not accept the perturbation (i.e., don't move
          //  the node)
        }
      }
      nt++;
      //  writing to disk
      if (coder::b_mod(nt, hyparam->ntWrite) == 0.0) {
        st.site = &r_emlrtRSI;
        coder::b_fwrite(st, fileID, E);
      }
      if (coder::b_mod(nt, hyparam->ntWriteFrame) == 0.0) {
        frameFileID = muDoubleScalarRound(frame);
        if (frameFileID < 2.147483648E+9) {
          if (frameFileID >= -2.147483648E+9) {
            i = static_cast<int32_T>(frameFileID);
          } else {
            i = MIN_int32_T;
          }
        } else if (frameFileID >= 2.147483648E+9) {
          i = MAX_int32_T;
        } else {
          i = 0;
        }
        st.site = &s_emlrtRSI;
        coder::b_sprintf(st, i, b_frameLabel);
        st.site = &t_emlrtRSI;
        b_directories.set_size(&q_emlrtRTEI, &st, 1,
                               directories->subdir.size(1) +
                                   b_frameLabel.size(1));
        loop_ub = directories->subdir.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_directories[i] = directories->subdir[i];
        }
        loop_ub = b_frameLabel.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_directories[i + directories->subdir.size(1)] = b_frameLabel[i];
        }
        b_st.site = &tb_emlrtRSI;
        frameFileID = coder::internal::fileManager(b_st, b_directories);
        c_nodes.set_size(&r_emlrtRTEI, sp, state.size(0), 2);
        loop_ub = state.size(0);
        for (i = 0; i < 2; i++) {
          for (int32_T i1{0}; i1 < loop_ub; i1++) {
            c_nodes[i1 + c_nodes.size(0) * i] = state[i1 + state.size(0) * i];
          }
        }
        st.site = &u_emlrtRSI;
        coder::b_fwrite(st, frameFileID, c_nodes);
        st.site = &v_emlrtRSI;
        b_st.site = &yb_emlrtRSI;
        c_st.site = &ac_emlrtRSI;
        d_st.site = &bc_emlrtRSI;
        coder::internal::cfclose(d_st, frameFileID);
        frame++;
      }
      //  adaptive step size
      if (coder::b_mod(nt, hyparam->ntAdmit) == 0.0) {
        //  adjust epsilonTop
        if (numVisitsTop > 0.0) {
          frameFileID = numAcceptsTop / numVisitsTop;
          if (frameFileID == 0.0) {
            epsTop /= 100.0;
          } else {
            epsTop = epsTop * frameFileID / hyparam->pAdmit;
          }
        }
        //  adjust epsilonBulk
        frameFileID = hyparam->ntAdmit - numVisitsTop;
        if (frameFileID > 0.0) {
          frameFileID = numAcceptsBulk / frameFileID;
          if (frameFileID == 0.0) {
            epsBulk /= 100.0;
          } else {
            epsBulk = epsBulk * frameFileID / hyparam->pAdmit;
          }
        }
        numVisitsTop = 0.0;
        numAcceptsTop = 0.0;
        numAcceptsBulk = 0.0;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    st.site = &w_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    coder::internal::fileManager(b_st);
    resumeInfo->nt = nt;
    resumeInfo->E = E;
    resumeInfo->epsilonTop = epsTop;
    resumeInfo->epsilonBulk = epsBulk;
    resumeInfo->nextFrame = frame;
  } break;
  case 1: {
    real_T E;
    real_T fileID;
    real_T frame;
    real_T nt;
    real_T ntPause;
    //  resume perturbing network after convergence check
    nt = hyparam->nt;
    E = hyparam->E;
    //  prepare for perturbation loop
    st.site = &x_emlrtRSI;
    b_st.site = &tb_emlrtRSI;
    fileID = coder::internal::b_fileManager(b_st, energyLogFile);
    frame = hyparam->nextFrame;
    ntPause = 3.0 * hyparam->ntCheck;
    while (nt < ntPause) {
      real_T frameFileID;
      st.site = &y_emlrtRSI;
      b_st.site = &cc_emlrtRSI;
      frameFileID = coder::b_rand();
      frameFileID = muDoubleScalarFloor(frameFileID *
                                        static_cast<real_T>(numMovingNodes));
      if (frameFileID + 1.0 != static_cast<int32_T>(frameFileID + 1.0)) {
        emlrtIntegerCheckR2012b(frameFileID + 1.0, &b_emlrtDCI,
                                (emlrtConstCTX)sp);
      }
      if ((static_cast<int32_T>(frameFileID + 1.0) < 1) ||
          (static_cast<int32_T>(frameFileID + 1.0) > movingNodes.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(frameFileID + 1.0),
                                      1, movingNodes.size(0), &d_emlrtBCI,
                                      (emlrtConstCTX)sp);
      }
      b_nodes.set_size(&s_emlrtRTEI, sp, ii.size(0));
      loop_ub = ii.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_nodes[i] =
            (ii[i] == movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1]);
      }
      st.site = &ab_emlrtRSI;
      if (coder::any(st, b_nodes)) {
        real_T newPosition[2];
        boolean_T b;
        st.site = &bb_emlrtRSI;
        coder::b_rand(newPosition);
        i = movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1];
        b = ((i < 1) || (i > state.size(0)));
        if (b) {
          emlrtDynamicBoundsCheckR2012b(i, 1, state.size(0), &e_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        newPosition[0] =
            state[i - 1] + hyparam->epsilonTop * (2.0 * newPosition[0] - 1.0);
        newPosition[1] = state[(i + state.size(0)) - 1] +
                         hyparam->epsilonTop * (2.0 * newPosition[1] - 1.0);
        st.site = &cb_emlrtRSI;
        frameFileID =
            getEnergyChange(st, static_cast<real_T>(i), newPosition, state,
                            springs, springCatalog, force, param->springK);
        st.site = &db_emlrtRSI;
        if (coder::b_rand() < muDoubleScalarExp(-frameFileID / param->kBT)) {
          state[i - 1] = newPosition[0];
          state[(i + state.size(0)) - 1] = newPosition[1];
          E += frameFileID;
          //  else
          //  do not accept the perturbation (i.e., don't move
          //  the node)
        }
      } else {
        real_T newPosition[2];
        boolean_T b;
        st.site = &eb_emlrtRSI;
        coder::b_rand(newPosition);
        i = movingNodes[static_cast<int32_T>(frameFileID + 1.0) - 1];
        b = ((i < 1) || (i > state.size(0)));
        if (b) {
          emlrtDynamicBoundsCheckR2012b(i, 1, state.size(0), &f_emlrtBCI,
                                        (emlrtConstCTX)sp);
        }
        newPosition[0] =
            state[i - 1] + hyparam->epsilonBulk * (2.0 * newPosition[0] - 1.0);
        newPosition[1] = state[(i + state.size(0)) - 1] +
                         hyparam->epsilonBulk * (2.0 * newPosition[1] - 1.0);
        st.site = &fb_emlrtRSI;
        frameFileID =
            getEnergyChange(st, static_cast<real_T>(i), newPosition, state,
                            springs, springCatalog, force, param->springK);
        st.site = &gb_emlrtRSI;
        if (coder::b_rand() < muDoubleScalarExp(-frameFileID / param->kBT)) {
          state[i - 1] = newPosition[0];
          state[(i + state.size(0)) - 1] = newPosition[1];
          E += frameFileID;
          //  else
          //  do not accept the perturbation (i.e., don't move
          //  the node)
        }
      }
      nt++;
      //  writing to disk
      if (coder::b_mod(nt, hyparam->ntWrite) == 0.0) {
        st.site = &hb_emlrtRSI;
        coder::b_fwrite(st, fileID, E);
      }
      if (coder::b_mod(nt, hyparam->ntWriteFrame) == 0.0) {
        frameFileID = muDoubleScalarRound(frame);
        if (frameFileID < 2.147483648E+9) {
          if (frameFileID >= -2.147483648E+9) {
            i = static_cast<int32_T>(frameFileID);
          } else {
            i = MIN_int32_T;
          }
        } else if (frameFileID >= 2.147483648E+9) {
          i = MAX_int32_T;
        } else {
          i = 0;
        }
        st.site = &ib_emlrtRSI;
        coder::b_sprintf(st, i, b_frameLabel);
        st.site = &jb_emlrtRSI;
        b_directories.set_size(&t_emlrtRTEI, &st, 1,
                               directories->subdir.size(1) +
                                   b_frameLabel.size(1));
        loop_ub = directories->subdir.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_directories[i] = directories->subdir[i];
        }
        loop_ub = b_frameLabel.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_directories[i + directories->subdir.size(1)] = b_frameLabel[i];
        }
        b_st.site = &tb_emlrtRSI;
        frameFileID = coder::internal::fileManager(b_st, b_directories);
        c_nodes.set_size(&u_emlrtRTEI, sp, state.size(0), 2);
        loop_ub = state.size(0);
        for (i = 0; i < 2; i++) {
          for (int32_T i1{0}; i1 < loop_ub; i1++) {
            c_nodes[i1 + c_nodes.size(0) * i] = state[i1 + state.size(0) * i];
          }
        }
        st.site = &kb_emlrtRSI;
        coder::b_fwrite(st, frameFileID, c_nodes);
        st.site = &lb_emlrtRSI;
        b_st.site = &yb_emlrtRSI;
        c_st.site = &ac_emlrtRSI;
        d_st.site = &bc_emlrtRSI;
        coder::internal::cfclose(d_st, frameFileID);
        frame++;
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtConstCTX)sp);
      }
    }
    st.site = &mb_emlrtRSI;
    b_st.site = &ub_emlrtRSI;
    coder::internal::fileManager(b_st);
    resumeInfo->nt = nt;
    resumeInfo->E = E;
    resumeInfo->epsilonTop = hyparam->epsilonTop;
    resumeInfo->epsilonBulk = hyparam->epsilonBulk;
    resumeInfo->nextFrame = frame;
  } break;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

// End of code generation (metropolisMikado.cpp)
