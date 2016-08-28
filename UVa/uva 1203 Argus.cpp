#include<stdio.h>
#include<algorithm>
#include<queue>
#include<iostream>
#include<string.h>
using namespace std;
struct cmp
{
    bool operator ()(const pair<int,int>p1,const pair<int,int> p2)const
    {
        if(p1.second==p2.second) return p1.first>p2.first;
        return p1.second > p2.second;
    }
};
int main()
{
    string s;
    priority_queue<pair<int,int>,vector<pair<int,int> >,cmp > save;
    int time[3005];
    char in[50];
    gets(in);
    while(in[0]!='#')
    {
        char input[30]="",temp[20]="";
        int id=0,p=0;
        sscanf(in,"%s %d %d",temp,&id,&p);
        //cout<<temp<<" "<<id<<" "<<p<<endl;
        pair<int,int> a(id,p);
        save.push(a);
        time[id]=p;
        // getline(cin,s);
        strcpy(in,"");
        gets(in);
    }
    int num;
    cin>>num;
    for(int i=0; i<num; i++)
    {
        int tmpid,tmpp;
        tmpid=save.top().first;
        tmpp=save.top().second;
        cout<<tmpid<<endl;
        save.pop();
        tmpp+=time[tmpid];
        pair<int ,int> tmp(tmpid,tmpp);
        save.push(tmp);
    }
    return 0;
}
