#include <stdio.h>
#include <math.h>

float f(float x)
{
    float z;
    z = cos(x)-2*x+1;
    return z;
}

int main()
{
    int i;
    i = 0;
    float a, b, c, t;
    printf("Enter the value of a, b and tolerance");
    scanf("%f %f %f", &a, &b, &t);

    do
    {
        if (fabs(f(b) - f(a)) <= t)
        {
            printf("There is no solution");
            return 0;
        }
        else
        {

            c = (a * f(b) - b * f(a)) / (f(b) - f(a));
            a = b;
            b = c;
            /*i++;
           if (i == 100)
            {
                printf("There is no solution");
                return 0;
            }*/
        }
    } while (fabs(f(c)) > t);
    printf("The root = %f and its functional value is = %f", c, f(c));
    return 0;
}