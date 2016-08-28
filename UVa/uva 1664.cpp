#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int g[200005];

void ini(int n)
{
    for(int i=1;i<=n;i++)
    {
        g[i]=i;
    }
}
int Find(int x)
{
    if(g[x]!=x)
    {
        g[x]=Find(g[x]);
    }
    return g[x];
}
int Union(int x,int y)
{
    if(Find(x)!=Find(y))
    {
        g[g[x]]=g[y];
    }
}


struct node
{
    int num=0;
    long long int sum=0;
};
struct edge
{
    int u=0,v=0,w=0;
    friend bool operator < (edge a,edge b);
};
bool operator < (edge a,edge b)
{
    return a.w>b.w;
}
edge edges[200005];
node no[200005];
int main()
{
    int n;
    while(cin>>n)
    {
        memset(g,0,sizeof(g));
        ini(n);

        for(int i=1; i<n; i++)
        {
            cin>>edges[i].u>>edges[i].v>>edges[i].w;
        }
        sort(edges+1,edges+n);

        for(int i=1;i<=n;i++)
        {
            no[i].sum=0;
            no[i].num=1;
        }

        for(int i=1;i<n;i++)
        {
            int xx=Find(edges[i].u);
            int yy=Find(edges[i].v);
            if(no[xx].sum+(long long int)no[yy].num*edges[i].w > no[yy].sum+(long long int)no[xx].num*edges[i].w)
            {
                g[yy]=xx;
                no[xx].num+=no[yy].num;
                no[xx].sum+=(long long int)no[yy].num*edges[i].w;
            }
            else
            {
                g[xx]=yy;
                no[yy].num+=no[xx].num;
                no[yy].sum+=(long long int)no[xx].num*edges[i].w;
            }
        }
        cout << no[ Find(1) ].sum << endl;
    }
    return 0;
}
