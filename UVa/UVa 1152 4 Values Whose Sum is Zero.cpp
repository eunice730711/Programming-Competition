#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<unordered_map>
using namespace std;
int arr[4005][4];
int aaa[16000005],bbb[16000005];

int main()
{
    int cas;
    cin>>cas;
    while(cas--)
    {
        int n;
        cin>>n;
        memset(arr,0,sizeof(arr));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>arr[i][j];
            }
        }
        int ind1=0,ind2=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                aaa[ind1++]=arr[i][0]+arr[j][1];
                bbb[ind2++]=0-(arr[i][2]+arr[j][3]);
            }
        }
        //cout<<"ind"<<ind1<<' '<<ind2<<' '<<endl;
        unordered_map<long long int ,long long int> save;
        for(int i=0; i<ind1; i++)
        {
            save[aaa[i]]+=1;
            //cout<<"i "<<i<<' '<<aaa[i]<<endl;
        }
       // cout<<save.size()<<endl;
        sort(bbb,bbb+ind2);
        int num=0;
        for(int i=0; i<ind2; i++)
        {
            num+=save[bbb[i]];
        }
        cout<<num<<endl;
        for(int i=0;i<ind1;i++)
        {
            aaa[i]=0,bbb[i]=0;
        }
        cout<<endl;
    }



    return 0;
}
