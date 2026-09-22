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
#include <string.h>

int countMatches(char pattern[], char text[]) {
    int patternLen = strlen(pattern);
    int textLen = strlen(text);
    int count = 0;

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == patternLen) {
            count++;
        }
    }

    return count;
}

int countRemovals(char pattern[], char text[]) {
    int patternLen = strlen(pattern);
    int textLen = strlen(text);
    int count = 0;

    for (int i = 0; i < patternLen; i++) {
        char temp[patternLen];
        int index = 0;
        for (int j = 0; j < patternLen; j++) {
            if (j != i) {
                temp[index++] = pattern[j];
            }
        }
        temp[index] = '\0';

        count += countMatches(temp, text);
    }

    return count;
}

int countReplacements(char pattern[], char text[]) {
    int patternLen = strlen(pattern);
    int textLen = strlen(text);
    int count = 0;

    for (int i = 0; i < patternLen; i++) {
        for (char replacement = 'A'; replacement <= 'T'; replacement++) {
            if (replacement != pattern[i]) {
                char temp[patternLen];
                for (int j = 0; j < patternLen; j++) {
                    if (j == i) {
                        temp[j] = replacement;
                    } else {
                        temp[j] = pattern[j];
                    }
                }
                temp[patternLen] = '\0';

                count += countMatches(temp, text);
            }
        }
    }

    return count;
}

int main() {
    char pattern[101], text[1001];
    while (1) {
        scanf("%s", pattern);
        if (strcmp(pattern, "0") == 0) {
            break;
        }
        scanf("%s", text);

        int exactMatches = countMatches(pattern, text);
        int removals = countRemovals(pattern, text);
        int replacements = countReplacements(pattern, text);

        printf("%d %d %d\n", exactMatches, removals, replacements);
    }

    return 0;
}

