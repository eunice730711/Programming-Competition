#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char arr[105][105];
int check(int r,int c,int m,int n)
{
    int ans=1;
    char ch=arr[r][c];
    int tmpr=r,tmpc=c,len=1,tmpi=-1,tmpj=-1;
    while(r-len>=0 && c-len>=0 && r+len<m &&c+len<n)
    {
        //cout<<"aa"<<endl;
        //cout<<r-len<<' '<<c-len<<' '<<r+len<<' '<<c+len<<endl;
        for(int i=r-len; i<=r+len; i++)
        {
            for(int j=c-len; j<=c+len; j++)
            {
                //cout<<"for "<<i<<' '<<j<<endl;
                if(arr[i][j]!=ch)
                {
                    //cout<<'k'<<endl;
                    tmpi=i,tmpj=j;
                    break;
                }
            }
            if((tmpi!=-1 || tmpj!=-1 ) && arr[tmpi][tmpj]!=ch ) break;
        }

        if((tmpi!=-1 || tmpj!=-1 ) && arr[tmpi][tmpj]!=ch )
        {
            //cout<<"a"<<tmpi<<' '<<tmpj<<endl;
            break;
        }
        ans+=2;
        len+=1;
    }
    return ans;

}
int main()
{
    int cas=0;
    cin>>cas;
    while(cas--)
    {
        int m,n,q;
        memset(arr,0,sizeof(arr));
        cin>>m>>n>>q;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
            }
        }
        cout<<m<<' '<<n<<' '<<q<<endl;
        for(int i=0; i<q; i++)
        {
            int r,c;
            cin>>r>>c;
            int ans=check(r,c,m,n);
            cout<<ans<<endl;

        }
    }




    return 0;
}
