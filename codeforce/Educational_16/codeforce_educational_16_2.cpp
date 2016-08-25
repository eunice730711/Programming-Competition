//
//  main.cpp
//  codeforceEducational16
//
//  Created by Emily on 2016/8/25.
//  Copyright © 2016年 Emily. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int arr[300005];
int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n)
    {
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
            
        }
        sort(arr,arr+n);
        if(n%2!=0)cout << arr[n/2] << endl;
        else cout << arr[n/2-1] << endl;
    }
    return 0;
}
