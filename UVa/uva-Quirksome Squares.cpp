#include<stdio.h>
#include<stdlib.h>
int Ten(int n)
{
    int a=1;
    for(int i=0; i<n; i++)
    {
        a=a*10;
    }
    return a;
}
int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF)
    {

        for(int i=0; i<Ten(n/2); i++)
        {
            int s=i*i,d=Ten(n/2);
            if(((s/d)+(s%d))==i)
            {
                if(n==2)
                {
                    printf("%02d\n",s);

                }
                else if(n==4)
                {
                    printf("%04d\n",s);

                }
                else if(n==6)
                {
                    printf("%06d\n",s);

                }
                else if(n==8)
                {
                    printf("%08d\n",s);
                }
            }
        }
    }
    return 0;
}
