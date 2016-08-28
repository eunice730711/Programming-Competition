#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        list<char> ls;
        list<char>::iterator it=ls.begin();
        int len=str.size();
        for(int i=0;i<len;i++)
        {
            if(str[i]=='[') it=ls.begin();
            else if(str[i]==']') it=ls.end();
            else ls.insert(it,str[i]);
        }
        for(it=ls.begin();it!=ls.end();it++)
        {
            cout<<*it;
        }
        cout<<endl;
    }
    return 0;
}
