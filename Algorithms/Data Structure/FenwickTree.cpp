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
	int f[]={2,4,5,5,6,6,6,7,7,8,9};
	FenwickTree ft(10);
	for(int i=0;i<11;i++) ft.adjust(f[i],i);
	cout << ft.rsq(1,6) << endl;
	return 0;
}