#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

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

int pop(Stack *sPtr)
{

    if (sPtr->top >= 0)
    {

        sPtr->top--;

        return 0;
    }

    return 1;
}

void print(Stack *sPtr)
{

    for (int i = 0; i <= sPtr->top; i++)
    {

        printf("%d. number: %d\n", i + 1, sPtr->arr[i]);
    }
}

int main()
{

    Stack s;
    s.top = (-1);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    print(&s);

    pop(&s);
    printf("After pop\n");
    print(&s);

    return 0;
}