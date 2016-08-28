#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int g[100];
int Find(int a)
{
    if(g[a]!=a)
    {
        g[a]=Find(g[a]);
    }
    return g[a];
}
bool Union(int a,int b)
{
    if(Find(a)==Find(b)) return true;
    else
    {
        g[g[a]]=g[b];
        return false;
    }
}
int main()
{
    int n,e;
    map<char,int> m;
    char tmp1='A',tmp2='a';
    for(int i=1; i<=26; i++)
    {
        m[tmp1]=i;
        tmp1++;
    }
    for(int i=27; i<=52; i++)
    {
        m[tmp2]=i;
        tmp2++;
    }
    while(scanf("%d%d",&n,&e)!=EOF)
    {
        memset(g,0,sizeof(g));
        for(int i=1; i<=55; i++)
        {
            g[i]=i;
        }
        int face=0;
        for(int i=0; i<e; i++)
        {
            char in1,in2;
            cin>>in1>>in2;
            int u=m[in1],v=m[in2];
            if(Union(u,v)==true) face++;
        }
        printf("%d\n",face+1);
    }
    return 0;
}
