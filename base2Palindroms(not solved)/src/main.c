#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the length and position of the k-th palindrome
void length_kth(int n, int *length, int *position) {
    int accumulated_counts = 1;
    int l = 1;

    while (accumulated_counts < n) {
        l++;
        if (l % 2 == 0) {
            accumulated_counts += (int)pow(2, (l - 2) / 2);
        } else {
            accumulated_counts += (int)pow(2, (l - 1) / 2);
        }
    }

    *length = l;
    *position = n - accumulated_counts + 1;
}

// Function to generate the n-th binary palindrome
unsigned int nth_bin_palindrome(int n) {
    if (n < 3) {
        return (1 << n) - 1; // Return 2^n - 1
    }

    int length, position;
    length_kth(n, &length, &position);

    int k = position - 1;
    unsigned int palindrome = 1;

    if (length % 2 == 0) {
        int half_length = (length - 2) / 2;
        palindrome = (1 << (half_length + 1)) | (k << half_length) | (1 << half_length);
    } else {
        int half_length = (length - 1) / 2;
        palindrome = (1 << (half_length + 1)) | (k << half_length);
    }

    return palindrome;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    unsigned int result = nth_bin_palindrome(n);
    printf("The %d-th binary palindrome is: %u\n", n, result);

    return 0;
}
