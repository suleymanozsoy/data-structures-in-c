#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode
{

    int data;
    struct StackNode *next;

} StackNode;

void push(StackNode **ptr, int value)
{

    StackNode *newNode = malloc(sizeof(StackNode));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = *ptr;
    *ptr = newNode;
}

void pop(StackNode **ptr)
{

    if (*ptr == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }

    StackNode *temp = *ptr;

    *ptr = (*ptr)->next;

    free(temp);
}

int main()
{

    StackNode *top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("Top: %d\n", top->data);

    pop(&top);

    printf("After pop: %d\n", top->data);

    return 0;
}