#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
bool schedule[1000005];
//bitset<1000005> schedule(0);
int n,m;
bool CheckConflict(int a[],int b[],int r[],int c[],int d[])
{
	for(int i=0;i<n;i++)
	{
		int start = a[i], end = b[i];
		for(int j=start+1;j<=end;j++)
		{
			if(schedule[j]) return true;
			schedule[j]=true;
		}

	}
	for(int i=0;i<m;i++)
	{
		int mytime = c[i],end = d[i], interval=r[i];
		while(mytime<1000000)
		{
			for(int j=mytime+1;j<=end;j++)
			{
				if(schedule[j]) return true;
				schedule[j]=true;
			}
			mytime+=interval;
			end = min(1000000,end+interval);
		}
	}
	return false;
}
int main()
{
	while(cin >> n >> m)
	{
		//schedule.reset();
		memset(schedule,false,sizeof(schedule));
		int a[105],b[105],r[105],c[105],d[105];
		if(!n && !m) break;
		for(int i=0;i<n;i++)
		{
			cin >> a[i] >> b[i];
		}
		for(int i=0;i<m;i++)
		{
			cin >> c[i] >> d[i] >> r[i];
		}
		if(CheckConflict(a,b,r,c,d)) cout << "CONFLICT" << endl;
		else cout << "NO CONFLICT" << endl;

	}
	return 0;
}