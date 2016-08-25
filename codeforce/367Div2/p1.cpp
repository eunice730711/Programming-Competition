#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    
    double n,a,b;
    while(cin >> a >> b)
    {
        cin >> n;
        double min=1e10;
        for(int i=0;i<n;i++)
            
        {
            long double x,y,s;
            cin >> x >> y >> s;
            double dis=sqrt((x-a)*(x-a)+(y-b)*(y-b))/s;
            if(dis<=min) min=dis;
            
        }
        printf("%7lf\n",min);
        
    }
    return 0;
}
