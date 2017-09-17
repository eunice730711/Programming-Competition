#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
// 首先要先推出題目為遞減函數
double arr[6];
double binary_search(double a, double b)
{
   if(fabs(a-b)<=1e-10) return -1;
   double x = (a+b)/2;
   double ans = arr[0]*exp(-x)+arr[1]*sin(x)+arr[2]*cos(x)+arr[3]*tan(x)+arr[4]*x*x + arr[5];
   if(fabs(ans-0.0)<1e-8)
   {
      return x;
   }
   if(ans>0) return binary_search(x,b);
   else return binary_search(a,x);
}
int main()
{
   while(scanf("%lf%lf%lf%lf%lf%lf",&arr[0],&arr[1],&arr[2],&arr[3],&arr[4],&arr[5])!=EOF)
   {
      double myans = binary_search(0.0,1.0);
      if(myans == -1) printf("No solution\n");
      else printf("%.4lf\n",myans); 
   }
   return 0;
}
