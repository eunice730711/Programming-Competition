#include<stdio.h>
#include<stdlib.h>
char map[105][105];
bool check[105][105];
int m=0,n=0;
void IsOil(int x,int y)
{
    if(x<0||y<0||x>=m||y>=n)
        return ;
    else if(map[x][y]=='*'||check[x][y]==true)
        return ;
    else
    {
        check[x][y]=true;
        IsOil(x-1,y);
        IsOil(x-1,y-1);
        IsOil(x-1,y+1);
        IsOil(x,y-1);
        IsOil(x,y+1);
        IsOil(x+1,y);
        IsOil(x+1,y-1);
        IsOil(x+1,y+1);
    }
}
int main()
{

    scanf("%d %d",&m,&n);
    while(m!=0&&n!=0)
    {
        for(int i=0; i<m; i++)
        {
            scanf("%s",map[i]);
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                check[i][j]=false;
            }
        }
        int count_=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j]=='@'&&check[i][j]==false)
                {
                    IsOil(i,j);
                    count_++;
                }
            }
        }
        printf("%d\n",count_);
        scanf("%d %d",&m,&n);
    }
    return 0;
}
