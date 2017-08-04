#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
vector<int> dfs_num,dfs_low,dfs_parent;
vector<vector<int> > edges;
vector<ii> bridges;
int count_=1;
void bridge(int u)
{
   dfs_num[u]=dfs_low[u]=count_++;
   for(int i=0;i<edges[u].size();i++)
   {
      int v = edges[u][i];
      if(!dfs_num[v])
      {
         dfs_parent[v]=u;
//         if(u == root) child++;
         bridge(v);
         if(dfs_low[v] > dfs_num[u])
         {
            ii k = u<v ? ii(u,v):ii(v,u);
            bridges.push_back(k);
         }
         dfs_low[u] = min(dfs_low[u],dfs_low[v]);
      }
      else if(v != dfs_parent[u])
      {
         dfs_low[u] = min(dfs_low[u],dfs_num[v]);
      }
   }
}
int main()
{
   int n;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   while(scanf("%d",&n)!=EOF)
   {
      //if(!n) break;
      count_=1;
      dfs_num.assign(n+1,0);
      dfs_low.assign(n+1,0);
      dfs_parent.assign(n+1,0);
      edges.reserve(n+1);
      for(int i=0;i<n;i++) edges[i].clear();
      bridges.clear();

      for(int i=0;i<n;i++)
      {
         int idx,nodes;
         scanf("%d (%d)",&idx,&nodes);
      //   cout << idx << ' ' << nodes << endl;
         for(int j=0;j<nodes;j++)
         {
            int tmp;
            scanf("%d",&tmp);
            edges[idx].push_back(tmp);
         }
      }
      for(int i=0;i<n;i++)
      {
        if(!dfs_num[i]) bridge(i);
      }
      //cout << "low: " << endl;
      //for(int i=0;i<n;i++) cout << i << ' ' << dfs_low[i] << endl;
      //cout << endl;
      sort(bridges.begin(),bridges.end());
      printf("%d critical links\n",(int)bridges.size());
      for(int i=0;i<bridges.size();i++)
      {
         printf("%d - %d\n",bridges[i].first, bridges[i].second);
      }
      printf("\n");
   }


   return 0;
}
