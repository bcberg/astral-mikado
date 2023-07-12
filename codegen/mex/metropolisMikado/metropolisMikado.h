//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado.h
//
// Code generation for function 'metropolisMikado'
//

#pragma once

// Include files
#include "metropolisMikado_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void metropolisMikado(const emlrtStack *sp,
                      const coder::array<real_T, 2U> &nodes,
                      const coder::array<real_T, 2U> &springs,
                      const coder::array<real_T, 2U> &springCatalog,
                      const struct0_T *param, const struct1_T *hyparam,
                      const struct2_T *directories, char_T startOrResume,
                      coder::array<real_T, 2U> &state,
                      coder::array<char_T, 2U> &energyLogFile,
                      struct3_T *resumeInfo);

// End of code generation (metropolisMikado.h)
