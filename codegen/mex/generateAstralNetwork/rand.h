/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#pragma once

/* Include files */
#include "generateAstralNetwork_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_rand(const emlrtStack *sp, const real_T varargin_1[2],
            emxArray_real_T *r);

void c_rand(const emlrtStack *sp, const real_T varargin_1[2],
            emxArray_real_T *r);

/* End of code generation (rand.h) */
