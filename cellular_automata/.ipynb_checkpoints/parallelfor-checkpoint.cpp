#include <algorithm>
#include <thread>
#include <functional>
#include <vector>
#include <parallel_for.h>


int main()
{
    /// Say you want to parallelize this:
    for (int i = 0; i < 10; ++i)
        printf("%d\n", i);    

    /// Then you would do:
    
    parallel_for (10, [&](int start=0, int end=10){ 
        for (int i = start; i < end; ++i)
            printf("%d\n", i/2);
    });
    return 0;
}