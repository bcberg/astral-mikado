//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// norm.cpp
//
// Code generation for function 'norm'
//

// Include files
#include "norm.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "lapacke.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstddef>

// Variable Definitions
static emlrtRSInfo ic_emlrtRSI{
    119,    // lineNo
    "norm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" // pathName
};

static emlrtRSInfo jc_emlrtRSI{
    148,        // lineNo
    "mat2norm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" // pathName
};

static emlrtRSInfo kc_emlrtRSI{
    156,        // lineNo
    "mat2norm", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\matfun\\norm.m" // pathName
};

static emlrtRSInfo lc_emlrtRSI{
    28,    // lineNo
    "svd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo mc_emlrtRSI{
    107,          // lineNo
    "callLAPACK", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pathName
};

static emlrtRSInfo nc_emlrtRSI{
    31,       // lineNo
    "xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

static emlrtRSInfo oc_emlrtRSI{
    197,            // lineNo
    "ceval_xgesvd", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgesvd.m" // pathName
};

static emlrtRTEInfo e_emlrtRTEI{
    111,          // lineNo
    5,            // colNo
    "callLAPACK", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\svd.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    44,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    47,          // lineNo
    13,          // colNo
    "infocheck", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\infocheck.m" // pName
};

// Function Definitions
namespace coder {
real_T b_norm(const emlrtStack &sp, const real_T x_data[],
              const int32_T x_size[2])
{
  static const char_T fname[14]{'L', 'A', 'P', 'A', 'C', 'K', 'E',
                                '_', 'd', 'g', 'e', 's', 'v', 'd'};
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T A_data[4];
  real_T s_data[2];
  real_T absx;
  real_T y;
  boolean_T MATRIX_INPUT_AND_P_IS_TWO;
  boolean_T VECTOR_INPUT_AND_P_IS_NUMERIC;
  st.prev = &sp;
  st.tls = sp.tls;
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
  VECTOR_INPUT_AND_P_IS_NUMERIC = false;
  MATRIX_INPUT_AND_P_IS_TWO = false;
  if (x_size[0] == 1) {
    VECTOR_INPUT_AND_P_IS_NUMERIC = true;
  } else {
    MATRIX_INPUT_AND_P_IS_TWO = true;
  }
  if (x_size[0] == 0) {
    y = 0.0;
  } else if (MATRIX_INPUT_AND_P_IS_TWO) {
    int32_T m;
    st.site = &ic_emlrtRSI;
    m = x_size[0];
    y = 0.0;
    for (int32_T j{0}; j < 2; j++) {
      b_st.site = &jc_emlrtRSI;
      for (int32_T i{0}; i < m; i++) {
        absx = muDoubleScalarAbs(x_data[i + x_size[0] * j]);
        if (muDoubleScalarIsNaN(absx) || (absx > y)) {
          y = absx;
        }
      }
    }
    if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
      b_st.site = &kc_emlrtRSI;
      c_st.site = &lc_emlrtRSI;
      d_st.site = &mc_emlrtRSI;
      e_st.site = &nc_emlrtRSI;
      m = x_size[0] << 1;
      std::copy(&x_data[0], &x_data[m], &A_data[0]);
      n_t = LAPACKE_dgesvd(102, 'N', 'N', (ptrdiff_t)x_size[0], (ptrdiff_t)2,
                           &A_data[0], (ptrdiff_t)x_size[0], &s_data[0],
                           nullptr, (ptrdiff_t)1, nullptr, (ptrdiff_t)1, &absx);
      f_st.site = &oc_emlrtRSI;
      if ((int32_T)n_t < 0) {
        if ((int32_T)n_t == -1010) {
          emlrtErrorWithMessageIdR2018a(&f_st, &f_emlrtRTEI, "MATLAB:nomem",
                                        "MATLAB:nomem", 0);
        } else {
          emlrtErrorWithMessageIdR2018a(&f_st, &g_emlrtRTEI,
                                        "Coder:toolbox:LAPACKCallErrorInfo",
                                        "Coder:toolbox:LAPACKCallErrorInfo", 5,
                                        4, 14, &fname[0], 12, (int32_T)n_t);
        }
      }
      if ((int32_T)n_t > 0) {
        emlrtErrorWithMessageIdR2018a(&c_st, &e_emlrtRTEI,
                                      "Coder:MATLAB:svd_NoConvergence",
                                      "Coder:MATLAB:svd_NoConvergence", 0);
      }
      y = s_data[0];
    }
  } else if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
    n_t = (ptrdiff_t)(x_size[0] << 1);
    incx_t = (ptrdiff_t)1;
    y = dnrm2(&n_t, (real_T *)&x_data[0], &incx_t);
  } else {
    y = rtNaN;
  }
  return y;
}

} // namespace coder

// End of code generation (norm.cpp)
