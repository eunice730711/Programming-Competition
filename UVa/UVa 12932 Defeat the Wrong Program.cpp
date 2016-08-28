#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
int main()
{
    int n,m,cas=1;
    while(cin>>n>>m)
    {
        int arr[505][505]= {{0}},row[505]= {0},col[505]= {0};
        int narr[505][505]= {{0}},maxr=0,maxc=0,idxr=0,idxc=0;
        vector<ii> ans;
        for(int i=0; i<n; i++)
        {
            int rowtmp=0;
            for(int j=0; j<m; j++)
            {
                cin>>arr[i][j];
                rowtmp+=arr[i][j];
            }
            row[i]=rowtmp;
            if(rowtmp>maxr) maxr=rowtmp,idxr=i;
        }
        for(int i=0; i<m; i++)
        {
            int coltmp=0;
            for(int j=0; j<n; j++)
            {
                coltmp+=arr[j][i];
            }
            col[i]=coltmp;
            if(coltmp>maxc) maxc=coltmp,idxc=i;
        }
        //cout<<"max "<<maxr<<' '<<maxc<<endl;
        //for(int i=0;i<n;i++) if(row[i]==maxr) idxr.push_back(i);
        //for(int j=0;j<m;j++) if(col[j]==maxc) idxc.push_back(j);

//        for(int i=0;i<idxr.size();i++)
//        {
//            for(int j=0;j<idxc.size();j++)
//            {
//                wans.push_back(ii(idxr[i],idxc[j]));
//            }
//        }

        int maxans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                narr[i][j]=row[i]+col[j]-arr[i][j];
                maxans=max(maxans,narr[i][j]);
            }
        }
        //cout<<"maxans "<<maxans<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(narr[i][j]==maxans)
                {
                    ans.push_back(ii(i,j));
                }
            }
        }
        //for(int i=0; i<ans.size(); i++) cout<<"a "<<ans[i].first<<' '<<ans[i].second<<endl;
        //  for(int j=0;j<wans.size();j++) cout<<"w "<<wans[j].first<<' '<<wans[j].second<<endl;

        //bool flag=true;
        ii wans(idxr,idxc);


        auto it=find(ans.begin(),ans.end(),wans);
        if(it==ans.end()) printf("Case %d: Strong\n",cas++);
        else printf("Case %d: Weak\n",cas++);






    }




    return 0;
}
