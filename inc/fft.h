/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef FFT_H
#define FFT_H

#include "ml_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int32_t         min_frequency;
    int32_t         max_frequency;
} transition_fft_t;

#ifdef __cplusplus
}
#endif

#endif /* FFT_H */

