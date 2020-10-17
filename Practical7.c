#include <stdlib.h>
#include "stdio.h"

void display(int array[], int start, int end)
{
    printf("\nThe elements are: \n");
    for (int i = start; i <= end; i++)
    {
        printf("%d ", array[i]);
    }
}

int find_median(int numbers[], int g_size)
{
    printf("\nFinding median for : ");
    for (int f = 0; f < g_size; ++f)
    {
        printf("%d ", numbers[f]);
    }
    int i, k, j;
    for (i = 1; i < g_size; i++)
    {
        k = numbers[i];
        j = i - 1;
        while (j >= 0 && k < numbers[j])
        {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = k;
    }
    printf("\nMedian is : %d", numbers[g_size / 2]);
    return numbers[g_size / 2];
}

int partition(int nums[], int beg, int end, int num)
{
    int i;
    for (i = beg; i < end; i++)
    {
        if (nums[i] == num)
            break;
    }
    int temp = nums[i];
    nums[i] = nums[end];
    nums[end] = temp;
    i = beg;
    for (int j = beg; j <= end - 1; j++)
    {
        if (nums[j] <= num)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }
    int temp1 = nums[i];
    nums[i] = nums[end];
    nums[end] = temp1;
    return i;
}

// Median of Medians Algorithm to find the kth smallest element which can be used
// as mid in Quick Sort.
int MOM(int numbers[], int low, int high, int size, int g_size)
{
    if (size > 0 && size <= high - low + 1)
    {
        int t_size = high - low + 1;
        int median[(t_size + g_size - 1) / g_size];
        int i;

        for (i = 0; i < (t_size / g_size); ++i)
        {
            median[i] = find_median(numbers + low + (i * g_size), g_size);
        }

        if (i * 5 < t_size)
        {
            median[i] = find_median(numbers + low + (i * g_size), t_size % g_size);
        }

        int median_of_median;

        if (i == 1)
            median_of_median = median[i - 1];
        else // Recursively Finding the MOM
            median_of_median = MOM(median, 0, i - 1, i / 2, g_size);

        int pos = partition(numbers, low, high, median_of_median);

        if (pos - low == size - 1) // If we have the required kth smallest number then we return
            return numbers[pos];
        if (pos - low > size - 1)
            return MOM(numbers, low, pos - 1, size, g_size);

        return MOM(numbers, pos + 1, high, size - pos + low - 1, g_size);
    }
    return 1000; // NUll case
}

void quicksort(int numbers[], int low, int high, int g_size)
{
    if (low < high)
    {
        int temp_size = high - low + 1;

        int mid = MOM(numbers, low, high, temp_size / 2, g_size);

        printf("\n\nThe pivot selected is %d", mid);

        printf("\nThe Array before applying Partition is: ");
        display(numbers, low, high);

        int p = partition(numbers, low, high, mid);

        printf("\nThe Array after applying Partition is: ");
        display(numbers, low, high);

        // Recursive Calling
        quicksort(numbers, low, p - 1, g_size);
        quicksort(numbers, p + 1, high, g_size);
    }
}

void main()
{
    int n;
    printf("Median of medians");
    printf("\nPlease enter the number of elements : ");
    scanf("%d", &n);
    int numbers[n];
    printf("\nPlease enter the elements : ");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &numbers[i]);
    }
    int g_size;
    printf("\nPlease enter group size : ");
    scanf("%d", &g_size);

    //Quick Sort
    quicksort(numbers, 0, n - 1, g_size);

    printf("\nThe sorted numbers are : ");
    for (int i = 0; i < n; ++i)
    {
        printf(" %d ", numbers[i]);
    }
}