#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, m, *arr = malloc(200 * sizeof(int));
    float value1 = 0, value2 = 0;
    scanf("%d", &n);
    // m = 3;
    // m = 4;
    // arr[0] = 1;
    // arr[1] = 1;
    // arr[2] = 2;
    // arr[3] = 1;
    // arr[4] = 2;
    // arr[5] = 2;
    // arr[0] = 0;
    // arr[1] = 0;
    // arr[2] = 10;
    // arr[3] = 0;
    // arr[4] = 13;
    // arr[5] = 5;
    // arr[6] = 10;
    // arr[7] = 8;

//     2
// 3 1 1 2 1 2 2
// 4 0 0 10 0 13 5 10 8


    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d", arr[i], arr[i + 1]);
        }
        int j = 0;
        for (int i = 0; i < (m * 2) - 3; i++)
        {
            if (i == 0)
            {
                j = 3;
                value1 = (value1 + (arr[0] * arr[j]));
                value2 = (value2 + (arr[j - 1] * arr[j - 2]));
            }
            else if (j + 2 < (m * 2))
            {
                
                j = j + 2;
                value1 = (value1 + (arr[j - 3] * arr[j]));
                value2 = (value2 + (arr[j - 1] * arr[j - 2]));
            }
            else
            {
                value1 = (value1 + (arr[(m * 2) - 1] * arr[1]));
                value2 = (value2 + (arr[0] * arr[(m * 2) - 1]));
            }
        }
        float area = (value1 - value2) / 2;
        if (area < 0)
        {
            area *= (-1);
        }
        printf("%0.1f", area);
    }
    return 0;
}