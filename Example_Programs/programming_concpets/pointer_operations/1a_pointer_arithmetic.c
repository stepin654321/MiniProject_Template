/* Pointer arithmetic */

/**
* Allowed pointer arithmetic (p1, p2 are pointers, t is a scalar)
*   pointer + scalar, p1 + t, ++p1
*   pointer - scalar, p1 - t, --p2
*   difference between pointers p1 - p2
*   derefernce *p1
*/

#include<stdio.h>

int main() {
  int val=100; 
  int *ptr;
  ptr=&val;         //Make a note of value
  
  int *p1, *p2, t;
  p1 = ptr + 5;
  //print p1
  p2 = ptr - 10;
  //print p2
  ++p1;
  //print p1
  --p2;
  //print p2
  t = p1 - p2;
  //print the difference
  
  //TODO: try these operations on other types like double*, char*

  return 0;
}
