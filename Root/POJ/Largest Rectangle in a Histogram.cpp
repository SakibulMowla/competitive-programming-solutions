#include "stdio.h"
#include "iostream"
using namespace std;

#define SZ 100000
#define SZ1 262150

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

typedef long long ll;

struct data
{
    ll minim, indx;
};

data tree[SZ1];
data small;
ll arr[SZ];

void build(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].minim = arr[b];
        tree[node].indx = b;
        return;
    }

    ll mid = (b + e) >> 1;
    build(left);
    build(riht);

    ll pref;
    if(tree[node<<1].minim < tree[(node<<1)|1].minim) pref = node<<1;
    else pref = (node<<1)|1;

    tree[node].minim = tree[pref].minim;
    tree[node].indx = tree[pref].indx;
}

void query(ll node,ll b,ll e,ll f,ll t)
{
    if(b >= f && e <= t)
    {
        if(tree[node].minim < small.minim)
        {
            small.minim = tree[node].minim;
            small.indx = tree[node].indx;
        }
        return;
    }
    ll mid = (b + e) >> 1;
    if(f <= mid) query(left, f, t);
    if(t > mid) query(riht, f, t);
}

ll ans, n;

void calculate(ll b,ll e)
{
    small.minim = 1e12;
    query(1, 1, n, b, e);
    ans = max(ans, small.minim*(e-b+1));
    if(small.indx != b) calculate(b, small.indx-1);
    if(small.indx != e) calculate(small.indx+1, e);
}

int main()
{
    ll i;

    while(scanf("%lld",&n) == 1 && n)
    {
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        build(1, 1, n);
        ans = 0LL;
        calculate(1, n);
        printf("%lld\n",ans);
    }

    return 0;
}
