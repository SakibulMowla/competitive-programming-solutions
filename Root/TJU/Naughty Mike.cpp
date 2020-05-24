#include "stdio.h"
#include "string.h"
#define SZ 100010

typedef long long ll;

ll arr[SZ] , tree[3*SZ];

void build(ll b,ll e,ll node)
{
//    printf("b = %lld e = %lld\n",b,e);
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b + e) >> 1;
    build(b,mid,node<<1);
    build(mid+1,e,(node<<1)+1);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

void update(ll b,ll e,ll node,ll toup)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b + e) >> 1;
    if(toup <= mid) update(b,mid,node<<1,toup);
    else update(mid+1,e,(node<<1)+1,toup);
    tree[node] = tree[node<<1] + tree[(node<<1)+1];
}

ll query(ll b,ll e,ll node,ll f,ll t)
{
//    printf("b = %lld e = %lld\n",b,e);
    if(e < f || b > t) return 0ll;
    if(b>=f && e<=t) return tree[node];
    ll mid = (b + e) >> 1;
    return query(b,mid,node<<1,f,t) + query(mid+1,e,(node<<1)+1,f,t);
}

int main()
{
    ll t,n,i,j,k;
    char str[20];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            scanf("%lld",&arr[i]);
        build(1,n,1);
        scanf("%lld",&k);
        while(k--)
        {
            scanf("%s %lld %lld",str,&i,&j);
            if(strcmp(str,"Add") == 0)
            {
                arr[i] += j;
                update(1,n,1,i);
            }
            else if(strcmp(str,"Delete") == 0)
            {
                if(j > arr[i]) arr[i] = 0;
                else arr[i] -= j;
                update(1,n,1,i);
            }
            else printf("%lld\n",query(1,n,1,i,j));
        }
    }

    return 0;
}
