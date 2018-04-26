#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;
vector<vector<char> > v;
vector<string> possible;
int k,count_=0;
string myans;
void permutation(int len,string str)
{
	// string tmp="";
	if(len == 5)
	{
		count_+=1;
		if(count_ == k) myans = str;
		// if(count_ == k) return str;

	}
	for(int i=0;i<v[len].size();i++)
	{
		str += v[len][i];
		permutation(len+1,str);
		str = str.substr(0,str.length()-1);
	}
	// return tmp;
}
int main()
{
   int test;
   // fstream infile,outfile;
   // infile.open("in.txt",ios::in);
   // outfile.open("out.txt",ios::out);
   cin >> test;
   while(test--)
   {
   	  count_ =0;
   	  myans = "";
      cin >> k;
      string str1[7],str2[7];
      v.clear();
      possible.clear();
      for(int i=0;i<6;i++) cin >> str1[i];
      for(int i=0;i<6;i++) cin >> str2[i];
	  for(int i=0;i<5;i++)
	  {
	  	vector<char> tmp;
	  	map<char,bool> check;
	  	for(int j=0;j<6;j++)
	  	{
	  		for(int k=0;k<6;k++)
	  		{
	  			if(str1[j][i]==str2[k][i])
	  			{
	  				if(!check[str1[j][i]]) tmp.push_back(str1[j][i]);
	  				check[str1[j][i]] = true;
	  			}
	  		}
	  	}
	  	sort(tmp.begin(),tmp.end());
	  	v.push_back(tmp);
	  }
	  string str="";
	  permutation(0,str);
	  if(count_<k) cout << "NO" << endl;
	  else cout << myans << endl;
	  // for(int i=0;i<v.size();i++) 
	  // {
	  // 	for(int j=0;j<v[i].size();j++)
	  // 		printf("%c ",v[i][j]);
	  // 	printf("\n");
	  // }
	  
   }



   return 0;
}
