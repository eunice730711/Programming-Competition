#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef pair<int,int> ii;
int main()
{
   int test;
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   scanf("%d",&test);
   map<ii,int> idx;
   map<int,ii> pos;
   int num=0;
   for(int i=0;i<5;i++)
   {
      for(int j=0;j<5;j++)
      {
         ii tmp = ii(i,j);
         idx[tmp]=num;
         pos[num]=tmp;
         num++;
      }
   }
   while(test--)
   {
      int n;
      scanf("%d",&n);
      vector<ii> save;
      vector<int> v[30];
      for(int i=0;i<n;i++)
      {
         int a,b,popu;
         scanf("%d %d %d",&a,&b,&popu);
         save.push_back(ii(a,b));
         for(int j=0;j<25;j++)
         {
            ii position = pos[j];
            int dis = popu * (abs(position.first-a)+abs(position.second-b));
            v[j].push_back(dis);
         }
      }
      int ans[5];
      int sum=1e9;
      for(int i=0;i<25;i++)
      {
         for(int j=i+1;j<25;j++)
         {
            for(int k=j+1;k<25;k++)
            {
               for(int p=k+1;p<25;p++)
               {
                  for(int q=p+1;q<25;q++)
                  {
                     int tmp=0;
                     for(int a=0;a<n;a++)
                     {
                        int minn = 1e9;
                        minn = min(minn,v[i][a]);
                        minn = min(minn,v[j][a]);
                        minn = min(minn,v[k][a]);
                        minn = min(minn,v[p][a]);
                        minn = min(minn,v[q][a]);
                        tmp += minn;
                     }
                     if(tmp<sum)
                     {
                        sum = tmp;
                        ans[0]=i,ans[1]=j,ans[2]=k,ans[3]=p,ans[4]=q;
                     }
                  }
               }
            }
         }
      }
      printf("%d",ans[0]);
      for(int i=1;i<5;i++) printf(" %d",ans[i]);
      printf("\n");
   
   }

   return 0;
}
