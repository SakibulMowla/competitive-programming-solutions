#include "stdio.h"
#include "algorithm"
#define SZ 100100

typedef long long ll;
const ll mod = 1000007LL;
ll dp[SZ] , arr[SZ];

int main()
{
    ll test=0,t,i,j,k,c,n,sum;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld %lld %lld",&k,&c,&n,&arr[1]);

        for(i=2;i<=n;i++)
        {
            arr[i] = (k * arr[i-1] + c) % mod;
        }

        std::sort(arr+1,arr+n+1);

        for(i=1;i<=n;i++)
        {
            dp[i] = dp[i-1] + arr[i];
        }

        sum = 0;

        for(i=1;i<n;i++)
        {
            j = ( arr[i] * (n-i) ) - ( dp[n] - dp[i] );
            if(j < 0) j = -j;
            sum += j;
        }

        printf("Case %lld: %lld\n",++test,sum);
    }

    return 0;
}
