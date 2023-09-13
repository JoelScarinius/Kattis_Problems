#include <stdio.h>

int main() 
{
    int b, k, g, days = 0, groups = 0;
    
    scanf("%d %d %d", &b, &k, &g);

    groups = k / g;
    while (b > 1)
    {
        days++;
        b -= groups;
    }

    printf("%d\n", days);

    return 0;
}