#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
int bomb[1030][1030];
int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
        vector<pair<int,ii> > pp;
        memset(bomb,0,sizeof(bomb));
        int d,n;
        cin>>d>>n;
        for(int i=0; i<n; i++)
        {
            int x,y,p;
            cin>>x>>y>>p;
            pp.push_back(make_pair(p,ii(x,y)));
        }
        for(int i=0; i<n; i++)
        {
            int num=pp[i].first;
            int xx=pp[i].second.first;
            int yy=pp[i].second.second;
            for(int j=xx-d; j<=xx+d; j++)
            {
                for(int k=yy-d; k<=yy+d; k++)
                {
                    if(j>=0 && k>=0 && j<1025 && k< 1025) bomb[j][k]+=num;
                }
            }
        }

        int ansx=0,ansy=0,maxn=0;
        for(int i=0; i<1030; i++)
        {
            for(int j=0; j<1030; j++)
            {
                if(maxn<bomb[i][j])
                {
                    maxn=bomb[i][j];
                    ansx=i,ansy=j;
                }
            }
        }
        cout<<ansx<<' '<<ansy<<' '<<maxn<<endl;
    }

    return 0;
}
