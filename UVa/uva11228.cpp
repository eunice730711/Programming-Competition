#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
// fstream outfile,infile;
int g[1005];
int state=0;
priority_queue<pair<double,ii>,vector<pair<double,ii> >,greater<pair<double,ii> > > pq;
void init(int n)
{
   for(int i=0;i<n;i++)
      g[i]=i;
}
int find(int a)
{
   if(g[a]!=a)
      g[a]=find(g[a]);
   return g[a];
}
void uni(int a,int b)
{
   if(find(a)!=find(b))
   {
      g[g[b]]=g[a];
   }
}
ii kruskal(int r)
{
   double ans=0,sum=0;
   while(!pq.empty())
   {
      pair<double,ii> tmp = pq.top();
      //if(tmp.first > (double)r) break;
      pq.pop();
      double w = tmp.first;
      int a = tmp.second.first, b = tmp.second.second;
      if(find(a)!=find(b)) 
      {
         if(w > r)
         {
            sum+= w;
            state +=1;
         }
         else ans +=w;
         uni(a,b);
      }
    }
   return ii(round(ans),round(sum));
}
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      int n,r;
      state=0;
      vector<ii> v;
      cin >> n >> r;
      pq = priority_queue<pair<double,ii>,vector<pair<double,ii> >,greater<pair<double,ii> > >();

      for(int i=0;i<n;i++)
      {
         int x,y;
         cin >> x >> y;
         v.push_back(ii(x,y));
      }
      init(n);
      double dis=0;
      for(int i=0;i<n;i++)
      {
         int x,y;
         x = v[i].first;
         y = v[i].second;
         for(int j=i+1;j<n;j++)
         {
              int a,b;
              a = v[j].first;
              b = v[j].second;
              dis = sqrt((a-x)*(a-x)+(b-y)*(b-y));
              pq.push(make_pair(dis,ii(i,j)));
         }
      }
      ii ans = kruskal(r);
      cout << "Case #" << c << ": " << state+1 << ' ' << ans.first << ' ' << ans.second << endl;
      //pq = priority_queue<pair<int,ii>,vector<pair<int,ii> >,greater<pair<int,ii> > >();

   
   }




   return 0;
}
