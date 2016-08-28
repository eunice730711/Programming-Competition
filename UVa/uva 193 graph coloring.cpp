#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
bool adj[105][105]= {false},rec[105]= {false},color[105]= {false};
int n=0,k=0,ans=0;
void dfs(int p,int num)
{
    if(p>n)
    {
        //cout<<num<<endl;
        if(num>ans)
        {
            ans=num;
            for(int i=1; i<=n; i++)
            {
                rec[i]=color[i];
            }
        }
        return ;
    }

    for(int i=1; i<=n; i++)
    {
        if(adj[p][i]==true && color[i]==true)
        {
            color[p]=false;
            dfs(p+1,num);
            return;
        }
    }
    color[p]=true;
    dfs(p+1,num+1);
    color[p]=false;
    dfs(p+1,num);

}
int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {

        cin>>n>>k;

        memset(adj,false,sizeof(adj));
        memset(color,false,sizeof(color));
        ans=0;
        memset(rec,false,sizeof(rec));
        for(int i=0; i<k; i++)
        {
            int a,b;
            cin>>a>>b;
            adj[a][b]=adj[b][a]=true;
        }

        dfs(1,0);
        int cc=0;
        cout<<ans<<endl;
        for(int i=1; i<=n; i++)
        {
            if(rec[i]==true && cc!=ans-1) cout<<i<<' ',cc+=1;
            else if(rec[i]==true && cc==ans-1)
            {
                cout<<i<<endl;
                break;
            }
        }

    }

    return 0;
}
