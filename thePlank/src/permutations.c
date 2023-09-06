// #include <stdio.h>
// #include <stdlib.h>
// #include "permutations.h"

// int numPermutations (int n)
// {
//     int *arr = {0}, *arr2 = {0}, count = 0, result = 0; // Will always be at least one permutation
//     // if (n == 1)
//     // {
//     //     return count; 
//     // }
//     // else if (n == 2)
//     // {
//     //     return count + 1;
//     // }
//     // else
//     // {
//         // if (n == 3)
//         // {
//         //     count = count + 1;
//         // }
        
//         // arr[0] = 1;
//         // arr[1] = 2;
//         // heapPermutation(arr, 2, n, &count);
//         for (int i = 0; i < n; i++)
//         {
//             result = 0;
//             arr[i] = 1;
//             arr2[i] = arr[i];
//             for (int i = 0; i < 24; i++)
//             {
//                 result = result + arr[i];
//             }
//             if (result == n)
//             {
//                 count = count + 1;
//                 for (int i = 0; i < n; i++)
//                 {
//                     if (arr[i] == 0)
//                     {
//                         while (i - 2 >= 0)
//                         {
//                             i - 2;
//                             arr[i] = 2;
//                             heapPermutation(arr, i, n, &count);
//                         }
//                         while (i - 3 >= 0)
//                         {
//                             i - 3;
//                             arr[i] = 3;
//                             heapPermutation(arr, i, n, &count);
//                         }
//                     }

                    
//                     // if (i - 4 >= 0)
//                     // {
//                     //     arr[i - 4] = 2;
//                     //     heapPermutation(arr, i - 4, n, &count);
//                     // }
//                     // if (i - 6 >= 0)
//                     // {
//                     //     arr[i - 6] = 2;
//                     //     heapPermutation(arr, i - 4, n, &count);
//                     // }
                    
//                 }
                
//             }
//         }
//             // int arr = {1, 2, 3};
//             // heapPermutation(a, 3, n, &count);
//     // }
//     return count;
// }

// // Generating permutation using Heap Algorithm
// void heapPermutation(int arr, int size, int n, int *count) {
//     if (size == 1)
//         *count = *count + 1;

//     for (int i = 0; i < size; i++) {
//         heapPermutation(a, size - 1, n, count);

//         if (size % 2 == 1) {
//             int temp = a[0];
//             a[0] = a[size - 1];
//             a[size - 1] = temp;
//         } else {
//             int temp = a[i];
//             a[i] = a[size - 1];
//             a[size - 1] = temp;
//         }
//     }
// }