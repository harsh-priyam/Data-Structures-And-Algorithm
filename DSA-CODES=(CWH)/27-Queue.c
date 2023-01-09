//~~~~~~~~~~~~~~~~~~~QueueDataStructuresAnditsApplications~~~~~~~~~~~~~~~~~~~~~~~~~
#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int r;
    int f;
    int *arr;
};

int IsFull(struct Queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEmpty(struct Queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int EnqueueFunc(struct Queue *q, int data)
{
    if (IsFull(q))
    {
        printf("QueueOverFlow!!\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = data;
         printf("Enqued Element is %d\n",data);
    }
}





int DequeueFunc(struct Queue *q)
{
    int a = -1;
    if (IsEmpty(q))
    {
        printf("QueueUnderFlow!!\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    struct Queue q;
    q.f = q.r = -1;
    q.size = 5;
    q.arr = (int *)malloc(q.size * sizeof(int));

    EnqueueFunc(&q, 12);
    EnqueueFunc(&q, 624);
    EnqueueFunc(&q, 524);
    EnqueueFunc(&q, 224);
    EnqueueFunc(&q, 124);

    

    printf("The Value of %d has been excluded Out!!\n", DequeueFunc(&q));
    printf("The Value of %d has been excluded Out!!\n", DequeueFunc(&q));
    printf("The Value of %d has been excluded Out!!\n", DequeueFunc(&q));
    printf("The Value of %d has been excluded Out!!\n", DequeueFunc(&q));
    printf("The Value of %d has been excluded Out!!\n", DequeueFunc(&q));

    

    if (IsEmpty(&q))
    {
        printf("The Queue Is Empty\n");
    }
    if (IsFull(&q))
    {
        printf("The Queue Is Full\n");
    }

    return 0;
}


// Also Using Pointers and the arrow operator~~~~~~~~~~~~~~~~
/* 

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
    if (ptr->r == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void InQueueFunc(struct Queue *ptr, int data)
{
    if (IsFull(ptr))
    {
        printf("QueueOveraFlow!!\n");
    }
    else
    {
        ptr->r++;
        ptr->arr[ptr->r] = data;
    }
}

int DeQueueFunc(struct Queue *ptr)
{
    int a = -1;
    if (IsEmpty(ptr))
    {
        printf("QueueUnderFlow!!\n");
    }
    else
    {
        ptr->f++;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main()
{
    struct Queue *q ;
    q->f = q->r = -1;
      q->size = 3;
    q->arr = (int *)malloc(q->size*sizeof(int));
  

    InQueueFunc(q, 25555);
    InQueueFunc(q, 51);

    if (IsFull(q))
    {
        printf("Queue is Full\n");
    }
    if (IsEmpty(q))
    {
        printf("Queue is Empty\n");
    }

    printf("The Data %d has been out\n",DeQueueFunc(q));

    return 0;
} */