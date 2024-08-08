//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// repmat.cpp
//
// Code generation for function 'repmat'
//

// Include files
#include "repmat.h"
#include "assertValidSizeArg.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo jb_emlrtRSI{
    38,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    79,                                                              // lineNo
    "repmat",                                                        // fcnName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/repmat.m" // pathName
};

static emlrtRTEInfo tb_emlrtRTEI{
    69,                                                              // lineNo
    28,                                                              // colNo
    "repmat",                                                        // fName
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elmat/repmat.m" // pName
};

// Function Definitions
namespace coder {
void repmat(const emlrtStack &sp, const real_T a[2], const real_T varargin_1[2],
            array<real_T, 2U> &b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  boolean_T overflow;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &jb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  internal::assertValidSizeArg(st, varargin_1);
  i = static_cast<int32_T>(varargin_1[0]);
  b.set_size(&tb_emlrtRTEI, &sp, i, 2);
  overflow = (static_cast<int32_T>(varargin_1[0]) > 2147483646);
  for (int32_T jcol{0}; jcol < 2; jcol++) {
    int32_T ibmat;
    ibmat = jcol * i;
    st.site = &kb_emlrtRSI;
    if (overflow) {
      b_st.site = &lb_emlrtRSI;
      check_forloop_overflow_error(b_st);
    }
    for (int32_T itilerow{0}; itilerow < i; itilerow++) {
      b[ibmat + itilerow] = a[jcol];
    }
  }
}

} // namespace coder

// End of code generation (repmat.cpp)
