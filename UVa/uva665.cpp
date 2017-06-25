#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   for(int c=0;c<cas;c++)
   {
      if(c!=0) printf("\n");
      int n,k;
      bool arr[105];
      memset(arr,false,sizeof(arr));
      cin >> n >> k;
      for(int i=0;i<k;i++)
      {
         int num;
         bool vis[105];
         memset(vis,false,sizeof(vis));
         cin >> num;
         vector<int> ind;
         for(int j=0;j<num*2;j++) 
         {
            int index;
            cin >> index;
            ind.push_back(index);
            vis[index]=true;
         }
         char com;
         cin >> com;
         if(com=='=')
         {
            for(int j=0;j<ind.size();j++)
            {
               int k=ind[j];
               arr[k]=true;
            }
         }
         else
         {
            for(int j=1;j<=n;j++)
            {
               if(!vis[j]) arr[j]=true;   
            }
         }
      }
      int count=0,coin=0;
      for(int i=1;i<=n;i++)
      {
         if(!arr[i]) 
         {
            coin = i;
            count+=1;
         }
      }
      if(count==1) cout << coin << endl;
      else cout << 0 << endl; 
   }
   return 0;
}
