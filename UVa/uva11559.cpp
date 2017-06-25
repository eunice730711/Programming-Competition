#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int n,b,h,w;
   while(cin >> n >> b >> h >> w)
   {
      int first = true;
      int money=0;
      for(int i=0;i<h;i++)
      {
         int p;
         bool ok = false;
         cin >> p;
         for(int j=0;j<w;j++)
         {
            int beds;
            cin >> beds;
            if(beds>=n) ok=true;
         }
         if(first)
         {
            if(ok)
            {
               money = p*n;
               first = false;
            }
         }
         else
         {
            if(ok && p*n<money)
            {
               money = p*n;
            }
         }
      }
      if(money == 0 || b<money) cout << "stay home" << endl;
      else cout << money << endl;
   }
   return 0;
}
