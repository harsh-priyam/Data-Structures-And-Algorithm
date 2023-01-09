// ~~~~~~~~~~~~~~~~~~Searching In A Binary Search tree using Reccursive Method~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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

int B_S_T_function(struct Node *root)
{
  struct Node *prvs = NULL;
  if (root != NULL)
  {
    if (!B_S_T_function(root->left))
    {
      return 0;
    }
    if (prvs != NULL && prvs->data >= root->data)
    {
      return 0;
    }
    prvs = root;
    return B_S_T_function(root->right);
  }
}

struct Node *SearchFunction(struct Node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  else if (key == root->data)
  {
    return root;
  }
  else if (key < root->data)
  {
    return SearchFunction(root->left, key);
  }
  else
  {
    return SearchFunction(root->right, key);
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

  struct Node *num = SearchFunction(n, 5);

  if (num != NULL)
  {
    printf("Found!! :: %d\n", num->data);
  }
  else
  {
    printf("Not Found\n");
  }

  return 0;
}