#ifndef stringMatching_H_
#define stringMatching_H_

#include <stdlib.h>

#define ASCII 128

// Implements brute-force string matching
// Input: An array T [0..n − 1] of n characters representing a text,
// an array P[0..m − 1] of m characters representing a pattern and
// Output: Number of matches
// or −1 if there are no matches
int bruteForceMatching(char *S, char *L);

// Implements Boyer-Moore and Horspool’s algorithm for string matching.
// Input: Pattern P[0..m − 1], text T [0..n − 1],
// an alphabet (ascii) of possible characters,
// an option variable to determine BoyerMoore or Horspool algorithm
// Output: Number of matches
// or −1 if there are no matches
int bMHorspoolMatching(char *S, char *L, char *ascii, unsigned int option);

#endif