/*
find the longest unique sequence
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      map<int,int> lastseen;
      int ans=0,num=0,n,block=0;
      cin >> n;
      for(int i=1;i<=n;i++)
      {
         int tmp,last;
         cin >> tmp;
         last = lastseen[tmp];
         if(last!=0)
         {
            block = max(block,last);
            num = i-block-1;
         }
         num++;
         lastseen[tmp]=i;
         ans=max(ans,num);
      }
      cout << ans << endl;
   }
   return 0;
}
