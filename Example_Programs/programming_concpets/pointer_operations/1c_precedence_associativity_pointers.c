/* Precedence & associativity */

/**
* Combinations of dereference, increment/decrement operations
* *ptr++, (*ptr)++, *(ptr++), ++*ptr, ++(*ptr), *++ptr, *(++ptr)
*/
#include<stdio.h>

int main() {
  int arr[10]={10,20,30,40,50, 60, 70, 80, 90, 100};
  int *ptr=&arr[2];         //ptr=arr+2
  int val;
  
  val=*ptr++;               //A, val=*ptr, ptr=ptr+1
  printf("val = %d, *ptr = %d\n", val, *ptr);
  
  val=*(ptr++);             //B, same as above
  printf("val = %d, *ptr = %d\n", val, *ptr);

  val=(*ptr)++;             //C, val=*ptr, *ptr=*ptr+1
  printf("val = %d, *ptr = %d\n", val, *ptr);
  
  val=++*ptr;               //D, *ptr=*ptr+1, val=*ptr
  printf("val = %d, *ptr = %d\n", val, *ptr);
  
  val=++(*ptr);             //E, same as above
  printf("val = %d, *ptr = %d\n", val, *ptr);

  val=*++ptr;               //F, ptr=ptr+1, val=*ptr
  printf("val = %d, *ptr = %d\n", val, *ptr);
  
  val=*(++ptr);             //G, same as above
  printf("val = %d, *ptr = %d\n", val, *ptr);

  //TODO: analyze *ptr--, (*ptr)--, --*ptr, *--ptr

  return 0;
}
