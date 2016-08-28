#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<sstream>
using namespace std;
int arr[30][30];
bool vis[30][30]= {false};
int n;
void dfs(int i,int j,int num)
{
    if(vis[i][j] || arr[i][j]==0)
    {
        vis[i][j]=true;
        return ;
    }
    if(arr[i][j]==1)
    {
        vis[i][j]=true;
        if(i>0) dfs(i-1,j,num);
        if(j>0) dfs(i,j-1,num);
        if(i>0&&j>0) dfs(i-1,j-1,num);
        if(i<n-1) dfs(i+1,j,num);
        if(j<n-1) dfs(i,j+1,num);
        if(i<n-1&&j<n-1) dfs(i+1,j+1,num);
        if(i>0&&j<n-1) dfs(i-1,j+1,num);
        if(i<n-1&&j>0) dfs(i+1,j-1,num);
    }
}
int main()
{
    int cas=0;
    while(cin>>n)
    {
        memset(arr,0,sizeof(arr));
        memset(vis,false,sizeof(vis));
        getchar();
        for(int i=0; i<n; i++)
        {
            int j=0;
            char str[30]="";
            scanf("%s",str);
            for(int j=0;j<n;j++)
            {
                arr[i][j]=str[j]-'0';
            }
        }
        int num=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]==1&&!vis[i][j]) dfs(i,j,++num);
            }
        }
        cas++;
        cout<<"Image number "<<cas<<" contains "<<num<<" war eagles."<<endl;
    }
    return 0;
}
