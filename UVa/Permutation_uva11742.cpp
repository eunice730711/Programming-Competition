#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef pair<int,int> ii;
int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,m;
   while(scanf("%d%d",&n,&m)!=EOF)
   {
      if(!n && !m) break;
      int pos[10];
      for(int i=0;i<n;i++) pos[i]=i;//represent position of the number
      vector<pair<int,ii> > v;
      for(int i=0;i<m;i++)
      {
         int a,b,c;
         scanf("%d%d%d",&a,&b,&c);
         v.push_back(make_pair(c,ii(a,b)));
      }
      int ans=0;
      do
      {
         //for(int i=0;i<n;i++) printf("%d ",pos[i]);
         //cout << endl;
         bool flag = true;
         for(int i=0;i<m;i++)
         {
            int a,b,c;
            c = v[i].first;
            a = v[i].second.first, b = v[i].second.second;
            //cout << a << ' ' << b << ' ' << c << endl;
            if(c>0) 
            {
               if(abs(pos[a]-pos[b])>c)
               {
                  flag=false;
                  break;
               }
            }
            else if(c<0)
            {
               if(abs(pos[a]-pos[b])<-c)
               {
                  flag=false;
                  break;
               }
            }
         }
         if(flag) ans++;
         //cout << ans << endl;
      
      }while(next_permutation(pos,pos+n));
      printf("%d\n",ans);
   }
   return 0;
}
