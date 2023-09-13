#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringMatching.h"

// Fills the shift table used by Horspool’s and Boyer-Moore algorithms
// Input: Pattern P[0..m − 1] and an alphabet of possible characters
// Output: Table[0..size − 1] indexed by the alphabet’s characters and
// filled with shift sizes computed by formula (7.1)
static char *shiftTable(char *S, char *alphabet, int m, int n);
// Fills the suffix used by Boyer-Moore algorithm
// Input: Pattern P[0..m − 1] and the length of the pattern
// Output: goodTable[0..m − 1] filled with m number of shifts depended on number of matches.
static int *suffix(char *S, unsigned int m);
// This is a helper function to the suffix function that collects the substring that is
// needed for searching for duplicates of this substring in the pattern.
// Input: Pattern P[0..m − 1] and two index variables represented as unsigned ints.
// One is the length of the pattern and the other is the length of the pattern minus the number of matches.
// Output: A substring represented as a char pointer.
static char *getSubstring(char *S, unsigned int i, unsigned int m);
// This is a helper function to the suffix function that finds out at which index
// from the right you can find a duplicate of the matched substring. 
// Input: Pattern [0..m − 1],  substring [0..m − 2] and two index variables represented as unsigned ints.
// One is the length of the pattern and the other is the number of matches. 
// Output: An index of the right most occurrence of a matching substring.
static int getMatchingIdx(char *subString, char *S, unsigned int k, unsigned int m, int *duplicateIdx);

int bruteForceMatching(char *S, char *L)
{
    int matches = 0;
    unsigned int m = strlen(S), n = strlen(L);
    for (int i = 0; i <= n-m; i++)
    {
        unsigned int j = 0;
        while (j < m && S[j] == L[i+j])
        {
            j++;
        }
        if (j == m) matches++; // If every character in the pattern is matched increment matches.
    }
    return matches;
}

int bMHorspoolMatching(char *S, char *L, char *ascii, unsigned int option)
{   
    int m = strlen(S), i = m-1, matches = 0; // i keeps track of which characters that are supposed to be compared.
    unsigned int n = strlen(L), *goodTable;
    char *badTable = shiftTable(S, ascii, m, n); // Used in both Horspool and Boyer-Moore
    if (option == 3) 
    {
        goodTable = suffix(S, m); // Used only in Boyer-Moore
    }
    while (i <= n-1)
    {
        int k = 0; // Variable that counts number of matches.
        // Loops until a mismatch occur or every character in the pattern is matched.
        while (k <= m-1 && S[m-1-k] == L[i-k])
        {
            k++;
        }    
        if (k == m) 
        {
            matches++; // If every character in the pattern is matched increment matches.
            i += m; // Shifts i to the next possible match.
        }
        else 
        {
            if (option == 3) // Only Boyer-Moore uses this part.
            {
                if (k == 0) i += (int)(badTable[(int)L[i-k]]-k);
                // The maximum value generated from the 2 tables decides how many steps can be shifted.
                else
                {
                    i += ((int)(badTable[(int)L[i-k]]-k) > ((int)goodTable[k-1])) 
                    ? (int)(badTable[(int)L[i-k]]-k) : (int)goodTable[k-1];
                }
            }
            else i += badTable[(int)L[i]]; // Only Horspool uses this part.
        }
    }
    free(goodTable); // Free memory allocated for goodTable because it is no longer used.
    return matches;
}

static char *shiftTable(char *S, char *ascii, int m, int n)
{
    for (unsigned int i = 0; i <= ASCII; i++) // Fills the shiftTable with max steps possible to shift.
        ascii[i] = m;
    for (unsigned int j = 0; j <= m-2 && m-1 > 0; j++) // Gives certain shift steps to the characters in the pattern.
        ascii[(int)S[j]] = m-1-j;
    return ascii;
}

static int *suffix(char *S, unsigned int m)
{
    int *goodTable = (int *)calloc(m-1,sizeof(int)); // Allocates memory for the good suffix table.
    unsigned int k = 1; // Variable that controls number of matches.

    while (k < m) // Loops until all different number of substrings is handled correctly
    {
        int duplicateIdx = -1;
        char* subString = getSubstring(S, (m-k), m); // Returns Substring used to find duplicates in pattern.
        int idx = getMatchingIdx(subString, S, k, m, &duplicateIdx); // Idx of the rightmost first occurrence of substring.
        free(subString); // Free memory allocated for substring because it is no longer used.
        // If a rightmost occurrence of the substring is found or we have duplicates of the substring that makes it possible to preform a longer shift.
        if (idx != -1) goodTable[k-1] = (duplicateIdx >= idx || k == 1) ? (m-k) - idx : m-1-duplicateIdx; 
        // If a rightmost occurrence of the substring wasn't found but a substring was found in an earlier iteration.
        else if (idx == -1 && duplicateIdx != -1) goodTable[k-1] = (duplicateIdx != 0) ? m-1-duplicateIdx : m-1; 
        else goodTable[k-1] = m; // If no occurrence of the substring was found in first iteration.
        k++;
    }
    return goodTable;
}

static char *getSubstring(char *S, unsigned int i, unsigned int m)
{
    char* substring = calloc((m-i)+1, sizeof(char)); // Allocates memory for the substring and initializes it.
    for (unsigned int k = i; k < m; k++) substring[k-i] = S[k]; // Creates the substring depended on number of matches.
    return substring;
}

static int getMatchingIdx(char *subString, char *S, unsigned int k, unsigned int m, int *duplicateIdx)
{
    int idx = -1;
    char *temp = S;
    // Compares pattern with substring and if match is found assign idx with index of rightmost occurrence.
    while (temp < S + (m-k))
    {
        if (strncmp(temp, subString, k)==0) idx = temp-S;
        temp++;
    }
    temp = S; // Resets temp to pattern.
    unsigned int i = k, j = 0;

    while (temp <= S + (m-1) && i > 0)
    {
        // Compares pattern with all substrings of the substring to look for duplicates of the different substrings.
        if (strncmp(temp, subString + j, i)==0 && temp-S < (m-k))
        {
            // Assign leftmost index of found duplicate substring if a longer shift is possible, determined by restraints.
            if (temp-S < *duplicateIdx || *duplicateIdx == -1) 
            {    
                if (*duplicateIdx - (k-1) != 0) 
                {
                    if (temp-S == 0 || ((temp-S) - (strlen(subString + j)-1)) == 0)
                    {
                        *duplicateIdx = temp-S;
                        if (k > 1) *duplicateIdx += i-1;
                        // If optimal shift is found return.
                        if (*duplicateIdx - (strlen(subString + j)-1) == 0) return idx; 
                    }
                    // Secures that the correct index is assigned depended on number of matches at this certain iteration.
                    temp += (m-i-1); // Makes the loop to jump to next iteration. 
                }
            }
        }
        temp++;
        if (temp >= S + (m-1)) // Changes values to be correct for next iteration.
        {
            i--;
            j++;
            temp = S; // Resets temp to pattern.
        }
    }
    return idx;
}
