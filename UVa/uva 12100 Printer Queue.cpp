#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<queue>

//void findmax(queue<int> q,int n)
//{
//    for(queue<int>::iterator it=q.begin())
//}
using namespace std;
int main()
{
    int test=0;
    cin>>test;
    while(test--)
    {
        int n,p,job;
        queue<int> q;
        priority_queue <int> pq;
        cin>>n>>p;
        for(int i=0; i<n; i++)
        {
            int in;
            cin>>in;
            if(i==p)
            {
                job=in;
                q.push(-1);
            }
            else  q.push(in);
            pq.push(in);
        }
       // cout<<pq.top()<<endl;
        int cnt=0;
        while(1)
        {
            if(q.front()!=-1)
            {
                if(q.front()<pq.top())
                {
                    int tmp=q.front();
                    q.pop();
                    q.push(tmp);
                }
                else
                {
                    cnt++;
                    q.pop();
                    pq.pop();

                }
            }
            else
            {
                if(job<pq.top())
                {
                    q.pop();
                    q.push(-1);
                }
                else
                {
                    cnt++;
                    break;
                }
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}
