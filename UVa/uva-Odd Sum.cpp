#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t=0;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int u=0,v=0,total=0;
        scanf("%d",&u);
        scanf("%d",&v);
        for(int j=u;j<=v;j++)
        {
            if(j%2!=0)
            {
                total+=j;

            }
        }
        printf("Case %d: %d\n",i,total);
    }
    return 0;
}
