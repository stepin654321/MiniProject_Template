#include <stdio.h>
#include "complex_calculator.h"
int main()
{
    printf("Complex calculator ");
    static complex_t a={0,0};
    static complex_t b={0,0};
    static complex_t c={0,0};
    int choice;
    while(1)
    {
        printf("To add complex numbers press 1.\n");
        printf("To subtract complex numbers press 2.\n");
        printf("To multiply complex numbers press 3.\n");
        printf("To divide complex numbers press 4.\n");
        printf("To exit press 5.\n");
        printf("Enter the number.\n");
        scanf("%d", &choice);

        if(choice == 1){
            error_t res = complex_sum(&a,&b,&c);
        }
        if(choice == 2){
            error_t res = complex_diff(&a,&b,&c);
                    }
        if(choice == 3){
            error_t res = complex_mul(&a,&b,&c);
        }
        if(choice == 4){
            error_t res = complex_div(&a,&b,&c);
        }
        
        if(choice == 5){
            break;
        }

    } 
    return 0;
}
