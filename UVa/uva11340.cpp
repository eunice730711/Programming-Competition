#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      map<char,int> value;
      int k;
      cin >> k;
      for(int i=0;i<k;i++)
      {
         char ch;
         int p;
         cin >> ch >> p;
         value[ch]=p;
      }
      int pay=0;
      scanf("%d ",&k);
      for(int i=0;i<k;i++)
      {
         string input;
         getline(cin,input);
         int len = input.length();
         for(int j=0;j<len;j++)
         {
            pay+=value[input[j]];
         }
      }
      printf("%.2lf$\n",pay/100.0); 
   }
   return 0;
}
