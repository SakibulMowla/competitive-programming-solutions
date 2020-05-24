#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 1010
typedef long long ll;

ll n, dp[SZ][3010], myw[SZ], myc[SZ];

ll solve(ll indx,ll left,ll cnt)
{
    if(indx == n)
        return 0;
    ll &ret = dp[indx][left];
    if(ret != -1) return ret;

    ll a=0, b=0;
    a = solve(indx+1, left, cnt);
    if(left >= myw[indx])
    {
        if(cnt)
            left -= myw[indx];
        left = min(left, myc[indx]);
        b = solve(indx+1, left, cnt+1);
        b++;
    }
    return ret = max(a, b);
}

int main()
{
    ll i, j, k;

    while(scanf("%lld",&n) == 1 && n)
    {
        k = 0;
        for(i=0; i<n; i++)
            scanf("%lld %lld",&myw[i],&myc[i]), k = myc[i] > k ? myc[i] : k;
        for(i=0; i<=n; i++)
        {
            dp[i][3000] = -1;
            for(j=0; j<=k; j++)
                dp[i][j] = -1;
        }
        printf("%lld\n",solve(0,3000,0));
    }

    return 0;
}
