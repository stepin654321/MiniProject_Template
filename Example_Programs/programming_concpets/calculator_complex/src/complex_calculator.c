#include "stdlib.h"
#include "complex_calculator.h"
#include<math.h>

error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    csum->real = cnum1->real + cnum2->real;
    csum->imaginary = cnum1->imaginary + cnum2->imaginary;

    return SUCCESS;

}

error_t complex_diff(complex_t* cnum1, complex_t* cnum2, complex_t* cdiff)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    cdiff->real = cnum1->real - cnum2->real;
    cdiff->imaginary = cnum1->imaginary - cnum2->imaginary;

    return SUCCESS;

}

error_t complex_mul(complex_t* cnum1, complex_t* cnum2, complex_t* cmul)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    cmul->real = (cnum1->real * cnum2->real) - (cnum1->imaginary * cnum2->imaginary);
    cmul->imaginary = (cnum1->real * cnum2->imaginary) + (cnum1->imaginary * cnum2->real);

    return SUCCESS;

}

error_t complex_div(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv)
{
    if (cnum2->real==0 && cnum2->imaginary==0)
    {
        return ERROR_DIV_BY_ZERO;
    }

    else if(cnum2 == NULL || cnum1 ==NULL)
        return ERROR_NULL_PTR;
    
    else{
    cdiv->real = ((cnum1->real * cnum2->real) + (cnum1->imaginary * cnum2->imaginary)) / (pow(cnum2->real,2) + pow(cnum2->imaginary,2));
    cdiv->imaginary = ((cnum1->imaginary * cnum2->real) - (cnum1->real * cnum2->imaginary)) / (pow(cnum2->real,2) + pow(cnum2->imaginary,2));
    
    return SUCCESS;
    }

}
