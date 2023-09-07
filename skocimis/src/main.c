#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);    

    printf("%d\n", ((C - B) - 1 > (B - A) - 1) ? (C - B) - 1 : (B - A) - 1);

    return 0;
}