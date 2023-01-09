//~~~~~~~~~~~~~~~~~~~BubbleSortAlgorithmWithAdaptiveApproachAlso~~~~~~~~~~~~~~~~~~~


#include <stdio.h>

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void BubbleSortAlgo(int *arr, int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BubbleSortAlgoAdaptive(int *arr, int n)
{
    int IsSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {

        IsSorted = 1;
        printf("Working on the pass number : %d\n", i + 1);

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                IsSorted = 0;
            }
        }
        if (IsSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("The UnSorted array will be :\n");
    PrintArray(arr, 5);
    //  BubbleSortAlgo(arr, 5);
    printf("\nThe Sorted array will be :\n");
    BubbleSortAlgoAdaptive(arr, 5);
    PrintArray(arr, 5);
    return 0;
}