#include "factorial.h"

int factorial(int number)
{
  /* Return -1 for negative numbers */
  if(number < 0)
    return -1;

  /* Return 1 for 0 */
  if(number == 0)
    return 1;

  /* Recursively calculate Factorial of the number */
  return number * factorial(number-1);
}
