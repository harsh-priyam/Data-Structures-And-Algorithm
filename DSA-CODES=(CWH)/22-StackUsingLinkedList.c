//~~~~~~~~~~~~~~~~~Impletations of Stack Using Linked-List~~~~~~~~~~~~~~~~~~~~~~~~~~~~

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
        printf("Value = %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int IsEmpty(struct Node *top)
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

int IsFull(struct Node *top)
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
    if (IsFull(top))
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

int PopFunction(struct Node *tp)
{
    if (IsEmpty(tp))
    {
        printf("StackUnderFlow\n");
    }

    else
    {
        struct Node *n = tp;

        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{

    top = PushFunction(top, 475);
    top = PushFunction(top, 465);
    top = PushFunction(top, 455);
    top = PushFunction(top, 145);

    Linked_List(top);

    printf("The Value of %d has been popped out ::\n", PopFunction(top));
    printf("\n");
    Linked_List(top);
    return 0;
}