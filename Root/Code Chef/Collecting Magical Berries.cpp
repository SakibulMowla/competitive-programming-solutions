#include "stdio.h"
#include "string.h"

#define SZ 100010
#define SZ1 3*SZ
#define SZ2 3000010

typedef long long ll;
ll mod = 3046201LL;

ll fact[SZ2], arr[SZ], tree[SZ1];

void build(ll b,ll e,ll node)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll mid = (b+e) >> 1LL;

    build(b, mid, node<<1LL);
    build(mid+1LL, e, (node<<1LL)+1LL );

    tree[node] = tree[node<<1LL] + tree[(node<<1LL)+1LL];
}

void update(ll b,ll e,ll node,ll indx)
{
    if(b == e)
    {
        tree[node] = arr[indx];
        return;
    }

    ll mid = (b + e) >> 1;

    if(indx <= mid) update(b, mid, node<<1LL, indx);
    else update(mid+1LL, e, (node<<1LL)+1LL, indx);

    tree[node] = tree[node<<1LL] + tree[(node<<1LL)+1LL];
}

ll query(ll b,ll e,ll node,ll f,ll t)
{
    if(f > e || t < b) return 0LL;

    if(b>=f && e<=t) return tree[node];

    ll mid = (b + e) >> 1LL, sum = 0LL;

    if(f <= mid) sum += query(b, mid, node<<1LL, f, t);
    if(t > mid) sum += query(mid+1LL, e, (node<<1LL)+1, f, t);

    return sum;
}

//ll bigmod(ll b,ll p)
//{
//    if(p == 0) return 1%mod;
//    ll x = bigmod(b,p/2);
//    x = (x * x) % mod;
//    if(p%2) x = (b * x) % mod;
//    return x;
//}

ll bigmod(ll b,ll p)
{
    ll R=1;
    while(p>0)
    {
        if(p%2==1)
        {
            R=(R*b)%mod;
        }
        p/=2;
        b=(b*b)%mod;
    }
    return R;
}

void factor(ll n)
{
    fact[0]= 1LL;
    ll i;
    for(i=1; i<=n; i++)
        fact[i] = (i * fact[i-1]) % mod;
}

int main()
{
    factor(3000005);
    char s[20];
    ll sum, party1, party2, val1, val2, koyta, ans, len, n, i, j, q;

    while(scanf("%lld", &n) == 1)
    {
        for(i=1; i<=n; i++)   scanf("%lld",&arr[i]);

        build(1LL, n, 1LL);

        scanf("%lld",&q);

        while(q--)
        {
            scanf("%s",s);
            if(strcmp(s,"change") == 0)
            {
                scanf("%lld %lld",&i,&j);
                arr[i] = j;
                update(1LL, n, 1LL, i);
            }
            else
            {
                scanf("%lld %lld",&i,&j);

                len = j - i + 1;
                sum = query(1LL, n, 1LL, i, j);

                party1 = sum % len;
                party2 = len - party1;
                val1 = sum / len + 1;
                val2 = sum / len;

                ans = fact[len];
                ans = (ans * bigmod(fact[party1], mod-2)) % mod;
                ans = (ans * bigmod(fact[party2], mod-2)) % mod;

                if(party1)
                {
                    ans = (ans * fact[sum]) % mod;
                    koyta = bigmod(fact[val1], party1);
                    ans = (ans * bigmod(koyta, mod-2)) % mod;
                    sum = sum - (party1 * val1);
                    ans = (ans * bigmod(fact[sum], mod-2)) % mod;
                }

                if(party2)
                {
                    ans = (ans * fact[sum]) % mod;
                    koyta = bigmod(fact[val2], party2);
                    ans = (ans * bigmod(koyta, mod-2)) % mod;
                }

                printf("%lld\n",ans);

            }
        }
    }

    return 0;
}
