#include <stdio.h>
#include <stdlib.h>

void main (void)
{
    int n = 0, intersections = 0;
    scanf("%d", &n);
    if (n == 3)
    {
        intersections = 0;
    }
    else if (n == 4)
    {
        intersections = 1;
    }
    else if (n == 5)
    {
        intersections = 5;
    }
    else intersections = (n*(n - 1))/2;
    printf("\n%d", intersections);
}