#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[100], y[100], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, a, b, d,aa,yl[100];
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
        yl[i]=log(y[i]);
        sumx = sumx + x[i];
        sumx2 = sumx2 + pow(x[i], 2);
        sumy = sumy + yl[i];
        sumxy = sumxy + x[i] * yl[i];
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
        aa=exp(a);
    }
    printf("The required equation is y=%0.2fexp(%0.2fx)", aa, b);
    return 0;
}