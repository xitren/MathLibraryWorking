/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef POLYNOM_H
#define POLYNOM_H

#include "ml_types.h"

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
    assert_param_morethatzero(SIZE); \
    (POINTER).size      = (SIZE); \
    assert_param_existpointer(ELEMENTS_POINTER); \
    (POINTER).elements  = (ELEMENTS_POINTER); \
    

	typedef struct {
		double coeff;
		double power;
	} element_t;

	typedef struct {
		unsigned char *name;
		size_t size;
		element_t *elements;
	} poly_opt_t;


	ml_status_t ml_poly_init(poly_opt_t *poly);


	sample_si32_t ml_poly_get(poly_opt_t *poly, const sample_si32_t input);

#ifdef __cplusplus
}
#endif

#endif /* POLYNOM_H */

