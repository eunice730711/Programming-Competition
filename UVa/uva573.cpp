#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   double h,u,d,f;
   while(cin >> h >> u >> d >> f)
   {
      if(h==0) break;
      double loss = u*(f/100);
      double pos = 0;
      int day=0;
      bool success = false;
      while(pos<=h)
      {
         day++;
         pos+=u;
         if(pos>h)
         {
            success = true;
            break;
         }
         pos-=d;
         if(pos<0)
         {
            success = false;
            break;
         }
         u-=loss;
         if(u<0) u=0;
      }
   
      if(success) cout << "success on day " << day << endl;
      else cout << "failure on day " << day << endl;
   
   
   }




   return 0;
}
