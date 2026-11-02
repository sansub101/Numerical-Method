#include <stdio.h>

int main()
{
    int n, i, j, k;
    float mat[100][100], temp, x[100], t;
    printf("Enter the size of matrix \n");
    scanf("%d", &n);
    printf("Enter the %d elements of  matrix \n", n * n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%f", &mat[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = n + i; j <= 2 * n; j++)
        {
            if (j == i + n)
            {
                mat[i][j] = 1;
            }
            else
            {

                mat[i][j] = 0;
            }
        }
    }

    for (j = 1; j <= n; j++)
    {
        if (fabs(mat[j][j]) <= 0.0005)
        {
            printf("We can't get the solution");
            return 0;
        }
        else
        {
            for (i = 1; i <= n; i++)
            {
                if (i != j)
                {
                    temp = mat[i][j] / mat[j][j];
                    for (k = 1; k <= (2 * n); k++)
                    {
                        mat[i][k] = mat[i][k] - temp * mat[j][k];
                    }
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        t = mat[i][i];
        for (j = 1; j <= 2 * n; j++)
        {
            mat[i][j] = mat[i][j] / t;
        }
    }
    printf("The inverse matrix is ");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = (n + 1); j <= (2 * n); j++)
        {
            printf("%0.2f ", mat[i][j]);
        }
    }
    return 0;
}