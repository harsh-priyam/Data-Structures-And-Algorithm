//Checking Wheteher The Given Tree is Binary Saearch tree


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

int BinarySearchTree(struct Node *root)
{
    static struct Node *prvs = NULL;

    if (root != NULL)
    {
        if (!BinarySearchTree(root->left))
        {
            return 0;
        }
        if (prvs != NULL && prvs->data >= root->data)
        {
            return 0;
        }
        prvs = root;
        return BinarySearchTree(root->right);
    }
    else
    {
        return 1;
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

    int flag = BinarySearchTree(n);

    if (flag == 1)
    {
        printf("Its A Binary Search Tree!\n");
    }
    else
    {
        printf("Not A Binary Search Tree!\n");
    }

    return 0;
}