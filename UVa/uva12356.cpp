#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int s,b;
	while(cin >> s >> b)
	{
		if(s==0 && b==0) break;
		int rs[100005],ls[100005];
		for(int i=1;i<=s;i++)
			ls[i]=i-1,rs[i]=i+1;
		ls[0]=rs[0]=rs[s]=0;
		for(int i=0;i<b;i++)
		{
			int l,r;
			cin >> l >> r;
			if(ls[l]==0) cout << '*';
			else cout << ls[l];
			if(rs[r]==0) cout << ' ' << '*' << endl;
			else cout << ' ' << rs[r] << endl;
			rs[ls[l]]=rs[r];
			ls[rs[r]]=ls[l]; 
		}
		cout << '-' << endl;
	}
	return 0;
}