#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b;
	while(cin >> a >> b)
	{
		if((a == b) && a == 0 && b==0) cout << "NO" << endl;
		else if(a==b || abs(a-b)==1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}