#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n&&n!=0)
    {
        int arr[105]={0},temp=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            arr[temp]+=1;
        }
        for(int i=1;i<=100;i++)
        {
            while(arr[i]!=0)
            {
                 printf("%d ",i);
                 arr[i]-=1;
            }
        }
        printf("\n");

    }
    return 0;
}
