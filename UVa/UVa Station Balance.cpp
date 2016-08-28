#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef pair<double,double> ii;
int main()
{
    int c,s;
    int cas=1;
    while(cin>>c>>s)
    {
        double chamber[1005]={0.0},total=0;

        double avg=0,bala=0;
        memset(chamber,0,sizeof(chamber));
        vector<double> ch;
        vector<ii> col;
        for(int i=0;i<s;i++)
        {
            double mass=0;
            cin>>mass;
            chamber[i]=mass;
            total+=mass;
        }
        avg=(double)total/(double)c;
        //cout<<avg<<endl;

        for(int i=0;i<2*c;i++)
        {
            //cout<<chamber[i]<<endl;
            ch.push_back(chamber[i]);
            //bala+=abs(chamber[i]-avg);
        }

        sort(ch.begin(),ch.end());
        vector<double> re(ch);
        reverse(re.begin(),re.end());

        for(int i=0;i<c;i++)
        {
        //cout<<ch[i]<<' '<<re[i]<<endl;
           col.push_back(ii(ch[i],re[i]));
        }
        printf("Set #%d\n",cas);
        for(int i=0;i<c;i++)
        {
            if(col[i].first==0 && col[i].second==0) printf(" %d:\n",i);
            else if(col[i].first==0) printf(" %d: %.0f\n",i,col[i].second);
            else if(col[i].second!=0) printf(" %d: %.0f %.0f\n",i,col[i].first,col[i].second);

            double tmp=col[i].first+col[i].second;
            //cout<<tmp<<endl;
            bala+=abs(tmp-avg);
            //cout<<bala<<endl;

        }
        printf("IMBALANCE = %.5f\n",bala);
        cout<<endl;
        cas++;
    }





    return 0;
}
