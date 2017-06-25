#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int c=1;c<=t;c++)
	{
		int n,max=0;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			int speed;
			cin >> speed;
			if(speed>max) max=speed;			
		}
		cout << "Case " << c << ": " << max << endl;
	}
	return 0;
}
