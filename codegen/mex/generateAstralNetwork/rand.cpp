//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rand.cpp
//
// Code generation for function 'rand'
//

// Include files
#include "rand.h"
#include "mustBeInteger.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo f_emlrtRSI{
    103,                                                             // lineNo
    "rand",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/randfun/rand.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    104,                                                             // lineNo
    "rand",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/randfun/rand.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    20,                // lineNo
    "zerosWithChecks", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "zerosWithChecks.m" // pathName
};

static emlrtDCInfo i_emlrtDCI{
    23,                // lineNo
    13,                // colNo
    "zerosWithChecks", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/"
    "zerosWithChecks.m", // pName
    4                    // checkKind
};

static emlrtRTEInfo jb_emlrtRTEI{
    103,                                                             // lineNo
    24,                                                              // colNo
    "rand",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/randfun/rand.m" // pName
};

// Function Definitions
namespace coder {
void b_rand(const emlrtStack &sp, const real_T varargin_1[2],
            array<real_T, 2U> &r)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &h_emlrtRSI;
  mustBeInteger(b_st, varargin_1);
  if (!(varargin_1[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[0], &i_emlrtDCI, &st);
  }
  if (!(varargin_1[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[1], &i_emlrtDCI, &st);
  }
  r.set_size(&jb_emlrtRTEI, &st, static_cast<int32_T>(varargin_1[0]), 2);
  st.site = &g_emlrtRSI;
  if (static_cast<int32_T>(varargin_1[0]) != 0) {
    emlrtRandu(&(r.data())[0], static_cast<int32_T>(varargin_1[0]) << 1);
  }
}

void c_rand(const emlrtStack &sp, const real_T varargin_1[2],
            array<real_T, 2U> &r)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &f_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &h_emlrtRSI;
  mustBeInteger(b_st, varargin_1);
  if (!(varargin_1[0] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[0], &i_emlrtDCI, &st);
  }
  if (!(varargin_1[1] >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1[1], &i_emlrtDCI, &st);
  }
  r.set_size(&jb_emlrtRTEI, &st, static_cast<int32_T>(varargin_1[0]),
             static_cast<int32_T>(varargin_1[1]));
  st.site = &g_emlrtRSI;
  if ((static_cast<int32_T>(varargin_1[0]) != 0) &&
      (static_cast<int32_T>(varargin_1[1]) != 0)) {
    emlrtRandu(&(r.data())[0], static_cast<int32_T>(varargin_1[0]) *
                                   static_cast<int32_T>(varargin_1[1]));
  }
}

} // namespace coder

// End of code generation (rand.cpp)
