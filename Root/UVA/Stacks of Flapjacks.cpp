            // 120 - Stacks of Flapjacks
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int stack[100] , n;
int getmax(int upto)
{
    int i,maxi,pos;
    maxi = -1;
    for(i=0;i<=upto;i++)
        if(stack[i] > maxi)
            maxi = stack[i] , pos = i;
    return pos;
}
void flip(int upto)
{
    int tmp,i,mid = upto/2;
    for(i=0;i<=mid;i++)
    {
        tmp = stack[i];
        stack[i] = stack[upto-i];
        stack[upto-i] = tmp;
    }
}
void solve()
{
    int i,maxpos;
    for(i=n-1;i>0;i--)
    {
        maxpos = getmax(i);
        if(stack[maxpos] != stack[i])
        {
            if(stack[maxpos] != stack[0])
            {
                flip(maxpos);
                printf("%d ",n-maxpos);
            }
            flip(i);
            printf("%d ",n-i);
        }
    }
}
int main()
{
    char *str,line[1000];
    while(scanf(" %[^\n]",line) == 1)
    {
        n = 0;
        printf("%s\n",line);
        str = strtok(line," ");
        while(str)
        {
            stack[n++] = atoi(str);
            str = strtok(NULL," ");
        }
        solve();
        printf("0\n");
    }
    return 0;
}
