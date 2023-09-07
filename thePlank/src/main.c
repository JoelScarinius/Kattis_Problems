#include <stdio.h>
#include <math.h>

int main() {
    double result;
    int exponent;

    scanf("%d", &exponent);

    result = round(0.33622811699494115 * pow(1.839286755214161, 1 + exponent));

    printf("%.0f\n", result);

    return 0;
}