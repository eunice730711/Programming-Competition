#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 10
bool vis[maxn];
int x[maxn],y[maxn],ans[maxn],t[maxn];
double dis[maxn][maxn];
double min_;
int n,casenum;
int sqr(int x)
{
    return x*x;
}
void dfs(int sum,int now,double s) ///路徑含sum個起點,路長為s,尾節點為now
{
    if(sum==n)
    {
        if(s<min_)
        {
            min_=s;
            for(int i=1; i<=n; i++) ans[i]=t[i];
        }
        return;
    }
    for(int i=1; i<=n; i++)
        if(!vis[i])
        {
            vis[i]=1;
            t[sum+1]=i;
            dfs(sum+1,i,s+dis[now][i]);
            vis[i]=0;
        }
}
void init()
{
    for(int i=1; i<=n; i++) cin>>x[i]>>y[i];
    memset(dis,0,sizeof(dis));
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            dis[i][j]=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))+16;
}
void solve()
{
    cout<<"**********************************************************"<<endl;
    cout<<"Network #"<< ++casenum <<endl;
    min_=1e10;
    dfs(0,0,0.0);
    for(int i=1; i<=n-1; i++)
    {
        cout<<"Cable requirement to connect ("<<x[ans[i]]<<",";
        cout<< y[ans[i]]<< ") to (" << x[ans[i+1]]<< "," << y[ans[i+1]] << ") is ";
                cout << dis[ans[i]][ans[i+1]] << " feet." << endl;
    }
        cout<< "Number of feet of cable required is "<<min_<<"."<<endl;

}
int main()
{
    ios::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(2);
    while(cin>>n&&n>0)
    {
        init();
        solve();
    }
    return 0;
}
