/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SIGNAL_GEN_H
#define SIGNAL_GEN_H

#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif
    
typedef struct {
    double     amplitude;
    double     frequency_hz;
    double     phase_rad;
    double     sampling_frequency_hz;
    uint32_t   sample_counter;
} sygnal_options_t;

sample_t ml_sig_gen_get_sample(sygnal_options_t *sin_sets);

#ifdef __cplusplus
}
#endif

#endif /* SIGNAL_GEN_H */

