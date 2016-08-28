#include<stdio.h>
#include<stdlib.h>
int store[35]= {0};
int main()
{
    long int input=0;
    scanf("%d",&input);
    while(input!=0)
    {
        int count_=0,p=0;
        while(input)
        {
            store[count_]=input%2;
            input=input/2;
            if(store[count_]==1) p++;
            count_++;

        }
        printf("The parity of ");
        for(int i=count_-1; i>=0; i--)
        {
            printf("%d",store[i]);
        }
        printf(" is %d (mod 2).\n",p);
        scanf("%d",&input);
    }
    return 0;
}
