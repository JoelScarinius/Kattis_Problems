#include <stdio.h>
#include "sorting.h"
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    long long int n = 0;
    scanf("%lld", &n); // Input number of sticks
    long long int r = n - 1, l = 0;
    long long int *arr = malloc(n * sizeof(long long int));
    bool isPossible = false;


    for (long long int i = 0; i < n; i++)
    {
        long long int stickLength = 0;
        scanf("%lld", stickLength); // Input length of sticks
        arr[i] = stickLength;
        // arr[i] = 1;
    }
    // arr[0] = 3;
    // arr[1] = 1;
    // arr[2] = 10;
    // arr[3] = 5;
    // arr[4] = 15;

    quickSort(arr, l, r);// Starts quickSort

    // for (long long int i = 0; i < n; i++)
    // {
    //     printf("%lld ", arr[i]);
    // }
    

    for (long long int i = 0; i < n - 2 ; i++)
    {
        if ((arr[i] + arr[i+1]) > arr[i+2])
        {
            if (arr[i] + arr[i+2] > arr[i+1])
            {
                if (arr[i+1] + arr[i+2] > arr[i])
                {
                    isPossible = true;
                }
            }
        }
        else
        {
            i = i + 2;
        }
    }

    if (isPossible)
    {
        printf("\npossible");
    }
    else
    {
        printf("\nimpossible");
    }    
    return 0;
}
