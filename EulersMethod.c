#include <stdio.h>

float f (float x,float y)
{
    float z;
    z=x*cos(x);
    return (z);
}

int main()
{
    float xn,x0,y0,h,x1,y1,m,ya;
    printf ("Enter the initial value of x0 and y0: ");
    scanf ("%f%f",&x0,&y0);
    printf ("Enter step size h: ");
    scanf ("%f",&h);
    printf ("ENter the final value xn: ");
    scanf ("%f",&xn);
    printf ("x\t\ty\n");
    while (x0<=xn)
    {
        m=f(x0,y0);
        y1=y0+h*m;
        x1=x0+h;
        printf ("%0.4f\t%0.4f\n",x0,y0);
        ya=y0;
        x0=x1;
        y0=y1;
    }
    printf ("The final value of y is %0.4f",ya);
    return 0;

}