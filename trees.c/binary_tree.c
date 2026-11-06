#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode
{

    int data;
    struct BTNode *right;
    struct BTNode *left;

} BTNode;

BTNode *create_node(int value)
{

    BTNode *newNode = malloc(sizeof(BTNode));

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

void inorder(BTNode *node)
{

    if (node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(BTNode *node)
{

    if (node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(BTNode *node)
{

    if (node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main(void)
{
    BTNode *root = create_node(10);

    if (root == NULL)
        return 1;

    root->left = create_node(20);
    root->right = create_node(30);
    root->left->left = create_node(40);
    root->left->right = create_node(50);
    root->right->left = create_node(60);

    printf("Inorder: ");
    inorder(root);

    printf("\nPreorder: ");
    preorder(root);

    printf("\nPostorder: ");
    postorder(root);

    printf("\n");

    free_tree(root);

    return 0;
}