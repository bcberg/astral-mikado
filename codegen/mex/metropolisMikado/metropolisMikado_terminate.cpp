//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// metropolisMikado_terminate.cpp
//
// Code generation for function 'metropolisMikado_terminate'
//

// Include files
#include "metropolisMikado_terminate.h"
#include "_coder_metropolisMikado_mex.h"
#include "metropolisMikado_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void metropolisMikado_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void metropolisMikado_terminate()
{
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (metropolisMikado_terminate.cpp)
