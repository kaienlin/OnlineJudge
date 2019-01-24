#ifndef _COMPLEX_H
#define _COMPLEX_H
 
typedef struct cplex {
    float real;
    float imaginary;
} complex;
 
void init(complex *c, float a, float b);
void complex_print(complex *x);
complex complex_add(complex *x, complex *y);
complex complex_sub(complex *x, complex *y);
complex complex_mul(complex *x, complex *y);
#endif

#include <stdio.h>
#include "complex.h"

void init(complex *c, float a, float b)
{
    c->real = a;
    c->imaginary = b;
}

void complex_print(complex *x)
{
    printf("%.3f%+.3fi\n", x->real, x->imaginary);
}

complex complex_add(complex *x, complex *y)
{
    complex ans;
    ans.real = x->real + y->real;
    ans.imaginary = x->imaginary + y->imaginary;
    return ans;
}

complex complex_sub(complex *x, complex *y)
{
    complex ans;
    ans.real = x->real - y->real;
    ans.imaginary = x->imaginary - y->imaginary;
    return ans;
}

complex complex_mul(complex *x, complex *y)
{
    complex ans;
    ans.real = x->real * y->real - x->imaginary * y->imaginary;
    ans.imaginary = x->real * y->imaginary + x->imaginary * y-> real;
    return ans;
}