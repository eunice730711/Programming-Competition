/*
Implementing dynamic cumulative frequency tables.
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

class FenwickTree{
	private: vi ft;
		int LSOne(int i){ return (i&-i);}
	public: FenwickTree(int n) {ft.assign(n+1,0);}
	int rsq(int b) //returns RSQ(1, b)
	{
		int sum=0;
		for(;b;b-=LSOne(b)) sum+=ft[b];
		return sum;
	}
	int rsq(int a,int b) //returns RSQ(a, b)
	{
		return rsq(b)-(a==1?0:rsq(a-1));
	}
	// adjusts value of the k-th element by v(v can be +ve/inc or -ve/dec)
	void adjust(int k,int v)
	{
		for(;k<(int)ft.size();k+=LSOne(k)) ft[k]+=v;
	}
	// using for testing
	void print(int idx)
	{
		cout << ft[idx] << endl;
	}
};
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		FenwickTree fn(n),fz(n);
		int a[100005];
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]<0) fn.adjust(i,1);
			else if(a[i]==0) fz.adjust(i,1);
		}
		for(int i=0;i<k;i++)
		{
			char com=' ';
			int idx,value;
			cin >> com >> idx >> value;
			if(com=='C')
			{
				if(a[idx]==0 && value!=0)
				{
					fz.adjust(idx,-1);
					if(value<0) fn.adjust(idx,1);
				}
				else if(a[idx]<0 && value>=0)
				{
					fn.adjust(idx,-1);
					if(value==0) fz.adjust(idx,1);
				}
				else if(a[idx]>0)
				{
					if(value==0) fz.adjust(idx,1);
					else if(value<0) fn.adjust(idx,1);
				}
				a[idx]=value;
			}
			else if(com=='P')
			{
				int zero=0,neg=0;
				zero=fz.rsq(idx,value);
				neg=fn.rsq(idx,value);
				if(zero>0) cout << 0;
				else if(neg%2) cout << '-';
				else cout << '+';
			}
		}
		cout << endl;
	}
}