//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado_initialize.cpp
//
// Code generation for function 'metropolisMikado_initialize'
//

// Include files
#include "metropolisMikado_initialize.h"
#include "_coder_metropolisMikado_mex.h"
#include "metropolisMikado_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void metropolisMikado_once();

// Function Definitions
static void metropolisMikado_once()
{
  mex_InitInfAndNan();
}

void metropolisMikado_initialize()
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
    metropolisMikado_once();
  }
}

// End of code generation (metropolisMikado_initialize.cpp)
