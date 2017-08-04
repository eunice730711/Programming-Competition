#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int cas;
   scanf("%d",&cas);
   while(cas--)
   {
      int a,b,c;
      bool sol=false;
      scanf("%d%d%d",&a,&b,&c);
      for(int x=-100 ; x<100 ;x++)
         if(x*x<c)
         {
            for(int y=x+1; y<=100; y++)
            {
               if(x*x+y*y<=c)
               {
                  for(int z=y+1; z<=100;z++)
                  {
                     if(x+y+z==a && x*y*z==b && x*x+y*y+z*z==c)
                     {
                        printf("%d %d %d\n",x,y,z);
                        sol=true;
                        break;
                     }
                  }
               }
            }
         }
      if(!sol) printf("No solution.\n");
   
   }
   return 0;
}
