#include "stdio.h"
#include "string.h"

#define SZ 100010
typedef long long ll;

ll tree[3*SZ] , lazy[3*SZ];

void build(ll b,ll e,ll node)
{
//    printf("node = %lld %lld %lld\n",node,b,e);
    tree[node] = lazy[node] = 0;
    if(b == e) return;
    ll mid = (b + e) / 2;
    build(b,mid,node << 1);
    build(mid+1,e,(node<<1) + 1);
}

void update(ll b,ll e,ll node,ll f,ll t,ll val)
{
//    if(f > e || b > t) return;
//    printf("node = %lld %lld %lld\n",node,b,e);
    if(b>=f && e<=t)
    {
        tree[node] += val * (e-b+1);
        lazy[node] += val;
        return;
    }

    ll mid = (b + e) >> 1 , r = (e-b+1);

    lazy[node<<1] += lazy[node];
    lazy[(node<<1)+1] += lazy[node];
    tree[node<<1] += (r-(r>>1)) * lazy[node];
    tree[(node<<1)+1] += (r>>1) * lazy[node];
    lazy[node] = 0;

    if(mid >= f) update(b,mid,node<<1,f,t,val);
    if(mid < t) update(mid+1,e,(node<<1)+1,f,t,val);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

ll query(ll b,ll e,ll node,ll f,ll t)
{
//    if(f > e || b > t) return 0ll;
    if(b>=f && e<=t)
    {
        return tree[node];
    }
    ll mid = (b + e) >> 1 , sum = 0 , r = e-b+1;

    lazy[node<<1] += lazy[node];
    lazy[(node<<1)+1] += lazy[node];
    tree[node<<1] += (r-(r>>1)) * lazy[node];
    tree[(node<<1)+1] += (r>>1) * lazy[node];
    lazy[node] = 0;

    if(mid >= f) sum += query(b,mid,node<<1,f,t);
    if(mid < t) sum += query(mid+1,e,(node<<1)+1,f,t);
    return sum;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll i,j,k,q,v,n,t,test=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        build(0,n-1,1);
        printf("Case %lld:\n",++test);
        while(q--)
        {
            scanf("%lld",&k);
            if(!k)
            {
                scanf("%lld %lld %lld",&i,&j,&v);
                update(0,n-1,1,i,j,v);
            }
            else
            {
                scanf("%lld %lld",&i,&j);
                printf("%lld\n",query(0,n-1,1,i,j));
            }
        }
    }
    return 0;
}
