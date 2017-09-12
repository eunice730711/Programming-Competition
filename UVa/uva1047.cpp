#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
int n,m;
bool vis[25];
vector<int> ans,comp;
map<int,int> people;
int maxn=0;
vector<vector<int> > common;

int compute(vector<int> &v)
{
   int sum = 0;
   for(int i=0;i<v.size();i++) sum+=people[v[i]];
   for(int i=0;i<comp.size();i++)
   {
      vector<int> inter;
      set_intersection(v.begin(),v.end(),common[i].begin(),common[i].end(),back_inserter(inter)); 
      if(inter.size()>1) sum-=(comp[i])*(inter.size()-1);
   }
   return sum;
}
void backtracking(int s,vector<int> &v)
{
   if(v.size() == m) {
      int sum = compute(v);
      if(sum > maxn)
      {
         maxn = sum;
         ans = v;
      }
   }
   for(int i=s+1;i<=n;i++)
   {
      if(!vis[i])
      {
         v.push_back(i);
         vis[i]=true;
         backtracking(i,v);
         vis[i]=false;
         v.pop_back();
      }
   }
}
int main()
{
   int cas=1;
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
   while(scanf("%d %d",&n,&m)!=EOF)
   {
      memset(vis,false,sizeof(vis));
      common.clear();
      ans.clear();
      comp.clear();
      maxn=0;
      people.clear();
      map<vector<int>, int> check;
      if(!n && !m) break;
      for(int i=1;i<=n;i++)
      {
         int tmp;
         scanf("%d",&tmp);
         people[i]=tmp;
      }
      int k;
      scanf("%d",&k);
      for(int i=0;i<k;i++)
      {
         int t,popu;
         scanf("%d",&t);
         vector<int> com;
         for(int j=0;j<t;j++)
         {
            int tower;
            scanf("%d",&tower);
            com.push_back(tower);
         }
         sort(com.begin(),com.end());
         common.push_back(com);
         scanf("%d",&popu);
         comp.push_back(popu);
      }
      vector<int> v;
      backtracking(0,v);
      printf("Case Number  %d\n",cas++);
      printf("Number of Customers: %d\n",maxn);
      printf("Locations recommended:");
      for(int i=0;i<m;i++) printf(" %d",ans[i]);
      printf("\n\n");
   }
   return 0;
}
