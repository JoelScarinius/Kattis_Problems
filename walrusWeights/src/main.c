#include <stdio.h>

int main() {
    int n, diff = 1000;
    scanf("%d",&n);
    int platesWeight[n];

    for (int i = 0; i < n; i++) 
    {
        scanf("%d",&platesWeight[i]);
        if (platesWeight[i] == 1000 )
        {
            diff = 0;
        }
    }
    if (diff == 0 || n == 1)
    {
        printf("%d", (n == 1) ? platesWeight[0] : 1000);
        return 0;
    }

    int storedDiffs[2][1001];

    for (int i = 0; i <= 1000; i++) {
        storedDiffs[0][i] = i < (i > platesWeight[0] ? i - platesWeight[0] : platesWeight[0] - i) ? 0 : platesWeight[0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 1000; j++) {
            int include = platesWeight[i] > j ? platesWeight[i] : platesWeight[i] + storedDiffs[!(i & 1)][j - platesWeight[i]], exclude = storedDiffs[!(i & 1)][j];
            int a1 = j > include ?  j - include : include - j, a2 = j > exclude ? j - exclude : exclude - j;
            storedDiffs[i & 1][j] = a1 == a2 ? (include > exclude ? include : exclude) : (a1 < a2 ? include : exclude);
        }
    }
    printf("%d\n", storedDiffs[!(n & 1)][1000]);
    return 0;
}