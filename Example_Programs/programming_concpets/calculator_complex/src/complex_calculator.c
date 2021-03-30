#include "stdlib.h"
#include "complex_calculator.h"

complex add(complex a1, complex a2){
    complex temp;
    temp.real = a1.real + a2.real;
    temp.imaginary = a1.imaginary + a2.imaginary;
    return (temp);

}

complex multiply(complex m1, complex m2){
    complex temp;
    temp.real = (m1.real*m2.real)-(m1.imaginary*m2.imaginary);
    temp.imaginary = (m1.imaginary*m2.real)-(m1.real*m2.imaginary);
    return (temp);

}

complex subtract(complex s1, complex s2){
    complex temp;
    temp.real = s1.real - s2.real;
    temp.imaginary = s1.imaginary + s2.imaginary;
}

complex division(complex d1, complex d2){
    complex temp;
    temp.real = (d1.real*d2.real + d1.imaginary*d2.imaginary)/(d2.real*d2.real+d2.imaginary*d2.imaginary);     
    temp.imaginary = (d1.imaginary*d2.real - d1.real*d2.imaginary)/(d2.real*d2.real + d2.imaginary*d2.imaginary);
    return (temp);
}

