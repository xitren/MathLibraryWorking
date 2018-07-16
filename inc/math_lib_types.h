/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <assert.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NAME_OF(var)  #var
    
#define assert_param_trueorfalse(X) \
    assert( ( (X) == 0) | ( (X) == 1)); \
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
    
#define assert_param_using(X) \
    if ( (X)->status == MATHLIB_NO ) { \
        return input; \
    } \
    
#define assert_param_morethatzero(X) \
    assert( (X) > 0 ); \
    
typedef int32_t sample_t;

/**
 * @param input Input sample for conversation
 * @return Sample before conversation
 */
typedef sample_t (*fconv)(sample_t const input);

typedef enum {
    MATHLIB_OK = 0,
    MATHLIB_ERROR = -1
} status_t;

typedef enum {
    MATHLIB_NO = 0,
    MATHLIB_YES
} status_using_t;

#ifdef __cplusplus
}
#endif

#endif /* TYPES_H */

