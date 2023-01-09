#include <stdio.h>

void Display(int arr[], int n)
{
    printf("The Modified Array will be :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int InsertFunc(int arr[], int size, int index, int element, int capc)
{
    int i;

    if (size >= capc)
    {
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    int arr[100] = {1, 2, 3, 4, 5};
    
    int size = 5, index = 3, element = 89, capc = 100;
    InsertFunc(arr, size, index, element, capc);
    size += 1;
    Display(arr, size);

    return 0;
}