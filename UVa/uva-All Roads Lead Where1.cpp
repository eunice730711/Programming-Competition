#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Edge
{
    char a,b;
};
//Edge query[1000000];
char p1[10000]="",p2[10000]="";
int main()
{
    int m=0,n=0,test=0;
    scanf("%d",&test);
    for(int u=0; u<test; u++)
    {
        scanf("%d %d",&m,&n);
        char parent[28]="";
        Edge query;
        for(int i=0; i<m; i++)
        {
            char str1[100000]="",str2[100000]="";
            scanf("%s%s",str1,str2);
            parent[str2[0]-'0'-16]=str1[0];//將A的parent存在parent[0]以此類推
            //  printf("aaa\n");
        }
        /*   for(int i=0; i<27; i++)
           {
               printf("%c %d\n",parent[i],i);
           }*/
           //printf("%d\n",u);
          if(u!=0) printf("\n");
        for(int i=0; i<n; i++)
        {
            char str1[100000]="",str2[100000]="";
            scanf("%s%s",str1,str2);
            query.a=str1[0];
            query.b=str2[0];

            // printf("aaa**\n");


//printf("aaa*\n");
            int ind1=0,ind2=0,ans1=0,ans2=0;
            char ch=parent[(query.a)-'0'-16];
            p1[ind1++]=query.a;//先存頭
            if(query.a!='R') p1[ind1++]=ch;
            //printf("%c***\n",ch);
            while(ch!='R'&&query.a!='R')
            {
                //printf("aaa*\n");
                ch=parent[ch-'0'-16];
                p1[ind1++]=ch;
            }

            char ch1=parent[(query.b)-'0'-16];
            p2[ind2++]=query.b;
            if(query.b!='R') p2[ind2++]=ch1;

            while(ch1!='R'&&query.b!='R')
            {
//printf("aaa*!\n");
                ch1=parent[ch1-'0'-16];
                p2[ind2++]=ch1;
            }

            bool find_=false;
            for(int i=0; i<strlen(p1); i++)
            {
                for(int j=0; j<strlen(p2); j++)
                {
                    //  printf("aaa****\n");
                    if(p1[i]==p2[j])
                    {
                        ans1=i;
                        ans2=j;
                        find_=true;
                        break;
                    }
                }
                if(find_==true) break;
            }
            // printf("%d %d\n",ans1,ans2);
            // printf("aaa****\n");
            for(int i=0; i<ans1; i++)
            {
                printf("%c",p1[i]);
            }
            for(int i=ans2; i>=0; i--)
            {
                printf("%c",p2[i]);
            }
            printf("\n");
        }

    }
    return 0;
}

