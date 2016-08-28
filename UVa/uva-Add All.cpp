#include<stdio.h>
#include<stdlib.h>
long int arr[5005]= {0};
int cmp(const void *p,const void *q)
{
    return (*(int*)p-*(int*)q);
}
int main()
{
    int n=0;
    scanf("%d",&n);
    while(n!=0)
    {
        for(int i=0; i<n; i++)
        {
            scanf("%ld",&arr[i]);
        }
        long int count_=0;
        qsort(arr,n,sizeof(long int),cmp);
        while(n!=1)
        {
            int new1=arr[0]+arr[1];
            count_+=new1;
            arr[0]=new1;
            n--;
            for(int j=1; j<n; j++)
            {
                arr[j]=arr[j+1];
            }
            int tem=arr[0],u=1;
            for(u=1;u<n&&arr[u]<tem;u++);
            if(u<=n)
            {
                 for(int i=0;i<u-1;i++)
            {
                arr[i]=arr[i+1];
            }
            arr[u-1]=tem;
            }
        }
        printf("%d\n",count_);
        scanf("%d",&n);
    }
    return 0;
}
