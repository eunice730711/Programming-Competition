#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int arr[10005]= {0};
int main()
{
    int n,q,cas=1;
    while(cin>>n>>q && n!=0 ||q!=0)
    {
        //cout<<n<<' '<<q<<endl;
        memset(arr,0,sizeof(arr));
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);

        printf("CASE# %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            int ques;
            cin>>ques;
            //int *ind;
            std::vector<int> v(arr,arr+n);
            auto ind=lower_bound(v.begin(),v.end(),ques);

            if(v[ind-v.begin()]==ques) printf("%d found at %d\n",ques,ind-v.begin()+1);
            else printf("%d not found\n",ques);
        }
    }







    return 0;
}
