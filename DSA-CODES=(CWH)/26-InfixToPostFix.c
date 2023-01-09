#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
  int top;
  int size;
  char *arr;
};

int IsEmpty(struct stack *ptr)
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
int IsFull(struct stack *ptr)
{
  if (ptr->top == ptr->size - 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void Push(struct stack *ptr, char data)
{
  if (IsFull(ptr))
  {
    printf("StackOverFlow!!\n");
  }
  else
  {
    ptr->top++;
    ptr->arr[ptr->top] = data;
  }
}

int Pop(struct stack *ptr)
{
  if (IsEmpty(ptr))
  {
    printf("StackUnderFlow\n");
  }
  else
  {
    char data = ptr->arr[ptr->top];
    ptr->top--;
    return data;
  }
}

int PrsdncFunc(char ch)
{
  if (ch == '/' || ch == '*')
  {
    return 3;
  }
  else if (ch == '+' || ch == '-')
  {
    return 2;
  }
  else
  {
    return 0;
  }
}

int OperatorFunc(char ch)
{
  if (ch == '/' || ch == '*' || ch == '+' || ch == '-')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int stackTop(struct stack *ptr)
{
  return ptr->arr[ptr->top];
}

char *IntoPo(char *infix)
{
  struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
  sp->size = 100;
  sp->top = -1;
  sp->arr = (char *)malloc(sp->size * sizeof(char));
  int i = 0;
  int j = 0;
  char *postfix = (char *)malloc((strlen((infix) + 1)) * sizeof(char));

  while (infix[i] != '\0')
  {
    if (!OperatorFunc(infix[i]))
    {
      postfix[j] = infix[i];
      j++;
      i++;
    }
    else
    {
      if (PrsdncFunc(infix[i]) > PrsdncFunc(stackTop(sp)))
      {
        Push(sp, infix[i]);
        i++;
      }
      else
      {
        postfix[j] = Pop(sp);
      }
    }
  }
  while (!IsEmpty(sp))
  {
    postfix[j] = Pop(sp);
    j++;
  }
  postfix[j] = '\0';
  return postfix;
}

int main()
{
  char *infix = "a-b";
  printf("The Postfix of infix is %s\n", IntoPo(infix));

  return 0;
}