#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{

    int i = low;
    int j = mid + 1;
    int a[high - low];
    int k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] > arr[j])
        {
            a[k] = arr[j];
            j++;
        }
        else if (arr[i] < arr[j])
        {
            a[k] = arr[i];
            i++;
        }
        else if (arr[i] == arr[j])
        {
            a[k] = arr[i];
            k = k + 1;
            a[k] = arr[j];
            j++;
            i++;
        }
        k++;
    }

    if (i <= mid)
    {
        for (int d = i; d <= mid; d++)
        {
            a[k] = arr[d];
            k = k + 1;
        }
    }
    else if (j <= high)
    {
        for (int d = j; d < high; d++)
        {
            a[k] = arr[d];
            k = k + 1;
        }
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = a[i];
    }
}

void merge_sort(int arr[], int low, int high)
{

    if (low < high)
    {

        int mid;
        mid = low + (high - low) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void main()
{
    int arr[] = {1, 5, 3, 6};
    merge_sort(arr, 0, 3);
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", arr[i]);
    }
}