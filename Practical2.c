#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int p, pivot, index, choice;
    printf("\nEnter the indx for pivot(between %d and %d): ", low, high - 1);
    scanf("%d", &choice);
    printf("\nArray before partition:");
    for (int i = low; i <= high; i++)
    {
        printf("%d ", arr[i]);
    }
    if (choice < high)
    {
        swap(&arr[choice], &arr[high]);
    }

    pivot = arr[high];

    int i;
    i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    printf("\nArray after Partition:");
    for (int i = low; i <= high; i++)
    {
        printf("%d ", arr[i]);
    }

    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    int p;

    if (low < high)
    {

        p = partition(arr, low, high);

        
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void main()
{
    int choice, n;
    printf("Enter the number of elemets: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter element %d of the array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //printf("Enter the index for pivot: ");
    //scanf("%d", &choice);

    //int arr[] = {2, 6, 3, 1, 7, 9, 4};
    quick_sort(arr, 0, n - 1);

    printf("\n\nThe final array is:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}