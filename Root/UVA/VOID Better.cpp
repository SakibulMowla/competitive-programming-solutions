#include "stdio.h"
#define SZ 5010
const long long mod = 1000000007;

long long arr[SZ] , dp[SZ] ;

int main()
{
    long long t,i,n,ans=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans = 0;
        for(i=0; i<n; i++)
            scanf("%lld",&arr[i]);
        dp[n] = 0;
        for(i=n-1; i>=0; i--)
        {
            ans = (ans + (arr[i] *  dp[i+1] ) % mod ) % mod;
            dp[i] = (dp[i+1] + dp[i+1] * arr[i] + arr[i]) % mod;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
