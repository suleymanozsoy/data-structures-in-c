#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct
{

    int content[SIZE];
    int front;
    int rear;
    int count;

} CircularQueue;

int enqueue(CircularQueue *q, int value)
{

    if (q->count >= SIZE)
    {
        printf("Queue is full!\n");
        return 1;
    }

    q->rear = (q->rear + 1) % SIZE;

    q->content[q->rear] = value;

    q->count++;

    return 0;
}

int dequeue(CircularQueue *q, int *value)
{

    if (q->count <= 0)
    {
        printf("Queue is empty!\n");
        return 1;
    }

    *value = q->content[q->front];

    q->front = (q->front + 1) % SIZE;

    q->count--;

    return 0;
}

void queue_reversal(CircularQueue *q)
{

    if (q->count == 0)
        return;

    int value;

    dequeue(q, &value);

    queue_reversal(q);

    enqueue(q, value);
}