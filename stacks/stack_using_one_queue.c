#include <stdio.h>

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

    if (q->rear < 0)
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

int queue_size(const Queue *q)
{
    return q->rear + 1;
}

int stack_push(Queue *q, int value)
{

    int oldSize = queue_size(q);

    if (!enqueue(q, value))
        return 0;

    for (int i = 0; i < oldSize; i++)
    {

        int temp;

        if (!dequeue(q, &temp))
            return 0;

        if (!enqueue(q, temp))
            return 0;
    }

    return 1;
}

int stack_pop(Queue *q, int *value)
{
    return dequeue(q, value);
}

int main(void)
{

    Queue q1;

    q1.front=0;
    q1.rear=-1;
    

    if (!stack_push(&q1, 10) ||
        !stack_push(&q1, 20) ||
        !stack_push(&q1, 30))
    {
        return 1;
    }

    int value;

    printf("Pop order: \n");

    while (queue_size(&q1) > 0)
    {

        if (!stack_pop(&q1, &value))
            return 1;

        printf("%d ", value);
    }

    printf("\n");

    return 0;
}
