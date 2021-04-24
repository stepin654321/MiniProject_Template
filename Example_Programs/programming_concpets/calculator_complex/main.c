/**
 * @file main.c
 * @author Asish Sankhyan
 * @brief Write functions to compute sum, difference, product & division of two complex variables of the below structure.
 * @version 0.1
 * @date 2021-04-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    float real;
    float imaginary;
} complex_t;
void prints(complex_t temp)
{
    printf("%.1f+i%.1f\n", temp.real, temp.imaginary);
}
complex_t add(complex_t c1, complex_t c2)
{
    complex_t temp;
    temp.real = c1.real + c2.real;
    temp.imaginary = c1.imaginary + c2.imaginary;
    printf("Addition: ");
    return temp;
}
complex_t minus(complex_t c1, complex_t c2)
{
    complex_t temp;
    temp.real = c1.real - c2.real;
    temp.imaginary = c1.imaginary - c2.imaginary;
    printf("Subtraction: ");
    return temp;
}
complex_t multiply(complex_t c1, complex_t c2)
{
    complex_t temp;
    temp.real = c1.real * c2.real;
    temp.imaginary = c1.imaginary * c2.imaginary;
    return temp;
}
complex_t divide(complex_t c1, complex_t c2)
{
    complex_t temp;
    temp.real = c1.real / c2.real;
    temp.imaginary = c1.imaginary / c2.imaginary;
    return temp;
}
int main()
{
    complex_t c1, c2;
    c1.real = 10;
    c1.imaginary = 5;
    c2.real = 11;
    c2.imaginary = 6;
    complex_t c3;
    printf("Number one :");
    prints(c1);
    printf("Number two :");
    prints(c2);
    printf("Enter 1 for addition\n2 for Subtraction\n3 for multiplication\n4 for division\n5 for exit\n");
    while (1)
    {
        int x;
        scanf("\n%d", &x);
        switch (x)
        {
        case 1:
        {
            c3 = add(c1, c2);
            prints(c3);
            break;
        }
        case 2:
        {
            c3 = minus(c1, c2);
            prints(c3);
            break;
        }
        case 3:
        {
            c3 = multiply(c1, c2);
            prints(c3);
            break;
        }
        case 4:
        {
            c3 = divide(c1, c2);
            prints(c3);
            break;
        }
        case 5:
        {
            exit(0);
        }
        default:
            break;
        }
    }
}
