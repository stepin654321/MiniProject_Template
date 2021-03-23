#include <stdio.h>
#include "complex_calculator.h"
int main()
{
    //TODO Write all the logic for Calculator app
    printf("Complex calculator \n");

    static complex_t a={0,0};
    static complex_t b={0,0};
    static complex_t c={0,0};
    //int input_1,input_2,input_3,input_4;
    int choice;
    while(1)
    {
        printf("Press 1 to add two complex numbers.\n");
        printf("Press 2 to subtract two complex numbers.\n");
        printf("Press 3 to multiply two complex numbers.\n");
        printf("Press 4 to divide two complex numbers.\n");
        printf("Press 5 to exit.\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        if(choice == 5){
            exit(0);
        }

        if (choice >= 1 && choice <= 4)
        {   
            
            printf("Enter a and b where a + ib is the first complex number.");
            printf("\na = ");
            scanf("%f", &a.real);
            printf("b = ");
            scanf("%f", &a.imaginary);
            printf("Enter c and d where c + id is the second complex number.");
            printf("\nc = ");
            scanf("%f", &b.real);
            printf("d = ");
            scanf("%f", &b.imaginary);
            // a.real = input_1;
            // a.imaginary = input_2;
            // b.real = input_3;
            // b.imaginary = input_4;
        }
        if(choice == 1){
            error_t res = complex_sum(&a,&b,&c);
        }
        if(choice == 2){
            error_t res = complex_sub(&a,&b,&c);
        }
        if(choice == 3){
            error_t res = complex_mul(&a,&b,&c);
        }
        if(choice == 4){
            error_t res = complex_div(&a,&b,&c);
        }
  
  
  
    } // while end


    return 0;
    //gcc -I inc -I unity unity/unity.c src/complex_div.c src/complex_mul.c src/complex_sub.c src/complex_sum.c test/test_complex_calculator.c -o test_run.exe
    //gcc -I inc src/complex_div.c src/complex_mul.c src/complex_sub.c src/complex_sum.c main.c -o prod_run.exe
}