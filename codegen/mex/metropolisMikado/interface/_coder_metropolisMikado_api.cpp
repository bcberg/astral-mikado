//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_metropolisMikado_api.cpp
//
// Code generation for function '_coder_metropolisMikado_api'
//

// Include files
#include "_coder_metropolisMikado_api.h"
#include "metropolisMikado.h"
#include "metropolisMikado_data.h"
#include "metropolisMikado_mexutil.h"
#include "metropolisMikado_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Declarations
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<char_T, 2U> &y);

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret);

static struct0_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *param,
                                    const char_T *identifier);

static struct0_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static char_T d_emlrt_marshallIn(const emlrtStack &sp,
                                 const mxArray *startOrResume,
                                 const char_T *identifier);

static char_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *hyparam,
                             const char_T *identifier, struct1_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *directories,
                             const char_T *identifier, struct2_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *nodes,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y);

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y);

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

static const mxArray *emlrt_marshallOut(const struct3_T u);

static char_T g_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

// Function Definitions
static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               coder::array<char_T, 2U> &y)
{
  c_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               coder::array<real_T, 2U> &ret)
{
  static const int32_T dims[2]{-1, 4};
  int32_T iv[2];
  boolean_T bv[2]{true, false};
  emlrtCheckVsBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "double", false, 2U,
                            (const void *)&dims[0], &bv[0], &iv[0]);
  ret.prealloc(iv[0] * iv[1]);
  ret.set_size(static_cast<emlrtRTEInfo *>(nullptr), &sp, iv[0], iv[1]);
  ret.set(static_cast<real_T *>(emlrtMxGetData(src)), ret.size(0), ret.size(1));
  emlrtDestroyArray(&src);
}

static struct0_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *param,
                                    const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = c_emlrt_marshallIn(sp, emlrtAlias(param), &thisId);
  emlrtDestroyArray(&param);
  return y;
}

static struct0_T c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[3]{"totForce", "kBT", "springK"};
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 3,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "totForce";
  y.totForce = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 0, "totForce")),
      &thisId);
  thisId.fIdentifier = "kBT";
  y.kBT = b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1, "kBT")),
      &thisId);
  thisId.fIdentifier = "springK";
  y.springK = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 2, "springK")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static char_T d_emlrt_marshallIn(const emlrtStack &sp,
                                 const mxArray *startOrResume,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  char_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(startOrResume), &thisId);
  emlrtDestroyArray(&startOrResume);
  return y;
}

static char_T d_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  char_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *hyparam,
                             const char_T *identifier, struct1_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(hyparam), &thisId, y);
  emlrtDestroyArray(&hyparam);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct1_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[12]{
      "nt",        "E",       "ntCheck",      "maxConvChecks",
      "ntAdmit",   "pAdmit",  "epsilonBulk",  "epsilonTop",
      "ksSamples", "ntWrite", "ntWriteFrame", "nextFrame"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 12,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "nt";
  y.nt = b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 0, "nt")),
      &thisId);
  thisId.fIdentifier = "E";
  y.E = b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1, "E")),
      &thisId);
  thisId.fIdentifier = "ntCheck";
  y.ntCheck = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 2, "ntCheck")),
      &thisId);
  thisId.fIdentifier = "maxConvChecks";
  y.maxConvChecks =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 3, "maxConvChecks")),
                         &thisId);
  thisId.fIdentifier = "ntAdmit";
  y.ntAdmit = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 4, "ntAdmit")),
      &thisId);
  thisId.fIdentifier = "pAdmit";
  y.pAdmit = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 5, "pAdmit")),
      &thisId);
  thisId.fIdentifier = "epsilonBulk";
  y.epsilonBulk =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 6, "epsilonBulk")),
                         &thisId);
  thisId.fIdentifier = "epsilonTop";
  y.epsilonTop =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 7, "epsilonTop")),
                         &thisId);
  thisId.fIdentifier = "ksSamples";
  y.ksSamples = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 8, "ksSamples")),
      &thisId);
  thisId.fIdentifier = "ntWrite";
  y.ntWrite = b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 9, "ntWrite")),
      &thisId);
  thisId.fIdentifier = "ntWriteFrame";
  y.ntWriteFrame =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 10, "ntWriteFrame")),
                         &thisId);
  thisId.fIdentifier = "nextFrame";
  y.nextFrame =
      b_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u,
                                                        0, 11, "nextFrame")),
                         &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *directories,
                             const char_T *identifier, struct2_T &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(directories), &thisId, y);
  emlrtDestroyArray(&directories);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T &y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[2]{"dir", "subdir"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtConstCTX)&sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U,
                         (const void *)&dims);
  thisId.fIdentifier = "dir";
  b_emlrt_marshallIn(
      sp, emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 0, "dir")),
      &thisId, y.dir);
  thisId.fIdentifier = "subdir";
  b_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtConstCTX)&sp, u, 0, 1, "subdir")),
      &thisId, y.subdir);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *nodes,
                             const char_T *identifier,
                             coder::array<real_T, 2U> &y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(sp, emlrtAlias(nodes), &thisId, y);
  emlrtDestroyArray(&nodes);
}

