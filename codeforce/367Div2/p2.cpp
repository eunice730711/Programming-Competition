#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v;
        for(int i=0;i<n;i++) 
        {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        int day;
        vector<int>::iterator ind;
        cin >> day;
        for(int i=0;i<day;i++)
        {
            int m;
            cin >> m;
            
           ind=upper_bound(v.begin(),v.end(),m);
           cout << ind-v.begin()<< endl;  
        }
    }
    return 0;
}
