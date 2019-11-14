/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef SIGNAL_GEN_H
#define SIGNAL_GEN_H

#include "ml_types.h"

#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		float32_t amplitude;
		float32_t signal_frequency_hz;
		float32_t phase_rad;
		float32_t sampling_frequency_hz;
		uint32_t sample_counter;
	} sin_opt_t;

	typedef struct {
		float32_t amplitude;
		float32_t signal_frequency_hz;
		float32_t phase_rad;
		float32_t sampling_frequency_hz;
		uint32_t sample_counter;
	} cos_opt_t;

	sample_f32_t ml_sg_sin_get(sin_opt_t *opts);
	sample_f32_t ml_sg_cos_get(cos_opt_t *opts);

#ifdef __cplusplus
}
#endif

#endif /* SIGNAL_GEN_H */

