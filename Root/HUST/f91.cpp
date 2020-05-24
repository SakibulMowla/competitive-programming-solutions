#include "stdio.h"

int dp[1000010];

int f91(int n)
{
    if(dp[n] != 0) return dp[n];
    if(n <= 100) return dp[n] = f91(f91(n+11));
    else return dp[n] = n - 10;
}

int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
        printf("f91(%d) = %d\n",n,f91(n));
    return 0;
}
