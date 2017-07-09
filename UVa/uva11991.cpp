#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
   int m,n;
   while(cin >> n >> m)
   {
      //vector<int> edges[1000005];
      map<int,vector<int> > edges;
      for(int i=1;i<=n;i++)
      {
         int tmp;
         cin >> tmp;
         edges[tmp].push_back(i);
      }
      for(int i=0;i<m;i++)
      {
         int k,v;
         cin >> k >> v;
         if(edges[v].size()>=k) cout << edges[v][k-1] << endl;
         else cout << '0' << endl;
         
      }
   }




   return 0;
}
