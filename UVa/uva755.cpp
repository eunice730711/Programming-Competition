#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
using namespace std;
map<char,int> m;
void mapping()
{
   char ch = 'A';
   for(int i=2;i<=9;i++)
   {
      //cout << ch << endl;
      for(int j=0;j<3;j++)
      {
         if((ch+j)=='Q') ch+=1;
         m[ch+j]=i;
      }
      ch +=3;
   }
}
void standard(string *str)
{
   int len = str->length();
   for(int i=0,j=0;i<len;i+=1,j+=1)
   {
      if((*str)[i]>='A' && (*str)[i]<='Y')
      {
         (*str)[j]=m[(*str)[i]]+'0';
      }
      else if((*str)[i]>='0' && (*str)[i]<='9')
      {
         (*str)[j]=(*str)[i];
      }
      else j-=1;
   }
   *str = str->substr(0,7);
   
   //cout << "output_in:" << (*str) << endl;
   //return str->substr(0,8);
}
int main()
{
   int test;
   cin >> test;
   mapping();
   for(int c=0;c<test;c++)
   {
      if(c!=0) printf("\n");
      map<string,int> count;
      int num;
      cin >> num;
      for(int i=0;i<num;i++)
      {
         string str;
         cin >> str;
         standard(&str);
      //   cout << "output: "<< str << endl;
         count[str]+=1;
      }
      vector<pair<string,int> > ans;
      for(map<string,int>::iterator it=count.begin();it!=count.end();it++)
      {
         if(it->second>1) 
         {
            pair<string,int> p;
            p.first = it->first;
            p.second = it->second;
            ans.push_back(p);
         }
      }
      if(ans.size()>0)
      {
         sort(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++)
         {
            cout << ans[i].first.substr(0,3) << '-' << ans[i].first.substr(3,7) << ' ' << ans[i].second << endl;       
         }

      }
      else printf("No duplicates.\n");
      


   
   }



   return 0;
}
