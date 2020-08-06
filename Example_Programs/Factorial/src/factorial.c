#include "factorial.h"

int factorial(int number) 
{
  if(number<0) return -1;
  if(number==0) return 1;
  return number*factorial(number-1);
}
