#include <stdio.h>
#include <stdlib.h>

int main() 
{
    struct point
    {
        int x;
        int y;
    };
    int n, m;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        scanf("%d", &m);
        struct point *p = malloc(m * sizeof(struct point));

        for (int i = 0; i < m; i++)
            scanf("%d %d", &(p + i)->x, &(p + i)->y);

        for (int i = 0; i < m; i++) 
            sum += (p + i)->x * (p + (i + 1) % m)->y - (p + i)->y * (p + (i + 1) % m)->x;

        if (sum & 1) printf("%.1f\n", sum / 2.0);
        else printf("%d\n", sum >> 1);
    }
    return 0;
}