/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef OVERSAMPLING_H
#define OVERSAMPLING_H

#include <stdint.h>
#include "math_library_types.h"

#ifdef __cplusplus
extern "C" {
#endif

int8_t init_resampler_down(transition_oversampling_t *oversampling);

#ifdef __cplusplus
}
#endif

#endif /* OVERSAMPLING_H */

