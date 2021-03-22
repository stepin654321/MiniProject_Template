#include "header_def.h"

int sum(complex_num c_1, complex_num c_2){
    struct complex_num c;
   //Adding up two complex numbers
   c.real = c_1.real + c_2.real;
   c.img = c_1.img + c_2.img;
   printf("The sum is %d + i%d\n ", c.real,c.img);
   return c.real+c.img; 
}