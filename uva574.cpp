#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
   int t,n;
   while(scanf("%d%d",&t,&n)!=EOF)
   {
      if(!n && !t) break;
      int arr[15];
      for(int i=0;i<n;i++) scanf("%d",&arr[i]);
      printf("%d\n",pow(2,n));
      for(int i=0;i<pow(2,n);i++)
      {
         
      }
   
   
   
   }



   return 0;
}
