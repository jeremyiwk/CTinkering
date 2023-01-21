#include <iostream> 
#include <stdio.h>
#include <complex>  
#include <math.h>

using namespace std;

int main ()
{
    
    int N = 10;
    
    double pi = M_PI;
    complex<double> I (0.0,1.0);
    
    complex<double> x_n[N];
    
    x_n[0] = 1.0 + 0.0*I;
    x_n[1] = 2.0 + 0.0*I;
    x_n[2] = 3.0 + 0.0*I;
    x_n[3] = 4.0 + 0.0*I;
    x_n[4] = 5.0 + 0.0*I;
    x_n[5] = 6.0 + 0.0*I;
    x_n[6] = 7.0 + 0.0*I;
    x_n[7] = 8.0 + 0.0*I;
    x_n[8] = 9.0 + 0.0*I;
    x_n[9] = 10.0 + 0.0*I;
    
    complex<double> X_k[N];
    
    
    for (int i=0; i<N; ++i)
    {
        X_k[i] = 0.0;
        
        for (int j=0; j<N; ++j)
        {
            complex<double> ii = i;
            complex<double> jj = j;
            complex<double> NN = N;
            X_k[i] += x_n[j]*exp(-2*pi*I*ii*jj/NN);
        }
    }
    
    
    for (int i=0; i<N; ++i)
    {
        printf("X_k[%d] =  %f + %fi \n", i, real(X_k[i]), imag(X_k[i]));
    }

  return 0;
}