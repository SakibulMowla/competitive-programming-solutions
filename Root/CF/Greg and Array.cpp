#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define SZ 100010
#define SZ1 262150

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int qi[SZ], qj[SZ], arr[SZ];
ll tree[SZ1];
bool upd[SZ1];
ll qv[SZ];

void prop(int node,int aa,int bb)
{
    tree[aa] += tree[node];
    tree[bb] += tree[node];
    tree[node] = 0;
    upd[node] = 0;
    upd[aa] = 1;
    upd[bb] = 1;
}

void update(int node,int b,int e,int f,int t,ll val)
{
    if(b >= f && e <= t)
    {
        tree[node] += val;
        upd[node] = 1;
        return;
    }
    if(upd[node]) prop(node, node<<1, (node<<1)|1);
    int mid = (b + e) >> 1;
    if(f <= mid) update(left, f, t, val);
    if(t >  mid) update(riht, f, t, val);
}

ll query(int node,int b,int e,int x)
{
    if(b == e)
    {
        return tree[node];
    }
    int mid = (b + e) >> 1;
    if(upd[node]) prop(node, node<<1, (node<<1)|1);
    if(x <= mid) return query(left, x);
    else return query(riht, x);
}

int main()
{
    int n, m, k, i, j;

    scanf("%d %d %d",&n,&m,&k);

    for(i=1; i<=n; i++) scanf("%d",&arr[i]);
    for(i=1; i<=m; i++) scanf("%d %d %I64d",&qi[i],&qj[i],&qv[i]);

    while(k--)
    {
        scanf("%d %d",&i,&j);
        update(1, 1, m, i, j, 1);
    }
    for(i=1; i<=m; i++)
    {
        qv[i] = qv[i] * query(1, 1, m, i);
    }
    memset(tree, 0, sizeof(tree));
    memset(upd, 0, sizeof(upd));
    for(i=1; i<=m; i++)
    {
        update(1, 1, n, qi[i], qj[i], qv[i]);
    }
    ll tmp;
    for(i=1;i<=n;i++)
    {
        tmp = arr[i]+query(1, 1, n, i);
        printf("%I64d ",tmp);
    }

    return 0;
}
