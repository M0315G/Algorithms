#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort_iterative(int arr[], int n)
{
  int i, j;
  int min;
  for (i = 0; i < n - 1; i++)
  {
    min = i; // Finding the minimum element from the array

    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }

    swap(&arr[i], &arr[min]); // Swapping
  }

  printf("\nResult of Selection Sort(Iterative):\n");
  printf("The final sorted array is:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
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
    selection_sort_iterative(arr, n);

    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}