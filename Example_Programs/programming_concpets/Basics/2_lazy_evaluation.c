/**
 * @file 2_lazy_evaluation.c
 * @author Bharath G
 * @brief Example to show the lazy evaluation or short circuit behaviour of logical expressions
 * @version 0.1
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
 
int main(void) {
  int a = 20;
  int b = -5;
 
  if (a != 20 && b++)
    printf("Inside 1st if condition, b = %d\n", b);
   
   printf("After 1st if condition, b = %d\n", b);

   if (a == 20 || b++)
    printf("Inside 2nd if condition, b = %d\n", b);
   
   printf("After 2nd if condition, b = %d\n", b);
  return 0;
}