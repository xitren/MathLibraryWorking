/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef FILTRATION_H
#define FILTRATION_H

#include <stdint.h>
#include <stddef.h>
#include "ml_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ML_FILT_SETS(PNTR, \
                    NAME, \
                    TYPE_FILTER, \
                    ORDER_FILTER, \
                    SAMPLING_FREQUENCY, \
                    CUTOFF_FREQUENCY, \
                    LENGTH_BUFFER, \
                    PNTR_TEMP_BUFFER, \
                    PNTR_IBUFFER, \
                    PNTR_OBEFFER, \
                    PNTR_COEFFICIENTS) { \
    assert_param_existpointer(NAME); \
    (PNTR).name              = (NAME); \
    assert_param_range(MATHLIB_FILT_LOWPASS, (TYPE_FILTER), MATHLIB_FILT_USERS); \
    (PNTR).filter_type       = (TYPE_FILTER); \
    assert_param_morethatzero(ORDER_FILTER); \
    (PNTR).order             = (ORDER_FILTER); \
    assert_param_morethatzero(SAMPLING_FREQUENCY); \
    (PNTR).sampl_freq_hz     = (SAMPLING_FREQUENCY); \
    assert_param_morethatzero(CUTOFF_FREQUENCY); \
    (PNTR).cutoff_freq_hz    = (CUTOFF_FREQUENCY); \
    assert_param_morethatzero(LENGTH_BUFFER); \
    (PNTR).length_buffer     = (LENGTH_BUFFER); \
    assert_param_existpointer(PNTR_TEMP_BUFFER); \
    assert_param_existpointer(PNTR_IBUFFER); \
    assert_param_existpointer(PNTR_OBEFFER); \
    assert_param_existpointer(PNTR_COEFFICIENTS); \
    (PNTR).m_buffer          = (PNTR_TEMP_BUFFER); \
    (PNTR).inp_buffer        = (PNTR_IBUFFER); \
    (PNTR).out_buffer        = (PNTR_OBEFFER); \
    (PNTR).coeff             = (PNTR_COEFFICIENTS); } \
    

	typedef enum {
		MATHLIB_FILT_LOWPASS = 0,
		MATHLIB_FILT_HIGHPASS,
		MATHLIB_FILT_USERS
	} filter_t;

	typedef struct {
		char *name; /* Name filter */
		filter_t filter_type; /* Filter type (MATHLIB_FILT_LOWPASS, MATHLIB_FILT_HIGHPASS, MATHLIB_FILT_USERS) */
		uint32_t order; /* Order filter. Must be more than zero */
		float32_t sampl_freq_hz; /* Sampling frequency of signals, Hz. Must be more than zero */
		float32_t cutoff_freq_hz; /* Cutoff frequency for filter, Hz. Must be more than zero */
		size_t length_buffer; /* Buffer size. Must be more than zero */
		sample_si32_t *m_buffer; /* Pointer for temp buffer. Minimal buffer size must be is @order */
		sample_si32_t *inp_buffer; /*  */
		sample_si32_t *out_buffer;
		float32_t *coeff; /* Pointer for coefficients array. Array size must be is @order */
		uint32_t m_n_buffer_index; /* Not used for init */
		uint32_t buffer_it; /* Not used for init */
	} filt_opt_t;

	/**
	 * Initialization and validation filter structure
	 * @param filt Structure pointer for filter
	 * @return Status about validation
	 */
	ml_status_t ml_filt_init(filt_opt_t *filt);

	/**
	 * Getting sample after filtration
	 * @param filt Structure pointer of filter
	 * @param input Sample for filtration
	 * @return Status about coefficient created
	 */
	sample_si32_t ml_filt_get(filt_opt_t *filt, sample_si32_t input);

#ifdef __cplusplus
}
#endif

#endif /* FILTRATION_H */

