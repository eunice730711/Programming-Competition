#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
char first[105],second[105];
char stk[105];
int sidx;
void dfs(string s,int i,int o)
{
   if(i == strlen(first) && o == strlen(first)) 
   {
   		for(int j=0;j<s.length();j++)
      {
          if(j) cout << ' ';
          cout << s[j];
      }
      cout << endl;
   		return;
   }
   if(i<strlen(first)) 
   {
      stk[sidx++]=first[i];
      dfs(s+'i',i+1,o);
      sidx--;
   }
   if(i>o)
   {
      if(stk[sidx-1]==second[o])
      {
         sidx--;
         dfs(s+'o',i,o+1);
         sidx++;
         stk[sidx-1]=second[o];
      }
   }

}
int main()
{
   while(gets(first))
   {
     gets(second);
     stk[0]=first[0];
     sidx=1;
     cout << "[" << endl;
     if(strlen(first)==strlen(second)) dfs("i",1,0);
   	 cout << "]" << endl;
   }
   return 0;
}
