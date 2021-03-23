#include<stdio.h>
#include "complex_header.h"

/**
 * @brief add function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t add(complex_t first, complex_t second)
{
    complex_t temp;
    temp.real = first.real + second.real;
    temp.img = first.img + second.img;
    return(temp);
}

/**
 * @brief subtract function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t subtract(complex_t first, complex_t second)
{
    complex_t temp;
    temp.real = first.real - second.real;
    temp.img = first.img - second.img;
    return(temp);
}

/**
 * @brief multiply function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t multiply(complex_t first, complex_t second)
{
    complex_t temp;
    temp.real = first.real * second.real;
    temp.img = first.img * second.img;
    return(temp);
}

/**
 * @brief divide function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t divide(complex_t first, complex_t second)
{
    complex_t temp;
    temp.real = first.real / second.real;
    temp.img = first.img / second.img;
    return(temp);
}
