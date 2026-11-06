#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode {
    int data;
    struct BTNode *right;
    struct BTNode *left;
} BTNode;

BTNode *create_node(int value)
{
    BTNode *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL)
        return NULL;

    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void free_tree(BTNode *root)
{
    if (root == NULL)
        return;

    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(void)
{
    BTNode *root = create_node(10);
    if (root == NULL)
        return 1;

    root->left = create_node(20);
    root->right = create_node(30);
    if (root->left == NULL || root->right == NULL) {
        free_tree(root);
        return 1;
    }

    root->left->left = create_node(40);
    root->left->right = create_node(50);
    root->right->left = create_node(60);
    if (root->left->left == NULL || root->left->right == NULL ||
        root->right->left == NULL) {
        free_tree(root);
        return 1;
    }

    printf("Binary Tree created successfully.\n");
    free_tree(root);
    return 0;
}
