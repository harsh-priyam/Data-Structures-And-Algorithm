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

struct Node *Delete_Last(struct Node *first)
{
    struct Node *ptr1 = first;
    struct Node *ptr2 = first->next;

    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr1->next = ptr2->next;
    free(ptr2);
    return first;
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

    first->data = 1;
    first->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    LinkedList(first);
    first = Delete_Last(first);
    printf("\n");
    LinkedList(first);
    return 0;
}