#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
pair<int,int> s2m(int second)
{
   pair<int,int> p;
   int m = second/60;
   int s = second%60;
   p.first = m;
   p.second = s;
   return p;
}
int main()
{
   
    string str="";
    int num=1; 
    while(getline(cin,str))
    {   
         int arr[12],x=0;
         vector<int> vec;
         stringstream ss(str);         
         while(ss >> arr[x])
         {
            vec.push_back(arr[x]);
            x++;
         }
         bool first = true;
         int ans=0;
         for(int i=0;i<=3600;i++)
         {
            bool flag=true;
            for(int j=0;j<vec.size();j++)
            {
               int cycle = vec[j];
               if(i%(2*cycle)>=cycle-5)
               {
                  flag=false;
                  break;
               }
            }
            if(flag==false) first=false;
            if(first==false && flag==true){
               ans=i;
               break;
            } 

         }
         pair<int,int> final;
         final = s2m(ans);
         if(ans!=0) printf("Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n",num++,final.first,final.second);
         else printf("Set %d is unable to synch after one hour.\n",num++);
         //cout << final.first << ' ' << final.second << endl;
    
    }



   return 0;
}
