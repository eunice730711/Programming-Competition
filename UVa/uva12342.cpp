#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double arr[4]={180000, 300000, 400000, 300000};
double per[4]={0, 0.1, 0.15, 0.2};
double compute(int k)
{
   double tax=0;
   for(int i=0;i<4;i++)
   {
      if(k>arr[i]) tax+=arr[i]*per[i];
      else
      {
         tax+=k*per[i];
         return tax;
      }
      k-=arr[i];
   }
   if(k>0) tax+=k*0.25;
   return tax;
}
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      int k=0;
      cin >> k;
      double ans = compute(k);
      if(ans>0 && ans < 2000) ans = 2000;
      ans = ceil(ans);
      printf("Case %d: %d\n",c,int(ans));
   
   }
   return 0;
}
