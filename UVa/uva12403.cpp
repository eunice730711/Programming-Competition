#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{

   int n;
   cin >> n;
   int count=0;
   while(n--)
   {
      string str="";
      int m;
      cin >> str;
      if(str=="report") cout << count << endl;
      else if(str=="donate") 
      {
         cin >> m;
         count +=m;
      } 
   
   }



   return 0;
}
