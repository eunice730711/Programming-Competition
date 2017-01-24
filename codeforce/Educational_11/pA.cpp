#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// int check(int a, int b)
// {
//     int r = a % b;
//     cout << "r: " << r << endl;
//     cout << "b: " << b << endl;
//     if(r==0) 
//     {
//         cout << "return: " << b << endl;
//         return b;
//     }      
//     else
//     {
//         cout << "else r: " << r << endl;
//         cout << "else b: " << b << endl;

//         b = check(b,r);
//     }
//     cout << "out" << endl;
//     return b;
// }
int gcd(int a, int b)
{
    return b ? gcd(b,a%b):a;
}
int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> ans;
        int arr[1005] , num=0;
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        for(int i=0;i<n-1;i++)
        {
            if(gcd(arr[i],arr[i+1])!=1)
            {
                ans.push_back(arr[i]);
                ans.push_back(1);
                num++;
            }
            else ans.push_back(arr[i]);
        }
        cout << num << endl;
        for(int i=0;i<ans.size();i++) cout << ans[i] << ' ';
        cout << arr[n-1] << endl;
    }
    return 0;
}