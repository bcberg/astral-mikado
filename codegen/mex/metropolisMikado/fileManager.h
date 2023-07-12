//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fileManager.h
//
// Code generation for function 'fileManager'
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
namespace coder {
namespace internal {
real_T b_fileManager(const emlrtStack &sp,
                     const ::coder::array<char_T, 2U> &varargin_1);

int32_T cfclose(const emlrtStack &sp, real_T fid);

int32_T fileManager(const emlrtStack &sp);

real_T fileManager(const emlrtStack &sp,
                   const ::coder::array<char_T, 2U> &varargin_1);

} // namespace internal
} // namespace coder

// End of code generation (fileManager.h)
