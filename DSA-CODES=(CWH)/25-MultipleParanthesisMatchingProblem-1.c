//~~~~~~~~~~~~~~~~~~~~~~~~~~~MultipleParanthesismatchingProblem~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
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
        printf("StackOverFlow\n");
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
int MatchFunction(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int ParenthesisFunc(char *ch)
{
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char pop_char;

    for (int i = 0; ch[i] != '\0'; i++)
    {
        if (ch[i] == '(' || ch[i] == '{' || ch[i] == '[')
        {
            PushFunction(sp, ch[i]);
        }
        else if (ch[i] == ')' || ch[i] == '}' || ch[i] == ']')
        {
            if (IsEmpty(sp))
            {
                return 0;
            }
            pop_char = PopFunction(sp);
            if (MatchFunction(ch[i], pop_char))
            {
                return 1;
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
    char *ch = "(3+{7+2)}";
    if (ParenthesisFunc(ch))
    {
        printf("Matched\n");
    }
    else
    {
        printf("Not Matched\n");
    }

    return 0;
}