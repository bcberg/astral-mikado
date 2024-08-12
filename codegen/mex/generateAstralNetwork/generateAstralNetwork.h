//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// generateAstralNetwork.h
//
// Code generation for function 'generateAstralNetwork'
//

#pragma once

// Include files
#include "generateAstralNetwork_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
emlrtCTX emlrtGetRootTLSGlobal();

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

void generateAstralNetwork(const emlrtStack *sp, real_T numAsters, real_T l,
                           real_T D, real_T astralNum, struct0_T *network,
                           struct1_T *crossings, struct2_T *asters);

// End of code generation (generateAstralNetwork.h)
