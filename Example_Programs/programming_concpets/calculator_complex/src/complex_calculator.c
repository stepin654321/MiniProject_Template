#include <stdlib.h>
#include <math.h>
#include "complex_calculator.h"


error_t complex_sum(complex_t* c1, complex_t* c2, complex_t* result)
{
    if(NULL == c1 || NULL == c2)
        return ERROR_NULL_PTR;
    
    
    result->real = c1->real + c2->real;
    result->imaginary = c1->imaginary + c2->imaginary;

    return SUCCESS;

}

error_t complex_sub(complex_t *c1, complex_t *c2, complex_t *result)
{
    if (NULL == c1 || NULL == c2)
        return ERROR_NULL_PTR;

    result->real = c1->real - c2->real;
    result->imaginary = c1->imaginary - c2->imaginary;

    return SUCCESS;
}

error_t complex_mul(complex_t *c1, complex_t *c2, complex_t *result)
{
    if (NULL == c1 || NULL == c2)
        return ERROR_NULL_PTR;

    result->real = (c1->real * c2->real) - (c1->imaginary * c2->imaginary);
    result->imaginary = (c1->real * c2->imaginary) + (c1->imaginary * c2->real);

    return SUCCESS;
}

error_t complex_div(complex_t *c1, complex_t *c2, complex_t *result)
{
    if (c2->real == 0 && c2->imaginary == 0)
    {
        return ERROR_DIV_BY_ZERO;
    }

    else if (c2 == NULL || c1 == NULL)
        return ERROR_NULL_PTR;

    else
    {
        result->real = ((c1->real * c2->real) + (c1->imaginary * c2->imaginary)) / (pow(c2->real, 2) + pow(c2->imaginary, 2));
        result->imaginary = ((c1->imaginary * c2->real) - (c1->real * c2->imaginary)) / (pow(c2->real, 2) + pow(c2->imaginary, 2));

        return SUCCESS;
    }
}