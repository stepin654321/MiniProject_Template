#include<stdio.h>
#include<math.h>
typedef struct complex_t {

float real;

float imaginary;

} complex_t;

complex_t sum(complex_t a,complex_t b)
{
    struct complex_t ans;
    ans.real = a.real + b.real;
    ans.imaginary = a.imaginary + b.imaginary;
    return ans;
}

complex_t difference(complex_t a,complex_t b)
{
    struct complex_t ans;
    ans.real = a.real - b.real;
    ans.imaginary = a.imaginary - b.imaginary;
    return ans;
}
complex_t multiply(complex_t a,complex_t b)
{
    struct complex_t ans;
    ans.real = (a.real * b.real) - (a.imaginary * b.imaginary);
    ans.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return ans;
}
complex_t divide(complex_t a,complex_t b)
{
    struct complex_t ans;
    ans.real=(((a.real)*(b.real))+((a.imaginary)*(b.imaginary)))/(pow(b.real,2)+pow(b.imaginary,2));
    ans.imaginary=(((b.real)*(a.imaginary))-((a.real)*(b.imaginary)))/(pow(b.real,2)+pow(b.imaginary,2));
    return ans;
}
