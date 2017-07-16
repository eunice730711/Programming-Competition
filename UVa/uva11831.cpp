#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
int main()
{
  int n,m,s;
  // fstream outfile,infile;
  // infile.open("input.txt",ios::in);
  // outfile.open("output.txt",ios::out);
  while(cin >> n >> m >> s)
  {
      char arena[105][105],dir=' ';
      if(!n && !m && !s) break;
      string str="";
      int x=0,y=0;
      for(int i=0;i<n;i++)
      {
         cin >> str;
         for(int j=0;j<m;j++)
         {
            arena[i][j]=str[j];
            if(str[j]=='N'||str[j]=='S'||str[j]=='L'||str[j]=='O')
            {
               x=i,y=j,dir=str[j];
            }
         }
      }
      string instr="";
      cin >> instr;
      int sum=0;
      for(int i=0;i<s;i++)
      {
         if(dir=='N')
         {
            if(instr[i]=='F') 
            {
               if(x-1>=0 && arena[x-1][y]!='#') x-=1;
               if(arena[x][y]=='*')
               {
               	 	sum+=1;
               	 	arena[x][y]='.';
               }
            }
            else if(instr[i]=='D') dir='L';
            else dir='O';
         }
         else if(dir=='S')
         {
         	if(instr[i]=='F') 
            {
               if(x+1<n && arena[x+1][y]!='#') x+=1;
               if(arena[x][y]=='*')
               {
               	 	sum+=1;
               	 	arena[x][y]='.';
               }
            }
            else if(instr[i]=='D') dir='O';
            else dir='L';
         
         }
         else if(dir=='L')
         {
         	if(instr[i]=='F') 
            {
               if(y+1<m && arena[x][y+1]!='#') y+=1;
               if(arena[x][y]=='*')
               {
               	 	sum+=1;
               	 	arena[x][y]='.';
               }
            }
            else if(instr[i]=='D') dir='S';
            else dir='N';
         }
         else
         {
         	if(instr[i]=='F') 
            {
               if(y-1>=0 && arena[x][y-1]!='#') y-=1;
               if(arena[x][y]=='*')
               {
               	 	sum+=1;
               	 	arena[x][y]='.';
               }
            }
            else if(instr[i]=='D') dir='N';
            else dir='S';
         }
      }
      cout << sum << endl;
   
  }



   return 0;
}
