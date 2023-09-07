#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "findHidingPlaces.h"

int main() 
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        char position[3];
        scanf("%s", position);
        Position start = chessNotationToIndices(position);
        Position hidingPlaces[64];
        int distances[64];

        int hidingPlacesCount = findHidingPlaces(start, hidingPlaces, distances);
        sortChessPositions(hidingPlaces, hidingPlacesCount);

        printf("%d ", distances[0]);
        for (int j = 0; j < hidingPlacesCount; j++) {
            char chessPosition[3];
            indicesToChessNotation(hidingPlaces[j], chessPosition);
            printf("%s ", chessPosition);
        }
        printf("\n");
    }
    return 0;
}
