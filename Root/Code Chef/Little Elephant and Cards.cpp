#include "stdio.h"
#include "math.h"

#define SZ 1010

const int mod = 1000000007;
int dp[SZ][SZ];

int nCr(int n,int r)
{
    if(r == 1) return n;
    if(n == r) return 1;
    if(dp[n][r] != 0) return dp[n][r];
    dp[n][r] = ( nCr(n-1,r) + nCr(n-1,r-1) ) % mod;
//    printf("n = %d r = %d ans = %d\n",n,r,dp[n][r]);
    return dp[n][r];
}

int main()
{
    int t,n,i,j,k;
    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf("%d",&n);
            for(i=0; i<n; i++) scanf("%d",&j);
            k = 0;
            i = (n/2) + 1;
            for( ; i<=n; i++)
                k = ( k + nCr(n,i) ) % mod /*, printf("k = %d i = %d n = %d\n",k,i,n)*/;
            printf("%d\n",k);
        }
    }

    return 0;
}
