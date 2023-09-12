#include <stdio.h>
#include <stdlib.h>

typedef enum {UP, DOWN, LEFT, RIGHT} Direction;

typedef struct {
    char arr[20][21];
} FunHouse;

void placeExit(Direction direction, FunHouse *funHouse, int row, int col, int L, int W)
{
    char c = funHouse->arr[row][col];
    while (1)
    {
        if (direction == UP)
        {
            while (row < L)
            {
                c = funHouse->arr[row][col];
                if (funHouse->arr[row][col] == '/' || funHouse->arr[row][col] == '\\')
                {
                    if (funHouse->arr[row][col] == '/')
                    {
                        col--;
                        direction = LEFT;
                        break;
                    }
                    else if (funHouse->arr[row][col] == '\\')
                    {
                        col++;
                        direction = RIGHT;
                        break;
                    }
                }
                else if (funHouse->arr[row][col] == 'x')
                {
                    funHouse->arr[row][col] = '&';
                    return;
                }
                row++;
            }
        }
        if (direction == DOWN)
        {
            while (row >= 0)
            {
                c = funHouse->arr[row][col];
                if (funHouse->arr[row][col] == '/' || funHouse->arr[row][col] == '\\')
                {
                    if (funHouse->arr[row][col] == '/')
                    {
                        col++;
                        direction = RIGHT;
                        break;
                    }
                    else if (funHouse->arr[row][col] == '\\')
                    {
                        col--;
                        direction = LEFT;
                        break;
                    }
                }
                else if (funHouse->arr[row][col] == 'x')
                {
                    funHouse->arr[row][col] = '&';
                    return;
                }
                row--;
            }
        }
        if (direction == LEFT)
        {
            while (col >= 0)
            {
                c = funHouse->arr[row][col];
                if (funHouse->arr[row][col] == '/' || funHouse->arr[row][col] == '\\')
                {
                    if (funHouse->arr[row][col] == '/')
                    {
                        row++;
                        direction = UP;
                        break;
                    }
                    else if (funHouse->arr[row][col] == '\\')
                    {
                        row--;
                        direction = DOWN;
                        break;
                    }
                }
                else if (funHouse->arr[row][col] == 'x')
                {
                    funHouse->arr[row][col] = '&';
                    return;
                }
                col--;
            }
        }
        if (direction == RIGHT)
        {
            while (col < W)
            {

                c = funHouse->arr[row][col];
                if (funHouse->arr[row][col] == '/' || funHouse->arr[row][col] == '\\')
                {
                    if (funHouse->arr[row][col] == '/')
                    {
                        row--;
                        direction = DOWN;
                        break;
                    }
                    else if (funHouse->arr[row][col] == '\\')
                    {
                        row++;
                        direction = UP;
                        break;
                    }
                }
                else if (funHouse->arr[row][col] == 'x')
                {
                    funHouse->arr[row][col] = '&';
                    return;
                }
                col++;
            }
        }
    }
}

int main() 
{
    int W, L, houseCnt = 0, startRow, startCol;
    FunHouse funHouse;
    while (1)
    {
        scanf("%d %d", &W, &L);
        if (W == 0 && L == 0)
            break;

        for (int row = 0; row < L; row++)
        {
            scanf("%s", funHouse.arr[row]);
        }
        for (int row = 0; row < L; row++)
        {
            for (int col = 0; col < W; col++)
            {
                if (funHouse.arr[row][col] == '*')
                {
                    startRow = row;
                    startCol = col;
                }
            }
        }
        if (startRow == 0)
        {
            placeExit(UP, &funHouse, startRow + 1, startCol, L, W);
        }
        else if (startRow == L - 1)
        {
            placeExit(DOWN, &funHouse, startRow - 1, startCol, L, W);
        }
        else if (startCol == 0)
        {
            placeExit(RIGHT, &funHouse, startRow, startCol + 1, L, W);
        }
        else if (startCol == W - 1)
        {
            placeExit(LEFT, &funHouse, startRow, startCol - 1, L, W);
        }
        printf("HOUSE %d\n", ++houseCnt);
        for (int row = 0; row < L; row++)
        {
            for (int col = 0; col < W; col++)
            {
                printf("%c", funHouse.arr[row][col]);
            }
            printf("\n");
        }
    }

    return 0;
}