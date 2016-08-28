#include<stdio.h>
#include<stdlib.h>
int main()
{
    int coins[5]= {1,5,10,25,50};
    long long int change[30005]= {1};
    for(int i=0; i<5; i++)
    {
        for(int j=coins[i]; j<=30000; j++)
        {
            change[j]+=change[j-coins[i]];
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(change[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",change[n],n);

    }
    return 0;
}
