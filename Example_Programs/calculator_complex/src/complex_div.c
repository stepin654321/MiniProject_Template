#include "stdlib.h"
#include "complex_calculator.h"

error_t complex_div(complex_t* s1, complex_t* s2, complex_t* res){

    if(s2->real == 0 || s2->imaginary == 0 ){
        printf("You cannot divide by 0");
        return  ERROR_DIV_BY_ZERO;
    }

    int a=(((s1->real)*(s2->real))+((s1->imaginary)*(s2->imaginary)))/(pow(s2->real,2)+pow(s2->imaginary,2));
    int b=(((s2->real)*(s1->imaginary))-((s1->real)*(s2->imaginary)))/(pow(s2->real,2)+pow(s2->imaginary,2));

    res->real = a;
    res->imaginary = b;
    printf("The division is %d + i%d\n", a,b);
    return SUCCESS;

}