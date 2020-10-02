#include <stdio.h>

// Function to swap two numbers in-place.
void swap(int *x, int *y)
{

    int temp = *x; //Using a temporary variable.
    *x = *y;
    *y = temp;
}

// FUnction to perform Iterative version of Bubble Sort.
void bubble_sort_iterative(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
    printf("\nResult of Bubble Sort(Iterative):\n");
    printf("The final sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    int n = 7;
    int arr[] = {1, 6, 3, 8, 6, 2, 9};
    printf("The initial array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    bubble_sort_iterative(arr, n);
}