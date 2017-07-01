#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int s,b;
	while(scanf("%d%d",&s,&b)!=EOF)
	{
		if(s==0 && b==0) break;
		int rs[100005],ls[100005];
		for(int i=1;i<=s;i++)
			ls[i]=i-1,rs[i]=i+1;
		ls[0]=rs[0]=rs[s]=0;
		for(int i=0;i<b;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(ls[l]==0) printf("*");
			else printf("%d",ls[l]);
			if(rs[r]==0) printf(" *\n");
			else printf(" %d\n",rs[r]);
			rs[ls[l]]=rs[r];
			ls[rs[r]]=ls[l]; 
		}
		printf("-\n");
	}
	return 0;
}