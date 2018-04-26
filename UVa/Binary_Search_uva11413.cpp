#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
// Binary Search for the Answer
int n,v;
int arr[1005];
bool container(int mid)
{
   int cap=0,count=1;
   for(int i=0;i<n;i++)
   {
      if(arr[i]>mid) return false;
      cap+=arr[i];
      if(cap>mid) 
      {
         cap=0;
         count+=1;
         if(count>v) return false;
         i-=1;
      }
      else if(cap==mid) 
      {
         cap=0;
         if(i!=n-1) count+=1;
         if(count>v) return false;
      }
   }
   return true;

}
int binary_search(int l,int r)
{
   if(l>=r) return l;
   int mid = (l+r)/2;
   bool check = container(mid);
   if(check) return binary_search(l,mid);
   return binary_search(mid+1,r);
}
int main()
{
   while(scanf("%d%d",&n,&v)!=EOF)
   {
      memset(arr,0,sizeof(arr));
      int right=0,left=0;
      for(int i=0;i<n;i++) 
      {
         scanf("%d",&arr[i]);
         if(arr[i]>left) left = arr[i];
         right += arr[i];
      }
      printf("%d\n",binary_search(left,right));
   }
   return 0;
}
