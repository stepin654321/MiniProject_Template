#include <stdlib.h>
#include <stdio.h>
#include "complex_cal.h"

error_t complex_sum(complex_t *a, complex_t *b, complex_t *sum)
{
    if (a == NULL || b == NULL)
    {
        return ERR_NULL_PTR;
    }

    sum->real = a->real + b->real;
    sum->imaginary = a->imaginary + b->imaginary;

    return SUCCESS;
}

error_t complex_diff(complex_t *a, complex_t *b, complex_t *diff)
{

    if (a == NULL || b == NULL)
        return ERR_NULL_PTR;

    diff->real = a->real - b->real;
    diff->imaginary = a->imaginary - b->imaginary;

    return SUCCESS;
}

error_t complex_mul(complex_t *a, complex_t *b, complex_t *mul)
{

    if (a == NULL || b == NULL)
        return ERR_NULL_PTR;

    mul->real = a->real * b->real - a->imaginary * b->imaginary;
    mul->imaginary = a->real * b->imaginary + a->imaginary * b->real;

    return SUCCESS;
}

error_t complex_div(complex_t *a, complex_t *b, complex_t *div)
{

    if (a == NULL || b == NULL)
        return ERR_NULL_PTR;
    if (b->real == 0 && b->imaginary == 0)
        return ERR_DIV_BY_ZERO;

    float real_numerator = (a->real * b->real) + (a->imaginary * b->imaginary);
    float denominator = (b->real * b->real) + (b->imaginary * b->imaginary);

    float imag_numerator = (a->imaginary * b->real) - (a->real * b->imaginary);

    div->real = real_numerator / denominator;
    div->imaginary = imag_numerator / denominator;

    return SUCCESS;
}