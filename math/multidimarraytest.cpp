#include <stdio.h>
#include <iostream>

int main(void)
{
    int ind1 = 10, ind2 = 10;
    
    int multi[ind1][ind2];
    
    for (int i=0; i<ind1; ++i)
    {
        for (int j=0; j<ind2; ++j)
        {
            multi[i][j] = (i+1)*(j+1);
        }
    }
    
    FILE *file;
    file = fopen("multiarray.txt","w+");

    for (int i=0; i<ind1; ++i)
    {
        for (int j=0; j<ind2; ++j)
        {
            if (j==ind2-1)
                fprintf(file, "%d %s", multi[i][j], "\n");
            else
                fprintf(file, "%d %s", multi[i][j], ", ");
        }
    }
    
    fclose(file);
    return 0;
}