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
#include "math_library_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum
{
    CONV_OK                     = 0,
    CONV_ERROR_TYPE_TABLE       = -1,
    CONV_ERROR_SIZE_TABLE       = -2,
    CONV_ERROR_SYSTEM_MEMORY    = -3
} status_conv_t;

extern resul_t result;

status_conv_t fconversion(lut_t const LUT, int32_t const *inp, size_t size_inp);

#ifdef __cplusplus
}
#endif

#endif /* CONVERSION_H */

