#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      int a[100005],b[100005];
      int n;
      cin >> n;
      for(int i=1;i<=n;i++)
      {
         cin >> b[i];
      }
      int sum=0,ans=0;
      for(int i=1;i<=n;i++)
      {
         int tmp;
         cin >> tmp;
         a[i]=b[i]-tmp;
         sum+=a[i];
      }
      if(sum<0)
      {
         printf("Case %d: Not possible\n",c);
         continue;
      }
      sum=0;
      for(int i=1;i<=n;i++)
      {
         sum+=a[i];
         if(sum<0)
         {
            ans = i+1;
            sum=0;
         }
      }
      printf("Case %d: Possible from station %d\n",c,ans);   
   }
   return 0;
}
