#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int main()
{
   int k;
   vector<int> v;
   map<int,bool> vis;
   map<int,int> m;
   while(cin >> k) 
   {
      //if(k==0) break;
      v.push_back(k);
      m[k]++;
      vis[k]=false;
   }
   for(int i=0;i<v.size();i++)
   {
      int num = v[i];
      if(!vis[num]) 
      {
         cout << num << ' ' << m[num] << endl;
         vis[num]=true;
      }
   }
   




   return 0;
}
