#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[1000000]="",t[1000000]="";
int main()
{
    while(scanf("%s%s",&s,&t)!=EOF)
    {
        int i=0,j=0;
        while(i<strlen(s)&&j!=strlen(t))
        {
           while(j<strlen(t))
            {
                if(s[i]==t[j])
                {

                    i++;
                    j++;
                    break;
                }
                j++;
            }
        }
        if(i==strlen(s)) //¤]¥i¼g¦¨ if(s[i]=='\0')
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
