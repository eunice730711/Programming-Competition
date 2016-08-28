#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue <int> pq;
        bool checks=false,checkq=false,checkpq=false,im=false;

        int c=3;
        for(int i=0; i<n; i++)
        {
            int a,b;
            cin>>a>>b;
            if(a==1)
            {
                s.push(b);
                q.push(b);
                pq.push(b);
            }
            else
            {
                if(s.empty()&&q.empty()&&pq.empty()) im=true;
                else
                {


                    if(checks==false)
                    {
                        if(!s.empty())
                        {
                            int tmp=s.top();
                            s.pop();
                            if(tmp!=b)
                            {
                                checks=true;
                                c--;
                            }

                        }

                    }
                    if(checkq==false)
                    {
                        if(!q.empty())
                        {
                            int tmp=q.front();
                            q.pop();
                            if(tmp!=b)
                            {
                                checkq=true;
                                c--;
                            }
                        }
                    }
                    if(checkpq==false)
                    {
                        if(!pq.empty())
                        {
                            int tmp=pq.top();
                            pq.pop();
                            if(tmp!=b)
                            {
                                checkpq=true;
                                c--;
                            }
                        }
                    }
                }
            }

        }

        if(c==1)
        {
            if(checks==false)
            {
                cout<<"stack"<<endl;
            }
            else if(checkq==false)
            {
                cout<<"queue"<<endl;
            }
            else if(checkpq==false)
            {
                cout<<"priority queue"<<endl;
            }
        }
        else if(c==0 ||im==true)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<"not sure"<<endl;
        }
    }
    return 0;
}
