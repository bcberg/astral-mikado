//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fwrite.h
//
// Code generation for function 'fwrite'
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
void b_fwrite(const emlrtStack &sp, real_T fileID, real_T x);

void b_fwrite(const emlrtStack &sp, real_T fileID,
              const ::coder::array<real_T, 2U> &x);

} // namespace coder

// End of code generation (fwrite.h)
