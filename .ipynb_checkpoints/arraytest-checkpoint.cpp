#include <stdio.h>
#include <iostream>


int main(void)
{
    int test[5];
    test[0] = 0;
    test[1] = 1;
    test[2] = 2;
    test[3] = 3;
    test[4] = 4;
    for (int i=0; i<=5; ++i) 
    {
        printf("val = %d \n", test[i]);
    }
    return 0;
}
