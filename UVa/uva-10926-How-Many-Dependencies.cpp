#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int adj[105][105]= {0};
int dfs(int start,int task)
{
    if(task==0) return 0;
    bool visit[105]= {false};
    int c=0;
    stack<int> s;
    s.push(start);
    visit[start]=true;
    while(!s.empty())
    {
        int tmp=s.top();
        s.pop();
        for(int i=1; i<=task; i++)
        {
            if(adj[tmp][i]==1&&!visit[i])
            {
                s.push(i);
                visit[i]=true;
                c++;
            }
        }
    }
    return c;
}
int main()
{
    int task;
    cin>>task;
    while(task!=0)
    {
        memset(adj,0,sizeof(adj));

        for(int i=1; i<=task; i++)
        {
            int t;
            cin>>t;
            for(int j=1; j<=t; j++)
            {
                int tmp;
                cin>>tmp;
                adj[i][tmp]=1;

            }
        }
        int max_=dfs(1,task),ans=1;

        for(int j=2; j<=task; j++)
        {
            int p=dfs(j,task);
            if(p>max_)
            {
                max_=p;
                ans=j;
            }
        }
        cout<<ans<<endl;
        cin>>task;
    }
    return 0;
}
