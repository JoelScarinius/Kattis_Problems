#include <stdio.h>
#include <stdlib.h>
#include "insertionSort.h"

void insertionSort(int n, int a[])
{
    for (int i = 1; i <= n-1; i++)
    {
        int val = a[i], j = i-1;
        while (j >= 0 && a[j] > val)
        {
            a[j+1] = a[j]; 
            j -= 1;
        }
        a[j+1] = val;
    }
}