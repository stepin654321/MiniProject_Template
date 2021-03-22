/**
 * @file header_def.h
 * @author Arnob
 * @brief 
 * @version 0.1
 * @date 2021-03-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __FUN_H__
#define __FUN_H___

/**
 * @brief User defined datatype to hold imaginary and real part of imaginary number
 * 
 */
typedef struct complex_num
{
    int real, img;
} complex_num;
/**
 * @brief add two complex numbers
 * 
 * @param c_1 
 * @param c_2 
 * @return Integer
 */
int sum(complex_num c_1, complex_num c_2);
/**
 * @brief subtracts two complex numbers
 * 
 * @param c_1 
 * @param c_2 
 * @return Integer
 */
int sub(complex_num c_1, complex_num c_2);
/**
 * @brief multiplies 2 complex numbers
 * 
 * @param c_1 
 * @param c_2 
 * @return Integer
 */
int mul(complex_num c_1, complex_num c_2);
/**
 * @brief divides two complex numbers
 * 
 * @param c_1 
 * @param c_2 
 * @return Integer
 */
int div(complex_num c_1, complex_num c_2);

#endif