/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   types.h
 * Author: prilutsky_d
 *
 * Created on 2 июня 2018 г., 21:08
 */

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <stddef.h>

#define MATHLIB_OK       (0)
#define MATHLIB_ERROR    (-1)

#define NAME_OF(var)  #var

#ifdef __cplusplus
extern "C" {
#endif

typedef int32_t sample_t;

typedef enum
{
    STATIC,
    DYNAMIC,
    NOT_USE
} type_table_t;

typedef enum
{
    YES,
    NO
} status_using_t;

typedef enum
{
    LOWPASS,
    HIGPASS,
    USERS
} filter_t;

typedef struct {
    int32_t     *buffer;
    size_t      size;
} resul_t;

typedef struct {
    int32_t     amplitude;
    int32_t     frequency_hz;
    int32_t     phase_rad;
    int32_t     sampling_frequency_hz;
    int32_t     sample_counter;
} sygnal_options_t;

typedef struct {
    int32_t     coeff;
    int32_t     power;
} dynamic_table_element_t;
    
typedef struct {
    int32_t const   *table;
    size_t          size;
    int32_t         (*fconv)(int32_t const input);
    unsigned char   *name;
} static_table_t;

typedef struct {
    dynamic_table_element_t *elements;
    size_t                  size;
    int32_t                 (*fconv)(void *lut, int32_t const input);
    unsigned char           *name;
} dynamic_table_t;

typedef struct {
    status_using_t  status_fft;
    int32_t         min_frequency;
    int32_t         max_frequency;
} transition_fft_t;

typedef struct {
    status_using_t  status_filter;
    unsigned char   *name;
    filter_t        filter_type;
    size_t          order;
    double const    *coeff;
    double          sampling_frequency_hz;
    double          cutoff_frequency_hz;
    size_t          length_buffer;
    sample_t         (*filtration)(sample_t input);
} transition_filter_t;

typedef struct {
    status_using_t  status_oversampling;
    unsigned char   *name;
    double          source_frequency_hz;
    double          target_frequency_hz;
    uint32_t        filter_order;
    void            (*push)(sample_t input);
    sample_t        (*pull)(void);
} transition_oversampling_t;

typedef struct {
    status_using_t  status_rms;
    int32_t         *buffer;
    size_t          size;
} transition_rms_t;

typedef struct {
    status_using_t  status_log;
    status_using_t  status_border;
    int32_t         max;
    int32_t         min;
} transition_amplitude_t;

typedef struct {
    type_table_t            type_table;
    static_table_t          *static_table;
    dynamic_table_t         *dynamic_table;
    
    transition_amplitude_t  transition_amplitude;
    
    transition_filter_t     transition_filter;
    transition_rms_t        transition_rms;
    transition_fft_t        transition_fft;
} lut_t;

#ifdef __cplusplus
}
#endif

#endif /* TYPES_H */

