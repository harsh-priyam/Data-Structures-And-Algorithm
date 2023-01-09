//~~~~~~~~~~~~~~~~~INSERTION OF VALUE AT ANY POSITION IN LINKED_LIST~~~~~~~~~~~~~~~~~~~~

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void Linked_List(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("The Elements is : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * InsertionFunc(struct Node*first,int data,int index)
{
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    int i = 0;
    struct Node*p = first;

    while (i != index-1)  
    {
        p = p->next;
        i++;
    }
      ptr->next = p->next;
      p->next = ptr;
      ptr->data=data;
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

    Linked_List(first);
    InsertionFunc(first,23,3);
    printf("\n");
    Linked_List(first);
    return 0;
}