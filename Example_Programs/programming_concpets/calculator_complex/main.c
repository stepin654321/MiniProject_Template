#include "stdio.h"
#include "conio.h"
#include "inc\complex_calculator.h"

int main(){
    complex_t a = {1, 1}, b = {3, 1}, c = {0, 0};
    
    complex_sumcd(&a, &b, &c);
    printf("%f %f\n\n", c.real, c.imaginary);
    
    c.real = 0.0;
    c.imaginary = 0.0;
    complexSub(&a, &b, &c);
    printf("%f %f\n\n", c.real, c.imaginary);

    c.real = 0.0;
    c.imaginary = 0.0;
    complexMul(&a, &b, &c);
    printf("%f %f\n\n", c.real, c.imaginary);

    c.real = 0.0;
    c.imaginary = 0.0;
    complexDiv(&a, &b, &c);
    printf("%f %f\n\n", c.real, c.imaginary);
    return 0;
}