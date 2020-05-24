#include "stdio.h"
#include "string.h"
#include "math.h"

#define max(a,b) a > b ? a : b

int weight[110] , value[110] , dp[110][10010];
int n,m;
int knapsack()
{
    int i,j,w,maxim;

    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j] = -12345;
    dp[0][0] = 0;
    for(i=1;i<=n;i++)
    {
        for(w=0;w<=m;w++)
        {
            dp[i][w] = dp[i-1][w];
            if(w - weight[i] >= 0)
            {
                dp[i][w] = max(dp[i][w] , dp[i-1][w-weight[i]] + value[i]);
            }
        }
    }
    maxim = 0;
    m -= 200;
    for(i=0;i<=m;i++)
        maxim = max(maxim , dp[n][i]);
    for(i=2001;i<=m+200;i++)
        maxim = max(maxim , dp[n][i]);
    return maxim;
}

int main()
{
    int i,ans;
    while(scanf("%d %d",&m,&n) == 2)
    {
        m += 200;
        for(i=1;i<=n;i++)
            scanf("%d %d",&weight[i],&value[i]);
        ans = knapsack();
        printf("%d\n",ans);
    }

    return 0;
}
