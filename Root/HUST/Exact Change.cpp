#include "stdio.h"
#define SZ 20010
#define SZ1 110

typedef long long ll;
template <class T> T min(T a,T b)
{
    return a < b ? a : b;
}

const ll inf = 1<<28;
ll coin[SZ1] , dp[SZ];

int main()
{
    ll i,j,k,n,m,ans,t,target;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&target);
        scanf("%lld",&n);
        k = 0;
        for(i=0; i<n; i++)
        {
            scanf("%lld",&coin[i]) ;
            if(coin[i] > k) k = coin[i];
        }
        for(i=0; i<=target+k; i++) dp[i] = inf;
        dp[0] = 0;
        ans = inf;
        for(i=0; i<n; i++)
            for(j=target; j>=0; j--)
            {
                if(dp[j] != inf && j+coin[i] <= target + k && dp[j+coin[i]] > dp[j] + 1)
                {
                    dp[j+coin[i]] = dp[j] + 1;
                    if(j + coin[i] < ans && j+coin[i] >= target) ans = j + coin[i];
                }
            }
        printf("%lld %lld\n",ans,dp[ans]);
    }

    return 0;
}
