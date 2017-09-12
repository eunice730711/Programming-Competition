#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
   // 解法：
   // 不要浮點數，故將所有數字乘100
   // 原來的平衡式： a + b + c + d = a * b * c * d
   // 會變成： 100(a+b+c+d) * 1000000 = 100a * 100b * 100c * 100d
   // 我們用的整數 A = 100a, B = 100b, C = 100c, D = 100d
   // (A+B+C+D) * 1000000 = A * B * C * D
   // 移項得到： D = (A+B+C) * 1000000 / (A*B*C-1000000)
   // reference: https://geniustanley.github.io/2017/02/15/UVa-11236-Grocery-store/
   
   for(int i=1;4*i<2000;i+=1)
   {
      for(int j=i;(i+3*j)<2000;j+=1)
      {
         for(int k=j;(i+j+2*k)<2000;k+=1)
         {
            long long p = i * k * j;
            long long s = i + k + j;
            if(p<=1000000) continue;
            if(s*1000000%(p-1000000)) continue;
            int d = s * 1000000 / (p -1000000);
            if(s+d>2000 || d<k) continue;
            printf("%.2lf %.2lf %.2lf %.2lf\n",(double)i/100.0,(double)j/100.0,(double)k/100.0,(double)d/100.0);

         }
      }
   }
   return 0;
}
