/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef IIR_H
#define IIR_H

#include "ml_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char        *name;              /* Name filter */
    float32_t   sampling_freq_hz;      /* Sampling frequency of signals, Hz. Must be more than zero */
    float32_t   notch_freq_hz;     /* Notch frequency */
    float32_t   a1;     /* Not used for init */
    float32_t   a2;     /* Not used for init */
    float32_t   b0;     /* Not used for init */
    float32_t   b1;     /* Not used for init */
    float32_t   b2;     /* Not used for init */
    float32_t   G;      /* Not used for init */
    float32_t   x_1;    /* Not used for init */
    float32_t   x_2;    /* Not used for init */
    float32_t   y_1;    /* Not used for init */
    float32_t   y_2;    /* Not used for init */
} iir_notch_opt_t;

void ml_iir_notch_init(iir_notch_opt_t *option);
sample_si32_t ml_iir_notch_get(iir_notch_opt_t *option, sample_si32_t input);

#ifdef __cplusplus
}
#endif

#endif /* IIR_H */

