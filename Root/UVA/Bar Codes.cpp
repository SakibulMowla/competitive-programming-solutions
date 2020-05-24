#include "stdio.h"
#define SZ 55
typedef long long ll;
ll dp[SZ][SZ] , k ,p ,N;

ll solve(ll n,ll part)
{
    if(part == 0)
    {
        if(n == 0) return 1;
        return 0;
    }
    if(n <= 0 || part <= 0 ) return 0;
    if(dp[n][part] != -1) return dp[n][part];
    ll i,sum = 0;
    if(n == N)
    {
        if(n == 1 && part == 1 && k >= 1) return 1;
        for(i=1;i<=k-1;i++)
            sum += solve(n-i-1,part-1);
        for(i=1;i<=k;i++)
            sum += solve(n-i-1,part-2);
    }
    else
    for(i=1;i<=k;i++)
        sum += solve(n-i,part-1);
    return dp[n][part] = sum;
}

int main()
{
    ll n,i,j;

    while(scanf("%lld %lld %lld",&N,&p,&k) == 3)
    {
        for(i=0; i<=N; i++) for(j=0; j<=p; j++) dp[i][j] = -1;
        printf("%lld\n",solve(N,p));
    }

    return 0;
}
