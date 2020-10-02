#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perfom the operation of the inner loop of Bubble sort.
void one_pass(int arr[], int str, int end)
{

    if (str == end)            //Terminating condition.
    {
        return;
    }

    one_pass(arr, str, end - 1);

    int i = end - 1;
    int j = end;

    if (arr[i] > arr[j])       //Swapping condition
    {
        swap(&arr[i], &arr[j]);
    }
}

void bubble_sort(int arr[], int n)
{

    if (n == 1)
    {
        return;
    }

    one_pass(arr, 0, n);

    printf("\n");                   //To print the status of the array after each recursive traversal.
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    bubble_sort(arr, n - 1);
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
    bubble_sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}