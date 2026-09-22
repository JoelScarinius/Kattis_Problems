#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mailbox.h"

int totFireCrackers(int m, int k)
{
    int count = 0, r = m, l = 0;
    if (k <= 1)
    {
        return count = (m * (m + 1))/2;
    }
    else if (k == 2)
    {
        return count = (m * (m + 1))/2;
    }
    else
    {
        while (l < r)
        {
            m = floor((l + r) / 2);
            count = count + m;
            l = m + 1;
        }
        return count;
    }
}