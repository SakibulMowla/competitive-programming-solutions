#include "stdio.h"
#include "string.h"

#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 110
#define mod 1000000

int dp[SZ][SZ];

int main()
{
    int n,k,i,j;
    FORI(i,1,100) dp[i][1] = 1;
    FORI(i,1,100) dp[1][i] = i;
    FORI(i,2,100) FORI(j,2,100) dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    while(scanf("%d %d",&n,&k) ==2 && (n+k)) printf("%d\n",dp[n][k]);

    return 0;
}
