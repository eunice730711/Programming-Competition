#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        vector<int> ind;
        map<int,int> ma;
        int arr[2005];
        int mean = n/m;
        
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            if(arr[i]<=m) ma[arr[i]]+=1;
            if((arr[i]<=m && ma[arr[i]]>mean) || arr[i]>m) ind.push_back(i);
        }
        int change = 0;
        for(int i=1;i<=m;i++)
        {
            while(ma[i]<mean)
            {
                int idx = ind.back();
                arr[idx] = i;
                ma[i] +=1;
                ind.pop_back();
                change +=1;
            }
        }
        cout << mean << ' ' << change << endl;
        for(int i=0;i<n;i++)
        {
            cout << arr[i];
            if(i!=n-1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}