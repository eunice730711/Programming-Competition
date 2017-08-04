#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
bool check(string tmp,string si)
{
   map<char,bool> m;
   for(int i=0;i<5;i++)
   {
      if(m[si[i]]) return false;
      m[si[i]]=true;
   }
   for(int i=0;i<5;i++)
   {
      if(m[tmp[i]]) return false;
      m[tmp[i]]=true;
   }
   return true;
}
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n;
   bool first = true;
   while(scanf("%d",&n)!=EOF)
   {
      if(!n) break;
      int ans=0;
      if(!first) {
         printf("\n");
      }
      first = false;
      for(int i=1234;i<=98765;i++)
      {
         int tmp = i*n;
         if(i*n>98765) break;

         string s = to_string(tmp);
         if(s.length()==4) s = '0' + s;
         string si = to_string(i);
         if(si.length()==4) si = '0'+si;
         bool flag = check(s,si);
         
         if(flag)
         {
            printf("%s / %s = %d\n",s.c_str(),si.c_str(),n);
            ans++;
         }
      
      }
      if(ans==0) printf("There are no solutions for %d.\n",n);
   }
   return 0;
}
