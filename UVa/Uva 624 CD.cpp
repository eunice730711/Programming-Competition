#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
int p[25],N,k,visit[25],maxn=0;
vector<int> ans,final_;
void back_tracking(int w,int n,int over,int s)
{
    if(w>maxn)
    {
        final_=ans;
        maxn=w;
    }
    if(over>=N || n>=k ) return;
    for(int i=s; i<k; i++)
    {
        if(!visit[i])
        {
            visit[i]=true;
            if(w+p[i]>N) back_tracking(w,n,over+p[i],i);
            else
            {
                ans.push_back(p[i]);
                back_tracking(w+p[i],n+1,over+p[i],i+1);
                ans.pop_back();
            }

            visit[i]=false;
        }
    }
}
int main()
{
    while(cin>>N>>k)
    {
        maxn=0;
        memset(p,0,sizeof(p));
        memset(visit,false,sizeof(visit));
        ans.clear();
        final_.clear();
        for(int i=0; i<k; i++)
        {
            scanf("%d",&p[i]);
        }
        back_tracking(0,0,0,0);
        for(int i=0; i<final_.size(); i++)
        {
            printf("%d ",final_[i]);
        }
        printf("sum:%d\n",maxn);
    }
    return 0;
}
