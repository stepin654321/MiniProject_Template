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
 * @brief funtion for addition of complex number
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] csum Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */
error_t complex_sum(complex_t* cnum1, complex_t* cnum2, complex_t* csum);

/**
 * @brief funtion for subtraction of complex number 
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] csub Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise.
 */
error_t complex_sub(complex_t* cnum1, complex_t* cnum2, complex_t* csub);

/**
 * @brief funtion for multiplication of complex number
 * 
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 
 * @param[out] cmul Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise. 
 */
error_t complex_multiply(complex_t* cnum1, complex_t* cnum2, complex_t* cmul);

/**
 * @brief funtion for division of complex number
 *
 * @param[in] cnum1 Pointer to complex number1
 * @param[in] cnum2 Pointer to complex number2 s
 * @param[out] cdiv Pointer to store the computed result
 * @return error_t SUCCESS if operation is completed successfully. Error value otherwise. 
 */
error_t complex_divide(complex_t* cnum1, complex_t* cnum2, complex_t* cdiv);

