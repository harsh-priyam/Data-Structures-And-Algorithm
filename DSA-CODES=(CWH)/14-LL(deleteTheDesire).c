#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("The Elements will be : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *Delete_Desire(struct Node *first, int value)
{
    struct Node *ptr1 = first;
    struct Node *ptr2 = first->next;

    while (ptr2->data != value)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr2->data == value)
    {
        ptr1->next = ptr2->next;
        free(ptr2);
        return first;
    }
}

int main()
{
    struct Node *first;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    first->data = 114;
    first->next = second;

    second->data = 256;
    second->next = third;

    third->data = 633;
    third->next = fourth;

    fourth->data = 420;
    fourth->next = NULL;

    LinkedList(first);
   first = Delete_Desire(first,420);
   printf("\n");
   LinkedList(first);
    return 0;
}