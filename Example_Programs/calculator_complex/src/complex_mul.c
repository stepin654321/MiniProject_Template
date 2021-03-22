#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_mul(complex_t* s1, complex_t* s2, complex_t* res){
    int a=((s1->real)*(s2->real))-((s1->imaginary)*(s2->imaginary));
    int b=((s1->real)*(s2->imaginary))+((s2->real)*(s1->imaginary));
    res->real = a;
    res->imaginary = b;
    printf("The mutiplication is %d + i%d\n", a,b);
    return SUCCESS;

}