#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prvs;
    struct Node *next;
};

void TraversalAtBothDirections(struct Node *ptr, struct Node *ptr1)
{
    printf("Travelling in the Forward way & the datas will be :::\n");

    while (ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    printf("\n");
    printf("Travelling in the Backward way & the datas will be :::\n");

    while (ptr1 != NULL)
    {
        printf("%d\t", ptr1->data);
        ptr1 = ptr1->prvs;
    }
};



int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 45;
    head->prvs = NULL;
    head->next = second;

    second->data = 69;
    second->prvs = head;
    second->next = third;

    third->data = 87;
    third->prvs = second;
    third->next = fourth;

    fourth->data = 99;
    fourth->prvs = third;
    fourth->next = NULL;

    TraversalAtBothDirections(head, fourth);

    return 0;
}