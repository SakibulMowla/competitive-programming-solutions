#include "stdio.h"

#define mod 1000000

int dp[110][110];

int bctk(int n,int k)
{
    if(n<0 || k<0) return 0;
    if(dp[n][k] != -1) return dp[n][k];
    int i,res=0;
    for(i=0;i<=n;i++)
        res += (bctk(n-i,k-1) % mod);
    return dp[n][k] = res % mod;
}

int main()
{
    int i,j,n,k;
    for(i=0;i<101;i++) for(j=0;j<101;j++) dp[i][j] = -1;
    dp[0][0] = 1;
    while(scanf("%d %d",&n,&k) == 2 && (n+k))
        printf("%d\n",bctk(n,k));

    return 0;
}
