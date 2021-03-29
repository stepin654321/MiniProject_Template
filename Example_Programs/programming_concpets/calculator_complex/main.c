#include<stdio.h>
#include "complex_cal.h"

/**
 * @brief this is the main function
 * 
 * @return int 
 */
int main(){
    printf("Complex calculator :\n");

    static float realval_n1[] = {5, 23, 4,- 7, 0};
    static float realval_n2[] = {10, 17, -9, -5, 4 };

    static float imagval_n1[] = {2.4f, 3.6f, -2, 1.5f, -11};
    static float imagval_n2[] = {-1.45f, -2.34f, 9.87f, 0.56f, -14.14f};

    static complex_t n1 ={0,0} , n2 ={0,0};
    static complex_t sum= {0,0}, diff ={0,0}, mul ={0,0}, div={0,0};

    for(int i =0;i<5;i++){
        n1.real = realval_n1[i];
        n2.real = realval_n2[i];

        n1.imaginary = imagval_n1[i];
        n2.imaginary = imagval_n2[i];

        printf("Performing all operations on numbers %f + (%f)i  and %f + (%f)i\n",n1.real,n1.imaginary,n2.real,n2.imaginary);
        complex_sum(&n1, &n2, &sum); 
        printf("Sum = %f + (%f) i\n",sum.real,sum.imaginary);
        
        complex_diff(&n1, &n2, &diff );
        printf("Difference = %f + (%f) i\n",diff.real,diff.imaginary);
        
        complex_mul(&n1, &n2, &mul);
        printf("Product = %f + (%f) i\n",mul.real,mul.imaginary);

        complex_div(&n1, &n2, &div);
        printf("Quotient = %f + (%f) i\n",div.real,div.imaginary);

        printf("\n");

    } 
    return 0;
}