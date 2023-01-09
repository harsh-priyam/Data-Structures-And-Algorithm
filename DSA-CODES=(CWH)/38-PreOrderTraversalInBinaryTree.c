#include <stdio.h>
#include <stdlib.h>

 // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  

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

void PreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
    struct Node *n = NodeCreator(4);
    struct Node *p = NodeCreator(1);
    struct Node *q = NodeCreator(6);
    struct Node *p1 = NodeCreator(5);
    struct Node *p2 = NodeCreator(2);

    n->left = p;
    n->right = q;

    p->left = p1;
    p->right = p2;

    PreOrder(n);

    return 0;
}