#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    int n,c=1;
    while(cin>>n&&n!=0)
    {

        int arr[55]={0},sum=0;
        for(int i=0;i<n;i++){ cin>>arr[i]; sum+=arr[i];}
        int ave=sum/n,moves=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<ave)
            {
                moves+=(ave-arr[i]);
            }
        }
        cout<<"Set #"<<c<<endl;
        cout<<"The minimum number of moves is "<<moves<<'.'<<endl;
        cout<<endl;
        c++;

    }



    return 0;
}
