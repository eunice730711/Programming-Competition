#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n,k;
bool G[35][35];
int d[35];
struct Box
{
    int ind=0;
    int len[15]= {0};
    friend bool operator < (Box a,Box b);
};
bool operator < (Box a,Box b)
{
    sort(a.len,a.len+n);
    sort(b.len,b.len+n);
    for(int i=0; i<n; i++)
    {
        if(a.len[i]>=b.len[i]) return false;
    }
    return true;
}
int dp(int i)
{
    if(d[i]>0) return d[i];
    d[i]=1;
    for(int j=1; j<=k; j++)
    {
        if(G[i][j]) d[i]=max(d[i],dp(j)+1);
    }
    return d[i];
}
void printans(int i)
{
    printf("%d ",i);
    for(int j=1; j<=k; j++) if(G[i][j] && d[i]==d[j]+1)
        {
            printans(j);
            break;
        }
}
int main()
{
    while(cin>>k>>n)
    {
        Box boxes[35];
        memset(G,false,sizeof(G));
        memset(d,0,sizeof(d));
        for(int i=1; i<=k; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>boxes[i].len[j];
            }
        }
        for(int i=1; i<=k; i++)
            for(int j=1; j<=k; j++)
                if(boxes[i]<boxes[j]) G[i][j]=true;
        int maxn=0,idx=0;
        for(int i=1; i<=k; i++) dp(i);
        for(int i=1; i<=k; i++)
        {
            if(d[i]>maxn)
            {
                maxn=d[i];
                idx=i;
            }
        }
        printf("%d\n",maxn);
        printans(idx);
        cout<<endl;
    }
    return 0;
}
