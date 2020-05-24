#include "stdio.h"
typedef long long ll;

const ll mod = 1000000007LL;

int main()
{
    ll n, i, ans, sum;

    while(scanf("%I64d",&n) == 1)
    {
        ans = sum = 0;
        for(i=1;i<=n;i++)
        {
            sum = (sum + i) % mod;
            printf("sum = %lld %lld\n",sum,(sum*(n-i+1))%mod);
            ans = (ans + (sum*(n-i+1))%mod ) % mod;
        }
        ans = (ans + ans) % mod;
        ans = (ans - n) % mod;
        if(ans < 0) ans += mod;
        printf("%I64d\n",ans);
    }

    return 0;
}
