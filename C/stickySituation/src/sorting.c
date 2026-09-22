#include "sorting.h"
#include <stdio.h>

static long long int hoarePartition(long long int *a, long long int l, long long int r);

void quickSort(long long int *a, long long int l, long long int r)
{
    if(l < r)
    {
        long long int s = hoarePartition(a, l, r);
        quickSort(a, l, s-1); 
        quickSort(a, s+1, r);
    }
}

void swap(long long int *a, long long int i, long long int j)
{
    long long int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

static long long int hoarePartition(long long int *a, long long int l, long long int r)
{
    long long int p = a[l], j = r+1, i = l;
    while(i < j) 
    {
        do
        {
            i++;
        } while(a[i] < p && i < r); 
        do
        {
            j--; 
        } while(a[j] > p && j > l);
        swap(a, i, j);
    }
    swap(a, i, j); // undo last swap when i >= j
    swap(a, l, j);
    return j = (j == 0) ? j + 1 : j;
}
