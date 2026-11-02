#include <stdio.h>

int main()
{
    int n, d, i, j, k;
    double x[100], y[100], mat[100][100], temp, z[100];
    printf("enter number of data and degree of equation ");
    scanf("%d %d", &n, &d);
    if (n <= d)
    {
        printf("Error");
        return 0;
    }
    printf("Enter the values of x \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }
    printf("Enter the values of y \n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &y[i]);
    }
    for (i = 0; i <= d; i++)
    {
        for (j = 0; j <= d; j++)
        {
            mat[i][j] = 0;
            for (k = 0; k < n; k++)
            {
                mat[i][j] = mat[i][j] + pow(x[k], i + j);
            }
        }
    }
    for (i = 0; i <= d; i++)
    {
        for (k = 0; k < n; k++)
        {
            mat[i][d + 1] = mat[i][d + 1] + pow(x[k], i) * y[k];
        }
    }
    printf ("The augmented matrix of the normal equations is \n");
    for (i = 0; i <= d; i++)
    {
        for (j = 0; j <= d + 1; j++)
        {
            printf("%0.2lf ", mat[i][j]);
        }
        printf("\n");
    }
    for (j = 0; j <= d; j++)
    {
        if (fabs(mat[j][j]) <= 0.0005)
        {
            printf("We can't get the solution \n");
            return 0;
        }
        else
        {
            for (i = 0; i <= d; i++)
            {
                if (i != j)
                {
                    temp = mat[i][j] / mat[j][j];
                    for (k = 0; k <= d + 1; k++)
                    {
                        mat[i][k] = mat[i][k] - temp * mat[j][k];
                    }
                }
            }
        }
    }
    printf("The coefficients are \n");
    for (i = 0; i <= d; i++)
    {
        z[i] = mat[i][d + 1] / mat[i][i];
        printf ("%0.2lf ",z[i]);
    }
    return 0;
}