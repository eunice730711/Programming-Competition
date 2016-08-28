#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map_[15]="AHIMO0TUVWXY18",map1[9]="EJLSZ235",map2[9]="3LJ25SEZ";
void Reverse(char str[],int len,char result[])
{
    int j=0;
    for(int i=len-1; i>=0; i--)
    {
        result[j]=str[i];
        j++;
    }
}
bool CheckPalindromes(char str[],int len,char re[])
{

    int check=0;
    for(check=0; check<len; check++)
    {
        if(str[check]!=re[check])
            return false;
    }
    return true;
}
bool CheckMirror(char str[],int len,char re[])
{
    for(int i=0; i<len; i++)
    {

        int x=0,y=0,flag=0;
        for(x=0; x<14&&map_[x]!=re[i]; x++);
        if(x<14)flag=1;
        else
        {
            for(y=0; y<8; y++)
            {
                if(re[i]==map1[y])
                {
                    re[i]=map2[y];
                    flag=1;
                    break;

                }
            }
        }
        if(flag!=1)
        {
            return false;
        }
    }
    int check=0;
    for(check=0; check<len; check++)
    {
        if(str[check]!=re[check])
            return false;
    }
    return true;
}
int main()
{
    char str[25]="";
    while(scanf("%s",str)!=EOF)
    {
        char re[25]="";
        int len=strlen(str);
        Reverse(str,len,re);
        bool palindromes=CheckPalindromes(str,len,re),mirror=CheckMirror(str,len,re);
        if(palindromes==false&&mirror==false)
        {
            printf("%s -- is not a palindrome.\n\n",str);
        }
        else if(palindromes==true&&mirror==false)
        {
            printf("%s -- is a regular palindrome.\n\n",str);
        }
        else if(palindromes==false&&mirror==true)
        {
            printf("%s -- is a mirrored string.\n\n",str);
        }
        else
        {
            printf("%s -- is a mirrored palindrome.\n\n",str);
        }
    }
    return 0;
}
