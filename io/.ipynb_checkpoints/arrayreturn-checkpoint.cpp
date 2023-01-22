#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> arrayreturn(vector<int> arr)
{
    return arr;
}

int main(void)
{
    vector<int> x = {1,2,3};
    
    vector<int> y = arrayreturn(x);
 
    
    
    return 0;
}