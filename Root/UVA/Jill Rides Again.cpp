#include <stdio.h>

#define SZ 20001
#define inf 1<<30

int main()
{
    int dp[SZ],t=0,test,n,max,curmax,maxa0,maxan,a0,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n-1;i++)
            scanf("%d",&dp[i]);
        max = -inf , curmax = 0 , maxa0 = 1 , maxan = 1 , a0 = 1;
        for(i=0;i<n-1;i++)
        {
            curmax += dp[i];
            if(curmax > max || (curmax == max && (i+2-a0 > maxan - maxa0)))
                max = curmax , maxa0 = a0 , maxan = i+2;
            if(curmax < 0)
                curmax = 0 , a0 = i+2 ;
        }
        if(max <= 0)
            printf("Route %d has no nice parts\n",++t);
        else
            printf("The nicest part of route %d is between stops %d and %d\n",++t,maxa0,maxan);
    }
    return 0;
}
