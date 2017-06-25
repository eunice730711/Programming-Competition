#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int cas;
   cin >> cas;
   for(int c=1;c<=cas;c++)
   {
      int arr[3];
      cin >> arr[0] >> arr[1] >> arr[2];
      sort(arr,arr+3);
      cout << "Case " << c << ": " << arr[1] << endl;
   
   }


   return 0;

}
