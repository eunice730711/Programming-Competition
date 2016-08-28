#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
    int a;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        char str[100]="";
        cin>>str;
       // cout<<str<<endl;
        int len=strlen(str);
        int ss=0,ans=0;
        for(int i=0;i<len;i++)
        {
            if(i==0)
            {
                if(str[i]=='O')
                {
                    ss=1;
                    ans+=ss;
                }
                else ss=0;
            }
            else
            {
                if(str[i]=='O')
                {
                    ss+=1;
                    ans+=ss;
                }
                else if(str[i]=='X') ss=0;
            }
           // cout<<i<<' '<<ans<<endl;
        }
        cout<<ans<<endl;

    }




    return 0;
}
