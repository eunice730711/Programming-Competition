#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
int g[200005]= {0};
int num[200005]={0};
void ini(int n)
{
    for(int i=0; i<=n; i++)
    {
        g[i]=i;
        num[i]=1;
    }
}
int Find(int a)
{
    if(g[a]!=a)
    {
        g[a]=Find(g[a]);
    }
    return g[a];
}
int Union(int x,int y)
{
    if(Find(x)!=Find(y))
    {
        num[g[y]]+=num[g[x]];
        num[g[x]]=0;
        g[g[x]]=g[y];
    }
    return num[g[y]];
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        map<string,int> m;
        memset(g,0,sizeof(g));
        memset(num,0,sizeof(num));
        int n;
        cin>>n;
        ini(2*n);
        int c=1;
        for(int i=1; i<=n; i++)
        {
            string a,b;
            cin>>a>>b;
            if(m.count(a)<=0)
            {
                m.insert(pair<string,int>(a,c));
                c++;
            }
            if(m.count(b)<=0)
            {
                m.insert(pair<string,int>(b,c));
                c++;
            }

            int ga=m[a],gb=m[b];
            int ans=Union(ga,gb);
            cout<<ans<<endl;
        }
    }
    return 0;
}
