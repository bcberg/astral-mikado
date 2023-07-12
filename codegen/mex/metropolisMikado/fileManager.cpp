//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fileManager.cpp
//
// Code generation for function 'fileManager'
//

// Include files
#include "fileManager.h"
#include "metropolisMikado_mexutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo
    vb_emlrtRSI{
        39,            // lineNo
        "fileManager", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    wb_emlrtRSI{
        35,            // lineNo
        "fileManager", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtMCInfo
    emlrtMCI{
        224,            // lineNo
        21,             // colNo
        "filecloseall", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    b_emlrtMCI{
        224,            // lineNo
        13,             // colNo
        "filecloseall", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    c_emlrtMCI{
        225,            // lineNo
        5,              // colNo
        "filecloseall", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    d_emlrtMCI{
        99,         // lineNo
        17,         // colNo
        "fileopen", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    f_emlrtMCI{
        195,       // lineNo
        21,        // colNo
        "cfclose", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    g_emlrtMCI{
        195,       // lineNo
        13,        // colNo
        "cfclose", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtMCInfo
    h_emlrtMCI{
        196,       // lineNo
        5,         // colNo
        "cfclose", // fName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pName
    };

static emlrtRSInfo
    sc_emlrtRSI{
        99,         // lineNo
        "fileopen", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    tc_emlrtRSI{
        195,       // lineNo
        "cfclose", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    uc_emlrtRSI{
        224,            // lineNo
        "filecloseall", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    vc_emlrtRSI{
        196,       // lineNo
        "cfclose", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

static emlrtRSInfo
    wc_emlrtRSI{
        225,            // lineNo
        "filecloseall", // fcnName
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
        "internal\\fileManager.m" // pathName
    };

// Function Declarations
static const mxArray *c_coder_internal_ifWhileCondExt(const emlrtStack &sp,
                                                      const mxArray *m1,
                                                      emlrtMCInfo &location);

static boolean_T e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static boolean_T
emlrt_marshallIn(const emlrtStack &sp,
                 const mxArray *c_a__output_of_coder_internal_i,
                 const char_T *identifier);

static boolean_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo &location);

static const mxArray *logical(const emlrtStack &sp, const mxArray *m1,
                              emlrtMCInfo &location);

// Function Definitions
static const mxArray *c_coder_internal_ifWhileCondExt(const emlrtStack &sp,
                                                      const mxArray *m1,
                                                      emlrtMCInfo &location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 1, &pArray,
                               "coder.internal.ifWhileCondExtrinsic", true,
                               &location);
}

static boolean_T e_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "logical", false, 0U,
                          (const void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T
emlrt_marshallIn(const emlrtStack &sp,
                 const mxArray *c_a__output_of_coder_internal_i,
                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  boolean_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(c_a__output_of_coder_internal_i),
                       &thisId);
  emlrtDestroyArray(&c_a__output_of_coder_internal_i);
  return y;
}

static boolean_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *feval(const emlrtStack &sp, const mxArray *m1,
                            const mxArray *m2, emlrtMCInfo &location)
{
  const mxArray *pArrays[2];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 2, &pArrays[0],
                               "feval", true, &location);
}

static const mxArray *logical(const emlrtStack &sp, const mxArray *m1,
                              emlrtMCInfo &location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtConstCTX)&sp, 1, &m, 1, &pArray, "logical",
                               true, &location);
}

namespace coder {
namespace internal {
real_T b_fileManager(const emlrtStack &sp,
                     const ::coder::array<char_T, 2U> &varargin_1)
{
  static const int32_T iv[2]{1, 5};
  static const char_T u[5]{'f', 'o', 'p', 'e', 'n'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &wb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 5, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateString1R2022a(&st, 'a');
  emlrtAssign(&b_y, m);
  b_st.site = &sc_emlrtRSI;
  return b_emlrt_marshallIn(
      b_st,
      feval(b_st, y, emlrt_marshallOut(b_st, varargin_1), b_y, d_emlrtMCI),
      "<output of feval>");
}

int32_T cfclose(const emlrtStack &sp, real_T fid)
{
  static const int32_T iv[2]{1, 6};
  static const char_T u[6]{'f', 'c', 'l', 'o', 's', 'e'};
  emlrtStack b_st;
  const mxArray *b_y;
  const mxArray *failp;
  const mxArray *m;
  const mxArray *y;
  int32_T st;
  b_st.prev = &sp;
  b_st.tls = sp.tls;
  failp = nullptr;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtConstCTX)&sp, 6, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(fid);
  emlrtAssign(&b_y, m);
  b_st.site = &tc_emlrtRSI;
  emlrtAssign(&failp,
              logical(b_st, feval(b_st, y, b_y, f_emlrtMCI), g_emlrtMCI));
  b_st.site = &vc_emlrtRSI;
  if (emlrt_marshallIn(
          b_st,
          c_coder_internal_ifWhileCondExt(b_st, emlrtAlias(failp), h_emlrtMCI),
          "<output of coder.internal.ifWhileCondExtrinsic>")) {
    st = -1;
  } else {
    st = 0;
  }
  emlrtDestroyArray(&failp);
  return st;
}

int32_T fileManager(const emlrtStack &sp)
{
  static const int32_T iv[2]{1, 6};
  static const int32_T iv1[2]{1, 3};
  static const char_T u[6]{'f', 'c', 'l', 'o', 's', 'e'};
  static const char_T b_u[3]{'a', 'l', 'l'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *failp;
  const mxArray *m;
  const mxArray *y;
  int32_T f;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &vb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  failp = nullptr;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 6, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a(&st, 3, m, &b_u[0]);
  emlrtAssign(&b_y, m);
  b_st.site = &uc_emlrtRSI;
  emlrtAssign(&failp, logical(b_st, feval(b_st, y, b_y, emlrtMCI), b_emlrtMCI));
  b_st.site = &wc_emlrtRSI;
  if (emlrt_marshallIn(
          b_st,
          c_coder_internal_ifWhileCondExt(b_st, emlrtAlias(failp), c_emlrtMCI),
          "<output of coder.internal.ifWhileCondExtrinsic>")) {
    f = -1;
  } else {
    f = 0;
  }
  emlrtDestroyArray(&failp);
  return f;
}

real_T fileManager(const emlrtStack &sp,
                   const ::coder::array<char_T, 2U> &varargin_1)
{
  static const int32_T iv[2]{1, 5};
  static const char_T u[5]{'f', 'o', 'p', 'e', 'n'};
  emlrtStack b_st;
  emlrtStack st;
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  st.prev = &sp;
  st.tls = sp.tls;
  st.site = &wb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  y = nullptr;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a(&st, 5, m, &u[0]);
  emlrtAssign(&y, m);
  b_y = nullptr;
  m = emlrtCreateString1R2022a(&st, 'w');
  emlrtAssign(&b_y, m);
  b_st.site = &sc_emlrtRSI;
  return b_emlrt_marshallIn(
      b_st,
      feval(b_st, y, emlrt_marshallOut(b_st, varargin_1), b_y, d_emlrtMCI),
      "<output of feval>");
}

} // namespace internal
} // namespace coder

// End of code generation (fileManager.cpp)
