#include <stdio.h>
#include <stdlib.h>

int find(int* numbers, int n, int key)
{
    int ClosestSum = 0;
    int sum = 999999999;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int result = numbers[i] + numbers[j];
            int newSum = abs(key - result);
            if (newSum < sum)
            {
                sum = newSum;
                ClosestSum = result;
            }
        }
    }

    return ClosestSum;
}

int main()
{
    int n, caseNumber = 1;
    while (scanf("%d",&n) == 1)
    {
        printf("Case %d:\n", caseNumber++);
        int* numbers = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", numbers + i);
        int queries;
        scanf("%d", &queries);
        while (queries--)
        {
            int key;
            scanf("%d",&key);
            printf("Closest sum to %d is %d.\n", key, find(numbers, n, key));
        }
    }
    return 0;
}