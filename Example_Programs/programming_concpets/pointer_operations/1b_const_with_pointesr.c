/* const keyword usage */

/**
* const keyword usage with pointers
* pointer to const
* constant pointer
* violation of const commitment
*/
#include<stdio.h>

int main() {
  
  // Pointer to a constant integer
  const int a1 = 10;
  const int* ptr1 = &a1;  
  *ptr1 = 5; // wrong
  ptr1++;    // right 


// Constant Pointer to an integer
  int a2 = 10;
  int *const ptr2 = &a2;  
  *ptr2 = 5; // right
  ptr2++;    // wrong

// Constant Pointer to a constant integer
  int a2 = 10;
  const int *const ptr2 = &a2;  
  *ptr2 = 5; // wrong
  ptr2++;    // wrong


  return 0;
}
