#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <iostream>
using namespace std;
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int sum;
      scanf("%d",&sum);
      int n;
      scanf("%d",&n);
      bool flag=false;
      int arr[25];
      for(int i=0;i<n;i++)
      {
         int tmp;
         scanf("%d",&tmp);
         arr[i]=tmp;
      }
      for(int i=0;i<(1<<n);i++)
      {
         int tmp=0;
         for(int j=0;j<n;j++)
         {
            if(i & (1<<j))
               tmp+=arr[j];
         }
         if(tmp==sum)
         {
            flag=true;
            break;
         }
      }
      if(flag) printf("YES\n");
      else printf("NO\n");
   
   }
   return 0;
}
