#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ 100010
#define SZ1 262150

#define left node<<1LL, b, mid
#define riht (node<<1LL)|1LL, mid+1LL, e

typedef long long ll;

ll arr[SZ], tree[SZ1], lazy[SZ1];
bool upd[SZ1];

void build(ll node,ll b,ll e)
{
//    printf("yes\n");
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }

    ll mid = (b + e) >> 1LL;
    build(left);
    build(riht);
    tree[node] = tree[node<<1LL] + tree[(node<<1LL)|1LL];
}

void push_down( ll n, ll l, ll r, ll b, ll m, ll e)
{
    lazy[l] += lazy[n];
    lazy[r] += lazy[n];
    tree[l] += (m-b+1) * lazy[n];
    tree[r] += (e-m) * lazy[n];
    lazy[n] = 0;
    upd[n] = 0;
    upd[l] = 1;
    upd[r] = 1;
}

void update( ll node, ll b, ll e, ll f, ll t, ll val)
{
    if(b>=f && e<=t)
    {
        lazy[node] += val;
        upd[node] = 1;
        tree[node] += (e-b+1) * val;
        return;
    }
    ll mid = (b + e) >> 1LL;
    if(upd[node])
        push_down(node, node<<1LL, (node<<1LL)|1LL, b, mid, e);
    if(f <= mid)
        update(left, f, t, val);
    if(t > mid)
        update(riht, f, t, val);
    tree[node] = tree[node<<1LL] + tree[(node<<1LL)|1];
}

ll query( ll node, ll b, ll e, ll f, ll t)
{
    if(b >= f && e <= t)
        return tree[node];
    ll sum=0ll, mid = (b + e) >> 1LL;
    if(upd[node])
        push_down(node, node<<1LL, (node<<1LL)|1LL, b, mid, e);
    if(f <= mid)
        sum = query(left, f ,t);
    if(t > mid)
        sum += query(riht, f, t);
//    tree[node] = tree[node<<1LL] + tree[(node<<1LL)|1LL];
    return sum;
}

int main()
{
    ll n, q, i, j, k;
    char ch;

    scanf("%lld %lld",&n,&q);

    for(i=1; i<=n; i++)
        scanf("%lld",&arr[i]);

    build(1, 1, n);

    while(q--)
    {
        scanf(" %c",&ch);
        if(ch == 'C')
        {
            scanf("%lld %lld %lld",&i,&j,&k);
            update(1, 1, n, i, j, k);
        }
        else
        {
            scanf("%lld %lld",&i,&j);
            printf("%lld\n",query(1, 1, n, i, j));
        }
    }

    return 0;
}
