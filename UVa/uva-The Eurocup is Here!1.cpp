#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int twopow(int p)
{
    int a=1;
    for(int i=1; i<=p; i++)
    {
        a*=2;
    }
    return a;
}
int BinarySearch(int team,int round)
{
    int count_=1,tail=pow(2,round)-1,head=0;
    while((tail+head+1)/2!=0)
    {
        if(team>=(tail+head+1)/2)
        {
            count_++;
            if(head==team||head+1==team) break;
            head=(tail+head+1)/2;
        }
        else
        {
            if(tail==team||tail==team+1) break;
            tail=(tail+head+1)/2-1;
        }
    }
    return count_;
}
int pass(int team,int round)
{
    int count_=1,tem=0;
    if(team==0) return 1;
    else if(team%2!=0) return twopow(round);
    else
    {
        for(int i=round-1; i>0; i--)
        {
            if(team%(twopow(i))!=0)
            {

                count_++;
            }
            else
            {
                break;
            }
        }
    }
    tem=round-count_;
    return twopow(round)-twopow(tem)+1; //2^round+2^(team¦b²Ä´Xround)+1

}
int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int round=0,team=0,opp=0,passi=0;
        scanf("%d %d",&round,&team);
        opp=BinarySearch(team,round);
        passi=pass(team,round);
        printf("%d %d\n",opp,passi);
    }
    return 0;
}
