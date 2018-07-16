/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef AMPL_H
#define AMPL_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "math_lib_types.h"

#define ML_AMPL_SETS(POINTER, \
                    USE_BORDER, \
                    USE_LOG, \
                    MAX, \
                    MIN) { \
    assert_param_trueorfalse(USE_BORDER); \
    (POINTER).status_border = (USE_BORDER) ? MATHLIB_YES : MATHLIB_NO; \
    assert_param_trueorfalse(USE_LOG); \
    (POINTER).status_log    = (USE_LOG) ? MATHLIB_YES : MATHLIB_NO; \
    assert_param_notzero(MAX); \
    assert_param_notzero(MIN); \
    (POINTER).max           = (MAX); \
    (POINTER).min           = (MIN); } \
    
typedef struct {
    status_using_t  status_border;
    status_using_t  status_log;
    int32_t         max;
    int32_t         min;
} transition_ampl_t;


status_t ml_ampl_init(transition_ampl_t *ampl);


sample_t ml_ampl_get(transition_ampl_t *ampl, sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* AMPL_H */

