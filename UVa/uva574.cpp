#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
int main()
{
   int t,n;
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(scanf("%d%d",&t,&n)!=EOF)
   {
      if(!n && !t) break;
      int arr[15];
      for(int i=0;i<n;i++) scanf("%d",&arr[i]);
      //printf("%f\n",pow(2,n));
      map<vector<int>, bool> m;
      vector<vector<int> > ans;
      for(int i=0;i<(int)pow(2,n);i++)
      {
         //bitset<6> b(i);
         //cout << b << endl;
         int sum=0;
         vector<int> v;
         for(int j=0;j<n;j++)
         {
            if(i & (1<<j))
            {
               sum += arr[j];
               v.push_back(arr[j]);
            }
         }
         if(sum==t && !m[v])
         {
           // printf("IN\n");
            m[v]=true;
            ans.push_back(v);
         }
      }
      printf("Sums of %d:\n",t);
      if(!ans.size()) printf("NONE\n");
      else 
      {
         sort(ans.begin(),ans.end());
         reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++)
         {
            for(int j=0;j<ans[i].size();j++)
            {
               printf("%d",ans[i][j]);
               if(j!=ans[i].size()-1) printf("+");
            }
            printf("\n");
         }
      
      }
   
   
   
   }



   return 0;
}
