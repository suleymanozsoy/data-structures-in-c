
#include <stdio.h>

#define SIZE 100

typedef struct
{
    int content[SIZE];
    int top;
} Stack;

typedef struct
{
    Stack data;
    Stack mins;
} MinStack;

int stack_is_empty(const Stack *s)
{
    return s->top == -1;
}

int push(Stack *s, int value)
{

    if (s->top >= SIZE - 1)
        return 0;

    s->content[s->top] = value;

    s->top++;

    return 1;
}

int pop(Stack *s, int *value)
{

    if (stack_is_empty(s))
        return 0;

    *value = s->content[s->top];

    s->top--;

    return 1;
}

int stack_top(const Stack *s, int *value)
{

    if (stack_is_empty(s))
        return 0;

    *value = s->content[s->top];

    return 1;
}

int min_stack_push(MinStack *ms, int value)
{

    if (ms->data.top >= SIZE - 1 || ms->mins.top >= SIZE - 1)
        return 0;

    int newMin = value;
    int previousMin;

    if (!stack_is_empty(&ms->mins))
    {

        stack_top(&ms->mins, &previousMin);

        if (previousMin < newMin)
            newMin = previousMin;
    }

    push(&ms->data, value);

    push(&ms->mins, newMin);

    return 1;
}

int min_stack_pop(MinStack *ms, int *value)
{

    if (stack_is_empty(&ms->data) || stack_is_empty(&ms->mins))
        return 0;

    int temp;

    pop(&ms->mins, &temp);

    return pop(&ms->data, value);
}

int find_min(const MinStack *ms, int *value)
{

    return stack_top(&ms->mins, value);
}

int main(void)
{

    MinStack ms = {.data.top = -1, .mins.top = -1};

    int values[] = {8, 3, 5, 2, 4};

    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        if (!min_stack_push(&ms, values[i]))
        {
            printf("Stack is full!\n");
            return 1;
        }
    }

    int value;

    if (find_min(&ms, &value))
        printf("Minimum: %d\n", value);

    if (min_stack_pop(&ms, &value))
        printf("Popped: %d\n", value);

    if (find_min(&ms, &value))
        printf("Minimum: %d\n", value);

    if (min_stack_pop(&ms, &value))
        printf("Popped: %d\n", value);

    if (find_min(&ms, &value))
        printf("Minimum: %d\n", value);

    return 0;
}
