#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
   int cas=1;
   string str;
   while(cin >> str)
   {
      if(str=="end") break;
      int length[1005];
      for(int i=0;i<1005;i++) length[i]=1;
      int n = str.length();
      for(int i=0;i<n;i++)
      {
         for(int j=i+1;j<n;j++)
         {
            if(str[i]<str[j])
            {
               length[j]=max(length[j],length[i]+1);
            }
         }
      }
      int ans=0;
      for(int i=0;i<n;i++) ans=max(ans,length[i]);
      printf("Case %d: %d\n",cas++,ans); 
   }
   return 0;
}