static void emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             coder::array<real_T, 2U> &y)
{
  b_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  static const int32_T iv[2]{0, 0};
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

static const mxArray *emlrt_marshallOut(const struct3_T u)
{
  static const char_T *sv[5]{"nt", "E", "epsilonBulk", "epsilonTop",
                             "nextFrame"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *m;
  const mxArray *y;
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 5, (const char_T **)&sv[0]));
  b_y = nullptr;
  m = emlrtCreateDoubleScalar(u.nt);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "nt", b_y, 0);
  c_y = nullptr;
  m = emlrtCreateDoubleScalar(u.E);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "E", c_y, 1);
  d_y = nullptr;
  m = emlrtCreateDoubleScalar(u.epsilonBulk);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "epsilonBulk", d_y, 2);
  e_y = nullptr;
  m = emlrtCreateDoubleScalar(u.epsilonTop);
  emlrtAssign(&e_y, m);
  emlrtSetFieldR2017b(y, 0, "epsilonTop", e_y, 3);
  f_y = nullptr;
  m = emlrtCreateDoubleScalar(u.nextFrame);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(y, 0, "nextFrame", f_y, 4);
  return y;
}

static char_T g_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  char_T ret;
  emlrtCheckBuiltInR2012b((emlrtConstCTX)&sp, msgId, src, "char", false, 0U,
                          (const void *)&dims);
  emlrtImportCharR2015b((emlrtCTX)&sp, src, &ret);
  emlrtDestroyArray(&src);
  return ret;
}

void metropolisMikado_api(const mxArray *const prhs[7], int32_T nlhs,
                          const mxArray *plhs[3])
{
  coder::array<real_T, 2U> nodes;
  coder::array<real_T, 2U> springCatalog;
  coder::array<real_T, 2U> springs;
  coder::array<real_T, 2U> state;
  coder::array<char_T, 2U> energyLogFile;
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  struct0_T param;
  struct1_T hyparam;
  struct2_T directories;
  struct3_T resumeInfo;
  char_T startOrResume;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  // Marshall function inputs
  nodes.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[0]), "nodes", nodes);
  springs.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[1]), "springs", springs);
  springCatalog.no_free();
  emlrt_marshallIn(st, emlrtAlias(prhs[2]), "springCatalog", springCatalog);
  param = c_emlrt_marshallIn(st, emlrtAliasP(prhs[3]), "param");
  emlrt_marshallIn(st, emlrtAliasP(prhs[4]), "hyparam", hyparam);
  emlrt_marshallIn(st, emlrtAliasP(prhs[5]), "directories", directories);
  startOrResume = d_emlrt_marshallIn(st, emlrtAliasP(prhs[6]), "startOrResume");
  // Invoke the target function
  metropolisMikado(&st, nodes, springs, springCatalog, &param, &hyparam,
                   &directories, startOrResume, state, energyLogFile,
                   &resumeInfo);
  // Marshall function outputs
  state.no_free();
  plhs[0] = emlrt_marshallOut(state);
  if (nlhs > 1) {
    plhs[1] = emlrt_marshallOut(st, energyLogFile);
  }
  if (nlhs > 2) {
    plhs[2] = emlrt_marshallOut(resumeInfo);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_metropolisMikado_api.cpp)
