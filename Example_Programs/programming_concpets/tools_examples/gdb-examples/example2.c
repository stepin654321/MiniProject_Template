#include<stdio.h>

const int cval = 100;

int main(int argc, char* argv[]) {
  int *ptr;
  ptr=&cval;      //error or warning?
  *ptr=200;
  printf("Thank You\n");
  return 0;
}
