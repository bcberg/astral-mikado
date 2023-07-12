//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sprintf.h
//
// Code generation for function 'sprintf'
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
void b_sprintf(const emlrtStack &sp, int32_T varargin_1,
               ::coder::array<char_T, 2U> &str);

}

// End of code generation (sprintf.h)
