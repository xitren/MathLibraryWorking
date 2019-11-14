/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef ML_TYPES_H
#define ML_TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>
#include "arm_math.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ABS(X)  (X > 0) ? (X) : (-1 * X)

#define NAME_OF(var)  #var

#define assert_param_trueorfalse(X) \
    assert(((X) == 0) || ((X) == 1)); \
    /*
    if ((X != 0) | (X != 1)) { \
        printf("%s: Error %s must be not zero!\n\r", __func__, NAME_OF(X)); \
        return MATHLIB_ERROR; \
    } \
    */

#define assert_param_notzero(X) \
    assert( (X) ); \
    /*
    if ( !(X) ) { \
        printf("%s: Error %s must be not zero!\n\r", __func__, NAME_OF(X)); \
        return MATHLIB_ERROR; \
    } \
    */

#define assert_param_existpointer(X) \
    assert( (X) ); \
    /*
    if ( !(X) ) { \
        printf("%s: Error pointer for %s!\n\r", __func__, NAME_OF(X)); \
        return MATHLIB_ERROR; \
    } \
    */

#define assert_param_morethatzero(X) \
    assert((X) > 0); \
    
#define assert_param_range(BORDER_LOWEST, X, BORDER_HIGHEST) \
    assert(((uint32_t)BORDER_LOWEST >= (X)) && ((X) <= (uint32_t)BORDER_HIGHEST)); \
    
	typedef int32_t sample_si32_t;
	typedef float32_t sample_f32_t;

	typedef enum {
		MATHLIB_OK = 0,
		MATHLIB_ERROR = -1
	} ml_status_t;

#ifdef __cplusplus
}
#endif

#endif /* ML_TYPES_H */

