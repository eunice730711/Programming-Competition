#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Print(char in[],char s[][105])
{
    int i,j;
    for(i=0; in[i]!='<'; i++) printf("%c",in[i]);
    for(i++,j=0; in[i]!='>'; i++,j++) s[2][j]=in[i];
    s[2][j] = '\0';
    for(i++,j=0; in[i]!='<'; i++,j++) s[3][j]=in[i];
    s[3][j] = '\0';
    for(i++,j=0; in[i]!='>'; i++,j++) s[4][j]=in[i];
    s[4][j] = '\0';
    for(i++,j=0; in[i]; i++,j++) s[5][j]=in[i];
    s[5][j] = '\0';
    printf("%s%s%s%s",s[2],s[3],s[4],s[5]);
}
void Print1(char in1[],char s[][105])
{
    int i;
    for(i=0; in1[i]!='.'; i++) printf("%c",in1[i]);
    printf("%s%s%s%s",s[4],s[3],s[2],s[5]);
}
int main()
{
    int n=0;
    char in[105]="",in1[105]="",s[6][105];
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
    {
        fgets(in,sizeof(in),stdin);
        fgets(in1,sizeof(in1),stdin);
        int num=strlen(in);
        Print(in,s);
        Print1(in1,s);
    }
    return 0;
}
