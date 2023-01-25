#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <Eigen/Dense>
 
using Eigen::MatrixXd;
using namespace std;

int poweroftwo(int N)
{
    int D = (int)log2(N-1) + 1;
    long int p = pow(2,D);
    return p;
}

bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
}


MatrixXd pad_to_square(MatrixXd A, int D)
{
    int N = A.rows();
    int M = A.cols();
    assert(max(N,M) <= D);
    
    MatrixXd A0 =  MatrixXd::Zero(D,D);
    A0.block(0,0,N,M) = A;
    return A0;
}


MatrixXd matmul_2x2(MatrixXd A, MatrixXd B)
{
    int N = A.rows();
    int K = A.cols();
    int L = B.rows();
    int M = B.cols();
    
    assert(N==K && L==M && K==L);
    assert(isPowerOfTwo(N));
    
    int h = (int)(N/2);
    
    MatrixXd C = MatrixXd::Zero(N,N);
    
    if (N == 1)
    {    C(0,0) = A(0,0)*B(0,0);
        return C;
    }
    else
    {
        C.block(0,0,h,h) = matmul_2x2(A.block(0,0,h,h), B.block(0,0,h,h)) + matmul_2x2(A.block(0,h,h,h), B.block(h,0,h,h));
    
        C.block(0,h,h,h) = matmul_2x2(A.block(0,0,h,h), B.block(0,h,h,h)) + matmul_2x2(A.block(0,h,h,h), B.block(h,h,h,h));
    
        C.block(h,0,h,h) = matmul_2x2(A.block(h,0,h,h), B.block(0,0,h,h)) + matmul_2x2(A.block(h,h,h,h), B.block(h,0,h,h));
    
        C.block(h,h,h,h) = matmul_2x2(A.block(h,0,h,h), B.block(0,h,h,h)) + matmul_2x2(A.block(h,h,h,h), B.block(h,h,h,h));
        
        return C;
    }
}


// MatrixXd matmul(MatrixXd A, MatrixXd B)
// {
//     int N = A.rows();
//     int K = A.cols();
//     int L = B.rows();
//     int M = B.cols();
    
//     assert(L == K);
    
//     int Adim = max(N,L);
//     int Bdim = max(L,M);
//     int maxDim = max(Adim, Bdim);
//     D = poweroftwo(maxDim);
    
// }


int main(void)
{
    int N = 5;
    int p;
    p = poweroftwo(N);
    
    printf("The smallest power of 2 greater than %d is %d\n", N, p);
    
    MatrixXd A(2,2);
    A(0,0) = 3;
    A(1,0) = 2.5;
    A(0,1) = -1;
    A(1,1) = A(1,0) + A(0,1);
    std::cout << A << std::endl;
    
    MatrixXd C;
    
    C = 2*A;
    std::cout << C << std::endl;
    
    MatrixXd D;
    
    D = matmul_2x2(A, C);
    
    std::cout << D << std::endl;

    MatrixXd P;
    
    P = A*C;
    
    std::cout << P << std::endl;
    return 0;
}