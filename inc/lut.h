/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ML_LUT_SETS(POINTER, \
                    NAME, \
                    USE, \
                    SIZE, \
                    TABLE_POINTER) { \
    assert_param_existpointer(NAME); \
    (POINTER).name    = (NAME); \
    assert_param_trueorfalse(USE); \
    (POINTER).status  = (USE) ? MATHLIB_YES : MATHLIB_NO; \
    assert_param_morethatzero(SIZE); \
    (POINTER).size    = (SIZE); \
    assert_param_existpointer(TABLE_POINTER); \
    (POINTER).table   = (TABLE_POINTER); } \
    
typedef struct {
    unsigned char   *name;
    status_using_t  status;
    sample_t        *table;
    size_t          size;
} transition_lut_t;


status_t ml_lut_init(transition_lut_t *lut);


sample_t ml_lut_get(transition_lut_t *lut, const sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* CAESAR_CIPHER_H */

