#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    double l=0,w=0;
    while(scanf("%lf %lf",&l,&w)==2)
    {
        double maxx=0,minx=0;
        maxx=((w+l)-sqrt((l*l+w*w-w*l)))/6;
        if(l/2<=w/2) minx=l/2;
        else minx=w/2;
        printf("%.3f %.3f %.3f\n",maxx+(1E-6),0.0,minx+(1E-6));
    }
    return 0;
}
