#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int begin;
   int cas=1;
   while(cin >> begin)
   {
      int pro=begin;
      int create[15],req[15],ava[15];
      if(pro<0) break;
      for(int i=0;i<12;i++)
      {
         int k=0;
         cin >> k;
         create[i]=k;
      }
      cout << "Case " << cas++ << ":"<< endl;
      for(int i=0;i<12;i++)
      {
         int r=0;
         cin >> r;
         if(r<=pro) {
            cout << "No problem! :D" << endl;
            pro-=r;
         }
         else cout << "No problem. :(" << endl;
         pro+=create[i];
      }
   
   
   
   }


   return 0;
}
