//~~~~~~~~~~~~~~~~~~~~~~LinearSearching~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#include <stdio.h>

int LinearSearch(int arr[], int element, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[50] = {1, 2, 3, 4, 5};
    int element = 4;
    int size = 5;
    int index;

    index = LinearSearch(arr, element, size);
    printf("The %d is present at %d position:\n", element, index);
    return 0;
}