/**
 * @file complex_divide.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<math.h>
#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_divide(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    else if (cnum2->real==0 && cnum2->imaginary==0)
        return ERROR_DIV_BY_ZERO;
    else if(cnum2 == NULL || cnum1 ==NULL)
        return ERROR_NULL_PTR;
    else{
    cdiv->real = ((cnum1->real * cnum2->real) + (cnum1->imaginary * cnum2->imaginary)) / (pow(cnum2->real,2) + pow(cnum2->imaginary,2));
    cdiv->imaginary = ((cnum1->imaginary * cnum2->real) - (cnum1->real * cnum2->imaginary)) / (pow(cnum2->real,2) + pow(cnum2->imaginary,2));
    
    return SUCCESS;
    }
}