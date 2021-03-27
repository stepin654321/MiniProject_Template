/* Passing functions to other functions */

/**
 * passing function names vs function calls
 * parameters representing function pointers
 * Hint - basis for callback functions
 */
#include <stdio.h>

typedef int (*fptr_t)(int, int);

int sum(int, int);
int prod(int, int);
void acompute(int, int, int (*)(int, int));
void acompute_t(int x, int y, fptr_t fnptr);

int sum(int x, int y) { return x + y; }
int prod(int x, int y) { return x * y; }
int main() {
  int a = 10, b = 20, c, d;

  acompute(a, b, sum);
  acompute_t(a, b, prod);
  return 0;
}

void acompute(int x, int y, int (*fptr)(int, int)) {
  int z;
  z = fptr(x, y);
  printf("Res = %d\n", z);
}

void acompute_t(int x, int y, fptr_t fnptr) {
  int z;
  z = fnptr(x, y);
  printf("Res = %d\n", z);
}
