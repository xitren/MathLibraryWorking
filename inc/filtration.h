/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   filtration.h
 * Author: prilutsky_d
 *
 * Created on 2 июня 2018 г., 20:45
 */

#ifndef FILTRATION_H
#define FILTRATION_H

#include <stdint.h>
#include <stddef.h>
#include "math_library_types.h"

#ifdef __cplusplus
extern "C" {
#endif

int8_t filter_init(transition_filter_t *filter, double *coef_h);
sample_t filtration(sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* FILTRATION_H */

