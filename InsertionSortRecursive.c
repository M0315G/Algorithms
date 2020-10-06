#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to move the left-most element 
int one_pass(int arr[], int j, int key)
{
    //printf("\nKey = %d, j = %d", key, j);
    arr[j + 1] = arr[j];
    j = j - 1;
    if (j >= 0 && arr[j] > key)
    {
        j = one_pass(arr, j, key);
    }

    return j;
}

void insertion_sort(int arr[], int n)
{

    if (n == 1)
    {
        return;
    }

    insertion_sort(arr, n - 1);

    int key = arr[n - 1];
    int j = n - 2;

    if (arr[j] > key)
    {
        j = one_pass(arr, j, key);
        printf("\n");                   // To print the status of the array after each pass
        for (int i = 0; i < n; i++)
        {
            printf("%d  ", arr[i]);
        }
    }

    arr[j+1] = key;
}

void main()
{

    //int arr[] = {2, 4, 6, 1, 5, 7};
    int n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element-%d of array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}