#include<stdio.h>
#include<string.h>
#include<ctype.h>

//存储输入的矩阵链条
char temp[1000];

//letter的结构体
typedef struct
{
    char lter;
    int row, column;
} Matrix;

Matrix stack[1000];

int main()
{
    int i, j, len, n, t, m, num, flag, rear, front, k;
    int row, column;
    Matrix Mtx[27];
    char letter;
    for(i=0; i<27; ++i)
        Mtx[i].row = Mtx[i].column = 0;
    scanf("%d", &n);

    //input part one
    for(t=1; t<=n; ++t)
    {
        getchar();
        scanf("%c", &letter);
        m = letter - 65;
        Mtx[m].lter = letter;
        scanf("%d", &Mtx[m].row);
        scanf("%d", &Mtx[m].column);
    }
    memset(temp, '\0', sizeof(temp));

    //input part two
    while(scanf("%s", temp) != EOF)
    {
        for(i=0; i<1000; ++i)
            stack[i].lter = '\0', stack[i].row = stack[i].column = 0;
        num = flag = 0;
        rear = front = 1;
        len = strlen(temp);

        //进栈各种情况判断
        //其中stack[0]存储当前与下一矩阵进行运算的矩阵元素
        for(i=0; i<len; ++i)
        {
            if(isalpha(temp[i]))
            {
                m = temp[i] - 65;
                if(stack[0].lter == '\0')
                {
                    stack[0].lter = temp[i];
                    stack[0].row = Mtx[m].row, stack[0].column = Mtx[m].column;
                }
                else
                {
                    if(stack[0].column != Mtx[m].row)
                    {
                        flag = 1;
                        break;
                    }
                    else
                    {
                        num += stack[0].row*stack[0].column*Mtx[m].column;
                        stack[0].column = Mtx[m].column;
                    }
                }
            }
            else if(temp[i] == '(')
            {
                if(stack[0].lter == '\0')
                {
                    stack[rear++].lter = temp[i];
                }
                else
                {
                    stack[rear++] = stack[0];
                    stack[rear++].lter = temp[i];
                    stack[0].lter = '\0';
                }
            }
            else
            {
                rear--;
                if(rear != front)
                {
                    rear--;
                    if(stack[rear].lter != '(')
                    {
                        if(stack[rear].column != stack[0].row)
                        {
                            flag = 1;
                            break;
                        }
                        else
                        {
                            num += stack[rear].row*stack[rear].column*stack[0].column;
                            stack[0].lter = stack[rear].lter;
                            stack[0].row =  stack[rear].row;
                        }
                    }
                    else rear++;


                }
            }
        }
        if(flag) printf("error\n");
        else printf("%d\n", num);
    }
    return 0;
}
