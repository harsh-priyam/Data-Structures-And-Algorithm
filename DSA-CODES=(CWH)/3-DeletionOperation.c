#include <stdio.h>
void Display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void DeletionFunc(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[50] = {1, 2, 3, 4, 5};
    int size = 5;
    int index = 2;

    DeletionFunc(arr, size, index);
    size -= 1;
    Display(arr, size);

    return 0;
}