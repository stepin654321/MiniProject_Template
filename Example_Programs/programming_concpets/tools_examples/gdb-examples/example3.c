#include<stdio.h>

int *fetch() {
  int val=100;
  return &val;
}

int main(int argc, char* argv[]) {
  int *ptr;
  ptr=fetch();     
  printf("Ret val=%d\n",*ptr);
  return 0;
}
