#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Min_index(int arr[], int i, int j)
{

    if (i == j)
        return i;

    int k = Min_index(arr, i + 1, j);

    return (arr[i] < arr[k]) ? i : k;
}

// Function for Recursive version of Selective Sort.
void selection_sort(int arr[], int n, int index)
{

    if (index == n)
        return;

    int k = Min_index(arr, index, n - 1);

    if (k != index)
    {
        swap(&arr[k], &arr[index]);
    }

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    selection_sort(arr, n, index + 1);
}

void main()
{
    int n;
    printf("Enter the value of n:");
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element-%d of array: ", i + 1);
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n, 0);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}