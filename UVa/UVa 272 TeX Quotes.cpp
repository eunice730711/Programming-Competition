#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<math.h>
using namespace std;
int main()
{
    string str="";
    bool first=true;
    while(getline(cin,str))
    {
        int len=str.size();
        for(int i=0;i<len;i++)
        {
            if(str[i]=='"'&&first==true)
            {
                 cout<<"``";
                 first=false;
            }
            else if(str[i]=='"'&&first==false)
            {
                cout<<"''";
                first=true;
            }
            else cout<<str[i];

        }
        cout<<endl;
    }
    return 0;
}
