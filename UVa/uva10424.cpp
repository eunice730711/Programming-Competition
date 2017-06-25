#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<char,int> m;
int caculate(string a)
{
 transform(a.begin(),a.end(),a.begin(),::tolower);
 int num=0,ans=0;
 for(int i=0;i<a.length();i++)
 {
   num+=m[a[i]];
 }
 while(num>=10)
 {
  ans=0;
  while(num>0)
  {
   ans+=num%10;
   num/=10;
  }
  num=ans;
 }
 return num;
}
int main()
{
 string str1,str2;
 char ch='a';
 for(int i=1;i<=26;i++)
 {
   m[ch]=i;
   ch+=1;
 }
 while(getline(cin,str1) && getline(cin,str2))
 {
    int n1=0,n2=0;
    n1 = caculate(str1);  
    n2 = caculate(str2);
    double ans;
    if(n1>n2) ans = (double)n2/(double)n1 * 100; 
    else ans = (double)n1/(double)n2 * 100;
    if(ans<=100) printf("%.2lf %%\n",ans);
    else printf("100.00 %%\n");
 }



 return 0;
}
