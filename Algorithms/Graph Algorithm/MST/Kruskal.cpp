/*
Uva908: Kruskal Algorithm / HEAP
題目給予一個建好得MST，再新增一些edge，重建一顆新的MST
印出舊的MST的cost和新的MST的cost
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int,int> ii;
#define MAXN 1000005
int g[MAXN];
void ini(int n)
{
    for(int i=1; i<=n; i++)
    {
        g[i]=i;
    }
}
int Find(int a)
{
    if(a!=g[a]) g[a]=Find(g[a]);
    return g[a];
}
void Union(int a,int b)
{
    if(Find(a)!=Find(b))
    {
        g[g[a]]=g[b];
    }
}
int Kruskal(priority_queue<pair<int,ii> > &ppq)
{
    int cost=0;
    while(!ppq.empty())
    {
        pair<int,ii> tmp=ppq.top();
        ppq.pop();
        if(Find(g[tmp.second.first])!=Find(g[tmp.second.second]))
        {
            cost += (0 - tmp.first);
            Union(tmp.second.first,tmp.second.second);
        }
    }
    return cost;
}
int main()
{
    int n=0, flag=0;
    while(cin >>n)
    {
        int k,m;
        int a,b,c,ans1=0,ans2=0;
        memset(g,-1,sizeof(g));
        ini(n);
        for(int i=0; i<n-1; i++)
        {
            cin >> a >> b >> c;
            ans1 += c;
        }
        priority_queue<pair<int,ii> > pq;
        cin >> k;
        for(int i=0; i<k; i++)
        {
            cin >> a >> b >> c;
            pq.push(make_pair(0-c,make_pair(a,b)));
        }
        cin >> m;
        for(int i=0; i<m; i++)
        {
            cin >> a >> b >> c;
            pq.push(make_pair(0-c,make_pair(a,b)));
        }
        if(flag == 1) cout<<endl;
        flag = 1;
        ans2 = Kruskal(pq);
        cout << ans1 << endl << ans2 << endl;
    }
    return 0;
}
