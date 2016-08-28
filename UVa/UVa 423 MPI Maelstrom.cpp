#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#define INF 100000
using namespace std;
int dis[105][105];
int initial(int n)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) dis[i][j]=(i==j)?0:INF;
}
int Floyd(int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
}
int main()
{
    int n;
    while(cin>>n)
    {

        char str[100];
        initial(n);
        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<i; j++)
            {
                cin>>str;
                if(str[0]!='x')
                {
                    int tmpi=atoi(str);
                    dis[i][j]=tmpi;
                    dis[j][i]=tmpi;
                }
            }
        }
        Floyd(n);
        int ans=0;
        for(int i=2;i<=n;i++)
        {
            ans=max(dis[1][i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}
