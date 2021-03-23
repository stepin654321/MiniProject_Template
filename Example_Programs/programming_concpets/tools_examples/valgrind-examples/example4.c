#include<stdio.h>
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"
int main(int argc, char* argv[]) {
  int *parr;
  int len=10, sum;
  parr = malloc(len * sizeof(int));
  srand(time(0));
  
  for(int i=0;i<len;i++)
    parr[i] = rand()%100;
  
  for(int i=0;i<len;i++)
    sum += *parr++;              
 
  free(parr);
  return 0;
}
