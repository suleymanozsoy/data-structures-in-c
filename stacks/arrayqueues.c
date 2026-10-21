#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct
{

    int front;
    int rear;
    int content[SIZE];
} Queue;

int enqueue(Queue *q, int value)
{

    if (q->rear >= SIZE - 1)
    {
        printf("Queue is full!\n");
        return 0;
    }

    q->rear++;
    q->content[q->rear] = value;
    return 1;
}

int dequeue(Queue *q, int *value)
{

    if (q->rear < q->front)
    {
        printf("Queue is empty!\n");
        return 0;
    }

    *value = q->content[0];

    for (int i = 1; i <= q->rear; i++)
    {

        q->content[i - 1] = q->content[i];
    }

    q->rear--;

    return 1;
}

int main()
{

    Queue q;

    q.front = 0;
    q.rear = -1;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    int removedValue;

    if (dequeue(&q, &removedValue))
    {
        printf("Removed: %d\n", removedValue);
    }

    printf("Front: %d\n", q.front);
    printf("Rear: %d\n", q.rear);

    if (q.rear >= q.front)
    {
        printf("Last Item: %d\n", q.content[q.rear]);
    }

    return 0;
}