#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    printf("%d %d\n", *((int *)b), *((int *)a));
    return *((int *)b) - *((int *)a);
}

int main()
{
    int N, T;
    scanf("%d %d", &N, &T);

    size_t waitingTimesCnt[T + 1];
    int current[T + 1];
    memset(waitingTimesCnt, 0, (T + 1) * sizeof(size_t));
    memset(current, 0, (T + 1) * sizeof(int));
    int cashPerTime[T + 1][N];

    for (int i = 0; i < N; i++)
    {
        int cash, waitingTime;
        scanf("%d %d", &cash, &waitingTime);
        cashPerTime[waitingTime][waitingTimesCnt[waitingTime]++] = cash;
    }

    for (int i = 0; i <= T; i++)
    {
        if (waitingTimesCnt[i] > 1)
            qsort(cashPerTime[i], waitingTimesCnt[i], sizeof(int), compare);
    }

    int sum = 0;
    for (int i = T; i >= 0; i--)
    {
        int maxAbove = -1;
        int maxAboveIndex = -1;
        for (int j = i; j <= T; j++)
        {
            if (waitingTimesCnt[j] && cashPerTime[j][current[j]] > maxAbove)
            {
                maxAbove = cashPerTime[j][current[j]];
                maxAboveIndex = j;
            }
        }
        if (maxAboveIndex != -1)
        {
            sum += cashPerTime[maxAboveIndex][current[maxAboveIndex]];
            current[maxAboveIndex]++;
            waitingTimesCnt[maxAboveIndex]--;
        }
    }

    printf("%d\n", sum);

    return 0;
}