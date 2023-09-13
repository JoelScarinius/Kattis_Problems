// #include <stdio.h>
// #include <stdlib.h>
// #include "stringMatching.h"

// #define MAX 100

// int main() 
// {
//     // char S[MAX], L[MAX];
//     char ascii[ASCII];
//     int type1Matches = 0, type2Matches = 0, type3Matches = 0, size = 0;
//     char *S = (char *)malloc(sizeof(char)*MAX);
//     char *L = (char *)malloc(sizeof(char)*MAX);
//     while (1)
//     {
//         scanf("%s %s", S, L);
//         // if ( == "0")
//         //     break;
//         size = strlen(S);
//         for (int i = size; i >= 0; i--)
//         {
//             if (i == size)
//             {
//                 type1Matches = bMHorspoolMatching(S, L, ascii, 3, size - i);
//             }
//         }
        
//         type1Matches = bMHorspoolMatching(S, L, ascii, 3); 
//         // type2Matches = bMHorspoolMatching(S, L, ascii, 3); // WHY DOES L become empty in this call?
//         // type3Matches = bMHorspoolMatching(S, L, ascii, 3);

//         printf("%d %d %d\n", type1Matches, type2Matches, type3Matches);
//     }
//     free(S);
//     free(L);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create the types dictionary
void getTypesDict(char *s1, int *types) {
    int len = strlen(s1);
    types[0] = 1; // Initialize s1 to type 1

    // Iterate over all substrings of s1
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            types[atoi(s1 + i)] = 2; // Set substrings to type 2
        }
    }

    // Iterate over all positions to insert A, C, G, and T
    for (int i = 0; i <= len; i++) {
        char newStr[32]; // Assuming a maximum length of 31 for input strings
        for (char base = 'A'; base <= 'T'; base += 4) {
            strcpy(newStr, s1);
            memmove(newStr + i + 1, newStr + i, len - i + 1); // Shift characters to make space
            newStr[i] = base; // Insert the base at the current position
            types[atoi(newStr)] = 3; // Set the new string to type 3
        }
    }
}

// Function to get types count for s2
void getTypesCount(char *s2, int *types, int *counter) {
    int len = strlen(s2);

    // Iterate over all substrings of s2
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j <= len; j++) {
            counter[types[atoi(s2 + i)]]++; // Increment the counter based on the type
        }
    }
}

int main() {
    while (1) {
        char s1[32], s2[32];
        scanf("%s", s1);
        if (s1[0] == '0') {
            break;
        }

        scanf("%s", s2);

        int types[10000] = {0}; // Assuming a maximum length of 9999 for s1
        int counter[4] = {0};

        getTypesDict(s1, types);
        getTypesCount(s2, types, counter);

        // Print the results
        for (int i = 1; i <= 3; i++) {
            printf("%d ", counter[i]);
        }
        printf("\n");
    }

    return 0;
}
