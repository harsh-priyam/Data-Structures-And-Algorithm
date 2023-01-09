#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", A[i]);
    }
}

void Merge(int *A, int low, int high, int mid)
{
    int k=low;
    int i = low;
    int j = mid + 1;
    int B[100];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            k++;
            i++;
        }
        else
        {
            B[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int *A, int low, int high)
{
    int mid;
   

    if (low < high)
    {
         mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, high, mid);
    }
}

int main()
{
    int A[] = {7,9,18,19,22,1,6,10,11};
    int n = 9;
    printArray(A, n);
    printf("\n");
    MergeSort(A, 0, 8);
    printf("\n");
    printArray(A, n);
    return 0;
}