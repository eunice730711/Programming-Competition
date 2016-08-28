#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
using namespace std;
int adj[105][105],visit[105],low[105],ans[105];
int t,count_;
void DFS(int p,int i,int n)
{
    visit[i]=low[i]=(t++);
    int child=0;
    bool ap=false;
    //cout<<p<<' '<<i<<endl;
    //cout<<adj[3][4]<<endl;
    for(int j=1; j<=n; j++)
    {
       // cout<<"aa"<<endl;

        if(adj[i][j]==1 && p!=j)
        {
            //cout<<"cc"<<endl;
            if(visit[j])
            {
                low[i]=min(low[i],low[j]);
            }
            else
            {
                child++;
                DFS(i,j,n);
                low[i]=min(low[i],low[j]);
                if(low[j]>=visit[i]) ap=true;
            }
        }
    }
    if( i==p && child>1 || i!=p && ap==true)  //(i==p && child>0)
    {
        //cout<<"aaa"<<endl;
        ans[count_++]=i;
    }

}
int main()
{
    int n,cas=0;
    while(cin>>n && n!=0)
    {
        //map<pair<string,string>,int> adj;
        map<string,int> city;
        map<int,string> names;
        memset(adj,0,sizeof(adj));
        memset(visit,0,sizeof(visit));
        memset(low,0,sizeof(low));
        memset(ans,0,sizeof(ans));

        for(int i=1; i<=n; i++)
        {
            string str;
            cin>>str;
            city[str]=i;
            names[i]=str;
            //cout<<str<<endl;
            //cout<<city[str]<<endl;
        }
        int r;
        cin>>r;
        for(int i=0; i<r; i++)
        {
            string a,b;
            cin>>a>>b;
            adj[city[a]][city[b]]=1;
            adj[city[b]][city[a]]=1;
        }
        //cout<<adj[3][4]<<endl;
        t=1;
        count_=0;
        for(int i=1; i<=n; i++)
        {
            if(!visit[i]) DFS(i,i,n);
        }
        cout<<"City map #"<<++cas<<": "<<count_<<" camera(s) found"<<endl;
        string answer[105];
        for(int i=0; i<count_; i++)
        {
            answer[i]=names[ans[i]];
        }
        sort(answer,answer+count_);
        for(int i=0; i<count_; i++)
        {
            cout<<answer[i]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
