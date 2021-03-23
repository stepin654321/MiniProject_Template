#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_mul(complex_t* s1, complex_t* s2, complex_t* res){
    res->real =((s1->real)*(s2->real))-((s1->imaginary)*(s2->imaginary));
    res->imaginary=((s1->real)*(s2->imaginary))+((s2->real)*(s1->imaginary));
    printf("The mutiplication is %f + i%f\n", res->real ,res->imaginary);
    return SUCCESS;

}