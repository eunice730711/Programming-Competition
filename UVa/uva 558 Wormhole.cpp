#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#define INF 100000000
using namespace std;
struct edge
{
    int cost,u,v;
};
edge edges[2005];
bool BellmenFord(int n,int m)
{
    int dis[1005];
    for(int i=0; i<n; i++)
    {
        if(i==0) dis[i]=0;
        else dis[i]=INF;
    }
    for(int i=0; i<=n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(dis[edges[j].v]>dis[edges[j].u]+edges[j].cost)
            {
                dis[edges[j].v]=dis[edges[j].u]+edges[j].cost;
            }
        }
    }
    for(int i=0; i<m; i++)
        if(dis[edges[i].v]>dis[edges[i].u]+edges[i].cost)
            return true;
    return false;
}
int main()
{
    int cas=0;
    cin>>cas;
    while(cas--)
    {
        memset(edges,0,sizeof(edges));
        int n,m;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>edges[i].u>>edges[i].v>>edges[i].cost;
        }
        bool check=false;
        if(BellmenFord(n,m)==true) cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}
