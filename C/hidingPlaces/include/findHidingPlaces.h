#ifndef FINDHIDINGPLACES_H
#define FINDHIDINGPLACES_H

#include "structs.h"

Position createPosition(int row, int col);

Position chessNotationToIndices(const char *position);

void indicesToChessNotation(Position indices, char *position);

int findHidingPlaces(Position start, Position *hidingPlaces, int *distances);


void sortChessPositions(Position *hidingPlaces, int hidingPlacesCount);

void swap(Position *hidingPlaces, int i, int min);

#endif // FINDHIDINGPLACES_H