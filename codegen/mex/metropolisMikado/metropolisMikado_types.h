//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado_types.h
//
// Code generation for function 'metropolisMikado'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T {
  real_T totForce;
  real_T kBT;
  real_T springK;
};

struct struct1_T {
  real_T nt;
  real_T E;
  real_T ntCheck;
  real_T maxConvChecks;
  real_T ntAdmit;
  real_T pAdmit;
  real_T epsilonBulk;
  real_T epsilonTop;
  real_T ksSamples;
  real_T ntWrite;
  real_T ntWriteFrame;
  real_T nextFrame;
};

struct struct3_T {
  real_T nt;
  real_T E;
  real_T epsilonBulk;
  real_T epsilonTop;
  real_T nextFrame;
};

struct struct2_T {
  coder::array<char_T, 2U> dir;
  coder::array<char_T, 2U> subdir;
};

// End of code generation (metropolisMikado_types.h)
