#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void Linked_List(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The value of the data is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int IfEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IfFull(struct Node *top)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *PushFunction(struct Node *top, int x)
{
    if (IfFull(top))
    {
        printf("StackOverFlow!!\n");
    }

    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));

        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int PeekFunction(int pos)
{
    struct Node *ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
        return -1;
}

int main()
{

    top = PushFunction(top, 45);
    top = PushFunction(top, 49);
    top = PushFunction(top, 44);
    top = PushFunction(top, 41);

    Linked_List(top);
     
    for (int j = 1; j <= 4; j++)
    {
        printf("The Value at index %d is %d\n",j,PeekFunction(j));
    }
     


    return 0;
}