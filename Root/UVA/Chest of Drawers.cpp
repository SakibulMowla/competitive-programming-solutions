#include "stdio.h"
#include "string.h"
#define SZ 70
#define slld(n) scanf("%I64d",&n)
typedef long long ll;
enum {lock,unlock};

ll dp[SZ][SZ][3];

ll solve(ll n,ll s,ll state)
{
//    printf("%lld %lld %lld\n",n,s,state);
    if(s > n) return 0;
//    if(n<0 || s<0) return 0;
    if(n==0)
    {
        if(s==0) return 1;
        return 0;
    }
    ll &res = dp[n][s][state];
    if(res != -1) return res;
    res = solve(n-1,s,1);
    if(state == lock) res += solve(n-1,s-1,0);
    else res += solve(n-1,s,0);
    return res;
}

int main()
{
    ll n,s;
    memset(dp,-1,sizeof(dp));
    while(scanf("%lld %lld",&n,&s) == 2)
    {
        if(n<0 && s<0) return 0;
        printf("%lld\n",solve(n,s,0));
    }
}
