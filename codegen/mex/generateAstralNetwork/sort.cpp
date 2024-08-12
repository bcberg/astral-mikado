//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sort.cpp
//
// Code generation for function 'sort'
//

// Include files
#include "sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo hc_emlrtRSI{
    76,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRSInfo ic_emlrtRSI{
    79,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    81,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    84,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    87,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    90,     // lineNo
    "sort", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pathName
};

static emlrtRTEInfo jc_emlrtRTEI{
    56,                                                                // lineNo
    24,                                                                // colNo
    "sort",                                                            // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pName
};

static emlrtRTEInfo kc_emlrtRTEI{
    75,                                                                // lineNo
    26,                                                                // colNo
    "sort",                                                            // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/eml/+coder/+internal/sort.m" // pName
};

// Function Definitions
namespace coder {
namespace internal {
void sort(const emlrtStack &sp, array<real_T, 1U> &x, array<int32_T, 1U> &idx)
{
  array<real_T, 1U> vwork;
  array<int32_T, 1U> iidx;
  emlrtStack b_st;
  emlrtStack st;
  int32_T k;
  int32_T vlen;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)&sp);
  k = x.size(0);
  vlen = x.size(0) - 1;
  vwork.set_size(&jc_emlrtRTEI, &sp, k);
  idx.set_size(&kc_emlrtRTEI, &sp, k);
  st.site = &hc_emlrtRSI;
  st.site = &ic_emlrtRSI;
  st.site = &jc_emlrtRSI;
  st.site = &kc_emlrtRSI;
  if (k > 2147483646) {
    b_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(b_st);
  }
  for (k = 0; k <= vlen; k++) {
    vwork[k] = x[k];
  }
  st.site = &lc_emlrtRSI;
  sortIdx(st, vwork, iidx);
  st.site = &mc_emlrtRSI;
  for (k = 0; k <= vlen; k++) {
    x[k] = vwork[k];
    idx[k] = iidx[k];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)&sp);
}

} // namespace internal
} // namespace coder

// End of code generation (sort.cpp)
