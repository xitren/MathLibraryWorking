/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "lut.h"
#include "poly.h"
#include "ampl.h"
#include "filt.h"
#include "rms.h"
#include "fft.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    CONV_OK                     = 0,
    CONV_ERROR_TYPE_TABLE       = -1,
    CONV_ERROR_SIZE_TABLE       = -2,
    CONV_ERROR_SYSTEM_MEMORY    = -3
} status_convs_t;

typedef struct {
    sample_t     *buffer;
    size_t       size;
} resul_t;

typedef struct {
    transition_lut_t    lut;
    transition_poly_t   poly;
    transition_ampl_t   ampl;
    transition_filt_t   filt;
    transition_rms_t    rms;
    transition_fft_t    fft;
    resul_t             result;
} convs_t;


status_convs_t ml_convs_init(convs_t *convs);


sample_t ml_convs_get(convs_t *convs, sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* CONVERSION_H */

