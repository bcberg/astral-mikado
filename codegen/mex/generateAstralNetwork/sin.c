/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sin.c
 *
 * Code generation for function 'sin'
 *
 */

/* Include files */
#include "sin.h"
#include "eml_int_forloop_overflow_check.h"
#include "generateAstralNetwork_data.h"
#include "generateAstralNetwork_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include "omp.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = {
    11,                                                           /* lineNo */
    "sin",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024a/toolbox/eml/lib/matlab/elfun/sin.m" /* pathName */
};

/* Function Definitions */
void b_sin(const emlrtStack *sp, emxArray_real_T *x)
{
  jmp_buf *volatile emlrtJBStack;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T b_sin_numThreads;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &u_emlrtRSI;
  nx = x->size[0] * x->size[1];
  b_st.site = &s_emlrtRSI;
  if (nx > 2147483646) {
    c_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  if (nx < 3200) {
    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarSin(x_data[k]);
    }
  } else {
    emlrtEnterParallelRegion(&st, omp_in_parallel());
    emlrtPushJmpBuf(&st, &emlrtJBStack);
    b_sin_numThreads = emlrtAllocRegionTLSs(
        st.tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs());
#pragma omp parallel for num_threads(b_sin_numThreads)

    for (k = 0; k < nx; k++) {
      x_data[k] = muDoubleScalarSin(x_data[k]);
    }
    emlrtPopJmpBuf(&st, &emlrtJBStack);
    emlrtExitParallelRegion(&st, omp_in_parallel());
  }
}

/* End of code generation (sin.c) */
