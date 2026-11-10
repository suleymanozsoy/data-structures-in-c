
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct
{

    int content[SIZE];
    int top;

} Stack;

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

int push(Stack *sPtr, int value)
{

    if (sPtr->top >= SIZE - 1)
    {
        printf("Stack is full!\n");
        return 1;
    }

    sPtr->top++;
    sPtr->content[sPtr->top] = value;

    return 0;
}

int pop(Stack *sPtr, int *value)
{

    if (sPtr->top >= 0)
    {

        *value = sPtr->content[sPtr->top];

        sPtr->top--;

        return 0;
    }

    return 1;
}

int remove_minimum(Stack *s)
{

    if (s->top == -1)
        return 1;

    CircularQueue q = {.count = 0, .front = 0, .rear = -1};

    int minValue;
    pop(s, &minValue);
    enqueue(&q, minValue);

    while (s->top != -1)
    {

        int value;

        pop(s, &value);

        if (value < minValue)
            minValue = value;

        enqueue(&q, value);
    }

    while (q.count > 0)
    {

        int value;

        dequeue(&q, &value);

        push(s, value);
    }

    while (s->top >= 0)
    {

        int value;

        pop(s, &value);

        if (value != minValue)
            enqueue(&q, value);
    }

    while (q.count > 0)
    {

        int value;

        dequeue(&q, &value);

        push(s, value);
    }

    return minValue;
}

int main()
{

    Stack s = {.top = -1};

    push(&s, 4);
    push(&s, 2);
    push(&s, 7);
    push(&s, 2);
    push(&s, 5);

    printf("Before function: \n");

    for (int i = s.top; i >= 0; i--)
    {

        printf("%d\n", s.content[i]);
    }

    remove_minimum(&s);

    printf("After function: \n");

    for (int i = s.top; i >= 0; i--)
    {

        printf("%d\n", s.content[i]);
    }

    return 0;
}
