#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int n;
   cin >> n;
   for(int i=1;i<=n;i++)
   {
      int a,b,c;
      cin >> a >> b >> c;
      if(a<=20 && b<=20 && c<=20) cout << "Case " << i << ": " << "good" << endl;
      else cout << "Case " << i << ": " << "bad" << endl;
   
   }



   return 0;
}
