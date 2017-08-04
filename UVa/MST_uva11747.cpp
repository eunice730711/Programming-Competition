#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int g[200005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > edges;
vector<int> ans;
void init(int n)
{
   for(int i=0;i<n;i++)
      g[i]=i;
}
int find(int a)
{
   if(g[a]!=a)
      g[a] = find(g[a]);
   return g[a];
}
void uni(int a,int b)
{
   if(find(a)!=find(b))
      g[g[b]]=g[a];
}
long long int kruskal()
{
   long long int sum=0;
   while(!edges.empty())
   {
      int weight=edges.top().first;
      int a = edges.top().second.first;
      int b = edges.top().second.second;
      edges.pop();
      if(find(a)!=find(b))
      {
         uni(a,b);
         sum+=weight;
      }
      else ans.push_back(weight);
   }
   return sum;
}
int main()
{
   int n,m;
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
   while(scanf("%d%d",&n,&m))
   {
      ans.clear();
      if(!n&&!m) break;
      long long int total = 0;
      for(int i=0;i<m;i++)
      {
         int a,b,c;
         scanf("%d%d%d",&a,&b,&c);
         total +=c;
         edges.push(make_pair(c,make_pair(a,b)));
      }
      init(n);
      kruskal();
      // cout <<  kruskal() << endl;
      sort(ans.begin(),ans.end());
      if(ans.size()==0) printf("forest\n");
      else
      {
         printf("%d",ans[0]);
         for(int i=1;i<ans.size();i++) printf(" %d",ans[i]);
         printf("\n");
      }
   }
   return 0;
}
