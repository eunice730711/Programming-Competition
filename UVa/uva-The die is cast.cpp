#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char arr[1000][1000];
int vis[1000][1000];
int ans[1000];
int w=0,h=0,dice=0,dot=0;
int cmp(const void *p,const void *q)
{
    return (*(int*)p-*(int*)q);
}
void dfs(int i,int j)
{
    if(i>=h||j>=w||i<0||j<0)
    {
        return ;
    }
    else if(vis[i][j]!=0||arr[i][j]=='.')
    {
        return ;
    }
    else
    {
        vis[i][j]=dice;
        dfs(i+1,j);
        dfs(i,j+1);
        dfs(i-1, j);
        dfs(i, j-1);
    }
}
void dfs1(int i,int j)
{
    if(i>=h||j>=w||i<0||j<0)
    {
        return ;
    }
    else if(vis[i][j]<0||arr[i][j]=='.'||arr[i][j]=='*')
    {
        return ;
    }
    else
    {
        vis[i][j]=0-vis[i][j];
        dfs1(i+1,j);
        dfs1(i,j+1);
        dfs1(i-1, j);
        dfs1(i, j-1);
    }
}
int main()
{
    int count_=0;
    scanf("%d %d",&w,&h);
    while(w!=0||h!=0)
    {
        count_++;
        dice=0;
        dot=0;
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                scanf(" %c",&arr[i][j]);
            }
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(vis[i][j]==0&&(arr[i][j]=='*'||arr[i][j]=='X'))
                {
                    dice++;
                    dfs(i,j);
                }
            }
        }
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(vis[i][j]>0&&arr[i][j]=='X')
                {
                    ans[vis[i][j]]++;
                    dfs1(i,j);
                }
            }
        }
        qsort(ans,dice+1,sizeof(int),cmp);
        printf("Throw %d\n",count_);
        for(int i=1; i<=dice; i++)
        {
            printf("%d",ans[i]);
            if(i!=dice) printf(" ");
        }
        printf("\n");
        printf("\n");
        scanf("%d %d",&w,&h);
    }
    return 0;
}
