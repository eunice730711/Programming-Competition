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
   while(scanf("%d",&n)!=EOF)
   {
      if(n<=0) break;
      vector<int> v;
      map<int,bool> vis;
      for(int i=0;i<=20;i++)
      {
         for(int j=1;j<=3;j++)
         {
            if(!vis[i*j])
            {
               for(int k=0;k<3;k++) v.push_back(i*j);
            }
            vis[i*j]=true;
         }
      }
      for(int i=0;i<3;i++) v.push_back(50);
      sort(v.begin(),v.end());
      int j,k,com=0,per=0;
      map<set<int>,bool> check;
      for(int i=0;i<v.size()-2;i++)
      {
         j=i+1;
         k=v.size()-1;
         while(j<k)
         {
            int sum = v[i]+v[j]+v[k];
            if(sum==n) 
            {
               set<int> tmp;
               tmp.insert(v[i]);
               tmp.insert(v[j]);
               tmp.insert(v[k]);
               if(!check[tmp])
               {
                  com+=1;
                  if(v[i]!=v[j] && v[j]!=v[k] && v[k]!=v[i])
                  {
                     per+=6;
                  }
                  else if(v[i]==v[j] && v[j]==v[k])
                  {
                     per+=1;
                  }
                  else per+=3;
               }
               check[tmp]=true;
               j++;
               k--;
            }
            else (sum>n) ? k-=1:j+=1;
         }
      }
      if(per==0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
      else
      {
         printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n,com);
         printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",n,per);
      }
      printf("**********************************************************************\n");                      
   }
   printf("END OF OUTPUT\n");
   return 0;
}
