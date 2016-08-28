#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int ans[20]={1};
bool IsPrime(int n)
{
    for(int i=0;i<13;i++)
    {
        if(n==prime[i]) return true;
    }
    return false;
}
void backtracking(int n,int len,bool visit[])
{
    if(n==len)
    {
        if(IsPrime(1+ans[len-1]))
        {
            for(int i=0;i<n;i++)
            {
                cout<<ans[i];
                if(i!=n-1) cout<<' ';
            }
            cout<<endl;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(visit[i]) continue;
        if(IsPrime(i+ans[len-1]))
        {
            ans[len]=i;
            visit[i]=true;
            backtracking(n,len+1,visit);
            visit[i]=false;
        }
    }
}
int main()
{
    int n,cas=0;
    while(cin>>n)
    {
        if(cas++) cout<<endl;
        bool visit[20]={false};
        cout<<"Case "<<cas<<":"<<endl;
        backtracking(n,1,visit);


    }




    return 0;
}
