#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string.h>
using namespace std;
#define MAXN 505
#define INF 10000000
int map[505][505];
int dis[505][505];

void floy_dp(int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {

                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
}
int main()
{
    int cas;
    cin>>cas;
    for(int cc=0; cc<cas; cc++)
    {
        memset(dis,0,sizeof(dis));
        memset(map,0,sizeof(map));

        if(cc!=0) cout<<endl;
        int f=0,n=0,a=0,b=0,c=0;
        cin>>f>>n;
        int fire[105];
        for(int i=0; i<f; i++)
            cin>>fire[i];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                dis[i][j]=(i==j?0:INF);
            }
        }
        string str="";
        getline(cin,str);
        while(getline(cin,str) && !str.empty())
        {
            stringstream ss(str);
            ss>>a>>b>>c;
            dis[a][b]=c;
            dis[b][a]=c;
        }
        floy_dp(n);
        int path[505]= {0},dd=0;
        for(int i=1; i<=n; i++) ;
        for(int i=1; i<=n; i++)
        {
            path[i]=INF;
            for(int j=0; j<f; j++)
            {
                path[i]=min(path[i],dis[i][fire[j]]);
            }
            dd=max(dd,path[i]);
        }
        int ansd=0,ans=1;
        for(int i=1; i<=n; i++)
        {
            ansd=0;
            for(int j=1; j<=n; j++)
            {
                int s=min(dis[i][j],path[j]);
                ansd=max(s,ansd);
            }
            if(ansd<dd)
            {
                dd=ansd;
                ans=i;
            }
        }
        cout<<ans<<endl;
    }
}
