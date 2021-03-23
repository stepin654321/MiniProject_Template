#include "fun.h"
#include <stdio.h>
int main() {
  int a, b, c, d;
  a = 10;
  b = 20;
  c = sum(a, b);
  d = square(a);
  printf("c=%d,d=%d\n",c,d);
  return 0;
}