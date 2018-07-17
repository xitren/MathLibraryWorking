/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef OVRSMPL_H
#define OVRSMPL_H

#include <stdint.h>
#include "filt.h"
#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ML_OVRSMPL_SETS(PNTR, \
                    NAME, \
                    USE, \
                    SOURCE_FREQUENCY, \
                    TARGET_FREQUENCY, \
                    FILTER_ORDER, \
                    PNTR_BUFFER, \
                    LENGTH_BUFFER, \
                    FILTER_LENGTH_BUFFER, \
                    PNTR_FILTER_TEMP_BUFFER, \
                    PNTR_FILTER_IBUFFER, \
                    PNTR_FILTER_OBEFFER, \
                    PNTR_FILTER_COEFFICIENTS ) {                                \
    assert_param_existpointer(NAME);                                            \
    assert_param_trueorfalse(USE);                                              \
    assert_param_morethatzero(SOURCE_FREQUENCY);                                \
    assert_param_morethatzero(TARGET_FREQUENCY);                                \
    assert_param_range( 0, (TARGET_FREQUENCY), (SOURCE_FREQUENCY) );            \
    assert_param_existpointer(PNTR_BUFFER);                                     \
    assert_param_morethatzero(LENGTH_BUFFER);                                   \
    (PNTR).name             = (NAME);                                           \
    (PNTR).status           = (USE) ? MATHLIB_YES : MATHLIB_NO;                 \
    (PNTR).source_freq_hz   = (SOURCE_FREQUENCY);                               \
    (PNTR).target_freq_hz   = (TARGET_FREQUENCY);                               \
    (PNTR).buffer           = (PNTR_BUFFER);                                    \
    (PNTR).length_buffer    = (LENGTH_BUFFER);                                  \
    assert_param_morethatzero(FILTER_LENGTH_BUFFER);                            \
    assert_param_morethatzero(FILTER_ORDER);                                    \
    assert_param_existpointer(PNTR_FILTER_TEMP_BUFFER);                         \
    assert_param_existpointer(PNTR_FILTER_IBUFFER);                             \
    assert_param_existpointer(PNTR_FILTER_OBEFFER);                             \
    assert_param_existpointer(PNTR_FILTER_COEFFICIENTS);                        \
    (PNTR).filt.length_buffer = (FILTER_LENGTH_BUFFER);                 \
    (PNTR).filt.order         = (FILTER_ORDER);                         \
    (PNTR).filt.m_buffer      = (PNTR_FILTER_TEMP_BUFFER);              \
    (PNTR).filt.inp_buffer    = (PNTR_FILTER_IBUFFER);                  \
    (PNTR).filt.out_buffer    = (PNTR_FILTER_OBEFFER);                  \
    (PNTR).filt.coeff         = (PNTR_FILTER_COEFFICIENTS); }           \
    
typedef struct {
    unsigned char       *name;
    status_using_t      status;
    double              source_freq_hz;
    double              target_freq_hz;
    
    transition_filt_t   filt;          /*  */
    sample_t            *buffer;        /*  */
    size_t              length_buffer;  /*  */
    uint32_t            buffer_mask;    /* Not used for init */
    uint32_t            step;           /* Not used for init */
    uint32_t            read_pos;       /* Not used for init */
    uint32_t            write_pos;      /* Not used for init */
    uint32_t            sub_pos;        /* Not used for init */
} transition_ovrsmpl_t;

int8_t ml_ovrsmpl_init_down(transition_ovrsmpl_t *ovrsmpl);

void ml_ovrsmpl_push(transition_ovrsmpl_t *ovrsmpl, sample_t input);

sample_t ml_ovrsmpl_pull(transition_ovrsmpl_t *ovrsmpl);

#ifdef __cplusplus
}
#endif

#endif /* OVRSMPL_H */

