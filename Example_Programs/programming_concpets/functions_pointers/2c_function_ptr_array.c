/* Array of function pointers */
#include <stdio.h>

int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int divide(int x, int y) { return x / y; }

int multiply(int x, int y) { return x * y; }

int main() {
  int (*fparr[5])(int, int);

  fparr[0] = add;
  fparr[1] = subtract;
  fparr[2] = multiply;
  fparr[3] = divide;
  fparr[4] = NULL;

  int a = 10, b = 20, c;
  int i = 3;

  c = (fparr[i])(a, b); // i can be 0,1,2,3
  // what if i==4

  return 0;
}
