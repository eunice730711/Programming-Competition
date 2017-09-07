#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int test;
	cin >> test;
	bool first = true;
	while(test--)
	{
		if(!first) cout << endl;
		first = false;
		int n;
		cin >> n;
		pair<int,int> dataset[10005];
		map<int,string> names;
		for(int i=0;i<n;i++)
		{
			string str;
			int a,b;
			cin >> str >> a >> b;
			names[i]=str;
			dataset[i].first = a;
			dataset[i].second = b;
		}
		int q;
		cin >> q;
		for(int i=0;i<q;i++) 
		{
			int ask;
			cin >> ask;
			int count=0;
			string ans="";
			for(int j=0;j<n;j++)
			{
				if(ask>=dataset[j].first && ask<=dataset[j].second)
				{
					count++;
					ans = names[j];
				}
				if(count>1) break;
			}
			if(count>1 || count==0) cout << "UNDETERMINED" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}