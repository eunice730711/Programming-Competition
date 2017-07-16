#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
map<char,bool> vis;
vector<char> nodes;
vector<vector<char> >edges;
bool check(char ch)
{
	for(int i=0;i<edges[ch].size();i++)
	{
		if(vis[edges[ch][i]]) return false;
	}
	return true;
}
bool backtracking(string path)
{	
	if(path.length()==nodes.size())
	{
		printf("%c",path[0]);
		for(int i=1;i<path.length();i++)
		{
			printf(" %c",path[i]);
		}
		printf("\n");
		return true;
	}
	bool ans = false;
	for(int i=0;i<nodes.size();i++)
	{
		if(!vis[nodes[i]])
		{
			if(check(nodes[i]))
			{
				vis[nodes[i]]=true;
				ans = backtracking(path+nodes[i]) | ans;
				vis[nodes[i]]=false;
			}
		}
	}
	return ans;	
}
int main()
{
	int cas;
	scanf("%d\n\n",&cas);
	for(int c=0;c<cas;c++)
	{
		if(c) cout << endl;
		vis.clear();
		nodes.clear();
		string line = "";
		string node="",cons="";
		getline(cin,node);
		getline(cin,cons);
		for(int i=0;i<node.length();i++)
		{
			if(node[i]!=' ') nodes.push_back(node[i]);
		}
		sort(nodes.begin(),nodes.end());
		edges.clear();
		edges.resize(256);
		for(int i=0;i<cons.length();i++)
		{
			if(cons[i]=='<')
			{
				edges[cons[i-1]].push_back(cons[i+1]);
			}
		}
		if(!backtracking("")) cout << "NO" << endl;
		if(!getline(cin, line)) break;
	}
}