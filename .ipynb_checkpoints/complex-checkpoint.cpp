#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ccomplex>

using namespace std;

int main() 
{
    complex<double> z1 (1.0, 1.0);
    complex<double> z2 (1.0, 1.0);
    complex<double> prod;
    prod = z1*z2;
    complex<double> I (0.0, 1.0);
    
    double prod_real = real(prod);
    
    printf("z1 = %f + i%f\n", real(z1), imag(z1));
    
    printf("z2 = %f + i%f\n", real(z2), imag(z2));

    printf("The product of z1 and z2 is : %f + i%f\n", real(z1*z2), imag(z1*z2));
    
    complex<double> unit;
    unit = exp(I*z1);
    
    printf("exp(z1) : %f + i%f\n", real(unit), imag(unit));
    
    return 0;
}