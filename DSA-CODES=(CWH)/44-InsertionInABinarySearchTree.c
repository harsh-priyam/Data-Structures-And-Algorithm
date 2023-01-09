// ~~~~~~~~~~~~~~~Insertion In A BinarySearchTree~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *NodeCreator(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int B_S_T(struct Node *root)
{
    struct Node *prvs = NULL;

    if (root != NULL)
    {
        if (!B_S_T(root->left))
        {
            return 0;
        }
        if (prvs != NULL && prvs->data >= root->data)
        {
            return 0;
        }
        prvs = root;
        return B_S_T(root->right);
    }
    else
    {
        return 1;
    }
}

struct Node *SearchFunction(struct Node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

void InsertFunction(struct Node *root, int key)
{
    struct Node *prvs = NULL;
    while (root != NULL)
    {
        prvs = root;
        if (key == root->data)
        {
            printf("The Data of %d is being already there!\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct Node *new = NodeCreator(key);
    if (key < prvs->data)
    {
        prvs->left = new;
    }
    else
    {
        prvs->right = new;
    }
}

int main()
{
    struct Node *n = NodeCreator(5);
    struct Node *p = NodeCreator(3);
    struct Node *q = NodeCreator(6);
    struct Node *p1 = NodeCreator(1);
    struct Node *p2 = NodeCreator(4);

    n->left = p;
    n->right = q;

    p->left = p1;
    p->right = p2;

    q->left = NULL;
    q->right = NULL;

    InsertFunction(n, 16);
    printf("%d\n", n->right->right->data);

    return 0;
}