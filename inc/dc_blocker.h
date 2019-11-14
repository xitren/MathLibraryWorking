/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef DC_BLOCKER_H
#define DC_BLOCKER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include "ml_types.h"

	typedef struct {
		char *name;
		float32_t cutoff_freq_hz; /* Sampling frequency of signals, Hz. Must be more than zero */
		float32_t sampling_freq_hz; /* Sampling frequency of signals, Hz. Must be more than zero */
		float32_t alpha; /* Not used for init */
		float32_t temp; /* Not used for init */
		float32_t xn_1; /* Not used for init */
		float32_t yn_1; /* Not used for init */
	} dc_blocker_opt_t;

	ml_status_t ml_dc_blocker_init(dc_blocker_opt_t *opt);
	sample_si32_t ml_dc_blocker_get(dc_blocker_opt_t *opt, sample_si32_t x_n);

#ifdef __cplusplus
}
#endif

#endif /* DC_BLOCKER_H */

