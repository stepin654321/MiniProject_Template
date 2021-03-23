#include <stdio.h>
#include "complex_header.h"
int main()
{
    // declaring structure type variables for storing input and displaying output
    complex_t first, second, sum, diff, mul, div;
    
    // giving input from my side
    first.real = 1;
    first.img = 2;
    second.real = 3;
    second.img = 1;

    // calling functions
    sum = add(first, second);
    diff = subtract(first, second);
    mul = multiply(first, second);
    div = divide(first, second);


    // displaying output
    printf("\nsum = %.1f + %.1fi", sum.real, sum.img);
    printf("\ndiff = %.1f + %.1fi", diff.real, diff.img);
    printf("\nproduct = %.1f + %.1fi", mul.real, mul.img);
    printf("\ndivision = %.1f + %.1fi", div.real, div.img);
    return 0;
}