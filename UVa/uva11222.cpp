#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool com(pair<int,int> a, pair<int,int> b)
{
   return (a.first > b.first); 
}
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      vector<int> p[3];
      map<int,int> m;
      for(int i=0;i<3;i++)
      {
         int n;
         cin >> n;
         for(int j=0;j<n;j++)
         {
            int pro;
            cin >> pro;
            p[i].push_back(pro);
            m[pro]+=1;
         }
      }
      vector<pair<int,int> > ans;
      vector<int> problem[3];
      for(int i=0;i<3;i++)
      {
         for(int j=0;j<p[i].size();j++)
         {
            if(m[p[i][j]]<2)
            {
               problem[i].push_back(p[i][j]);
            }
         }   
         ans.push_back(make_pair(problem[i].size(),i));
      }
      sort(ans.begin(),ans.end(),com);
      //cout << "Case #" << c << ":" << endl;
      printf("Case #%d:\n",c);
      int pre=0;
      for(int i=0;i<3;i++)
      {
         pair<int,int> pp=ans[i];
         if(pp.first < pre) break; 
         //cout << pp.second+1 << ' ';
         //cout << pp.first << ' ';
         printf("%d %d",pp.second+1,pp.first);
         sort(problem[pp.second].begin(),problem[pp.second].end());
         for(int j=0;j<problem[pp.second].size();j++)
         {
           // cout << problem[pp.second][j];
            printf(" %d",problem[pp.second][j]);
            //if(j!=problem[pp.second].size()-1) printf(" ");
         }
         //cout << endl;
         printf("\n");
         pre = pp.first;
      }
   }
   return 0;
}
