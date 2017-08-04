#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int g[200005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > edges;
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
//         cout << a << ' ' << b << endl;
         uni(a,b);
         sum+=weight;
      }
   }
   return sum;
}
int main()
{
   int n,m;
   while(cin >> n >> m)
   {
      if(!n&&!m) break;
      long long int total = 0;
      for(int i=0;i<m;i++)
      {
         int a,b,c;
         cin >> a >> b >> c;
         total +=c;
         edges.push(make_pair(c,make_pair(a,b)));
      }
      init(n);
      cout <<  total - kruskal() << endl;
   
   }




   return 0;
}
