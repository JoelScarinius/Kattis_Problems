#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int x = 0, y = 0, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    double minDistance = 999;
    scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);

    if (x < x1) {
        if (y < y1) {
            minDistance = sqrt(pow(x1 - x, 2) + pow(y1 - y, 2));
        } else if (y > y2) {
            minDistance = sqrt(pow(x1 - x, 2) + pow(y - y2, 2));
        } else {
            minDistance = x1 - x;
        }
    } else if (x > x2) {
        if (y < y1) {
            minDistance = sqrt(pow(x - x2, 2) + pow(y1 - y, 2));
        } else if (y > y2) {
            minDistance = sqrt(pow(x - x2, 2) + pow(y - y2, 2));
        } else {
            minDistance = x - x2;
        }
    } else {
        if (y < y1) {
            minDistance = y1 - y;
        } else if (y > y2) {
            minDistance = y - y2;
        } else {
            minDistance = 0.0;
        }
    }
    printf("%0.3f\n", minDistance);
    return 0;
}