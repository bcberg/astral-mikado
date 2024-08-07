//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_generateAstralNetwork_api.cpp
//
// Code generation for function '_coder_generateAstralNetwork_api'
//

// Include files
#include "_coder_generateAstralNetwork_api.h"
#include "generateAstralNetwork.h"
#include "generateAstralNetwork_data.h"
#include "generateAstralNetwork_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier);

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *emlrt_marshallOut(const struct0_T &u);

static const mxArray *emlrt_marshallOut(const struct1_T &u);

static const mxArray *emlrt_marshallOut(const struct2_T &u);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 0U,
                          (const void *)&dims);
  ret = *static_cast<real_T *>(emlrtMxGetData(src));
  emlrtDestroyArray(&src);
  return ret;
}

static const mxArray *b_emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = u.size(1);
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(1); b_i++) {
    for (int32_T c_i{0}; c_i < u.size(0); c_i++) {
      pData[i] = u[c_i + u.size(0) * b_i];
      i++;
    }
  }
  emlrtAssign(&y, m);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *b_nullptr,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(sp, emlrtAlias(b_nullptr), &thisId);
  emlrtDestroyArray(&b_nullptr);
  return y;
}

static real_T emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = b_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct0_T &u)
{
  static const char_T *sv[4]{"nodes", "augNodes", "springs", "ends"};
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T i;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 4, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, "nodes", emlrt_marshallOut(u.nodes), 0);
  emlrtSetFieldR2017b(y, 0, "augNodes", emlrt_marshallOut(u.augNodes), 1);
  b_y = nullptr;
  iv[0] = u.springs.size(0);
  iv[1] = 4;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.springs.size(0); b_i++) {
    pData[i] = u.springs[b_i];
    i++;
  }
  for (int32_T b_i{0}; b_i < u.springs.size(0); b_i++) {
    pData[i] = u.springs[b_i + u.springs.size(0)];
    i++;
  }
  for (int32_T b_i{0}; b_i < u.springs.size(0); b_i++) {
    pData[i] = u.springs[b_i + u.springs.size(0) * 2];
    i++;
  }
  for (int32_T b_i{0}; b_i < u.springs.size(0); b_i++) {
    pData[i] = u.springs[b_i + u.springs.size(0) * 3];
    i++;
  }
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "springs", b_y, 2);
  emlrtSetFieldR2017b(y, 0, "ends", emlrt_marshallOut(u.ends), 3);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct1_T &u)
{
  static const char_T *sv[2]{"centerCross", "filCross"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, "centerCross", b_emlrt_marshallOut(u.centerCross),
                      0);
  emlrtSetFieldR2017b(y, 0, "filCross", emlrt_marshallOut(u.filCross), 1);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct2_T &u)
{
  static const char_T *sv[2]{"centers", "orients"};
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(y, 0, "centers", emlrt_marshallOut(u.centers), 0);
  emlrtSetFieldR2017b(y, 0, "orients", b_emlrt_marshallOut(u.orients), 1);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T iv[2];
  int32_T i;
  y = nullptr;
  iv[0] = u.size(0);
  iv[1] = 2;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (int32_T b_i{0}; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i];
    i++;
  }
  for (int32_T b_i{0}; b_i < u.size(0); b_i++) {
    pData[i] = u[b_i + u.size(0)];
    i++;
  }
  emlrtAssign(&y, m);
  return y;
}

void generateAstralNetwork_api(const mxArray *const prhs[4], int32_T nlhs,
                               const mxArray *plhs[3])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T network;
  struct1_T crossings;
  struct2_T asters;
  real_T D;
  real_T astralNum;
  real_T l;
  real_T numAsters;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  numAsters = emlrt_marshallIn(st, emlrtAliasP(prhs[0]), "numAsters");
  l = emlrt_marshallIn(st, emlrtAliasP(prhs[1]), "l");
  D = emlrt_marshallIn(st, emlrtAliasP(prhs[2]), "D");
  astralNum = emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "astralNum");
  // Invoke the target function
  generateAstralNetwork(&st, numAsters, l, D, astralNum, &network, &crossings,
                        &asters);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(network);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(crossings);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(asters);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_generateAstralNetwork_api.cpp)
