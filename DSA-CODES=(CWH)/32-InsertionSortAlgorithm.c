//~~~~~~~~~~~~~~~~~~~~~~~~~~~Insertion Sort~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>

void MyArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void insertionSort(int *arr, int n)
{
    int index, j;
    for (int i = 1; i <= n - 1; i++)
    {
        index = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > index)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = index;
    }
}

int main()
{
    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = 6;

    MyArray(arr, 6);
    printf("\n");
    insertionSort(arr, 6);
    printf("\n");
    MyArray(arr, 6);

    return 0;
}