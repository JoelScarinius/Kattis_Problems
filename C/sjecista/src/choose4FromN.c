#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "choose4FromN.h"

int choose4FromN(int n, int k)
{
    if (n == k)
    {
        return 1;
    }
    else
    {
        return n * choose4FromN(n - 1, k);
    }
}