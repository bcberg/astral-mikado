//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sum.cpp
//
// Code generation for function 'sum'
//

// Include files
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <emmintrin.h>

// Variable Definitions
static emlrtRSInfo db_emlrtRSI{
    20,                                                             // lineNo
    "sum",                                                          // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/sum.m" // pathName
};

static emlrtRSInfo
    eb_emlrtRSI{
        99,        // lineNo
        "sumprod", // fcnName
        "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
        "sumprod.m" // pathName
    };

static emlrtRSInfo fb_emlrtRSI{
    86,                      // lineNo
    "combineVectorElements", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    112,                // lineNo
    "blockedSummation", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    173,                // lineNo
    "colMajorFlatIter", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    192,                // lineNo
    "colMajorFlatIter", // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" // pathName
};

static emlrtRTEInfo mb_emlrtRTEI{
    146,                // lineNo
    24,                 // colNo
    "blockedSummation", // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    20,                                                             // lineNo
    1,                                                              // colNo
    "sum",                                                          // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/datafun/sum.m" // pName
};

// Function Definitions
namespace coder {
void sum(const emlrtStack &sp, const array<real_T, 2U> &x, array<real_T, 1U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  int32_T sum_numThreads;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  if (x.size(0) == 0) {
    y.set_size(&nb_emlrtRTEI, &c_st, 0);
  } else {
    int32_T vectorUB;
    int32_T vstride;
    int32_T vstride_tmp;
    d_st.site = &gb_emlrtRSI;
    vstride_tmp = x.size(0);
    vstride = x.size(0);
    y.set_size(&mb_emlrtRTEI, &d_st, x.size(0));
    e_st.site = &hb_emlrtRSI;
    if (x.size(0) > 2147483646) {
      f_st.site = &t_emlrtRSI;
      check_forloop_overflow_error(f_st);
    }
    if (static_cast<int32_T>(x.size(0) < 3200)) {
      for (int32_T xj{0}; xj < vstride_tmp; xj++) {
        y[xj] = x[xj];
      }
    } else {
      emlrtEnterParallelRegion(&d_st,
                               static_cast<boolean_T>(omp_in_parallel()));
      sum_numThreads = emlrtAllocRegionTLSs(
          d_st.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sum_numThreads)

      for (int32_T xj = 0; xj < vstride; xj++) {
        y[xj] = x[xj];
      }
      emlrtExitParallelRegion(&d_st, static_cast<boolean_T>(omp_in_parallel()));
    }
    e_st.site = &ib_emlrtRSI;
    vstride_tmp = (vstride / 2) << 1;
    vectorUB = vstride_tmp - 2;
    for (int32_T xj{0}; xj <= vectorUB; xj += 2) {
      __m128d r;
      r = _mm_loadu_pd(&y[xj]);
      _mm_storeu_pd(&y[xj], _mm_add_pd(r, _mm_loadu_pd(&x[vstride + xj])));
    }
    if (static_cast<int32_T>(vstride - vstride_tmp < 3200)) {
      for (int32_T xj{vstride_tmp}; xj < vstride; xj++) {
        y[xj] = y[xj] + x[vstride + xj];
      }
    } else {
      emlrtEnterParallelRegion(&d_st,
                               static_cast<boolean_T>(omp_in_parallel()));
      sum_numThreads = emlrtAllocRegionTLSs(
          d_st.tls, static_cast<boolean_T>(omp_in_parallel()),
          omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(sum_numThreads)

      for (int32_T xj = vstride_tmp; xj < vstride; xj++) {
        y[xj] = y[xj] + x[vstride + xj];
      }
      emlrtExitParallelRegion(&d_st, static_cast<boolean_T>(omp_in_parallel()));
    }
  }
}

} // namespace coder

// End of code generation (sum.cpp)
