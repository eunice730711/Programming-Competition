#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int map_[32768]= {0};
struct store
{
    int factor=0,p=0;
};
int pow(int a,int b)
{
    int ans=1;
    for(int i=0; i<b; i++)
    {
        ans*=a;
    }
    return ans;
}
bool IsPrime(int a)
{
    for(int i=2; i<=sqrt(a); i++)
    {
        if(a%i==0) return false;
    }
    return true;
}
int com(int a,store f[])
{
    int temp=a,count_=0,check=0;
    for(int i=0; map_[i]<=temp;)
    {
        if(temp%map_[i]==0)
        {
            temp=temp/map_[i];

            f[count_].factor=map_[i];
            f[count_].p+=1;
            if(temp==1) break;
            if(temp%map_[i]!=0)
            {
                i++;
                count_++;
            }
            check=1;
        }
        if(check!=1)i++;
        else check=0;
    }
    return count_;
}
int main()
{
    int num1=0,num2=0,count_=0;
    for(int k=2; k<=32768; k++)
    {
        if(IsPrime(k)==true)
        {
            map_[count_]=k;
            count_++;
        }
    }
    scanf("%d",&num1);
    while(num1!=0)
    {
        int x=1,ans=0,index=0;
        store f[5000];
        scanf("%d",&num2);
        while(1)
        {
            x*=pow(num1,num2);
            if(getchar()=='\n')  break;
            scanf("%d %d",&num1,&num2);
        }
        ans=x-1;
        index=com(ans,f);
        for(int i=index; i>=0; i--)
        {
            if(i==index) printf("%d %d",f[i].factor,f[i].p);
            else printf(" %d %d",f[i].factor,f[i].p);
        }
        printf("\n");
        scanf("%d",&num1);
    }
    return 0;
}
