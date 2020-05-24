#include "stdio.h"

typedef long long ll;

const ll mod = 1000000007LL;

ll mul(ll a,ll b,ll mod)
{
    a %= mod;
    b %= mod;
    if(b<0) b += mod;
    if(a<0) a += mod;
    ll ret = 0;
    while(b)
    {
        if(b&1)
        {
            ret += a;
            if(ret>=mod) ret -= mod;
        }
        a = a<<1;
        if(a >= mod) a -= mod;
        b = b>>1;
    }
    return ret;
}

ll BigMod(ll B,ll P,ll M)
{
    ll R = 1%M;
    while(P)
    {
        if(P&1)
            R = mul(R, B, M);
        P >>= 1LL;
        B = mul(B, B, M);
    }
    return R;
}


template <class T> T gcd(T a, T b)
{
    while(b == 0) return a;
    return gcd(b, a%b);
}


int main()
{
    ll test = 0, t, i, j, k, n, ans;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&k);

        ans = 0LL;

        for(i=1; i<=n; i++)
        {
            ans = ans + BigMod(k, gcd(i, n), mod);
            if(ans >= mod)
                ans -= mod;
        }

        ans = (ans * BigMod(n, mod-2, mod)) % mod;


        printf("Case %lld: %lld\n",++test,ans);
    }

    return 0;
}
