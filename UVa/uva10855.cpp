#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
char big[500][500],small[500][500];
int check(int n,int m)
{
   int ans=0;
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
         if(i+m-1<n && j+m-1<n)
         {
            bool flag = true;
            for(int k=0;k<m;k++)
               for(int l=0;l<m;l++)
                   if(small[k][l]!=big[i+k][j+l])
                   {
                     flag = false;
                     break;
                   }
            if(flag) ans++;
         }      
      }
   return ans;
}
void rotate(int m)
{
   char tmp[m][m];
   for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
         tmp[i][j]=small[m-j-1][i];
   for(int i=0;i<m;i++)
      for(int j=0;j<m;j++)
         small[i][j]=tmp[i][j];   
}
int main()
{
   int n,m;
   while(cin >> n >> m)
   {
      if(n==0 && m==0) break;
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            cin >> big[i][j];
      for(int i=0;i<m;i++)
         for(int j=0;j<m;j++)
            cin >> small[i][j];
      int ans[4];
      for(int i=0;i<4;i++)
      {
         ans[i] = check(n,m);
         rotate(m);
      }
      printf("%d %d %d %d\n",ans[0],ans[1],ans[2],ans[3]);
   }
   return 0;
}
