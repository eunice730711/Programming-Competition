#include<stdio.h>
int main()
{
    int vt=0,v0=0;
    scanf("%d%d",&vt,&v0);
    while(vt!=0||v0!=0)
    {
        int r=0;
        r=vt%(2*v0);
        if(r!=0)
        {
            if(r==v0)
            {
                printf("0\n");
            }
            else if(r<v0)
            {
                printf("%d\n",vt/(2*v0));
            }
            else
            {
                printf("%d\n",vt/(2*v0)+1);
            }
        }
        else
        {
            printf("%d\n",vt/(2*v0));
        }
        scanf("%d%d",&vt,&v0);
    }
    return 0;
}
