#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
	int n,l;
	


	while(cin >> n >> l)
	{
		vector<int> arr1,arr2;
		deque<int> d1,d2;
		for(int i=0;i<n;i++)
		{
			int num,dis=0;
			cin >> num;
			arr1.push_back(num);
			if(i!=0) dis=arr1[i]-arr1[i-1],d1.push_back(dis);
			
		}
		d1.push_back(arr1[0]-0+l-arr1[n-1]);
		for(int i=0;i<n;i++)
		{
			int num,dis=0;
			cin >> num;
			arr2.push_back(num);
			if(i!=0) dis=arr2[i]-arr2[i-1],d2.push_back(dis);
			
		}
		d2.push_back(arr2[0]-0+l-arr2[n-1]);
		int times=n;
		bool ok = true;
		while(times--)
		{
			ok = true;
			deque<int>::iterator it2 = d2.begin();
			for(deque<int>::iterator it1 = d1.begin();it1!=d1.end();it1++)
			{
				if(*it2 != *it1)
				{
					ok = false;
					break;
				}
				it2++;
			}
			if(ok) break;
			int first = d2.front();
			d2.pop_front();
			d2.push_back(first);
		}
		if(ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}