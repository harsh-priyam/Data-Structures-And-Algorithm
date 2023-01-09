#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};

int IsEmpty(struct Queue *ptr)
{
    if (ptr->f == ptr->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct Queue *ptr)
{
    if (ptr->r + 1 % ptr->size == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void EnQueue(struct Queue *ptr, int data)
{
    if (IsFull(ptr))
    {
        printf("CircularQueueOverFlow!!\n");
    }
    else
    {
        ptr->r = ptr->r + 1 % ptr->size;
        ptr->arr[ptr->r] = data;
        printf("Enqued Element is %d\n", data);
    }
}

int DeQueue(struct Queue *ptr)
{
    int a = -1;
    if (IsEmpty(ptr))
    {
        printf("CircularQueueUnderFlow!!\n");
    }
    else
    {
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Queue *q;
    q->f = q->r = 0; /* Coz it must start with zero as full con is when last is equal to first  and if we use -1 then it does not return to first as -1 is in another dimension*/
    q->size = 10;
    q->arr = (int *)malloc(q->size * sizeof(int));

    EnQueue(q, 45);
    EnQueue(q, 78);
    EnQueue(q, 54);
    EnQueue(q, 14);

    printf("The Data %d has been Dequeued\n", DeQueue(q));
    printf("The Data %d has been Dequeued\n", DeQueue(q));
    printf("The Data %d has been Dequeued\n", DeQueue(q));
    printf("The Data %d has been Dequeued\n", DeQueue(q));

    EnQueue(q, 87);

    if (IsFull(q))
    {
        printf("The Circular Queue is Full\n");
    }
    if (IsEmpty(q))
    {
        printf("The Circular Queue is Empty\n");
    }

    return 0;
}