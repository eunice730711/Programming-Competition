#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main()
{
   int n,m;
   while(cin >> n >> m)
   {
      if(!n && !m) break;
      map<int,int> cd;
      for(int i=0;i<n;i++)
      {
         int tmp;
         cin >> tmp;
         cd[tmp]+=1;
      }
      int ans=0;
      for(int i=0;i<m;i++)
      {
         int tmp;
         cin >> tmp;
         if(cd[tmp]) ans++;
      }
      cout << ans << endl;
   }




   return 0;
}
