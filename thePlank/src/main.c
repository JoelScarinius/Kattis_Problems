// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// void main (void)
// {
//     int n = 0;
//     scanf("%d", &n);
//     printf("%d", round(0.33622811699494115 * (pow(1.839286755214161, (1 + n)))));

//     // printf("%d\n", numPermutations(n));

    
// }

// #include <stdio.h>
// #include <math.h>

// int main() {
//     double result;
//     int exponent;

//     scanf("%d", &exponent);

//     result = round(0.33622811699494115 * pow(1.839286755214161, 1 + exponent));

//     printf("%.0f\n", result);

//     return 0;
// }

#include <stdio.h>
#include <math.h>

int solution(int n) {
    int arr[24], result = 0;
    for (int i = 0; i < n; i++)
    {
        if (n == 0)
        {
            arr[i]  = 1;
        }
        if (n - 1 > 0 )
        {
            arr[i] = result + arr[i];
        }
        if (n - 2 > 0)
        {
            arr[i] = result + arr[i];
        }
        result = result + arr[i];
         
    }
    return result;
    
}

int main() {
    double result;
    int exponent;

    scanf("%d", &exponent);

    result = solution(exponent);

    printf("%.0f\n", result);

    return 0;
}