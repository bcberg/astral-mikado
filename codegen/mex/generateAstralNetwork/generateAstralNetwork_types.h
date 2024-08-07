//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// generateAstralNetwork_types.h
//
// Code generation for function 'generateAstralNetwork'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  coder::array<real_T, 2U> nodes;
  coder::array<real_T, 2U> augNodes;
  coder::array<real_T, 2U> springs;
  coder::array<real_T, 2U> ends;
};

struct struct1_T {
  coder::array<real_T, 2U> centerCross;
  coder::array<real_T, 2U> filCross;
};

struct struct2_T {
  coder::array<real_T, 2U> centers;
  coder::array<real_T, 2U> orients;
};

// End of code generation (generateAstralNetwork_types.h)
