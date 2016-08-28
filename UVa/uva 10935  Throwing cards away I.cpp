#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        queue<int> q;
        int arr[55]={0};
        for(int i=1;i<=n;i++)
        {
            q.push(i);
        }
        int c=0;
        for(int i=1;i<n;i++)
        {
            arr[c]=q.front();
            c++;
            q.pop();
            int tmp=q.front();
            q.push(tmp);
            q.pop();
        }
        cout<<"Discarded cards:";
        for(int i=0;i<n-1;i++)
        {
            cout<<' '<<arr[i];
            if(i!=n-2) cout<<',';
        }
        cout<<endl;
        cout<<"Remaining card: "<<q.front()<<endl;

    }
    return 0;
}
