#include<stdio.h>
#include<stdlib.h>
int map[10005]={0};
int main()
{
    int l=0,h=0,r=0,rmax=0;
    while(scanf("%d %d %d",&l,&h,&r)!=EOF)
    {
        for(int i=l;i<r;i++)
        {
            if(h>map[i])
            {
                map[i]=h;
            }
        }
        if(r>rmax)
        {
            rmax=r;
        }
    }
    int hight=0;
    for(int i=0;i<rmax;i++)
    {
        if(map[i]!=hight)
        {
            printf("%d %d ",i,map[i]);
            hight=map[i];
        }
    }
    printf("%d %d\n",rmax,0);
    return 0;
}
