#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
   string input;
   int c=1;
   while(cin >> input)
   {
      if(input=="*") break;
      if(input=="Hajj") printf("Case %d: Hajj-e-Akbar\n",c++);
      else if(input=="Umrah") printf("Case %d: Hajj-e-Asghar\n",c++);
      
   }



   return 0;
}
