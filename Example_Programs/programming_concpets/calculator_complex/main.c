#include <stdio.h>
#include "complex_calculator.h"

int main()
{

complex n1, n2, result_add,result_sub,result_div,result_mul;

    n1.real=10;
    n1.imaginary=20;
    n2.real=2;
    n2.imaginary=5;

    result_add = add(n1, n2);

    result_mul= multiply(n1,n2);

    result_sub= subtract(n1,n2);

    result_div= division(n1,n2);

    printf("Sum = %.1f + %.1fi \n", result_add.real, result_add.imaginary);
    printf("Difference = %.1f + %.1fi \n", result_sub.real, result_sub.imaginary);
    printf("Multiply = %.1f + %.1fi \n", result_mul.real, result_mul.imaginary);
    printf("Division = %.1f + %.1fi \n", result_div.real, result_div.imaginary);

    

    return 0;

}