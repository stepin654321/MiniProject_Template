#include <stdio.h>

//#include "fun.h"

int main() {
  int num1 = 10, num2=20, num3, num4;
  num1 = 10;
  num2 = 20;
  num3 = sum(num1, num2);
  num4 = square(num1);

  printf("Sum = %d \t Square = %d \n", num3, num4);
  return 0;
}