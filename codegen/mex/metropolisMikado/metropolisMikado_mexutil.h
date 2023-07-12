//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado_mexutil.h
//
// Code generation for function 'metropolisMikado_mexutil'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
real_T b_emlrt_marshallIn(const emlrtStack &sp,
                          const mxArray *a__output_of_feval_,
                          const char_T *identifier);

real_T b_emlrt_marshallIn(const emlrtStack &sp, const mxArray *u,
                          const emlrtMsgIdentifier *parentId);

void c_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                        const emlrtMsgIdentifier *msgId,
                        coder::array<char_T, 2U> &ret);

const mxArray *emlrt_marshallOut(const emlrtStack &sp,
                                 const coder::array<char_T, 2U> &u);

real_T f_emlrt_marshallIn(const emlrtStack &sp, const mxArray *src,
                          const emlrtMsgIdentifier *msgId);

const mxArray *feval(const emlrtStack &sp, const mxArray *m1, const mxArray *m2,
                     const mxArray *m3, emlrtMCInfo &location);

// End of code generation (metropolisMikado_mexutil.h)
