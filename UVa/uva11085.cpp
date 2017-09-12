#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > queens;
void all()
{
   static const int arr[]={0,1,2,3,4,5,6,7};
   vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
   do
   {
      bool check = true;
      for(int i=0;i<8;i++)
      {
         for(int j=i+1;j<8;j++)
         {
            if(abs(i-j) == abs(vec[i]-vec[j]))
            {
               check = false;
               break;
            }
         
         }
      }
      if(check) queens.push_back(vec);
   }while(next_permutation(vec.begin(),vec.end()));
}
int main()
{
   all();
   int tmp,cas=1;
   while(scanf("%d",&tmp)!=EOF)
   {
      vector<int> input;
      input.push_back(tmp-1);
      for(int i=0;i<7;i++)
      {
         int in;
         scanf("%d",&in);
         input.push_back(in-1);
      }
      int ans=1e9;
      for(int i=0;i<queens.size();i++)
      {
         vector<int> v;
         v = queens[i];
         int minn=0;
         for(int j=0;j<8;j++)
         {
            if(abs(v[j]-input[j])) minn+=1;
         }
         ans = min(ans,minn);
      }
      printf("Case %d: %d\n",cas++,ans);
   }
   return 0;
}
