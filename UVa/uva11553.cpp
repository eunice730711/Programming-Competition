#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   int cas;
   scanf("%d",&cas);
   while(cas--)
   {
      int n;
      scanf("%d",&n);
      int arr[10][10]={0};
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            scanf("%d",&arr[i][j]);
         }
      }
      int p[10];
      for(int i=0;i<n;i++) p[i]=i;
      int sum=0,ans=100000;
      do
      {
         sum=0;
         for(int i=0;i<n;i++)
         {
            sum+=arr[i][p[i]];
         }
         ans = min(ans,sum);

      }while(next_permutation(p,p+n));
      cout << ans << endl;
   }



   return 0;
}
