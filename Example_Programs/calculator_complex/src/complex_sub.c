#include "stdlib.h"
#include "complex_calculator.h"


error_t complex_sub(complex_t* c_1, complex_t* c_2, complex_t* c){
   if(NULL == c_1 || NULL == c_2)
        return ERROR_NULL_PTR;
   c->real = c_1->real - c_2->real;
   c->imaginary = c_1->imaginary - c_2->imaginary;
   printf("The sub is %f + i%f\n", c->real, c->imaginary);
   
   return SUCCESS;
}