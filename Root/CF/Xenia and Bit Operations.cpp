#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define SZ 131080
#define SZ1 262150

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

ll arr[SZ];
ll tree[SZ1];
ll m;

void build(ll node,ll b,ll e,ll mark)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b + e) >> 1;
    build(left, mark+1);
    build(riht, mark+1);
    if(m%2 != mark%2)   tree[node] = tree[node<<1] | tree[(node<<1)|1];
    else                tree[node] = tree[node<<1] ^ tree[(node<<1)|1];
}

void query(ll node,ll b,ll e,ll pos,ll mark)
{
    if(b == e)
    {
        tree[node] = arr[b];
        return;
    }
    ll mid = (b + e) >> 1;
    if(pos <= mid) query(left, pos, mark+1);
    else           query(riht, pos, mark+1);
    if(m%2 != mark%2)   tree[node] = tree[node<<1] | tree[(node<<1)|1];
    else                tree[node] = tree[node<<1] ^ tree[(node<<1)|1];
}

int main()
{
    ll n, i, j, q;

    while(scanf("%I64d %I64d",&m,&q) == 2)
    {
        n = 1<<m;
        for(i=1;i<=n;i++)
            scanf("%I64d",&arr[i]);
        build(1, 1, n, 0);
        while(q--)
        {
            scanf("%I64d %I64d",&i,&j);
            arr[i] = j;
            query(1, 1, n, i, 0);
            printf("%I64d\n",tree[1]);
        }
    }

    return 0;
}
