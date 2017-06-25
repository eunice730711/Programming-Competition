/*
注意有孤立節點且不知道編號大小範圍(可用map對應)
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
using namespace std;
vector<int> edges[35];
bool vis[35];
set<int> nodes;
map<int,int> depths,ind;
int cas=1;
void bfs(int start)
{
   memset(vis,false,sizeof(vis));
   queue<pair<int,int> > q;
   q.push(make_pair(start,0));
   vis[start]=true;
   while(!q.empty())
   {
      int node = q.front().first, depth = q.front().second;
      q.pop();
      for(int i=0;i<edges[node].size();i++)
      {
      	if(!vis[edges[node][i]])
      	{
      	 	q.push(make_pair(edges[node][i],depth+1));
      		depths[edges[node][i]]=depth+1;
      		vis[edges[node][i]]=true;
      	}
      }
   }
}
int main()
{
   int n;
   while(cin >> n)
   {
      
      if(n==0) break;
      memset(vis,false,sizeof(vis));
      nodes.clear();
      int idx=1;
      ind.clear();
      for(int i=0;i<35;i++) edges[i].clear();
      for(int i=0;i<n;i++)
      {
         int a,b;
         cin >> a >> b;
         if(ind[a]==0)
         {
         	ind[a]=idx;
         	nodes.insert(idx);
         	idx++;
         }
         if(ind[b]==0)
         {
         	ind[b]=idx;
         	nodes.insert(idx);
         	idx++;
         }
         edges[ind[a]].push_back(ind[b]);
         edges[ind[b]].push_back(ind[a]);
      }
      int p,q;
      while(cin >> p >> q)
      {
         if(p==0 && q==0) break;
         depths.clear();
         bfs(ind[p]);
         int ans=0;
         for(set<int>::iterator it=nodes.begin();it!=nodes.end();it++)
         {
         	if((depths[*it]>q || depths[*it]==0 ) && (*it!=ind[p])) ans++;
         }
         printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cas++,ans,p,q);
      }
   }
   return 0;
}
