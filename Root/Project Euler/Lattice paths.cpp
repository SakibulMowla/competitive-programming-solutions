#include "stdio.h"
#include "string.h"

typedef long long ll;

ll r,c;
ll dp[22][22];

ll solve(ll n,ll m)
{
    printf("n = %d r = %d\n",n,r);
    if(r == n && m == c) return 1;
    if(n > r || m > c) return 0;
    ll &ret = dp[n][m];
    if(ret != -1) return ret;
    return ret = solve(n+1,m) + solve(n,m+1);
}

int main()
{
    r = c = 20;
    memset(dp,-1,sizeof dp);
    printf("%lld\n",solve(0,0));

    return 0;
}
