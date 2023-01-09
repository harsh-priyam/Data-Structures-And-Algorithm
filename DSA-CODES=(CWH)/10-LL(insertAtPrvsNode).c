//~~~~~~~~~~~~~~~~~INSERTION OF VALUE BEFORE ANY NODE IN LINKED_LIST~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include<stdlib.h>


struct Node
{
   int data;
   struct Node*next;
};

void Linked_List(struct Node*ptr)
{
  while (ptr!=NULL)
  {
      printf("The Data will be %d\n",ptr->data);
      ptr = ptr->next;
  }
}

struct Node * InsertFunction(struct Node* first , struct Node* prvs_Node , int data)
{
   struct Node*ptr = (struct Node*)malloc(sizeof (struct Node));
     ptr->data=data;

    ptr->next = prvs_Node->next;
    prvs_Node->next = ptr;
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
    InsertFunction(first,second,625);
    printf("\n");
    Linked_List(first);  
    return 0;
}