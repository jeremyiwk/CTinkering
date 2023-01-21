#include <iostream>
#include <stdio.h>
#include <math.h>
#include <ccomplex>

using namespace std;

complex<double> vectordot(complex<double> arr1[], complex<double> arr2[], int size)
{
    complex<double> prod (0.0,0.0);
    for (int i=0; i < size; ++i)
    {
        prod += arr1[i]*arr2[i];
    }
    return prod;
}

int main(void)
{
    complex<double> I (0.0, 1.0);
    complex<double> z1[2], z2[2];
    complex<double> z3;
    
    z1[0] = 1.0 + I*1.0;
    z2[0] = 1.0 + I*1.0;
    z1[1] = 1.0 + I*1.0;
    z2[1] = 1.0 + I*1.0;
    z3 = vectordot(z1, z2, 2);
    
    printf("The dot product of z1 and z2 is : %f + i%f\n", real(z3), imag(z3));
    return 0;
}
