#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int n,p;
   while(cin >> n >> p)
   {
      if(!n && !p) break;
      if(p==1) 
      {
         printf("Line = %d, column = %d.\n",(n+1)/2,(n+1)/2);
         continue;
      }
      int i=1;
      while(i*i<p) i+=2;
      int t = (n+1)/2-(i+1)/2, pi = (i-2)*(i-2)+1;
      int x = n-t;
      int y = x-1;
      while(pi<p && y-1>t) pi+=1,y-=1;
      while(pi<p && x-1>t) pi+=1,x-=1;
      while(pi<p && y+1<=n-t) pi+=1,y+=1;
      while(pi<p && x+1<=n-t) pi+=1,x+=1;
      printf("Line = %d, column = %d.\n",x,y);
   }
   return 0;
}
