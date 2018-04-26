#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
int arr[505][505];
int bs(int l_i,int l_j,int right) // 二維的binary search
{
   int r_j = l_j + (n-1-l_i);
   if(r_j>=m) r_j = m-1;
   int r_i = l_i + (r_j - l_j);
   int mid_i,mid_j;
   while( l_j != r_j)
   {
      mid_i = (r_i+l_i+1)/2;
      mid_j = (r_j+l_j+1)/2;
      if(arr[mid_i][mid_j]<=right)
      {
         l_i = mid_i;
         l_j = mid_j;
      }
      else 
      {
         r_i = mid_i-1;
         r_j = mid_j-1;
      }
   }
   return l_j;
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   while(scanf("%d%d",&n,&m)!=EOF)
   {
      if(!n && !m) break;
      memset(arr,0,sizeof(arr));
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<m;j++)
         {
            scanf("%d",&arr[i][j]);
         }
      }
      int q;
      scanf("%d",&q);
      while(q--)
      {
         int left,right,x,y,b,ans=0;
         scanf("%d%d",&left,&right);
         for(int i=0;i<n;i++)
         {
            int j;
            vector<int> v(arr[i],arr[i]+m);
            vector<int>::iterator low = lower_bound(v.begin(),v.end(),left);
            if(low==v.end()) continue; // 連最右邊的都不<=left
            x = low-v.begin();
            if(arr[i][x]>right) continue; // 雖然大於左邊界但已大於右邊界
            int y = bs(i,x,right);
            if(arr[i+y-x][y]>right) continue; // 超出左邊界了
            if(y-x+1>ans) ans = y-x+1;
         }
         printf("%d\n",ans);
      }
    printf("-");
    puts("");
   }
   return 0;
}
