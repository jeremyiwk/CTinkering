#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

vector<double> multiply(vector<double> A, vector<double> B)
{
    vector<double> C = A;
    
    for (int i = 0; i < A.size(); ++i)
    {
        C[i] = A[i]*B[i];
    }
    return A;
}

int main(void)
{
    vector<double> A = {1, 2, 4, 8};
    vector<double> B = {1, 2, 3, 4};
    vector<double> C;
    C = multiply(A, B);
    
    for (int i = 0; i < A.size(); ++i)
    {
        printf("%d\n", i); 
    }
    
    printf("A = {%f, %f, %f, %f}\n", A[0], A[1], A[2], A[3]);
    printf("B = {%f, %f, %f, %f}\n", B[0], B[1], B[2], B[3]);
    printf("C = {%f, %f, %f, %f}\n", C[0], C[1], C[2], C[3]);
    return 0;
}
