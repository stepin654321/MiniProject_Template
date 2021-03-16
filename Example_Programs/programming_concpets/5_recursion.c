/**
 * @file 5_recursion.c
 * @author Bharath G
 * @brief Example to understand recursive functions
 * @version 0.1
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021
 * 
 * @note Visualizer: https://www.cs.usfca.edu/~galles/visualization/RecFact.html
 */

#include <stdio.h>
unsigned long int factorial(unsigned int i) {

   /* Termination condition */
   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int  main()
{
   int i = 12;
   printf("Factorial of %d is %d\n", i, factorial(i));
   return 0;
}