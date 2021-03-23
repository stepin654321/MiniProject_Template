#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_div(complex_t* s1, complex_t* s2, complex_t* res){

    if(s2->real == 0 || s2->imaginary == 0 ){
        printf("You cannot divide by 0\n");
        return  ERROR_DIV_BY_ZERO;
    }

    res->real = (((s1->real)*(s2->real))+((s1->imaginary)*(s2->imaginary)))/(pow(s2->real,2)+pow(s2->imaginary,2));
    res->imaginary =(((s2->real)*(s1->imaginary))-((s1->real)*(s2->imaginary)))/(pow(s2->real,2)+pow(s2->imaginary,2));

    printf("The division is %f + i%f\n", res->real,res->imaginary);
    return SUCCESS;

}