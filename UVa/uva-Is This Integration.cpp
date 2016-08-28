#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 2.0*acos(0.0)
int main()
{
    double a,x,y,z;
    while(scanf("%lf",&a)!=EOF)
    {
        double p,q,r;//p為正方形面積,q為扇形面積,r為彈頭面積
        p=a*a;
        q=0.25*PI*p;
        r=(1.0/3.0)*PI*p-(sqrt(3.0)/4.0)*p;
        z=p-2*q+r;
        y=3*q-p-2*r;
        x=p-4*q+4*r;
        printf("%.3f %.3f %.3f\n",x,4*y,4*z);
    }
    return 0;
}
