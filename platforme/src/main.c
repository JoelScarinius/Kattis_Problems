// #include <stdio.h>
// #include <stdlib.h>

// struct point
// {
//     int X1, X2, Y;
// };

// int main() 
// {
//     int N, maxX = 0, maxY = 0, minX = 10000, minY = 10000, totLength = 0, platForm = 0, count = 0;
//     // int x1, x2, y;
//     scanf("%d", &N);

//     struct point *p = malloc(N * sizeof(struct point));
//     int arr[100][100] = {0};

//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d %d", &(p + i)->Y, &(p + i)->X1, &(p + i)->X2);
//         // scanf("%d %d %d", &y, &x1, &x2);
//         // (p + i)->Y = y;
//         // (p + i)->X1 = x1;
//         // (p + i)->X2 = x2;
//         for (int j = (p + i)->X1; j <= (p + i)->X2; j++)
//         {
//             if (arr[(p + i)->Y][j] == 1)
//                 count++;
//             arr[(p + i)->Y][j] = 1;
//         }        
//         maxY = ((p + i)->Y > maxY) ? (p + i)->Y : maxY;
//         maxX = ((p + i)->X2 > maxX) ? (p + i)->X2 : maxX;
//         minX = ((p + i)->X1 < minX) ? (p + i)->X1 : minX;
//         minY = ((p + i)->Y < minY) ? (p + i)->Y : minY;
//     }

//     for (int i = minY; i <= maxY; i++)
//     {
//         for (int j = minX; j <= maxX; j++)
//         {
//             if (arr[i][j] == 1 && (arr[i][j + 1] == 0 || arr[i][j - 1] == 0)) 
//             {
//                 for (int k = i; k > 0; k--)
//                 {
//                     if (arr[k][j] != 1||k == i)
//                         totLength += 1;
//                     else if (arr[k][j - 1] != 1 && arr[i][j + 1] != 1 && arr[k][j + 1] == 1)
//                         totLength += 1;
//                 }
//             }
//         }
//     }

//     // for (int i = 0; i <= maxY; i++)
//     // {
//     //     for (int j = 0; j <= maxX; j++)
//     //     {

//             // float x1 = (p + platForm)->X1;
//             // float x2 = (p + platForm)->X2;
//             // int y = (p + platForm)->Y;
//             // if (i == (p + platForm)->Y && (j == (p + platForm)->X1 || j == (p + platForm)->X2))
//             // {
//             //     while (y !=  (x1 + 0.5 || x2 - 0.5))
//             //     {
//             //         if (x1 + 0.5 == j || x2 - 0.5 == j)
//             //         {
//             //             totLength += 1;
//             //         }
//             //         x1 += 1;
//             //         x2 -= 1;
//             //     }
//             //     for (int k = i, l = 0; k > 0; k--, l++)
//             //     {
//             //         if ((p + l)->Y == k && (p + l)->X1 <= j + 0.5 && j - 0.5 <= (p + l)->X2)
//             //         {
//             //             totLength += 1;
//             //         }
//             //     }
//             //     if (j == (p + platForm)->X2) platForm++;
//             // }
//     //     }
//     // }
//     printf("%d", totLength);
//     return 0;
// }

#include <stdio.h>

int length(int platforms[][3], int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int y = platforms[i][0];
        int x1 = platforms[i][1];
        int x2 = platforms[i][2];
        
        int l = -1, r = -1;
        
        for (int j = i - 1; j >= 0; j--) {
            int y2 = platforms[j][0];
            int x3 = platforms[j][1];
            int x4 = platforms[j][2];
            
            if (l == -1 && x3 <= x1 && x1 <= x4) {
                l = y - y2;
            }
            
            if (r == -1 && x3 <= x2 && x2 <= x4) {
                r = y - y2;
            }
            
            if (l != -1 && r != -1) {
                break;
            }
        }
        
        s += (l != -1 ? l : y) + (r != -1 ? r : y);
    }
    return s;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int platforms[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &platforms[i][0], &platforms[i][1], &platforms[i][2]);
    }
    
    printf("%d\n", length(platforms, n));
    
    return 0;
}
