#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<deque>
using namespace std;
long long int con=0,num=0;
int comnum(deque <char> &de)
{
    int tnum=0;
    bool flag=false;
    while(!de.empty())
    {
        flag=true;
        char ch=de.front();
        de.pop_front();
        int k=ch-'0';
        tnum=tnum*10+k;
    }
    if(flag==false) return 1;
    // cout<<tnum<<"***"<<endl;
    return tnum;
}
int comcon(deque <char> &de)
{
    int tcon=0;
    while(!de.empty())
    {
        char ch=de.front();
        de.pop_front();
        int k=ch-'0';
        tcon=tcon*10+k;
    }
    // cout<<tcon<<"yayaya"<<endl;
    return tcon;
}
void process(int f,int l,char str[])
{
    //cout<<f<<l<<endl;
    bool check=false;
    int i=f;
    if(str[i]=='-')
    {
        check=true;
        i++;
    }
    while(i<l)
    {
        // cout<<i<<"haha"<<endl;
        deque<char> de;
        while(str[i]!='-'&&str[i]!='+'&&str[i]!='=')
        {
            de.push_back(str[i]);
            i++;
        }
        // cout<<"i:"<<i<<endl;
        if(de.back()=='x')
        {
            // cout<<i<<"a"<<endl;
            de.pop_back(); //§âx®³±¼
            if(check==false) num+=comnum(de);
            else if(check==true) num-=comnum(de);
        }
        else
        {
            // cout<<i<<"b"<<endl;
            if(check==false) con+=comcon(de);
            else if(check==true) con-=comcon(de);
        }
        if(str[i]=='-') check=true;
        else check=false;
        i++;
        if(i>=l) return ;
    }
}
void process1(int f,int l,char str[])
{
    bool check=false;
    int i=f;
    if(str[i]=='-')
    {
        check=true;
        i++;
    }
    while(i<l)
    {
        deque<char> de;
        while(str[i]!='-'&&str[i]!='+'&&str[i]!='\0')
        {
            de.push_back(str[i]);
            i++;
        }
        if(de.back()=='x')
        {
            de.pop_back();
            if(check==false) num-=comnum(de);
            else if(check==true) num+=comnum(de);
            if(str[i]=='-') check=true;
            else check=false;
            i++;
        }
        else
        {
            if(check==false) con-=comcon(de);
            else if(check==true) con+=comcon(de);
            if(str[i]=='-') check=true;
            else check=false;
            i++;
        }
        if(i>=l) return ;
    }
}
int Findeq(char str[])
{
    int k=0;
    while(str[k]!='=')
    {
        k++;
    }
    return k;
}
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        con=0;
        num=0;
        char str[260]="";
        scanf("%s",str);
        int len=strlen(str);
        //cout<<str[0]<<"*"<<endl;
        int eq=Findeq(str);
        //cout<<eq<<endl;
        process(0,eq,str);
        // cout<<num<<'/'<<con<<endl;
        process1(eq+1,len,str);
        //cout<<con<<'/'<<num<<endl;
        if(num==0&&con!=0) cout<<"IMPOSSIBLE";
        else if(num==0&&con==0) cout<<"IDENTITY";
        else if(con%num!=0&&(con*(0-num)<0))cout<<con/(0-num)-1;
        else cout<<con/(0-num);
        if(test!=0) cout<<endl;
    }
    return 0;
}
