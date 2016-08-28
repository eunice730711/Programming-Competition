#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<utility>
#include<string.h>
#define MAXN 800
using namespace std;
typedef pair<double,double> ii;
int g[MAXN]={0};
vector<ii> ans;
int initial()
{
    for(int i=0; i<MAXN; i++) g[i]=i;
}
int Find(int a)
{
    if(g[a]!=a)
    {
        g[a]=Find(g[a]);
    }
    return g[a];
}
void Union(int a,int b)
{
    if(Find(a)!=Find(b))
    {
        g[g[a]]=g[b];
    }
}
void kruskal(priority_queue<pair<double,ii> > &pq)
{
    while(!pq.empty())
    {
        pair<double,ii> top=pq.top();
        pq.pop();
        int x=top.second.first,y=top.second.second;
        if(Find(x)!=Find(y))
        {
            Union(x,y);
            ans.push_back(ii(x,y));
        }
    }
}
double dist(double x1,double x2,double y1,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int cas;
    while(cin>>cas)
    {
        for(int c=0; c<cas; c++)
        {
            if(c) cout<<endl;
            memset(g,0,sizeof(g));
            ii pos[MAXN];
            ans.clear();
            priority_queue<pair<double,ii> > pq;
            int n;
            cin>>n;
            for(int i=1; i<=n; i++)
            {
                cin>>pos[i].first>>pos[i].second;
            }
            for(int i=1; i<=n-1; i++)
            {
                for(int j=i+1; j<=n; j++)
                {
                    double len=dist(pos[i].first,pos[j].first,pos[i].second,pos[j].second);
                    pq.push(make_pair(0.0-len,ii(i,j)));
                }
            }
            int m;
            cin>>m;
            initial();
            for(int i=0; i<m; i++)
            {
                int a,b;
                cin>>a>>b;
                Union(a,b);
            }
            kruskal(pq);
            if(ans.empty()) printf("No new highways need\n");
            else
            {
                for(int i=0; i<ans.size(); i++)
                {
                    cout<<ans[i].first<<' '<<ans[i].second<<endl;
                }
            }
        }
    }
    return 0;
}
