//~~~~~~~~~~~~~~~~~~~~~~Paranthesis Matching Problem Using Stack Concept~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~Using Stack of Array~~~~~~~~~~~~~~~~~~~~~~~


#include <stdio.h>
#include <stdlib.h>

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

void PushFunction(struct stack *ptr, char value)
{
    if (IsFull(ptr))
    {
        printf("StackOverFlow");
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int PopFunction(struct stack *ptr)
{
    if (IsEmpty(ptr))
    {
        printf("StackUnderFlow\n");
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int ParathensisFunc(char *ch)
{
    struct stack *sp;

    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * (sizeof(char)));

    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] == '(')
        {
            PushFunction(sp, '(');
        }

        else if (ch[i] == ')')
        {
            if (IsEmpty(sp))
            {
                return 0;
            }
            else
            {
                PopFunction(sp);
            }
        }
    }
    if (IsEmpty(sp))
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

    char *ch = "(8*9)+(777+6)";

    if (ParathensisFunc(ch))
    {
        printf("Paranthesis Matched!!\n");
    }
    else
    {
        printf("Paranthesis Not Matched!!\n");
    }

    return 0;
}