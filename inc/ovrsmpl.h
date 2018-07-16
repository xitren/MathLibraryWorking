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

typedef struct {
    status_using_t      status_ovrsmpl;
    unsigned char       *name;
    double              source_frequency_hz;
    double              target_frequency_hz;
    uint32_t            filter_order;
    
    transition_filt_t   *filt;          /* Not used for init */
    sample_t            *buffer;        /* Not used for init */
    size_t              buffer_size;    /* Not used for init */
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

