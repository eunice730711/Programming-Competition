#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void com(int in,int *p,int input[])
{
    if(in==-1)
    {
        *p-=1;
    }
    else if(in==-2)
    {
        *p+=1;
    }
    else
    {
        in=input[in];
        com(in,p,input);
    }
}
int main()
{
    int c=0;
    scanf("%d",&c);
    for(int i=0; i<c; i++)
    {
        int instruction=0,input[105]= {0},num1=0,ind=1,p=0;
        scanf("%d",&instruction);
        getchar();
        for(int j=1; j<=instruction; j++)
        {
            char str[10]="",str1[10]="",str2[5]="",num[5]="";
            gets(str);
            if(strcmp(str,"LEFT")==0)
            {
                input[j]=-1;
            }
            else if(strcmp(str,"RIGHT")==0)
            {
                input[j]=-2;
            }
            else
            {
                int len=0;
                sscanf(str,"%s %s %s",&str1,&str2,&num);
                len=strlen(num);
                if(len==1) num1=num[0]-'0';
                else if(len==2)
                {
                    int a=0,b=0;
                    a=num[0]-'0';
                    b=num[1]-'0';
                    num1=a*10+b;
                }
                else
                {
                    num1=100;
                }
                input[j]=num1;
            }
        }
         for(int k=1;k<=instruction;k++)
         {
             com(input[k],&p,input);
         }
         printf("%d\n",p);
    }
    return 0;
}
