#include <stdio.h>
#include <stdlib.h>

int main() 
{
    long long int a = 1 , b = 1 , c = 1;
    scanf("%lld %lld %lld", &a, &b, &c);
    long long int rest = (a*b)%c;
    if (rest == 0 && c != 1)
    {
        long long int sum = (a*b)/c;
        printf("%lld", sum);
        return 0;
    }
    else
    {
        char result[100];
        long long int integerResult = (a*b)/c;
        long double decimalResult = (long double)(rest)/c;
        sprintf(result, "%.18LF", decimalResult);
        if (result[0] == '0' && result[1] == '.')
        {
            for (int i = 0; i < 18; i++)
            {
                result[i] = result[i+1];
            }
        }
        printf("%lld%s", integerResult, result);
        return 0;
    }   
}