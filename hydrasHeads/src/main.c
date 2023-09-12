#include <stdio.h>

int fightHydra(int H, int T)
{
    int S = 0;

    while (T >= 3)
    {
        T -= 2;
        S++;
        H++;
    }
    if (T == 1)
    {
        if (H % 2 == 0)
        {
            S += 5;
            H += 2;
        }
        else
        {
            S += 2;
            H++;
        }
        T--;
    }
    else
    {
        if (H % 2 == 0)
        {
            S += 4;
            H += 2;
        }
        else
        {
            S++;
            H++;
        }
    }
    if (H % 2 == 0)
    {
        while (H > 0) 
        {
            H -= 2;
            S++;
        }
    }
    else S = -1;

    return S;
}

int main() 
{
    while (1)
    {
        int H, T, S;
        scanf("%d %d", &H, &T);
        if (H == 0 && T == 0)
            break;
        S = fightHydra(H, T);
        printf("%d\n", S);
    }

    return 0;
}