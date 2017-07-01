#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int main()
{
   int cas;
   bool first = true;
   cin >> cas;
   while(cas--)
   {
      if(!first) printf("\n");
      first = false;
   
      int b,sg,sb;
      cin >> b >> sg >> sb;
      multiset<int,greater<int> > green,blue;
      for(int i=0;i<sg;i++)
      {
         int k;
         cin >> k;
         green.insert(k);
      }
      for(int i=0;i<sb;i++)
      {
         int k;
         cin >> k;
         blue.insert(k);
      }
      int win=0;
      vector<int> bfighter,gfighter;
      int field=b;
      while(!green.empty() && !blue.empty())
      {
         field=min(b,min((int)green.size(),(int)blue.size()));
         int k=0;
         for(multiset<int>::iterator it=green.begin();k<field;k++)
         {
            gfighter.push_back(*it);
            green.erase(it++);
            //it++;
         }
         k=0;
         for(multiset<int>::iterator it=blue.begin();k<field;k++)
         {
            bfighter.push_back(*it);
            blue.erase(it++);
            //it++;
         }
         for(int i=0;i<field;i++)
         {
            int gf,bf;
            gf=gfighter[i];
            bf=bfighter[i];
            if(gf>bf) 
            {
               gf-=bf;
               green.insert(gf);
            }
            else if(bf>gf)
            {
               bf-=gf;
               blue.insert(bf);
            }
         }
         //cout << "aa" << endl;
         gfighter.clear();
         bfighter.clear();
         if(blue.empty() && green.empty())
         {
            break;
         }
         else if(blue.empty())
         {
            win=1;
            break;
         }
         else if(green.empty())
         {
            win=2;
            break;
         }
      }
      if(win == 0)
      {
         printf("green and blue died\n");
      }
      else if(win==1)
      {
         printf("green wins\n");
         for(multiset<int>::iterator it=green.begin();it!=green.end();it++)
         {
            cout << *it << endl;      
         }
      }
      else if(win==2)
      {
         printf("blue wins\n");
         for(multiset<int>::iterator it=blue.begin();it!=blue.end();it++)
         {
            cout << *it << endl;
         }
      }
      
   }
   return 0;
}
