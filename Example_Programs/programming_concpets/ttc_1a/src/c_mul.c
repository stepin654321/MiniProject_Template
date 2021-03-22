#include "header_def.h"

int mul(complex_num s1, complex_num s2){
    struct complex_num res;
    int a=((s1.real)*(s2.real))-((s1.img)*(s2.img));
    int b=((s1.real)*(s2.img))+((s2.real)*(s1.img));
    res.real = a;
    res.img = b;
    printf("The mutiplication is %d + i%d\n", a,b);
    return a+b;

}