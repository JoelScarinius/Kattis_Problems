#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int row, col, cars = 0, cars0 = 0, cars1 = 0, cars2 = 0, cars3 = 0, cars4 = 0;
    scanf("%d %d", &row, &col);
    char arr[row][col + 1];
    for (int i = 0; i < row; i++)
    {
        scanf("%s", &arr[i]);
    }

    for (int i = 0; i < row - 1; i++)
    {
        for (int j = 0; j < col - 1; j++)
        {
            if (arr[i][j] == '#' || arr[i][j + 1] == '#' || arr[i + 1][j] == '#' || arr[i + 1][j + 1] == '#')
            {
                continue;
            }
            else
            {
                if (arr[i][j] == 'X') cars++;
                if (arr[i][j + 1] == 'X') cars++;
                if (arr[i + 1][j] == 'X') cars++;
                if (arr[i + 1][j + 1] == 'X') cars++;
            }
            if (cars == 0) cars0++;
            else if (cars == 1) cars1++;
            else if (cars == 2) cars2++;
            else if (cars == 3) cars3++;
            else if (cars == 4) cars4++;
            cars = 0;
        }
    }

    printf("%d\n", cars0);
    printf("%d\n", cars1);
    printf("%d\n", cars2);
    printf("%d\n", cars3);
    printf("%d\n", cars4);
    
    return 0;
}

