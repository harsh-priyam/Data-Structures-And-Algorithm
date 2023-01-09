//~~~~~~~~~~~~~~~~~LinkedRepresentationOfBinaryTree~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* NodeCreator(int data)
{
   struct Node* n = (struct Node*)malloc(sizeof(struct Node));

   n->data = data;
   n->left = NULL;
   n->right = NULL;
   return n;
}



int main()
{
    struct Node*n = NodeCreator(8);
    struct Node*p1 = NodeCreator(2);
    struct Node*p2 = NodeCreator(6);

    n->left = p1;
    n->right = p2;

    return 0;
}