#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f (float x)
{
    float z;
    z=x*exp(x)-cos(x);
    return (z);
}

int main()
{
    float a,b,c,t,d;
    int i;
    i=0;
    printf ("Enter the value of a, b and tolerance \n");
    scanf ("%f %f %f", &a, &b, &t);
    if (f(a)*f(b)<0)
    {
            do 
            {
                c=(a+b)/2;
                if (f(c)*f(a)>0)
                {
                    a=c;
                }
                else
                {
                    b=c;
                }
                i=i+1;
                if (i>100)
                {
                    printf ("The function is not continuous in the interval. \n");
                    return 0;
                }
                d=f(c);
                printf ("%d %f \n", i, d);
            }while (fabs(f(c))>t);
            printf ("The root is %f", c);
    }
    else
    {
        printf ("There is no root in the interval. \n");
    }
return 0;
}
