#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int main(){
	int i,j,k,l,n,m,a[200],b[200];
	cin>>n>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	for(i=0;i<n;i++) {
		for(j=1;j<n;j++) {
			cout << (a[i]-b[0]+m)%m << ' ' << (a[(j+i)%n]-b[j]+m)%m << endl;
			if((a[i]-b[0]+m)%m!=(a[(j+i)%n]-b[j]+m)%m)
			{
				cout << endl;
				break;
			}
		}
		if(j==n) {
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}