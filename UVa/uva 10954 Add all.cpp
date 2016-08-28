#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        priority_queue <long long int,vector<long long int>,greater<long long int> > pq;
        for(int i=0; i<n; i++)
        {
            int tmp;
            cin>>tmp;
            pq.push(tmp);
        }
        long long int cost=0;
        for(int i=0; i<n-1; i++)
        {
            long long int first=pq.top();
            pq.pop();
            long long int second=pq.top();
            pq.pop();
            long long int newk=first+second;
            cost+=newk;
            pq.push(newk);
        }
        cout<<cost<<endl;
    }
    return 0;
}
