/*
codeforce #20C
print the shortest path
This is Dijkstra more fast version
*/
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAXN 100005
#define mk make_pair
using namespace std;
typedef pair<int,int> ii;
vector<ii> edges[MAXN];
int parent[MAXN];
bool vis[MAXN];
void print(int i)
{
	if(!i) return;
	print(parent[i]);
	printf("%d ",i);
}
void dijkstra(int s, int t)
{
	priority_queue<pair<int,ii> > pq;
	pq.push(mk(0,ii(s,0)));
	while(!pq.empty())
	{
		int node = pq.top().second.first;
		int d = pq.top().first, p = pq.top().second.second;
		pq.pop();
		if(vis[node]) continue;
		vis[node] = true;
		parent[node] = p;

		for(int i=0;i<edges[node].size();i++)
		{
			ii x = edges[node][i];
			if(!vis[x.first])
			{
				pq.push(mk(d-x.second,ii(x.first,node)));
			}
		}
	}
	if(!parent[t]) printf("-1\n");
	else print(t);

}
int main()
{
	int m,n;
	while(cin >> m >> n)
	{
		memset(vis,false,sizeof(vis));
		memset(parent,0,sizeof(parent));
		for(int i=0;i<n;i++) edges[i].clear();
		for(int i=0;i<n;i++)
		{
			int a,b,w;
			cin >> a >> b >> w;
			edges[a].push_back(ii(b,w));
			edges[b].push_back(ii(a,w));
		}
		dijkstra(1,m);
		cout << endl;
	}
	return 0;
}