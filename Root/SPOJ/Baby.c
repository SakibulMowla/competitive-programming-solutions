#include "stdio.h"
#include "string.h"
#include "math.h"

#define MAX (1<<16)+2

const int inf = 1<<28;

int min(int a,int b)
{
    return a < b ? a : b;
}

int n , dp[MAX] , now[20] , dest[20];

int solve(int indx,int mask)
{
    int ret = dp[mask];
    if(ret != -1) return ret;

    if(!mask) return dp[mask] = 0;

    int i, tmp, cal;
    ret = inf;

    for(i=0;i<n;i++)
    {
        if( (1<<i) & mask )
        {
            tmp = mask & ~(1<<i);
            cal = abs(indx-i) + abs(now[indx] - dest[i]);
            ret = min(ret , cal + solve(indx+1 , tmp));
        }
    }

    return dp[mask] = ret;
}

int main()
{
    int i,j;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0;i<n;i++)    scanf("%d",&now[i]);
        for(i=0;i<n;i++)    scanf("%d",&dest[i]);

        j = (1<<n) - 1;
        for(i=0;i<=j;i++)   dp[i] = -1;

        printf("%d\n", solve(0, j));
    }

    return 0;
}
