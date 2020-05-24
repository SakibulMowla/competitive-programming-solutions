#include "stdio.h"
typedef long long ll;
const ll mod = 1000000007ll;

int main()
{
    ll t,n,k,ans,i,j;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&k);
        ans = 1ll;
        for(i=1; i<n; i++)
        {
            ans = (ans * k) % mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
