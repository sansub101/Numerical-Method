#include <stdio.h>

int main()
{
    int n, i, j, k;
    float mat[100][100], temp,x[100];
    printf("Enter the size of matrix \n");
    scanf("%d", &n);
    printf("Enter the %d elements of augmented matrix \n",(n*(n+1)));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    for (j = 1; j <= n; j++)
    {
        if (fabs(mat[j][j]) <= 0.0005)
        {
            printf ("We can't get the solution");
            return 0;
        }
        else
        {
            for (i = 1; i <= n; i++)
            {
                if (i != j)
                {
                    temp = mat[i][j] / mat[j][j];
                    for (k = 1; k <= n + 1; k++)
                    {
                        mat[i][k] = mat[i][k] - temp * mat[j][k];
                    }
                }
            }
        }
    }
    printf ("The solution is \n");
    for (i=1;i<=n;i++)
    {
        x[i]=mat[i][n+1]/mat[i][i];
        printf ("x%d = %f \n",i,x[i]);
    }
    return 0;
}