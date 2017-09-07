#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int test;
   cin >> test;
   while(test--)
   {
      int n;
      cin >> n;
      int a[5005];
      for(int i=0;i<n;i++)
      {
         cin >> a[i];
      }
      int sum=0;
      for(int i=1;i<n;i++)
      {
         for(int j=i-1;j>=0;j--)
         {
            if(a[j]<=a[i]) sum+=1;
         }
      }
      cout << sum << endl;
   
   }


   return 0;
}
