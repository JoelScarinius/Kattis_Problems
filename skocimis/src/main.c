#include <stdio.h>
#include <stdlib.h>

void maxMoves(int A, int B, int C, int *moves, char *arr) 
{
    if ((arr[A + 1] == arr[B] && arr[B + 1] == arr[C]) || (arr[B + 1] == arr[A] && arr[A + 1] == arr[C]))
    {
        return;
    }
    else if (arr[A + (B - A) + 1] != arr[C] && (*moves % 2 == 0))
    {
        arr[A + (B - A) + 1] = arr[A];
        *moves = *moves + 1;
        maxMoves(A + (B - A) + 1, B, C, moves, arr);
    }
    else
    {
        arr[B + (A - B) + 1] = arr[B];
        *moves = *moves + 1;
        maxMoves(A, B + (A - B) + 1, C, moves, arr);
    }
}

// int main() 
// {
//     char *arr = malloc(100 * sizeof(char));
//     int A, B, C, moves = 0;

//     scanf("%d %d %d", &A, &B, &C);

//     for (int i = 0; i < 100; i++)
//     {
//         arr[i] = 'X';
//     }
//     arr[A] = 'A';
//     arr[B] = 'B';
//     arr[C] = 'C';
//     maxMoves(A, B, C, &moves, arr);
    
//     free(arr);

//     printf("%d\n", moves);

//     return 0;
// }

int main() 
{
    int A, B, C;

    scanf("%d %d %d", &A, &B, &C);    

    printf("%d\n", ((C - B) - 1 > (B - A) - 1) ? (C - B) - 1 : (B - A) - 1);

    return 0;
}