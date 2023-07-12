//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// any1.cpp
//
// Code generation for function 'any1'
//

// Include files
#include "any1.h"
#include "eml_int_forloop_overflow_check.h"
#include "metropolisMikado_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    ec_emlrtRSI{
        13,    // lineNo
        "any", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\ops\\any.m" // pathName
    };

static emlrtRSInfo
    fc_emlrtRSI{
        143,        // lineNo
        "allOrAny", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\allOrAny."
        "m" // pathName
    };

// Function Definitions
namespace coder {
boolean_T any(const emlrtStack &sp, const ::coder::array<boolean_T, 1U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &ec_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = false;
  b_st.site = &fc_emlrtRSI;
  if (x.size(0) > 2147483646) {
    c_st.site = &rb_emlrtRSI;
    check_forloop_overflow_error(c_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x.size(0))) {
    if (x[ix - 1]) {
      y = true;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

} // namespace coder

// End of code generation (any1.cpp)
