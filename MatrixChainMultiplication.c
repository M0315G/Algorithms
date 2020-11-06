#include <stdio.h>
#include <limits.h>

char matrixName = 'A';
int sequence[50][50];

void printingTheParenthesis(int l, int r)
{
    if (l == r){
        printf("%c", matrixName);
        matrixName++;
        return;
    }

    else
    {
        printf(" ( ");
        printingTheParenthesis(l, sequence[l][r]);
        printingTheParenthesis(sequence[l][r] + 1, r);
        printf(" ) ");
    }
}

void matrixChainOrder(int p[], int n) 
{ 
    int m[n][n];  
    int bracket[n][n]; 
  
    // cost is zero when multiplying one matrix. 
    for (int i=1; i<n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (int L=2; L<n; L++) 
    { 
        for (int i=1; i<n-L+1; i++) 
        { 
            int j = i+L-1; 
            m[i][j] = INT_MAX; 
            for (int k=i; k<=j-1; k++) 
            { 
                // q = cost/scalar multiplications 
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
                if (q < m[i][j]) 
                { 
                    m[i][j] = q; 
                    sequence[i][j] = k;
                } 
            } 
        } 
    } 
    

    for(int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            printf("\nCost[%d][%d] : %d",i+1,j+1, m[i][j]);
        }
    }

    printf("\n\nOptimal Parenthesization is : "); 
    printingTheParenthesis(1,n-1); 
    printf("\nOptimal Cost is : %d\n\n",m[1][n-1]); 
} 

int main(){
   
    int n;
    printf("\n\nEnter numer of dimensions entries: ");
    scanf("%d",&n);

    int a[n];
    printf("Eg: For Matrices with dimensions 2 X 4 and 4 X 6, only enter 2,4,6 :\n");
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    
    matrixChainOrder(a, n); 
    return 0; 
}