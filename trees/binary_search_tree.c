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
    newNode->left = NULL;
    newNode->right = NULL;

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

BTNode *find(BTNode *root, int key)
{

    if (root == NULL)
        return NULL;

    if (root->data == key)
        return root;

    if (key < root->data)
        return find(root->left, key);

    return find(root->right, key);
}

BTNode *findMin(BTNode *p)
{
    if (p == NULL)
        return NULL;

    while (p->left != NULL)
        p = p->left;

    return p;
}

BTNode *findMax(BTNode *p)
{

    if (p == NULL)
        return NULL;

    if (p->right == NULL)
        return p;

    return findMax(p->right);
}

BTNode *insert(BTNode *p, int key)
{
    if (p == NULL)
        return create_node(key);

    if (key < p->data)
        p->left = insert(p->left, key);

    else if (key > p->data)
        p->right = insert(p->right, key);

    return p;
}

BTNode *remove_node(BTNode *p, int key)
{
    if (p == NULL)
        return NULL;

    if (key < p->data)
    {
        p->left = remove_node(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = remove_node(p->right, key);
    }
    else
    {

        if (p->left != NULL && p->right != NULL)
        {

            BTNode *successor = findMin(p->right);

            p->data = successor->data;

            p->right = remove_node(p->right, successor->data);
        }
        else
        {
            BTNode *temp = p;

            if (p->left == NULL)
                p = p->right;
            else
                p = p->left;

            free(temp);
        }
    }

    return p;
}

int main()
{

    BTNode *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);

    root = remove_node(root, 20);
    root = remove_node(root, 50);
    root = remove_node(root, 70);

    printf("Root: %d\n", root->data);

    free_tree(root);
    return 0;
}