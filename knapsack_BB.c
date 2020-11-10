#include <stdio.h>

void arrange_items(int n, int *arr)
{

    float ratio[n];
    for (int i = 0; i < n; i++)
    {
        ratio[i] = (*((arr + i * 2) + 1) / (*((arr + i * 2) + 0)));
        printf("\n%d\t%d", *((arr + i * 2) + 0), *((arr + i * 2) + 1));
    }

    int i, j;
    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = i; // Finding the minimum element from the array

        for (j = i + 1; j < n; j++)
        {
            if (ratio[j] > ratio[min])
            {
                min = j;
            }
        }

        int temp = ratio[i];
        ratio[i] = ratio[min];
        ratio[min] = ratio[i];

        int t1, t2;
        t1 = *((arr + i * 2) + 0);
        t2 = *((arr + i * 2) + 1);
        *((arr + i * 2) + 0) = *((arr + min * 2) + 0);
        *((arr + i * 2) + 1) = *((arr + min * 2) + 1);
        *((arr + min * 2) + 0) = t1;
        *((arr + min * 2) + 1) = t2;
    }

    printf("\nThe items now are:\n");
    printf("Weight\tProfit");
    for (i = 0; i < n; i++)
    {
        printf("\n%d\t%d ", *((arr + i * 2) + 0), *((arr + i * 2) + 1));
    }
}


int find_cost(int n, int items[n][2], int weight, int use_item[n])
{

    int w1 = weight;
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (use_item[i] == 1)
        {
            if (w1 - items[i][0] >= 0)
            {
                w1 = w1 - items[i][0];
                cost = cost + items[i][1];
            }
            else
            {
                w1 = 0;
                cost = cost + (int)(w1 * (items[i][1] / items[i][0]));
            }
        }
    }

    return cost;
}

int find_upperBound(int n, int items[n][2], int weight, int use_item[n])
{

    int w1 = weight;
    int upper_bound = 0;
    for (int i = 0; i < n; i++)
    {
        if (use_item[i] == 1)
        {
            if (w1 - items[i][0] >= 0)
            {
                w1 = w1 - items[i][0];
                upper_bound = upper_bound + items[i][1];
            }
        }
    }

    return upper_bound;
}

void knapsack(int n, int items[n][2], int weight)
{

    int include_item[n];
    int use_item[n];

    for (int i = 0; i < n; i++)
    {
        use_item[i] = 1;
    }

    arrange_items(n, (int *)items);

    printf("\nCalculating the Maximum Profit...");

    int w1 = weight;
    int u = find_upperBound(n, items, weight, use_item);
    int c = find_cost(n, items, weight, use_item);

    printf("\nFor Node - 1:");
    printf("\nu = %d", u);
    printf("\nc = %d", c);
    printf("\n");

    int u1, u2, c1, c2, max = 0, profit = 0;
    for (int i = 0; i < n; i++)
    {

        //Taking the Item
        u1 = find_upperBound(n, items, weight, use_item);
        c1 = find_cost(n, items, weight, use_item);
        printf("\nTaking the %d Item: ", (i + 1));
        printf("\nu = %d", u1);
        printf("\nc = %d", c1);

        //Without the Item
        use_item[i] = 0;
        u2 = find_upperBound(n, items, weight, use_item);
        c2 = find_cost(n, items, weight, use_item);
        printf("\nWithout taking the %d Item: ", (i + 1));
        printf("\nu = %d", u2);
        printf("\nc = %d", c2);
        printf("\n");
        if (u1 > u2)
        {
            max = u1;
            printf("\nWe will include %d Item as the upper bound of that node is greater.", (i + 1));
            include_item[i] = 1;
            use_item[i] = 1;
        }
        else
        {
            max = u2;
            printf("\nWe will not include %d Item as the upper bound of that node is greater.", (i + 1));
            include_item[i] = 0;
        }
    }

    printf("\nThe Maximum Cost is : %d", max);
    printf("\nThe Matrix is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", include_item[i]);
    }

    printf("\nThe items now are:\n");
    printf("Weight\tProfit");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d ", items[i][0], items[i][1]);
    }
}

void main()
{

    int weight, n;
    printf("\nEnter the Maximum weight of the Knapsack: ");
    scanf("%d", &weight);
    printf("\nEnter the no of items: ");
    scanf("%d", &n);

    int items[n][2];

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the weight of item no - %d: ", (i + 1));
        scanf("%d", &items[i][0]);
        printf("\nEnter the profit of item no - %d: ", (i + 1));
        scanf("%d", &items[i][1]);
    }

    int profit, include_item[n];
    knapsack(n, items, weight);
}