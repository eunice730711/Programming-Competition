#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[10005];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int first=-1,sum=0,num=0,max=0,ans=0;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            if(s[i]!='0'&&s[i]!='+'&&s[i]!='-')
            {
                first=i;
                break;
            }
        }
        if(first<0)
        {
            printf("2\n");
        }
        else
        {
            for(int i=first; i<len; i++)
            {
                if(s[i]>=48&&s[i]<=57) num=s[i]-48; //s[i]=0~9
                else if(s[i]>=65&&s[i]<=90) num=s[i]-55; //s[i]=A~Z
                else num=s[i]-61; //s[i]=a~z
                if(max < num)  max = num;
                sum+=num;
            }
            int p=max;
            for(p=max; p<=62; p++)
            {
                if(sum%p==0)
                {
                    ans=p+1;
                    break;
                }

            }
            if(p>=63) printf("such number is impossible!\n");
            else printf("%d\n",ans);
        }
    }

    return 0;
}
