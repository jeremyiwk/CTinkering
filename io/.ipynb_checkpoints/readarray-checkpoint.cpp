#include <iostream>
#include <fstream>

using namespace std;

int countlines(string filename)
{
    fstream readfile(filename);
    int count = 0;
    string line;
    while(readfile.peek()!=EOF)
    { 
        getline(readfile, line);
        count++;
    }
    
    readfile.close();
    return count;
}

int main(void)
{
    char filename[] = "array.txt";
    
    printf("Reading array from %s.\n", filename);
    
    int count = countlines(filename);
    
    fstream readarray(filename);
    double array[count];
    
    for (int i=0; i<count; ++i)
    {
        readarray >> array[i];
        printf("%f\n",array[i]);
        
    }
    
    readarray.close();

    return 0;
}