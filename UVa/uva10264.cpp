#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int k = 1<<n;
		int w[65536],x[65536];	
		for(int i=0;i<k;i++) 
			cin >> w[i];
		memset(x,0,sizeof(x));
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++) //將每個位元flip一次得到相鄰點座標
			{
				x[i]+=w[i^(1<<j)];
			}
		}
		int ans=0;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<n;j++)
			{
				ans = max(ans,x[i]+x[i^(1<<j)]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}