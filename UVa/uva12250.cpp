#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
int main()
{
   string str="";
   int cas=1;
   while(cin >> str)
   {
      if(str=="#") break;
      cout << "Case " << cas++ << ": ";
      if(str=="HELLO") cout << "ENGLISH" << endl;
      else if(str=="HOLA") cout << "SPANISH" << endl;
      else if(str=="HALLO") cout << "GERMAN" << endl;
      else if(str=="BONJOUR") cout << "FRENCH" << endl;
      else if(str=="CIAO") cout << "ITALIAN" << endl;
      else if(str=="ZDRAVSTVUJTE") cout << "RUSSIAN" << endl;
      else cout << "UNKNOWN" << endl;
   
   
   }


   return 0;
}
