#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
   int n;
   while(cin >> n)
   {
      if(n==0) break;
      string ans[55];
      bool vis[55];
      memset(vis,false,sizeof(vis));
      vector<pair<string,string> >vec;
      for(int i=0;i<n;i++) 
      {
         pair<string,string> p;
         cin >> p.first >> p.second;
         vec.push_back(p);
      }
      int index=0;
      for(int i=0;i<n;i++)
      {
         pair<string,string> p;
         p = vec[i];
         string steps = p.second;
         string card = p.first;
         int len = steps.length();
         int count=1;
         while(count<=len)
         {
            if(vis[index]) 
            {
               if(index==n-1) index-=n;
               index++;
               continue;
            }
            if(count == len) 
            {
               ans[index]=card;
               vis[index]=true;
               if(index==n-1) index-=n;
               index++;
               break;
            }
            if(!vis[index])
            {
               if(index==n-1) index-=n;
               index++;
               count++;
            }
         }
      }
   cout << ans[0];
   for(int i=1;i<n;i++)
   {
      cout << ' ' << ans[i];
   
   }
   cout << endl;
   
   
   }


   return 0;
}
