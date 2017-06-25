#include <iostream>
#include <cmath>
using namespace std;
int compute(int n)
{
   int k;
   k = (((n*567)/9 + 7492)*235)/47 - 498;
   return abs((k/10)%10);
}
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      int n;
      cin >> n;
      cout << compute(n) << endl;
   
   }


   return 0;
}
