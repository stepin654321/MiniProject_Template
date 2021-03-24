/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <conio.h>
#include "complex_calculator.h"
int main()
{
   int choice,check;
   static complex_t First_complex_number = {0, 0};
   static complex_t secound_complex_number = {0, 0};
   static complex_t result_complex_number = {0, 0};

   printf("Complex calculator\n");
   do
   {
      printf("Enter Your Choice\npress 1 for addition\npress 2 for subtaction\npress 3 for multiplication \npress 4 for division\n");
      scanf("%d",&choice);
      switch(choice)
      {
         case 1: complex_sum(&First_complex_number,&secound_complex_number,&result_complex_number);
                 break;
         case 2: complex_sub(&First_complex_number,&secound_complex_number,&result_complex_number);
                 break;
         case 3: complex_multiply(&First_complex_number,&secound_complex_number,&result_complex_number);
                 break;
         case 4: complex_divide(&First_complex_number,&secound_complex_number,&result_complex_number);
                 break;
         default: printf("wrong choice\n");
                  break;
      }
      printf("press enter to continue and press escape to exit\n");
   } while ((check=getch())!=27);
   printf("program has terminated\n");
   return 0;
}