/**
 * @file complex_calculator.h
 * @author your name (you@domain.com)
 * @brief Functions to perform Sum, Difference, Division and Multiplication on complex Varibales of \ref complex_t
 * @version 0.1
 * @date 2021-03-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __COMPLEX_CALCULATOR_H__
#define __COMPLEX_CALCULATOR_H__
/**
 * @brief Error values for calculator operations
 * 
 */
typedef enum error_t {
    ERROR_DIV_BY_ZERO = -2, /**< Division by 0 error */
    ERROR_NULL_PTR = -1,    /**< Null pointer dereferncing error */
    SUCCESS = 0             /**< Compute operation is successful */
}error_t;

/**
 * @brief Structure for Complex number
 * 
 */
typedef struct complex_t {
    float real;         /**< real part of the complex number */
    float imaginary;    /**< real part of the complex number */
} complex_t;


/**
* @brief computes sum of teh two complex numbers
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] csum Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */
error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum);

/**
* @brief computes difference of teh two complex numbers
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] cdiff Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */

error_t complex_diff(complex_t* cnum1, complex_t* cnum2, complex_t* cdiff);

/**
* @brief computes product of teh two complex numbers
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] cmul Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */

error_t complex_mul(complex_t* cnum1, complex_t* cnum2, complex_t* cmul);

/**
* @brief computes division of teh two complex numbers
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] csum Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */

error_t complex_div(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv);

#endif