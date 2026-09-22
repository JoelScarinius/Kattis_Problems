#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    Position position;
    int distance;
} QueueNode;

#endif // STRUCTS_H