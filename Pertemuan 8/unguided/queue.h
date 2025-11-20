#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef struct {
    int info[MAX_QUEUE];
    int head;
    int tail;
} Queue;

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
