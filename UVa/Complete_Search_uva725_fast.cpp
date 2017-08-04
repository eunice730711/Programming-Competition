#include <cstdio>
#include <cstdlib>
int main()
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   int n;
   bool first = true;
   while(scanf("%d",&n)!=EOF)
   {
      if(!n) break;
      if(!first) printf("\n");
      first = false;
      int ans=0;
      for(int b = 1234; b <= 98765/n ; b++)
      {
         int tmp, used = (b<10000);
         int a = b * n;
         tmp = b;
         while(tmp) 
         {
            used |= 1 << (tmp%10);
            tmp/=10;
         }
         tmp = a;
         while(tmp)
         {
            used |= 1 << (tmp%10);
            tmp/=10;
         }
         if(used == (1<<10)-1) 
            printf("%0.5d / %0.5d = %d\n",a,b,n),ans+=1;

      }
      if(!ans) printf("There are no solutions for %d.\n",n);
   }
   return 0;
}