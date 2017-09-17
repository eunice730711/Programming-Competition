#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,m;
pair<int,int> s,d;
vector<pair<int,int> > v;
map<int,bool> vis;
bool dfs(int s,int count)
{
  // cout <<"s: "<< s << endl;
  // cout <<"count: " << count << endl;
   if(count==n && s==d.first)
   {
      //cout << "in" << endl;
      return true;
   }
   for(int i=0;i<m;i++)
   {  
      if(!vis[i])
      {
         if(v[i].first==s)
         {
            vis[i]=true;
            if(dfs(v[i].second,count+1)) return true;
            vis[i]=false;
         }
         else if(v[i].second==s)
         {
            vis[i]=true;
            if(dfs(v[i].first,count+1)) return true;
            vis[i]=false;
         }
      }
   }
   return false;
}
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(scanf("%d",&n)!=EOF)
   {
      if(!n) break;
      scanf("%d",&m);
      scanf("%d%d",&s.first,&s.second);
      scanf("%d%d",&d.first,&d.second);
      vis.clear();
      v.clear();
      for(int i=0;i<m;i++) 
      {
         pair<int,int> tmp;
         scanf("%d%d",&tmp.first,&tmp.second);
         v.push_back(tmp);
      }
      bool ans=dfs(s.second,0);
      if(ans) printf("YES\n");
      else printf("NO\n");
      

   }
   return 0;
}
