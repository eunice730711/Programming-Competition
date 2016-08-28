#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    int ind1=0,ind2=0,ind3=0;
    int ans[1505]={1};
    int pren=1;
    for(int i=1;i<1505;i++)
    {
        for(;ind1<1505;ind1++)
        {
            if(ans[ind1]*2>pren) break;
        }
        for(;ind2<1505;ind2++)
        {
            if(ans[ind2]*3>pren) break;
        }
        for(;ind3<1505;ind3++)
        {
            if(ans[ind3]*5>pren) break;
        }
        pren=min(ans[ind1]*2,min(ans[ind2]*3,ans[ind3]*5));
        ans[i]=pren;
    }
    printf("The 1500'th ugly number is %d.\n",ans[1499]);



    return 0;
}
