#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int calcDaysToConquer(int **arr, int row, int col)
{
    int days = 1;
    bool isConquered = false;
    while (!isConquered)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                conquerCells(arr, i, j, row, col, &isConquered);
            }
        }
        // check if conquering is completed
        if (isConquered) return days;
        else
        {
            isConquered = true;
            preConqueredCells(arr, row, col, &isConquered);
            if (days == 1 && isConquered == true) return days; // if all cells are occupied from the beginning
            else days++;
        }
        // check if conquering is completed
        if (isConquered) return days;
    }
}

void conquerCells(int **arr, int i, int j, int row, int col, bool *isConquered)
{
    if (arr[i][j] == 2) // 0 for unoccupied 1 for occupied 2 for previous occupied
    {
        if (j + 1 <= col && arr[i][j + 1] == 0)
        {
            arr[i][j + 1] = 1;
        }
        if (j - 1 >= 1 && arr[i][j - 1] == 0)
        {
            arr[i][j - 1] = 1;
        }
        if (i + 1 <= row && arr[i + 1][j] == 0)
        {
            arr[i + 1][j] = 1;
        }
        if (i - 1 >= 1 && arr[i - 1][j] == 0)
        {
            arr[i - 1][j] = 1;
        }
    }
    else *isConquered = false;
}

void preConqueredCells(int **arr, int row, int col, bool *isConquered)
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (arr[i][j] == 1) // 0 for unoccupied 1 for occupied 2 for previous occupied
            {
                arr[i][j] = 2;
            }
            if (arr[i][j] == 0)
            {
                *isConquered = false;
            }
        }
    }
}

int main() 
{
    int N, R, C, days = 1, row, col;
    
    scanf("%d %d %d", &R, &C, &N);

    int **arr = calloc(R, sizeof(int *));
    for (int i = 1; i <= R; i++)
    {
        arr[i] = calloc(C + 1, sizeof*(arr[i]));
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &row, &col);
        arr[row][col] = 2; // 0 for unoccupied 1 for occupied 2 for previous occupied
    }
    printf("%d", calcDaysToConquer(arr, R, C));    
    return 0;
}