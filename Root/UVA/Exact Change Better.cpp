#include "stdio.h"
#define SZ 110
#define SZ1 20010

typedef long long ll;
const ll inf = 1<<28;
ll coin[SZ],dp[SZ1];

ll max(ll a,ll b)
{
    return a > b ? a : b;
}
ll min(ll a,ll b)
{
    return a < b ? a : b;
}

int main()
{
    ll t,i,j,k,n,w,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&w,&n);
        k = 0;
        for(i=0; i<n; i++) scanf("%lld",&coin[i]) , k = max(k,coin[i]);
        for(i=1; i<=w+k; i++) dp[i] = inf;
        dp[0]= 0;
        ans = inf;
        for(i=0; i<n; i++)
        {
            for(j=w;j>=0;j--)
            {
                if(dp[j] != inf && j+coin[i] <= w+k && dp[j+coin[i]] > dp[j] + 1)
                {
                    dp[j+coin[i]] = dp[j] + 1;
                    if(j+coin[i] < ans && j+coin[i] >= w)
                        ans = j + coin[i];
                }
            }
        }
        printf("%lld %lld\n",ans,dp[ans]);
    }

    return 0;
}
