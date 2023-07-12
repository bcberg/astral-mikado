//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_metropolisMikado_mex.cpp
//
// Code generation for function '_coder_metropolisMikado_mex'
//

// Include files
#include "_coder_metropolisMikado_mex.h"
#include "_coder_metropolisMikado_api.h"
#include "metropolisMikado_data.h"
#include "metropolisMikado_initialize.h"
#include "metropolisMikado_terminate.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void metropolisMikado_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
                                  const mxArray *prhs[7])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *b_prhs[7];
  const mxArray *outputs[3];
  int32_T i1;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        16, "metropolisMikado");
  }
  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "metropolisMikado");
  }
  // Call the function.
  for (int32_T i{0}; i < 7; i++) {
    b_prhs[i] = prhs[i];
  }
  metropolisMikado_api(b_prhs, nlhs, outputs);
  // Copy over outputs to the caller.
  if (nlhs < 1) {
    i1 = 1;
  } else {
    i1 = nlhs;
  }
  emlrtReturnArrays(i1, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&metropolisMikado_atexit);
  // Module initialization.
  metropolisMikado_initialize();
  try {
    // Dispatch the entry-point.
    metropolisMikado_mexFunction(nlhs, plhs, nrhs, prhs);
    // Module termination.
    metropolisMikado_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge, "windows-1252", true);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_metropolisMikado_mex.cpp)
