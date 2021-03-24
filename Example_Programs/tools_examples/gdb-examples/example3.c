#include<stdio.h>

int val;
int *fetch() {
  val=100;
  return &val; 
}

int main(int argc, char* argv[]) {
  int *ptr;
  ptr=fetch(); 
  printf("Ret val=%d\n",*ptr); 
  return 0;                    
}
/*
  In original code, val had local scope and hence after the 
  execution of fetch() function, its memory got freed
  therefore in main() ptr was trying to access unknown 
  memory location, hence Segmentation fault.
  FIX --> declared val as a global varible.
 */
