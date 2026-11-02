#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[100], y[100], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, a, b, d;
    printf("Enter the number of data ");
    scanf("%d", &n);
    printf("Enter the values of x \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter the values of y \n");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &y[i]);
    }
    for (i = 1; i <= n; i++)
    {
        sumx = sumx + x[i];
        sumx2 = sumx2 + pow(x[i], 2);
        sumy = sumy + y[i];
        sumxy = sumxy + x[i] * y[i];
    }
    d = (n * sumx2 - sumx * sumx);
    if (d <= 0.0005)
    {
        printf("Error");
        return 0;
    }
    else
    {
        a = (sumy * sumx2 - sumx * sumxy) / d;
        b = (n * sumxy - sumx * sumy) / d;
    }
    printf("The required equation is y=%0.2f+%0.2fx", a, b);
    return 0;
}