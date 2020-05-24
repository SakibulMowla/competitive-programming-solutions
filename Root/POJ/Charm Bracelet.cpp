#include "stdio.h"

#define SZ 3410
#define SZ1 12890

int dp[SZ1]; // item, weight
int weight[SZ];
int value[SZ];

int maxim(int a,int b)
{
    return a > b ? a : b;
}

int knapsack(int n, int limit)
{
    int i, j;

    for(i=0; i<=limit; i++)
        dp[i] = 0;

    for(i=1; i<=n; i++)
    {
        for(j=limit; j>=weight[i]; j--)
        {
            if(dp[j-weight[i]] + value[i] > dp[j])
                dp[j] =  dp[j-weight[i]] + value[i];
        }
    }

    return dp[limit];
}

int main()
{
    int n, m, i, j;

    scanf("%d %d",&n,&m);

    for(i=1; i<=n; i++)
        scanf("%d %d",&weight[i],&value[i]);

    printf("%d\n",knapsack(n, m));

    return 0;
}
