#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int m,n,k;
vector<int> edges[100005];
bool vis[1005];
void dfs(int s,set<int> &home,int path)
{
	if(vis[s]) return;
	home.insert(s);
	vis[s]=true;
	for(int i=0;i<edges[s].size();i++)
	{
		path+=1;
		dfs(edges[s][i],home,path);
	}
}
int main()
{
	while(cin >> n >> m >> k)
	{
		memset(vis,false,sizeof(vis));
		vector<int> cities;
		for(int i=0;i<k;i++)
		{
			int c;
			cin >> c;
			cities.push_back(c);
		}
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin >> a >> b;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		vector<int> gov;
		int maxn=-1,edge_num=0,idx=0;
		for(int i=0;i<k;i++)
		{
			set<int> s;
			int path =0;
			dfs(cities[i],s,path);
			int com = (s.size()*(s.size()-1)/2)-path/2;
			if(com > maxn)
			{
				maxn = com;
				idx = i;
			}
			gov.push_back(s.size());
		}
		int noconnect=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]) noconnect+=1;
		}
		for(int i=0;i<k;i++)
		{
			if(i == idx) gov[i]+=noconnect;
			edge_num+=gov[i]*(gov[i]-1)/2;
		}
		cout << edge_num - m << endl;
	}
   return 0;
}
