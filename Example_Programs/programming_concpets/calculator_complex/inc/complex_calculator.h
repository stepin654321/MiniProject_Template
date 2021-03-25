
/**
 * @file complex_calculator.h
 * @author 260757 (sarthaknaithani@yahoo.in)
 * @brief Functions to perform Sum, Difference, Division and Multiplication on complex Varibales of \ref complex_t
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _COMPLEX_T_H
#define _COMPLEX_T_H

#include <stdlib.h>
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
 * @brief This funtion performs subtraction two complex nos ie. _Z2 from _Z1.
 * 
 * @param _Z1 ( complex_t* ) First complex num.
 * @param _Z2 ( complex_t* ) Second Complex num.
 * @param _Z3 ( complx_t* ) Sum of two complex nos (*_Z3 = *_Z1 - _Z2 )
 * @return error_t returns the error codes: ERROR_DIV_BY_ZERO = -2, ERROR_NULL_PTR = -1, SUCCESS = 0;
 */
error_t complexSub(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3);

/**
 * @brief This funtion performs Multiplication two complex nos. _Z1 and Z2.
 * 
 * @param _Z1 ( complex_t* ) First complex num.
 * @param _Z2 ( complex_t* ) Second Complex num.
 * @param _Z3 ( complx_t* ) Sum of two complex nos (*_Z3 = *_Z1 * _Z2 )
 * @return error_t returns the error codes: ERROR_DIV_BY_ZERO = -2, ERROR_NULL_PTR = -1, SUCCESS = 0; 
 */
error_t complexMul(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3);

/**
 * @brief This funtion performs division two complex nos. _Z1 by _Z2.
 * 
 * @param _Z1 ( complex_t* ) First complex num.
 * @param _Z2 ( complex_t* ) Second Complex num.
 * @param _Z3 ( complx_t* ) Sum of two complex nos (*_Z3 = *_Z1 / _Z2 )
 * @return error_t returns the error codes: ERROR_DIV_BY_ZERO = -2, ERROR_NULL_PTR = -1, SUCCESS = 0;
 */
error_t complexDiv(complex_t const* _Z1, complex_t const* _Z2, complex_t* _Z3);

#endif /* _COMPLEX_T_H */

