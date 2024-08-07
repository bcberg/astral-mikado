//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// rand.h
//
// Code generation for function 'rand'
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
void b_rand(const emlrtStack &sp, const real_T varargin_1[2],
            array<real_T, 2U> &r);

void c_rand(const emlrtStack &sp, const real_T varargin_1[2],
            array<real_T, 2U> &r);

} // namespace coder

// End of code generation (rand.h)
