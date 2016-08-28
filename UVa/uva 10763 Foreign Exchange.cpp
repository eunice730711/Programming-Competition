#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int in;
    while(cin>>in&&in!=0)
    {
        bool check=true;
        vector<int> start,des;
        for(int i=0; i<in; i++)
        {
            int a,b;
            cin>>a>>b;
            start.push_back(a);
            des.push_back(b);
        }
        sort(start.begin(),start.end());
        sort(des.begin(),des.end());
        for(int i=0;i<in;i++)
        {
            if(start[i]!=des[i]) check=false;
        }
        if(check==false) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
