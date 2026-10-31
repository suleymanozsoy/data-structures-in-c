#include <stdio.h>

#define SIZE 5

typedef struct
{
    int top;
    int content[SIZE];
} Stack;

typedef struct
{
    Stack input;
    Stack output;
} QueueTwoStacks;

int stack_push(Stack *s, int value)
{

    if (s->top >= SIZE - 1)
        return 0;

    s->content[++s->top] = value;
    return 1;
}

int stack_pop(Stack *s, int *value)
{

    if (s->top == -1)
        return 0;

    *value = s->content[s->top--];
    return 1;
}

int stack_is_empty(const Stack *s)
{
    return s->top == -1;
}

int stack_size(const Stack *s)
{
    return s->top + 1;
}

int queue_enqueue(QueueTwoStacks *q, int value)
{

    int total = stack_size(&q->input) + stack_size(&q->output);

    if (total >= SIZE)
        return 0;

    return stack_push(&q->input, value);
}

int queue_dequeue(QueueTwoStacks *q, int *value)
{

    if (stack_is_empty(&q->output))
    {

        while (!stack_is_empty(&q->input))
        {

            int temp;

            stack_pop(&q->input, &temp);
            stack_push(&q->output, temp);
        }
    }

    if (stack_is_empty(&q->output))
        return 0;

    return stack_pop(&q->output, value);
}

int main(void)
{

    QueueTwoStacks q = {
        .input.top = -1,
        .output.top = -1};

    int value;

    queue_enqueue(&q, 10);
    queue_enqueue(&q, 20);
    queue_enqueue(&q, 30);

    if (queue_dequeue(&q, &value))
        printf("Dequeued: %d\n", value);

    queue_enqueue(&q, 40);

    if (queue_dequeue(&q, &value))
        printf("Dequeued: %d\n", value);

    if (queue_dequeue(&q, &value))
        printf("Dequeued: %d\n", value);

    if (queue_dequeue(&q, &value))
        printf("Dequeued: %d\n", value);

    return 0;
}
