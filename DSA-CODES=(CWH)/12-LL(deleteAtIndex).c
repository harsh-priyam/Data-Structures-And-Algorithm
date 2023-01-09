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

struct Node *DeleteAtindex(struct Node *first, int index)
{

    struct Node *ptr1 = first;
    struct Node *ptr2 = first->next;

    for (int i = 0; i < index - 1; i++)
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

    // Allocate memory for nodes in the linked list in Heap
    first = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    first->data = 1;
    first->next = second;

    // Link second and third nodes
    second->data = 2;
    second->next = third;

    // Link third and fourth nodes
    third->data = 3;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 4;
    fourth->next = NULL;

    LinkedList(first);
    first = DeleteAtindex(first, 2);
    printf("\n");
    LinkedList(first);
    return 0;
}