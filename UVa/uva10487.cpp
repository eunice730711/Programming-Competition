#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
int main()
{
   int n;
   int cas=1;
   // fstream outfile,infile;
   // infile.open("in.txt",ios::in);
   // outfile.open("out.txt",ios::out);
   while(cin >> n)
   {
      if(!n) break;
      int arr[1005],ask;
      for(int i=0;i<n;i++) cin >> arr[i];
      sort(arr,arr+n);
      cout << "Case " << cas++ << ":" << endl;
      int m;
      cin >> m;
      for(int i=0;i<m;i++)
      {  
         cin >> ask;
         int sum=0,diff=1e9,tmp,p=0,q=n-1,ans;
         do
         {
            sum = arr[p]+arr[q];
            if(sum > ask)
            {
               q-=1;
               tmp = abs(sum-ask);
               if(tmp<= diff)
               {
                  ans = sum;
                  diff = tmp;
               }
            }
            else if(sum < ask)
            {
               p+=1;
               tmp = abs(sum-ask);
               if(tmp <= diff)
               {
                  ans = sum;
                  diff = tmp;
               }
            }
            else
            {
               ans = sum;
               break;
            }                   
         }while(p<q);
         cout << "Closest sum to " << ask << " is " << ans << "." << endl;
      
      }
      
   }

   return 0;
}
