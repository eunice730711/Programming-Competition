#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <bitset>
#include <cmath>
using namespace std;
bitset<1050> arr1,arr2;
int idx=0,filled=0;
void build(string str,int depth,bitset<1050> &b)
{
   int child = 0;
   int len = str.length();
   int pixel = 1024/pow(4,depth);
   while(idx<len)
   {  
      if(str[idx]=='p')
      {
         idx++;
         build(str,depth+1,b);
         child++;
      }
      else if(str[idx]=='e') 
      {
         for(int j=filled;j<filled+pixel;j++)
         {
            b.set(j,0);
         }
         filled+=pixel;
         idx++;
         child++;
      }
      else if(str[idx]=='f')
      {
         for(int j=filled;j<filled+pixel;j++) b.set(j,1);
         filled+=pixel;
         idx++;
         child++;
      }
      if(child==4) return;
   }
}
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      filled=0,idx=0;
      string str1,str2;
      cin >> str1 >> str2;
      build(str1,0,arr1);
      filled=0,idx=0;
      build(str2,0,arr2);
      bitset<1050> ans;
      ans =  arr1|arr2;
      printf("There are %lu black pixels.\n",ans.count());
   }
   return 0;
}
