//~~~~~~~~~~~~~~~~~~~~BinarY Searching of Desired Element~~~~~~~~~~~~~~~~~~~~~~`

#include <stdio.h>
int BinaryFunc(int arr[], int size, int element)
{

    int min = 0;
    int max = size - 1;

    while (min <= max)
    {
        int mid = (max + min) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
        
    }
    return -1;
}

int main()
{
    int arr[50] = {1, 2, 3, 4, 5};
    int size = 5;
    int element = 13;
int data =  BinaryFunc(arr, size, element);
   printf("The Number %d is present at the %d position\n",element,data);
    return 0;
}