#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map_[66]="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
              "abcdefghijklmnopqrstuvwxyz"
              "0123456789+/=";
bool check(char test)
{
    for(int i=0; i<65; i++)
    {
        if(test==map_[i])
        {
            return true;
        }
    }
    return false;
}
int decode(char input[])
{

    int intToBinary=0,j=0;
    for(int i=0; i<4; i++)
    {
        if(input[i]=='=')
        {
            intToBinary=intToBinary<<=6;
        }
        else
        {
            for(j=0; j<66&&input[i]!=map_[j]; j++);
            intToBinary=(intToBinary<<6)+j;
        }
    }
    printf("%c",intToBinary>>16);
    if(input[2]!='=')
        printf("%c",intToBinary>>8);
    if(input[3]!='=')
        printf("%c",intToBinary);

}
int main()
{
    char input[4]="",in=' ';
    while(scanf("%c",&in)==1)
    {
        char pre=' ';
        for(int i=0; i<4; )
        {
            if(in=='#')
            {
                if(pre=='#') break;
                printf("#");
                pre='#';
            }
            else if(check(in)==true)
            {
                input[i]=in;
                i++;
                pre=in;
            }
            else
            {
                pre=' ';
            }
           if(i!=4){ scanf("%c",&in);}
        }
        if(pre=='#') break;
        decode(input);
    }
    return 0;
}
