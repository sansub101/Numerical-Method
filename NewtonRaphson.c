#include <stdio.h>
#include <math.h>

float f (float x)
{
    float z1;
    z1= x*sin(x)+cos(x);
    return z1;
}

float g (float y)
{
    float z;
    z= y*cos(y);
    return z;
}

int main()
{
    int i;
    float x0,x1,t;
    printf ("Enter the initial guess and the value of tolerance \n ");
    scanf ("%f %f", &x0, &t);
    i=0;
    do
    {  
    if (fabs(g(x0))<=t)
    {
        printf ("The slope of the function is zero so we can't get the solution \n");
        return 0;
    }
    else
    {
        x1 = x0-f(x0)/g(x0);
        x0=x1;
        i++;
        if (i==100)
        {
            printf ("The function is continuous and we can't getthe solution \n");
            return 0;
        }
    }
    }while (fabs(f(x0))>t);
    printf ("The solution is %f and its functional value is %f.", x0, f(x0));
    return 0;
}