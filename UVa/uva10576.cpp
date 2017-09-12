#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
int s,d;
// freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
while(scanf("%d%d",&s,&d)!=EOF)
{
   int ans=-1;
   for(int i=0;i<4096;i++)
   {
         int arr[15],tot=0;
         for(int j=0;j<12;j++)
         {
            if(i & (1<<j)) arr[j]=(0-d),tot-=d;
            else arr[j]=s,tot+=s;
         }
         if(tot<0) continue;
         bool check = true;
         for(int j=0;j<8;j++)
         {
            int red=0;
            for(int k=j;k<j+5;k++)
            {
               red+=arr[k];
            }
            if(red>=0) 
            {
               check = false;
               break;
            }
         }
         if(!check) continue;
         int sum=0;
         for(int j=0;j<12;j++) sum+=arr[j];
         ans = max(ans,sum);
      }
      if(ans<0) printf("Deficit\n");
      else printf("%d\n",ans);
   }
   return 0;
}
