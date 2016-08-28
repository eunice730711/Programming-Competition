#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int ans[10005];
int arr[10005]= {0};
int fun(int bound)
{
    int c=0;
    for(int i=0; i<bound; i++)
    {
        int r,l;
        l=arr[i]/bound;
        r=arr[i]%bound;
        if((l+r)*(l+r)==arr[i])
        {
            ans[c]=arr[i];
            c++;
        }
    }
    return c;
}
int main()
{

    for(int i=0; i<10000; i++)
    {
        arr[i]=i*i;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(ans,0,sizeof(ans));
        if(n==2)
        {
            int num=fun(10);
            for(int i=0; i<num; i++)
            {
                printf("%02d\n",ans[i]);
            }
        }
        else if(n==4)
        {
            int num=fun(100);
            for(int i=0; i<num; i++)
            {
                printf("%04d\n",ans[i]);
            }

        }
        else if(n==6)
        {
            int num=fun(1000);
            for(int i=0; i<num; i++)
            {
                printf("%06d\n",ans[i]);
            }
        }
        else
        {
            int num=fun(10000);
            for(int i=0; i<num; i++)
            {
                printf("%08d\n",ans[i]);
            }
        }
    }
    return 0;
}
