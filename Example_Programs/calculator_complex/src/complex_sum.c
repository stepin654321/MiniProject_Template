#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum)
{
    if(NULL == cnum1 || NULL == cnum2)
        return ERROR_NULL_PTR;
    
    printf("%d r %d i\n ", cnum1->real, cnum2->real); // why 0 , 0 is recieved here?
    csum->real = cnum1->real + cnum2->real;
    csum->imaginary = cnum1->imaginary + cnum2->imaginary;
    printf("This sum is %d + %di", csum->real,csum->imaginary);
    return SUCCESS;

}