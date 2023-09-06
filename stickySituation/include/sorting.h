#ifndef sorting_H_
#define sorting_H_

#include <stdlib.h>

//Sorts a subarray by quicksort
//Input: Subarray of array A[0..n − 1], defined by its left and right
// indices l and r
//Output: Subarray A[l..r] sorted in nondecreasing order
void quickSort(long long int *arr, long long int l, long long int r);

// Swaps to elements in an array.
// Input: Array Arr[0..n − 1], and 2 idexes i and j;
// indices l and r
// Output: Void but the array have now swapped elements
void swap(long long int *arr, long long int i, long long int j);

#endif