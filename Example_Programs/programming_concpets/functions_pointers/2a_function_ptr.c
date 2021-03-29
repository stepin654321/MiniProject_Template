/* Function Pointers */

/**
 * function name acts like it's address
 * Binding pointers and functions
 * invoking functions through pointers
 */

#include <stdio.h>

int sum(int, int);
int prod(int, int);

int main() {

  int a = 10, b = 20, c, d;
  int *ptr_a = &a;

  int (*fp)(int, int);

  fp = sum; // same as *fp = &sum
  sum(a, b);
  c = fp(a, b);

  fp = prod;
  d = fp(a, b); // same as (*fp)(a,b)

  return 0;
}

int sum(int x, int y) { return x + y; }

int prod(int x, int y) { return x * y; }
