#include <stdio.h>
#include <stdlib.h>

void main (void)
{
    int n = 0, minBombs = 0;
    scanf("%d", &n);
    if (n <= 3) minBombs = 1;
    else minBombs = n-2;
    printf("%d", minBombs);
}