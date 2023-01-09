//~~~~~~~~~~~~~~~~Insertion of a element at first via using LinkedList~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void Linked_List(struct Node* ptr)
{
    while (ptr!=NULL)
    {
        printf("The Elements are : %d\n",ptr->data);
        ptr = ptr->next;
    }
    
}

struct Node *Insert_At_First(struct Node *first , int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
   ptr->data=data;
   ptr->next=first;
   return ptr;

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

       first->data=56;
       first->next=second;

       second->data=89;
       second->next=third;

       third->data=14;
       third->next=fourth;

       fourth->data=25;
       fourth->next=NULL;

       Linked_List(first);
        first =  Insert_At_First(first,23);
        printf("\n");
        Linked_List(first);
    return 0;
}