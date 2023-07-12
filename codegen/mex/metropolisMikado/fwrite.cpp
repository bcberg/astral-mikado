//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fwrite.cpp
//
// Code generation for function 'fwrite'
//

// Include files
#include "fwrite.h"
#include "metropolisMikado_mexutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo xb_emlrtRSI{
    61,       // lineNo
    "fwrite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fwrite.m" // pathName
};

static emlrtMCInfo e_emlrtMCI{
    101,          // lineNo
    13,           // colNo
    "fullFwrite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fwrite.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    33,       // lineNo
    5,        // colNo
    "fwrite", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fwrite.m" // pName
};

static emlrtRSInfo yc_emlrtRSI{
    101,          // lineNo
    "fullFwrite", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\iofun\\fwrite.m" // pathName
};

// Function Declarations
static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            emlrtMCInfo &location);

// Function Definitions
static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, const mxArray *m3,
                            const mxArray *m4, const mxArray *m5,
                            emlrtMCInfo &location)
{
  const mxArray *pArrays[5];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  pArrays[4] = m5;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 5, &pArrays[0],
                               "feval", true, &location);
}

namespace coder {
void b_fwrite(const emlrtStack &sp, real_T fileID, real_T x)
{
  static const int32_T iv[2]{1, 6};
  static const int32_T iv1[2]{1, 6};
  static const char_T precision[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char_T u[6]{'f', 'w', 'r', 'i', 't', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!(fileID != 0.0)) {
    emlrtErrorWithMessageIdR2018a(&sp, &c_emlrtRTEI, "MATLAB:notimplemented_mx",
                                  "MATLAB:notimplemented_mx", 0);
  }
  st.site = &xb_emlrtRSI;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 6, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(fileID);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateDoubleScalar(x);
  emlrtAssign(&c_y, m);
  d_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&st, 6, m, &precision[0]);
  emlrtAssign(&d_y, m);
  e_y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *static_cast<int32_T *>(emlrtMxGetData(m)) = 0;
  emlrtAssign(&e_y, m);
  b_st.site = &yc_emlrtRSI;
  b_emlrt_marshallIn(b_st, feval(b_st, y, b_y, c_y, d_y, e_y, e_emlrtMCI),
                     "<output of feval>");
}

void b_fwrite(const emlrtStack &sp, real_T fileID,
              const ::coder::array<real_T, 2U> &x)
{
  static const int32_T iv[2]{1, 6};
  static const int32_T iv2[2]{1, 6};
  static const char_T precision[6]{'d', 'o', 'u', 'b', 'l', 'e'};
  static const char_T u[6]{'f', 'w', 'r', 'i', 't', 'e'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv1[2];
  int32_T i;
  st.prev = &sp;
  st.tls = sp.tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (!(fileID != 0.0)) {
    emlrtErrorWithMessageIdR2018a(&sp, &c_emlrtRTEI, "MATLAB:notimplemented_mx",
                                  "MATLAB:notimplemented_mx", 0);
  }
  st.site = &xb_emlrtRSI;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 6, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(fileID);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  iv1[0] = x.size(0);
  iv1[1] = 2;
  m = emlrtCreateNumericArray(2, &iv1[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < x.size(0); b_i++) {
    pData[i] = x[b_i];
    i++;
  }
  for (int32_T b_i{0}; b_i < x.size(0); b_i++) {
    pData[i] = x[b_i + x.size(0)];
    i++;
  }
  emlrtAssign(&c_y, m);
  d_y = nullptr;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a(&st, 6, m, &precision[0]);
  emlrtAssign(&d_y, m);
  e_y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *static_cast<int32_T *>(emlrtMxGetData(m)) = 0;
  emlrtAssign(&e_y, m);
  b_st.site = &yc_emlrtRSI;
  b_emlrt_marshallIn(b_st, feval(b_st, y, b_y, c_y, d_y, e_y, e_emlrtMCI),
                     "<output of feval>");
}

} // namespace coder

// End of code generation (fwrite.cpp)
