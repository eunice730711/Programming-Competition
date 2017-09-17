#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n;
   while(scanf("%d",&n)!=EOF)
   {
      vector<int> v;
      for(int i=0;i<n;i++)
      {
         int tmp;
         scanf("%d",&tmp);
         v.push_back(tmp);
      }
      sort(v.begin(),v.end());
      int money;
      scanf("%d",&money);
      int s=0,d=n-1,sum;
      pair<int,int> book;
      while(d>s)
      {
         sum = v[s]+v[d];
         if(sum==money)
         {
            book.first = v[s];
            book.second = v[d];
            s++;
            d--;
         }
         else if(sum>money)
         {
            d--;
         }
         else s++;
      }
      printf("Peter should buy books whose prices are %d and %d.\n",book.first,book.second);
      printf("\n");
   
   
   }


   return 0;
}
