/**
 * 
 * @brief Example to understand the difference between Inline functions and Macro functions
 * 
 */
#include <stdio.h>
#define GREATER(a, b) ((a < b) ? b : a)

// Inline function 
static inline int Maximum(int a, int b) 
{ 
    return (a > b) ? a : b; 
}
int main( void)
{
    printf("Greater of 10 and 20 is %d\n", GREATER(20, 10) );
    printf("Maximum of 10 and 20 is %d\n", Maximum(20, 10) );
    return 0;
}