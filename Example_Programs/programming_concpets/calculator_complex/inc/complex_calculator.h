/**
 * @file complex_calculator.h
 * @author your name (abhishek.1599@gmail.com)
 * @brief Functions to perform Sum, Difference, Division and Multiplication on complex Varibales of \ref complex_t
 * @version 0.1
 * @date 2021-03-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __COMPLEX_CALCULATOR_H__
#define __COMPLEX_CALCULATOR_H__

/**
 * @brief 
 * 
 */

typedef struct complex {
    float real;         /**< real part of the complex number */
    float imaginary;    /**< real part of the complex number */
} complex;
/**
 * @brief 
 * 
 * @param a1 
 * @param a2 
 * @return complex 
 */
complex add(complex a1, complex a2);

/**
 * @brief 
 * 
 * @param m1 
 * @param m2 
 * @return complex 
 */

complex multiply(complex m1, complex m2);

/**
 * @brief 
 * 
 * @param d1 
 * @param d2 
 * @return complex 
 */

complex division(complex d1, complex d2);

/**
 * @brief 
 * 
 * @param s1 
 * @param s2 
 * @return complex 
 */

complex subtract(complex s1, complex s2);

#endif