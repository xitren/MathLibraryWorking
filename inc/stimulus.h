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

void init_stimulus(
    int _number_of_targ,
    int _number_of_targ_rep,
    int _number_of_stimulus,
    int _freq,
    int _stim_lenght,
    int _wait_between_stim,
    int _wait_before_targ );

void get_stimulus(int *targ, int *stim);


#ifdef __cplusplus
}
#endif

#endif /* STIMULUS_H */

