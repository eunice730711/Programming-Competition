#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
        int m,k;
        cin>>m>>k;
        long long int minn=0,maxn=0;
        int book[505];
        for(int i=0; i<m; i++)
        {
            cin>>book[i];
            if(minn<book[i])
            {
                minn=book[i];
            }
            maxn+=book[i];
        }
        long long int mid=0;
       // cout<<minn<<' '<<maxn<<endl;
        while(minn<maxn)
        {
            long long int sum=0,ans=1;
            mid=(minn+maxn)/2;
            for(int i=0; i<m; i++)
            {
                if(sum+book[i]>mid) sum=book[i],ans+=1;
                else sum+=book[i];
            }
            //printf("ans %d\n",ans);
            //printf("mid: %d\n",mid);

            if(ans<=k) maxn=mid;
            else minn=mid+1;
           // printf("max: %d,min: %d\n",maxn,minn);
        }
       // cout<<minn<<' '<<maxn<<endl;
        vector<int> job[505];
        long long int sum1=0;
        for(int i=m-1,j=k-1; i>=0 && j>=0 ; i--)
        {
            if(sum1+book[i]>minn || j>i)
            {
                sum1=book[i];
                j--;
                job[j].push_back(book[i]);

            }
            else
            {
                sum1+=book[i];
                job[j].push_back(book[i]);
            }
        }
        for(int i=0; i<k; i++)
        {
          // printf("i: %d : %d\n",i,job[i].size());
            for(int j=job[i].size()-1; j>=0; j--)
            {
                cout<<job[i][j];
                if(j!=0) cout<<' ';
            }
            if(i!=k-1) cout<<" / ";
            else if(i==k-1) cout<<endl;
        }
    }
    return 0;
}
