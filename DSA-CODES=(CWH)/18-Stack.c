//~~~~~~~~~~~~~~~~~~IMPLETATION OF STACK DATA TYPES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int IfEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IfFull(struct stack *ptr)
{
  if (ptr->top == ptr->size-1)
  {
      return 1;
  }
  else
  {
      return 0;
  }
  

}
int main()
{
    struct stack *s;
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

//~~~~~~~~~~~~~~~~~~~~~~~Manual Entering the datas in the array~~~~~~~~~~~~~~~~~~~~~~~~~~~
/*    s->arr[0]=4;
    s->top++;

    s->arr[1]=5;
    s->top++;

    s->arr[2]=10;
    s->top++;

    s->arr[3]=15;
    s->top++;

    s->arr[4]=45;
    //s->top++;
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~    

 // ~~~~~~~~~~~~~~~Stack is Empty or Not Empty~~~~~~~~~~~~~~~~~~~~
   if (IfEmpty(s))
    {
        printf("The Stack is Empty!\n");
    }
    else
    {
        printf("The Stack is Not Empty!\n");
    }
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //~~~~~~~~~~~~~~~~~~~Stack is Full or Not Full ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  if (IfFull(s))
  {
      printf("The Stack is Completely Full!");
  }
      else
      {
          printf("The Stack is Not Completely Full!");
      }
      
   //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    return 0;
}