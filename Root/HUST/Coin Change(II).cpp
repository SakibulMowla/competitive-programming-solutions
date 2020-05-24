#include "stdio.h"
#include "string.h"
#define SZ 110
#define SZ1 10010
const int mod = 100000007;
int coin[SZ] , dp[SZ1];
int main()
{
    int t,test,i,j,k,n;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++) scanf("%d",&coin[i]);
        memset(dp,0,sizeof(int) * (k+1));
        dp[0] = 1;
        for(i=0;i<n;i++)
            for(j=coin[i];j<=k;j++)
                dp[j] = (dp[j] + dp[j-coin[i]]) % mod;
        printf("Case %d: %d\n",++t,dp[k]);
    }

    return 0;
}
