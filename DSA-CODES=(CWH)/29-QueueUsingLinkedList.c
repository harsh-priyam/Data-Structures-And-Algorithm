//~~~~~~~~~~~~~~~~~~~~~~~~~~~~Queue Using Linked List~~~~~~~~~~~~~~~~~~~~~~


#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *f = NULL;
struct Node *r = NULL;

void LinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The Value will be %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void EnQueue(int value)
{

    struct Node *n = (struct Node *)malloc(sizeof(struct Node));

    if (n == NULL)
    {
        printf("QueueOverFlow!!\n");
    }
    else
    {
        n->data = value;
        n->next = NULL;

        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int Dequeue()
{
    struct Node *ptr = f;
    int value = -1;
    if (f == NULL)
    {
        printf("QueueUnderFlow!!\n");
    }
    else
    {
        f = f->next;
        value = ptr->data;
        free(ptr);
    }
    return value;
}

int main()
{
  
    printf("Dequeuing Element %d from the list\n", Dequeue());
    EnQueue(25);
    EnQueue(26);
    EnQueue(49);
    EnQueue(71);
    LinkedList(f);
    printf("Dequeuing Element %d from the list\n", Dequeue());
    return 0;
}
