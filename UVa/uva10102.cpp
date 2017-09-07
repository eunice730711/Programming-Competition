#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
typedef pair<int,int> ii;
int main()
{
   //fstream outfile,infile;
   //infile.open("in.txt",ios::in);
   //outfile.open("out.txt",ios::out);
   int m;
   while(cin >> m)
   {
      string str[10000];
      for(int i=0;i<m;i++)
      {
         cin >> str[i];
      //   cout << str[i] << endl;
      }
      vector<ii> one,three;
      for(int i=0;i<m;i++)
      {
         for(int j=0;j<m;j++)
         {
            if(str[i][j]=='1') one.push_back(ii(i,j));  
            else if(str[i][j]=='3') three.push_back(ii(i,j));
         }
      }
      int ans=0;
      for(int i=0;i<one.size();i++)
      {
      //   cout << "i: " << i << endl;
         int idv=1e9;
         for(int j=0;j<three.size();j++)
         {
            ii pos1=one[i],pos2=three[j];
            int x1=pos1.first,y1=pos1.second,x2=pos2.first,y2=pos2.second;
            int dis = abs(x1-x2)+abs(y1-y2);
        //    cout << "dis: " << dis << endl; 
            idv = min(idv,dis);
         }
         ans = max(idv,ans);
      }
      cout << ans << endl;
   }

   return 0;
}
