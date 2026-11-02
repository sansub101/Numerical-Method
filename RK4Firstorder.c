#include <stdio.h>

float f (float x,float y)
{
    float z;
    z=x*cos(x);
    return (z);
}

int main()
{
    float x0,y0,xn,h,k1,k2,k3,k4,k,x1,y1,yt;
    printf ("Enter the initial value of x0 and y0: ");
    scanf ("%f%f",&x0,&y0);
    printf ("Enter step size h: ");
    scanf ("%f",&h);
    printf ("Enter the final value xn: ");
    scanf ("%f",&xn);
    printf ("x\t\ty\n");
    while (x0<=xn)
    {
        k1= h*f(x0,y0);
        k2= h*f(x0+h/2,y0+k1/2);
        k3= h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0+h,y0+k3);
        k=(k1+2*k2+2*k3+k4)/6;
        y1=y0+k;
        x1=x0+h;
        printf ("%0.4f\t\t%0.4f\n",x0,y0);
        yt=y0;
        x0=x1;
        y0=y1;


    }
    printf ("The final value of y is %0.4f",yt);
    return 0;

}