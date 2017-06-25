#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      int m,n;
      cin >> m >> n;
      int p,q;
      p = (m-2)/3;
      q = (n-2)/3;
      if((m-2)%3>0) p+=1;
      if((n-2)%3>0) q+=1;
      cout << p*q << endl;
   
   
   
   }





   return 0;
}
