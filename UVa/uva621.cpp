#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char check(string s)
{
   int len=s.length();
   if(s[len-1]=='5'&&s[len-2]=='3') return '-';
   else if(s[0]=='9'&&s[len-1]=='4') return '*';
   else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0') return '?';
   else return '+';
}
int main()
{
   int cas;
   cin >> cas;
   while(cas--)
   {
      string input;
      cin >> input;
      char ans = check(input);
      cout << ans << endl;
   
   }
   



   return 0;
}
