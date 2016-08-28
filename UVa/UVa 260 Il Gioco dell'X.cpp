#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
char arr[205][205];
int n=0;
bool visit[205][205];
//bool dfs(int x,int y)
//{
//     printf("B x y:%d %d\n",x,y);
//    bool a=false,b=false;
//    if(x==n-1) return true;
//
//    if(y!=n-1)
//    {
//        if(arr[x+1][y]=='b') a=dfs(x+1,y);
//        if(arr[x+1][y+1]=='b') b=dfs(x+1,y+1);
//        return a|b;
//    }
//    else if(y==n-1)
//    {
//        if(arr[x+1][y]=='b') a=dfs(x+1,y);
//        return a;
//    }
//}
bool dfs(int x,int y)
{
    bool a=false,b=false,c=false,d=false,e=false,f=false;
    if(x==n-1) return true;
    if(x>0 && y>0 && arr[x-1][y-1]=='b' && !visit[x-1][y-1]) visit[x-1][y-1]=true,a=dfs(x-1,y-1);
    if(x>0  && arr[x-1][y]=='b' && !visit[x-1][y]) visit[x-1][y]=true,b=dfs(x-1,y);
    if(y>0 && arr[x][y-1]=='b' && !visit[x][y-1]) visit[x][y-1]=true,c=dfs(x,y-1);
    if(y<n && arr[x][y+1]=='b' && !visit[x][y+1]) visit[x][y+1]=true,d=dfs(x,y+1);
    if(x<n && arr[x+1][y]=='b' && !visit[x+1][y]) visit[x+1][y]=true,e=dfs(x+1,y);
    if(x<n && y<n && arr[x+1][y+1] && !visit[x+1][y+1]) visit[x+1][y+1]=true,f=dfs(x+1,y+1);
    return a|b|c|d|e|f;


}
bool dfs1(int x,int y)
{
    //printf("W x y:%d %d\n",x,y);

    if(y==n-1) return true;
    bool a=false,b=false;
    if(x!=n-1)
    {
        if(arr[x][y+1]=='w') a=dfs1(x,y+1);
        if(arr[x+1][y+1]=='w') b=dfs1(x+1,y+1);
        return a|b;
    }
    else if(x==n-1)
    {
        if(arr[x][y+1]=='w') a=dfs1(x,y+1);
        return a;
    }


}
int main()
{
    int cas=1;
    while(cin>>n&&n!=0)
    {

        memset(arr,0,sizeof(arr));
        for(int i=0; i<n; i++)
        {
            scanf("%s",arr[i]);
        }

        bool win=false;
        for(int i=0; i<n; i++)
        {
            //memset(visit,false,sizeof(visit));
            if(arr[0][i]=='b' && dfs(0,i)==true)
            {
                cout<<cas++<<' '<<"B"<<endl;
                win=true;
                break;
            }
        }
        if(win==false)  cout<<cas++<<' '<<"W"<<endl;

    }
    return 0;
}
