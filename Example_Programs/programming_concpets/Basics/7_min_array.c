/**
 * @file 7_min_array.c
 * @author Bharath G
 * @brief  Function to find Minimum value in unsigned integer array
 * @version 0.1
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

#define ARRAY_SIZE    (10)
/* Two methods to access the array values */
#define INDEX_BASED   (1)
#define POINTER_BASED (2)

/* Change this to above options to change the method of access */
#define ARRAY_ACCESS_METHOD (POINTER_BASED)

/**
 * Function to find Minimum value in unsigned integer array
 * Param1 - Pointer to unsigned integer Array
 * Param2 - Size of the Array
 * Return - -1 if the Array pointer is NULL, minimum value otherwise
 */

/**
 * @brief 
 * 
 * @param ptr_arr 
 * @param arr_size 
 * @return int 
 */
int min_value_in_array(const unsigned int *ptr_arr, const size_t arr_size)
{
  /* If array is not pointing to anything, return a error */
  if(NULL == ptr_arr)
    return -1;
 
  /* Initialize the minimum value with the first value in array */ 
  unsigned int min_val = ptr_arr[0];
  
  /* Loop through the array till the minimum value is found */ 
  for(unsigned int index = 0; index < arr_size; ++index)
  {
    /* Index based accesing */
    #if (ARRAY_ACCESS_METHOD == INDEX_BASED)
      if(ptr_arr[index] < min_val)
      {
        min_val = ptr_arr[index];
      }
    #else
    /* Pointer based accesing */
      if(*ptr_arr< min_val)
      {
        min_val = *ptr_arr;
      }
      ptr_arr++;
    #endif
  }
  
  return min_val;
}

int main() {

  /* Test the function with Known data */
  unsigned int arr1[ARRAY_SIZE] = {107,350,125,104,156,650,47,80,49,707};
  printf("Minimum in Array = %d",min_value_in_array(arr1, ARRAY_SIZE));
  
  /* Test the function with random data */
  unsigned int arr2[ARRAY_SIZE] = {};
  /* Seed value for Random number generator */
  srand(time(0));
  /* Fill the array with random values */
  for(unsigned int index = 0; index <ARRAY_SIZE; index++)
  {
    /* Fill data values which are below 1000 */
    arr2[index] = rand()%1000;
  }
  printf("Minimum in Array = %d",min_value_in_array(arr2, ARRAY_SIZE));
  
  return 0;
}