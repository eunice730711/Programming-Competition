#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int n;
   int cas=1;
   while(cin >> n)
   {
      int a=0,b=0;
      if(n==0) break;
      for(int i=0;i<n;i++)
      {
         int k;
         cin >> k;
         if(k==0) b++;
         else if(k>0 && k<=99) a++;
      }
      cout << "Case " << cas++ << ": " << a-b << endl; 
   }




   return 0;
}
