#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
 int cas;
 cin >> cas;
 while(cas--)
 {
   int arr[3][3];
   string str="";
   for(int i=0;i<3;i++)
   {
      string input="";
      cin >> input;
      for(int j=0;j<3;j++)
      {
         arr[i][j]=input[j]-'0';
      }
      str+=input;
   }
   string first = str;
   int ans=0;
   if(str=="000000000")
   {
      cout << "-1" << endl;
      continue;
   }
   while(str!="000000000")
   {
      str = "";
      for(int i=0;i<3;i++)
      {
         for(int j=0;j<3;j++)
         {
            int num=0;
            if(i-1>=0) num+=arr[i-1][j];
            if(i+1<3) num+=arr[i+1][j];
            if(j+1<3) num+=arr[i][j+1];
            if(j-1>=0) num+=arr[i][j-1];
            str+=(num%2+'0');
         }
      }
      int ind=0;
      for(int i=0;i<3;i++)
         for(int j=0;j<3;j++)
            arr[i][j]=str[ind]-'0',ind++;
      if(str!=first && str!="000000000") ans++;
   }
   cout << ans << endl;
 }
 return 0;
}
