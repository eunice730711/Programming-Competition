#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      int max=0;
      vector<pair<string,int> > v;
      for(int i=0;i<10;i++)
      {
         string str;
         int vote;
         cin >> str >> vote;
         v.push_back(make_pair(str,vote));
         if(vote>max) max = vote;
      }
      cout << "Case #" << c << ":" << endl;
      for(int i=0;i<10;i++)
      {
         if(v[i].second==max) cout << v[i].first << endl;
      }
   }
   return 0;
}
