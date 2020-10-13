#include <stdio.h>

int max_cross_sub_array(int a[], int low, int mid, int high)
{
    int l_sum = -1000000;
    int sum = 0;
    int left;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + a[i];
        if (sum > l_sum)
        {
            l_sum = sum;
            left = i;
        }
    }

    int r_sum = -1000000;
    sum = 0;
    int right;
    for (int i = mid + 1; i <= high; i++)
    {
        sum = sum + a[i];
        if (sum > r_sum)
        {
            r_sum = sum;
            right = i;
        }
    }

    return left, right, (l_sum + r_sum);
}

int max_sub_array(int a[], int low, int high)
{
    if (low == high)
    {
        return low, high, a[low];
    }
    else
    {
        int l_low, l_high, l_sum, r_low, r_high, r_sum, c_low, c_high, c_sum;
        int mid = (int)(low + high) / 2;
        l_low, l_high, l_sum = max_sub_array(a, low, mid);
        r_low, r_high, r_sum = max_sub_array(a, mid + 1, high);
        c_low, c_high, c_sum = max_cross_sub_array(a, low, mid, high);

        if (l_sum >= r_sum && l_sum >= c_sum)
        {
            return l_low, l_high, l_sum;
        }
        else if (r_sum >= l_sum && r_sum >= c_sum)
        {
            return r_low, r_high, r_sum;
        }
        else
        {
            return c_low, c_high, c_sum;
        }
    }
}

void main()
{
    int n;
    printf("\nEnter the total number of elements: ");
    scanf("%d", &n);
    int i = 0;
    int a[n];
    printf("\nEnter %d elements:\n", n);
    while (i < n)
    {
        scanf("%d", &a[i]);
        i++;
    }
    //int a[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int low, high, sum;
    low, high, sum = max_sub_array(a, 0, n-1);
    printf("The maximum subarray is: %d", sum);
}