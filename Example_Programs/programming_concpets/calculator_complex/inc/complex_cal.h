#ifndef COMPLEX_CAL_H
#define COMPLEX_CAL_H

typedef enum error_t
{
    ERR_DIV_BY_ZERO = -2,
    ERR_NULL_PTR = -1,
    SUCCESS = 0
} error_t;

typedef struct complex_t
{
    float real;
    float imaginary;
} complex_t;

error_t complex_sum(complex_t *a, complex_t *b, complex_t *sum);

error_t complex_sub(complex_t *a, complex_t *b, complex_t *diff);

error_t complex_mul(complex_t *a, complex_t *b, complex_t *mul);

error_t complex_div(complex_t *a, complex_t *b, complex_t *div);

#endif