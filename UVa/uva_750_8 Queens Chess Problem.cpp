//
//  main.cpp
//  uva750
//
//  Created by Emily on 2016/8/25.
//  Copyright © 2016年 Emily. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,sol=1;
int rows[10];
bool place(int row,int col)
{
    for(int pre=1;pre<=row-1;pre++)
    {
        if(col==rows[pre] || abs(col-rows[pre])==abs(row-pre))
            return false;
    }
    return true;
}
void getAns(int row)
{
    if(row==9) return;
    for(int col=1;col<=8;col++)
    {
            if(place(row,col))
            {
                rows[row]=col;
                //cout << "row " << row << ' ' << "col " << col <<  endl;
                if(row == 8 && rows[b]==a)
                {
                    //cout << "aa" << endl;
                    printf("%2d     ", sol++);
                    for(int i=1;i<=8;i++) printf(" %d",rows[i]);
                    puts("");
                    return;
                    
                    
                }
                getAns(row+1);
                
            }
        
    }
    //getAns(row+1);
    
}
int main(int argc, const char * argv[]) {
    
    int t;
    bool first=0;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(first) puts("");
        first=1;
        sol=1;
        memset(rows,0,sizeof(rows));
      
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8\n");
        
        
        //printf("aa\n");
        getAns(1);
    }
    return 0;
}
