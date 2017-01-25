#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
int main()
{
	priority_queue<pair<int,string>,vector<pair<int,string> >,greater<pair<int,string> > > pq;
	int usb=0,ps=0,two=0;
	while(cin >> usb >> ps >> two)
	{
		int n;
		cin >> n;
		for(int i=0;i<n;i++) 
		{
			int tmp=0;
			string type="";
			cin >> tmp >> type;
			pq.push(make_pair(tmp,type));
		}
		long long int sum=0, num=0;
		while(!pq.empty())
		{
			pair<int,string> tmp;
			tmp = pq.top();
			if(tmp.second == "USB")
			{
				if(usb >0)
				{
					usb-=1;
					sum += tmp.first;
					num++;
				}
				else if(two>0)
				{
					two-=1;
					sum += tmp.first;
					num++;
				}

			}
			else if(tmp.second == "PS/2")
			{
				if(ps >0)
				{
					ps-=1;
					sum += tmp.first;
					num++;
				}
				else if(two>0)
				{
					two-=1;
					sum += tmp.first;
					num++;
				}
			}
			if(usb==0 && ps==0 && two==0) break;
			pq.pop();
		}
		cout << num << ' ' << sum << endl;

	}
	return 0;
}