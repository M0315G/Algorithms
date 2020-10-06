#include<stdio.h>

void insertion_sort_iterative(int arr[], int n)
{

  int i, j, key;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }

    arr[j + 1] = key;
  }

  printf("\nResult of Insertion Sort(Iterative):\n");
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
    insertion_sort_iterative(arr, n);
}