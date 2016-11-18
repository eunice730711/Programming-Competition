/*
uva10034:
給座標找MST
Implementation: Prim algorithm using HEAP data structure
*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#define INF 1e9
using namespace std;
typedef pair<double,double> dd;
vector<pair<int,double> > edges[105];
double d[105];
bool vis[105];
int n;
double prim()
{
	for(int i=0;i<n;i++) d[i]=INF,vis[i]=false;
	priority_queue<pair<double,int> ,vector<pair<double,int> >, greater<pair<double,int> > >  pq; //d[index] & index
	d[0] = 0;
	int u = -1;
	double ans = 0;
	pq.push(make_pair(d[0],0)); // value = 0 / root node index =0
	while(!pq.empty())
	{	
		u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		ans += d[u];
		vis[u]=true;
		for(int i=0;i<edges[u].size();i++)
		{
			if(!vis[edges[u][i].first] && edges[u][i].second < d[edges[u][i].first])
			{
				d[edges[u][i].first] = edges[u][i].second;
				pq.push(make_pair(d[edges[u][i].first],edges[u][i].first));
			}
		}
	}
	return ans;
}
int main()
{
	int test;
	cin >> test;
	bool first = true;
	while(test--)
	{
		for(int i=0;i<n;i++) edges[i].clear();
		dd points[105];
		if(!first) printf("\n");
		first = false;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			cin >> points[i].first >> points[i].second;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				double d;
				d = sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first) + (points[i].second-points[j].second)*(points[i].second-points[j].second));
				edges[i].push_back(make_pair(j,d));
			}
		}
		double ans = prim();
		printf("%.2lf\n",ans);
	}
	return 0;
}