/*
 * This is an implementation of the heap sort algorithm as described
 * in this wikipedia article : https://en.wikipedia.org/wiki/Heapsort#Algorithm.
 * We shall do this using vectors from the standard library.
 *
 * Author : Jeremy Welsh-Kavan
 * Date : 03/12/2023
 */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <utility>


using namespace std;


int iParent(int node)
{
    return floor((node - 1)/2);
}

int iLeftChild(int node)
{
    return 2*node + 1;
}

void shiftDown(vector<float>&a, int start, int end)
{
    int root = start;
    
    while (iLeftChild(root) <= end)
    {
        int child = iLeftChild(root);
        int swap = root;
        
        if (a[swap] < a[child])
        {
            swap = child;
        }
        if (child + 1 <= end and a[swap] <= a[child + 1])
        {
            swap = child + 1;
        }
        if (swap == root)
        {
            break;
        }
        else
        {
            std::swap(a[root],a[swap]);
            root = swap;
        }
    }
    
}

void heapify(vector<float>& a, int count)
{
    int start = iParent(count - 1);
    
    while (start >= 0)
    {
        shiftDown(a, start, count - 1);
        start -= 1;
    }
}


void heapsort(vector<float>& a)
{
    int count = a.size();
    
    heapify(a, count);
    
    int end = count - 1;
    
    while (end > 0)
    {
        std::swap(a[end],a[0]);
        end -= 1;
        
        shiftDown(a, 0, end);
    }
}



int main(void)
{
    
    vector<float> nums = { 0, 10, 4, 3, 3,2,3,20,1 };
 
    heapsort(nums);
 
    for (int i: nums) {
        std::cout << i << endl;
    }
    
    
    return 0;
}