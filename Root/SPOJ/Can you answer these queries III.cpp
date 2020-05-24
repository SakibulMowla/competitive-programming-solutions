using namespace std;

#include "stdio.h"
#include "iostream"

#define SZ 50010
#define SZ1 131075

typedef long long ll;
const ll inf = 1e10;

struct data
{
    ll rsum, bpre, bsuf, bsum;
    data()
    {
        rsum = bpre = bsuf = bsum = -inf;
    }
};

ll arr[SZ];
data tree[SZ1];

void doit(ll node,ll left,ll right)
{
    tree[node].rsum = tree[left].rsum + tree[right].rsum;
    tree[node].bpre = max(tree[left].bpre, tree[left].rsum + tree[right].bpre);
    tree[node].bsuf = max(tree[right].bsuf, tree[left].bsuf + tree[right].rsum);
    tree[node].bsum = max( max(tree[left].bsum , tree[right].bsum) , tree[left].bsuf + tree[right].bpre );
}

void build(ll b,ll e,ll node)
{
    if(b == e)
    {
        tree[node].bpre = tree[node].bsuf = tree[node].bsum = tree[node].rsum = arr[b];
        return;
    }

    ll mid = (b+e) >> 1, left = node << 1, right = left + 1;

    build(b, mid, left);
    build(mid+1, e, right);

    doit(node, left, right);
}

void update(ll b,ll e,ll node,ll indx)
{
    if(b == e)
    {
        tree[node].bpre = tree[node].bsuf = tree[node].bsum = tree[node].rsum = arr[b];
        return;
    }

    ll mid = (b+e) >> 1, left = node << 1, right = left + 1;

    if(indx <= mid) update(b, mid, left, indx);
    else update(mid+1, e, right, indx);

    doit(node, left, right);
}

data query(ll b,ll e,ll node,ll f,ll t)
{
    if(b>=f && e<=t) return tree[node];

    data lf, rt, now;
    ll mid = (b+e) >> 1, left = node << 1, right = left+1;

    if(f <= mid) lf = query(b, mid, left, f, t);
    if(t > mid) rt = query(mid+1, e, right, f, t);

    now.rsum = lf.rsum + rt.rsum;
    now.bpre = max(lf.bpre, lf.rsum+rt.bpre);
    now.bsuf = max(rt.bsuf, rt.rsum+lf.bsuf);
    now.bsum = max( max(lf.bsum , rt.bsum) , lf.bsuf + rt.bpre );

    return now;
}

int main()
{
    ll n, m, i, j, k;

    while(scanf("%lld",&n) == 1)
    {
        for(i=1;i<=n;i++)   scanf("%lld",&arr[i]);
        build(1, n, 1);
        scanf("%lld",&m);
        while(m--)
        {
            scanf("%lld %lld %lld",&i,&j,&k);
            if(i)
            {
                printf("%lld\n",query(1, n, 1, j, k).bsum);
            }
            else
            {
                arr[j] = k;
                update(1, n, 1, j);
            }
        }
    }

    return 0;
}
