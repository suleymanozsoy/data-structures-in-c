#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct
{

    int content[SIZE];
    int rear;
    int front;

} Queue;

typedef struct
{

    int arr[SIZE];
    int top;

} Stack;

int push(Stack *sPtr, int value)
{

    if (sPtr->top >= SIZE - 1)
    {
        printf("Stack is full!\n");
        return 1;
    }

    sPtr->top++;
    sPtr->arr[sPtr->top] = value;

    return 0;
}

int pop(Stack *sPtr, int *value)
{

    if (sPtr->top >= 0)
    {

        *value = sPtr->arr[sPtr->top];

        sPtr->top--;

        return 0;
    }

    return 1;
}

int enqueue(Queue *q, int value)
{

    if (q->rear >= SIZE - 1)
    {
        printf("Queue is full!\n");
        return 1;
    }

    q->rear++;
    q->content[q->rear] = value;
    return 0;
}

int dequeue(Queue *q, int *value)
{

    if (q->rear < q->front)
    {
        printf("Queue is empty!\n");
        return 1;
    }

    *value = q->content[0];

    for (int i = 1; i <= q->rear; i++)
    {

        q->content[i - 1] = q->content[i];
    }

    q->rear--;

    return 0;
}

void interleave_queue(Stack *s, Queue *q)
{

    int half = (q->rear + 1) / 2;

    for (int i = 0; i < half; i++)
    {
        int value;

        dequeue(q, &value);
        push(s, value);
    }

    for (int i = s->top; i >= 0; i--)
    {

        int value;

        pop(s, &value);

        enqueue(q, value);
    }

    for (int i = half; i > 0; i--)
    {

        int value;

        dequeue(q, &value);

        enqueue(q, value);
    }

    for (int i = 0; i < half; i++)
    {

        int value;

        dequeue(q, &value);

        push(s, value);
    }

    for (int i = 0; i < half; i++)
    {

        int value;

        pop(s, &value);

        enqueue(q, value);

        dequeue(q, &value);

        enqueue(q, value);
    }
}

int main(void)
{

    Stack s = {.top = -1};

    Queue q;

    q.front = 0;
    q.rear = 5;

    q.content[0] = 1;
    q.content[1] = 2;
    q.content[2] = 3;
    q.content[3] = 4;
    q.content[4] = 5;
    q.content[5] = 6;

    for (int i = 0; i <= q.rear; i++)
        printf("%d ", q.content[i]);

    printf("\n");

    printf("After function: \n");

    interleave_queue(&s, &q);

    for (int i = 0; i <= q.rear; i++)
        printf("%d ", q.content[i]);
}
