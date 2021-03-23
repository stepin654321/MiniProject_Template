#include "header_def.h"

int div(complex_num s1, complex_num s2){
    struct complex_num res;

    if(s2.real == 0 || s2.img == 0 ){
        printf("You cannot divide by 0");
        return -1;
        
    }

    int a=(((s1.real)*(s2.real))+((s1.img)*(s2.img)))/(pow(s2.real,2)+pow(s2.img,2));
    int b=(((s2.real)*(s1.img))-((s1.real)*(s2.img)))/(pow(s2.real,2)+pow(s2.img,2));

    res.real = a;
    res.img = b;
    printf("The division is %d + i%d\n", a,b);
    return a+b;

}