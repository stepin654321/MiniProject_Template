/**
 * @file complex_sub.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_sub(complex_t* cnum1, complex_t* cnum2, complex_t* csub)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    csub->real = cnum1->real - cnum2->real;
    csub->imaginary = cnum1->imaginary - cnum2->imaginary;
    return SUCCESS;
}