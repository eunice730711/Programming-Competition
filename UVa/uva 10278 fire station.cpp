#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
    int b=0,d=10000000;
};
Node nodes[505];
bool operator < (const Node &a,const Node &b){return a.d<b.d;}
int dij(Node source,int in)
{
    bool vis[505]={false};
    int d[505];
    for(int i=1;i<=in;i++) d[i]=100000000;
    priority_queue<Node> pq;
    d[source]=0;
    sourcr.d=0;
    pq.push(source);
    while(!pq.empty())
    {

    }


}


int main()
{
    int cas=0;
    scanf("%d",&cas);
    while(cas--)
    {
        int f=0,in=0,fire[105]={0},adj[505][505]={{0}};
        scanf("%d%d",&f,&in);
        for(int i=0;i<f;i++)
        {
            scanf("%d",&fire[i]);
        }
        for(int i=1;i<=in;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            adj[a][b]=c;
        }
    }



    return 0;

}
