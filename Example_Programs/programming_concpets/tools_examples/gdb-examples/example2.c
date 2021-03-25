#include<stdio.h>

// const int cval = 100; // This is in read only data section

int main(int argc, char* argv[]) {
  const int cval = 100; 
  int *ptr;
  ptr=&cval;      //error or warning? // line 7 is causing warning., here storing address of Read only
  *ptr=200; 
 
  printf("Thank You\n");
  printf("%d ",cval);
  return 0;
}

 /* 
    In original code cval was a global variable and was in read only memory that
    didn't belong to us, hence segmentation fault.
    Fix --> made it local variable assumin we are trying to change constant value.
    Doubt: When declared locally, not visible through nm command.
  */
