//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// norm.h
//
// Code generation for function 'norm'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
real_T b_norm(const emlrtStack &sp, const real_T x_data[],
              const int32_T x_size[2]);

}

// End of code generation (norm.h)
