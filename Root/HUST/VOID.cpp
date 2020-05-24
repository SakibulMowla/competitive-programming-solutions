#include "stdio.h"
#define SZ 5010
const long long mod = 1000000007;

long long arr[SZ] , dp[SZ] , N , ans;

long long solve(long long pos)
{
    if(pos == N-1) return arr[pos];
    if(dp[pos] != -1) return dp[pos];
    long long ret=dp[pos] , k;
    ret = solve(pos+1) ;
    ans = (ans + (arr[pos] * ( ret )) % mod ) % mod;
    ret += (ret * arr[pos] + arr[pos]) % mod;
    return dp[pos] = ret;
}

int main()
{
    long long t,i,j,k,n;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        N = n;
        ans = 0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
            dp[i] = -1;
        }
        solve(0);
        printf("%lld\n",ans);
    }

    return 0;
}
