#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct QueueNode {
    int floor;
    int cost;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int floor, int cost) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->floor = floor;
    newNode->cost = cost;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

QueueNode* dequeue(Queue* q) {
    if (isEmpty(q)) {
        return NULL; // Queue is empty
    }

    QueueNode* curr = q->front;
    q->front = q->front->next;

    return curr;
}

int bfs(int f, int s, int g, int u, int d) {
    if (s == g) {
        return 0;
    }

    bool* visited = (bool*)malloc(sizeof(bool) * f);
    for (int i = 0; i < f; i++) {
        visited[i] = false;
    }
    visited[s - 1] = true;

    Queue queue;
    initQueue(&queue);
    enqueue(&queue, s, 0);

    while (!isEmpty(&queue)) {
        QueueNode* curr = dequeue(&queue);
        if (curr == NULL) {
            break;
        }
        int up = curr->floor + u;
        int down = curr->floor - d;

        if (up == g || down == g) {
            free(visited);
            return curr->cost + 1;
        }

        if (up <= f && !visited[up - 1]) {
            enqueue(&queue, up, curr->cost + 1);
            visited[up - 1] = true;
        }

        if (down > 0 && !visited[down - 1]) {
            enqueue(&queue, down, curr->cost + 1);
            visited[down - 1] = true;
        }
        free(curr);
    }
    free(visited);
    return -1; // No valid path to reach the goal floor
}

int main() {
    int f, s, g, u, d;
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int result = bfs(f, s, g, u, d);
    if (result == -1) {
        printf("use the stairs\n");
    } else {
        printf("%d\n", result);
    }

    return 0;
}

