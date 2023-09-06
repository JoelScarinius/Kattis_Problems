#include <stdio.h>
#include <stdlib.h>
#include "mailbox.h"

void main (void)
{
    int n = 1, k = 3, m = 73;
    // scanf("%d", &n);
    int *arr = malloc(sizeof(int)*n);
    arr[0] = n;
    for (int i = 1; i <= n; i++)
    {
        // scanf("%d %d", &k, &m);
        arr[i] = totFireCrackers(m, k);
    }
    for (int i = 0; i <= n; i++)
    {
        printf("\n%d", arr[i]);
    }
}