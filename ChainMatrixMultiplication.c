#include <stdio.h>
#include <limits.h>

long int m[30][30];
int s[30][30];
int p[30], i, j, n;

void MinMultiplication(int i, int j)
{
    if (i == j)
        printf(" A%d ", i);
    else
    {
        printf("( ");
        MinMultiplication(i, s[i][j]);
        MinMultiplication(s[i][j] + 1, j);
        printf(" )");
    }
}

void CMC(void)
{
    long int q;
    int k;
    for (i = n; i > 0; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                m[i][j] = 0;
            else
            {
                for (k = i; k < j; k++)
                {
                    q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
}

int OptimalParenthesis(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = OptimalParenthesis(p, i, k) +
                OptimalParenthesis(p, k + 1, j) +
                p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    return min;
}

void main()
{
    int k;
    printf("\nEnter the no. of metricies: \t");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
        {
            m[i][i] = 0;
            m[i][j] = INT_MAX;
            s[i][j] = 0;
        }
    printf("\nEnter the Dimensions of the matrices: \n");
    for (k = 0; k <= n; k++)
    {
        printf("The value for P-%d: \t", k);
        scanf("%d", &p[k]);
    }
    CMC();
    printf("\nThe formed Cost Matrix M is:\n");
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
            printf("M[%d][%d]: %ld\n", i, j, m[i][j]);

    i = 1, j = n;

    printf("\n\nMultiplication Sequence is: \n");
    MinMultiplication(i, j);

    printf("\n\nMinimum number of Multiplications is : %d ", OptimalParenthesis(p, 1, n));
}
