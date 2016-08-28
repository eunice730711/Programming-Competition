#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    int n=0;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int i=0; i<n; i++)
    {
        map<string,int> input;
        string str;
        int cc=0;
        getline(cin,str);

        while(str!="")
        {
             input[str]+=1;
             cc++;
             getline(cin,str);
        }
        for(map<string,int>::iterator it=input.begin(); it!=input.end(); it++)
        {
            double k=(double)(it->second)/cc;
            cout<<it->first<<' ';
            printf("%0.4f\n",k*100);
        }
        if(i!=n-1) cout<<endl;
    }
    return 0;
}
