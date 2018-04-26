#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[100005],n;
bool check(int k)
{
   int tmp = k;
   for(int i=0;i<=n-1;i++)
   {
      if((arr[i+1]-arr[i])==tmp)
      {
         tmp-=1;
      }
      else if((arr[i+1]-arr[i])>tmp) return false;
   }
   return true;
}
int binary_search(int left,int right)
{
   if(left>=right) return left;
   int mid = (right+left)/2;
   bool tmp = check(mid);
   if(tmp) return binary_search(left,mid);
   return binary_search(mid+1,right);
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   int test;
   scanf("%d",&test);
   for(int c=1;c<=test;c++)
   {
      scanf("%d",&n);
      memset(arr,0,sizeof(arr));
      int left=0,right=0,tmp;
      arr[0]=0;
      for(int i=1;i<=n;i++)
      {
         scanf("%d",&arr[i]);
         if(i>0)
         {
            tmp = arr[i]-arr[i-1];
            if(tmp>left) left=tmp;
         }
      }
      right = arr[n]-arr[0];
      int ans = binary_search(left,right);
      printf("Case %d: %d\n",c,ans);
   }
   return 0;
}
