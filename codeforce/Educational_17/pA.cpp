#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
// #define MAX 100000000
// vector<int> prime;
// void sieve()
// {
// 	char map[MAX];
// 	memset(map,1,sizeof(map));
// 	map[0]=map[1]=0;
// 	for(int i=2;i<MAX;i++)
// 	{
// 		if(map[i])
// 		{
// 			for(int j=i*i;j<MAX;j+=i)
// 			{
// 				map[j]=0;
// 			}
// 		}
// 	}
// 	for(int i=0;i<MAX;i++)
// 	{
// 		if(map[i]) prime.push_back(i);
// 	}
// }
int main()
{
	long long int n, k;
	while(cin >> n >> k)
	{
		vector<long long int> ans;
		for(long long int i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				ans.push_back(i);
				ans.push_back(n/i);
			}
		}
		sort(ans.begin(),ans.end());
		if(k-1<ans.size()) cout << ans[k-1] << endl;
		else cout << "-1" << endl;
	}
	return 0;
}