#include "stdio.h"
#include "string.h"

#define SZ 25
template <class T> T min(T a,T b) { return a < b ? a : b; }
typedef long long ll;
ll red[SZ],blue[SZ],gren[SZ],n;

ll dp[25][5];

ll solve(ll p,ll col)
{
    if(p > n) return 0;
    if(dp[p][col] != -1) return dp[p][col];
    ll ans = 1<<28;
    if(col == 1) ans = min( solve(p+1,2) , solve(p+1,3) );
    if(col == 2) ans = min( solve(p+1,1) , solve(p+1,3) );
    if(col == 3) ans = min( solve(p+1,1) , solve(p+1,2) );
    if(col == 1) ans += red[p];
    if(col == 2) ans += blue[p];
    if(col == 3) ans += gren[p];
    return dp[p][col] = ans;
}

int main()
{
    ll t=0,test,i,ans;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld %lld %lld",&red[i],&blue[i],&gren[i]);
        memset(dp,-1,sizeof(dp));
        ans = i << 28;
        ans = min(ans , solve(1,1));
        ans = min(ans , solve(1,2));
        ans = min(ans , solve(1,3));
        printf("Case %lld: %lld\n",++t,ans);
    }

    return 0;
}
