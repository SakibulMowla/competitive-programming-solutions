#include "bits/stdc++.h"
using namespace std;

#define SZ 100010
#define SZ1 262150

#define left node<<1, b ,mid
#define riht (node<<1)+1, mid+1, e

int tree[SZ1], sum[SZ1];

void build(int node,int b,int e)
{
    tree[node] = sum[node] = 0;
    if(b == e)
        return;
    int mid = (b + e) >> 1;
    build(left);
    build(riht);
}

void push_down(int node,int b,int e)
{
    int mid = (b + e) >> 1;
    tree[node<<1] += tree[node];
    tree[(node<<1)+1] += tree[node];
    tree[node<<1] %= 2;
    tree[(node<<1)+1] %= 2;
    sum[node<<1] = (mid-b+1) - sum[node<<1];
    sum[(node<<1)+1] = (e-mid) - sum[(node<<1)+1];
    tree[node] = 0;
}

void update(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
    {
        tree[node]++;
        tree[node] %= 2;
        sum[node] = (e - b + 1) - sum[node];
        return;
    }

    int mid = (b + e) >> 1;

    if(tree[node])
    {
        push_down(node, b, e);
    }

    if(f <= mid) update(left, f, t);
    if(t > mid)  update(riht, f, t);

    sum[node] = sum[node<<1] + sum[(node<<1)+1];
}

int query(int node,int b,int e,int f,int t)
{
    if(b >= f && e <= t)
    {
        return sum[node];
    }

    int mid = (b + e) >> 1, ret = 0;

    if(tree[node])
    {
        push_down(node, b, e);
    }

    if(f <= mid) ret += query(left, f, t);
    if(t > mid)  ret += query(riht, f, t);

    return ret;
}

int main()
{
    int n, m, i, j, k;

    scanf("%d %d",&n,&m);

    build(1, 1, n);

    while(m--)
    {
        scanf("%d %d %d",&k,&i,&j);
        if(k == 0) update(1, 1, n, i, j);
        else
            printf("%d\n",query(1, 1, n, i, j));
    }

    return 0;
}
