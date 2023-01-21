// std::real example
#include <iostream>     // std::cout
#include <complex>      // std::complex, std::real
#include <math.h>

using namespace std;

int main ()
{
  complex<double> mycomplex (10.0,1.0);

  cout << "Real part: " << real(mycomplex) << '\n';

  return 0;
}