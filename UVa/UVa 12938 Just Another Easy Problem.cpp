#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
bool com(int a,int b)
{


    int num=0;
    for(int i=0; i<4; i++)
    {
        if(a%10!=b%10) num++;
        a/=10;
        b/=10;
    }
    if(num==1) return true;
    else return false;
}
int main()
{
    int cas;
    cin>>cas;
    for(int cc=1; cc<=cas; cc++)
    {
        int n,ans=0;
        cin>>n;
        for(int i=32; i<=99; i++)
        {
            if(com(i*i,n))
            {
                ans++;
                //cout<<i<<endl;
            }
        }
        printf("Case %d: %d\n",cc,ans);
    }




    return 0;
}
