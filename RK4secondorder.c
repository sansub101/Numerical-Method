#include <stdio.h>
#include <math.h>

float f (float x,float y, float z)
{
    float r;
    r=sin(x)-5*z-6*y;
    return (r);
}

int main()
{
    float x0,y0,z0,xn,h,k1,k2,k3,k4,k,l1,l2,l3,l4,l,x1,y1,z1,yt;
    printf ("Enter the initial value of x0, y0 and z0 : ");
    scanf ("%f%f%f",&x0,&y0,&z0);
    printf ("Enter step size h: ");
    scanf ("%f",&h);
    printf ("Enter the final value xn: ");
    scanf ("%f",&xn);
    printf ("x\t\ty\t\tz\n");
    while (x0<=xn)
    {
       k1=h*(z0);
       l1=h*f(x0,y0,z0);
       k2=h*(z0+l1/2);
       l2=h*f(x0+h/2,y0+k1/2,z0+l1/2);
       k3=h*(z0+l2/2);
       l3=h*f(x0+h/2,y0+k2/2,z0+l2/2);
       k4=h*(z0+l3);
       l4=h*f(x0+h,y0+k3,z0+l3);
       k=(k1+2*k2+2*k3+k4)/6;
       l=(l1+2*l2+2*l3+l4)/6;
       x1=x0+h;
       y1=y0+k;
       z1=z0+l;
       printf ("%0.4f\t%0.4f\t%0.4f \n",x0,y0,z0);
       yt=y0;
        x0=x1;
        y0=y1;
        z0=z1;
    }
    printf ("The final value of y is %0.4f",yt);
    return 0;

}
