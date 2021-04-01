/* Passing arrays */

/**
 * Arrays are passed by reference(base address)
 * Whole array is never passed
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fill(int[], int);          // void fill(int*,int);
void aprint(const int[], int);  // void aprint(int*,int);
void compute(const int *, int); // void compute(int[],int);

int main() {
  int arr[10];

  fill(arr, 10); // arr is equivalent to &arr[0]
  aprint(arr, 8);
  compute(arr, 10);
  return 0;
}

void fill(int arr[], int n) { // void fill(int* arr,int n)
  // sizeof(arr)
  srand(time(0));
  int i;
  for (i = 0; i < n; i++)
    arr[i] = rand() % 100; //*(arr+i)=rand()%100;
}

void aprint(const int arr[], int n) { // void aprint(int *arr,int n)
  // sizeof(arr)
  int i;
  for (i = 0; i < n; i++)
    printf("%d\n", arr[i]); // printf("%d\n", *arr++);
}

void compute(const int *parr, int n) {
  // sizeof(parr)
  int i, sum = 0;
  for (i = 0; i < n; i++)
    sum += *parr++; // sum +=  parr[i]
}
