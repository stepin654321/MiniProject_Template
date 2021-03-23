#ifndef __COMPLEX_CALC_H__
#define __COMPLEX_CALC_H__

/**
 * @brief structure of a complex number with members real and imaginary
 * 
 */
typedef struct complex_t{

float real;

float img;

}complex_t;

/**
 * @brief add function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t add(complex_t first, complex_t second);

/**
 * @brief subtract function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t subtract(complex_t first, complex_t second);

/**
 * @brief multiply function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t multiply(complex_t first, complex_t second);


/**
 * @brief divide function of structure type returns real and imaginary part
 * 
 * @param first 
 * @param second 
 * @return complex_t 
 */
complex_t divide(complex_t first, complex_t second);

#endif