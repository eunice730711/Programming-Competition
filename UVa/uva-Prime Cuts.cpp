#include<stdio.h>
#include<stdlib.h>
bool Prime(int num)
{
    for(int i=2;i<num;i++)
    {
        if(num%i==0) return false;
    }
    return true;
}
int main()
{
    int n=0,c=0;
    while(scanf("%d %d",&n,&c)!=EOF)
    {
        int p[1001]={0},count_=0;
        for(int i=1;i<=n;i++)
        {
            if(Prime(i)==true)
            {
                p[count_]=i;
                count_++;
            }
        }
    /*    for(int k=0;k<count_;k++)
        {
            printf("%d ",p[k]);
        }*/
      //  printf("\n");
        printf("%d %d:",n,c);
        if((count_%2==0&&count_<=2*c)||(count_%2!=0&&count_<=2*c-1))
        {
            for(int j=0;j<count_;j++)
            {
                printf(" %d",p[j]);
            }
        }
        else if(count_%2==0)
        {
            int index=0;
            index=count_/2-c;
            for(int j=1;j<=2*c;j++)
            {
                printf(" %d",p[index]);
                index++;
            }
        }
        else
        {
            int index=0;
            index=(count_+1)/2-c;
            for(int j=1;j<=2*c-1;j++)
            {
                printf(" %d",p[index]);
                index++;
            }
        }
        printf("\n\n");
    }
    return 0;

}
