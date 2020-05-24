#include "stdio.h"
#define SZ 100010

typedef long long ll;
ll tree[3*SZ] , lazy[3*SZ];

void pushdown(ll node,ll r)
{
    if(lazy[node])
    {
        lazy[node<<1] += lazy[node];
        lazy[(node<<1)+1] += lazy[node];
        tree[node<<1] += (r-(r>>1)) * lazy[node];
        tree[(node<<1)+1] += (r>>1) * lazy[node];
        lazy[node] = 0;
    }
}

void build(ll b,ll e,ll node)
{
    tree[node] = lazy[node] = 0;
    if(b == e) return;
    ll mid = (b + e) >> 1;
    build(b,mid,node<<1);
    build(mid+1,e,(node<<1)+1);
}

void update(ll b,ll e,ll node,ll f,ll t,ll val)
{
    if(e < f || b > t) return;
    if(b>=f && e<=t)
    {
        tree[node] += val * (e-b+1);
        lazy[node] += val;
        return;
    }
    pushdown(node,e-b+1);
    ll mid = (b + e) >> 1;
    update(b,mid,node<<1,f,t,val);
    update(mid+1,e,(node<<1)+1,f,t,val);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

ll query(ll b,ll e,ll node,ll f,ll t)
{
    if(e < f || b > t) return 0 ;
    if(b>=f && e<=t)
        return tree[node];
    pushdown(node,e-b+1);
    ll mid = (b + e) >> 1;
    return query(b,mid,node<<1,f,t) + query(mid+1,e,(node<<1)+1,f,t);
}

int main()
{
    ll n,q,i,j,k,l,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        build(1,n,1);
        while(q--)
        {
            scanf("%lld",&i);
            if(i == 0)
            {
                scanf("%lld %lld %lld",&j,&k,&l) ;
                update(1,n,1,j,k,l);
            }
            else
            {
                scanf("%lld %lld",&j,&k) ;
                printf("%lld\n",query(1,n,1,j,k));
            }
        }
    }

    return 0;
}
