#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main()
{
   int n,m;
   while(cin >> n)
   {
      
      if(!n) break;
      cin >> m;
      vector<double> front,rear;
      front.clear(),rear.clear();
      for(int i=0;i<n;i++){ double tmp;cin >> tmp;front.push_back(tmp);}
      for(int i=0;i<m;i++){ double tmp;cin >> tmp;rear.push_back(tmp);}
      vector<double> radio;
      radio.clear();
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<m;j++)
         {

            radio.push_back((double)rear[j]/(double)front[i]);
         }
      }
      sort(radio.begin(),radio.end());
      double ans=0;
      for(int i=0;i<radio.size()-1;i++)
      {
         double tmp = radio[i+1]/radio[i];
         if(tmp>ans) ans = tmp;
      }
      printf("%.2lf\n",ans);
   }
   return 0;
}
