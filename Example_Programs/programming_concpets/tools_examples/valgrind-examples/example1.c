#include<stdio.h>
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"
int arr[10] ={};
int main(int argc, char* argv[]) {
  int *parr;
  int len=10, sum;
  if(argc > 1)
    len = strtoul(argv[1],NULL,10);
  
  parr = malloc(len * sizeof(int));
  
  srand(time(0));
  
  for(int i=0;i<len;i++)
    parr[i] = rand()%100;
  
  for(int i=0;i<len+10;i++)
    sum += parr[i];
  
  printf("%d", arr[10]);
  return 0;
}
