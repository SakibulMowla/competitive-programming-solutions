#include <stdio.h>

int main()
{
    int val,n,curmax,max;
    while(scanf("%d",&n) == 1 && n)
    {
        max = -1;
        curmax = 0;
        while(n--)
        {
            scanf("%d",&val);
            curmax += val;
            if(curmax > max)
                max = curmax;
            if(curmax < 0)
                curmax = 0;
        }
        if(max <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n",max);
    }

    return 0;
}
