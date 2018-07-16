/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef RMS_H
#define RMS_H

#include <stddef.h>
#include "math_lib_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    unsigned char   *name;
    status_using_t  status;
    sample_t        *buffer;
    size_t          size;
} transition_rms_t;
    

sample_t ml_rms_get(transition_rms_t *rms, sample_t input);


sample_t ml_rms_init(sample_t input);

#ifdef __cplusplus
}
#endif

#endif /* RMS_H */

