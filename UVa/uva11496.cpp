#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
   int n;
   while(cin >> n)
   {
      if(n==0) break;
      int arr[10005];
      for(int i=0;i<n;i++)
      {
         int music;
         cin >> music;
         arr[i]=music;
      }
      int ans=0,pre=arr[0],status=0,prestatus=0;
      for(int i=1;i<n;i++)
      {
         if(arr[i]<pre) status=-1;
         else if(arr[i]>pre) status=1;
         if(prestatus!=status && prestatus!=0) ans++;
         prestatus = status;
         pre = arr[i];
      }
      //cout << "ans: " << ans << endl;
      for(int i=0;i<2;i++)
      {
         if(arr[i]<pre) status=-1;
         else if(arr[i]>pre) status=1;
         if(prestatus!=status && prestatus!=0) ans++;
         prestatus = status;
         pre = arr[i];
      }
      cout << ans << endl;
   
   }



   return 0;
}
