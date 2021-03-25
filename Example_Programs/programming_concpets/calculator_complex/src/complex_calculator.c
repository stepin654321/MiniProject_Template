#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    
    csum->real = cnum1->real + cnum2->real;
    csum->imaginary = cnum1->imaginary + cnum2->imaginary;

    return SUCCESS;

}
error_t complexSub(complex_t const*  cnum1, complex_t const* cnum2, complex_t* cdiff){
    if( cnum1 == NULL|| cnum2 == NULL)
        return ERROR_NULL_PTR;
    
    cdiff->real = cnum1->real - cnum2->real;
    cdiff->imaginary = cnum1->imaginary - cnum2->imaginary;
    
    return SUCCESS;
}

error_t complexMul(complex_t const* cnum1, complex_t const* cnum2, complex_t* cmul){
    
    if( cnum1 == NULL|| cnum2 == NULL)
        return ERROR_NULL_PTR;
    
    cmul->real = (cnum1->real * cnum2->real) - (cnum1->imaginary * cnum2->imaginary);
    cmul->imaginary = (cnum1->real * cnum2->imaginary) + (cnum1->imaginary * cnum2->real);
    
    return SUCCESS;
}

error_t complexDiv(complex_t const* cnum1, complex_t const* cnum2, complex_t* cdiv){
    if( cnum1 == NULL|| cnum2 == NULL)
        return ERROR_NULL_PTR;
    
    float divv = cnum2->imaginary*cnum2->imaginary + cnum2->real * cnum2->real;
    
    if(divv == 0)
        return ERROR_DIV_BY_ZERO;
    
    cdiv->real = ((cnum1->real * cnum2->real) + (cnum1->imaginary * cnum2->imaginary))/divv;
    cdiv->imaginary = ((cnum1->imaginary * cnum2->real) - (cnum1->real * cnum2->imaginary))/divv;
    
    return SUCCESS;
}