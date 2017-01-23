#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int n;
   while(cin >> n)
   {
      int k=0,ans=0;
      if(n%2==0)
      {
         k = n/2;
         cout << k << endl;
         for(int i=0;i<k;i++)
         {
            cout << '2';
            if(i!=k-1) cout << ' ';
            
         }
         cout << endl;
      }
      else
      {
         k = n/2-1;
         cout << k+1 << endl;
         for(int i=0;i<k;i++)
         {
            cout << '2' << ' ';
         }
         cout << '3' << endl;
         
      }
   }


   return 0;
}
