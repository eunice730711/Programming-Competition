#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int arr[1005]= {0};
bool solve(int n)
{
    stack <int> s;
    int i=1,j=1;
    while(j<=n)
    {
        if(i==arr[j])
        {
            i++;
            j++;
        }
        else
        {
            if(!s.empty()&&s.top()==arr[j])
            {
                s.pop();
                j++;
            }
            else if(i<=n)
            {
                s.push(i);
                i++;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        memset(arr,0,sizeof(arr));
        int k=0;
        while(cin>>k)
        {
            if(k==0) break;
            else
            {
                arr[1]=k;
                for(int i=2; i<=n; i++)
                {
                    cin>>arr[i];
                }
                bool ans=solve(n);
                if(ans==true) cout<<"Yes"<<endl;
                else cout<<"No"<<endl;


            }
        }
        cout<<endl;
        cin>>n;
    }





    return 0;
}
