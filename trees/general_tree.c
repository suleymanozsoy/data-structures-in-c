#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int data;
    struct TNode *childptr;
    struct TNode *siblingptr;
} TNode;

TNode *create_node(int value)
{
    TNode *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL)
        return NULL;

    newNode->data = value;
    newNode->childptr = NULL;
    newNode->siblingptr = NULL;
    return newNode;
}

void add_child(TNode *parent, int value)
{
    if (parent == NULL)
        return;

    TNode *valueNode = create_node(value);
    if (valueNode == NULL)
        return;

    if (parent->childptr == NULL) {
        parent->childptr = valueNode;
        return;
    }

    TNode *current = parent->childptr;
    while (current->siblingptr != NULL)
        current = current->siblingptr;

    current->siblingptr = valueNode;
}

void print_tree(const TNode *node, int depth)
{
    if (node == NULL)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("%d\n", node->data);
    print_tree(node->childptr, depth + 1);
    print_tree(node->siblingptr, depth);
}

void free_tree(TNode *node)
{
    if (node == NULL)
        return;

    free_tree(node->childptr);
    free_tree(node->siblingptr);
    free(node);
}

int main(void)
{
    TNode *root = create_node(10);
    if (root == NULL)
        return 1;

    add_child(root, 20);
    add_child(root, 30);
    add_child(root, 40);
    add_child(root->childptr, 50);
    add_child(root->childptr, 60);
    add_child(root->childptr->siblingptr->siblingptr, 70);

    print_tree(root, 0);
    free_tree(root);
    return 0;
}
