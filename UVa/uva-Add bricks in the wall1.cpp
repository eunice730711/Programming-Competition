#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int num=1,input[21]= {0},index=0,ans[50]= {0};
        for(int j=0; j<5; j++)
        {
            for(int k=0; k<num; k++)
            {
                scanf("%d",&input[index]);
                index++;
            }
            num++;
        }
        int add=1,id=0,a=0;
        int x[10]= {0},y[10]= {0},z[10]= {0};
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<add; k++)
            {

                x[id]=( input[a]-input[a+add]-input[a+add+1])/2;
                y[id]=x[id]+input[a+add];
                z[id]=x[id]+input[a+add+1];
                id++;
                a++;
            }
            add++;
        }
        int u=0,ind=0,add1=1,xid=0,yid=0,zid=0;
        ans[ind++]=input[u++];
        for(int j=0; j<4; j++)
        {

            //ind=ind+1+add1;
            for(int t=0; t<add1; t++)
            {
                ans[ind++]=y[yid++];
                ans[ind++]=z[zid++];
            }
            ans[ind++]=input[u++];
            for(int k=0; k<add1; k++)
            {

                ans[ind++]=x[xid++];
                ans[ind++]=input[u++];
            }

            add1++;
        }
        int b=0,num1=1;
        for(int j=0; j<9; j++)
        {
            for(int k=0; k<num1; k++)
            {
                printf("%d",ans[b++]);
                if(k!=num1-1)
                {
                    printf(" ");
                }

            }
            printf("\n");
            num1++;

        }
    }
    return 0;
}
