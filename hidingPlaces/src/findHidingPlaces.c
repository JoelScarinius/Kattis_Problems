#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

Position createPosition(int row, int col) {
    Position position;
    position.row = row;
    position.col = col;
    return position;
}

Position chessNotationToIndices(const char* position) {
    Position indices;
    indices.col = position[0] - 'a';
    indices.row = position[1] - '1';
    return indices;
}

void indicesToChessNotation(Position indices, char* position) {
    position[0] = indices.col + 'a';
    position[1] = indices.row + '1';
    position[2] = '\0';
}

int findHidingPlaces(Position start, Position* hidingPlaces, int* distances) {
    int dr[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
    int dc[] = { 1, -1, 1, -1, 2, -2, 2, -2 };
    QueueNode queue[64];
    bool visited[8][8];
    memset(visited, false, sizeof(visited));
    int front = 0;
    int rear = 0;
    int maxDistance = 0;
    int hidingPlacesCount = 0;

    queue[rear].position = start;
    queue[rear].distance = 0;
    rear++;

    visited[start.row][start.col] = true;

    while (front < rear) {
        QueueNode node = queue[front++];
        Position position = node.position;
        int distance = node.distance;

        if (distance > maxDistance) {
            maxDistance = distance;
            hidingPlacesCount = 0;
            hidingPlaces[hidingPlacesCount++] = position;
        } else if (distance == maxDistance) {
            hidingPlaces[hidingPlacesCount++] = position;
        }

        for (int i = 0; i < 8; i++) {
            int newRow = position.row + dr[i];
            int newCol = position.col + dc[i];

            if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8 && !visited[newRow][newCol]) {
                visited[newRow][newCol] = true;
                queue[rear].position.row = newRow;
                queue[rear].position.col = newCol;
                queue[rear].distance = distance + 1;
                rear++;
            }
        }
    }

    memcpy(distances, &maxDistance, sizeof(maxDistance));
    return hidingPlacesCount;
}

void sortChessPositions(Position *hidingPlaces, int hidingPlacesCount)
{
    
    

    for (int i = 0; i <= hidingPlacesCount - 2; i++)
    {
        int max = i, min = i;
        for (int j = i + 1; j <= hidingPlacesCount - 1; j++) 
        {
            if (hidingPlaces[j].row > hidingPlaces[max].row)
            {
                max = j;
            }
            else if (hidingPlaces[j].row == hidingPlaces[max].row)
            {
                if (hidingPlaces[j].col < hidingPlaces[max].col)
                {
                    max = j;
                }
            }
            }
        swap(hidingPlaces, i, max); 
    }
    
}

void swap(Position *hidingPlaces, int i, int max)
{
    Position temp = hidingPlaces[i];
    hidingPlaces[i] = hidingPlaces[max];
    hidingPlaces[max] = temp;
}