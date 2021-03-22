/**
 * @file 1_mmeory_map.c
 * @author Bharath G
 * @brief Program to show in which section of the memory map each variable is stored.
 * Adding qualifiers like const and static change the sections.
 * Initialized and Uninitialized variables are stored in different sections.
 * 
 * To check the memory map or the symbols created, run below commands
 *  gcc -c memory_map.c
 *  nm memory_map.o
 * @version 0.1
 * @date 2021-03-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */

int global_initialized_variable = 10;
int global_uninitialized_variable;

static int global_static_initialized_variable = 10;
static int global_static_initialized_variable;

const int global_const_initialized_variable = 10;

static const int global_static_const_initialized_variable = 10;
static const int global_static_const_uninitialized_variable;

/* Function prototype */ 
int referenced_function(int,int);

void normal_function()
{
    // Function body
}

static void static_function()
{
    // Function body
}

int main() 
{
  int x, y, z;
  
  const int local_const_initialized_variable = 10;
  const int local_const_uninitialized_variable;
  
  static int local_static_initialized_variable = 1000;
  static int local_static_uninitialized_variable;


  static const int local_static_const_initialized_variable = 2000;
  static const int local_static_const_uninitialized_variable;

  /* Definition is not provided in this file, hence compilation will fail.
     So use " -c " option in gcc to stop after object file generation  */
  z = referenced_function(x, y);
  return 0;
}
