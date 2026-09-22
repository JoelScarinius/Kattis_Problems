#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point
{
    double X, Y;
};

double calcArea(struct point *p, int N)
{
    double sum = 0;
    for (int i = 0; i < N; i++) 
        sum += (p + i)->X * (p + (i + 1) % N)->Y - (p + i)->Y * (p + (i + 1) % N)->X;
    return fabs(sum) / 2;
}

int main() 
{
    int N, A, sum = 0;

    scanf("%d", &N);    

    struct point *p = malloc(N * sizeof(struct point));

    for (int i = 0; i < N; i++)
        scanf("%lf %lf", &(p + i)->X, &(p + i)->Y);

    scanf("%d", &A);

    double area = calcArea(p, N);
    double offset = sqrt(A / area);
    double minX = 500, minY = 500;
        
    for (int i = 0; i < N; i++)
    {
        (p + i)->X *= offset;
        (p + i)->Y *= offset;
        (minX < (p + i)->X) ? minX : (minX = (p + i)->X);
        (minY < (p + i)->Y) ? minY : (minY = (p + i)->Y);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%0.4lf ", (p + i)->X - minX);
        printf("%0.4lf\n", (p + i)->Y - minY);
    }

    return 0;
}