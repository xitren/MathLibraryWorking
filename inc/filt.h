/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef FILTRATION_H
#define FILTRATION_H

#include <stdint.h>
#include <stddef.h>
#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ML_FILT_SETS(POINTER, \
                    NAME, \
                    USE, \
                    TYPE_FILTER, \
                    ORDER_FILTER, \
                    SAMPLING_FREQUENCY, \
                    CUTOFF_FREQUENCY, \
                    LENGTH_BUFFER, \
                    TEMP_BUFFER, \
                    IBUFFER, \
                    OBEFFER, \
                    COEFFICIENTS) { \
    assert_param_existpointer(NAME); \
    (POINTER).name              = (NAME); \
    assert_param_trueorfalse(USE); \
    (POINTER).status            = (USE) ? MATHLIB_YES : MATHLIB_NO; \
    (POINTER).filter_type       = (TYPE_FILTER); \
    assert_param_morethatzero(ORDER_FILTER); \
    (POINTER).order             = (ORDER_FILTER); \
    assert_param_morethatzero(SAMPLING_FREQUENCY); \
    (POINTER).sampl_freq_hz     = (SAMPLING_FREQUENCY); \
    assert_param_morethatzero(CUTOFF_FREQUENCY); \
    (POINTER).cutoff_freq_hz    = (CUTOFF_FREQUENCY); \
    assert_param_morethatzero(LENGTH_BUFFER); \
    (POINTER).length_buffer     = (LENGTH_BUFFER); \
    (POINTER).m_buffer          = (TEMP_BUFFER); \
    (POINTER).inp_buffer        = (IBUFFER); \
    (POINTER).out_buffer        = (OBEFFER); \
    (POINTER).coeff             = (COEFFICIENTS); }\
    
typedef enum
{
    MATHLIB_FILT_LOWPASS = 0,
    MATHLIB_FILT_HIGHPASS,
    MATHLIB_FILT_USERS
} filter_t;
    
typedef struct {
    status_using_t  status;
    unsigned char   *name;
    filter_t        filter_type;
    uint32_t        order;
    double          sampl_freq_hz;
    double          cutoff_freq_hz;
    size_t          length_buffer;
    sample_t        *m_buffer;
    sample_t        *inp_buffer;
    sample_t        *out_buffer;
    double          *coeff;
    uint32_t        m_n_buffer_index;   /* Not used for init */
    uint32_t        buffer_it;          /* Not used for init */
} transition_filt_t;

/**
 * Initialization and validation filter structure
 * @param filt Structure pointer for filter
 * @return Status about validation
 */
status_t ml_filt_init(transition_filt_t *filt);

/**
 * Getting sample after filtration
 * @param filt Structure pointer of filter
 * @param input Sample for filtration
 * @return Status about coefficient created
 */
sample_t ml_filt_get(transition_filt_t *filt, sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* FILTRATION_H */

