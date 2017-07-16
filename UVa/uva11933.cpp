#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;
int main()
{
	long long int n;
	while(cin >> n)
	{
		if(!n) break;
		bitset<35> bi(n);
		string str = bi.to_string();
		reverse(str.begin(),str.end());
		long long int sum=0;
		int idx=1;
		for(int i=0;i<str.length()+1;i++)
		{
			if(str[i]=='1')
			{
				if(idx%2) sum+=pow(2,i);
				idx+=1;
			}
		}
		cout << sum << ' ' << n-sum << endl;
	}
	return 0;
}