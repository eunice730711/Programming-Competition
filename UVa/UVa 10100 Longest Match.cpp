#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    char str1[1010],str2[1010];
    int cas=1;
    while(gets(str1))
    {
        bool check1=false,check2=false;
        vector<string> word1,word2;
        gets(str2);
        int len1=strlen(str1),len2=strlen(str2),ind1=0,ind2=0;
        char tmpstr[25]="";
        strcpy(tmpstr,"");
        for(int i=0; i<len1; i++)
        {
            if((str1[i]<='z'&&str1[i]>='a')||(str1[i]<='Z'&&str1[i]>='A'))
            {
                tmpstr[ind1++]=str1[i];
                //cout<<str1[i]<<' ';
            }
            else
            {
                //cout<<endl;
                string tmp(tmpstr);
                //cout<<tmp<<endl;
                word1.push_back(tmp);
                memset(tmpstr,0,sizeof(tmpstr));
                ind1=0;
                if(i==len1-1) check1=true;
            }
        }
        if(check1==false)
        {
            string tmp(tmpstr);
            word1.push_back(tmp);
            memset(tmpstr,0,sizeof(tmpstr));
            ind1=0;
        }

        for(int i=0; i<len2; i++)
        {
            if((str2[i]<='z'&&str2[i]>='a')||(str2[i]<='Z'&&str2[i]>='A'))
            {
                tmpstr[ind2++]=str2[i];
            }
            else
            {
                string tmp(tmpstr);
                word2.push_back(tmp);
                memset(tmpstr,0,sizeof(tmpstr));
                ind2=0;
                if(i==len1-1) check1=true;
            }
        }
        if(check2==false)
        {
            string tmp(tmpstr);
            word2.push_back(tmp);
            memset(tmpstr,0,sizeof(tmpstr));
            ind2=0;
        }

        int ans=0;
        for(int i=0; i<word1.size(); i++)
        {
            for(int j=0; j<word2.size(); j++)
            {
                if(word1[i]==word2[j]) ans++;
            }
        }
//        cout<<word1.size()<<endl;
//        for(int i=0; i<word1.size(); i++) cout<<word1[i]<<' ';
//        cout<<endl;
//        for(int i=0; i<word2.size(); i++) cout<<word2[i]<<' ';
//        cout<<endl;
//cout<<strcmp(str1,"")<<endl;
        if(strcmp(str1,"")==0||strcmp(str2,"")==0) printf("%d. Blank!\n",cas);
        else printf("%d. Length of longest match: %d\n",cas,ans);
        cas++;
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
    }
    return 0;
}
