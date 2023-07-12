//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sprintf.cpp
//
// Code generation for function 'sprintf'
//

// Include files
#include "sprintf.h"
#include "metropolisMikado_mexutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "emlrt.h"

// Variable Definitions
static emlrtRSInfo rc_emlrtRSI{
    29,        // lineNo
    "sprintf", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtMCInfo i_emlrtMCI{
    53,              // lineNo
    14,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pName
};

static emlrtMCInfo j_emlrtMCI{
    55,              // lineNo
    15,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pName
};

static emlrtDCInfo e_emlrtDCI{
    57,              // lineNo
    53,              // colNo
    "nonConstPrint", // fName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m", // pName
    4 // checkKind
};

static emlrtRSInfo xc_emlrtRSI{
    53,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtRSInfo ad_emlrtRSI{
    55,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

static emlrtRSInfo bd_emlrtRSI{
    58,              // lineNo
    "nonConstPrint", // fcnName
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" // pathName
};

// Function Declarations
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y);

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location);

// Function Definitions
static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *tmpStr,
                             const char_T *identifier,
                             coder::array<char_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<char_T, 2U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *length(const emlrtStack &sp, const mxArray *m1,
                             emlrtMCInfo &location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 1, &pArray, "length",
                               true, &location);
}

namespace coder {
void b_sprintf(const emlrtStack &sp, int32_T varargin_1,
               ::coder::array<char_T, 2U> &str)
{
  static const int32_T iv[2]{1, 7};
  static const int32_T iv1[2]{1, 14};
  static const char_T formatSpec[14]{'/', 'f', 'r', 'a', 'm', 'e', '%',
                                     '0', '4', 'd', '.', 'b', 'i', 'n'};
  static const char_T u[7]{'s', 'p', 'r', 'i', 'n', 't', 'f'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *tmpStr;
  const mxArray *y;
  real_T strSize;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  tmpStr = nullptr;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 7, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&st, 14, m, &formatSpec[0]);
  emlrtAssign(&b_y, m);
  c_y = nullptr;
  m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *static_cast<int32_T *>(emlrtMxGetData(m)) = varargin_1;
  emlrtAssign(&c_y, m);
  b_st.site = &xc_emlrtRSI;
  emlrtAssign(&tmpStr, feval(b_st, y, b_y, c_y, i_emlrtMCI));
  b_st.site = &ad_emlrtRSI;
  strSize = b_emlrt_marshallIn(
      b_st, length(b_st, emlrtAlias(tmpStr), j_emlrtMCI), "<output of length>");
  if (!(strSize >= 0.0)) {
    emlrtNonNegativeCheckR2012b(strSize, &e_emlrtDCI, &st);
  }
  b_st.site = &bd_emlrtRSI;
  emlrt_marshallIn(b_st, emlrtAlias(tmpStr), "tmpStr", str);
  emlrtDestroyArray(&tmpStr);
}

} // namespace coder

// End of code generation (sprintf.cpp)
