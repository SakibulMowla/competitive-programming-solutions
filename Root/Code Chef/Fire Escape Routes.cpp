#include "stdio.h"
#define SZ 100010

typedef long long ll;
const ll mod = 1e9 + 7;

ll par[SZ],cycle[SZ];

void init(int n)
{
    ll i;
    for(i=0;i<=n;i++) par[i] = i , cycle[i] = 1;
}

ll find(ll r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(ll a,ll b)
{
    if(cycle[a] < cycle[b])
    {
        par[a] = b;
        cycle[b] += cycle[a];
    }
    else
    {
        par[b] = a;
        cycle[a] += cycle[b];
    }
}

int main()
{
    ll t,n,m,i,j,k;
    while(scanf("%lld",&t) == 1)
    {
        while(t--)
        {
            scanf("%lld %lld",&n,&m);
            init(n);
            for(i=0;i<m;i++)
            {
                scanf("%lld %lld",&j,&k);
                j = find(j);
                k = find(k);
                if(j != k) Union(j,k);
            }
            j = 0;
            k = 1;
            for(i=1;i<=n;i++)
            {
                if(i == par[i]) j++ , k = (k * cycle[i]) % mod;
            }
            printf("%lld %lld\n",j,k);
        }
    }

    return 0;
}
