#include <stdio.h>

int main()
{
    int i, j, n;
    float x[100], y[100], xp, yp, p;
    printf("Enter the number of data ");
    scanf("%d", &n);
    printf("Enter the values of x \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    printf("ENter the value of x to be interpolated ");
    scanf("%f", &xp);
    p=1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p = p*(xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp = yp + p * y[i];
        p = 1;
    }
    printf ("\n The interpolated value is %0.2f",yp);
    return 0;
}