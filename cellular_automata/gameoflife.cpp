/*
This is a C++ implementation of Jon Conway's Game of Life
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <Eigen/Dense>
#include <EigenRand/EigenRand>
#include <vector>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <parallel_for.h>
 
using namespace Eigen;
using Eigen::MatrixXd;
using namespace std;

#define N_GRID 500

#define NxN_GRID N_GRID*N_GRID

#define N_STEPS 100


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
        if (count==3)
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
    
    // for (int i=0; i<N; ++i)
    // {
    //     for (int j=0; j<M; ++j)
    //     {
    //         int count = 0;
    //         count     = count_neighbors(A, i, j);
    //         B(i,j)    = cell_survival(A(i,j), count);
    //     }
    // }
    
    // for (int n = 0; n < NxN_GRID; ++n)
    //     {
    //         int i = n/N_GRID;
    //         int j = n - i*N_GRID;
    //         printf("(i,j) = (%d, %d)\n", i, j);
    //         int count = 0;
    //         count     = count_neighbors(A, i, j);
    //         B(i,j)    = cell_survival(A(i,j), count);
    //     }
    
    long int T = M*N;
    parallel_for (NxN_GRID, [&](int start=0, int end=NxN_GRID)
    { 
        for (int n = start; n < end; ++n)
        {
            int i = n/N_GRID;
            int j = n - i*N_GRID;
            //printf("(i,j) = (%d, %d)\n", i, j);
            int count = 0;
            count     = count_neighbors(A, i, j);
            B(i,j)    = cell_survival(A(i,j), count);
        }
    });
    return B;
}

int main(void)
{
    Eigen::Rand::P8_mt19937_64 gen{ 42 };
    using Matrix = Matrix<int, -1, -1>;
    
    int Nsteps= N_STEPS;
    int Ngrid = N_GRID;
    Matrix A = Rand::uniformInt<Matrix>(Ngrid, Ngrid, gen, 0, 1);
    
    // std::cout << "Here is the matrix m:\n" << A << std::endl;
    
    ofstream file("test.txt");
    for (int n=0; n<Nsteps; ++n)
    {
        A = GameOfLife_nextstep(A);
        file  << A << '\n';
        std::cout << n << std::endl;
        //system("clear");
    }
    file.close();
    // setlocale(LC_CTYPE, "");
    // wchar_t star = 0x25FB; //0x2605;
    // wprintf(L"%lc\n", star);
    
    
    return 0;
}