#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
int main()
{
   int n;
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(scanf("%d",&n)!=EOF)
   {
      if(n<=0) break;
      int per=0;
      set<set<int> > s;
      vector<int> v;
      map<int,bool> vis;
      for(int i=0;i<=20;i++)
      {
         for(int j=1;j<=3;j++)
         {
            if(!vis[i*j]) v.push_back(i*j);
            vis[i*j]=true;
         }
      }
      v.push_back(50);
      for(int i=0;i<v.size();i++)
      {
         for(int j=0;j<v.size();j++)
         {
            for(int k=0;k<v.size();k++)
            {
               if(v[i]+v[j]+v[k]==n)
               {
                  per+=1;
                  set<int> tmp;
                  tmp.insert(v[i]);
                  tmp.insert(v[j]);
                  tmp.insert(v[k]);
                  s.insert(tmp);
               }
            }
         }
      }
      if(per==0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
      else
      {
         printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %lu.\n",n,s.size());
         printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,per);
      }
      printf("**********************************************************************\n");
   
   }

   printf("END OF OUTPUT\n");


   return 0;
}
