#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<set>
#include<algorithm>
struct edge
{
    int a=0,b=0;
    double dis=0;
    friend bool operator < (edge p,edge q);

};
bool operator < (edge p,edge q)
{
    if(p.dis<q.dis) return true;
    return false;
}
struct point
{
    int x=0,y=0;
};
using namespace std;
int g[205];
void ini()
{
    for(int i=0;i<205;i++)
    {
        g[i]=i;
    }
}
int find(int a)
{
   if(a!=g[a])
   {
       g[a]=find(g[a]);
   }
   return g[a];
}
void Union(int x,int y)
{
    if(find(x)!=find(y))
    {
        g[g[x]]=g[y];
    }
}
int main()
{
    int n;
    int case_=1;
    while(cin>>n&&n!=0)
    {
        ini();
        point stone[205];
        edge E[50000];
        for(int i=0; i<n; i++)  cin>>stone[i].x>>stone[i].y;
        int ind=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                double tmp=(double)sqrt((stone[i].x-stone[j].x)*(stone[i].x-stone[j].x)+(stone[i].y-stone[j].y)*(stone[i].y-stone[j].y));
                E[ind].dis=tmp;
                E[ind].a=i;
                E[ind].b=j;
                ind++;
            }
        }
        sort(E,E+ind);
        bool one=false,two=false;

        double min=0;
        for(int i=0; i<ind; i++)
        {
            Union(E[i].a,E[i].b);
            if(min<E[i].dis) min=E[i].dis;
            if(find(0)==find(1)) break;
        }
        printf("Scenario #%d\n",case_);
        printf("Frog Distance = %.3f\n\n",min);
        case_++;
    }
    return 0;
}
