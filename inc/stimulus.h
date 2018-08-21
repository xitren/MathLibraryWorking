/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef STIMULUS_H
#define STIMULUS_H

#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char *name; /* Name of structure */
    status_using_t status; /* (MATHLIB_YES or MATHLIB_NO) */
    uint32_t freq_hz; /* Frequency sampling */

    uint32_t freq_stimulus_hz; /* Frequency stimulus */
    uint32_t num_stimulus; /* Number stimulus in process */
    uint32_t durat_stimulus_ms; /* Duration of presentation */

    uint32_t timeout_ms; /* Timeout beetween stimulus */
} stimulus_freq_t;

void stimulus_init(
    int _number_of_targ,
    int _number_of_targ_rep,
    int _number_of_stimulus,
    int _freq,
    int _stim_lenght,
    int _wait_between_stim,
    int _wait_before_targ );

void stimulus_get(int *targ, int *stim);

void stimulus_init_freq(stimulus_freq_t str_stim);
void stimulus_get_freq(stimulus_freq_t *str_stim, int *targ, int *stim);

#ifdef __cplusplus
}
#endif

#endif /* STIMULUS_H */

