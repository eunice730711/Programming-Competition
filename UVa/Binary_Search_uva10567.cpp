#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
string input,queue;
vector<vector<int> > v;

int main()
{
   fstream infile,outfile;
   //infile.open("in.txt",ios::in);
   //outfile.open("out.txt",ios::out);
   cin >> input;
   v.resize(256);
   for(int i=0;i<input.length();i++)
   {
      v[input[i]].push_back(i);
   }
   int q;
   cin >> q;
   for(int i=0;i<q;i++)
   {
      cin >> queue;
      int idx=-1,a=0;
      bool found=true;
      for(int j=0;j<queue.size();j++)
      {
         vector<int>::iterator low = upper_bound(v[queue[j]].begin(),v[queue[j]].end(),idx);
         idx = low - v[queue[j]].begin();
         if(low==v[queue[j]].end())
         {
            found = false;
            break;
         }
         idx = v[queue[j]][idx];
         if(j==0) a = idx;
      }
      if(!found) printf("Not matched\n");
      else
      {
         printf("Matched %d %d\n",a,idx);
      }
   }



   return 0;
}
