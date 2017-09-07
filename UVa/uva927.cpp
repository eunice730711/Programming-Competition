#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int test;
	scanf("%d", &test);
	for(int cc=0;cc<test;cc++)
	{
		long long int c[25];
		long long int n,ans=0;
		scanf("%lld", &n);
		for(int i=0;i<=n;i++)
		{
			scanf("%lld", &c[i]);
		}
		double d,k;
		cin >> d >> k;
		double idx=0;
		double ansidx = 2*k/d;
		// cout << double(ansidx) << endl;
		while((idx*idx+idx)<ansidx)
		{
			idx+=1;
		}
		// cout <<"idx: "<< idx << endl;
		for(int i=0;i<=n;i++)
		{
			ans+=c[i]*pow(idx,i);
		}
		printf("%lld\n",ans);
	}




	return 0;
}