#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define maxn 1010
int pic[maxn][maxn],nextt[maxn];
int n;

void init()
{
    memset(pic,0,sizeof(pic));
    string str;
    getline(cin,str);
    for(int i=1; i<=n; i++)
    {
        getline(cin,str);
        for(int j=1; j<=n; j++)
            pic[i][j]=str[(j-1)*2]-'0';
    }
}
void solve()
{
    int head=1,t;
    memset(nextt,0,sizeof(nextt));
    for(int k=2; k<=n; k++)
    {
        bool flag=0;
        for(int i=head; i; i=nextt[i])
        {
            if(pic[k][i])
            {
                if(i==head) head=k;
                else nextt[t]=k;
                nextt[k]=i;
                flag=1;
                break;
            }
            else t=i;
        }
        if(!flag) nextt[t]=k;
    }
    cout<<'1'<<endl<<n<<endl;
    for(int i=head; i; i=nextt[i])
    {
        if(i!=head) cout<<' ';
        cout<<i;
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        init();
        solve();
    }
    return 0;
}
