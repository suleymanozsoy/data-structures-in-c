#include <stdio.h>



#define SIZE 5

typedef struct
{

    int arr[SIZE];
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

void compress_stack(Stack *s)
{

    if (s->top == -1)
        return;

    CircularQueue q = {.count = 0, .front = 0, .rear = -1};

    int previous;
    int count = 1;

    pop(s, &previous);

    while (s->top >= 0)
    {

        int value;

        pop(s, &value);

        if (value == previous)
        {
            count++;
        }
        else
        {

            enqueue(&q, previous);

            enqueue(&q, count);

            previous = value;
            count = 1;
        }
    }

    enqueue(&q, previous);

    enqueue(&q, count);

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

        enqueue(&q, value);
    }

    while (q.count > 0)
    {

        int value;

        dequeue(&q, &value);

        push(s, value);
    }
}

int main()
{

    Stack s = {.top = -1};

    push(&s, 4);
    push(&s, 4);
    push(&s, 4);

    printf("Before function\n");

    for (int i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.arr[i]);
    }
    printf("\n");
    compress_stack(&s);

    printf("After function\n");

    for (int i = s.top; i >= 0; i--)
    {
        printf("%d\n", s.arr[i]);
    }
}