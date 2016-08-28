#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
bool cmp(string a,string b)
{
   return (a+b) > (b+a);
}
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        string arr[55];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n,cmp);
        for(int j=0; j<n; j++)
        {
            cout<<arr[j];
        }
        cout<<endl;

        cin>>n;
    }




    return 0;
}
