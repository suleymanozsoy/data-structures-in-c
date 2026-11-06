#include <stdlib.h>
#include <stdio.h>

typedef struct TNode
{

    int data;
    struct TNode *siblingPtr;
    struct TNode *childPtr;

} TNode;

TNode *create_node(int value)
{

    TNode *newNode = malloc(sizeof(TNode));

    if (newNode == NULL)
        return NULL;

    newNode->data = value;
    newNode->childPtr = NULL;
    newNode->siblingPtr = NULL;

    return newNode;
}

void add_child(TNode *parent, int value)
{

    if (parent == NULL)
        return;

    TNode *valueNode = create_node(value);

    if (valueNode == NULL)
        return;

    if (parent->childPtr == NULL)
    {
        parent->childPtr = valueNode;
        return;
    }

    TNode *current = parent->childPtr;

    while (current->siblingPtr != NULL)
        current = current->siblingPtr;

    current->siblingPtr = valueNode;
}

void print_tree(TNode *node, int depth)
{

    if (node == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("%d\n", node->data);

    print_tree(node->childPtr, depth + 1);

    print_tree(node->siblingPtr, depth);
}

void free_tree(TNode *node)
{
    if (node == NULL)
        return;

    free_tree(node->childPtr);

    free_tree(node->siblingPtr);

    free(node);
}

int main()
{

    TNode *root = create_node(10);

    if (root == NULL)
        return 1;

    add_child(root, 20);
    add_child(root, 30);
    add_child(root, 40);

    add_child(root->childPtr, 50);
    add_child(root->childPtr, 60);
    add_child(root->childPtr->siblingPtr->siblingPtr, 70);

    print_tree(root, 0);

    free_tree(root);

    return 0;
}