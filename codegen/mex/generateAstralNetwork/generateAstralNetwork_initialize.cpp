//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// generateAstralNetwork_initialize.cpp
//
// Code generation for function 'generateAstralNetwork_initialize'
//

// Include files
#include "generateAstralNetwork_initialize.h"
#include "_coder_generateAstralNetwork_mex.h"
#include "generateAstralNetwork_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void generateAstralNetwork_once();

// Function Definitions
static void generateAstralNetwork_once()
{
  mex_InitInfAndNan();
}

void generateAstralNetwork_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2022b(&st);
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    generateAstralNetwork_once();
  }
}

// End of code generation (generateAstralNetwork_initialize.cpp)
