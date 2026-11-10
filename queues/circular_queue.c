#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

typedef struct
{

    int content[SIZE];
    int front;
    int rear;
    int count;

}   CircularQueue;

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

int main()
{

    CircularQueue q = {.front = 0, .rear = -1, .count = 0};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    int value;

    dequeue(&q, &value);
    
    printf("Dequeued value: %d\n", value);

    dequeue(&q, &value);
    
    printf("Dequeued value: %d\n", value);

    enqueue(&q, 60);
    enqueue(&q, 70);

    printf("\nCircular Queue:\n");

    for (int i = 0; i < q.count; i++)
    {
        int index = (q.front + i) % SIZE;

        printf("%d. number: %d\n", i + 1, q.content[index]);
    }

    return 0;
}
