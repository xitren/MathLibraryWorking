/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   polynom.h
 * Author: prilutsky_d
 *
 * Created on 4 июня 2018 г., 15:35
 */

#ifndef POLYNOM_H
#define POLYNOM_H

#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ML_POLY_SETS(POINTER, \
                    NAME, \
                    USE, \
                    SIZE, \
                    ELEMENTS_POINTER) \
    assert_param_existpointer(NAME); \
    (POINTER).name      = (NAME); \
    assert_param_trueorfalse(USE); \
    (POINTER).status    = (USE) ? (MATHLIB_YES) : (MATHLIB_NO); \
    assert_param_morethatzero(SIZE); \
    (POINTER).size      = (SIZE); \
    assert_param_existpointer(ELEMENTS_POINTER); \
    (POINTER).elements  = (ELEMENTS_POINTER); \
    
typedef struct {
    double coeff;
    double power;
} element_t;

typedef struct {
    unsigned char   *name;
    status_using_t  status;
    size_t          size;
    element_t       *elements;
} transition_poly_t;


status_t ml_poly_init(transition_poly_t *poly);


sample_t ml_poly_get(transition_poly_t *poly, const sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* POLYNOM_H */

