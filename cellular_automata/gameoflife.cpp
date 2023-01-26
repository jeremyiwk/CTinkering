/*
This is a C++ implementation of Jon Conway's Game of Life
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <Eigen/Dense>
#include <EigenRand/EigenRand>
#include <vector>
 
using namespace Eigen;
using Eigen::MatrixXd;
using namespace std;

int periodic_BC(int N, int i)
{
    if (i >= 0)
    {
        return i%N;
    }
    else
    {
        return N + (i%N);
    }
}

int count_neighbors(MatrixXi A, int n, int m)  
{
    int N = A.rows();
    int M = A.cols();
    int count = 0;
    
    count += A( periodic_BC(N, n-1), periodic_BC(M, m-1));
    count += A( periodic_BC(N, n-1), periodic_BC(M, m  ));
    count += A( periodic_BC(N, n-1), periodic_BC(M, m+1));
    count += A( periodic_BC(N, n  ), periodic_BC(M, m-1));
    count += A( periodic_BC(N, n  ), periodic_BC(M, m+1));
    count += A( periodic_BC(N, n+1), periodic_BC(M, m-1));
    count += A( periodic_BC(N, n+1), periodic_BC(M, m  ));
    count += A( periodic_BC(N, n+1), periodic_BC(M, m+1));
    return count;
}

int cell_survival(int pop, int count)
{
    int life;
    
    if (pop==0)
    {
        if (count==2 or count==3)
        {
            life = 1;
        }
    }
    
    else if (pop==1)
    {
        if (count==2 or count==3)
            life = 1;
        else
            life = 0;
    }
    else
    {
        printf("Something went wrong and the cell population is: %d\n", pop);
    }
            
    return life;
}

MatrixXi GameOfLife_nextstep(MatrixXi A)
{
    int N = A.rows();
    int M = A.cols();
    MatrixXi B = MatrixXi::Zero(N,M);
    
    for (int i=0; i<N; ++i)
    {
        for (int j=0; j<N; ++j)
        {
            int count = 0;
            count     = count_neighbors(A, i, j);
            B(i,j)    = cell_survival(A(i,j), count);
        }
    }
    return B;
}

int main(void)
{
    Eigen::Rand::P8_mt19937_64 gen{ 42 };
    using Matrix = Matrix<int, -1, -1>;
    
    int Nsteps= 10;
    int Ngrid = 40;
    Matrix A = Rand::uniformInt<Matrix>(Ngrid, Ngrid, gen, 0, 1);
    
    std::cout << "Here is the matrix m:\n" << A << std::endl;
    
    for (int i=0; i<Nsteps; ++i)
    {
        A = GameOfLife_nextstep(A);
        std::cout << A << std::endl;
    }
    
    return 0;
}