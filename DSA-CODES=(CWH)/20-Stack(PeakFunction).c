//~~~~~~~~~~~~~~~~~~~~~The Impletation Of Peak in Stack~~~~~~~~~~~~~~~~~~~~~
// peak function is just to print the postion of datas entered inside the Stack



#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

void Push(struct stack *ptr, int value)
{
    ptr->top++;
    ptr->arr[ptr->top] = value;
}
int Pop(struct stack *ptr)
{
    int value;
    value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

int Peek_of_Stack(struct stack *ptr, int i)
{
    if (ptr->top - i + 1 < 0)
    {
        printf("Invalid Value!!\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top - i + 1];
    }
}

int main()
{   
    struct stack *st = (struct stack *)malloc(sizeof(struct stack));

    st->size = 50;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));

    
    Push(st, 62);
    Push(st, 39);
    Push(st, 48);
    Push(st, 45);
    for (int j = 1; j <= st->top+1; j++)
    {
        printf("At position %d the value is : %d\n",j,Peek_of_Stack(st,j));
    }
    
    return 0;
}