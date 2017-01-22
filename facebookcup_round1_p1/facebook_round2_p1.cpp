#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;
fstream outfile,infile;
int m,n;
long long int ans[305][305];
long long int p[305][305];
int dp()
{
	long long int money=0;
	for(int i=0;i<305;i++)
	{
		for(int j=0;j<305;j++)
		{
			ans[i][j]=100000000;
		}
	}
	for(int j=1;j<=m;j++) // first day
	{
		money+=p[1][j];
		ans[1][j]=money+j*j;
	}

	for(int i=2;i<=n;i++) // day
	{
		for(int j=i;j<=n;j++) // total bread
		{
			ans[i][j]=ans[i-1][j];
			money =0;
			for(int k=1;k<=m && j-k>=i-1;k++) // bread to take
			{
				money += p[i][k];
				ans[i][j]=min(ans[i][j],ans[i-1][j-k]+money+(k*k));
			}
		}
	}
	return ans[n][n];
}
int main()
{
	int t;
	//infile.open("pie_progress_example_input.txt",ios::in);
	//outfile.open("pie_progress_example_out.txt",ios::out);

	cin >> t;
	for(int cas=1;cas<=t;cas++)
	{	
		long long int total =0;
		memset(p,0,sizeof(p));
		
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin >> p[i][j];
			}
			sort(p[i],p[i]+m+1);
		}
		total = dp();
		cout << "Case #" << cas << ": " << total << endl;
	}
	return 0;
}