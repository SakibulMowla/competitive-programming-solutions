#include "stdio.h"
#define SZ 110
#define SZ1 10010

typedef long long ll;
const ll mod = 100000007;

ll dp[SZ1] , coin[SZ];

int main()
{
    ll t=0,test,i,j,k,n;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0;i<n;i++) scanf("%lld",&coin[i]);
        for(i=1;i<=k;i++) dp[i] = 0;
        dp[0] = 1;
        for(i=0;i<n;i++)
            for(j=coin[i];j<=k;j++)
                dp[j] = (dp[j] + dp[j-coin[i]]) % mod;
        printf("Case %lld: %lld\n",++t,dp[k]);
    }

    return 0;
}
