using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"
#include "algorithm"

#define SZ 1005

typedef long long ll;
const ll inf = 1e15;
const ll mod = 1000000007LL;

ll fac[SZ];

ll bigmod(ll b,ll p,ll m)
{
    if(p == 0) return 1%m;
    ll x = bigmod(b,p/2,m);
    x = (x * x) % m;
    if(p % 2) x = (b * x) % m;
    return x;
}

void pre(ll n)
{
    ll i;
    fac[0] = 1;
    for(i=1;i<=n;i++)
        fac[i] = (i * fac[i-1]) % mod ;
}

int main()
{
    ll n, m, i, k, a, b, c, ans;
    ll arr[SZ];

    while(scanf("%I64d %I64d",&n, &m) == 2)
    {
        pre(n);

        for(i=1;i<=m;i++)
            scanf("%I64d", &arr[i]);

        sort(arr+1, arr+m+1);

        a = arr[1] - 1;
        c = n - arr[m];
        if(m >= 2)
            b = (arr[m]-arr[1]+1)-m;
        else
            b = 0;

        ans = fac[a+b+c];
        ans = (ans * bigmod(fac[a], mod-2, mod)) % mod;
        ans = (ans * bigmod(fac[c], mod-2, mod)) % mod;

        for(i=2;i<=m;i++)
        {
            k = arr[i] - arr[i-1] - 2;
            if(k >= 0) ans = (ans * bigmod(fac[k+1], mod-2, mod)) % mod;
            if(k > 0) ans = (ans * bigmod(2, k, mod)) % mod;
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
