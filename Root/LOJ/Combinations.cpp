#include "stdio.h"
#define SZ 1000010

typedef long long ll;
const ll mod = 1000003LL;

ll fact[SZ];

void pre()
{
    ll i;
    fact[0] = 1;
    for(i=1;i<=1000000;i++)
        fact[i] = (i * fact[i-1]) % mod;
}

//ll bigmod(ll b,ll p)
//{
//    if(p == 0) return 1%mod;
//    ll x = bigmod(b,p/2);
//    x = (x * x) % mod;
//    if(p%2) x = (b * x) % mod;
//    return x;
//}

ll extGcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int g = extGcd(b, a % b, y, x);
        y -= a / b * x;
        return g;
    }
}

ll modInv(ll a, ll m)
{
    ll x, y;
    extGcd(a, m, x, y);
    x %= m;
    while (x < 0)
    {
        x += m;
    }
    return x;
}

inline void read (ll &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}


int main()
{
    pre();

    ll t=0, test, n, m, ans;

    read(test);

    while(test--)
    {
        read(n);
        read(m);
        ans = fact[n];
        ans = (ans * modInv(fact[m], mod)) % mod;
        ans = (ans * modInv(fact[n-m], mod)) % mod;
        printf("Case %lld: %lld\n",++t, ans);
    }
}
