#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;//first:color , second:node
struct node
{
    int n=0,dis=0,pre=0;
    friend bool operator < (node a,node b);
};
bool operator < (node a,node b)
{
    return (a.dis>b.dis || a.dis==b.dis && a.n>b.n);
}
vector<ii> edges[200005];
vector<node> D;

void Dijkstra(int N, int s)
{
    for(int i=0; i<D.size(); i++) D[i].dis=1<<20;
    //priority_queue<ii,vector<ii>,greater<ii>> Q;
    priority_queue<pair<node,int> > pq;
    D[s].dis=0;//dis of start
    D[s].n=0;//color of start
    D[s].pre=0;
    //Q.push(ii(0,s));
    pq.push(make_pair(D[s],s));

    while(!pq.empty())
    {
        //pair<node,int> top=Q.top();
        //Q.pop();
        //int v=top.second, d=top.first;
        pair<node,int> top=pq.top();
        pq.pop();
        // cout<<top.second<<' '<<top.first.dis<<' '<<top.first.n<<endl;
        int v=top.second, d=top.first.dis;
        //cout<<v<<d<<endl;


        if(d<=D[v].dis)
        {
            for(int i=0; i<edges[v].size(); i++)
            {
                sort(edges[v].begin(),edges[v].end());
                int v2=edges[v][i].first, color=edges[v][i].second;//the next node
                // cout<<"a"<<v2<<' '<<color<<endl;
                int newd=0;
                if(color==D[v].n)
                {
                    if(D[v2].dis>D[v].dis+0 || (D[v2].dis==D[v].dis+0 && D[v2].n>D[v].n))
                    {
                        D[v2].dis=D[v].dis+0;
                        //Q.push(ii(D[v2].dis,v2));

                        D[v2].n=color;
                        D[v2].pre=v;
                        pq.push(make_pair(D[v2],v2));
                        // cout<<"bbb"<<endl;
                    }
                }
                else
                {
                    if(D[v2].dis>D[v].dis+1 || (D[v2].dis==D[v].dis+1 && D[v2].n>D[v].n))
                    {
                        D[v2].dis=D[v].dis+1;
                        // Q.push(ii(D[v2].dis,v2));
                        //pq.push(make_pair(D[v2],v2));
                        D[v2].n=color;
                        D[v2].pre=v;
                        pq.push(make_pair(D[v2],v2));
                        //cout<<"ccc"<< ' '<<v2<<' '<<v<<endl;
                    }
                }
            }
        }
    }

}
int main()
{
    int n,m,a,b,w;
    while(cin>>n>>m)
    {
        D.resize(m);
        for(int i=0; i<m; i++)
        {
            cin>>a>>b>>w;
            edges[a].push_back(ii(b,w));

        }
        Dijkstra(n,1);
        int ans=D[n].dis;
        cout<<ans<<endl;
        int next=n;
        vector<int > path;
        while(D[next].n!=0)
        {
            path.push_back(D[next].n);
            next=D[next].pre;
        }
        reverse(path.begin(),path.end());
        auto it =unique(path.begin(),path.end());
        path.resize(distance(path.begin(),it));
        for(auto it=path.begin(); it!=path.end(); it++)
        {
            if(it==path.end()-1) cout<<*it;
            else cout<<*it<<' ';
        }
        cout<<endl;
        n=m=a=b=w=0;
    }
    return 0;
}
