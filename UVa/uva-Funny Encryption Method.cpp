#include<stdio.h>
#include<stdlib.h>
int ToBinarysOne(int in)
{
    int one=0;
    while(in/2!=0)
    {
        if(in%2!=0) one++;
        in/=2;
    }
    return one+1;
}
int HToBOnes(int in)
{
    int a=0,ones=0;
    while(in/10!=0)
    {
        a=in%10;
        ones=ones+ToBinarysOne(a);
        in/=10;
    }
    return ones+ToBinarysOne(in);

}

int main()
{
    int case_=0;
    scanf("%d",&case_);
    for(int i=0; i<case_; i++)
    {
        int input=0,b1=0,temp=0,b2=0;
        scanf("%d",&input);
        b2=HToBOnes(input);
        b1=ToBinarysOne(input);
        printf("%d %d\n",b1,b2);
    }

    return 0;

}
