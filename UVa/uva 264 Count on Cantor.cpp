#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int line=1;
        int num=0;
        while(num<n)
        {
            num+=line;
            line++;
           // printf("aaa\n");
        }
        int head=line-1,rear=1;
        int first=num+1-head;
       // printf("%d %d %d\n",head,rear,first);
        while(first!=n)
        {
            first++;
            head--;
            rear++;

        }
       // printf("%d %d %d\n",head,rear,first);
        if((line-1)%2==0) printf("TERM %d IS %d/%d\n",n,rear,head);
        else printf("TERM %d IS %d/%d\n",n,head,rear);
    }
    return 0;
}
